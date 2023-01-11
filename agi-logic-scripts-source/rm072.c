// [ rm72.cg
// [ standing outside the castle at right end of moat

#include  "gamedefs.reh"
#include  "rm72.msg"

if (init.log) {
    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    landing.x = 90;
    landing.y = 153;

    map.area = map.daventry;

    set(beenIn72);

    animate.obj(banners);
    load.view(v.castle.banners);
    set.view(banners, v.castle.banners);
    ignore.horizon(banners);
    if (girlSaved) {
        position(banners, 5, 18);
    }
    else {
        position(banners, 5, 34);
    }
    draw(banners);

    load.view.f(current.ego);
    set.view.f(ego, current.ego);
    if (positionEgo) {
        if (previous.room == 71) {
            position(ego, 0, 153);
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
    return();
}

// [ princess dynamic
if (girlSaved) {
    call(lgc.princess);
}

// [******** SAID STUFF ********]

if ((said(look) || said(look, castle))) {
    if (!girlSaved) {
        #message 1  "You gaze sadly at the shabby castle. It's obvious that it was once a
proud and beautiful place.But now, its banners are torn,
its stonesand statue work are crumbling, and the moat has been drained.
It's as if no one cares anymore.";
    }
    else {
        #message 2  "Atop the castle, the banners are proudly waving. The heavy feeling of
oppression is gone; hope has at last returned to Daventry!";
    }
}

if (said(look, flag)) {
    if (!girlSaved) {
        #message 9  "Sadly, the torn banners of the shabby castle are flying at half-mast.";
    }
    else {
        #message 10  "The worn banners atop the crumbling castle proudly wave.";
    }
}

if ((said(climb, moat) ||
    said(jump, moat) ||
    said(jump, over, moat) ||
    said(climb, down, moat) ||
    said(look, moat))) {
    #message 11  "The moat is too wide to cross. There is nothing of interest there, anyway.";
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

// [ ****** PAINLESS ROOM EXITS ******

if (edge.ego.hit == left) {
    new.room(71);
}

if (edge.ego.hit == bottom) {
    new.room(69);
}


