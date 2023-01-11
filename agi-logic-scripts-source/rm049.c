// [logics for room 49 -- treasure island
// [ Logic:
// [  if crewAsleep
// [    we are unhindered in efforts to get treasure
// [  else
// [    we always have company

#include "rm49.msg"
#include "gamedefs.reh"
#include  "iv-names.h"

#define  caughtEgo  lf0
#define  egoDead  lf2
#define  following  lf3
#define  pirateCaughtEgo  lf4
#define  ego.dead  lf5                                      // [ killed by guard
#define  someoneHere  lf6
#define  first.said  lf7

if (init.log)
{
    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    load.sound(m.shark);
    reset(sound.done);

    load.logics(lgc.seagulls);
    load.logics(lgc.beach);
    load.logics(lgc.shovel);

                                                            // [ misc
    set.horizon(70);
    map.area = map.mountains;
    set(beenIn49);
    landing.x = 20;
    landing.y = 74;

                                                            // [ ego
    load.view(v.ego);
    load.view(v.ego.dead);
    load.view(v.ego.wading.deep);
    load.view(v.ego.swimming);
    load.view(v.ego.drowning);

    load.view.v(current.ego);
    set.view.f(ego, current.ego);

    if (positionEgo) {
        if (previous.room == 31) {
                                                            // [ the trap
        }
        if (previous.room == 48) {
                                                            // [ might need adjustment
        }
        if (previous.room == 51) {
            ego.x = 114;
            position.f(ego, ego.x, ego.y);
        }
        if (previous.room == 50) {
            ego.x = 24;
            position.f(ego, ego.x, ego.y);
        }
    }
    if (drawEgo) {
        draw(ego);
    }

                                                            // [ the shark
    animate.obj(aShark);
    load.view(v.sharkfin);
    set.view(aShark, v.sharkfin);
    position(aShark, 150, 150)
        object.on.water(aShark);
    draw(aShark);
    wander(aShark);
                                                            // [  set(following);

    if (shipShape == atBeach) {
        set(tooBusyForMap);
        set(someoneHere);
        animate.obj(aPirate);
        load.view(v.pirate.guard);
        load.view(v.attacking);
        set.view(aPirate, v.pirate.guard);
        position(aPirate, 80, 120);
        object.on.land(aPirate);
        if ((invisibleEgo || current.status != normal.ego)) {
            wander(aPirate);
        }
        else {
            follow.ego(aPirate, 5, pirateCaughtEgo);
        }
        draw(aPirate);
        obj.on.land(aPirate);
    }

    work = 0;
    call(lgc.seagulls);
    call(lgc.beach);
    call(lgc.shovel);

    show.pic();
    sound(m.shark, sound.done);
    return();

}                                                           // [  end INIT.LOG

if (said(look, shark)) {
    #message 4  "A prowling shark waits offshore.";
}

if (said(get, shark)) {
    #message 3  "You've got to be kidding.";
}

if (said(kill, shark)) {
    #message 9  "You have no way of killing a shark.";
}
if (said(talk, shark)) {
    #message 5  "He can't understand you.";
}

if (someoneHere && (said(get, man) || said(kill, man))) {
    #message 16  "You're no match for him!";
}

if (someoneHere && said(look, man)) {
    #message 14  "A nasty pirate is here!";
}

if (someoneHere && said(talk, man)) {
    #message 15  "\"Arrr! I'm gonna git ya laddie!\"";
}

if (said(climb, tree)) {
    #message 10  "You have better things to do than to try to climb this tree.";
}

if ((said(look) || said(look, beach))) {
    #message 6  "You are on a small beach to the south of a looming mountain range.";
}

if (said(look, mountain)) {
    #message 7  "To the north, a mountain range beckons.";
}

if (said(look, tree)) {
    #message 11  "A lone palm tree graces this beach.";
}

if (said(look, ground)) {
    #message 8  "Yep. It's sandy here.";
}

if (ego.poofing.done && someoneHere) {                      // [ handle a state change
    if (current.status != normal.ego) {
        start.cycling(aPirate);
        wander(aPirate);
    }
    else {
        start.cycling(aPirate);
        follow.ego(aPirate, 5, pirateCaughtEgo);
    }
}

if (someoneHere && !first.said) {
    set(first.said);
    #message 1  "Not again! One of the nasty pirates is here on the beach, and
he would like to capture you.You'd better run!";
}

// [ pirate business
if (pirateCaughtEgo) {
    reset(pirateCaughtEgo);
    if (!handsOff) {
        #message 12  "How could you! You let yourself get caught again! Well, it's curtains for
you this time.";
        set(handsOff);
        program.control();
        set.view(aPirate, v.attacking);
        set.cel(aPirate, 0);
        end.of.loop(aPirate, ego.dead);
    }
    else {
        stop.cycling(aPirate);
    }
}

if (ego.dead) {
    reset(ego.dead);
    set.view(ego, v.ego.dead);
    set(certain.death);
    reset(handsOff);
}

// [ shark business
if (caughtEgo && (current.status == swimming || current.status == wading)) {
    reset(caughtEgo);
    if (!handsOff) {
        set(handsOff);
        erase(aShark);
        stop.motion(ego);
        set(keep.cycling);
        current.status = drowning;
        set.view(ego, v.ego.drowning);
        set.cel(ego, 0);
        work = 4;
        cycle.time(ego, work);
        end.of.loop(ego, egoDead);
    }
}

if (egoDead) {
    reset(egoDead);
    erase(ego);
    set(certain.death);
    #message 2  "Gosh! You barely made a mouthful for that hungry shark!";
}

if ((current.status == wading || current.status == swimming)) {
    if (!following) {
        set(following);
        follow.ego(aShark, 8, caughtEgo);
    }
}
else {
    reset(caughtEgo);                                       // [ just in case
    if (following) {
        reset(following);
        wander(aShark);
    }
}

// [ try to keep shark looking good

if (obj.hit.edge == 4) {                                    // [ must change if obj number changes
    get.dir(aShark, work);
    if (edge.obj.hit == right) {
        if (work == 2) {
            work = 1;
        }
        if (work == 4) {
            work = 5);
        }
        set.dir(aShark, work);
    }
    if (edge.obj.hit == left) {
        if (work == 8) {
            work = 1;
        }
        if (work == 6) {
            work = 5);
        }
        set.dir(aShark, work);
    }
}

// [ swimming/wading/walking stuff

if (hit.special) {                                          // [ surf line
    set(on.water);
    if (current.status == swimming) {
        current.status = wading;
        set.view(ego, v.ego.wading.deep);
        reset(keep.cycling);
    }
    if (current.status == normal.ego) {
        current.status = wading;
        set.view(ego, v.ego.wading.deep);
    }
}

if (current.status == wading && !on.water && !hit.special) {  // [ get him out
    current.status = normal.ego;
    set.view(ego, v.ego);
}

if (on.water && current.status == wading
    && (posn(ego, 118, 140, 160, 167) || posn(ego, 138, 84, 160, 167))) {
    current.status = swimming;
    set.view(ego, v.ego.swimming);
    set(keep.cycling);
}

call(lgc.seagulls);
call(lgc.beach);
call(lgc.shovel);

// [*****
// :e
// [*****

if (edge.ego.hit == top) {
    if ((current.status == swimming || current.status == wading)) {
        set.view(ego, v.ego);
        current.view(ego, current.ego);
        reset(keep.cycling);
        current.status = normal.ego;
    }
    shipShape = departed;
    set(crewAsleep);
    if (ego.x > 76) {
        new.room(51);
    }
    else {
        new.room(50);
    }
}

if (edge.ego.hit == left) {
    new.room(48);
}

if ((edge.ego.hit == bottom || edge.ego.hit == right)) {
    if ((current.status == swimming || current.status == wading)) {
        set.view(ego, v.ego.swimming);
        current.view(ego, current.ego);
    }
    exit.edge = edge.ego.hit;
    new.room(31);
}

