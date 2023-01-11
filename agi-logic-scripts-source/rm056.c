// [logics for room 56 -- More abominable snowman territory.

#include  "rm56.msg"
#include  "gamedefs.reh"

// [  If he's made it this far, there's a 100% chance of the snowman coming.
// [He'd better not be himself!!

// [%define  no.snowman      0
// [%define  lgc.snowman.loaded    1
// [%define  make.snowman.come    2
// [%define  snowman.init.done    3
// [%define  snowman.after.ego    4
// [%define  snowman.at.ego      5
// [%define  snowman.dragging.ego  6
// [%define  snowman.off.screen    7

#define  coming.in.for.a.landing  lf0

if (init.log)
{
    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    load.view(v.ego);
    map.area = map.mountains;
    set(beenIn56);
    landing.x = 44;
    landing.y = 154;
    set.horizon(114);

    load.logics(lgc.climbing);
    room.bottom = 166;

    if (previous.room == 55)
    {
        load.logics(lgc.snowman);
        snowman.script = lgc.snowman.loaded;
        reset(snowman.on.screen);
    }
    else
    {
        snowman.script = no.snowman;
    }

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    if (positionEgo)
    {
        if (previous.room == 57)
        {
            position(ego, 40, 167);
            if (current.status == climbing)
            {
                current.status = normal.ego;
                set.view(ego, v.ego);
            }
        }
        else
        {
            if (previous.room == 55)
            {
                position(ego, 0, 139);
            }
        }
    }

    observe.blocks(ego);
    if (drawEgo) { draw(ego); }

    call(lgc.climbing);

    if (snowman.script == lgc.snowman.loaded)
    {
        call(lgc.snowman);
        set.priority(a.snowman, 10);
        set.loop(a.snowman, facing.right);
        position(a.snowman, 0, 135);
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
    #message 1  "You have made the very top of the snowy mountain range. The
snow path ends here at a cliff.Far in the distance, you can see
a vast green valley. \"Could it be Daventry?\" you wonder. Your
excitement mounts.";
}

if (said(look, path))
{
    #message 2  "The snow path leads to the edge of a very steep precipice. You look
about, but see that there is no place to go but straight down.";
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

if (said(look, valley))
{
    #message 15  "That must be Daventry!";
    #message 16  "\"But why is Half Dome here?\" you wonder.";
    #message 17  "\"But, of course,\" you think, \"it's a Sierra game!\"";
}

// [*****
// :n
// [*****

if (ego.poofing.done) {
    if (current.status == normal.ego) {
        reset(coming.in.for.a.landing);                     // [ bottom of room trip wire
    }
}

ego.location = 0;
if (hit.special)
{
    if (ego.x < 114)                                        // [  avoid the P0 around that rock!
    {
        ego.location = 1;
        ego.x = 114;
        reposition.to.v(ego, ego.x, ego.y);
    }
    else
    {
        if (ego.y < 128)
        {
            ego.location = 2;
            set.priority(ego, 4);
        }
        else
        {
            if (posn(ego, 105, 130, 169, 160))
            {
                ego.location = 3;
                set.priority(ego, 11);
            }
            else
            {
                set.priority(ego, 14);
                ego.location = 4;

                if (ego.x > 140 &&
                    (ego.dir == ego.right ||
                        ego.dir == ego.up.right ||
                        ego.dir == ego.down.right))
                {
                    ego.location = 5;
                    ego.x += 4;
                    reposition.to.v(ego, ego.x, ego.y);
                }
            }
        }
    }
}

// [*****
// :s
// [*****

if (ego.x > 30 &&
    !snowman.on.screen &&
    snowman.script == lgc.snowman.loaded)
{
    ++snowman.script;                                       // [  now ss = make.snowman.come;
}

if (snowman.on.screen)
{
    if (snowman.script < snowman.dragging.ego)
    {
        get.posn(a.snowman, x, y);
        if (y > 111)
        {
            release.priority(a.snowman);
        }
        else
        {
            set.priority(a.snowman, 10);
        }
    }

    if (snowman.script == snowman.init.done)
    {
        ++snowman.script;                                   // [  now ss = snowman.after.ego;
        follow.ego(a.snowman, snowman.grab.distance, snowman.arrived);
        observe.blocks(a.snowman);
        snowman.x = 1;
        snowman.y = 135;                                    // [  where ego is dragged to
    }
}

// [*****
// :e
// [*****

call(lgc.climbing);

if (snowman.script)
{
    call(lgc.snowman);
}

// [if (invisibleEgo &&
// [  !coming.in.for.a.landing &&
// [  ego.y > 155)
// [  {
// [  set( coming.in.for.a.landing);
// [  print( 14);
// [  spell.cast = sc.visible;
// [  }

if (edge.ego.hit == bottom &&
    (current.status == eagle || current.status == fly)) {
        {
            edge.ego.hit = 0;
            spell.cast = sc.stop.flying;
        }

        if (edge.ego.hit == left)
        {
            new.room(55);
        }

        if (edge.ego.hit == bottom)
        {
            if (!beenIn57)
            {
                #message 13  "Bravely, you grasp the ice laden rocks, and attempt to scale the nearly
vertical wall.Be careful, Gwydion!";
            }
            set.view(ego, v.ego);
            current.ego = normal.ego;
            new.room(57);
        }

        
