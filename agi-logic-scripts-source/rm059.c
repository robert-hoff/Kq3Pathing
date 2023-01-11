// [logics for room 59 -- Further down the mountains.

#include  "rm59.msg"
#include  "gamedefs.reh"

if (init.log)
{
    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    load.view(v.ego);
    map.area = map.mountains;
    set(beenIn59);
    landing.x = 150;
    landing.y = 126;

    set.horizon(1);

    load.logics(lgc.climbing);
    room.bottom = 166;

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    if (positionEgo)
    {
        if (previous.room == 58)
        {
            position(ego, 0, 49);
        }
    }

    if (drawEgo) { draw(ego); }

    call(lgc.climbing);

    show.pic();
    return();

}

// [*****
// :h
// [*****

if (!have.input) { goto no.input; }

if ((said(look, mountain) ||
    said(look, up, mountain) ||
    said(look, up) ||
    said(look) ||
    said(look, room) ||
    said(look, down))) {
    #message 1  "You carefully make your way down the eastern side of these mountains.
The path travels
along the top of a narrow ridge.Looking back, you see the snowy
peaks through which you so recently journeyed.Whew!You wipe your brow as
you feel the worst is now behind you.";
}

if (said(look, path)) { #message 2  "You are trekking along a steep ridgetop on a treacherous path. One wrong
step could mean instant death.Be careful!"; }

if ((said(look, plants) ||
    said(look, tree))) {
    #message 3  "You see numerous evergreen trees and bushes. The forest is very tranquil.";
}

if (said(look, ground)) { #message 4  "The ground is covered with a crunchy carpet of pine needles."; }

if (said(look, sky)) { #message 5  "Looking back, you see snow-capped peaks thrusting their way upward
toward an azure sky."; }

if ((said(climb, trees) ||
    said(climb, up, trees))) {
    #message 6  "There are no climbable trees here.";
}

if ((said(pick, flowers) ||
    said(get, flowers) ||
    said(look, flowers))) {
    #message 7  "You see no flowers around here.";
}

// [*****
// :n
// [*****

ego.location = 0;

if (hit.special)
{
    start.climbing = falling;

    if ((posn(ego, 0, 37, 44, 51) ||                        // [  the far side of the mountain
        posn(ego, 39, 51, 108, 64) ||
        posn(ego, 108, 61, 159, 71)))
    {
        ego.location = 1;
        set.priority(ego, 4);
    }
    else
    {
        set.priority(ego, 7);

        if (posn(ego, 90, 79, 130, 94))                     // [  in the "crotch" of the corner
        {
            ego.location = 2;
            ego.x = 90;
            reposition.to.v(ego, ego.x, ego.y);
        }
        else
        {
            ego.location = 3;                               // [  everywhere else is easy
        }
    }
}

// [*****
// :e
// [*****

call(lgc.climbing);

if (edge.ego.hit == bottom) { new.room(61); }
if (edge.ego.hit == left) { new.room(58); }


