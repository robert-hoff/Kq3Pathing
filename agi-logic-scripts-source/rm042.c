// [logics for room -- 42: Bear's bedroom

#include "gamedefs.reh"
#include "rm42.msg"

#define  script      lv0
#define  start  0
#define  to.bed  1
#define  at.bed  2
#define  wake.up  3
#define  carried  4
#define  tossed  5
#define  end    6

#define  movement      lv1
#define  m.none    0
#define  m.corner    1
#define  m.bedside    2
#define  m.jumping    3
#define  m.on.bed    4
#define  m.off.bed    5
#define  m.sleeping  6
#define  m.bouncing  7
#define  m.falling    8

#define  drawer.status    lv3
#define  closed  0
#define  open    1

#define  drawer.timer    lv4

#define  sleep.timer    lv5
#define  waking.x      lv6
#define  waking.y      lv7

#define  script.timer    lv8
#define  the.bed      lv9
#define  papas.bed  1
#define  mamas.bed  2
#define  babys.bed  3

#define  snore.timer    lv10

#define  next        lf0
#define  snore.done    lf1
#define  ego.caught    lf2
#define  bed.time      lf3
#define  drawer.done    lf4
#define  by.drawer      lf5

% object  aBear    1
% object  a.drawer      2

if (init.log) {
    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    wiz.x = 58;
    wiz.y = 115;

    landing.x = 68;
    landing.y = 122;

    set(interiorRoom);

    load.sound(s.snoring);
    load.sound(s.ego.falling);

    load.view(v.ego.hanging.in.kitchen);
    load.view(v.ego);
    load.view(v.ego.sleeping.l / r);
    load.view(v.ego.falling);

    load.view.f(current.ego);
    set.view.f(ego, current.ego);

    if (positionEgo) {
        position(ego, 51, 116);
        set.loop(ego, 3);
    }

    if (current.status == deferred.entry) {
        set.view(ego, v.ego);
        set(positionEgo);
        position.f(ego, landing.x, landing.y);
        set(drawEgo);
    }

    if (drawEgo) {
        draw(ego);
    }

                                                            // [ the drawer
    animate.obj(a.drawer);
    load.view(v.drawer.rm42);
    set.view(a.drawer, v.drawer.rm42);
    position(a.drawer, 96, 96);
    set.loop(a.drawer, 0);
    set.cel(a.drawer, 0);
    work = 2;
    cycle.time(a.drawer, work);
    draw(a.drawer);
    stop.update(a.drawer);

                                                            // [ papa bear
    animate.obj(aBear);
    load.view(v.bear.papa);
    set.view(aBear, v.bear.papa);
    position(aBear, 49, 116);
    set.loop(aBear, 0);
    set.cel(aBear, 0);
                                                            // [ don't draw him

    show.pic();
    return();

}

if (current.status == normal.ego) {
    ego.location = nowhere;
    if (posn(ego, 94, 109, 101, 110)) {
        set(by.drawer);
    }
    else {
        reset(by.drawer);
    }

    if (posn(ego, 86, 129, 124, 165)) {
        ego.location = papas.bed;
    }

    if (posn(ego, 34, 143, 54, 165)) {
        ego.location = mamas.bed;
    }

    if (posn(ego, 85, 108, 111, 128)) {
        ego.location = babys.bed;
    }
}

// [ sleeping around stuff

if (aSecondPassed && sleep.timer) {
    --sleep.timer;
}

// [ go bed ambiguity

if (current.status == entranced) {
    if (have.input) {
        #message 19  "Shhhh! You'll wake yourself up.";
    }
}

if (current.status == sleeping) {
    if (have.input && (said(wake, up) ||
        said(get$out, bed) ||
        said(get, up, bed) ||
        said(get, up, from, bed) ||
        said(get, up))) {
        #message 23  "Good idea. You've got too much to do to be lying around in a strange bed.";
        sleep.timer = 2;
        ego.location = papas.bed;                           // [ fake it out
    }
}

if (current.status == normal.ego &&
    (said(go, bed) ||
        said(lie, on, bed) ||
        said(lie, bed) ||
        said(try, out, bed) ||
        said(go, sleep) ||
        said(sleep, on, bed) ||
        said(sleep, bed) ||
        said(get$in, bed) ||
        said(get, on, bed))) {
    if (ego.location == nowhere) {
        #message 17  "You need to move closer.";
    }
    else {                                                  // [ who's bed
        set(handsOff);                                      // [ reset when he gets up
        get.posn(ego, waking.x, waking.y);
        set.view(ego, v.ego.sleeping.l / r);
        set.cel(ego, 0);
        set.priority(ego, 15);
        current.status = sleeping;
        start.motion(ego);
        program.control();
        if (ego.location == papas.bed) {
            reposition.to(ego, 100, 132);
            #message 2  "You flop onto the biggest (and hardest) bed!";
            set.cel(ego, 2);
            set.loop(ego, 0);
            sleep.timer = 10;
        }
        if (ego.location == mamas.bed) {
            reposition.to(ego, 32, 143);
            #message 1  "You jump onto the medium-sized bed and sink deep into its fluffy depths.";
            set.loop(ego, 1);
            sleep.timer = 10;
        }
        if (ego.location == babys.bed) {
            reposition.to(ego, 87, 107);
            #message 3  "You lie upon the smallest bed, and snuggle down into the pillow.";
            set.loop(ego, 0);
            sleep.timer = 10;
        }
    }
}

if (aSecondPassed && current.status == sleeping) {
    if (sleep.timer == 5) {                                 // [ first message
        if (ego.location == papas.bed) {
            #message 18  "This bed is MUCH too hard!";
        }
        if (ego.location == mamas.bed) {
            #message 25  "This bed is MUCH too soft!";
        }
        if (ego.location == babys.bed) {
            work = 3;
            cycle.time(ego, work);
            #message 22  "Ahhhh! This bed is just right. You've fallen asleep.";
            snore.timer = 2;
            prevent.input();
        }
    }
    if (sleep.timer == 1) {                                 // [ second message
        if ((ego.location == papas.bed
            || ego.location == mamas.bed)) {
            set.view(ego, v.ego);
            reposition.to.f(ego, waking.x, waking.y);
            release.priority(ego);
            current.status = normal.ego;
            reset(handsOff);
            player.control();
            reset(keep.cycling);
        }
        else {
            current.status = entranced;
            script = 0;
            script.timer = 10;
        }
    }
}

--snore.timer;
if (snore.timer == 1) {
    sound(s.snoring, sound.done);
    set(keep.cycling);
    set.cel(ego, 0);
    end.of.loop(ego, snore.done);
}

if (snore.done) {
    reset(snore.done);
    snore.timer = SNOREDELAY;
    reset(keep.cycling);
}

// [**** the bear script ****]

if (aSecondPassed && script.timer) {
    --script.timer;
    if (script.timer == 0) {
        set(next);
    }
}

if (next) {
    program.control();
    prevent.input();
}

if (next && script == start) {
    reset(next);
    set(handsOff);
    ++script;
                                                            // [  position.to(aBear, 49, 116);
    draw(aBear);
    move.obj(aBear, 55, 110, 1, next);
}

if (next && script == to.bed) {
    reset(next);
    ++script;
    move.obj(aBear, 95, 110, 1, next);
}

if (next && script == at.bed) {
    reset(next);
    ++script;
    set.loop(aBear, facing.front);
    script.timer = 1;
}

if (next && script == wake.up) {
    reset(next);
    ++script;
    print.at(20, 2, 2, 37);
                                                            // [ now we wake up ego and tuck him under bears arm
    ignore.blocks(ego);
    ignore.objs(ego);
    set.view(ego, v.ego.hanging.in.kitchen);
    reset(keep.cycling);
    snore.timer = 0;
    move.obj(aBear, 55, 110, 1, next);
    current.status = normal.ego;
}

if (script == carried) {
    get.posn(aBear, x, y);
    x -= 7;
    y += 1;
    reposition.to.f(ego, x, y);
    get.priority(aBear, work);
    set.priority.f(ego, work);
}

if (next && script == carried) {
    reset(next);
    ++script;
    set.loop(aBear, facing.front);
    stop.cycling(aBear);
    set.view(ego, v.ego.falling);
    sound(s.ego.falling, sound.done);
    set.priority(ego, 6);
    work = 1;
    cycle.time(ego, work);
    move.obj(ego, 48, 167, 4, next);
}

if (next && script == tossed) {
    player.control();
    ++script;
    reset(next);
    current.status = normal.ego;
    reset(handsOff);
    player.control();
    accept.input();
    new.room(28);
}

// [*****
// [Get in their drawers
// [*****

--drawer.timer;
if (drawer.timer == 1)
{
    stop.update(a.drawer);
    if (drawer.status == open)
    {
        if (obj.in.room(i.thimble, current.room))
        {
            #message 7  "You open the drawer, and among the clothes, you see a pretty silver thimble.";
        }
        else
        {
            #message 14  "You open the drawer and see some bear-sized clothes.";
        }
    }
}

// [*****
// [handle.input
// [*****

if (have.input) {

    if (said(look, bed)) {
        if (ego.location == nowhere) {
            #message 15  "You are in the Bear family's cozy bedroom. You see three
beds and a chest of drawers.";
        }
        if (ego.location == papas.bed) {
            #message 27  "This is a big, old bed. It must be Papa Bear's.";
        }
        if (ego.location == mamas.bed) {
            #message 28  "This looks like a nice, soft bed. Maybe it's Mama Bear's.";
        }
        if (ego.location == babys.bed) {
            #message 29  "This bed looks just the right size for you.";
        }
    }

    if ((said(open, drawer) ||
        said(open, chest) ||
        said(open, dresser, drawer)))
    {
        if (by.drawer)
        {
            if (drawer.status == open)
            {
                #message 12  "It is already open.";
            }
            else
            {
                start.update(a.drawer);
                end.of.loop(a.drawer, drawer.done);
                drawer.status = open;
                drawer.timer = 30;
            }
        }
        else                                                // [too far away
        {
            #message 17  "You need to move closer.";
        }
    }

    if ((said(close, drawer) ||
        said(close, chest) ||
        said(close, dresser, drawer)))
    {
        if (by.drawer)
        {
            if (drawer.status == closed)
            {
                #message 9  "The drawer is already closed.";
            }
            else
            {
                start.update(a.drawer);
                reverse.loop(a.drawer, drawer.done);
                drawer.status = closed;
                drawer.timer = 30;
            }
        }
        else                                                // [too far away
        {
            #message 16  "A dresser sits in the corner of the room.";
        }

    }

    if (said(look, under, bed)) {
        if (ego.location == nowhere) {
            #message 17  "You need to move closer.";
        }
        else {
            #message 4  "There is nothing of interest under the bed.";
        }
    }

    if (said(get, thimble)) {
        if (!obj.in.room(i.thimble, current.room)) {
            #message 13  "You have already taken it!";
        }
        else {
            if (!by.drawer) {
                #message 17  "You need to move closer.";
            }
            else {
                if (drawer.status == closed) {
                    #message 5  "You open the drawer, take the thimble, and close the drawer in one
fluid movement.";
                }
                else {
                    #message 8  "You pick up the thimble and carry it with you.";
                }
                get(i.thimble);
                score += 1;
            }
        }
    }

    if (said(get, clothes)) {
        #message 26  "They wouldn't fit you.";
    }

    if ((said(look$in, drawer) || said(look, drawer))) {
        if (by.drawer) {
            if (drawer.status == closed) {
                #message 21  "The drawers are shut.";
            }
            else {
                if (!obj.in.room(i.thimble, current.room)) {
                    #message 11  "You see a few bear-sized clothes.";
                }
                else {
                    #message 10  "You see a few bear-sized clothes and a silver thimble.";
                }
            }
        }
        else {
            #message 17  "You need to move closer.";
        }
    }

    if ((said(look) || said(look, room) ||
        said(look, bedroom) || said(look, house))) {
        #message 15  "You are in the Bear family's cozy bedroom. You see three
beds and a chest of drawers.";
    }

    if ((said(look, chest) ||
        said(look, dresser)))
    {
        #message 16  "A dresser sits in the corner of the room.";
    }
}

// [*****
// :e
// [*****

if (hit.special && current.status == normal.ego) {
    new.room(41);
}


