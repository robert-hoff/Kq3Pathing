if (isset(newRoom))
{
    load.view.v(currentEgoView);
    set.view.v(ego, currentEgoView);
    load.view(View0);
    v56 = 1;
    v57 = 94;
    v58 = 131;
    v32 = 99;
    v31 = 136;
    v100 = 62;
    v101 = 121;
    load.logics(Logic104);
    if ((v127 == 1 ||
        v127 == 3) &&
        v137 <= 0 &&
        v128 != 20)
    {
        random(1, 2, v36);
        if (v36 == 1)
        {
            load.logics(Logic105);
            set(f98);
            load.view(View192);
            random(1, 2, v36);
            if (v36 == 1)
            {
                set(f220);
                set(f222);
                v222 = 2;
                v125 = 0;
            }
            else
            {
                v32 = 28;
                v31 = 167;
                random(6, 12, v125);
            }
        }
    }
    if (obj.in.room("Fly Wings*", currentRoom))
{
        load.view(View207);
    }
    load.pic(currentRoom);
    draw.pic(currentRoom);
    discard.pic(currentRoom);
    if (obj.in.room("Fly Wings*", currentRoom))
{
        animate.obj(o1);
        ignore.objs(o1);
        ignore.blocks(o1);
        set.view(o1, View207);
        position(o1, 103, 135);
        draw(o1);
    }
    if (v44 == 25)
    {
        set(f48);
    }
    if (isset(f48))
    {
        if (previousRoom == 3)
        {
            position(ego, 38, 158);
        }
        else
        {
            position.v(ego, v57, v58);
        }
    }
    if (isset(f47))
    {
        draw(ego);
    }
    call(Logic104);
    if (isset(f98))
    {
        call(Logic105);
        if (!isset(f220))
        {
            set.view(o15, View190);
            set.loop(o15, 0);
        }
        else
        {
            v128 = 102;
            set.view(o15, View192);
            v32 = 85;
            v31 = 135;
            set.cel(o15, 0);
            stop.cycling(o15);
            position.v(o15, v32, v31);
            v36 = 2;
            cycle.time(o15, v36);
            draw(o15);
            set(f99);
        }
    }
    show.pic();
    if (isset(f99) &&
        isset(f220) &&
        !isset(f109))
    {
        sound(Sound27, f41);
        print.at("You see Manannan spying on the poor citizens of Llewdor. He "
                  "grunts, clicks his tongue, and mutters to himself. He is spying "
                  "so intensely, he hasn't noticed you.", 2, 2, 37);
    }
    return ();
}
if (!isset(haveInput))
{
    goto(Label1);
}
if ((said("examine", "area") ||
    said("examine") ||
    said("examine", "building") ||
    said("examine", "tower") ||
    said("examine", "area")))
{
    print("You have entered the musty tower of the old wizard's house. A polished "
          "brass telescope is directed out a window. From here, Manannan spies "
          "upon the poor occupants of Llewdor.");
}
if (said("examine", "deck"))
{
    if (obj.in.room("Fly Wings*", currentRoom))
    {
        print("You see nothing on the dusty floor but a dead fly.");
    } else
    {
        print("You hope Manannan doesn't notice the floor needs sweeping.");
    }
}

if (said("examine", "spyglass"))
{
    if (isset(f220))
    {
        print("The wizard wouldn't like that.");
    }
    else
    {
        print("Manannan has the brass telescope pointed out a window. It is well "
              "polished. He uses the telescope to keep tabs on the citizenry of "
              "Llewdor.");
    }
}
if (!isset(f46) && (said("look in", "spyglass") || said("try", "spyglass")))
{
    if (isset(f99))
    {
        print("The wizard wouldn't like that.");
    }
    else
    {
        set(f122);
        v39 = 0;
    }
}

if (said("examine", "stair"))
{
    print("There are narrow, steep stairs leading downwards.");
}
if (said("capture", "bug"))
{
    if (!obj.in.room("Fly Wings*", currentRoom))
    {
        print("You already took it.");
    } else
    {
        if (!posn(ego, 95, 134, 112, 139))
        {
            print("You are not close enough.");
        }
        else
        {
            erase(o1);
            get("Fly Wings*");
            currentScore += 1;
            print("You pick up the dead fly and drop it into your hand. Disgustedly, "
                  "you look at it. \"I don't want to carry around a dead fly,\" you "
                  "think. Picking off its wings, you throw the rest away.");
        }
    }
}
if (said("move", "spyglass") || said("move", "spyglass", "glass"))
{
    if (isset(f220))
    {
        print("The wizard wouldn't like that.");
    }
    else
    {
        print("You push and pull on the heavy brass telescope, but in vain. It's "
              "just too heavy for you.");
    }
}
if (said("capture", "spyglass"))
{
    print("The big brass telescope is much too heavy for you to carry.");
}
if (isset(f220))
{
    if (said("examine", "enchanter"))
    {
        print("The old white-bearded wizard is peering through his telescope. He "
              "hasn't noticed you.");
    }
    if (said("call", "enchanter"))
    {
        ++v129;
    }
}
Label1:
--v223;
if (v223 == 1)
{
    set(f122);
}
if (isset(f122))
{
    reset(f122);
    ++v39;
    program.control();
    set(f46);
    v69 = 1;
    if (v39 == 1)
    {
        if (posn(ego, 42, 120, 110, 131))
        {
            v38 = 131;
            move.obj.v(ego, v40, v38, v69, f122);
            v39 = 4;
        }
        else
        {
            if (posn(ego, 42, 132, 115, 167))
            {
                v38 = 139;
                move.obj.v(ego, v40, v38, v69, f122);
            }
            else
            {
                player.control();
                start.motion(ego);
                reset(f46);
                print("You are not close enough.");
                v39 = 0;
            }
        }
    }
    if (v39 == 2)
    {
        move.obj(ego, 87, 139, 0, f122);
    }
    if (v39 == 3)
    {
        move.obj(ego, 87, 131, 0, f122);
        v39 = 4;
    }
    if (v39 == 5)
    {
        move.obj(ego, 87, 129, 0, f122);
    }
    if (v39 == 6)
    {
        move.obj(ego, 85, 129, 0, f122);
    }
    if (v39 == 7)
    {
        stop.motion(ego);
        v223 = 22;
    }
    if (v39 == 8)
    {
        v39 = 0;
        reset(f46);
        player.control();
        start.motion(ego);
        print("You put your eye to the glass. It amazes you how near everything "
              "seems. You can even see squirrels climbing faraway trees. No wonder "
              "the wizard knows all activities in Llewdor.");
    }
}

if (isset(f45))
{
    if (isset(f99) && isset(f220) && !isset(f109))
    {
        --v222;
        if (v222 == 5)
        {
            start.cycling(o15);
        }
        if (v222 == 1)
        {
            stop.cycling(o15);
            set.cel(o15, 0);
            random(17, 22, v68);
            print.v(v68);
            random(10, 30, v222);
        }
    }
}

if (isset(f99) && !isset(f109))
{
    if (!isset(f222) && !isset(f220))
    {
        set(f222);
        v124 = 0;
        set(f101);
    }
    if (isset(f101))
    {
        reset(f101);
        ++v124;
        if (v124 == 1)
        {
            move.obj(o15, 63, 130, 1, f101);
        }
        if (v124 == 2)
        {
            move.obj(o15, 88, 130, 1, f101);
        }
        if (v124 == 3)
        {
            move.obj(o15, 88, 133, 1, f101);
        }
        if (v124 == 4)
        {
            move.obj(o15, 85, 133, 1, f101);
        }
        if (v124 == 5)
        {
            v124 = 0;
            set(f220);
            set.view(o15, View192);
            set.cel(o15, 0);
            stop.cycling(o15);
            random(10, 30, v222);
        }
    }
}

if (edgeEgoHit == BOTTOM_EDGE && v44 != 125 && v40 > 25 && v40 < 47)
{
    new.room(Logic3);
}
call(Logic104);

if (isset(f98))
{
    call(Logic105);
}
return ();


[Messages
#message 1 "You have entered the musty tower of the old wizard's house. A polished brass telescope is directed out a window. From here, Manannan spies upon the poor occupants of Llewdor."
#message 2 "You see nothing on the dusty floor but a dead fly."
#message 3 "Manannan has the brass telescope pointed out a window. It is well polished. He uses the telescope to keep tabs on the citizenry of Llewdor."
#message 4 "You put your eye to the glass. It amazes you how near everything seems. You can even see squirrels climbing faraway trees. No wonder the wizard knows all activities in Llewdor."
#message 5 "There are narrow, steep stairs leading downwards."
#message 6 "You hope Manannan doesn't notice the floor needs sweeping."
#message 7 "You pick up the dead fly and drop it into your hand. Disgustedly, you look at it. \"I don't want to carry around a dead fly,\" you think. Picking off its wings, you throw the rest away."
#message 8 "You already took it."
#message 9 "The old white-bearded wizard is peering through his telescope. He hasn't noticed you."
#message 10 "The wizard wouldn't like that."
#message 11 ""
#message 12 ""
#message 13 "The big brass telescope is much too heavy for you to carry."
#message 14 ""
#message 15 "You push and pull on the heavy brass telescope, but in vain. It's just too heavy for you."
#message 16 "You see Manannan spying on the poor citizens of Llewdor. He grunts, clicks his tongue, and mutters to himself. He is spying so intensely, he hasn't noticed you."
#message 17 "\"Those little devils! What are they doing?\""
#message 18 "\"They are going to regret this!\""
#message 19 "\"Very good, my little pets. You're doing well these days.\""
#message 20 "\"I can't believe they would do this! They know my rules!\""
#message 21 "\"Well, I can see those wretches need my attention down there!\""
#message 22 "\"Tsk, tsk. What a shame. And they seemed so obedient at first.\""
#message 23 ""
#message 24 ""
#message 25 ""
#message 26 ""
#message 27 "You are not close enough."



