
if (isset(newRoom))
{
    load.pic(currentRoom);
    draw.pic(currentRoom);
    discard.pic(currentRoom);
    v56 = 7;
    reset(f34);
    v57 = 105;
    v58 = 124;
    v32 = 87;
    v31 = 116;
    load.logics(Logic112);
    load.logics(Logic116);
    load.view(View0);
    load.view(View11);
    load.view(View30);
    load.view(View24);
    load.view(View35);
    load.view.v(currentEgoView);
    set.view.v(ego, currentEgoView);
    load.sound(Sound1);
    load.sound(Sound6);
    if (v44 == 15)
    {
        ignore.horizon(ego);
        ignore.blocks(ego);
        if (previousRoom == 78)
        {
            position(ego, 113, 31);
        }
        else
        {
            position(ego, 113, 158);
        }
        set.priority(ego, 4);
        set.view(ego, View30);
        set.loop(ego, 1);
        fix.loop(ego);
    }
    if (v44 == 0)
    {
        set.view(ego, View0);
        if (previousRoom == 0)
        {
            position.v(ego, v57, v58);
        }
        if (previousRoom == 81)
        {
            position(ego, 151, 167);
        }
        if (previousRoom == 79)
        {
            start.motion(ego);
            egoDir = DOWN_RIGHT;
            if (v41 > 130)
            {
                position(ego, 48, 127);
            }
            else
            {
                position(ego, 73, 117);
            }
        }
    }
    if (v44 == 30)
    {
        set.view(ego, View0);
        set(f48);
        position.v(ego, v57, v58);
        set(f47);
    }
    if (isset(f47))
    {
        draw(ego);
    }
    v36 = 0;
    if (v62 == 2)
    {
        v36 = 1;
    }
    call(Logic112);
    show.pic();
    return ();
}
call(Logic112);
call(Logic116);


if (v44 == 0)
{
    if (posn(ego, 139, 128, 140, 157))
    {
        set.loop(ego, 1);
        fix.loop(ego);
        set(f221);
    }
    else
    {
        if (isset(f221))
        {
            release.loop(ego);
            reset(f221);
        }
    }
}


if (v44 == 15 && !posn(ego, 113, 0, 115, 167))
{
    v44 = 6;
    set.view(ego, View11);
    release.loop(ego);
    sound(Sound1, f238);
    if (v41 > 149)
    {
        goto(Label1);
    }
    if (v41 > 40)
    {
        reset(f223);
        v221 = v40;
        v222 = 134;
    }
    else
    {
        set(f223);
        v221 = v40;
        v222 = 134;
    }
    v36 = 3;
    move.obj.v(ego, v221, v222, v36, f222);
    set.scan.start();
    if (isset(f222))
    {
        program.control();
        reset(f222);
        observe.blocks(ego);
        stop.sound();
        if (isset(f223))
        {
            set.view(ego, View24);
            v44 = 20;
            reposition.to(ego, 102, 126);
            reset.scan.start();
        }
        else
        {
            set.view(ego, View35);
            reposition.to(ego, 105, 128);
            sound(Sound6, f238);
            v220 = 5;
            v44 = 18;
            set(f35);
            set.scan.start();
            if (isset(f45))
            {
                --v220;
            }
            if (v220 > 0 &&
                isset(f238))
            {
                sound(Sound6, f238);
            }
            if (v220 <= 0)
            {
                stop.sound();
                reset(f35);
                player.control();
                reposition.to(ego, 109, 126);
                set.view(ego, View0);
                observe.blocks(ego);
                release.priority(ego);
                release.loop(ego);
                v44 = 0;
                reset.scan.start();
            }
        }
    }
    return ();
}

if (posn(ego, 113, 136, 115, 150))
{
    if (v44 == 15)
    {
        if (egoDir != UP && egoDir != DOWN && egoDir != STOPPED)
        {
            v44 = 0;
            release.loop(ego);
            observe.blocks(ego);
            observe.horizon(ego);
            release.priority(ego);
            set.view(ego, View0);
            if (egoDir > DOWN)
            {
                reposition.to(ego, 110, 146);
            }
            else
            {
                reposition.to(ego, 117, 138);
            }
        }
    }
    else
    {
        if (v44 == 0)
        {
            v44 = 15;
            start.motion(ego);
            ignore.horizon(ego);
            ignore.blocks(ego);
            set.priority(ego, 4);
            set.view(ego, View30);
            set.loop(ego, 1);
            fix.loop(ego);
            reposition.to(ego, 113, 142);
        }
    }
}

if ((isset(egoHitSpecial) || isset(onWater)) && v44 != 6)
{
Label1:
    sound(Sound1, f238);
    v44 = 6;
    set.view(ego, View11);
    ignore.blocks(ego);
    set.priority(ego, 4);
    v38 = 166;
    v37 = 3;
    move.obj.v(ego, v40, v38, v37, f220);
}
else
{
    if (said("examine") || said("examine", "ship"))
    {
        print("This is the upper deck of the pirate ship. A ladder leads to the "
                "lower deck.");
    }
    if (said("examine", "up", "mast") ||
        said("examine", "mast"))
    {
        print("The solid mast is swaying slightly. A rope ladder leads up into the "
                "rigging.");
    }
    if (said("examine", "up", "ladder") ||
        said("examine", "ladder")) {
        print("The rope ladder looks flimsy. A careless step might be fatal!");
    }
    if (said("examine", "carry") ||
        said("look in", "carry") ||
        said("look in", "hole") ||
        said("examine", "hole"))
    {
        print("The hatchway leads below decks. The bright sun affords little "
                "illumination of what may lie below.");
    }
    if (said("look in", "door") || said("examine", "door"))
    {
        print("The doorways at the stern give way to darkness.");
    }
    if (said("dive", "bay") ||
        said("board", "bay") ||
        said("capture", "bay") ||
        said("jump") ||
        said("jump", "ship") ||
        said("jump", "bay") ||
        said("dive") ||
        said("dive", "liquid") ||
        said("board", "liquid") ||
        said("capture", "liquid") ||
        said("jump") ||
        said("jump", "ship") ||
        said("jump", "liquid") ||
        said("dive"))
    {
        print("The railing is too high for you to get over.");
    }
    if (said("examine", "sky"))
    {
        if (v62 == 2)
        {
            print("The sky is a deep, cloudless blue. You see sea birds high above you.");
        }
        else
        {
            print("Shore birds can be seen in the cloudless sky.");
        }
    }
    if ((said("examine", "desert") ||
        said("examine", "liquid") ||
        said("examine", "bay")))
    {
        if (v62 == 3)
        {
            print("You scan the horizon. You see land to the east.");
        }
        if (v62 == 2)
        {
            print("The ocean seems to be endless. In every direction, you see nothing "
                    "but deep, blue water.");
        }
        if (v62 == 4)
        {
            print("The ship has anchored just offshore of a small beach. Further "
                    "north, in the distance, looms a mountain range.");
        }
    }
    if (v62 == 4 &&
        (said("examine", "beach") ||
        said("examine", "beach")))
    {
        print("The ship has anchored just offshore of a small beach. Further north, "
                "in the distance, looms a mountain range.");
    }
    if (said("examine", "bandit"))
    {
        print("At the moment, you see no pirates.");
    }
    call(Logic112);
    if (edgeEgoHit > NOT_HIT && (v44 == 25 || v44 == 26))
    {
        if (edgeEgoHit == TOP_EDGE || edgeEgoHit == BOTTOM_EDGE)
        {
            if (v62 != 4)
            {
                new.room(Logic31);
            }
            else
            {
                new.room(Logic48);
            }
        }
        if (edgeEgoHit == LEFT_EDGE)
        {
            new.room(Logic82);
        }
        if (edgeEgoHit == RIGHT_EDGE)
        {
            new.room(Logic81);
        }
    }
    if (v44 == 15 &&
        edgeEgoHit == TOP_EDGE)
    {
        new.room(Logic78);
    }
    if (v44 == 15 &&
        edgeEgoHit == BOTTOM_EDGE)
    {
        new.room(Logic83);
    }
    if (edgeEgoHit == RIGHT_EDGE)
    {
        new.room(Logic81);
    }
    if (v44 == 0 &&
        (posn(ego, 68, 103, 73, 115) ||
        posn(ego, 37, 122, 45, 131)))
    {
        new.room(Logic79);
    }
    return ();
}


set.scan.start();
if (isset(f220))
{
    reset.scan.start();
    erase(ego);
    new.room(Logic83);
}
return ();

[Messages
#message 1 "Darn that flimsy ladder!"
#message 2 "This is the upper deck of the pirate ship. A ladder leads to the lower deck."
#message 3 "The solid mast is swaying slightly. A rope ladder leads up into the rigging."
#message 4 "The rope ladder looks flimsy. A careless step might be fatal!"
#message 5 "The hatchway leads below decks. The bright sun affords little illumination of what may lie below."
#message 6 "The doorways at the stern give way to darkness."
#message 7 "The railing is too high for you to get over."
#message 8 "You scan the horizon. You see land to the east."
#message 9 "The ocean seems to be endless. In every direction, you see nothing but deep, blue water."
#message 10 "The ship has anchored just offshore of a small beach. Further north, in the distance, looms a mountain range."
#message 11 "At the moment, you see no pirates."
#message 12 "The sky is a deep, cloudless blue. You see sea birds high above you."
#message 13 "Shore birds can be seen in the cloudless sky."



