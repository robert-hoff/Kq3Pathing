// [logics for room 41 -- Downstairs in the three bears' house
// [  February 19, 1988

#include "gamedefs.reh"
#include  "rm-names.h"
#include "rm41.msg"

// [  If you can enter this room, the bears are not home.  1 in 2 times,
// [3 bowls of porridge are on the table. You can get Baby's bowl.
// [The others are "too hot" or "too cold".
// [
// [  Can sit in the three chairs: message, message, Baby's breaks.
// [There's a fire in the fireplace.  Upstairs is room 42.  Outside is room 28.

#define  sit.baby's       0
#define  sit.mama's      100
#define  sit.papa's      200

#define  crushing.baby.chair    4                           // [  script step # for freezing

#define  papa's        1
#define  mama's        2
#define  baby's        3
#define  fire          4

#define  c.papa        0                                    // [  porridge bowl cell defines
#define  c.mama        1
#define  c.baby        2

#define  nextScript      lf0

#define  closestPorridge    lv0
#define  script        lv2
#define  standingX        lv3
#define  standingY        lv4
#define  scriptSeconds      lv5
#define  closestChair      lv6

% object  aFire        1
% object  aBabyBowl        2
% object  aMamaBowl        3
% object  aPapaBowl        4
% object  aChair        5

if (init.log)
{
    set(interiorRoom);

    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    wiz.x = 66;
    wiz.y = 163;

    landing.x = 66;
    landing.y = 144;

    load.view(v.ego);
    load.view(v.fire);
    load.view(v.ego.sitting);
    load.view(v.ego.breaking.bear.chair);
    load.view(v.porridge);

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    if (positionEgo)
    {
        if (previous.room == 42)                            // [  upstairs
        {
            ego.x = 48;
            ego.y = 68;
        }
        else
        {
            ego.x = 67;
            ego.y = 167;
        }
        position.v(ego, ego.x, ego.y);
    }

    if (drawEgo)
    {
        draw(ego);
    }

    animate.obj(aFire);
    set.view(aFire, v.fire);
    position(aFire, 79, 107);
    draw(aFire);

                                                            // [ if you haven't gotten porridge yet then 50/50 chance the bowls will be here
                                                            // [ but the possible ramifications are endless

                                                            // [ we only pick the number of bowls if they are undisturbed
    if ((previous.room == rm.map || previous.room != 42) && (bowlsOnTable == 0 || bowlsOnTable == 3)) {
        random(1, 2, work);
        if (work == 1) {
            bowlsOnTable = 3;
        }
        else {
            bowlsOnTable = 0;
        }
    }

    if (bowlsOnTable) {
        animate.obj(aMamaBowl);
        set.priority(aMamaBowl, 12);
        set.view(aMamaBowl, v.porridge);
        set.cel(aMamaBowl, c.mama);
        ignore.obj(aMamaBowl);
        position(aMamaBowl, 99, 111);
        draw(aMamaBowl);
        stop.update(aMamaBowl);

        animate.obj(aPapaBowl);
        set.priority(aPapaBowl, 12);
        set.view(aPapaBowl, v.porridge);
        set.cel(aPapaBowl, c.papa);
        ignore.obj(aPapaBowl);
        position(aPapaBowl, 78, 111);
        draw(aPapaBowl);
        stop.update(aPapaBowl);
    }
    if (bowlsOnTable == 3) {                                // [ add babies bowl
        animate.obj(aBabyBowl);
        set.priority(aBabyBowl, 12);
        set.view(aBabyBowl, v.porridge);
        set.cel(aBabyBowl, c.baby);
        ignore.obj(aBabyBowl);
        position(aBabyBowl, 89, 118);
        draw(aBabyBowl);
        stop.update(aBabyBowl);
    }

    animate.obj(aChair);
    set.view(aChair, v.ego.breaking.bear.chair);
    if (baby.chair.broke) {
        set.loop(aChair, 1);
    }
    else {
        set.loop(aChair, 0);
    }
    work = 3;
    cycle.time(aChair, work);
    set.cel(aChair, 0);
    position(aChair, 85, 144);
    draw(aChair);
    stop.update(aChair);

    show.pic();

    return();

}

closestChair = nowhere;
if (posn(ego, 77, 140, 99, 148)) {
    closestChair = baby's;}
        if (posn(ego, 95, 118, 112, 127)) {
            closestChair = mama's;}
                if (posn(ego, 63, 120, 73, 129)) {
                    closestChair = papa's;}

                        closestPorridge = 0;
                    if (bowlsOnTable)
                    {
                        if (posn(ego, 72, 120, 86, 128))
                        {
                            closestPorridge = papa's;
                        }

                        if (posn(ego, 87, 120, 108, 143))
                        {
                            closestPorridge = mama's;
                        }

                        if (obj.in.room(i.porridge, current.room) &&
                            posn(ego, 79, 141, 99, 144))
                        {
                            closestPorridge = baby's;
                        }
                    }

                                                            // [*****
                    :handle.input
                                                            // [*****

                        if (said(look, under, table))
                        {
                            #message 33  "You drop to your hands and knees and look under the pine table. You see
nothing but a clean floor.";
                        }

                    if ((said(look) ||
                        said(look, room) ||
                        said(look, cottage)))
                    {
                        #message 1  "You are in the charming home of the Three Bears.  Mama Bear certainly
does keep her house nice and cozy.";
                    }

                    if ((said(look, fire) ||
                        said(look, fireplace)))
                    {
                        #message 3  "There is a cheery fire crackling in the fireplace, even though it's
summer.";
                    }

                    if (said(open, window)) {
                        #message 31  "The window does not open.";
                    }

                    if ((said(look, out, window) || said(look, window) ||
                        said(look, door) ||
                        said(look, outside)))
                    {
                        #message 4  "You see the forest and Mama Bear's flower garden outside.";
                    }

                    if (said(look, stairs))
                    {
                        #message 5  "A rustic wooden stairway leads to the second floor.";
                    }

                    if (said(look, chairs))
                    {
                        if (!closestChair) {
                            #message 34  "The chairs are arranged in a cozy conversational grouping around the
dining table.";
                            if (baby.chair.broke) {
                                #message 35  "It appears however, that a previous conversation
may have gotten out of hand.";
                            }
                        }

                        if (closestChair == baby's)
                        {
                            if (baby.chair.broke)
                            {
                                #message 6  "There is only a splintered pile of wood that was once a small chair.";
                            }
                            else
                            {
                                #message 26  "The cute little wooden chair looks sturdily built.";
                            }
                        }

                        if (closestChair == mama's)
                        {
                            #message 7  "The medium-sized chair looks very soft and comfortable.";
                        }

                        if (closestChair == papa's)
                        {
                            #message 8  "The wooden chair is very large, and solidly built. It must be Papa Bear's.";
                        }
                    }

                    if ((said(sit, chair) ||
                        said(sit, on, chair) ||
                        said(sit))) {
                        if (!closestChair)
                        {
                            #message 9  "You can't reach it from here.";
                        }

                        if (closestChair == baby's)
                        {
                            if (baby.chair.broke)
                            {
                                #message 25  "%m6 You can't sit on that!";
                            }
                            else
                            {
                                set(baby.chair.broke);
                                    set(nextScript);
                                    script = sit.baby's;
                            }
                        }

                        if (closestChair == mama's)
                        {
                            set(nextScript);
                                script = sit.mama's;
                        }

                        if (closestChair == papa's)
                        {
                            set(nextScript);
                                script = sit.papa's;
                        }
                    }

                    if (said(look, table))
                    {
                        if (!bowlsOnTable)
                        {
                            #message 2  "The large wooden table is clean and polished.";
                        }

                        if (bowlsOnTable == 2)
                        {
                            #message 29  "%m2 %m27";
                        }

                        if (bowlsOnTable == 3)
                        {
                            #message 30  "%m2 %m28";
                        }
                    }

                    if ((said(look, bowl) ||
                        said(look, bowl, porridge) ||
                        said(look, porridge)))
                    {
                        if (!bowlsOnTable)
                        {
                            #message 32  "Where?";
                        }

                        if (bowlsOnTable == 2)
                        {
                            #message 27  "There are two bowls of porridge on the table. One is
too hot, and the other is too cold.";
                        }

                        if (bowlsOnTable == 3)
                        {
                            #message 28  "There are three bowls of porridge on the table. You
are surprised that bears eat porridge.You always thought
they ate honey and berries.";
                        }
                    }

                    if ((said(eat, bowl) ||
                        said(eat, bowl, porridge) ||
                        said(eat, porridge)))
                    {
                        if (!bowlsOnTable)
                        {
                            #message 32  "Where?";
                        }
                        else
                        {
                            if (!closestPorridge)
                            {
                                #message 19  "You're not close enough.";                        // [too far away
                            }

                            if (closestPorridge == papa's)
                            {
                                #message 15  "%m13much too hot.";
                            }

                            if (closestPorridge == mama's)
                            {
                                #message 16  "%m13much too cold.";
                            }

                            if (closestPorridge == baby's)
                            {
                                bowlsOnTable = 2;
                                    start.update(aBabyBowl);
                                    erase(aBabyBowl);
                                    get(i.porridge);
                                    drop(i.porridge);
                                    #message 17  "%m13just right! You take another bite, then another, and another.
Before you realize it, you have downed the entire bowl.";
                            }
                        }
                    }

                    if ((said(get, bowl)
                        || said(get, bowl, porridge) || said(get, porridge))) {
                        if (!bowlsOnTable) {
                            #message 32  "Where?";
                        }
                        else {
                            if (!closestPorridge) {
                                #message 19  "You're not close enough.";
                            }
                            if (closestPorridge == papa's) {
                                #message 20  "%m14much too hot.";
                        }
                        if (closestPorridge == mama's) {
                            #message 21  "%m14much too cold.";
                    }
                    if (closestPorridge == baby's) {
                        bowlsOnTable = 2;
                        start.update(aBabyBowl);
                        erase(aBabyBowl);
                        get(i.porridge);
                        score += 2;
                        #message 22  "%m14just right! So, you take it with you.";
                }
        }
}

// [*****
// [three-chair-script for ego
// [*****

if (aSecondPassed) {
    --scriptSeconds;
    if (scriptSeconds == 1) {
        set(nextScript);
    }
}

if (script == crushing.baby.chair) {
    current.cel(aChair, work);
    if (work == 4) {
        set(nextScript);
    }
}

if (nextScript)
{
    reset(nextScript);
    ++script;

    step = 1;
    program.control();
    prevent.input();
    set(handsOff);

    if (script == 1)                                        // [  move to baby's chair & break it
    {
        if (ego.y < 145)                                    // [  chair is @ 144.
        {
            script = 2;
        }
        else
        {
            x = 77;
            move.obj.v(ego, x, ego.y, step, nextScript);
        }
    }

    if (script == 2) {
        y = 141;
        move.obj.v(ego, ego.x, y, step, nextScript);
    }

    if (script == 3) {
        x = 85;
        move.obj.v(ego, x, ego.y, step, nextScript);
    }

    if (script == crushing.baby.chair) {
        erase(ego);
        start.update(aChair);
        set.cel(aChair, 1);
        end.of.loop(aChair, done);
        start.cycling(aChair);
    }

    if (script == 5) {
        stop.cycling(aChair);
        scriptSeconds = 3;
    }

    if (script == 6) {
        #message 10  "This chair feels just right.";
        scriptSeconds = 5;
    }

    if (script == 7) {
        end.of.loop(aChair, nextScript);
    }

    if (script == 8) {
        #message 36  "Oh, oh!";
        scriptSeconds = 2;
    }

    if (script == 9) {                                      // [  get off your ass, ego
        set.loop(aChair, 1);
        position(ego, 85, 141);
        draw(ego);
        script = 0;
    }

    if (script == 101)                                      // [  SIT IN MAMA'S
    {
        stop.motion(ego);
        get.posn(ego, standingX, standingY);
        set.view(ego, v.ego.sitting);
        set.loop(ego, 0);
        set.cel(ego, 0);
        set.priority(ego, 15);
        reposition.to(ego, 104, 123);
        set(keep.cycling);
        work = 3;
        cycle.time(ego, work);
        end.of.loop(ego, nextScript);
    }

    if (script == 102)
    {
        reset(keep.cycling);
        stop.cycling(ego);
        scriptSeconds = 4;
    }

    if (script == 103)
    {
        #message 11  "You sink deeply into the overstuffed chair... too deeply! This chair is much
too soft.";
        scriptSeconds = 4;
    }

    if (script == 104) {
        set(keep.cycling);
        beginning.of.loop(ego, nextScript);
    }

    if (script == 105) {
        set.view(ego, v.ego);
        set.loop(ego, facing.left);
        reposition.to(ego, 100, 124);
        script = 0;
    }

    if (script == 201)                                      // [  SIT IN PAPA'S
    {
        stop.motion(ego);
        set.view(ego, v.ego.sitting);
        set.loop(ego, 1);
        set.cel(ego, 0);
        set.priority(ego, 15);
        reposition.to(ego, 60, 117);
        set(keep.cycling);
        work = 3;
        cycle.time(ego, work);
        end.of.loop(ego, nextScript);
    }

    if (script == 202) {
        reset(keep.cycling);
        stop.cycling(ego);
        scriptSeconds = 3;
    }

    if (script == 203) {
        #message 12  "You feel very small and uncomfortable in this big chair.
This chair is much too hard.";
        scriptSeconds = 3;
    }

    if (script == 204) {
        set(keep.cycling);
        beginning.of.loop(ego, nextScript);
    }

    if (script == 205) {
        set.view(ego, v.ego);
        set.loop(ego, facing.right);
        reposition.to(ego, 65, 127);
        script = 0;
    }

    if (script == 0) {
        player.control();
        accept.input();
        release.priority(ego);
        start.motion(ego);
        ego.dir = 0;
        reset(keep.cycling);
        reset(handsOff);
        cycle.time(ego, ego.cycle.time);
    }
}

// [*****
// :e
// [*****

if (edge.ego.hit == bottom && ego.x > 63 && ego.x < 74) {
    new.room(28);
}

if (hit.special) {
    new.room(42);
}

