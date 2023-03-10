// [logics for room 48 -- beached near the boat

#include "rm48.msg"
#include "gamedefs.reh"

#define  struggles  lv0

#define  caughtEgo  lf0
#define  egoDead  lf1
#define  following  lf2

if (init.log) {

                                                            // [ this is opaque on purpose, but I made a picture of no ship there
    work = current.room;
    if (shipShape != atBeach) {
        work += 100;
    }

    load.pic(work);
    draw.pic(work);
    discard.pic(work);

    load.logics(lgc.beach);
    load.logics(lgc.seagulls);
    load.logics(lgc.shovel);

    load.sound(m.shark);

    if (!beenIn48) {
        score += 5;
        work = firstIn48;                                   // [ start at end of range
        :clrFlags
            if (work > lastIn48) {                          // [ equal to this rooms beenIn flag
                reset.v(work);
                --work;
                goto clrFlags;
            }
        set(beenIn48);
        set(beenIn49);
    }
    set.horizon(60);

    landing.x = 120;
    landing.y = 80;

                                                            // [ ego
    load.view.v(current.ego);
    load.view(v.ego);
    load.view(v.ego.wading.deep);
    load.view(v.ego.swimming);
    load.view(v.ego.drowning);                              // [ for shark byte

    set.view.f(ego, current.ego);
    if (positionEgo) {
        get.posn(ego, ego.x, ego.y);
        if (map.area == map.ship) {                         // [ we just jumped ship
            ego.x = 20;
            ego.y = 74;
            ego.dir = 5;
            current.status = swimming;
            set.view(ego, v.ego.swimming);
        }
        if (previous.room == 49) {
                                                            // [ might require some tuning
        }
    }

    if (drawEgo) {
        draw(ego);
    }

    map.area = map.mountains;

                                                            // [ the shark
    animate.obj(aShark);
    load.view(v.sharkfin);
    set.view(aShark, v.sharkfin);
    position(aShark, 0, 60)
        object.on.water(aShark);
    draw(aShark);
    wander(aShark);
    reset(following);

    work = 0;                                               // [ small gulls

    call(lgc.seagulls);
    call(lgc.beach);
    call(lgc.shovel);

    show.pic();
    sound(m.shark, sound.done);
    return();
}

if (said(look, shark)) {
    #message 2  "A prowling shark waits offshore.";
}

if (said(get, shark)) {
    #message 3  "You've got to be kidding?!";
}

if (said(kill, shark)) {
    #message 10  "You have no way of killing a shark.";
}

if (said(talk, shark)) {
    #message 11  "He doesn't understand you.";
}

if ((said(look, ship) || said(look, pirate, ship))) {
    if (shipShape == atBeach) {
        #message 4  "The pirate ship is anchored just offshore. You'd best
 be on your way.";
    }
    else {
        #message 5  "The pirate's ship is nowhere in sight!";
    }
}

if ((said(look) || said(look, beach))) {
    #message 6  "You are on a small beach to the south of a looming mountain range.";
}

if (said(look, ground)) {
    #message 8  "Yep. It's sandy here.";
}

if (said(look, tree)) {
    #message 9  "You see no trees.";
}

if (said(look, mountains)) {
    #message 7  "To the north, a mountain range beckons.";
}

// [ shark business
if (caughtEgo && (current.status == swimming || current.status == wading)) {
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

if (egoDead) {
    reset(egoDead);
    erase(ego);
    set(certain.death);
    #message 1  "Gosh! You barely made a mouthful for that hungry shark!";
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

if (on.water && current.status == wading && posn(ego, 0, 0, 70, 168)) {
    current.status = swimming;
    set.view(ego, v.ego.swimming);
    set(on.water);
}

call(lgc.beach);
call(lgc.seagulls);
call(lgc.shovel);

// [*****
// :e
// [*****

if (edge.ego.hit == right) { new.room(49); }
if ((edge.ego.hit == left || edge.ego.hit == bottom)) {
    if ((current.status == swimming || current.status == wading)) {
        set.view(ego, v.ego.swimming);
        current.view(ego, current.ego);
        current.status = swimming;
    }
    exit.edge = edge.ego.hit;
    new.room(31);
}


w
