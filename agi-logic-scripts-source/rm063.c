// [ rm63.cg
// [ on switch back cave stairs

#include  "gamedefs.reh"
#include  "rm63.msg"

#define  egoFalling  lf0
#define  hitBottom  lf1

if (init.log) {
    map.area = map.clouds;
    set(beenIn63);
    set(interiorRoom);

    landing.x = 92;
    landing.y = 156;

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    load.view(v.ego);
    load.view(v.ego.falling);
    load.view.f(current.ego);
    set.view.f(ego, current.ego);

                                                            // [ sound stuff
    load.sound(s.ego.falling);

    if (positionEgo) {
        if (previous.room == 62) {
            position(ego, 92, 165);
        }
        if (previous.room == 64) {
            position(ego, 45, 39);
        }
    }
    if (current.status == deferred.entry) {
        set.view(ego, v.ego);
        set(positionEgo);
        position.f(ego, landing.x, landing.y);
        set(drawEgo);
    }

    if (drawEgo) {
        draw(ego);
    }

    if (girlSaved) {
        load.logics(lgc.princess);
        call(lgc.princess);
    }

    show.pic();
    return();
}

// [******** PICTURE LOGIC ********]

// [ egoFalling off the stairs
if (!handsOff && hit.special && !egoFalling) {
    set(handsOff);
    prevent.input();
    set(egoFalling);
    ignore.blocks(ego);
    set.view(ego, v.ego.falling);
    sound(s.ego.falling, sound.done);
    work = 4;
    cycle.time(ego, work);
    x = ego.x;
    y = 164;
    work = 3;
    set.priority(ego, 15);
    move.obj.f(ego, x, y, work, hitBottom);
}

if (hitBottom) {
    reset(handsOff);
    reset(hitBottom);
    erase(ego);
    set(certain.death);
    #message 5  "Darn those steps!";
}

// [ princess dynamic
if (girlSaved) {
    call(lgc.princess);
}

// [******** SAID STUFF ********]
if ((said(look, up) || said(look, down) || said(look) || said(look, cave))) {
    #message 1  "Crumbled stone steps go upward into the depths of this mountain. To
your amazement, you see light coming down from above.
Looking down, you see the stairs steeply descending below you.";
}
if ((said(look, up, stairs) || said(look, down, stairs) || said(look, stairs))) {
    #message 2  "The stone steps go up into the very depths of this mountain. Not only
are they crumbly, but they are also very steep!";
}

// [ ****** PAINLESS ROOM EXITS ******

if (edge.ego.hit == 3) {
    new.room(62);
}

if (edge.ego.hit == 1) {
    new.room(64);
}


