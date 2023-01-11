// [rm71.cg
// [front door of castle

#include  "gamedefs.reh"
#include  "rm71.msg"

#define  egoLoc      lv0
#define  near.door  1

#define  at.door    lf0

if (init.log) {
    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    landing.x = 57;
    landing.y = 153;

    map.area = map.daventry;

    set(beenIn71);
    animate.obj(aDoor);
    load.view(v.door.castle);
    set.view(aDoor, v.door.castle);
    position(aDoor, 104, 120);
    if (girlSaved) {
        set.cel(aDoor, 2);                                  // [open
    }
    else {
        set.cel(aDoor, 0);                                  // [closed
    }
    draw(aDoor);
    stop.update(aDoor);

    animate.obj(banners);
    load.view(v.castle.banners);
    set.view(banners, v.castle.banners);
    ignore.horizon(banners);
    if (girlSaved) {
        position(banners, 130, 16);
    }
    else {
        position(banners, 130, 34);
    }
    work = 3;
    cycle.time(banners, work);
    draw(banners);

    load.view.f(current.ego);
    set.view.f(ego, current.ego);
    if (positionEgo) {
        if (previous.room == 69) {
            position(ego, 89, 164);
        }
    }

    if (drawEgo) {
        draw(ego);
    }

    if (girlSaved) {
        load.logics(lgc.princess);
        call(lgc.princess);
    }

    show.pic();
    if (girlSaved) {
        move.obj(ego, 110, 120, 1, at.door);
        #message 2  "The castle doors are wide open to welcome home a
long - missing son, and a much - loved daughter.Atop the castle, the
banners proudly wave.The heavy feeling of
oppression is gone; hope has at last returned to Daventry!";
        prevent.input();
    }
    return();
}

// [******picture stuff * *****

ego.location = nowhere;
if (posn(ego, 102, 119, 121, 126)) {
    ego.location = near.door;
}

// [princess dynamic
if (girlSaved) {
    call(lgc.princess);
}

// [********SAID STUFF********]

if ((said(look) ||
    said(look, castle))) {
    if (!girlSaved) {
        #message 1  "You gaze sadly at the deteriorated castle. It's obvious that it was once
proud and beautiful.But now, its banners are torn,
its stonesand statue work crumbling, and the moat has been drained.
It's as if no one cares anymore.";
    }
    else {
        #message 2  "The castle doors are wide open to welcome home a
long - missing son, and a much - loved daughter.Atop the castle, the
banners proudly wave.The heavy feeling of
oppression is gone; hope has at last returned to Daventry!";
    }
}

if ((said(look, door, castle) ||
    said(look, door))) {
    if (!girlSaved) {
        #message 3  "The massive wooden doors of the castle are closed.";
    }
    else {
        #message 4  "%m2";
    }
}

if (said(speak, rol)) {
    #message 13  "No one answers.";
}

if (said(open, door)) {
    if (ego.location == near.door) {
        #message 5  "The huge doors of the castle are bolted shut. Try as you might, you
cannot open them.";
    }
    else {
        #message 12  "And just how do you intend to do that from where you're standing.";
    }
}

if (!girlSaved && (said(knock, door) || said(knock, on, door))) {
    if (ego.location == near.door) {
        #message 6  "You rap loudly upon the massive wooden doors of the castle. Hollowly,
emptily, the sound reverberates within.No one answers.";
    }
    else {
        #message 12  "And just how do you intend to do that from where you're standing.";
    }
}

if (said(unlock, door) && !girlSaved) {
    if (ego.location == near.door) {
        #message 7  "You obviously do not have the key to this castle.";
    }
    else {
        #message 12  "And just how do you intend to do that from where you're standing.";
    }
}
if (said(break, door) && !girlSaved) {
    if (ego.location == near.door) {
        #message 8  "Your body is no match for these huge wooden doors.";
    }
    else {
        #message 12  "And just how do you intend to do that from where you're standing.";
    }
}

if (said(look, flag)) {
    if (!girlSaved) {
        #message 9  "Sadly, the torn banners of the shabby castle fly at half staff.";
    }
    else {
        #message 10  "The worn banners atop the crumbling castle proudly wave.";
    }
}

if ((said(climb, moat) ||
    said(jump, moat) ||
    said(jump, over, moat) ||
    said(climb, down, moat) ||
    said(look, across, moat) ||
    said(look, moat))) {
    #message 11  "The moat is too wide and too deep to cross.
There is nothing of interest there, anyway.";
}

if (said(look, tree)) {
    #message 14  "A once green woodland spreads out before you. Now, its many trees
and bushes are cruelly charred.";
}

if (said(look, plant)) {
    #message 15  "You see no flowers about.";
}

if ((said(climb, up, tree) || said(climb, tree))) {
    #message 16  "There are no climbable trees around.";
}

if ((said(look, up, sky) || said(look, sky))) {
    #message 17  "The sky is blue and the sun is shining, but yet a feeling of sadness
lingers here.";
}

if ((said(look, on, ground) || said(look, ground))) {
    #message 18  "There is nothing interesting on the ground but green grass.";
}

// [******PAINLESS ROOM EXITS * *****

if (edge.ego.hit == right) {
    new.room(72);
}

if (edge.ego.hit == bottom) {
    new.room(69);
}

// [entering castle
if (girlSaved && posn(ego, 105, 121, 116, 122)) {
    new.room(73);
}

