// [logics for room -- 35: Inside hole in bandit's tree

#include "gamedefs.reh"
#include "rm35.msg"

#define  said.it      lf1

if (init.log)
{

    load.view(v.ego);
    load.view.f(current.ego);
    set.view.f(ego, current.ego);

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    wiz.y = 0;                                              // [if set to 0 prevents wiz from entering room

    landing.x = 66;
    landing.y = 158;

                                                            // [ always a fly in this room
    set(positionEgo);                                       // [ tell room 0 we did it
    position(ego, 68, 145);
    set(keep.cycling);

    if (drawEgo) {
        draw(ego);
    }

    show.pic();
    return();

}

if (!said.it) {
    set(said.it);
    #message 1  "You have flown through the hole at the base of the tree
and are now inside the hollow trunk.You see a rope leading up into
a small hole above you.This area is cramped and confining,
even for a fly.";
}

if (spell.cast == sc.stop.flying) {
    #message 2  "You hope you'll be able to fit inside the tree in your normal form.";
    shake.screen(4);
    #message 5  "Obviously, your hopes were ill-founded. Too late, you realize you
are inside a tree, and... the results are too gruesome to discuss.";
    spell.cast = 0;
    erase(ego);
    set(certain.death);
    return();
}

// [*****
// :e
// [*****

if (ego.dir == 5) {
    new.room(22);
}
else {
    ego.dir = 0;
}


