// [logics for room 50 -- Bottom of Cliff Mays

#include  "rm50.msg"
#include  "gamedefs.reh"

if (init.log)
{
    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    load.view(v.ego);
    map.area = map.mountains;
    landing.x = 127;
    landing.y = 96;

    set(survivable.fall);
    load.logics(lgc.climbing);
                                                            // [  handle room.bottom dynamically below

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    if (positionEgo)
    {
        if (previous.room == 49)
        {
            if (ego.x < 18)
            {
                ego.x = 18;
            }
        }
        else
        {
            if (previous.room == 51)
            {
                if (ego.y < 55 && ego.y > 47)               // [  on upper ramp
                {
                    ego.y = 47;
                }
                if (ego.y < 96 && ego.y > 94)               // [  on middle ramp
                {
                    ego.y = 94;
                }
                if (ego.y < 87 && ego.y > 84)               // [  on middle ramp also
                {
                    ego.y = 87;
                }
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
    said(look, room) ||
    said(look, up)))
{
    #message 1  "You are at the foot of a high, snowy mountain range. A cliff looms
before you with a tricky path winding its way up the steep face.";
}

if ((said(look, path) ||
    said(look, up, path)))
{
    #message 2  "The narrow path winding up the steep cliff looks precarious and
confusing. \"Must I climb this?\" you wonder.";
}

if ((said(look, plants) ||
    said(look, trees) ||
    said(pick, flowers) ||
    said(get, flowers) ||
    said(look, flowers)))
{
    #message 3  "The shrubbery is scant here, growing only between boulders.";
}

if (said(look, ground))
{
    #message 4  "The ground is strewn with large boulders.";
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

if (has(i.shovel))
{
    if ((said(dig, hole) ||
        said(dig) ||
        said(dig, hole, ground) ||
        said(dig, with, shovel)))
    {
        #message 7  "Not here.";
    }
}

// [*****
// :n
// [*****

ego.location = 0;

if (ego.y > 62)
{
    ego.location = 1;
    room.bottom = 120;
}
else
{
    if (ego.x < 80)
    {
        ego.location = 2;
        room.bottom = 79;
    }
    else
    {
        ego.location = 3;
        room.bottom = 87;
    }
}

if (current.status == normal.ego)
{
    if (on.water)
    {
        set.view(ego, v.ego.climbing);
    }
    else
    {
        set.view(ego, v.ego);
    }
}

// [*****
// :e
// [*****

call(lgc.climbing);

if (edge.ego.hit == bottom) { new.room(49); }
if (edge.ego.hit == right) { new.room(51); }


