// [ rm65.cg
// [ standing outside the cave at the top

#include  "gamedefs.reh"
#include  "rm65.msg"

#define  egoFalling  lf0
#define  hitTimer    lv0

if (init.log) {
    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    set(beenIn65);
    map.area = map.clouds;

    set.horizon(37);

    landing.x = 30;
    landing.y = 90;

    if (girlSaved) {
        load.logics(lgc.princess);
    }

    load.view(v.ego);
    load.view(v.ego.falling);
    load.view.f(current.ego);
    set.view.f(ego, current.ego);

                                                            // [ sound stuff
    load.sound(s.ego.falling);

    if (positionEgo) {
    }

    if (drawEgo) {
        draw(ego);
    }

    show.pic();
    if (girlSaved) {
        call(lgc.princess);
    }
}

// [****** PICTURE LOGIC ******]

if (current.status == normal.ego && edge.ego.hit == top) {
    set(hit.special);
}

if (hit.special) {                                          // [falling off the edge
    #message 5  "You have skillfully detected the boundaries of cloud land. The rest
of your quest will go quickly...";
    erase(ego);
    hitTimer = 5;
    sound(s.ego.falling, sound.done);
    set.scan.start();
    if (aSecondPassed) {
        --hitTimer;
    }
    if (!hitTimer) {
        stop.sound();
        #message 6  "...downward!";
        reset.scan.start();
        set(certain.death);
    }
    return();
}

// [ princess dynamic
if (girlSaved) {
    call(lgc.princess);
}

if (spell.cast == sc.map) {
    spell.cast = 0;
    drop(i.magic.map);
    #message 7  "As you unroll the delicate map, it crumbles in the intense heat!";
}

// [******** SAID STUFF ********]

if ((said(look) || said(look, cloud))) {
    #message 1  "Looking around, you see clouds surrounding this small bit of land
like a white, cottony sea.Charred stumps of trees spoil the scene.";
}

if ((said(look, plant) ||
    said(look, tree) ||
    said(look, flower) ||
    said(pick, flower) ||
    said(climb, tree))) {
    #message 2  "All of the trees and plants in this area have been burnt to stumps
by the evil three - headed dragon!";
}

if (said(look, ground)) {
    #message 3  "The ground is moist from the constant presence of clouds, but yet
the trees are burnt and blackened.";
}

if ((said(look, up) ||
    said(look, up, sky) ||
    said(look, sky))) {
    #message 4  "The sky is blue and cloudless above this strange cloud land.";
}

// [ ****** PAINLESS ROOM EXITS ******

if (edge.ego.hit == 2) {                                    // [ right
    new.room(66);
}


