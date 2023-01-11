// [logics for room 118 -- lgc.medusa

#include "gamedefs.al"
#include "rm118.msg"

// [  Called by rooms 11, 16, 21, 26.

#define  mirror.kill.distance   50

#define  medusa.x        dv0                                // [  This dynamic gets 0-6.
#define  medusa.y        dv1
#define  dist          dv2
#define  death.watch      dv3
#define  medusa.seconds      dv4

#define  medusa.at.ego      df0
#define  ego.stone        df1
#define  medusa.on.screen    df2
#define  medusa.done      df3
#define  medusa.confounded    df4
#define  ego.sneaked.a.peek    df5

% object  a.medusa         3

if (init.log)
{
    if (!medusa.stone)
    {
        load.view(v.medusa);
        load.view(v.medusa.turning.to.stone);
        load.view(v.ego.turning.to.stone);
        load.sound(s.medusa.zapping);
        load.sound(m.badguy);

        animate.obj(a.medusa);
        set.view(a.medusa, v.medusa);
        work = 2;
        step.size(a.medusa, work);

        medusa.x = 5;
        random(70, 160, medusa.y);
        position.f(a.medusa, medusa.x, medusa.y);
        set.loop(a.medusa, facing.right);
        random(3, 6, medusa.seconds);
    }

    if (medusa.stone && medusa.statue.room == current.room)
    {
        view = 241;                                         // [  241 = v.medusa.turning.to.stone
        load.view.v(view);
        loop = 0;
        cell = 8;
        x = medusa.statue.x;
        y = medusa.statue.y;
        priority = 0;
        work = 0;
        add.to.picture.v(view, loop, cell, x, y, priority, work);
    }

    return();
}

if (!medusa.stone && medusa.on.screen)
{
    if (have.input)
    {
        if (has(i.mirror) &&
            (said(use, mirror) ||
                said(hold, mirror) ||
                said(point, mirror) ||
                said(show, medusa, mirror) ||
                said(point, medusa, mirror) ||
                said(show, mirror, medusa) ||
                said(aim, mirror, medusa) ||
                said(use, hand, mirror) ||
                said(hold, hand, mirror) ||
                said(point, hand, mirror) ||
                said(show, medusa, hand, mirror) ||
                said(point, medusa, hand, mirror) ||
                said(show, hand, mirror, medusa) ||
                said(aim, hand, mirror, medusa)))
        {
            distance(ego, a.medusa, work);
            if (work > mirror.kill.distance)
            {
                #message 2  "You are too far away for her to see it.";
            }
            else
            {
                set(medusa.stone);
                score += 5;
                normal.motion(a.medusa);
                stop.motion(a.medusa);
                get.posn(a.medusa, medusa.statue.x, medusa.statue.y);
                medusa.statue.room = current.room;

                set.view(a.medusa, v.medusa.turning.to.stone);
                set.cel(a.medusa, 0);
                work = 4;
                cycle.time(a.medusa, work);
                end.of.loop(a.medusa, medusa.done);
                sound(s.medusa.zapping, done);
            }
        }

        if (said(kill, medusa))
        {
            #message 5  "Good idea! But, how can you do that?";
        }

        if (said(talk, medusa))
        {
            #message 8  "Apparently, Medusa doesn't speak. The only sounds that emit from her
mouth are terrible grunts and groans.";
        }

        if (said(look, medusa))
        {
            set(medusa.at.ego);
            set(ego.sneaked.a.peek);
        }
    }
}

if (!medusa.on.screen && !medusa.stone)
{
    if (aSecondPassed)
    {
        --medusa.seconds;
        if (medusa.seconds == 1)
        {
            #message 15  "The most hideous-looking being has made its appearance! It's Medusa!";
            draw(a.medusa);
            set(medusa.on.screen);
            sound(m.badguy, done);
            follow.ego(a.medusa, 6, medusa.at.ego);
        }
    }
}

if (medusa.on.screen && !medusa.stone)
{
    distance(ego, a.medusa, dist);
    if (current.status == normal.ego &&
        !medusa.stone)
    {
        get.posn(a.medusa, medusa.x, medusa.y);
        x = medusa.x;
        y = medusa.y;
        x -= ego.x;
        y -= ego.y;

        if (x > 128)
        {
            work = 0;
            work -= x;
            x = work;
        }

        if (y > 128)
        {
            work = 0;
            work -= y;
            y = work;
        }

        current.loop(ego, loop);

        if (loop == facing.front && medusa.y > ego.y && y > x)
        {
            set(medusa.at.ego);
        }

        if (loop == facing.right && medusa.x > ego.x && y < x)
        {
            set(medusa.at.ego);
        }

        if (loop == facing.left && medusa.x < ego.x && y < x)
        {
            set(medusa.at.ego);
        }

        if (loop == facing.back && medusa.y < ego.y && y > x)
        {
            set(medusa.at.ego);
        }
    }
}

if (medusa.stone && medusa.statue.room == current.room)
{
    if (said(kill, medusa))
    {
        #message 4  "Medusa is now just a stone statue, perfectly harmless.";
    }

    if (said(get, medusa))
    {
        #message 9  "The statue is much too heavy to carry.";
    }

    if (said(look, medusa))
    {
        #message 11  "Even as a statue, Medusa is indescribably ugly.";
    }
}

// [*****
// :n
// [*****

if (medusa.at.ego && !medusa.stone)
{
    reset(medusa.at.ego);

    if (current.status != normal.ego)
    {
        set(medusa.confounded);
        wander(a.medusa);
    }
    else
    {
        set(handsOff);
        program.control();
        prevent.input();
        stop.motion(ego);
        wander(a.medusa);

        set(keep.cycling);
        set.view(ego, v.ego.turning.to.stone);
        work = 4;
        cycle.time(ego, work);
        end.of.loop(ego, ego.stone);

        current.status = entranced;
        sound(s.medusa.zapping, done);

        if ((dist > 15 || ego.sneaked.a.peek))
        {
            #message 16  "Your eyes fall upon a face so hideous, so gruesome, that the horror of it is
beyond description.People who look
upon the face of Medusa, with her hair of writhing, live snakes,
turn instantly to stone.Suddenly, your body feels coldand
stiffens hard as a rock.You make a nice statue, Gwydion.";                                      // [  You looked at the bitch!
        }
        else
        {
            #message 17  "Oh no! Medusa's touch is like ice! A cold chill shivers down your
spine, turning to a stiffness that soon hardens your body like a
rock.You are now nothing but a statue.";                                      // [  She touched me!
        }
    }
}

if (edge.obj.hit &&
    obj.hit.edge == a.medusa &&
    (current.status == entranced ||
        medusa.confounded))
{
    erase(a.medusa);
    reset(medusa.on.screen);
}

if (ego.stone)
{
    reset(ego.stone);
    reset(keep.cycling);
    set(certain.death);
    stop.cycling(ego);

    erase(a.medusa);
    reset(medusa.on.screen);
}

if (medusa.done)
{
    reset(medusa.done);
    stop.cycling(a.medusa);
    #message 10  "Averting your eyes, you aim the wizard's hand mirror at Medusa's face. A
scream pierces the air as she beholds her own hideous reflection...
then... nothing.You dare to look.Medusa has turned herself to stone!";
}

if ((current.status == stunned ||
    current.status == entranced))
{
    edge.ego.hit = 0;
}

// [*****
// :e
// [*****

