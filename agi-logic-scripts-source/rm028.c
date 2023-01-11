// [logics for room 28 -- outside bear's house

#include "rm28.msg"
#include "gamedefs.al"

// [  The entire Mama-bear-garden is priority 3 (perhaps she over-watered?).

// [  You can encounter bears leaving their house to walk in the woods, or
// [returning from a walk in the woods to then enter their house, or can
// [encounter Mama working in the garden on her knees.  If you get
// [too close to her, she'll rise, and kick you out of the room, to rm13.

// [  If you "knock door" and bears are at home, Papa will answer the door,
// [slam it in your face, stunning you.

#define  mama            1                                  // [  bear.on.screen values
#define  papa            2
#define  baby            3
#define  all            4

#define  none            0                                  // [  script and status use same values
#define  going.for.walk       50
#define  out.of.bedroom      70
#define  returning.from.walk    100
#define  papa.ready.to.open.door  106
#define  mama.in.garden      150
#define  mama.chasing      151
#define  in.house        200
#define  papa.pushing      201
#define  out.walking      250

#define    in.flower            1                           // [  ego.location values
#define  on.roof          2
#define  near.door          3
#define  near.garden        4
#define  near.window        5

#define  warning.time       10                              // [  in seconds

#define  open.door        lf0
#define  door.open        lf1
#define  door.open.done      lf2
#define  close.door      lf3
#define  door.close.done    lf4
#define  sound.done      lf5
#define  enter.house      lf6
#define  script.done      lf7
#define  music.done      lf8

#define  script        lv0
#define  bear.status      lv1
#define  script.timer      lv2
#define  warning.seconds    lv3
#define  stunned.seconds    lv4
#define  bear.on.screen      lv5
#define  mama.talk.count    lv6

% object  a.bear.papa      1
% object  a.bear.mama      2
% object  a.bear.baby      3
% object  a.door.rm28      4
% object  a.smoke        5

if (init.log)
{
    if ((storm.minutes || storm.seconds) && previous.room == 41)
    {
        pre.previous.room = previous.room;
        new.room(87);
    }

    load.view.f(current.ego);
    set.view.f(ego, current.ego);
    load.view(v.ego);
    map.area = map.llewdor;
    set(beenIn28);
    set.horizon(55);
    wiz.y = 0;

    random(1, 2, work);
    if (work == 1)
    {
        landing.x = 10;
        landing.y = 73;
    }
    else
    {
        landing.x = 135;
        landing.y = 83;
    }

    load.logics(lgc.forest);

    load.view(v.door.rm28);
    load.view(v.smoke);

    random(1, 9, work);
    if (work == 1)
    {
        bear.status = going.for.walk;
    }
    else
    {
        if (work == 2)
        {
            bear.status = returning.from.walk;
        }
        else
        {
            if (work < 5)
            {
                bear.status = mama.in.garden;
            }
            else
            {
                if (work < 7)
                {
                    bear.status = in.house;
                }
                else
                {
                    bear.status = out.walking;
                }
            }
        }
    }

    if ((handsOff ||
        previous.room == 41 ||
        current.status == deferred.entry))
    {
        bear.status = out.walking;
    }

    if (previous.room == 42)
    {
        bear.status = out.of.bedroom;
    }

    if (debugging && bear.tester)                           // [  var 98
    {
        bear.status = bear.tester;
        bear.tester = 0;
    }

    if (bear.status == going.for.walk)
    {
        load.view(v.bear.papa);
        load.view(v.bear.mama);
        load.view(v.bear.baby);
        load.sound(m.bears);

        animate.obj(a.bear.papa);
        animate.obj(a.bear.mama);
        animate.obj(a.bear.baby);

        ignore.obj(a.bear.papa);
        ignore.obj(a.bear.mama);
        ignore.obj(a.bear.baby);
    }

    if (bear.status == returning.from.walk)
    {
        load.view(v.bear.papa);
        load.view(v.bear.mama);
        load.view(v.bear.baby);
        load.view(v.ego.falling);
        load.view(v.ego.stunned);
        load.sound(s.ego.falling);
        load.sound(s.ego.stunned);
        load.sound(m.bears);
        load.sound(s.growl);

        animate.obj(a.bear.papa);
        animate.obj(a.bear.mama);
        animate.obj(a.bear.baby);

        ignore.obj(a.bear.papa);
        ignore.obj(a.bear.mama);
        ignore.obj(a.bear.baby);
    }

    if (bear.status == mama.in.garden)
    {
        load.view(v.bear.papa);
        load.view(v.bear.mama);
        load.view(v.bear.mama.in.garden);
        load.view(v.bear.mama.kicking.ego);
        load.view(v.ego.falling);
        load.view(v.ego.stunned);
        load.sound(s.ego.falling);
        load.sound(s.ego.stunned);
        load.sound(s.growl);

        animate.obj(a.bear.papa);
        animate.obj(a.bear.mama);

        ignore.obj(a.bear.papa);
        ignore.obj(a.bear.mama);
    }

    if ((bear.status == in.house ||
        bear.status == out.of.bedroom))
    {
        load.view(v.bear.papa);
        load.view(v.ego.falling);
        load.view(v.ego.stunned);
        load.sound(s.ego.falling);
        load.sound(s.ego.stunned);
        load.sound(s.growl);

        animate.obj(a.bear.papa);
        ignore.obj(a.bear.papa);
    }

    if (bear.status == out.walking)
    {
    }

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    animate.obj(a.door.rm28);
    set.view(a.door.rm28, v.door.rm28);
    set.cel(a.door.rm28, 0);
    work = 3;
    cycle.time(a.door.rm28, work);
    ignore.block(a.door.rm28);
    ignore.obj(a.door.rm28);
    set.priority(a.door.rm28, 9);
    position(a.door.rm28, 77, 109);
    draw(a.door.rm28);
    stop.update(a.door.rm28);

    animate.obj(a.smoke);
    set.view(a.smoke, v.smoke);
    set.loop(a.smoke, 0);
    set.cel(a.smoke, 0);
    work = 4;
    cycle.time(a.smoke, work);
    ignore.horizon(a.smoke);
    ignore.blocks(a.smoke);
    position(a.smoke, 108, 10);
    draw(a.smoke);

    if (current.status == fly)
    {
        set(positionEgo);
    }

    if (positionEgo)
    {
        if ((previous.room == 41 || previous.room == 42))
        {
            ego.x = 73;
            ego.y = 118;
        }

        if (previous.room == 27)
        {
            if (ego.y > 92 && ego.y < 97)
            {
                ego.y = 92;
            }
        }

        if (previous.room == 29)
        {
            if (ego.y > 70 && ego.y < 74)
            {
                ego.y = 70;
            }

            if (ego.y > 142 && ego.y < 147)
            {
                ego.y = 142;
            }

        }

        position.v(ego, ego.x, ego.y);
    }

    if (drawEgo)
    {
        draw(ego);
    }

    if (bear.status == out.of.bedroom)
    {
        program.control();
        prevent.input();
        script = out.of.bedroom;
        set(script.done);
    }

    if (bear.status == mama.in.garden)
    {
        bear.on.screen = mama;
        set.view(a.bear.mama, v.bear.mama.in.garden);
        position(a.bear.mama, 40, 130);
        work = 6;
        cycle.time(a.bear.mama, work);
        object.on.water(a.bear.mama);
        draw(a.bear.mama);
    }

    if ((bear.status == going.for.walk ||
        bear.status == returning.from.walk))
    {
        bear.on.screen = all;
        program.control();
        stop.motion(ego);

        set.view(a.bear.papa, v.bear.papa);
        set.view(a.bear.mama, v.bear.mama);
        set.view(a.bear.baby, v.bear.baby);

        if (bear.status == going.for.walk)
        {
            script = going.for.walk;
            set(script.done);
            set(open.door);
        }

        if (bear.status == returning.from.walk)
        {
            script = returning.from.walk;
            position(a.bear.papa, 148, 166);
            draw(a.bear.papa);
            set.loop(a.bear.papa, facing.left);
            move.obj(a.bear.papa, 137, 155, 1, script.done);
        }
    }

    call(lgc.forest);

    show.pic();

    if ((bear.status == going.for.walk ||
        bear.status == returning.from.walk))
    {
        sound(m.bears, music.done);
    }

    return();

}

// [  This block is sequence dependent:
ego.location = nowhere;
if (posn(ego, 0, 94, 95, 167)) { ego.location = near.garden; }
if (on.water) { ego.location = in.flower; }
if (posn(ego, 70, 108, 84, 118)) { ego.location = near.door; }
if ((posn(ego, 84, 115, 96, 125) ||
    posn(ego, 97, 98, 111, 121))) {
    ego.location = near.window;
}

// [*****
// [handle.input
// [*****

if (have.input)
{
    if (said(look, bear))
    {
        if (!bear.on.screen)
        {
            #message 40  "Where?";
        }

        if (bear.on.screen == mama)
        {
            #message 2  "%m1 To your surprise, you see a bear, wearing a dress, working in the
garden.It must be Mama Bear!";
        }

        if (bear.on.screen == papa)
        {
            #message 24  "He doesn't seem happy to see you.";
        }

        if (bear.on.screen == all)
        {
            #message 8  "You see three fully-clothed bears!";
        }
    }

    if (said(talk, bear))
    {
        if (!bear.on.screen)
        {
            #message 40  "Where?";
        }
        else
        {
            if (bear.on.screen == all)
            {
                #message 22  "Evidently, they don't hear you.";
            }
            else
            {
                if (bear.on.screen == mama)
                {
                    ++mama.talk.count;
                    if (mama.talk.count == 1)
                    {
                        sound(s.growl, done);
                        #message 28  "Your cordial greeting annoys the bear, and she growls back,
\"Grrrrrrrrrrrrreetings yourrrrrrrrrrself, young man. Stay out of my
garden!\"";
                    }
                    else
                    {
                        if (mama.talk.count == 2)
                        {
                            sound(s.growl, done);
                            #message 29  "Again, you speak to the bear. \"Grrrrrrrrrrr!\" she growls menacingly.
\"We don't take to strangers here. Go away!\"";
                        }
                        else
                        {
                            sound(s.growl, done);
                            #message 30  "Insistently, you talk to the bear yet again. She ignores you, but
you hear a constant low growl from deep within her.";
                        }
                    }
                }
            }
        }

        if (bear.on.screen && said(get, bear))
        {
            #message 31  "It is utterly impossible for you to catch a big bear.";
        }

        if (bear.on.screen && said(kill, bear))
        {
            #message 32  "How could you hurt a big bear? You couldn't.";
        }

        if (bear.on.screen && said(kiss, bear))
        {
            #message 33  "A strange idea.";
        }
    }

    if ((said(look, flower) ||
        said(look$in, flower) ||
        said(look, dew, flower)))
    {
        if (ego.location == in.flower)
        {
            #message 3  "You carefully peek into the pretty flowers of the flower garden. Drops
of glistening dew have gathered within their soft petals.";
        }
        else
        {
            if (bear.status == mama.in.garden)
            {
                #message 2  "%m1 To your surprise, you see a bear, wearing a dress, working in the
garden.It must be Mama Bear!";
            }
            else
            {
                #message 1  "There are lovely flowers growing in this well-tended
garden.Their sweet scent and beautiful colors delight you.";
            }
        }
    }

    if ((said(look, garden) ||
        said(look, flower, garden) ||
        said(look, flower) ||
        said(look, flower, flower, garden)))
    {
        if (bear.status == mama.in.garden)
        {
            #message 2  "%m1 To your surprise, you see a bear, wearing a dress, working in the
garden.It must be Mama Bear!";
        }
        else
        {
            #message 1  "There are lovely flowers growing in this well-tended
garden.Their sweet scent and beautiful colors delight you.";
        }
    }

    if ((said(look, house) ||
        said(look)))
    {
        #message 4  "This is the comfortable home of the Three Bears. A well-tended flower
garden grows out front.";
    }

    if ((said(look, room) ||
        said(look$in, window) ||
        said(look, window)))
    {
        if (ego.location == near.window)
        {
            #message 5  "You peer through the window, but the inside is dimly lit and you
cannot make out any details.";
        }
        else
        {
            #message 6  "You need to move closer.";
        }
    }

    if ((said(look, door) ||
        said(look, door, house)))
    {
        #message 7  "The heavy wooden door is closed.";
    }

    if ((said(pick, flower) ||
        said(pick, flower, flower, garden)))
    {
        if (ego.location == in.flower)
        {
            #message 9  "You wouldn't want to spoil the lovely flower bed by picking one!";
        }
        else
        {
            #message 6  "You need to move closer.";
        }
    }

    if (ego.location == in.flower &&
        (said(look, dew) ||
            said(look, dew, flower)))
    {
        #message 27  "The dew is beautiful.";
    }

    if ((said(get, dew) ||
        said(get, dew, flower) ||
        said(get, dew, flower, garden) ||
        said(get, dew, thimble) ||
        said(get, dew, flower, thimble) ||
        said(get, thimble, dew) ||
        said(get, thimble, dew, flower) ||
        said(get, dew, flower, garden) ||
        said(get, dew, from, flower) ||
        said(get, dew, from, flower, garden) ||
        said(get, dew, flower, thimble) ||
        said(get, dew, from, flower, garden, thimble) ||
        said(get, thimble, dew) ||
        said(get, thimble, dew, from, flower) ||
        said(get, thimble, dew, from, flower, garden)))
    {
        if (ego.location != in.flower)
        {
            #message 6  "You need to move closer.";
        }
        else
        {
            if (has(i.dew))
            {
                #message 15  "Your thimble is already full of dew.";
            }
            else
            {
                if (!has(i.thimble))
                {
                    #message 14  "You must have a thimble in order to get a thimbleful of dew.";
                }
                else
                {
                    drop(i.thimble);
                    get(i.dew);
                    #message 13  "Holding the silver thimble beneath a dew-filled flower, you gently tip
the flower so its dew runs into the thimble.You move from flower to flower,
repeating the process until your thimble is brimming with dew.";
                    if (!got.dew)
                    {
                        set(got.dew);
                        score += 1;
                    }
                }
            }
        }
    }

    if (!handsOff &&
        (said(knock) ||
            said(knock, on, door) ||
            said(knock, door) ||
            said(knock, door, cottage) ||
            said(knock, on, cottage, door)))
    {
        if (ego.location != near.door)
        {
            #message 6  "You need to move closer.";
        }
        else
        {
            if (bear.status == out.walking)
            {
                #message 34  "You rap lightly on the door of the charming house.";
                #message 35  "No reply.";
                #message 36  "You knock again, louder.";
                #message 37  "Again, there is no response.";
                #message 38  "Perhaps no one is home?";
            }
            else
            {
                script = papa.pushing;
                stop.motion(ego);
                program.control();
                prevent.input();
                start.update(a.door.rm28);
                end.of.loop(a.door.rm28, script.done);
            }
        }
    }

    if (!handsOff &&
        (said(open, door) ||
            said(turn, knob) ||
            said(turn, door, knob) ||
            said(turn, knob, door) ||
            said(turn, door, handle) ||
            said(turn, handle, door)))
    {
        if (ego.location != near.door)
        {
            #message 6  "You need to move closer.";
        }
        else
        {
            if ((bear.status == out.walking ||
                bear.status == going.for.walk))
            {
                set(open.door);
                set(enter.house);
            }
            else
            {
                script = papa.pushing;
                set(script.done);
            }
        }
    }

    if (said(look, mountain))
    {
        #message 26  "You see a lone mountain peak in the distance. Dark clouds swirl around
its summit.";
    }

}

// [****
// :n
// [***

if (bear.status == mama.in.garden &&
    ego.location == in.flower &&                            // [  he's close enough; get him, mama!
    !script)
{
    script = mama.in.garden;
    set(script.done);
}

if (ego.location != in.flower &&
    script == mama.chasing)
{
    accept.input();
    script = none;
    set.view(a.bear.mama, v.bear.mama.in.garden);
    normal.motion(a.bear.mama);
    stop.motion(a.bear.mama);
}

if (aSecondPassed)
{
    --script.timer;
    if (script.timer == 1)
    {
        set(script.done);
    }

    --warning.seconds;
    if (ego.location == near.garden &&
        !script &&
        bear.status == mama.in.garden &&
        !warning.seconds)
    {
        warning.seconds = warning.time;
        #message 10  "Mama Bear growls at you as you near the flower bed. Better stay away from
it... and HER!";
    }
}

if (open.door)
{
    reset(open.door);
    start.update(a.door.rm28);
    end.of.loop(a.door.rm28, door.open.done);
}

if (door.open.done)
{
    reset(door.open.done);
    set(door.open);
    stop.update(a.door.rm28);

    if ((script == papa.ready.to.open.door ||
        script == going.for.walk))
    {
        set(script.done);
    }
}

if (close.door)
{
    reset(close.door);
    reset(door.open);
    start.update(a.door.rm28);
    beginning.of.loop(a.door.rm28, door.close.done);
}

if (door.close.done)
{
    reset(door.close.done);
    stop.update(a.door.rm28);
}

// [****
// [Bear stuff
// [***

if (script.done)
{
    reset(script.done);
    ++script;
    program.control();
    prevent.input();
    set(handsOff);

    if (script == 51)                                       // [  they're going.for.walk
    {
        stop.motion(ego);
        position(a.bear.papa, 75, 124);
        set.loop(a.bear.papa, facing.right);
        draw(a.bear.papa);
        bear.on.screen = all;
        move.obj(a.bear.papa, 84, 124, 1, script.done);
    }

    if (script == 52)
    {
        position(a.bear.mama, 75, 124);
        set.loop(a.bear.mama, facing.right);
        draw(a.bear.mama);
        move.obj(a.bear.mama, 106, 124, 1, script.done);
        move.obj(a.bear.papa, 95, 124, 1, script.done);
    }

    if (script == 53)
    {
        position(a.bear.baby, 75, 124);
        set.loop(a.bear.baby, facing.right);
        draw(a.bear.baby);
        move.obj(a.bear.baby, 106, 124, 1, script.done);
        move.obj(a.bear.papa, 106, 124, 1, script.done);

        print.at(20, 2, 2, 37);
        set(close.door);
    }

    if (script == 54)
    {
        move.obj(a.bear.papa, 148, 166, 1, script.done);
    }

    if (script == 55)
    {
        move.obj(a.bear.mama, 148, 166, 1, script.done);
    }

    if (script == 56)
    {
        move.obj(a.bear.baby, 149, 167, 1, script.done);
    }

    if (script == 57)
    {
        erase(a.bear.papa);
    }

    if (script == 58)
    {
        erase(a.bear.mama);
    }

    if (script == 59)
    {
        erase(a.bear.baby);
        bear.on.screen = none;
        bear.status = out.walking;
        stop.sound();
        reset(music.done);
        script = 0;
    }

    if (script == 71)
    {
        set(door.open);
        bear.on.screen = papa;
        set.view(a.bear.papa, v.bear.papa);
        set.loop(a.bear.papa, facing.front);
        set.cel(a.bear.papa, 0);
        set.priority(a.bear.papa, 10);
        ignore.obj(a.bear.papa);
        ignore.block(a.bear.papa);
        position(a.bear.papa, 74, 110);
        draw(a.bear.papa);
        #message 12  "\"AND STAY OUT!!!\"";

        script = 205;                                       // [  also catch rest of code below
    }

    if (script == 101)                                      // [  they're returning from a walk
    {
        stop.motion(ego);
        bear.on.screen = all;
        move.obj(a.bear.papa, 128, 146, 1, script.done);

        position(a.bear.mama, 148, 166);
        set.loop(a.bear.mama, facing.left);
        draw(a.bear.mama);
        move.obj(a.bear.mama, 106, 124, 1, script.done);
    }

    if (script == 102)
    {
        move.obj(a.bear.papa, 106, 124, 1, script.done);

        position(a.bear.baby, 149, 167);
        set.loop(a.bear.baby, facing.left);
        draw(a.bear.baby);
        move.obj(a.bear.baby, 106, 124, 1, script.done);
        print.at(21, 2, 2, 37);
    }

    if (script == 103)
    {
        move.obj(a.bear.papa, 75, 124, 1, script.done);
    }

    if (script == 104)
    {
        move.obj(a.bear.mama, 75, 125, 1, done);
    }

    if (script == 105)
    {
        move.obj(a.bear.baby, 75, 126, 1, done);
    }

    if (script == papa.ready.to.open.door)                  // [  106
    {
        set(open.door);
    }

    if (script == 107)
    {
        move.obj(a.bear.papa, 75, 120, 1, script.done);
    }

    if (script == 108)
    {
        erase(a.bear.papa);
        move.obj(a.bear.mama, 75, 120, 1, script.done);
    }

    if (script == 109)
    {
        erase(a.bear.mama);
        move.obj(a.bear.baby, 75, 120, 1, script.done);
    }

    if (script == 110)
    {
        erase(a.bear.baby);
        set(close.door);
        bear.status = in.house;
        bear.on.screen = none;
        stop.sound();
        reset(music.done);
        script = 0;
    }

    if (script == 151)                                      // [  mama's chasing ego
    {
        sound(s.growl, done);
        #message 11  "Oh, dear! You have annoyed Mama Bear by trampling her precious flowers.";
        stop.motion(ego);
        set.view(a.bear.mama, v.bear.mama)
            follow.ego(a.bear.mama, 10, script.done);
    }

    if (script == 152)
    {
        stop.motion(a.bear.mama);
        set.view(a.bear.mama, v.bear.mama.kicking.ego)
            set.cel(a.bear.mama, 0);
        end.of.loop(a.bear.mama, done);

        set.view(ego, v.ego.falling);
        sound(s.ego.falling, done);
        set.priority(ego, 15);
        ignore.obj(ego);
        y = 166;
        step = falling.step.size;
        move.obj.v(ego, ego.x, y, step, script.done);
        bear.status = none;
    }

    if (script == 153)
    {
        erase(ego);
        current.status = stunned;
        edge.ego.hit = bottom;                              // [  new.room to 13, stunned
        script = 0;
    }

    if (script == 202)                                      // [  papa stuns ego, and slams door
    {
        start.update(a.door.rm28);
        end.of.loop(a.door.rm28, script.done);
    }

    if (script == 203)
    {
        set(door.open);
        bear.on.screen = papa;
        set.view(a.bear.papa, v.bear.papa);
        set.loop(a.bear.papa, facing.front);
        set.cel(a.bear.papa, 0);
        set.priority(a.bear.papa, 10);
        ignore.obj(a.bear.papa);
        ignore.block(a.bear.papa);
        position(a.bear.papa, 74, 110);
        draw(a.bear.papa);
        stop.cycling(a.bear.papa);
        script.timer = 4;
    }

    if (script == 204)
    {
        print.at(23, 2, 4, 37);
        set.cel(a.bear.papa, 0);
        work = 4;
        cycle.time(a.bear.papa, work);
        start.cycling(a.bear.papa);
        sound(s.growl, done);
        script.timer = 6;
    }

    if (script == 205)
    {
        work = 1;
        cycle.time(a.bear.papa, work);
        set.view(a.bear.papa, v.bear.papa);
        set.loop(a.bear.papa, facing.front);
        set.cel(a.bear.papa, 0);
        stop.cycling(a.bear.papa);

        set.view(ego, v.ego.falling);
        set(keep.cycling);
        set.priority(ego, 15);
        ignore.blocks(ego);
        move.obj(ego, 86, 133, falling.step.size, script.done);
        sound(s.ego.falling, done);
    }

    if (script == 206)
    {
        set.view(ego, v.ego.stunned);
        stop.motion(ego);
        current.status = stunned;
        stunned.seconds = ego.stunned.time;
        set(sound.done);
        script.timer = 3;
    }

    if (script == 207)
    {
        erase(a.bear.papa);
        set(close.door);
        script = 0;
        if (bear.status == mama.in.garden)
        {
            bear.on.screen = mama;
        }
        else
        {
            bear.on.screen = none;
        }
    }

    if (script == 0 && current.status != stunned)
    {
        player.control();
        accept.input();
        start.motion(ego);
        reset(handsOff);
    }
}

if (aSecondPassed)
{
    --stunned.seconds;
    if (stunned.seconds == 1)
    {
        player.control();
        accept.input();
        reset(handsOff);
        reset(keep.cycling);
        reset(sound.done);
        release.priority(ego);
        stop.sound();
        start.motion(ego);
        current.status = normal.ego;
        set.view(ego, v.ego);
        observe.blocks(ego);
    }
}

if (sound.done && current.status == stunned)
{
    sound(s.ego.stunned, sound.done);
}

if (music.done && bear.on.screen)
{
    sound(m.bears, music.done);
}

// [*****
// :e
// [*****

call(lgc.forest);

if (enter.house && door.open) { new.room(41); }
if (edge.ego.hit == bottom) { new.room(13); }
if (edge.ego.hit == top) { new.room(23); }
if (edge.ego.hit == left) { new.room(27); }
if (edge.ego.hit == right) { new.room(29); }

