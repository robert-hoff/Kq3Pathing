// [logics for room 52 -- A little higher up the mountains.

#include  "rm52.msg"
#include  "gamedefs.reh"

if (init.log)
{
    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    load.view(v.ego);
    map.area = map.mountains;
    set(beenIn52);
    landing.x = 50;
    landing.y = 93;

    set.horizon(35);

    load.logics(lgc.climbing);
    room.bottom = 166;

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    if (positionEgo)
    {
        if (previous.room == 53)
        {
            if (ego.y < 82)
            {
                ego.y = 82;
            }
            if (ego.y > 90)
            {
                ego.y = 90;
            }
        }
        else
        {
            if (previous.room == 51)
            {
                ego.x = 42;
                ego.y = 167;
            }
            else
            {
                ego.x = landing.x;
                ego.y = landing.y;
            }
        }
        position.v(ego, ego.x, ego.y);
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
    said(look, top, mountain) ||
    said(look, up, mountain) ||
    said(look) ||
    said(look, down) ||
    said(look, room) ||
    said(look, up)))
{
    #message 1  "The snow-capped mountains advance forever upward. A narrow path
skims along the top of a precipitous ridge.
As you look down, you see the steep cliff below you.";
}

if ((said(look, path) ||
    said(look, up, path)))
{
    #message 2  "The thin path runs along the top of a steep ridge. You must be very
careful as one wrong step will mean death!";
}

if ((said(look, plants) ||
    said(look, trees)))
{
    #message 3  "A forest begins, with tall evergreen trees and low bushes.";
}

if (said(look, ground))
{
    #message 4  "The ground goes... way up, or way down. Better be careful.";
}

if ((said(look, sky) ||
    said(look, up, sky)))
{
    #message 5  "You look upward and see the mountain range looming toward
the beautiful blue sky.";
}

if ((said(climb, trees) ||
    said(climb, up, trees)))
{
    #message 6  "There are no climbable trees here.";
}

if ((said(pick, flowers) ||
    said(get, flowers) ||
    said(look, flowers)))
{
    #message 7  "There are few flowers among the tall evergreens.";
}

// [*****
// :n
// [*****

ego.location = 1;
room.bottom = 166;

if (posn(ego, 0, 0, 48, 106))                               // [  left rear little special
{
    ego.location = 2;
    room.bottom = 156;
    if (hit.special)
    {
        set.priority(ego, 4);
        start.climbing = falling;
    }
}
else
{
    if (posn(ego, 55, 0, 84, 90))                           // [  right rear little special
    {
        ego.location = 3;
        if (hit.special)
        {
            set.priority(ego, 4);
            start.climbing = falling;
            if (ego.x > 76)
            {
                ego.location = 4;
                ego.x = 76;
                reposition.to.v(ego, ego.x, ego.y);
            }
        }
    }
    else
    {
        ego.location = 5;                                   // [  front edge, anywhere else
        if (hit.special)
        {
            set.priority(ego, 11);
            start.climbing = falling;

            if (ego.x < 33)
            {
                ego.x = 33;
                reposition.to.v(ego, ego.x, ego.y);
                room.bottom = 163;
            }
        }
    }
}

// [*****
// :e
// [*****

call(lgc.climbing);

if (edge.ego.hit == bottom) { new.room(51); }
if (edge.ego.hit == right) { new.room(53); }


