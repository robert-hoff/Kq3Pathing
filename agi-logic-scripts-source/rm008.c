// [logics for room 8 -- rm.dining

#include  "rm8.msg"
#include  "gamedefs.al"
#include  "rm-names.h"
#include  "iv-names.h"

// [  Wiz can poof in here.

// [  If (chore.to.do == feed.wiz), wiz is sitting at the table, waiting for
// [us everytime we pass through this room, until he's fed, or time's up. If ego
// [talks to wiz 2 times while wiz is hungry, wiz punishes ego.  Ego can feed
// [wiz, if he has food.  If ego feeds him, food appears on the table, wiz
// [eats, farts and leaves.

#define  c.mutton        3                                  // [  cel #'s of v.kitchen.stuff
#define  c.bread        4
#define  c.fruit        5
#define  c.porridge      7

#define  wiz.eat.time      23                               // [  real seconds
#define  ego.eat.time      22                               // [    "    "
#define  chewing.pause.time    15                           // [  cycles, not seconds

#define  something        255

#define  wiz.sitting      lf0
#define  house.wiz.init'd    lf1
#define  talked.to.wiz      lf2
#define  ego.eat.loop.done    lf3
#define  wiz.eat.loop.done    lf4
#define  make.ego.a.pussy    lf5
#define  make.wiz.a.pussy    lf6
#define  wiz.pussy.on.screen    lf7
#define  make.ego.rise      lf8

#define  wiz.eat.seconds    lv0
#define  wiz.chewing.timer    lv1
#define  ego.eat.seconds    lv2
#define  ego.chewing.timer    lv3
#define  ego.wants.to.eat    lv4
#define  wants.to.feed.wiz    lv5
#define  lcl.wiz.seconds    lv6
#define  ego.sit.timer      lv7

% object  aCandle1        1
% object  aCandle2        2
% object  aCandle3        3
% object  aCandle4        4
% object  a.food        5
% object  a.cup        6

if (init.log)
{
    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    load.view(v.ego);
    map.area = map.wiz.house;
    landing.x = 120;
    landing.y = 143;
    wiz.x = 29;
    wiz.y = 140;

    cat.x = 131;
    cat.y = 144;
    load.logics(lgc.wiz.house);

    if ((wiz.away.asleep == home.after.bed ||
        wiz.away.asleep == home.after.town) &&
        wiz.status != dead)
    {
        if (chore.to.do == fix.meal)                        // [  He's always here.
        {
            set(wiz.sitting);
            set(lgc.house.wiz.loaded);
            set(house.wiz.init'd);
                load.logics(lgc.house.wiz);
            wiz.entrance.time = 0;                          // [  He's always here now!
            load.view(v.wiz.eating);
        }
        else
        {
            random(1, 2, work);
            if (!chore.to.do&&
                work == 1)                                  // [  He's gonna poof in.
            {
                set(lgc.house.wiz.loaded);
                load.logics(lgc.house.wiz);
                random(6, 12, wiz.entrance.time);           // [  he's coming later
            }
        }
    }

    load.view(v.kitchen.stuff);
    load.view(v.ego.eating);
    load.view(v.candle.flame);
    load.view(v.tin.cup);
    load.sound(s.ego.poofing);

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    animate.obj(a.food);
    ignore.blocks(a.food);
    ignore.objs(a.food);
    position(a.food, 90, 121);
    set.view(a.food, v.kitchen.stuff);
    set.priority(a.food, 12);
    stop.cycling(a.food);

    animate.obj(aCandle1);
    ignore.horizon(aCandle1);
    position(aCandle1, 75, 81);                             // [  left front
    set.priority(aCandle1, 13);
    set.view(aCandle1, v.candle.flame);
    set.cel(aCandle1, 0);
    draw(aCandle1);

    animate.obj(aCandle2);
    ignore.horizon(aCandle2);
    position(aCandle2, 91, 81);                             // [  right front
    set.priority(aCandle2, 13);
    set.view(aCandle2, v.candle.flame);
    set.cel(aCandle2, 1);
    draw(aCandle2);

    animate.obj(aCandle3);
    ignore.horizon(aCandle3);
    position(aCandle3, 92, 75);                             // [  right rear
    set.priority(aCandle3, 12);
    set.view(aCandle3, v.candle.flame);
    set.cel(aCandle3, 1);
    draw(aCandle3);

    animate.obj(aCandle4);
    ignore.horizon(aCandle4);
    position(aCandle4, 78, 75);                             // [  left rear
    set.priority(aCandle4, 12);
    set.view(aCandle4, v.candle.flame);
    set.cel(aCandle4, 0);
    draw(aCandle4);

    if (obj.in.room(i.cup, current.room))
    {
        animate.obj(a.cup);
        ignore.blocks(a.cup);
        ignore.objs(a.cup);
        position(a.cup, 72, 123);
        set.view(a.cup, v.tin.cup);
        set.priority(a.cup, 12);
        draw(a.cup);
        stop.update(a.cup);
    }

    if ((positionEgo || current.status == fly))
    {
        if (previous.room == rm.entry)
        {
            position(ego, 26, 138);
        }
        else
        {
            if (previous.room == rm.kitchen)
            {
                position(ego, 104, 121);
            }
            else
            {
                position.v(ego, landing.x, landing.y);
            }
        }
    }

    if (drawEgo)
    {
        draw(ego);
    }

    call(lgc.wiz.house);

    if (lgc.house.wiz.loaded)
    {
        call(lgc.house.wiz);
        if (wiz.sitting)                                    // [  wiz waiting to munch
        {
            wiz.status = waiting.to.eat;
            ignore.objs(a.wiz);
            set.view(a.wiz, v.wiz.eating);
            position(a.wiz, 90, 119);
            wiz.x = 91;                                     // [  to fool lgc.PO'd.wiz
            wiz.y = 129;
            set.cel(a.wiz, 0);
            stop.cycling(a.wiz);
            draw(a.wiz);
            set(wiz.on.screen);
        }
    }

    show.pic();

    if (wiz.sitting)
    {
        sound(m.wiz, done);
        print.at(12, 2, 2, 37);
    }

    return();

}                                                           // [  end INIT.LOG

if (wiz.sitting)
{
    block(80, 119, 101, 131);
}
else
{
    unblock();
}

// [*****
// :h
// [*****

if (!have.input) { goto no.input; }

// [  FIRST, DO THE GENERIC STUFF:

if ((said(look, room) ||
    said(look, house) ||
    said(look)))
{
    #message 1  "This is where Manannan eats his meals. You, of course, are not supposed
to eat here.YOU eat in the kitchen.There is a pine table
and benches large enough to seat at least ten people; but the wizard has
never HAD any guests for dinner.";
}

if (said(look, table))
{
    #message 3  "The large dining table is made of pine planking.
Matching benches run its length on both sides.The
table is big enough to seat at least ten people.";
    if (obj.in.room(i.cup, current.room))
    {
        #message 21  "There is a little metal cup on the table.";
    }
}

if (obj.in.room(i.cup, current.room) &&
    said(look, cup))
{
    #message 21  "There is a little metal cup on the table.";
}

if ((said(look, top, table) ||
    said(look, top$of, table) ||
    said(look, table, top)))
{
    if (obj.in.room(i.cup, current.room))
    {
        #message 21  "There is a little metal cup on the table.";
    }
    else
    {
        #message 4  "There is nothing on the dining table. You keep it very clean as
Manannan will not eat on a dirty table.";
    }
}

if (said(look, under, table))
{
    #message 5  "You bend over and peer under the table. You see nothing but
a few crumbs left over from one of Manannan's meals.";
}

if ((said(look, moose) ||
    said(look, wall) ||
    said(look, moose, wall)))
{
    #message 8  "You scrutinize the moosehead very carefully. But, you see
it is nothing but an old head.You do feel sorry for the poor thing, though.";
}

if ((said(get, moose) ||
    said(get, moose, wall) ||
    said(get, moose, off, wall) ||
    said(remove, moose) ||
    said(remove, moose, wall)))
{
    #message 9  "The moosehead is securely fastened to the wall. You cannot remove it.";
}

if ((said(look, light) ||
    said(look, flame)))
{
    #message 10  "Flickering candles from the wrought iron lamp light the room.";
}

if (said(look, door))
{
    #message 11  "There are two doorways here. One leads to the kitchen,
the other to the entry hall.";
}

if ((said(get, cup) ||
    said(get, cup, table) ||
    said(get, cup, from, table)))
{
    if (!obj.in.room(i.cup, current.room))
    {
        #message 29  "You already took it.";
    }
    else
    {
        if (!posn(ego, 62, 126, 80, 150))
        {
            #message 23  "You're too far away.";
        }
        else
        {
            get(i.cup);
            score += 1;
            start.update(a.cup);
            erase(a.cup);
            #message 22  "You pick up the little tin cup and carry it with you.";
        }
    }
}

// [  HANDLE THAT ONCE IN A LIFETIME OPPORTUNITY!

if (wiz.pussy.on.screen)
{
    if (said(look, cat))
    {
        #message 33  "Manannan will never annoy anyone again.";
    }

    if (said(talk, cat))
    {
        #message 34  "Manannan seems unusually quiet, don't you think!";
    }

    if (said(anyword, cat))
    {
        #message 35  "You'd better get on with your quest. Manannan is no longer a bother to
anyone!";
    }
}

// [  NEXT, HANDLE EGO SITTING AND/OR EATING:

if ((said(sit, table) ||
    said(sit) ||
    said(sit, down) ||
    said(sit, down, table) ||
    said(sit, on, bench) ||
    said(sit, bench)))
{
    if (wiz.sitting)
    {
        #message 25  "Manannan wouldn't like that.";
    }
    else
    {
        if ((ego.y < 124 ||                                 // [  in doorway,
            ego.y > 152 ||                                  // [  in lower corners,
            ego.x < 41 ||                                   // [  could be in entry hall door
            ego.x > 152))                                   // [  could get trapped by table
        {
            #message 26  "You're too far from the table.";
        }
        else
        {
            if (!handsOff)
            {
                set(ego.arrived);
                ego.location = 0;
            }
            else
            {
                reset(have.match);                          // [  let rm100 handle it
            }
        }
    }
}

if ((said(leave, table) ||
    said(rise) ||
    said(get, up) ||
    said(get, up, from, table) ||
    said(leave, bench) ||
    said(stand, up)))
{
    if (current.status == sitting)
    {
        set(make.ego.rise);
    }
    else
    {
        if (current.status == eating)
        {
            #message 27  "Finish chewing first.";
        }
        else
        {
            #message 28  "You are standing.";
        }
    }
}

if (has(i.bread) &&
    (said(eat, bread) ||
        said(eat, food) ||
        said(eat, food, table)))
{
    ego.wants.to.eat = bread;
}

if (has(i.fruit) &&
    (said(eat, fruit) ||
        said(eat, food) ||
        said(eat, food, table)))
{
    ego.wants.to.eat = fruit;
}

if (has(i.mutton) &&
    (said(eat, mutton) ||
        said(eat, food) ||
        said(eat, food, table)))
{
    ego.wants.to.eat = mutton;
}

// [  ROOM SPECIFIC WIZARD SAIDS:

if (!wiz.sitting)
{
    if (wiz.on.screen && !PO'd.wiz.init'd &&
        (said(feed, wizard) ||
            said(feed, anyword, wizard) ||
            said(feed, anyword, anyword, wizard) ||
            said(feed, anyword, wizard, anyword) ||
            said(anyword, fruit, wizard) ||
            said(anyword, bread, wizard) ||
            said(anyword, mutton, wizard) ||
            said(fruit, anyword, wizard) ||
            said(bread, anyword, wizard) ||
            said(mutton, anyword, wizard)))
    {
        #message 24  "He doesn't seem to be hungry right now.";
    }
}
else
{
    if (said(look, wizard))
    {
        if (wiz.status == waiting.to.eat)
        {
            #message 12  "Manannan is impatiently waiting for his food! His
stomach rumbles as he drums his gnarled fingers on the
table.You'd better feed him quickly, or dire consequences may result.";
        }
        else
        {
            if (wiz.status == eating)
            {
                #message 2  "He seems to be quite hungry.";
            }
            else
            {
                reset(have.match);                          // [  let the dynamic have it
            }
        }
    }

    if ((said(talk, wizard) ||
        said(talk, to, wizard)))
    {
        if (wiz.status == eating)
        {
            #message 32  "He's too busy to reply.";
        }
        else
        {
            if (wiz.status == waiting.to.eat)
            {
                if (!talked.to.wiz)
                {
                    set(talked.to.wiz);
                    #message 13  "Manannan is out of sorts right now. \"Don't jabber
at me, boy!Bring me my food, NOW!\" he bellows.";
                }
                else
                {
                    #message 14  "After speaking to the grouchy wizard again, he narrows
his bushy - white eyebrows and looks at you with ill - temper. \"You're
awfully thick - headed, aren't you?\" he snarls. \"It seems you need to be
taught a lesson or two about OBEYING!\"";
                    set.view(a.wiz, v.wiz);
                    reposition.to(a.wiz, 91, 129);
                    make.wiz.come = osw.punish;
                    set(force.wiz.come);
                }
            }
            else
            {
                reset(have.match);
            }
        }
    }

    if ((said(feed, wizard) ||
        said(feed, food, wizard) ||
        said(feed, wizard, food) ||
        said(put, food, table) ||
        said(put, food, on, table) ||
        said(put, food, table, wizard) ||
        said(put, food, on, table, wizard) ||
        said(give, food, wizard) ||
        said(give, wizard, food)))
    {
        if (!has(i.bread) &&
            !has(i.fruit) &&
            !has(i.mutton) &&
            !has(i.porridge) &&
            !has(i.porridge.poisoned))
        {
            #message 19  "You have no food to give the wizard.";
        }
        else
        {
            wants.to.feed.wiz = 0;

            if (has(i.bread) &&
                !has(i.fruit) &&
                !has(i.mutton) &&
                !has(i.porridge) &&
                !has(i.porridge.poisoned))
            {
                wants.to.feed.wiz = bread;
            }

            if (!has(i.bread) &&
                has(i.fruit) &&
                !has(i.mutton) &&
                !has(i.porridge) &&
                !has(i.porridge.poisoned))
            {
                wants.to.feed.wiz = fruit;
            }

            if (!has(i.bread) &&
                !has(i.fruit) &&
                has(i.mutton) &&
                !has(i.porridge) &&
                !has(i.porridge.poisoned))
            {
                wants.to.feed.wiz = mutton;
            }

            if (!has(i.bread) &&
                !has(i.fruit) &&
                !has(i.mutton) &&
                has(i.porridge) &&
                !has(i.porridge.poisoned))
            {
                wants.to.feed.wiz = porridge;
            }

            if (!has(i.bread) &&
                !has(i.fruit) &&
                !has(i.mutton) &&
                !has(i.porridge) &&
                has(i.porridge.poisoned))
            {
                wants.to.feed.wiz = porridge.poisoned;
            }

            if (!wants.to.feed.wiz)
            {
                #message 15  "You are carrying more than one type of food. Which would you like
to give the wizard ? ";
                wants.to.feed.wiz = something;
                goto no.input;
            }
        }
    }

    if (has(i.bread))
    {
        if ((said(feed, bread, wizard) ||
            said(feed, wizard, bread) ||
            said(put, bread, table) ||
            said(put, bread, table, wizard) ||
            said(give, bread, wizard) ||
            said(give, wizard, bread)))
        {
            wants.to.feed.wiz = bread;
        }

        if (wants.to.feed.wiz == something && said(bread))
        {
            wants.to.feed.wiz = bread;
        }
    }

    if (has(i.fruit))
    {
        if ((said(feed, fruit, wizard) ||
            said(feed, wizard, fruit) ||
            said(put, fruit, table) ||
            said(put, fruit, table, wizard) ||
            said(give, fruit, wizard) ||
            said(give, wizard, fruit)))
        {
            wants.to.feed.wiz = fruit;
        }

        if (wants.to.feed.wiz == something && said(fruit))
        {
            wants.to.feed.wiz = fruit;
        }
    }

    if (has(i.mutton))
    {
        if ((said(feed, mutton, wizard) ||
            said(feed, wizard, mutton) ||
            said(put, mutton, table) ||
            said(put, mutton, table, wizard) ||
            said(give, mutton, wizard) ||
            said(give, wizard, mutton)))
        {
            wants.to.feed.wiz = mutton;
        }

        if (wants.to.feed.wiz == something && said(mutton))
        {
            wants.to.feed.wiz = mutton;
        }
    }

    if ((has(i.porridge) || has(i.porridge.poisoned)))
    {
        if ((said(feed, porridge, wizard) ||
            said(feed, wizard, porridge) ||
            said(put, porridge, table) ||
            said(put, porridge, on, table) ||
            said(put, porridge, table, wizard) ||
            said(put, porridge, on, table, wizard) ||
            said(give, porridge, wizard) ||
            said(feed, poison, porridge, wizard) ||
            said(feed, wizard, poison, porridge) ||
            said(put, poison, porridge, table) ||
            said(put, poison, porridge, on, table) ||
            said(put, poison, porridge, table, wizard) ||
            said(put, poison, porridge, on, table, wizard) ||
            said(give, poison, porridge, wizard) ||
            said(give, wizard, poison, porridge)))
        {
            wants.to.feed.wiz = porridge;
        }

        if (wants.to.feed.wiz == something && said(porridge))
        {
            wants.to.feed.wiz = porridge;
        }
    }

    if (has(i.porridge.poisoned))
    {
        if (wants.to.feed.wiz == porridge)
        {
            wants.to.feed.wiz = porridge.poisoned;
        }

        if ((said(feed, porridge, wizard) ||
            said(feed, wizard, porridge) ||
            said(put, porridge, table) ||
            said(put, porridge, on, table) ||
            said(put, porridge, table, wizard) ||
            said(put, porridge, on, table, wizard) ||
            said(give, porridge, wizard) ||
            said(feed, poison, porridge, wizard) ||
            said(feed, wizard, poison, porridge) ||
            said(put, poison, porridge, table) ||
            said(put, poison, porridge, on, table) ||
            said(put, poison, porridge, table, wizard) ||
            said(put, poison, porridge, on, table, wizard) ||
            said(give, poison, porridge, wizard) ||
            said(give, wizard, poison, porridge) ||
            said(feed, porridge, wizard) ||
            said(feed, wizard, porridge) ||
            said(put, porridge, table) ||
            said(put, porridge, table, wizard) ||
            said(give, porridge, wizard) ||
            said(give, wizard, porridge)))
        {
            wants.to.feed.wiz = porridge.poisoned;
        }

        if (wants.to.feed.wiz == something && said(poisoned, porridge))
        {
            wants.to.feed.wiz = porridge.poisoned;
        }
    }
}

if (wants.to.feed.wiz == something)                         // [  only 1 try--right or wrong!
{
    wants.to.feed.wiz = 0;
}

// [*****
// :n
// [*****

if (wiz.on.screen && !PO'd.wiz.init'd)
{
    if (wants.to.feed.wiz &&
        wants.to.feed.wiz != something)
    {
        if (!posn(ego, 75, 126, 105, 153))
        {
            wants.to.feed.wiz = 0;
            #message 23  "You're too far away.";
        }
        else
        {
            if (wiz.status != waiting.to.eat)
            {
                wants.to.feed.wiz = 0;
                #message 24  "He doesn't seem to be hungry right now.";
                goto no.input;
            }

            if (wants.to.feed.wiz == bread)
            {
                drop(i.bread);
                set.cel(a.food, c.bread);
            }

            if (wants.to.feed.wiz == fruit)
            {
                drop(i.fruit);
                set.cel(a.food, c.fruit);
            }

            if (wants.to.feed.wiz == mutton)
            {
                drop(i.mutton);
                set.cel(a.food, c.mutton);
            }

            if (wants.to.feed.wiz == porridge)
            {
                drop(i.porridge);
                set.cel(a.food, c.porridge);
            }

            if (wants.to.feed.wiz == porridge.poisoned)
            {
                drop(i.porridge.poisoned);
                set.cel(a.food, c.porridge);
                set(make.wiz.a.pussy);
            }

            wants.to.feed.wiz = 0;
            draw(a.food);
            set(handsOff);
            stop.motion(ego);
            wiz.eat.seconds = wiz.eat.time;
            wiz.status = eating;
            wiz.chewing.timer = 2;
            #message 16  "You place the food on the dining table before the
hungry wizard.Ravenously, he devours every bit of it.";
            work = 3;
            cycle.time(a.wiz, work);
            if (chore.to.do == fix.meal)
            {
                chore.to.do = 0;
                chore.minutes = 0;
                chore.seconds = 0;
            }
        }
    }

    --wiz.chewing.timer;
    if (wiz.chewing.timer == 1)
    {
        end.of.loop(a.wiz, wiz.eat.loop.done);
    }

    if (wiz.eat.loop.done)
    {
        reset(wiz.eat.loop.done);
        set.cel(a.wiz, 0);
        stop.cycling(a.wiz);
        wiz.chewing.timer = chewing.pause.time;
    }

    if (aSecondPassed)
    {
        --lcl.wiz.seconds;
        if (lcl.wiz.seconds == 1)
        {
            set(wiz.arrived);
        }

        --wiz.eat.seconds;
        if (wiz.eat.seconds == 1)
        {
            if (make.wiz.a.pussy)
            {
                reset(make.wiz.a.pussy);
                reset(handsOff);
                set(wiz.arrived);
                wiz.location = 50;
                #message 30  "You fooled him! Manannan didn't realize the porridge was tainted,
and ate the whole bowl!";
            }
            else
            {
                #message 18  "It's obvious the wizard enjoyed his meal as he lets out a satisfied
belch.He rises and leaves without so much as a \"Thank you!\"";
                erase(a.food);
                wiz.status = leaving.room;
                stop.cycling(a.wiz);
                wiz.location = 100;
                lcl.wiz.seconds = 5;
            }
        }
    }

    if ((wiz.location == 51 ||
        wiz.location == 101))
    {
        current.cel(a.poof, work);
        if (work == 3)
        {
            set(wiz.arrived);
        }
    }

                                                            // [  HERE'S THIS ROOM'S TWO POSSIBLE WIZARD SCENERIOS:

    if (wiz.arrived)
    {
        reset(wiz.arrived);
        ++wiz.location;
        prevent.input();
        program.control();
        stop.motion(ego);

                                                            // [  HERE'S WHAT WE'VE ALL BEEN WAITING FOR:  TURN THAT WIZ-BANG INTO A PUSSY!

        if (wiz.location == 51)
        {
            load.view(v.cat);
            load.sound(m.title);

            sound(m.title, done);
            erase(a.food);

            animate.obj(a.poof);
            set.view(a.poof, v.poof);
            set.priority(a.poof, 15);
            set.cel(a.poof, 0);
            work = 3;
            cycle.time(a.poof, work);
            ignore.obj(a.poof);
            stop.motion(a.poof);
            position(a.poof, 87, 126);
            draw(a.poof);
            end.of.loop(a.poof, wiz.arrived);
        }

        if (wiz.location == 52)
        {
            erase(a.wiz);
            score += 12;
            wiz.status = dead;
            wiz.away.asleep = in.town;
            reset(wiz.sitting);
            wiz.minutes = 0;
            wiz.seconds = 0;
            unblock();

            animate.obj(a.cat);
            set.view(a.cat, v.cat);
            set(pussy.on.screen);
            position(a.cat, 90, 130);
            draw(a.cat);
            move.obj(a.cat, 115, 130, 1, done);
        }

        if (wiz.location == 53)
        {
            erase(a.poof);
            lcl.wiz.seconds = 3;
        }

        if (wiz.location == 54)
        {
            #message 36  "Congratulations! Manannan will never again enslave you or the people
of Llewdor!!At last, you are free!";
            wander(a.cat);
            observe.objs(a.cat);
            set(wiz.pussy.on.screen);
            set(pussy.on.screen);
            reset(wiz.on.screen);
            reset(handsOff);
            wiz.location = 0;
        }

                                                            // [  THIS ONE poofS HIM FROM THE ROOM AFTER HE'S FINISHED EATING.

        if (wiz.location == 101)
        {
            stop.cycling(a.wiz);
            erase(a.food);

            animate.obj(a.poof);
            set.view(a.poof, v.poof);
            set.priority(a.poof, 15);
            set.cel(a.poof, 0);
            work = 3;
            cycle.time(a.poof, work);
            ignore.obj(a.poof);
            stop.motion(a.poof);
            position(a.poof, 87, 126);
            draw(a.poof);
            end.of.loop(a.poof, wiz.arrived);
            sound(s.ego.poofing, done);
        }

        if (wiz.location == 102)
        {
            erase(a.wiz);
        }

        if (wiz.location == 103)
        {
            erase(a.poof);
            reset(wiz.on.screen);
            reset(wiz.sitting);
            unblock();
            wiz.status = gone;
            reset(handsOff);
            wiz.location = 0;
            wiz.x = 29;
            wiz.y = 140;
        }

        if (wiz.location == 0)
        {
            start.motion(ego);
            accept.input();
            player.control();
        }
    }
}

// [  THIS SCRIPT WALKS EGO FROM WHEREVER HE IS, TO THE TABLE, AND SEATS HIM.
// [IF HE WANTED TO EAT, HE THEN BEGINS EATING.

if (aSecondPassed)
{
    --ego.sit.timer;
    if (ego.sit.timer == 1)
    {
        set(ego.arrived);
    }
}

if (ego.arrived)
{
    reset(ego.arrived);
    ++ego.location;

    get.posn(ego, x, y);                                    // [  defaults
    step = 1;

    if (ego.location == 1)
    {
        set(handsOff);
        program.control();
        current.status = walking;

        if (ego.y > 141 &&                                  // [  between the bench and the table
            ego.y < 144 &&
            ego.x > 50 &&
            ego.x < 115)
        {
            x = 115;
        }
        else
        {
            if (ego.y < 131)                                // [  far side of table
            {
                ego.location = 3;
            }
            else
            {
                if (ego.y < 148)                            // [  ends of table
                {
                    ego.location = 2;
                }
                else                                        // [  near side of table
                {
                    y = 148;
                }
            }

            if (ego.x < 81)
            {
                x = 42;
            }
            else
            {
                x = 115;
            }
        }

        move.obj.v(ego, x, y, step, ego.arrived);
    }

    if (ego.location == 2)
    {
        y = 129;
        move.obj.v(ego, x, y, step, ego.arrived);
    }

    if (ego.location == 3)
    {
        move.obj(ego, 90, 129, 0, ego.arrived);
    }

    if (ego.location == 4)
    {
        current.status = sitting;
        reposition.to(ego, 90, 118);
        set.view(ego, v.ego.eating);
        set.cel(ego, 0);
        reset(keep.cycling);
        start.motion(ego);
        ego.sit.timer = 4;
    }

    if (ego.location == 5)
    {
        #message 6  "You take a well deserved moment's rest. But, you wonder if
you have time to be sitting here ? ";
        ego.location = 0;
    }
}

if (ego.wants.to.eat)
{
    if (wiz.sitting)
    {
        #message 25  "Manannan wouldn't like that.";
        ego.wants.to.eat = 0;
    }
    else
    {

                                                            // [reset ego.wants.to.eat only when he's seated and ready to chew.

        if (!handsOff)
        {
            if ((ego.y < 124 ||                             // [  in doorway,
                ego.y > 152 ||                              // [  in lower corners,
                ego.x < 41 ||                               // [  could be in entry hall door
                ego.x > 152))                               // [  could get trapped by table
            {
                #message 26  "You're too far from the table.";
                ego.wants.to.eat = 0;
            }
            else
            {
                set(ego.arrived);
                ego.location = 0;
            }
        }

        if (current.status == sitting)
        {
            if (ego.wants.to.eat == fruit)
            {
                drop(i.fruit);
                set.cel(a.food, c.fruit);
            }

            if (ego.wants.to.eat == bread)
            {
                drop(i.bread);
                set.cel(a.food, c.bread);
            }

            if (ego.wants.to.eat == mutton)
            {
                drop(i.mutton);
                set.cel(a.food, c.mutton);
            }

            if (ego.wants.to.eat == porridge)
            {
                drop(i.porridge);
                set.cel(a.food, c.porridge);
            }

            if (ego.wants.to.eat == porridge.poisoned)
            {
                set(make.ego.a.pussy);
                drop(i.porridge.poisoned);
                set.cel(a.food, c.porridge);
            }

            ego.wants.to.eat = 0;
            draw(a.food);

            set(handsOff);
            set(keep.cycling);
            stop.motion(ego);
            work = 3;
            cycle.time(ego, work);
            current.status = eating;
            ego.eat.seconds = ego.eat.time;
            ego.chewing.timer = 2;
        }
    }
}

if (aSecondPassed)
{
    --ego.eat.seconds;
    if (ego.eat.seconds == 1)
    {
        erase(a.food);
        if (make.ego.a.pussy)
        {
            reset(make.ego.a.pussy);
            #message 31  "You purr contentedly. You will enjoy your new life as a cat!";
            load.view(v.gag.dead.ego.2);
            set.view(ego, v.gag.dead.ego.2);
            set.loop(ego, 0);                               // [  cat with ego head
            set.priority(ego, 15);
            reposition.to(ego, 91, 123);
            start.cycling(ego);
            work = 2;
            cycle.time(ego, work);
            set(certain.death);
        }
        else
        {
            set.cel(ego, 0);
            stop.cycling(ego);
            start.motion(ego);
            reset(keep.cycling);
            ego.eat.seconds = 0;
            ego.chewing.timer = 0;
            reset(ego.eat.loop.done);
            current.status = sitting;
            set(handsOff);
            #message 7  "Mmmmmm! You needed that.";
        }
    }
}

if (current.status == eating)
{
    --ego.chewing.timer;
    if (ego.chewing.timer == 1)
    {
        set(keep.cycling);
        end.of.loop(ego, ego.eat.loop.done);
    }

    if (ego.eat.loop.done)
    {
        reset(ego.eat.loop.done);
        set.cel(ego, 0);
        reset(keep.cycling);
        ego.chewing.timer = chewing.pause.time;
    }
}

if (current.status == sitting && ego.dir)
{
    set(make.ego.rise);
}

if (make.ego.rise)
{
    reset(make.ego.rise);
    set.view(ego, v.ego);
    reset(keep.cycling);
    reset(no.cycling);
    reposition.to(ego, 90, 130);
    player.control();
    ego.cycle.time = 1;
    cycle.time(ego, ego.cycle.time);
    current.status = normal.ego;
    ego.sit.timer = 0;
    reset(handsOff);
}

// [*****
// :e
// [*****

if (current.status != fly.landing)
{
    if (posn(ego, 101, 110, 115, 120)) { new.room(rm.kitchen); }
    if (posn(ego, 21, 132, 25, 144)) { new.room(rm.entry); }
}

call(lgc.wiz.house);

if (lgc.house.wiz.loaded)
{
    call(lgc.house.wiz);
}

if (wiz.on.screen && wiz.sitting)
{
    wiz.x = 91;                                             // [  fool wiz.logics
    wiz.y = 129;
}

if (!wiz.on.screen && chore.to.do == fix.meal)
{
    chore.seconds = 55;
}
