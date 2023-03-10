// [ Room 83 - Midships deck 1.  Captains quarters.  Ladder going down

// [ Main logic: captain will either be sitting in his chair OR
// [ will walk in after you've been in the room a while
// [ When you and the cap'n are in the same section, you will be apprehended
// [

#include "rm83.msg"
#include "gamedefs.reh"

#define  first.inventory.item  1
#define  last.inventory.item    55                          // [ +1 of inventory total

#define  egoLoc  lv0                                        // [ side of doorway he's on
#define  holdSide  90
#define  captain  0
#define  hold    1

#define  capnTimer    lv1                                   // [ time before he comes in
#define  writing.timer  lv2

#define  stunTimer    lv3
#define  hiding.place  lv4
#define  scan.room    lv5
#define  script    lv6
#define  hiding  0
#define  entering  1
#define  walkingToDesk  2
#define  writing  3
#define  chasing  4
#define  caught  5
#define  snore.timer  lv7

#define  fallDone    lf0
#define  capnHere    lf1                                    // [ set when he's in the room
#define  capnThere    lf2                                   // [ getting him to chair
#define  capAtDesk    lf3
#define  sDone    lf4
#define  next      lf5
#define  can.chase    lf6
#define  snore.done  lf7

#define  first.item  1                                      // [ first item of inventory
#define  last.item    55                                    // [ +1 of total

// [ define base of ladder
#define  baseLeft    140
#define  baseTop    125
#define  baseCenter  142
#define  baseRight    153
#define  baseBottom  133

// [ captains locations
#define  chairX  69
#define  chairY  117

if (init.log) {
    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    load.sound(s.ego.stunned);
    load.sound(s.ego.falling);
    load.sound(m.badguy);
    load.sound(s.snoring);

    load.logics(lgc.pirates);
    call(lgc.pirates);

                                                            // [ external stuff to set up
    set(interiorRoom);

    landing.x = 127;
    landing.y = 115;

    wiz.x = 130;
    wiz.y = 138;

    map.area = map.ship;

                                                            // [  footlocker
    animate.obj(aChest);
    load.view(v.footlocker);
    set.view(aChest, v.footlocker);
    ignore.blocks(aChest);
    position(aChest, 38, 165);
    stop.cycling(aChest);
                                                            // [ make an invisible footlocker to block ego
                                                            // [  add.to.pic(v.footlocker, 0, 0, 38, 165, 1, 1);
    if (chestOpen) {
        set.cel(aChest, 3);
    }
    else {
        set.cel(aChest, 0);
    }
    draw(aChest);
    stop.update(aChest);

                                                            // [ now what about the captain?  He's never here when at beach.
    if (shipShape != atBeach) {
        animate.obj(aCaptain);
        if (crewAsleep) {
            snore.timer = SNOREDELAY;
            load.view(v.pirate.sleeping);
            set.view(aCaptain, v.pirate.sleeping);
            work = 6;
            cycle.time(aCaptain, work);
            position(aCaptain, 68, 148);
            set.priority(aCaptain, 14);
            set.loop(aCaptain, 0);
        }
        else {
            load.view(v.captain.writing);
            load.view(v.pirate.captain);
            set.view(aCaptain, v.pirate.captain);
            ignore.blocks(aCaptain);
            random(1, 3, work);
            if (previous.room == 82) {                      // [ just came from 82
                work = 1;
            }
            if (handsOff) {
                work = 1;
            }
            if (work == 3) {                                // [ here and now
                script = writing;
                set.view(aCaptain, v.captain.writing);
                position(aCaptain, chairX, chairY);
                writing.timer = 66;
            }
            else {                                          // [ coming in later (maybe)
                random(10, 40, capnTimer);                  // [ time before entry
                position(aCaptain, 12, 129);
                script = hiding;
                if (work == 1) {                            // [ never coming in
                    capnTimer = 0;
                }
            }
        }
        draw(aCaptain);
        if (script == hiding) {
            stop.update(aCaptain);
        }
    }

    load.view(v.ego);                                       // [ get standard view
    load.view(v.ego.falling);
    load.view(v.ego.climbing.ladder);
    load.view(v.ego.stunned);
    load.view.f(current.ego);
    set.view.f(ego, current.ego);

    if (current.status == climbing) {                       // [ set ego to climbing and prepare to fall
        current.status = climbing;
        ignore.horizon(ego);
        ignore.blocks(ego);                                 // [ ladder crosses p1 line
        if (previous.room == 80) {
            position(ego, 145, 55);
        }
        else {
            position(ego, baseCenter, baseBottom);
        }
        set.priority(ego, 11);                              // [ in front of ladder
        set.view(ego, v.ego.climbing.ladder);
        set.loop(ego, 0);
        fix.loop(ego);
    }
    else {                                                  // [ walking in or falling in
        set.view(ego, v.ego);
        get.posn(ego, ego.x, ego.y);
        if (previous.room == 84) {
            if (ego.y > 134) {
                ego.y = 137;
            }
            else {
                ego.y = 110;
            }
            position.f(ego, ego.x, ego.y);
        }
        if (previous.room == 82) {
            position(ego, 28, 125);
        }
        if (previous.room == 80) {                          // [ falling in through hold
            position(ego, 120, 55);
            set.view(ego, v.ego.falling);
        }
    }

    if (current.status == deferred.entry) {
        set.view(ego, v.ego);
        position.v(ego, landing.x, landing.y);
        set(positionEgo);
        set(drawEgo);
    }

    if (drawEgo) {
        draw(ego);
    }
    show.pic();
    return();
}

call(lgc.pirates);

--snore.timer;
if (snore.timer == 1) {
    sound(s.snoring, sound.done);
    set.cel(aCaptain, 0);
    end.of.loop(aCaptain, snore.done);
}

if (snore.done) {
    reset(snore.done);
    snore.timer = SNOREDELAY;
    stop.cycling(aCaptain);
}

// [ set egoLoc to proper side of picture
if (ego.x > holdSide) {
    egoLoc = hold;
}
else {
    egoLoc = captain;
}

// [ time the captain entrance
if (capnTimer && aSecondPassed) {
    --capnTimer;
    if (capnTimer == 0) {
        set(next);
    }
}

// [ the captain walking in on you or visa versa
get.posn(aCaptain, x, y);
if (script == entering) {
    if (x > 32) {
        set(can.chase);
    }
    else {
        reset(can.chase);
    }
}
else {
    if ((script == walkingToDesk || script == writing)) {
        set(can.chase);
    }
    else {
        reset(can.chase);
    }
}

if (egoLoc == captain && current.status == normal.ego && can.chase) {
    script = chasing;
    set(next);
    #message 16  "The Captain doesn't want you snooping in his quarters.
You're in trouble now!";
    prevent.input();
}

if (!handsOff && script == hiding && next) {
    reset(next);
    script = entering;
    start.update(aCaptain);
    move.obj(aCaptain, 40, 129, 1, next);
    sound(m.badguy, sound.done);
}

if (script == entering && next) {
    reset(next);
    script = walkingToDesk;
    move.obj(aCaptain, chairX, chairY, 1, next);
}

if (script == walkingToDesk && next) {
    reset(next);
    script = writing;
    set.view(aCaptain, v.captain.writing);
    reposition.to(aCaptain, 69, 117);
    writing.timer = 66;
}

// [ this is the pen wiggling while at desk
if (script == writing) {
    --writing.timer;
    if (writing.timer == 21) {
        start.cycling(aCaptain);
    }
    if (writing.timer == 1) {
        writing.timer = 66;
        stop.cycling(aCaptain);
    }
}

if (script == chasing && next) {
    reset(next);
    script = caught;
    stop.motion(ego);
    set.view(aCaptain, v.pirate.captain);
    program.control();
    start.cycling(aCaptain);
    follow.ego(aCaptain, 10, next);
}

if (script == caught && next) {
    ++script;
    reset(next);
    set(tossed.in);
    if (timesCaught == 1) {
        #message 18  "\"Yer more trouble than yer worth!\" the Captain thunders.
\"'Tis the plank fer ya now!\"";                                          // [ final message
    }
    else {
        #message 19  "\"I'll not tolerate ya snoopin' around me quarters!\" the Captain
thunders. \"If I ketch ya in here again ya'll walk the plank!\"";                                          // [ warning message
    }
    player.control();
    accept.input();
    new.room(85);
}

// [ go start falling sequence if falling
if (current.status == falling) {
    x = 6;                                                  // [ rate
    y = 124;                                                // [ y destination
    goto DoFall;
}

// [ Slipping off of the ladder
if (current.status == climbing && !obj.in.box(ego, baseLeft, 33, baseRight, 166)) {
    current.status = falling;
    x = 3;
    y = 144;
    goto DoFall;
}

// [ falling in the hold is deadly

if (current.status == normal.ego && hit.special) {
    current.status = falling;
    sound(s.ego.falling, sound.done);
    set.view(ego, v.ego.falling);
    reposition.to(ego, 130, 125);
    set(keep.cycling);
    set.priority(ego, 10);
    move.obj(ego, 130, 165, falling.step.size, fallDone);
    set.scan.start();
    if (fallDone) {
        reset.scan.start();
        new.room(85);
    }
    return();
}

// [ when ego is at base of the ladder we are faced with a few choices
// [ Choices are based on direction that user is requesting
if (obj.in.box(ego, baseLeft, baseTop, baseRight, baseBottom)) {    // [ at base
    if (current.status == climbing) {
        if (ego.dir != 1 && ego.dir != 5 && ego.dir != 0) {
                                                            // [ get off ladder
            current.status = normal.ego;
            release.loop(ego);
            observe.blocks(ego);
            observe.horizon(ego);
            release.priority(ego);                          // [ was 4 on ladder
            set.view(ego, v.ego);
            reposition.to(ego, 141, 134);
            start.motion(ego);
        }
    }
    else {                                                  // [ put him back on the ladder
        start.motion(ego);                                  // [ stop him
        reposition.to(ego, baseCenter, baseBottom);
        ignore.horizon(ego);
        ignore.blocks(ego);                                 // [ ladder crosses p1 line
        set.priority(ego, 11);                              // [ in front of ladder in this room
        set.view(ego, v.ego.climbing.ladder);
        current.status = climbing;
        set.loop(ego, 0);                                   // [ back loop
        fix.loop(ego);
    }
}

// [******* SAID STUFF ********]

if ((said(look, room) || said(look))) {
    if (egoLoc == captain) {
        #message 2  "This must be the Captain's cabin. He seems to be
a bit more tidy than his mates, as the room is cleanand orderly.
Against one wall rests his bunk with a large chest at its foot.
Across the room is his desk with a chart tacked to the wall.";
    }
    if (egoLoc == hold) {
        #message 3  "You look curiously around. Out a porthole you see the swell of the
ocean.A device for turning the ship's rudder sets in the floor.
A rope ladder extends up through an opening in the ceiling.";
    }
}

if ((said(look$in, hold) || said(look, hold))) {
    if (egoLoc == hold) {
        #message 4  "You peer into the dark opening. It's impossible to make out any details.";
    }
    else {
        #message 1  "You can't see that very well from here.";
    }
}
if (said(look, under, bed)) {
    #message 26  "You see nothing you haven't seen before.";
}

if (said(look, bed)) {
    if (egoLoc == captain) {
        if (crewAsleep && shipShape != atBeach) {
            #message 27  "The captain is snoring peacefully in his bunk.";
        }
        else {
            #message 6  "The Captain's bunk has been very neatly made. You look it over
carefully, but find nothing of interest.";
        }
    }
    else {
        #message 1  "You can't see that very well from here.";
    }
}

if ((said(look, man, on, bed) ||
    said(look, man, bed) ||
    said(look, man))) {
    if (egoLoc == captain) {
        #message 27  "The captain is snoring peacefully in his bunk.";
    }
    else {
        #message 5  "You can't see anything from here.";
    }
}

if (said(look, ladder)) {
    if (egoLoc == hold) {
        #message 7  "The rope ladder is still there.";
    }
    else {
        #message 1  "You can't see that very well from here.";
    }
}

if ((said(look, out, porthole) || said(look, porthole))) {
    if (egoLoc == hold) {
        #message 8  "You see the rise and fall of the ocean as you gaze out the porthole.";
    }
    else {
        #message 1  "You can't see that very well from here.";
    }
}

if (chestOpen) {
    stop.update(aChest);
}

// [ implement GET STUFF ROL

if ((said(look, chest) ||
    said(get, stuff, rol) ||
    said(look$in, chest))) {
    if (egoLoc == hold) {
        #message 1  "You can't see that very well from here.";
    }
    else {
        if (!chestOpen) {
            #message 9  "The chest at the foot of the Captain's bunk is closed.";
        }
        else {
            distance(ego, aChest, work);
            if (work > 18) {
                #message 21  "The open chest bears closer examination.";
            }
            else {
                if (dontHaveStuff) {                        // [ get it back
                    reset(dontHaveStuff);
                    #message 20  "You've found all of your missing possessions! You
take them with you.";
                                                            // [ give it back to him
                    if (!found.stuff.once) {
                        score += 3;
                        set(found.stuff.once);
                    }
                    work = first.item;
                    hiding.place = inventory;
                    :giveloop
                        if (work < size.of.inventory) {
                            get.room.f(work, scan.room)
                                if (scan.room == current.room) {
                                    put.f(work, hiding.place);      // [ inventory
                                }
                            ++work;
                            goto giveloop;
                        }
                }
                else {
                    #message 17  "You look in the chest and find nothing.";
                }
            }
        }
    }
}

if ((said(look$in, desk) || said(look$in, drawer) || said(look, desk))) {
    if (egoLoc == captain && posn(ego, 63, 112, 83, 120)) {
        #message 11  "You gaze with interest at the Captain's desk. The desk top is very
neat, holding only writing implements.Curiously, you open a drawer or
two.There is nothing of interest among the charts and logbooks.
Quickly, you close them again.";
    }
    else {
        #message 1  "You can't see that very well from here.";
    }
}
if ((said(look, chart) || said(look, chart, on, wall))) {
    if (egoLoc == captain) {
        #message 12  "You stare at the chart tacked to the wall. It traces the route the
ship is now sailing.It leaves Llewdor, crossing a wide
ocean, and arriving at the foot of a mountain range.An \"X\" has
been marked at the arrival point.";
    }
    else {
        #message 1  "You can't see that very well from here.";
    }
}

if ((said(open, up, chest) || said(open, lid)
    || said(open, lid, chest) || said(open, chest))) {
    if (chestOpen) {
        #message 22  "The chest is already open.";
    }
    else {                                                  // [ is he close enough
        distance(ego, aChest, work);
        if (work > 18) {
            #message 10  "How do you propose to do that from where you're standing?";
        }
        else {
            start.update(aChest);
            set.cel(aChest, 0);
            end.of.loop(aChest, chestOpen);
        }
    }
}

if ((said(close, lid) || said(close, lid, chest) || said(close, chest))) {
    if (!chestOpen) {
        #message 23  "The chest is already closed.";
    }
    else {                                                  // [ is he close enough
        distance(ego, aChest, work);
        if (work > 18) {
            #message 10  "How do you propose to do that from where you're standing?";
        }
        else {
            start.update(aChest);
            set.cel(aChest, 3);
            reverse.loop(aChest, chestOpen);
            set.scan.start();
            if (chestOpen) {
                reset(chestOpen);
                stop.update(aChest);
                reset.scan.start();
            }
            return();
        }
    }
}

if ((said(lie, on, bed) || said(get, on, bed)
    || said(sleep, on, bed) || said(lie, on, bed) || said(lie, bed))) {
    if (egoLoc == captain) {
        #message 13  "You really have better things to do than lie around. It would be wise
to get out of there.";
    }
    else {
        #message 10  "How do you propose to do that from where you're standing?";
    }
}

if ((said(sit, on, chair) || said(sit, chair))) {
    if (egoLoc == captain) {
        #message 14  "You really have better things to do than sit around. It would be wise
to get out of there.";
    }
    else {
        #message 10  "How do you propose to do that from where you're standing?";
    }
}
if ((said(look$in, door) || said(look, door))) {
    if (egoLoc == captain) {
        #message 15  "Through one doorway, you see the rope ladder snaking its way down into
the cargo hold.Out the other, you see nothing but the endless ocean.";
    }
    else {
        #message 1  "You can't see that very well from here.";
    }
}

if ((said(look, window) || said(look, out, window))) {
    if (egoLoc == captain) {
        #message 25  "You look out the window and see the bright, blue ocean.";
    }
    else {
        #message 1  "You can't see that very well from here.";
    }
}

// [ ******* PAINLESS ROOM EXITS **********

// [ climbing up ladder
if (current.status == climbing && ego.y < 50) {
    new.room(80);
}

// [ climbing down ladder
if (current.status == climbing && ego.y > 143) {
    new.room(85);
}

// [ walking out on stern
if (obj.in.box(ego, 11, 114, 29, 130)) {
    new.room(82);
}

// [ out door at upper right
if (edge.ego.hit == right) {
    new.room(84);
}

return();

// :D
set.view(ego, v.ego.falling);
sound(s.ego.falling, sound.done);
ignore.blocks(ego);
move.obj.f(ego, ego.x, y, x, fallDone);
set.scan.start();
if (fallDone) {
    release.priority(ego);
    reset(fallDone);
    program.control();
    current.status = stunned;
    sound(s.ego.stunned, sDone);
    stunTimer = ego.stunned.time;
    set.view(ego, v.ego.stunned);
    set(keep.cycling);
    set.scan.start();
    if (aSecondPassed) {
        --stunTimer;
    }
    program.control();
    if (!stunTimer) {
        reset(keep.cycling);
        player.control();
        set.view(ego, v.ego);
        observe.blocks(ego);
        release.priority(ego);
        release.loop(ego);
        current.status = normal.ego;
        reset.scan.start();
    }
    if (stunTimer && sDone) {
        sound(s.ego.stunned, sDone);
    }
    return();
}


