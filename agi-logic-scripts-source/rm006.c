// [logics for room 6 -- rm.kitchen

#include  "rm6.msg"
#include  "gamedefs.al"
#include  "rm-names.h"
#include  "iv-views.h"

#define  seconds.to.sweep    26

#define  c.broom        0                                   // [  cel #'s of v.kitchen.stuff
#define  c.knife        1
#define  c.spoon        2
#define  c.mutton        3
#define  c.bread        4
#define  c.fruit        5
#define  c.bowl        6

#define  table        1                                     // [  "ego.location" values.
#define  shelf        2
#define  rack          3

#define  floor.y        134

#define  get.all.food      lf0
#define  get.bread        lf1
#define  get.fruit        lf2
#define  get.mutton      lf3
#define  sound.done      lf4
#define  ego.hit.floor      lf5
#define  house.wiz.init'd    lf6
#define  start.sweeping      lf7
#define  next.wiz.script    lf8
#define  sweep.done      lf9

#define  ego.stunned.seconds    lv0
#define  sweep.seconds      lv1
#define  moving.timer      lv2
#define  wriggle.timer      lv3
#define  sweeping.timer      lv4
#define  lcl.wiz.seconds    lv5
#define  lcl.wiz.script      lv6

% object  a.broom        1
% object  a.knife        2
% object  a.spoon        3
% object  a.bowl        4
% object  a.bread        5
% object  a.fruit        6
% object  a.mutton        7

if (init.log)
{
    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    load.view(v.ego);
    map.area = map.wiz.house;
    landing.x = 77;
    landing.y = 147;
    wiz.x = 105;
    wiz.y = 147;

    cat.x = 70;
    cat.y = 123;
    load.logics(lgc.wiz.house);
    obj.on.water(a.cat);

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    load.view(v.kitchen.stuff);
    load.view(v.ego.sweeping);

    if (current.status == hanging.in.kitchen)
    {
        load.logics(lgc.inventory.check);                   // [  just in case of a wizzie!!
        load.view(v.wiz);
        load.sound(s.ego.poofing);
        load.sound(m.wiz);

        load.sound(s.ego.falling);
        load.sound(s.ego.stunned);
        load.view(v.poof);
    }
    else
    {
        if ((wiz.away.asleep == home.after.bed ||           // [  If we're home, and he's
            wiz.away.asleep == home.after.town) &&
            !chore.to.do&&
            wiz.status != dead)
        {
            random(1, 4, work);
            if (work == 1)                                  // [  home, he may drop in.
            {
                load.logics(lgc.house.wiz);
                set(lgc.house.wiz.loaded);
                random(6, 12, wiz.entrance.time);           // [  he's coming later
            }
        }
    }

    animate.obj(a.broom);
    position(a.broom, 63, 119);
    set.view(a.broom, v.kitchen.stuff);
    set.cel(a.broom, c.broom);
    stop.cycling(a.broom);
    ignore.blocks(a.broom);
    draw(a.broom);
    stop.update(a.broom);

    if (obj.in.room(i.knife, current.room))
    {
        animate.obj(a.knife);
        position(a.knife, 62, 92);
        set.view(a.knife, v.kitchen.stuff);
        set.cel(a.knife, c.knife);
        stop.cycling(a.knife);
        draw(a.knife);
        stop.update(a.knife);
    }

    if (obj.in.room(i.spoon, current.room))
    {
        animate.obj(a.spoon);
        position(a.spoon, 65, 93);
        set.view(a.spoon, v.kitchen.stuff);
        set.cel(a.spoon, c.spoon);
        stop.cycling(a.spoon);
        draw(a.spoon);
        stop.update(a.spoon);
    }

    if (obj.in.room(i.mutton, current.room))
    {
        animate.obj(a.mutton);
        position(a.mutton, 125, 105);
        set.view(a.mutton, v.kitchen.stuff);
        set.cel(a.mutton, c.mutton);
        stop.cycling(a.mutton);
        draw(a.mutton);
        stop.update(a.mutton);
    }

    if (obj.in.room(i.bread, current.room))
    {
        animate.obj(a.bread);
        position(a.bread, 127, 112);
        set.view(a.bread, v.kitchen.stuff);
        set.cel(a.bread, c.bread);
        stop.cycling(a.bread);
        draw(a.bread);
        stop.update(a.bread);
    }

    if (obj.in.room(i.fruit, current.room))
    {
        animate.obj(a.fruit);
        position(a.fruit, 131, 122);
        set.view(a.fruit, v.kitchen.stuff);
        set.cel(a.fruit, c.fruit);
        stop.cycling(a.fruit);
        draw(a.fruit);
        stop.update(a.fruit);
    }

    if (obj.in.room(i.bowl, current.room))
    {
        animate.obj(a.bowl);
        position(a.bowl, 32, 74);
        set.view(a.bowl, v.kitchen.stuff);
        set.cel(a.bowl, c.bowl);
        stop.cycling(a.bowl);
        draw(a.bowl);
        stop.update(a.bowl);
    }

    if (current.status == fly)
    {
        set(positionEgo);
    }

    if (positionEgo)
    {
        if (previous.room == rm.dining)
        {
            position(ego, 104, 166);
        }
        else
        {
            position.v(ego, landing.x, landing.y);
        }
    }

    call(lgc.wiz.house);

    if (lgc.house.wiz.loaded)
    {
        call(lgc.house.wiz);
    }

    if (current.status == hanging.in.kitchen)
    {
        load.view(v.ego.hanging.in.kitchen);                // [  These are discarded at
        load.view(v.ego.falling);                           // [end of stunned.timer, so they are
        load.view(v.ego.stunned);                           // [loaded last, after calling house.wiz

        reset(drawEgo);
        set(positionEgo);
        start.a.poof = poof.in;
        set(handsOff);
        set.view(ego, v.ego.hanging.in.kitchen);
        position(ego, 72, 78);
    }

    if (drawEgo)
    {
        draw(ego);
    }

    if (current.status == hanging.in.kitchen)
    {
        set(drawEgo);                                       // [  to fool rm0 into !drawing him
    }

    show.pic();

    return();

}

if (posn(ego, 111, 124, 159, 150))
{
    ego.location = table;
}
else
{
    if (posn(ego, 55, 123, 70, 133))
    {
        ego.location = rack;
    }
    else
    {
        if (posn(ego, 10, 123, 54, 133))
        {
            ego.location = shelf;
        }
        else
        {
            ego.location = 0;
        }
    }
}

// [*****
// :h
// [*****

if (!have.input) { goto no.input; }

if (current.status == hanging.in.kitchen)
{
    #message 61  ".won taht od t'nac uoY";
    if (!debugging)
    {
        set(have.match);
    }
    goto no.input;
}

if (current.status == sweeping)
{
    #message 62  "You're too busy sweeping.";
    if (!debugging)
    {
        set(have.match);
    }
    goto no.input;
}

// [  HANDLE LOOKING AROUND.

if ((said(look, room) ||
    said(look, house) ||
    said(look) ||
    said(look, kitchen)))
{
    #message 1  "This is the kitchen of the wizard's house. Other than your own bed
chamber, this is the only place in the house that you feel you can call
\"your own.\" The wizard rarely enters the kitchen.
On cold days, the fireplace is a cozy place to sit.";
}

if ((said(look, fireplace) ||
    said(look$in, fireplace)))
{
    #message 3  "As it is now summer, the need to light a fire and cook hot food was
diminished.The fireplace is, at the moment, not burning.";
}

if ((said(look, barrel) ||
    said(look$in, barrel) ||
    said(get, barrel)))
{
    #message 36  "The barrels only contain foodstuffs. They are too huge to move.";
}

if (said(look, table))
{
    #message 5  "You use the heavy oak table when you prepare food for the wizard.";

    if (obj.in.room(i.bread, current.room) &&
        obj.in.room(i.fruit, current.room) &&
        obj.in.room(i.mutton, current.room))
    {
        #message 6  "%m11%m7,%m8, and%m9%m12.";
    }
    else
    {
        if (obj.in.room(i.bread, current.room) &&
            obj.in.room(i.fruit, current.room))
        {
            #message 15  "%m11%m7 and%m8%m12.";
        }
        else
        {
            if (obj.in.room(i.bread, current.room) &&
                obj.in.room(i.mutton, current.room))
            {
                #message 16  "%m11%m7 and%m9%m12.";
            }
            else
            {
                if (obj.in.room(i.fruit, current.room) &&
                    obj.in.room(i.mutton, current.room))
                {
                    #message 17  "%m11%m8 and%m9%m12.";
                }
                else
                {
                    if (obj.in.room(i.bread, current.room))
                    {
                        #message 10  "%m11%m7%m12.";
                    }
                    else
                    {
                        if (obj.in.room(i.fruit, current.room))
                        {
                            #message 13  "%m11%m8%m12.";
                        }
                        else
                        {
                            if (obj.in.room(i.mutton, current.room))
                            {
                                #message 14  "%m11%m9%m12.";
                            }
                        }
                    }
                }
            }
        }
    }
}

if (said(look, under, table))
{
    #message 25  "It's clean under there.";
}

if ((said(look, shelf) ||
    said(look, kitchen, shelf)))
{
    if (obj.in.room(i.bowl, current.room))
    {
        #message 18  "%m19 One useful item that catches your eye is the clay bowl you use
for all of your mixing.";
    }
    else
    {
        #message 19  "The kitchen shelf holds many ingredients and kitchen implements for cooking.";
    }
}

if (said(look, pots))
{
    #message 20  "There are pots, pans, and skillets hanging on the wall
beside the fireplace.";
}

if ((said(look, wall) ||
    said(look, rack) ||
    said(look, rack, wall)))
{
    #message 21  "There is an iron rack hanging on the wall by the fireplace.";
    if (obj.in.room(i.knife, current.room))
    {
        #message 22  "Your trusty knife%m24";
    }

    if (obj.in.room(i.spoon, current.room))
    {
        #message 23  "Your wooden serving spoon%m24";
    }
}

if (said(look, basket))
{
    #message 29  "There are large baskets hanging from the ceiling beam, and
smaller baskets on the kitchen shelves.";
}

if ((said(look, churn) ||
    said(look$in, churn)))
{
    #message 30  "Looking at the butter churn makes your muscles ache as you remember the
long hours churning cream to make butter.Otherwise, you have no
interest in it.";
}

if ((said(look, bucket) ||
    said(look$in, bucket)))
{
    #message 63  "It's just your old, oaken bucket.";
}

if ((said(look, ceiling) ||
    said(look, beam)))
{
    #message 31  "There are pots, pans, baskets, and drying herbs and spices hanging here.";
}

if (said(look, herbs))
{
    #message 59  "There are many hanging here. %m35";
}

// [  HANDLE GETTING STUFF.

if ((said(get, baskets) ||
    said(get, baskets, from, wall)))
{
    #message 32  "You can think of no use for baskets right now.";
}

if ((said(get, pots) ||
    said(get, pots, from, wall)))
{
    #message 33  "You are not in the mood for cooking at the moment, so the pots do not
interest you.";
}

if (said(get, churn))
{
    #message 30  "Looking at the butter churn makes your muscles ache as you remember the
long hours churning cream to make butter.Otherwise, you have no
interest in it.";
}

if ((said(get, rack) ||
    said(get, rack, from, wall)))
{
    #message 34  "The iron rack is securely attached to the wall. You cannot remove it no
matter how hard you try.";
}

if (said(get, herbs))
{
    #message 35  "You have no use for these particular herbs and spices.";
}

if ((said(get, all, food, table) ||
    said(get, food, table) ||
    said(get, food) ||
    said(get, all, food, from, table) ||
    said(get, food, from, table) ||
    said(get, all, food)))
{
    if (!obj.in.room(i.bread, current.room) &&
        !obj.in.room(i.fruit, current.room) &&
        !obj.in.room(i.mutton, current.room))
    {
        #message 45  "You already have it.";
    }
    else
    {
        set(get.all.food);
    }
}

if ((said(get, bread) ||
    said(get, bread, from, table) ||
    said(get, bread, table)))
{
    set(get.bread);
}

if ((said(get, fruit) ||
    said(get, fruit, from, table) ||
    said(get, fruit, table)))
{
    set(get.fruit);
}

if ((said(get, mutton) ||
    said(get, mutton, from, table) ||
    said(get, mutton, chop, from, table) ||
    said(get, mutton, chop)))
{
    set(get.mutton);
}

if ((said(get, spoon) ||
    said(get, spoon, rack) ||
    said(get, spoon, from, rack)))
{
    if (!obj.in.room(i.spoon, current.room))
    {
        #message 45  "You already have it.";
    }
    else
    {
        if (ego.location != rack)
        {
            #message 58  "You're too far away.";
        }
        else
        {
            #message 44  "You take the wooden spoon from the iron rack and keep it with you.";
            get(i.spoon);
            score += 1;
            start.update(a.spoon);
            erase(a.spoon);
        }
    }
}

if ((said(get, knife) ||
    said(get, knife, rack) ||
    said(get, knife, from, rack)))
{
    if (!obj.in.room(i.knife, current.room))
    {
        #message 45  "You already have it.";
    }
    else
    {
        if (ego.location != rack)
        {
            #message 58  "You're too far away.";
        }
        else
        {
            #message 46  "You take the carving knife from the iron rack and keep it with you.";
            get(i.knife);
            score += 1;
            start.update(a.knife);
            erase(a.knife);
        }
    }
}

if ((said(get, bowl, shelf) ||
    said(get, bowl, from, shelf) ||
    said(get, bowl)))
{
    if (!obj.in.room(i.bowl, current.room))
    {
        #message 45  "You already have it.";
    }
    else
    {
        if (ego.location != shelf)
        {
            #message 58  "You're too far away.";
        }
        else
        {
            #message 48  "You retrieve the clay bowl from the kitchen shelf and take it
with you.";
            get(i.bowl);
            score += 1;
            start.update(a.bowl);
            erase(a.bowl);
        }
    }
}

// [  HANDLE DOING STUFF.

if ((said(put, wood, fireplace) ||
    said(get, wood)))
{
    #message 4  "There is no need for you to start a fire in the fireplace, as it is now
summer and warm outside.";
}

if ((said(start, fire, fireplace) ||
    said(make, fire, fireplace) ||
    said(start, fire) ||
    said(light, fire) ||
    said(make, fire) ||
    said(light, fire, fireplace)))
{
    #message 4  "There is no need for you to start a fire in the fireplace, as it is now
summer and warm outside.";
}

if (!handsOff &&
    (said(clean, floor, with, broom) ||
        said(clean, floor) ||
        said(clean, kitchen) ||
        said(clean, kitchen, with, broom) ||
        said(use, broom, clean, kitchen) ||
        said(use, broom, clean, floor) ||
        said(use, broom, clean, room) ||
        said(clean, kitchen, floor) ||
        said(clean, room) ||
        said(clean, room, with, broom) ||
        said(get, broom)))
{
    if (ego.location != rack)
    {
        #message 58  "You're too far away.";
    }
    else
    {
        start.update(a.broom);
        erase(a.broom);

        set(handsOff);
        block(36, 120, 121, 154);
        get.posn(ego, source.x, source.y);
        sweep.seconds = seconds.to.sweep;
        current.status = sweeping;
        set.view(ego, v.ego.sweeping);
        program.control();
        set(keep.cycling);
        moving.timer = 0;
        sweeping.timer = 22;
        if (chore.to.do == clean.kitchen)
        {
            chore.to.do = 0;
            chore.minutes = 0;
            chore.seconds = 0;
        }
    }
}

// [*****
// :n
// [*****

// [  GETTING FOOD.

if ((get.all.food || get.bread))
{
    reset(get.bread);
    if (obj.in.room(i.bread, current.room))
    {
        if (ego.location != table)
        {
            reset(get.all.food);
            #message 57  "You aren't near the table.";
        }
        else
        {
            #message 38  "You take the loaf of bread and carry it with you.";
            get(i.bread);
            score += 1;
            start.update(a.bread);
            erase(a.bread);
        }
    }
    else
    {
        if (!get.all.food)
        {
            #message 45  "You already have it.";
        }
    }

    if (get.all.food)
    {
        set(get.fruit);
    }
}

if ((get.all.food || get.fruit))
{
    reset(get.fruit);
    if (obj.in.room(i.fruit, current.room))
    {
        if (ego.location != table)
        {
            reset(get.all.food);
            #message 57  "You aren't near the table.";
        }
        else
        {
            #message 40  "You take the fruit and carry it with you.";
            get(i.fruit);
            score += 1;
            start.update(a.fruit);
            erase(a.fruit);
        }
    }
    else
    {
        if (!get.all.food)
        {
            #message 45  "You already have it.";
        }
    }

    if (get.all.food)
    {
        set(get.mutton);
    }
}

if ((get.all.food || get.mutton))
{
    reset(get.mutton);
    if (obj.in.room(i.mutton, current.room))
    {
        if (ego.location != table)
        {
            reset(get.all.food);
            #message 57  "You aren't near the table.";
        }
        else
        {
            #message 42  "You take the mutton chop and carry it with you.";
            get(i.mutton);
            score += 1;
            start.update(a.mutton);
            erase(a.mutton);
        }
    }
    else
    {
        if (!get.all.food)
        {
            #message 45  "You already have it.";
        }
    }
    reset(get.all.food);
}

// [  CLEANING UP THE KITCHEN FLOOR.  IS EGO'S WORK NEVER DONE?

if (current.status == sweeping)
{
    if (aSecondPassed)
    {
        --sweep.seconds;
        if (sweep.seconds == 1)
        {
            sweep.seconds = 0;
            moving.timer = 0;
            sweeping.timer = 0;
            unblock();
            ignore.blocks(ego);
            ignore.objs(ego);
            move.obj(ego, 64, 125, 1, sweep.done);
        }
    }

    --moving.timer;
    if (moving.timer == 1)
    {
        start.motion(ego);
        wander(ego);
        random(11, 33, sweeping.timer);
    }

    --sweeping.timer;
    if (sweeping.timer == 1)
    {
        normal.motion(ego);
        stop.motion(ego);
        set.loop(ego, facing.front);
        random(11, 33, moving.timer);
    }
}

if (sweep.done)
{
    reset(sweep.done);
    reset(handsOff);
    player.control();
    observe.blocks(ego);
    observe.objs(ego);
    set.view(ego, v.ego);
    reset(keep.cycling);
    normal.motion(ego);
    current.status = normal.ego;
    draw(a.broom);
}

// [  PUNISHMENT STUFF.

if (ego.poofing.done)
{
    accept.input();
    reset(no.cycling);
    reset(ignore.special);
    reset(ignore.water);
    if (current.status == hanging.in.kitchen)
    {
        program.control();
        stop.motion(ego);
        #message 54  "You feel the blood rushing to your head as you realize that you are
upside - down.Straining to look up, you notice your feet have been
magically attached to a kitchen rafter.You struggle, but can't
release yourself.What a vexing situation!";
        ego.cycle.time = 2;
        cycle.time(ego, ego.cycle.time);
        wriggle.timer = 23;
    }
}

if (current.status == hanging.in.kitchen)
{
    --wriggle.timer;
    if (wriggle.timer == 12)
    {
        set(keep.cycling);
    }

    if (wriggle.timer == 1)
    {
        reset(keep.cycling);
        wriggle.timer = 44;
    }
}

if (punishment.done)
{
    reset(punishment.done);
    ignore.blocks(ego);
    ignore.objs(ego);
    set.priority(ego, 15);
    current.status = falling;
    prevent.input();
    program.control();
    set.view(ego, v.ego.falling);
    x = 4;
    y = 0;
    reposition(ego, x, y);
    set(keep.cycling);
    wriggle.timer = 0;
    ego.cycle.time = 1;
    cycle.time(ego, ego.cycle.time);
    y = floor.y;
    step = 3;
    sound(s.ego.falling, done);
    move.obj.v(ego, ego.x, y, step, ego.hit.floor);
}

if (ego.hit.floor)
{
    reset(ego.hit.floor);
    current.status = stunned;
    set.view(ego, v.ego.stunned);
    release.priority(ego);
    stop.motion(ego);
    prevent.input();
    program.control();
    set(keep.cycling);
    ego.stunned.seconds = ego.stunned.time;
    set(sound.done);
}

if (aSecondPassed)
{
    --lcl.wiz.seconds;
    if (lcl.wiz.seconds == 1)
    {
        set(next.wiz.script);
    }

    --ego.stunned.seconds;
    if (ego.stunned.seconds == 1)
    {
        current.status = normal.ego;
        player.control();
        accept.input();
        reset(handsOff);
        reset(keep.cycling);
        reset(sound.done);
        stop.sound();
        start.motion(ego);
        set.view(ego, v.ego);

        discard.view(v.ego.stunned);
        discard.view(v.ego.falling);
        discard.view(v.ego.hanging.in.kitchen);

        #message 60  "You feel dizzy and nauseated at the sudden changes in body position. It's
at least some consolation to find yourself on the floor again.";

        observe.blocks(ego);
        observe.objs(ego);
    }
}

if (sound.done && current.status == stunned)
{
    sound(s.ego.stunned, sound.done);
}

// [*****
// :e
// [*****

if (!moving.timer &&
    !sweep.seconds &&
    edge.ego.hit == bottom &&
    current.status != fly.landing &&
    ego.x > 99 && ego.x < 113)
{
    new.room(rm.dining);
}

call(lgc.wiz.house);

if (lgc.house.wiz.loaded)
{
    call(lgc.house.wiz);
}

