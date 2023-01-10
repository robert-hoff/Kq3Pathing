if (isset(newRoom))
{
    if (v186 == 0)
    {
        v182 = 86;
        v185 = 58;
        v186 = 151;
    }
    animate.obj(o1);
    load.view(View168);
    set.view(o1, View168);
    position.v(o1, v185, v186);
    if (v182 == currentRoom)
    {
        draw(o1);
    }
    return ();
}
if (v44 == 200)
{
    if (egoDir > STOPPED)
    {
        prevent.input();
        get.posn(o1, v40, v41);
        v41 -= 1;
        reposition.to.v(ego, v40, v41);
        start.motion(ego);
        v44 = 0;
        release.priority(ego);
        observe.blocks(ego);
        accept.input();
    }
}


if (v44 == 201 && isset(egoHitSpecial))
{
    prevent.input();
    set(f36);
    ignore.blocks(ego);
    ignore.objs(ego);
    if ((egoDir == UP_RIGHT ||
        egoDir == RIGHT ||
        egoDir == DOWN_RIGHT))
    {
        move.obj(ego, 125, 148, 6, f242);
    }
    else
    {
        if ((egoDir == DOWN_LEFT ||
            egoDir == LEFT ||
            egoDir == UP_LEFT))
        {
            move.obj(ego, 90, 148, 6, f242);
        }
        else
        {
            release.priority(ego);
            v38 = 142;
            v241 = 6;
            move.obj.v(ego, v40, v38, v241, f242);
        }
    }
    set.scan.start();
    if (isset(f242))
    {
        reset(f36);
        observe.blocks(ego);
        observe.objs(ego);
        v44 = 0;
        release.priority(ego);
        accept.input();
        reset.scan.start();
    }
    return ();
}


if (v71 == 12)
{
    print("As your sleep spell takes effect, a silence suddenly descends over the ship.");
    v71 = 0;
    set(f181);
    v52 = 0;
    v53 = 0;
    if (v62 == 2)
    {
        set(f46);
        v240 = 10;
        prevent.input();
        program.control();
    }
}


if (isset(f45) && v240 > 0)
{
    --v240;
    if (v240 == 7)
    {
        set.loop(ego, 2);
    }
    if (v240 == 5)
    {
        print("\"Wait a second...\"");
        print("\"Who's steering the ship?\" you ask.");
    }
    if (v240 == 0)
    {
        print("Unfortunately, there is no reply.");
        print("With no one to steer the ship, you are doomed to drift at sea forever.");
        stop.cycling(ego);
        set(f44);
    }
}


if (said("examine", "bin"))
{
    if (currentRoom == 85)
    {
        if (v182 == currentRoom)
        {
            print("%m6 There is also a smaller crate here.");
        }
        else
        {
            print("You notice many crates and boxes in the cargo hold. One, in "

                    "particular, captures your attention, for it lies directly under "

                    "the dangling rope ladder!");
        }
    }
    else
    {
        if (v182 == currentRoom)
        {
            print("%m8 There is also a smaller crate here.");
        }
        else
        {
            print("Large wooden crates are stacked along one wall of the hold.");
        }
    }
}
if (said("lift", "up", "bin") || said("lift", "bin"))
{
    print("The crates are sealed tightly. You can't open them no matter what you "
            "do.");
}

if (said("capture", "up", "bin") || said("capture", "bin"))
{
    if ((isset(f46) ||
        v44 != 0))
    {
        print("You can't do that... at least not now!");
    }
    else
    {
        if (v182 != currentRoom)
        {
            print("All of the large crates are too heavy to move.");
        }
        else
        {
            distance(ego, o1, v36);
            if (v36 < 12)
            {
                v182 = 0;
                erase(o1);
                set.view(ego, View37);
                v44 = 202;
                set(f46);
            }
            else
            {
                print("You're not close enough.");
            }
        }
    }
}
if ((said("add", "bin", "down") ||
    said("add", "down", "bin") ||
    said("add", "bin", "on", "deck") ||
    said("add", "bin", "down", "on", "deck") ||
    said("add", "bin")))
{
    if (v182 != 0)
    {
        print("You're not carrying a box, are you?");
    }
    else
    {
        v182 = currentRoom;
        reset(f46);
        v185 = v40;
        v186 = v41;
        current.loop(ego, v36);
        set.view(ego, View0);
        if (v36 == 0)
        {
            v185 += 6;
        }
        else
        {
            v40 += 6;
            reposition.to.v(ego, v40, v41);
        }
        position.v(o1, v185, v186);
        draw(o1);
        v44 = 0;
    }
}
if (said("move", "bin"))
{
    print("All of the large crates are too heavy to move.");
}
if ((said("look in", "bin") ||
    said("lift", "up", "bin") ||
    said("lift", "bin")))
{
    print("All of the crates are nailed shut. You have no means of opening them.");
}
if ((said("capture", "on", "bin") ||
    said("climb", "on", "bin") ||
    said("climb", "bin")))
{
    print("Why don't you try jumping.");
}
if ((said("jump") ||
    said("jump", "up") ||
    said("jump", "up", "ladder") ||
    said("jump", "up", "on", "ladder") ||
    said("jump", "on", "ladder") ||
    said("jump", "ladder")))
{
    if (v44 != 201)
    {
        goto(Label1);
    }
    else
    {
        set(f35);
        set.view(ego, View36);
        set.cel(ego, 0);
        end.of.loop(ego, f242);
        set.scan.start();
        if (isset(f242))
        {
            reset(f35);
            set(f36);
            set.view(ego, View30);
            set.loop(ego, 0);
            fix.loop(ego);
            v36 = 245;
            reposition(ego, v140, v36);
            move.obj(ego, 110, 94, 4, f242);
            release.priority(ego);
            ignore.blocks(ego);
            set.scan.start();
            if (isset(f242))
            {
                reset(f242);
                reset(f36);
                reposition.to(ego, 110, 94);
                v44 = 15;
                reset.scan.start();
            }
        }
        return ();
    }
}
if ((said("jump") ||
    said("jump", "bin") ||
    said("jump", "up") ||
    said("jump", "up", "bin") ||
    said("jump", "on", "bin") ||
    said("jump", "up", "on", "bin")))
{
    if (v44 == 200)
    {
        if (!posn(o1, 93, 140, 127, 151))
        {
            goto(Label1);
        }
        else
        {
            ignore.blocks(ego);
            set.view(ego, View36);
            set.cel(ego, 0);
            move.obj(ego, 110, 122, 1, f242);
            set.scan.start();
            current.cel(ego, v36);
            if (v36 == 2)
            {
                set(f36);
                v36 = 245;
                set.view(ego, View0);
                reset(f36);
                reposition(ego, v140, v36);
                set.scan.start();
                set.priority(ego, 13);
                if (isset(f242))
                {
                    reset(f242);
                    v44 = 201;
                    set.priority(ego, 13);
                    observe.blocks(ego);
                    reset.scan.start();
                }
            }
        }
        return ();
    }
    if (v44 == 0)
    {
        distance(ego, o1, v36);
        if (v36 > 16)
        {
            goto(Label1);
        }
        else
        {
            start.motion(ego);
            set.view(ego, View36);
            set.cel(ego, 0);
            end.of.loop(ego, f241);
            set(f35);
            egoDir = STOPPED;
            get.priority(ego, v36);
            set.priority.v(ego, v36);
            ignore.blocks(ego);
            set.scan.start();
            if (isset(f241))
            {
                reset(f241);
                get.posn(o1, v37, v38);
                v37 += 2;
                v38 -= 10;
                erase(ego);
                set.view(ego, View0);
                position.v(ego, v37, v38);
                draw(ego);
                reset(f35);
                v44 = 200;
                start.motion(ego);
                reset.scan.start();
            }
        }
        return ();
    }
Label1:
    if (v44 == 202)
    {
        print("You can't jump while you are carrying a crate around.");
        return ();
    }
    if (v44 == 15)
    {
        print("Now is not the time to be jumping.");
        return ();
    }
    start.motion(ego);
    set.view(ego, View36);
    set.cel(ego, 0);
    set(f35);
    end.of.loop(ego, f242);
    set.scan.start();
    edgeEgoHit = NOT_HIT;
    if (isset(f242))
    {
        reverse.loop(ego, f242);
        set.scan.start();
        edgeEgoHit = NOT_HIT;
        if (isset(f242))
        {
            reset(f242);
            normal.cycle(ego);
            set.view(ego, View0);
            reset(f35);
            reset.scan.start();
        }
    }
    return ();
}
return ();

[Messages
#message 1 "The crates are sealed tightly. You can't open them no matter what you do."
#message 2 "You try to jump up on the large crates, but they are too tall!"
#message 3 "You're not close enough."
#message 4 "All of the crates are nailed shut. You have no means of opening them."
#message 5 "You're not carrying a box, are you?"
#message 6 "You notice many crates and boxes in the cargo hold. One, in particular, captures your attention, for it lies directly under the dangling rope ladder!"
#message 7 "%m6 There is also a smaller crate here."
#message 8 "Large wooden crates are stacked along one wall of the hold."
#message 9 "%m8 There is also a smaller crate here."
#message 10 "All of the large crates are too heavy to move."
#message 11 "Why don't you try jumping."
#message 12 "As your sleep spell takes effect, a silence suddenly descends over the ship."
#message 13 "\"Wait a second...\""
#message 14 "\"Who's steering the ship?\" you ask."
#message 15 "Unfortunately, there is no reply."
#message 16 "You can't jump while you are carrying a crate around."
#message 17 "Now is not the time to be jumping."
#message 18 "You can't do that... at least not now!"
#message 19 "With no one to steer the ship, you are doomed to drift at sea forever."



