// [ rm68.cg
// [ The room with the well of souls

#include  "gamedefs.reh"
#include  "rm68.msg"

#define  hitBottom    lf0
#define  egoFalling  lf1

if (init.log) {
    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    set.horizon(48);
    map.area = map.daventry;
    set(beenIn68);

    landing.x = 99;
    landing.y = 89;
                                                            // [ sounds
    load.sound(s.ego.falling);

    load.view(v.ego);
    load.view(v.ego.falling);

    load.view.f(current.ego);
    set.view.f(ego, current.ego);
    if (positionEgo) {
        if (previous.room == 69) {
            position(ego, 73, 55);
        }
    }

    if (drawEgo) {
        draw(ego);
    }

    ignore.blocks(ego);                                     // [ anti-princess block at edge of chasm

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

if (ego.poofing.done) {
    ignore.blocks(ego);
}

// [****** PICTURE LOGIC ******]

// [ egoFalling in the chasm
if (!handsOff && hit.special && !egoFalling) {
    set(handsOff);
    prevent.input();
    set(egoFalling);
    ignore.blocks(ego);
    get.priority(ego, work);
    set.priority.f(ego, work);
    set.view(ego, v.ego.falling);
    work = 4;
    cycle.time(ego, work);
    x = ego.x;
    y = 164;
    work = 4;
    move.obj.f(ego, x, y, work, hitBottom);
    sound(s.ego.falling, sound.done);
}

if (hitBottom) {
    reset(hitBottom);
    erase(ego);
    set(certain.death);
    #message 12  "The treacherous chasm has claimed another victim.";
    reset(handsOff);
    return();
}

// [******** SAID STUFF ********]

if ((said(look, room) || said(look))) {
    #message 1  "The countryside of Daventry looks as if it had once been beautiful.
But now, trees are charred, a chasm splits the earth, and wildflowers no
longer grow.Nearby is an old, broken - down well that someone has
filled with rocks.It's useless now.";
}

if ((said(look, plant) || said(look, tree))) {
    #message 2  "Some plants and trees around Daventry have been burnt black and
leafless.";
}

if ((said(look, flower) || said(get, flower))) {
    #message 3  "Wildflowers no longer grow here.";
}

if (said(look, ground)) {
    #message 4  "There is nothing interesting on the ground but grass.";
}

if (said(look, sky)) {
    #message 5  "The sky is blue and the sun is shining, but yet a feeling of sadness
lingers here.";
}
if (said(climb, tree)) {
    #message 6  "There are no good climbing trees that you can see.";
}
if ((said(look, well) || said(look$in, well) || said(climb, well))) {
    #message 7  "The old well has been filled with rocks. It's useless. Like everything
 else in Daventry, the well gives a feeling of futileness.";
}
if ((said(look$in, chasm) || said(look, chasm) || said(look, over, chasm))) {
    #message 8  "A deep chasm splits the earth. Possibly, an earthquake ripped
 through Daventry at one time.Looking across the chasm, you see nothing
 but more charred countryside.";
}
if ((said(look, fence) || said(look, over, fence))) {
    #message 9  "A stone wall travels to the north and south. You see if you can climb
 it, but find it too high.There is nothing of any interest on the
 other side of the wall, anyway.";
}
if ((said(climb, fence) || said(climb, over, fence)
    || said(jump, fence) || said(jump, over, fence))) {
    #message 10  "%m9";
}
if ((said(jump, over, chasm) ||
    said(climb, chasm) ||
    said(climb, down, chasm) ||
    said(jump, down, chasm) ||
    said(go, across, chasm) ||
    said(jump, chasm))) {
    #message 11  "The chasm is much too wide to jump across, and too treacherous to
 climb.";
}

// [ ****** PAINLESS ROOM EXITS ******

if (edge.ego.hit == top) {
    new.room(69);
}

if (edge.ego.hit == right) {
    new.room(61);
}


