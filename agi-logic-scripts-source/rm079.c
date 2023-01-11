// [ Room 79 - Galley at aft of ship.  Cook will be in here

#include "rm79.msg"
#include "gamedefs.reh"

#define  caughtEgo    lf0
#define  snore.done  lf1

#define  snore.timer  lv1

if (init.log) {
    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);
    load.logics(lgc.pirates);

                                                            // [ external stuff
    set(interiorRoom);
    landing.x = 107;
    landing.y = 150;
    wiz.x = 70;
    wiz.y = 150;
    map.area = map.ship;

    load.sound(m.badguy);
    load.sound(s.snoring);

    load.view(v.ego);                                       // [ get standard view
    set.view(ego, v.ego);
    load.view.f(current.ego);
    set.view.f(ego, current.ego);
    if (positionEgo) {
        start.motion(ego);
        ego.dir = 7;
        if (ego.y > 120) {
            position(ego, 120, 150);                        // [ down stage
        }
        else {
            position(ego, 86, 125);                         // [ upstage
        }
        get.posn(ego, ego.x, ego.y);
    }
    else {
        ego.y = landing.y;
    }

    if (drawEgo) {
        draw(ego);
    }

    if (current.status == poofing) {
        ego.y = landing.y;
    }

                                                            // [ set a cook to wandering or sleeping
    animate.obj(aPirate);
    load.view(v.pirate.cook);
    load.view(v.pirate.sleeping);
    if (crewAsleep) {
        snore.timer = SNOREDELAY;
        set.view(aPirate, v.pirate.sleeping);
        set.loop(aPirate, 2);
        work = 6;
        cycle.time(aPirate, work);
        set.priority(aPirate, 14);
        position(aPirate, 20, 152);
    }
    else {
        set(tooBusyForMap);
        work = 40;
        position.f(aPirate, work, ego.y);
        set.view(aPirate, v.pirate.cook);
        sound(m.badguy, sound.done);
        if (current.status == normal.ego) {
            follow.ego(aPirate, 10, caughtEgo);
        }
        else {
            stop.cycling(aPirate);
        }
    }
    draw(aPirate);

    show.pic();
    return();
}

--snore.timer;
if (snore.timer == 1) {
    sound(s.snoring, sound.done);
    set.cel(aPirate, 0);
    end.of.loop(aPirate, snore.done);
}

if (snore.done) {
    reset(snore.done);
    snore.timer = SNOREDELAY;
    stop.cycling(aPirate);
}

call(lgc.pirates);

if (ego.poofing.done && !crewAsleep) {
    if (current.status != normal.ego) {
        reset(caughtEgo);
        stop.cycling(aPirate);
        normal.motion(aPirate);
        stop.motion(aPirate);
    }
    else {
        start.cycling(aPirate);
        follow.ego(aPirate, 10, caughtEgo);
    }
}

// [ catching ego (routines are order dependent)
if (caughtEgo) {
    if (handsOff) {
        stop.cycling(aPirate);
        normal.motion(aPirate);
        stop.motion(aPirate);
    }
    else {
        reset(caughtEgo);
        #message 11  "\"What d'ya think yer up ta, boy!?\"";
        set(tossed.in);
        new.room(85);
    }
}

// [******* SAID STUFF *******]

if ((said(look) || said(look, room) || said(look, ship))) {
    #message 1  "This is the galley of the pirate ship. A large iron stove dominates one
wall.Pots, pans, and barrels surround it.There is a long dining table at
the other end of the room.";
}

if (said(look, man)) {
    if (!crewAsleep) {
        #message 3  "Get out of here before the ship's cook cuts you up!";
    }
    else {
        #message 2  "The ship's cook is fast asleep in the evening meal. His snores are so
loud they seem to rattle the walls.";
    }
}

if (said(look, stove)) {
    #message 4  "It's just an old wood stove used for cooking. Nothing special about it.";
}

if (said(look, pots)) {
    #message 5  "The pots and pans are used for cooking the pirate's meals.";
}
if (said(look, barrel)) {
    #message 6  "The barrel seems to be full of rum, but you have better things to do
at the moment than drink.";
}
if (said(look, table)) {
    #message 7  "The wooden dining table is not too clean. The remains of many meals
are lodged between the oaken planks.Its top is deeply gouged and stained.";
}
if (said(look, under, table)) {
    #message 8  "It's obvious the pirate's eating habits are less than desirable. You see
nothing but crumbs and stains under the table.";
}
if ((said(sit, down) || said(sit, table)
    || said(sit, down, table) || said(sit))) {
    #message 9  "You have better things to do than sit around.";
}
if ((said(look, door) || said(look, out, door))) {
    #message 10  "The sight of the rolling swells make you a little queasy. To your relief,
you see no pirates coming.";
}

// [ position set in 80
if (hit.special) {
    new.room(80);
}


