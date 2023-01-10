if (isset(newRoom))
{
    set(f34);
    load.view.v(currentEgoView);
    set.view.v(ego, currentEgoView);
    v32 = 66;
    v31 = 163;
    v57 = 66;
    v58 = 144;
    load.view(View0);
    load.view(View178);
    load.view(View31);
    load.view(View17);
    load.view(View85);
    load.pic(currentRoom);
    draw.pic(currentRoom);
    discard.pic(currentRoom);
    if (isset(f48))
    {
        if (previousRoom == 42)
        {
            v40 = 48;
            v41 = 68;
        }
        else
        {
            v40 = 67;
            v41 = 167;
        }
        position.v(ego, v40, v41);
    }
    if (isset(f47))
    {
        draw(ego);
    }
    animate.obj(o1);
    set.view(o1, View178);
    position(o1, 79, 107);
    draw(o1);
    if ((previousRoom == 89 ||
        previousRoom != 42) &&
        (v190 == 0 ||
        v190 == 3))
    {
        random(1, 2, v36);
        if (v36 == 1)
        {
            v190 = 3;
        }
        else
        {
            v190 = 0;
        }
    }
    if (v190 > 0)
    {
        animate.obj(o3);
        set.priority(o3, 12);
        set.view(o3, View85);
        set.cel(o3, 1);
        ignore.objs(o3);
        position(o3, 99, 111);
        draw(o3);
        stop.update(o3);
        animate.obj(o4);
        set.priority(o4, 12);
        set.view(o4, View85);
        set.cel(o4, 0);
        ignore.objs(o4);
        position(o4, 78, 111);
        draw(o4);
        stop.update(o4);
    }
    if (v190 == 3)
    {
        animate.obj(o2);
        set.priority(o2, 12);
        set.view(o2, View85);
        set.cel(o2, 2);
        ignore.objs(o2);
        position(o2, 89, 118);
        draw(o2);
        stop.update(o2);
    }
    animate.obj(o5);
    set.view(o5, View17);
    if (isset(f175))
    {
        set.loop(o5, 1);
    }
    else
    {
        set.loop(o5, 0);
    }
    v36 = 3;
    cycle.time(o5, v36);
    set.cel(o5, 0);
    position(o5, 85, 144);
    draw(o5);
    stop.update(o5);
    show.pic();
    return ();
}
v226 = 0;
if (posn(ego, 77, 140, 99, 148))
{
    v226 = 3;
}
if (posn(ego, 95, 118, 112, 127))
{
    v226 = 2;
}
if (posn(ego, 63, 120, 73, 129))
{
    v226 = 1;
}
v220 = 0;
if (v190 > 0)
{
    if (posn(ego, 72, 120, 86, 128))
    {
        v220 = 1;
    }
    if (posn(ego, 87, 120, 108, 143))
    {
        v220 = 2;
    }
    if (obj.in.room("Porridge", currentRoom) &&
        posn(ego, 79, 141, 99, 144))
{
        v220 = 3;
    }
}
if (said("examine", "below", "counter"))
{
    print("You drop to your hands and knees and look under the pine table. You "
          "see nothing but a clean floor.");
}
if ((said("examine") ||
    said("examine", "area") ||
    said("examine", "building")))
{
    print("You are in the charming home of the Three Bears.  Mama Bear certainly "
            "does keep her house nice and cozy.");
}
if ((said("examine", "fire") ||
    said("examine", "fireplace")))
{
    print("There is a cheery fire crackling in the fireplace, even though it's "
            "summer.");
}
if (said("lift", "glass"))
{
    print("The window does not open.");
}
if ((said("examine", "out", "glass") ||
    said("examine", "glass") ||
    said("examine", "door") ||
    said("examine", "out")))
{
    print("You see the forest and Mama Bear's flower garden outside.");
}
if (said("examine", "stair"))
{
    print("A rustic wooden stairway leads to the second floor.");
}
if (said("examine", "bench"))
{
    if (v226 <= 0)
    {
        print("The chairs are arranged in a cozy conversational grouping around the "
                "dining table.");
        if (isset(f175))
        {
            print("It appears however, that a previous conversation may have gotten "
                    "out of hand.");
        }
    }
    if (v226 == 3)
    {
        if (isset(f175))
        {
            print("There is only a splintered pile of wood that was once a small "
                    "chair.");
        }
        else
        {
            print("The cute little wooden chair looks sturdily built.");
        }
    }
    if (v226 == 2)
    {
        print("The medium-sized chair looks very soft and comfortable.");
    }
    if (v226 == 1)
    {
        print("The wooden chair is very large, and solidly built. It must be Papa "
                "Bear's.");
    }
}
if ((said("get in", "bench") ||
    said("get in", "on", "bench") ||
    said("get in")))
{
    if (v226 <= 0)
    {
        print("You can't reach it from here.");
    }
    if (v226 == 3)
    {
        if (isset(f175))
        {
            print("%m6 You can't sit on that!");
        }
        else
        {
            set(f175);
            set(f220);
            v222 = 0;
        }
    }
    if (v226 == 2)
    {
        set(f220);
        v222 = 100;
    }
    if (v226 == 1)
    {
        set(f220);
        v222 = 200;
    }
}
if (said("examine", "counter"))
{
    if (v190 <= 0)
    {
        print("The large wooden table is clean and polished.");
    }
    if (v190 == 2)
    {
        print("%m2 %m27");
    }
    if (v190 == 3)
    {
        print("%m2 %m28");
    }
}
if ((said("examine", "basin") ||
    said("examine", "basin", "porridge") ||
    said("examine", "porridge")))
{
    if (v190 <= 0)
    {
        print("Where?");
    }
    if (v190 == 2)
    {
        print("There are two bowls of porridge on the table. One is too hot, and "
                "the other is too cold.");
    }
    if (v190 == 3)
    {
        print("There are three bowls of porridge on the table. You are surprised "
                "that bears eat porridge. You always thought they ate honey and "
                "berries.");
    }
}
if ((said("drink", "basin") ||
    said("drink", "basin", "porridge") ||
    said("drink", "porridge")))
{
    if (v190 <= 0)
    {
        print("Where?");
    }
    else
    {
        if (v220 <= 0)
        {
            print("You're not close enough.");
        }
        if (v220 == 1)
        {
            print("%m13much too hot.");
        }
        if (v220 == 2)
        {
            print("%m13much too cold.");
        }
        if (v220 == 3)
        {
            v190 = 2;
            start.update(o2);
            erase(o2);
            get("Porridge");
            drop("Porridge");
            print("%m13just right! You take another bite, then another, and another. "
                    "Before you realize it, you have downed the entire bowl.");
        }
    }
}


if (said("capture", "basin") || said("capture", "basin", "porridge") || said("capture", "porridge"))
{
    if (v190 <= 0)
    {
        print("Where?");
    }
    else
    {
        if (v220 <= 0)
        {
            print("You're not close enough.");
        }
        if (v220 == 1)
        {
            print("%m14much too hot.");
        }
        if (v220 == 2)
        {
            print("%m14much too cold.");
        }
        if (v220 == 3)
        {
            v190 = 2;
            start.update(o2);
            erase(o2);
            get("Porridge");
            currentScore += 2;
            print("%m14just right! So, you take it with you.");
        }
    }
}

if (isset(f45))
{
    --v225;
    if (v225 == 1)
    {
        set(f220);
    }
}

if (v222 == 4)
{
    current.cel(o5, v36);
    if (v36 == 4)
    {
        set(f220);
    }
}

if (isset(f220))
{
    reset(f220);
    ++v222;
    v69 = 1;
    program.control();
    prevent.input();
    set(f46);
    if (v222 == 1)
    {
        if (v41 < 145)
        {
            v222 = 2;
        }
        else
        {
            v37 = 77;
            move.obj.v(ego, v37, v41, v69, f220);
        }
    }
    if (v222 == 2)
    {
        v38 = 141;
        move.obj.v(ego, v40, v38, v69, f220);
    }
    if (v222 == 3)
    {
        v37 = 85;
        move.obj.v(ego, v37, v41, v69, f220);
    }
    if (v222 == 4)
    {
        erase(ego);
        start.update(o5);
        set.cel(o5, 1);
        end.of.loop(o5, f41);
        start.cycling(o5);
    }
    if (v222 == 5)
    {
        stop.cycling(o5);
        v225 = 3;
    }
    if (v222 == 6)
    {
        print("This chair feels just right.");
        v225 = 5;
    }
    if (v222 == 7)
    {
        end.of.loop(o5, f220);
    }
    if (v222 == 8)
    {
        print("Oh, oh!");
        v225 = 2;
    }
    if (v222 == 9)
    {
        set.loop(o5, 1);
        position(ego, 85, 141);
        draw(ego);
        v222 = 0;
    }
    if (v222 == 101)
    {
        stop.motion(ego);
        get.posn(ego, v223, v224);
        set.view(ego, View31);
        set.loop(ego, 0);
        set.cel(ego, 0);
        set.priority(ego, 15);
        reposition.to(ego, 104, 123);
        set(f35);
        v36 = 3;
        cycle.time(ego, v36);
        end.of.loop(ego, f220);
    }
    if (v222 == 102)
    {
        reset(f35);
        stop.cycling(ego);
        v225 = 4;
    }
    if (v222 == 103)
    {
        print("You sink deeply into the overstuffed chair... too deeply! This chair "

                "is much too soft.");
        v225 = 4;
    }
    if (v222 == 104)
    {
        set(f35);
        reverse.loop(ego, f220);
    }
    if (v222 == 105)
    {
        set.view(ego, View0);
        set.loop(ego, 1);
        reposition.to(ego, 100, 124);
        v222 = 0;
    }
    if (v222 == 201)
    {
        stop.motion(ego);
        set.view(ego, View31);
        set.loop(ego, 1);
        set.cel(ego, 0);
        set.priority(ego, 15);
        reposition.to(ego, 60, 117);
        set(f35);
        v36 = 3;
        cycle.time(ego, v36);
        end.of.loop(ego, f220);
    }
    if (v222 == 202)
    {
        reset(f35);
        stop.cycling(ego);
        v225 = 3;
    }
    if (v222 == 203)
    {
        print("You feel very small and uncomfortable in this big chair. This chair "
                "is much too hard.");
        v225 = 3;
    }
    if (v222 == 204)
    {
        set(f35);
        reverse.loop(ego, f220);
    }
    if (v222 == 205)
    {
        set.view(ego, View0);
        set.loop(ego, 0);
        reposition.to(ego, 65, 127);
        v222 = 0;
    }
    if (v222 == 0)
    {
        player.control();
        accept.input();
        release.priority(ego);
        start.motion(ego);
        egoDir = STOPPED;
        reset(f35);
        reset(f46);
        cycle.time(ego, v59);
    }
}
if (edgeEgoHit == BOTTOM_EDGE &&
    v40 > 63 &&
    v40 < 74)
{
    new.room(Logic28);
}
if (isset(egoHitSpecial))
{
    new.room(Logic42);
}
return ();

[Messages
#message 1 "You are in the charming home of the Three Bears.  Mama Bear certainly does keep her house nice and cozy."
#message 2 "The large wooden table is clean and polished."
#message 3 "There is a cheery fire crackling in the fireplace, even though it's summer."
#message 4 "You see the forest and Mama Bear's flower garden outside."
#message 5 "A rustic wooden stairway leads to the second floor."
#message 6 "There is only a splintered pile of wood that was once a small chair."
#message 7 "The medium-sized chair looks very soft and comfortable."
#message 8 "The wooden chair is very large, and solidly built. It must be Papa Bear's."
#message 9 "You can't reach it from here."
#message 10 "This chair feels just right."
#message 11 "You sink deeply into the overstuffed chair... too deeply! This chair is much too soft."
#message 12 "You feel very small and uncomfortable in this big chair. This chair is much too hard."
#message 13 "You taste the porridge and decide that this bowl of porridge is "
#message 14 "This bowl of porridge is "
#message 15 "%m13much too hot."
#message 16 "%m13much too cold."
#message 17 "%m13just right! You take another bite, then another, and another. Before you realize it, you have downed the entire bowl."
#message 18 "You ate it all."
#message 19 "You're not close enough."
#message 20 "%m14much too hot."
#message 21 "%m14much too cold."
#message 22 "%m14just right! So, you take it with you."
#message 23 "There are only two bowls on the table; one is too hot, and the other too cold."
#message 24 ""
#message 25 "%m6 You can't sit on that!"
#message 26 "The cute little wooden chair looks sturdily built."
#message 27 "There are two bowls of porridge on the table. One is too hot, and the other is too cold."
#message 28 "There are three bowls of porridge on the table. You are surprised that bears eat porridge. You always thought they ate honey and berries."
#message 29 "%m2 %m27"
#message 30 "%m2 %m28"
#message 31 "The window does not open."
#message 32 "Where?"
#message 33 "You drop to your hands and knees and look under the pine table. You see nothing but a clean floor."
#message 34 "The chairs are arranged in a cozy conversational grouping around the dining table."
#message 35 "It appears however, that a previous conversation may have gotten out of hand."
#message 36 "Oh, oh!"




