// [logics for room 58 -- Further down the mountain.

#include  "rm58.msg"
#include  "gamedefs.reh"

if (init.log)
{
    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    load.view(v.ego);
    map.area = map.mountains;
    set(beenIn58);
    landing.x = 60;
    landing.y = 111;

    set.horizon(1);

    load.logics(lgc.climbing);
    room.bottom = 166;

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    if (positionEgo)
    {
        if (previous.room == 57)
        {
            position(ego, 0, 138);
        }
        else
        {
            if (previous.room == 59)
            {
                position(ego, 152, 155);
            }
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
    said(look) ||
    said(look, up) ||
    said(look, room) ||
    said(look, down))) {
    #message 1  "You carefully make your way down the eastern side of these mountains.
The path travels
along the top of a narrow ridge.Looking back, you see the snowy
peaks through which you so recently journeyed.Whew!You wipe your brow as
you feel the worst is now behind you.";
}

if (said(look, path)) { #message 2  "You are walking along a steep ridgetop on a treacherous path. One wrong
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
    if (ego.y < 116)
    {
        ego.location = 1;
        set.priority(ego, 4);
    }
    else
    {
        if (posn(ego, 143, 138, 159, 145))
        {
            ego.location = 2;
            set.priority(ego, 9);
        }
        else
        {
            if (posn(ego, 126, 127, 144, 139))
            {
                ego.location = 3;
                set.priority(ego, 9);
            }
            else
            {
                ego.location = 4;
                set.priority(ego, 14);
            }
        }
    }
}

// [*****
// :e
// [*****

call(lgc.climbing);

if (edge.ego.hit == left) {
    if ((current.status == fly || current.status == eagle)) {
        edge.ego.hit = 0;
        spell.cast = sc.stop.flying;
    }
    else {
        new.room(57);
    }
}

if (edge.ego.hit == right) {
    new.room(59);
}


