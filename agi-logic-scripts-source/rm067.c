// [ rm67.cg
// [ standing outside the cave at the top

#include  "gamedefs.reh"
#include  "rm67.msg"

#define  hitTimer  lv0

#define  script  lv10
#define  next    lf10

if (init.log) {
    map.area = map.clouds;

    set.horizon(55);

    landing.x = 30;
    landing.y = 90;

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

                                                            // [ sound stuff
    load.sound(s.ego.falling);

    load.view.f(current.ego);
    set.view.f(ego, current.ego);
    if (positionEgo) {
        if (previous.room == 64) {
            position(ego, 123, 102);
        }
    }
    if (drawEgo) {
        draw(ego);
    }

    if (girlSaved) {
        position(ego, 0, 105);
                                                            // [    set(next);
        load.logics(lgc.princess);
        call(lgc.princess);
    }

    show.pic();
    return();
}

if (next && script == 0) {
    ++script;
    program.control();
    move.obj(ego, 160, 105, 1, next);
}

if (!beenIn67) {
    set(beenIn67) {
        #message 8  "It feels strangely hot up here.";
    }

                                                            // [ princess dynamic
    if (girlSaved) {
        call(lgc.princess);
    }

    if (spell.cast == sc.map) {
        spell.cast = 0;
        drop(i.magic.map);
        #message 12  "As you unroll the delicate map, it crumbles in the intense heat!";
    }

                                                            // [****** PICTURE LOGIC ******]

    if (current.status == normal.ego &&                     // [  falling off the edge
        (ego.y > 162 ||
            edge.ego.hit == right ||
            edge.ego.hit == top))
    {
        #message 10  "This mystical cloud land may never cease to amaze you, but...";
        sound(s.ego.falling, sound.done);
        erase(ego);
        hitTimer = 2;
        set.scan.start();
        if (aSecondPassed) {
            --hitTimer;
        }
        if (!hitTimer) {
            #message 11  "...it has ceased to support you!  Enjoy the trip.";
            reset.scan.start();
            set(certain.death);
        }
        return();
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

    if (said(look, sky)) {
        #message 4  "The sky is blue and cloudless above this strange cloud land.";
    }

    if (said(look, ground)) {
        #message 5  "This is a very strange cloud land. There is just a bit of land dotted
with charred trees encircled by a sea of white, fluffy clouds.This
gives you the odd feeling of floating upon a cottony ocean.A cave
entrance leads into a steep mountainside.";
    }

    if (said(look, mountain)) {
        #message 6  "The mountain rises steeply from this bizarre cloud land.  A cave goes
into its depths.";
    }

    if (said(climb, mountain)) {
        #message 7  "The mountain is unclimbable as it is much too steep and rocky.";
    }

    if ((said(look, cave) || said(look$in, cave))) {
        #message 9  "The cave leads deep into the steep mountainside. Within, crumbly stone
steps lead downward to murky depths.";
    }

                                                            // [ ****** PAINLESS ROOM EXITS ******

    if (hit.special) {                                      // [ inside cave mouth
        new.room(64);
    }

    if (edge.ego.hit == 4) {                                // [ left
        new.room(66);
    }

