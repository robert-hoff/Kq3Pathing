// [logics for room 1 -- rm.tower

#include  "rm1.msg"
#include  "gamedefs.al"
#include  "rm-names.h"

// [  A dead fly is on the floor. a telescope is in the center.  stairs go down
// [to room 3. Sometimes wiz is looking through the scope when ego enters.
// [If Wiz is looking through scope, he makes random comments (at random
// [intervals) about what he sees.  If "look scope", walk ego to scope, print a
// [message, then release him.

// [  Sometimes wiz pops in after a few seconds.  If so, he does NOT go to
// [telescope and the other messages do not apply.  Instead, he stands in doorway
// [and says: 11.  He gives you 25 seconds to leave, then he says: 12.  He
// [points, and calls rm104 for a punishment.

#define  time.before.ego.dead  25

#define  wiz.at.scope      lf0
#define  ego.poof.done      lf1
#define  house.wiz.init'd    lf2

#define  bugged.wiz.count    lv0
#define  ego.exit.timer      lv1
#define  wizard.timer      lv2
#define  ego.timer        lv3

% object  a.fly        1

if (init.log)
{
    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    load.view(v.ego);
    map.area = map.wiz.house;
    landing.x = 94;
    landing.y = 131;
    wiz.x = 99;
    wiz.y = 136;

    cat.x = 62;
    cat.y = 121;
    load.logics(lgc.wiz.house);

    if ((wiz.away.asleep == home.after.bed ||               // [  If we're home, and he's
        wiz.away.asleep == home.after.town) &&
        !chore.to.do&&
        wiz.status != dead)
    {
        random(1, 2, work);
        if (work == 1)                                      // [  home, he may drop in.
        {
            load.logics(lgc.house.wiz);
            set(lgc.house.wiz.loaded);
            load.view(v.wiz.at.scope);                      // [  load any local views necessary
            random(1, 2, work);
            if (work == 1)
            {
                set(wiz.at.scope);
                set(house.wiz.init'd);
                wizard.timer = 2;
                wiz.entrance.time = 0;                      // [  he's coming now
            }
            else
            {
                wiz.x = 28;
                wiz.y = 167;
                random(6, 12, wiz.entrance.time);           // [  he's coming later
            }
        }
    }

    if (obj.in.room(i.fly.wings, current.room))
    {
        load.view(v.fly);
    }

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    if (obj.in.room(i.fly.wings, current.room))
    {
        animate.obj(a.fly);
        ignore.objs(a.fly);
        ignore.block(a.fly);
        set.view(a.fly, v.fly);
        position(a.fly, 103, 135);
        draw(a.fly);
    }

    if (current.status == fly)
    {
        set(positionEgo);
    }

    if (positionEgo)
    {
        if (previous.room == 3)
        {
            position(ego, 38, 158);
        }
        else
        {
            position.v(ego, landing.x, landing.y);
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
        if (!wiz.at.scope)
        {
            set.view(a.wiz, v.wiz);
            set.loop(a.wiz, facing.right);
        }
        else
        {
            wiz.status = here;
            set.view(a.wiz, v.wiz.at.scope);
            wiz.x = 85;                                     // [  adjust wiz.x/y for scope
            wiz.y = 135;
            set.cel(a.wiz, 0);
            stop.cycling(a.wiz);
            position.v(a.wiz, wiz.x, wiz.y);
            work = wiz.cycle.time;
            cycle.time(a.wiz, work);
            draw(a.wiz);
            set(wiz.on.screen);
        }
    }

    show.pic();

    if (wiz.on.screen && wiz.at.scope && !PO'd.wiz.init'd)
    {
        sound(m.wiz, done);
        print.at(16, 2, 2, 37);
    }

    return();

}

// [*****
// :handle.input
// [*****

if (!have.input) { goto no.input; }

if ((said(look, room) ||
    said(look) ||
    said(look, house) ||
    said(look, tower) ||
    said(look, chamber)))
{
    #message 1  "You have entered the musty tower of the old wizard's
house.A polished brass telescope is directed out a window.From
here, Manannan spies upon the poor occupants of Llewdor.";
}

if (said(look, ground))
{
    if (obj.in.room(i.fly.wings, current.room))
    {
        #message 2  "You see nothing on the dusty floor but a dead fly.";
    }
    else
    {
        #message 6  "You hope Manannan doesn't notice the floor needs sweeping.";
    }
}

if (said(look, telescope))
{
    if (wiz.at.scope)
    {
        #message 10  "The wizard wouldn't like that.";
    }
    else
    {
        #message 3  "Manannan has the brass telescope pointed out a window.
It is well polished.He uses the
telescope to keep tabs on the citizenry of Llewdor.";
    }
}

if (!handsOff &&
    (said(look$in, telescope) ||
        said(use, telescope)))
{
    if (wiz.on.screen)
    {
        #message 10  "The wizard wouldn't like that.";
    }
    else
    {
        set(ego.arrived);
        ego.location = 0;
    }
}

if (said(look, stairs))
{
    #message 5  "There are narrow, steep stairs leading downwards.";
}

if (said(get, fly))
{
    if (!obj.in.room(i.fly.wings, current.room))
    {
        #message 8  "You already took it.";
    }
    else
    {
        if (!posn(ego, 95, 134, 112, 139))
        {
            #message 27  "You are not close enough.";
        }
        else
        {
            erase(a.fly);
            get(i.fly.wings);
            score += 1;
            #message 7  "You pick up the dead fly and drop it into
your hand.Disgustedly, you look at it. \"I
don't want to carry around a dead fly,\" you think. Picking off
its wings, you throw the rest away.";
        }
    }
}

if ((said(move, telescope) ||
    said(move, telescope, window)))
{
    if (wiz.at.scope)
    {
        #message 10  "The wizard wouldn't like that.";
    }
    else
    {
        #message 15  "You push and pull on the heavy brass telescope, but in vain.
It's just too heavy for you.";
    }
}

if (said(get, telescope))
{
    #message 13  "The big brass telescope is much too heavy for you to carry.";
}

if (wiz.at.scope)
{
    if (said(look, wizard))
    {
        #message 9  "The old white-bearded wizard is peering through his
telescope.He hasn't noticed you.";
    }

    if (said(talk, wizard))
    {
        ++wiz.temper;
    }
}

// [*****
// :no.input
// [*****

// [  MOVE EGO SO HE CAN LOOK THROUGH THE TELESCOPE.

--ego.timer;
if (ego.timer == 1)
{
    set(ego.arrived);
}

if (ego.arrived)
{
    reset(ego.arrived);
    ++ego.location;
    program.control();
    set(handsOff);
    step = 1;

    if (ego.location == 1)
    {
        // [  above the scope
        if (posn(ego, 42, 120, 110, 131))
        {
            y = 131;
            move.obj.v(ego, ego.x, y, step, ego.arrived);
            ego.location = 4;
        }
        else
        {
            // [  even/below the scope
            if (posn(ego, 42, 132, 115, 167))
            {
                y = 139;
                move.obj.v(ego, ego.x, y, step, ego.arrived);
            }
            else
            {
                player.control();
                start.motion(ego);
                reset(handsOff);
                #message 27  "You are not close enough.";
                ego.location = 0;
            }
        }
    }

    if (ego.location == 2)
    {
        move.obj(ego, 87, 139, 0, ego.arrived);
    }

    if (ego.location == 3)
    {
        move.obj(ego, 87, 131, 0, ego.arrived);
        ego.location = 4;
    }

    if (ego.location == 5)
    {
        move.obj(ego, 87, 129, 0, ego.arrived);
    }

    if (ego.location == 6)
    {
        move.obj(ego, 85, 129, 0, ego.arrived);
    }

    if (ego.location == 7)
    {
        stop.motion(ego);
        ego.timer = 22;
    }

    if (ego.location == 8)
    {
        ego.location = 0;
        reset(handsOff);
        player.control();
        start.motion(ego);
        #message 4  "You put your eye to the glass. It amazes you how near everything seems."
                    "You can even see squirrels climbing"
                    "faraway trees.No wonder the wizard knows all activities in"
                    "Llewdor.";
    }
}


// [  HANDLE THE LOCAL WIZARD STUFF.

if (aSecondPassed)
{
    if (wiz.on.screen && wiz.at.scope && !PO'd.wiz.init'd)
    {
        // [  this makes wizzie talk/gesture
        --wizard.timer;
        if (wizard.timer == 5)
        {
            start.cycling(a.wiz);
        }

        if (wizard.timer == 1)
        {
            stop.cycling(a.wiz);
            set.cel(a.wiz, 0);
            random(17, 22, message);
            print.v(message);
            random(10, 30, wizard.timer);
        }
    }
}


if (wiz.on.screen && !PO'd.wiz.init'd)
{
    if (!house.wiz.init'd && !wiz.at.scope)
    {
        set(house.wiz.init'd);
            wiz.location = 0;
        set(wiz.arrived);
    }

    if (wiz.arrived)
    {
        reset(wiz.arrived);
        ++wiz.location;

        if (wiz.location == 1)
        {
            move.obj(a.wiz, 63, 130, 1, wiz.arrived);
        }

        if (wiz.location == 2)
        {
            move.obj(a.wiz, 88, 130, 1, wiz.arrived);
        }

        if (wiz.location == 3)
        {
            move.obj(a.wiz, 88, 133, 1, wiz.arrived);
        }

        if (wiz.location == 4)
        {
            move.obj(a.wiz, 85, 133, 1, wiz.arrived);
        }

        if (wiz.location == 5)
        {
            wiz.location = 0;
            set(wiz.at.scope);

            set.view(a.wiz, v.wiz.at.scope);
            set.cel(a.wiz, 0);
            stop.cycling(a.wiz);
            random(10, 30, wizard.timer);
        }
    }
}

// [*****
// :exit              // [  test for leaving the room
// [*****

if (edge.ego.hit == bottom && current.status != fly.landing &&
    ego.x > 25 && ego.x < 47) {
    new.room(rm.hallway);
}

call(lgc.wiz.house);
if (lgc.house.wiz.loaded)
{
    call(lgc.house.wiz);
}







