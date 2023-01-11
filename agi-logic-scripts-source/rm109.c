// [ LGC.BOX - Room 109. Logic for the stupid box on the ship

#include  "gamedefs.reh"
#include  "rm109.msg"

#define  booboo  dv0
#define  scratch  dv1

#define  onBox  df0
#define  loopDone  df1
#define  jumpDone  df2

#define  ladLeft  108
#define  ladLeftOn  110                                     // [ on ladder, base positioning
#define  ladTop  20
#define  ladRight  118
#define  ladBottom  94

// [ top of box
#define  boxLeft  104
#define  boxTop  119
#define  boxRight  121
#define  boxBottom  124
#define  boxCenter  111                                     // [ for gettting on box

// [ jump box for getting on
#define  jmpLeft  96
#define  jmpTop  136
#define  jmpRight  131
#define  jmpBottom  150

#define  boxBaseY  148                                      // [ for jumping off
#define  floorRight 125
#define  floorLeft  90
#define  floorCenter 142

if (init.log) {
    if (boxYpos == 0) {                                     // [ set origin of box in room 86
        boxState = 86;
        boxXpos = 58;
        boxYpos = 151;
    }
    animate.obj(aBox);
    load.view(v.pirate.ship.box);
    set.view(aBox, v.pirate.ship.box);
    position.f(aBox, boxXpos, boxYpos);                     // [ maintanined globally
    if (boxState == current.room) {                         // [ only if in room
        draw(aBox);
    }
    return();
}

// [ get off small box by moving at all

if (current.status == on.small.box) {
    if (ego.dir) {
        prevent.input();
        get.posn(aBox, ego.x, ego.y);
        ego.y -= 1;                                         // [ 1 above base line
        reposition.to.f(ego, ego.x, ego.y);
        start.motion(ego);
        current.status = normal.ego;
        release.priority(ego);
        observe.blocks(ego);
        accept.input();
    }
}

// [ walking off the big box

if (current.status == on.big.box && hit.special) {
    prevent.input();
    set(no.cycling);
    ignore.blocks(ego);                                     // [ float over the dotted lines
    ignore.objs(ego);

                                                            // [ which side did he go to
    if ((ego.dir == 2 || ego.dir == 3 || ego.dir == 4)) {   // [ right side
        move.obj(ego, floorRight, boxBaseY, 6, jumpDone);
    }
    else {
        if ((ego.dir == 6 || ego.dir == 7 || ego.dir == 8)) {  // [ left side
            move.obj(ego, floorLeft, boxBaseY, 6, jumpDone);
        }
        else {
            release.priority(ego);
            y = floorCenter;
            scratch = 6;
            move.obj.f(ego, ego.x, y, scratch, jumpDone);
        }
    }
    set.scan.start();
    if (jumpDone) {
        reset(no.cycling);
        observe.blocks(ego);
        observe.objs(ego);
        current.status = normal.ego;
        release.priority(ego);
        accept.input();
        reset.scan.start();
    }
    return();
}

// [ while we're here...
// [ sleep spell detection
if (spell.cast == sc.start.sleep) {
    #message 12  "As your sleep spell takes effect, a silence suddenly descends over
the ship.";
    spell.cast = 0;                                         // [ cancel before room 0 says something
    set(crewAsleep);
    voyage.seconds = 0;
    voyage.minutes = 0;
    if (shipShape == underWay) {
        set(handsOff);
        booboo = 10;
        prevent.input();
        program.control();
    }
}

if (aSecondPassed && booboo) {
    --booboo;
    if (booboo == 7) {
        set.loop(ego, facing.front);
    }
    if (booboo == 5) {
        #message 13  "\"Wait a second...\"";
        #message 14  "\"Who's steering the ship?\" you ask.";
    }
    if (booboo == 0) {
        #message 15  "Unfortunately, there is no reply.";
        #message 19  "With no one to steer the ship, you are doomed to drift at sea forever.";
        stop.cycling(ego);
        set(certain.death);
    }
}

// [ box can be gotten or dropped anywhere
// [ I must be careful that my saids don't trip all over themselves

if (said(look, box)) {
    if (current.room == 85) {
        if (boxState == current.room) {
            #message 7  "%m6 There is also a smaller crate here.";
        }
        else {
            #message 6  "You notice many crates and boxes in the cargo hold. One, in particular,
captures your attention, for it lies directly under the dangling rope
ladder!";
        }
    }
    else {
        if (boxState == current.room) {
            #message 9  "%m8 There is also a smaller crate here.";
        }
        else {
            #message 8  "Large wooden crates are stacked along one wall of the hold.";
        }
    }
}

if ((said(open, up, crate) || said(open, box))) {
    #message 1  "The crates are sealed tightly. You can't open them no matter what you do.";
}

if ((said(pick, up, box) || said(get, box))) {
    if ((handsOff ||
        current.status != normal.ego))
    {
        #message 18  "You can't do that... at least not now!";
    }
    else {
        if (boxState != current.room) {
            #message 10  "All of the large crates are too heavy to move.";                                      // [ not on floor here
        }
        else {
            distance(ego, aBox, work);                      // [ try to pick it up
            if (work < 12) {                                // [ we got it
                boxState = 0;                               // [ give it to ego
                erase(aBox);
                set.view(ego, v.ego.carrying.box);
                current.status = carrying.box;
                set(handsOff);
            }
            else {
                #message 3  "You're not close enough.";
            }
        }
    }
}

if ((said(drop, box, down) ||
    said(drop, down, box) ||
    said(drop, box, on, floor) ||
    said(drop, box, down, on, floor) ||
    said(drop, box))) {
    if (boxState != 0) {                                    // [ ego is not carrying it
        #message 5  "You're not carrying a box, are you?";
    }
    else {
        boxState = current.room;
                                                            // [ put box at his feet
        reset(handsOff);
        boxXpos = ego.x;
        boxYpos = ego.y;
        current.loop(ego, work);                            // [ 0 = right
        set.view(ego, v.ego);
        if (work == 0) {
            boxXpos += 6;                                   // [ add ego baseline
        }
        else {
            ego.x += 6;                                     // [ move ego back
            reposition.to.f(ego, ego.x, ego.y);
        }
        position.f(aBox, boxXpos, boxYpos);
        draw(aBox);
        current.status = normal.ego;
    }
}

if (said(move, box)) {
    #message 10  "All of the large crates are too heavy to move.";
}

if ((said(look$in, box) || said(open, up, box) || said(open, box))) {
    #message 4  "All of the crates are nailed shut. You have no means of opening them.";
}

if ((said(get, on, box) || said(climb, on, box) || said(climb, box))) {
    #message 11  "Why don't you try jumping.";
}

// [ stuff to handle jumping on boxes

// [ jumping around the room

if ((said(jump) || said(jump, up) ||
    said(jump, up, ladder) ||
    said(jump, up, on, ladder) ||
    said(jump, on, ladder) ||
    said(jump, ladder))) {
    if (current.status != on.big.box) {
        goto JumpInPlace;
    }
    else {
                                                            // [ get on the ladder
        set(keep.cycling);
        set.view(ego, v.ego.jumping);
        set.cel(ego, 0);
        end.of.loop(ego, jumpDone);
        set.scan.start();
        if (jumpDone) {                                     // [ move to the ladder
            reset(keep.cycling);
            set(no.cycling);
            set.view(ego, v.ego.climbing.ladder);
            set.loop(ego, 0);                               // [ back view
            fix.loop(ego);
            work = -11;
            reposition(ego, zero, work);                    // [ align the views
            move.obj(ego, ladLeftOn, ladBottom, 4, jumpDone);
            release.priority(ego);
            ignore.blocks(ego);
            set.scan.start();
            if (jumpDone) {                                 // [ on the ladder now
                reset(jumpDone);
                reset(no.cycling);
                reposition.to(ego, ladLeftOn, ladBottom);
                current.status = climbing;
                reset.scan.start();
            }
        }
        return();
    }
}

// [ from someplace to a box
if ((said(jump) ||
    said(jump, box) ||
    said(jump, up) ||
    said(jump, up, box) ||
    said(jump, on, box) ||
    said(jump, up, on, box))) {
    if (current.status == on.small.box) {
        if (!posn(aBox, 93, 140, 127, 151)) {
            goto JumpInPlace;
        }
        else {
            ignore.blocks(ego);
            set.view(ego, v.ego.jumping);
            set.cel(ego, 0);
            move.obj(ego, 110, 122, 1, jumpDone);
            set.scan.start();
            current.cel(ego, work);
            if (work == 2) {
                set(no.cycling);
                work = -11;
                set.view(ego, v.ego);
                reset(no.cycling);
                reposition(ego, zero, work);
                set.scan.start();
                set.priority(ego, 13);
                if (jumpDone) {
                    reset(jumpDone);
                    current.status = on.big.box;
                    set.priority(ego, 13);
                    observe.blocks(ego);
                    reset.scan.start();
                }
            }
        }
        return();
    }                                                       // [ on.small.box

    if (current.status == normal.ego) {
        distance(ego, aBox, work);
        if (work > 16) {
            goto JumpInPlace;
        }
        else {
            start.motion(ego);
            set.view(ego, v.ego.jumping);
            set.cel(ego, 0);
            end.of.loop(ego, loopDone);
            set(keep.cycling);
            ego.dir = 0;
            get.priority(ego, work);
            set.priority.f(ego, work);
            ignore.blocks(ego);
                                                            // [ limit the scan here
            set.scan.start();
            if (loopDone) {
                reset(loopDone);
                get.position(aBox, x, y);
                x += 2;
                y -= 10;
                erase(ego);
                set.view(ego, v.ego);                       // [ for the rest of the journey
                position.f(ego, x, y);
                draw(ego);
                reset(keep.cycling);
                current.status = on.small.box;
                start.motion(ego);
                reset.scan.start();
            }
        }
        return();
    }                                                       // [ normal.ego jump
                                                            // [ here is where a little hop in place is done if conditions allow

    :JumpInPlace

        if (current.status == carrying.box) {
            #message 16  "You can't jump while you are carrying a crate around.";
            return();
        }
    if (current.status == climbing) {
        #message 17  "Now is not the time to be jumping.";
        return();
    }
    start.motion(ego);
    set.view(ego, v.ego.jumping);
    set.cel(ego, 0);
    set(keep.cycling);
    end.of.loop(ego, jumpDone);
    set.scan.start();
    edge.ego.hit = 0;
    if (jumpDone) {
        reverse.loop(ego, jumpDone);
        set.scan.start();
        edge.ego.hit = 0;
        if (jumpDone) {
            reset(jumpDone);
            normal.cycle(ego);
            set.view(ego, v.ego);
            reset(keep.cycling);
            reset.scan.start();
        }
    }
    return();
}                                                           // [ end of jump to box saids

