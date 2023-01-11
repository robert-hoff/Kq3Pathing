// [logics for room 54 -- high in Snowy mountains; Abominable snowman territory.

#include  "rm54.msg"
#include  "gamedefs.reh"

// [%define  no.snowman      0  // [  from gamedefs.al
// [%define  lgc.snowman.loaded    1
// [%define  make.snowman.come    2
// [%define  snowman.init.done    3
// [%define  snowman.after.ego    4
// [%define  snowman.at.ego      5
// [%define  snowman.dragging.ego  6
// [%define  snowman.off.screen    7

#define  lcl.snowman.arrived    lf0

#define  snowman.location     lv0

% object  a.water        1

if (init.log)
{
    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    load.view(v.ego);
    map.area = map.mountains;
    set(beenIn54);
    landing.x = 95;
    landing.y = 83;

    set.horizon(75);

    load.view(v.ego.climbing);
    load.view(v.water.rm54);

    random(1, 2, work);
    if (handsOff) {
        work = 2;
    }

    if (work == 1)
    {
        load.logics(lgc.snowman);
        snowman.script = lgc.snowman.loaded;
        reset(snowman.on.screen);
        snowman.x = 144;
        snowman.y = 95;                                     // [  where ego is dragged to
    }
    else
    {
        snowman.script = no.snowman;
    }

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    animate.obj(a.water);
    set.view(a.water, v.water.rm54);
    position(a.water, 38, 167);
    ignore.objs(a.water);
    set.priority(a.water, 4);
    draw(a.water);

    if (positionEgo)
    {
        if (previous.room == 55)
        {
            position(ego, 153, 95);
        }
        else
        {
            if (previous.room == 53)
            {
                position(ego, 39, 167);
                set.view(ego, v.ego.climbing);
            }
        }
    }

    observe.blocks(ego);
    if (drawEgo) { draw(ego); }

    if (snowman.script == lgc.snowman.loaded)
    {
        call(lgc.snowman);
        set.priority(a.snowman, 4);
        position(a.snowman, 142, 77);
    }

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
    said(look, down)))
{
    #message 1  "You've reached the heights of the mountain range and
snow and ice surround you.You still see no
end to the mountains.It's bitterly cold, and you
shiver in your thin rags.A path, through the snow, leads onward.";
}

if (said(look, path))
{
    #message 2  "A path has been forged through the heavy snow.
You wonder who made the path as you see no sign of life.";
}

if ((said(look, plants) ||
    said(look, tree) ||
    said(pick, flowers) ||
    said(get, flowers) ||
    said(look, flowers)))
{
    #message 3  "Plants and trees are scarce in the snowy reaches of these mountains.";
}

if (said(look, ground))
{
    #message 4  "The ground is completely covered with cold, white snow.";
}

if (said(look, sky))
{
    #message 5  "The deep-blue sky contrasts sharply with the brilliant white mountain
peaks.You must admit, even while shivering, it is a beautiful sight.";
}

if ((said(climb, trees) ||
    said(climb, up, trees)))
{
    #message 6  "There are no trees here.";
}

if (said(look, snow))
{
    #message 7  "White snow blankets everything here in the upper reaches of the great
mountains.It's beautiful, but it is VERY cold.";
}

if (said(play, snow))
{
    #message 9  "Wheee!";
}

if ((said(look, stream) ||
    said(look, water) ||
    said(look$in, stream)))
{
    #message 8  "The runoff from melting snows feeds a tiny stream cascading down
through the jumble of stones.";
}

if ((said(drink, water) ||
    said(drink, water, stream) ||
    said(get, water) ||
    said(get, water, stream) ||
    said(get, drink) ||
    said(get, drink, stream) ||
    said(get, drink, water) ||
    said(get, drink, water, stream) ||
    said(drink, water, from, stream) ||
    said(get, water, from, stream) ||
    said(get, drink, from, stream) ||
    said(get, drink, water, from, stream)))
{
    if (ego.y > 107)
    {
        #message 10  "Ahhh. It tastes like Sierra water!";
    }
    else
    {
        #message 11  "Your arms are not that long.";
    }
}

// [*****
// :n
// [*****

if (current.status == normal.ego)
{
    if (ego.y > 121)
    {
        set.view(ego, v.ego.climbing);
    }
    else
    {
        set.view(ego, v.ego);
    }
}

// [*****
// :s
// [*****

if (ego.x > 70 &&
    !snowman.on.screen &&
    snowman.script == lgc.snowman.loaded)
{
    ++snowman.script;                                       // [  now ss = make.snowman.come;
}

if (snowman.on.screen)
{
    get.posn(a.snowman, x, y);
    if (y > 101)
    {
        set.priority(a.snowman, 15);
    }
    else
    {
        release.priority(a.snowman);
    }

    if (snowman.script == snowman.init.done)
    {
        ++snowman.script;                                   // [  ss = snowman.after.ego;
        snowman.location = 0;
        move.obj(a.snowman, 95, 77, snowman.step.size, lcl.snowman.arrived);
        ignore.blocks(a.snowman);
    }

    if (snowman.script == snowman.after.ego &&
        lcl.snowman.arrived)
    {
        reset(lcl.snowman.arrived);
        ++snowman.location;

        if (snowman.location == 1)
        {
            move.obj(a.snowman, 95, 95, snowman.step.size, lcl.snowman.arrived);
        }

        if (snowman.location == 2)
        {
            ignore.block(a.snowman);
            release.priority(a.snowman);
            follow.ego(a.snowman, snowman.grab.distance, snowman.arrived);
            snowman.location = 0;
            snowman.x = 144;
            snowman.y = 95;                                 // [  where ego is dragged to
        }
    }
}

// [*****
// :e
// [*****

if (snowman.script)
{
    call(lgc.snowman);
}

if (edge.ego.hit == bottom)
{
                                                            // [  set.view( ego, v.ego);
                                                            // [  current.ego = normal.ego;
    new.room(53);
}

if (edge.ego.hit == right)
{
    new.room(55);
}


