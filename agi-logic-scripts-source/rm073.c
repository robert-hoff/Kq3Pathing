// [rm73.cg
// [first hallway in castle

#include  "gamedefs.reh"
#include  "rm73.msg"

#define  ego.there    lf0
#define  leaving    lf1

if (init.log) {
                                                            // [do some deferred disk I / O
    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    load.view.f(current.ego);
    set.view.f(ego, current.ego);

    landing.x = 76;
    landing.y = 160;

    set(interiorRoom);

    if (positionEgo) {
        if (previous.room == 71) {
            position(ego, 76, 163);
        }
    }
    if (!entered.castle) {
        set(entered.castle);
        score += 4;
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
    move.obj(ego, 71, 120, 1, ego.there);
    return();
}

// [princess dynamic
if (girlSaved) {
    call(lgc.princess);
}

if (ego.there && !leaving) {
    move.obj(ego, 0, 120, 1, ego.there);
    set(leaving);
}

// [*******SAID STUFF********]

if (said(look, castle)) {
    #message 1  "You and Princess Rosella have entered a hallway of the dilapidated
castle.Cracks mar the walls and dusty floor.Cobwebs drape an
overhanging lamp.Sadly, your sister remarks, \"Alexander, I wish you
could have seen it in better days.It wasn't always like this, you know.\"";
}

if (said(look, light)) {
    #message 2  "Cobwebs have not been cleaned from the overhanging chandelier.";
}

if (said(look, door)) {
    #message 3  "The doors of this castle are wide open.";
}

// [******PAINLESS ROOM EXITS * *****

if (edge.ego.hit == bottom) {
    new.room(71);
}

if (edge.ego.hit == 4) {
                                                            // [left
    new.room(74);
}

if (ego.there && leaving) {
    new.room(74);
}

