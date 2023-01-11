// [logics for room 29 -- the beach cliff
// [  February 3, 1988

#include "gamedefs.al"
#include "rm29.msg"

#define  sound.done      lf0
#define  fall.done        lf1
#define  near.mistletoe      lf2

#define  test.x        lv0
#define  test.y        lv1
#define  test.timer      lv2

% object  a.pirate.ship      1
% object  a.smoke1        2
% object  a.smoke2        3
% object  a.mistletoe      4

if (init.log)
{
    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    map.area = map.llewdor;
    set(beenIn29);
    set.horizon(55);
    wiz.x = 88;
    wiz.y = 140;

    random(1, 3, work);
    if (work == 1)
    {
        landing.x = 23;
        landing.y = 110;
    }
    else
    {
        if (work == 2)
        {
            landing.x = 57;
            landing.y = 66;
        }
        else
        {
            landing.x = 106;
            landing.y = 145;
        }
    }

    load.view(v.ego.falling);
    load.view(v.smoke);
    load.logics(lgc.forest);
    load.logics(lgc.eagle.feather);
    load.logics(lgc.seagulls);
    load.logics(lgc.climbing);
    room.bottom = 222;

    if (obj.in.room(i.mistletoe, current.room))
    {
        load.view(v.mistletoe);
    }

                                                            // [  DON'T MUCK WITH THIS NEXT SECTION, OR THE DISCARD.VIEW'S WON'T WORK.

    if (shipShape == inPort)
    {
        load.view(v.pirate.ship);
    }
    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);
    if (shipShape == inPort)
    {
        add.to.pic(v.pirate.ship, 0, 0, 137, 47, 4, 4);
        discard.view(v.pirate.ship);
    }

    if (obj.in.room(i.mistletoe, current.room))
    {
        animate.obj(a.mistletoe);
        set.view(a.mistletoe, v.mistletoe);
        position(a.mistletoe, 23, 92);
        ignore.objs(a.mistletoe);
        set.priority(a.mistletoe, 11);
        draw(a.mistletoe);
        stop.update(a.mistletoe);
    }

    if (positionEgo)
    {
        if (previous.room == 15)
        {
            ego.x = 118;
            ego.y = 167;
        }

        if (previous.room == 14)
        {
            if (ego.x > 118)
            {
                ego.x = 118;
            }
        }

        if (previous.room == 24)
        {
            if (ego.x > 100)
            {
                ego.x = 100;
            }
        }
        position.v(ego, ego.x, ego.y);
    }

    if (drawEgo)
    {
        draw(ego);
    }

    animate.obj(a.smoke1);
    set.view(a.smoke1, v.smoke);
    work = 4;
    cycle.time(a.smoke1, work);
    ignore.horizon(a.smoke1);
    position(a.smoke1, 108, 27);
    set.loop(a.smoke1, 3);
    set.cel(a.smoke1, 3);
    draw(a.smoke1);

    animate.obj(a.smoke2);
    set.view(a.smoke2, v.smoke);
    cycle.time(a.smoke2, work);
    ignore.horizon(a.smoke2);
    position(a.smoke2, 122, 27);
    set.loop(a.smoke2, 3);
    draw(a.smoke2);

    work = smallGull;
    call(lgc.seagulls);
    reposition.to(aGull1, 99, 19);
    reposition.to(aGull2, 111, 11);

    call(lgc.climbing);
    call(lgc.eagle.feather);

    show.pic();

    return();

}

reset(near.mistletoe);
if (posn(ego, 10, 109, 27, 122))
{
    set(near.mistletoe);
}

// [*****
// [handle.input
// [*****
call(lgc.eagle.feather);

if (!have.input) { goto no.input; }

if ((said(look, town) ||
    said(look, house)))
{
    #message 1  "You see a small seaside village up the coast to the north. Smoke rises
lazily from chimneys and mingles with the ocean air.";
}

if (said(look, tree))
{
    if (!obj.in.room(i.mistletoe, current.room))
    {
        #message 11  "The trees are not as large, being so near the coast.";
    }
    else
    {
        #message 2  "One of the trees has a light-green colored plant growing upon it. On
closer inspection, you see that it's mistletoe.";
    }
}

// [  Handle the mistletoe:

if ((said(look, mistletoe) ||
    said(look, mistletoe, tree)))
{
    if (!near.mistletoe)
    {
        #message 2  "One of the trees has a light-green colored plant growing upon it. On
closer inspection, you see that it's mistletoe.";
    }
    else
    {
        if (obj.in.room(i.mistletoe, current.room))
        {
            #message 3  "The mistletoe hangs from the branches of the tree. There are a few dried
sprigs mingled with the green mistletoe.";
        }
        else
        {
            #message 17  "You look through the remaining mistletoe, but find none that is dry.";
        }
    }
}

if ((said(stand, under, mistletoe) ||
    said(kiss, under, mistletoe) ||
    said(kiss, mistletoe)))
{
    if (!near.mistletoe)
    {
        #message 5  "You are not close enough.";
    }
    else
    {
        #message 10  "You give yourself a big smack. (Is this fun?)";
    }
}

if ((said(get, mistletoe) ||
    said(get, mistletoe, tree) ||
    said(climb, tree, get, mistletoe)))
{
    if (!near.mistletoe)
    {
        #message 5  "You are not close enough.";
    }
    else
    {
        if (!obj.in.room(i.mistletoe, current.room))
        {
            #message 17  "You look through the remaining mistletoe, but find none that is dry.";
        }
        else
        {
            start.update(a.mistletoe);
            erase(a.mistletoe);
            get(i.mistletoe);
            score += 1;
            #message 4  "You search among the hanging mistletoe until you find a
sprig that has dried.You break it off, and carry it with you.";
        }
    }
}

if ((said(look, ship) ||
    said(look, boat) ||
    said(look, ship, pier)))
{
    if (shipShape == inPort)
    {
        #message 6  "There is a three-masted ship docked at the pier. By her sturdy lines and
broad beam, you guess it to be a merchant vessel, trading goods
in the town.";
    }
    else
    {
        #message 7  "Where?";
    }
}

if (said(look, pier))
{
    if (shipShape == inPort)
    {
        #message 8  "%m9 You see a vessel tied up there now!";
    }
    else
    {
        #message 9  "A pier extends from the village and out into the bay. It is built
of heavy timbers to withstand winter storms.";
    }
}

if ((said(look, ocean) ||
    said(look, beach)))
{
    #message 12  "You look out over the vast, blue-gray ocean. You wonder what lands and
people reside across it.If only you could know!";
}

if ((said(look) ||
    said(look, bluff)))
{
    #message 13  "You are standing atop a bluff overlooking the ocean, and see a village
to the north. % m14 The trees here are stunted and twisted by
strong ocean winds.";
}

if ((said(look, sky)))
{
    #message 16  "You see seagulls flying overhead.";
}

if ((said(look, ground) ||
    said(look, grass) ||
    said(look, down)))
{
    #message 14  "The soft grass of the forest has been replaced by the
coarse grass of the seashore.";
}

if ((said(jump, down) ||
    said(climb, down) ||
    said(climb, down, cliff)))
{
    #message 5  "You are not close enough.";
}

if ((said(climb, tree) ||
    said(climb, up, tree)))
{
    #message 15  "There is no need to climb this tree.";
}

// [*****
// :n
// [*****

if (hit.special && current.status != falling)               // [  edge.of.cliff
{
    get.priority(ego, ego.location);
    if ((ego.location == 13 ||
        ego.location == 11 ||
        ego.location == 9))
    {
        --ego.location;
    }
    else
    {
        if (ego.location < 9)
        {
            ego.location = 5;
        }
    }
    set.priority.v(ego, ego.location);

    ego.x += 6;
    if (ego.x > ego.falling.limit)
    {
        ego.x = ego.falling.limit;
    }
    reposition.to.v(ego, ego.x, ego.y);
    start.climbing = falling;
}

if (aSecondPassed &&
    shipShape == inPort &&
    !voyage.minutes &&
    voyage.seconds &&
    voyage.seconds < 30)
{
    voyage.seconds = 30;
}

// [*****
// [exit              // [  test for leaving the room
// [*****

call(lgc.seagulls);

if (edge.ego.hit == top)
{
    new.room(24);
}

if (edge.ego.hit == left)
{
    new.room(28);
}

if (edge.ego.hit == right)
{
    new.room(25);
}

if (edge.ego.hit == bottom)
{
    if (current.status == falling)
    {
        if (debugging)
        {
            set(doit);
        }
        else
        {
            new.room(30);
        }
    }
    else
    {
        if (ego.x > 110)
        {
            new.room(15);
        }
        else
        {
            new.room(14);
        }
    }
}
call(lgc.climbing);
call(lgc.forest);

