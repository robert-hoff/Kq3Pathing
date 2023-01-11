// [logics for room -- rm37:outside bandit hideout
// [  February 3, 1988

#include "gamedefs.reh"
#include "rm37.msg"
#include  "rm-names.h"

#define  entering.hideout    1
#define  ladder.exit      2

#define  fall.done        lf0
#define  caught.ego      lf1

% object  a.bandit        1

if (init.log) {

    reset(handsOff);
    set(interiorRoom);

    if (!found.house) {
        set(found.house);
        score += 2;
    }
                                                            // [  wiz.x = 78;
                                                            // [  wiz.y = 0;

    landing.x = 93;
    landing.y = 136;

    ignore.block(ego);

    load.view(v.ego);
    load.view(v.ego.falling);
    load.view(v.ego.climbing.ladder);
    load.view.f(current.ego);
    set.view.f(ego, current.ego);

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

                                                            // [ sound stuff
    load.sound(s.ego.falling);
    load.sound(s.ego.stunned);

    if (current.status == fly) {
        set(positionEgo);
        set(drawEgo);
    }

    if (positionEgo) {
        if (previous.room == 38) {
            start.motion(ego);
            ego.dir = 3;
            position(ego, 83, 110);
            if (bandit.status == awake) {                   // [ he's going to kill you
                animate.obj(a.bandit);
                load.view(v.bandit.1);
                set.view(a.bandit, v.bandit.1);
                ignore.blocks(a.bandit);
                ignore.objs(a.bandit);
                position(a.bandit, 70, 113);
                work = 2;
                cycle.time(a.bandit, work);
                draw(a.bandit);
                follow.ego(a.bandit, 5, caught.ego);
                start.motion(ego);
                program.control();
            }
        }
        if (previous.room == 22) {                          // [entering from rm22
            current.status = climbing;
            position(ego, 93, 165);
            set.view(ego, v.ego.climbing.ladder);
            set.loop(ego, 0);
            fix.loop(ego);

        }
    }
    if (previous.room != rm.map && previous.room != 38) {
                                                            // [ do the set up for the next room
        random(1, 255, work);
        if (work > 64) {
            bandit.status = awake;
        }
        else {
            bandit.status = asleep;
        }
    }

    if (current.status == deferred.entry) {
        set(positionEgo);
        set(drawEgo);
        current.status = climbing;
        position(ego, 93, 165);
        set.view(ego, v.ego.climbing.ladder);
        set.loop(ego, 0);
        fix.loop(ego);
    }

    if (drawEgo) {
        draw(ego);
    }

    show.pic();
    return();

}

if (ego.poofing.done && current.status == normal.ego) {
    ignore.blocks(ego);
    current.status = climbing;
    set.view(ego, v.ego.climbing.ladder);
    set.loop(ego, 0);
    fix.loop(ego);
}

ego.location = nowhere;
if (posn(ego, 89, 110, 91, 116))
{
    ego.location = ladder.exit;
}

if (posn(ego, 70, 98, 73, 114))
{
    ego.location = entering.hideout;
}

// [*****
// [Ladders pray
// [*****

if (current.status == normal.ego &&                         // [enter top of ladder
    ego.location == ladder.exit &&
    (ego.dir == ego.right ||
        ego.dir == ego.down.right ||
        ego.dir == ego.up.right))
{
    set.view(ego, v.ego.climbing.ladder);
    set.loop(ego, 0);
    fix.loop(ego);
    ego.x = 93;
    reposition.to.f(ego, ego.x, ego.y);
    start.motion(ego);
    current.status = climbing;
}

if (current.status == climbing &&                           // [exit top of ladder
    ego.location == ladder.exit &&
    (ego.dir == ego.left ||
        ego.dir == ego.down.left ||
        ego.dir == ego.up.left))
{
    release.loop(ego);
    set.view(ego, v.ego);
    ego.x = 87;
    reposition.to.f(ego, ego.x, ego.y);
    start.motion(ego);
    set.loop(ego, facing.left);
    current.status = normal.ego;
}

// [*****
// [fall
// [*****

if (current.status == falling) {
    set(caught.ego);
}

if (caught.ego) {
    reset(caught.ego);
    stop.motion(a.bandit);
    normal.motion(a.bandit);
    stop.cycling(a.bandit);
    set(hit.special);
}

if (current.status != falling && hit.special) {
    sound(s.ego.falling, sound.done);
    set.view(ego, v.ego.falling);
    set.priority(ego, 15);
    y = 167;
    work = 6;
    move.obj.f(ego, ego.x, y, work, fall.done);
    current.status = falling;
}

if (fall.done) {
    reset(fall.done);
    edge.ego.hit = bottom;
    erase(ego);
}

// [ don't let a storm happen
if (has(i.storm.brew) && spell.cast == sc.make.storm) {
    spell.cast = 0;
    #message 13  "On second thought, you decide not to make a storm. You remember how
dangerous it is to be in a tree during a storm.";
}

// [*****
// [handle.input
// [*****

if (have.input)
{
    if ((said(look) ||
        said(look, house) ||
        said(look, tree))) {
        #message 1  "You are standing outside a shack that has been built in the branches of the
spreading oak tree.A rope ladder leads down toward the ground.";
    }

    if ((said(look$in, house) ||
        said(look$in) ||
        said(look$in, door, house) ||
        said(look, inside, room) ||
        said(look$in, door)))
    {
        if (bandit.status == awake) { #message 2  "There seems to be somebody moving around inside the treehouse."; }
        else { #message 3  "You can see very little of the interior from out here. But there seems
to be a figure sleeping in a chair."; }
    }

    if (said(look, door)) { #message 4  "The doorway of the treehouse is only a rough opening in the planks."; }

    if (said(anyword, window)) { #message 5  "There is no window, only a hole cut in the side."; }

    if ((said(look, rope, ladder) || said(look, ladder))) {
        #message 6  "The rope ladder drops down through the leaves of the huge tree toward
the ground below.";
    }

    if ((said(climb, tree) ||
        said(climb, up, tree) ||
        said(climb, down, tree))) {
        #message 7  "The tree looks very difficult to climb around on, but you can try if you
wish.";
    }

    if ((said(look, sky) ||
        said(look, up))) {
        #message 8  "The thick leaves of the oak tree allow only rare glimpses of the sky above.";
    }

    if ((said(look, ground) ||
        said(look, down))) {
        #message 9  "The thick leaves and massive branches obscure the ground below.";
    }

    if (said(look, bandit))
    {
        if (bandit.status == awake) { #message 10  "You can see someone moving about, but can not make out details from here."; }
        else { #message 11  "You see no one else around."; }
    }
}

// [*****
// [exit              // [  test for leaving the room
// [*****

if (edge.ego.hit == bottom) {
    new.room(22);
}

if (ego.location == entering.hideout && current.status == normal.ego) {
    new.room(38);
}

