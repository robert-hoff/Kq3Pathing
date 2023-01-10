if (isset(newRoom))
{
    if ((v76 > 0 || v75 > 0) && previousRoom == 41)
    {
        v72 = previousRoom;
        new.room(Logic87);
    }
    load.view.v(currentEgoView);
    set.view.v(ego, currentEgoView);
    load.view(View0);
    v56 = 2;
    set(f71);
    set.horizon(55);
    v31 = 0;
    random(1, 2, v36);
    if (v36 == 1)
    {
        v57 = 10;
        v58 = 73;
    }
    else
    {
        v57 = 135;
        v58 = 83;
    }
    load.logics(Logic111);
    load.view(View95);
    load.view(View232);
    random(1, 9, v36);
    if (v36 == 1)
    {
        v221 = 50;
    }
    else
    {
        if (v36 == 2)
        {
            v221 = 100;
        }
        else
        {
            if (v36 < 5)
            {
                v221 = 150;
            }
            else
            {
                if (v36 < 7)
                {
                    v221 = 200;
                }
                else
                {
                    v221 = 250;
                }
            }
        }
    }
    if ((isset(f46) ||
        previousRoom == 41 ||
        v44 == 30))
    {
        v221 = 250;
    }
    if (previousRoom == 42)
    {
        v221 = 70;
    }
    if (isset(f31) &&
        v96 > 0)
    {
        v221 = v96;
        v96 = 0;
    }
    if (v221 == 50)
    {
        load.view(View80);
        load.view(View82);
        load.view(View84);
        load.sound(Sound34);
        animate.obj(o1);
        animate.obj(o2);
        animate.obj(o3);
        ignore.objs(o1);
        ignore.objs(o2);
        ignore.objs(o3);
    }
    if (v221 == 100)
    {
        load.view(View80);
        load.view(View82);
        load.view(View84);
        load.view(View11);
        load.view(View35);
        load.sound(Sound1);
        load.sound(Sound6);
        load.sound(Sound34);
        load.sound(Sound12);
        animate.obj(o1);
        animate.obj(o2);
        animate.obj(o3);
        ignore.objs(o1);
        ignore.objs(o2);
        ignore.objs(o3);
    }
    if (v221 == 150)
    {
        load.view(View80);
        load.view(View82);
        load.view(View86);
        load.view(View83);
        load.view(View11);
        load.view(View35);
        load.sound(Sound1);
        load.sound(Sound6);
        load.sound(Sound12);
        animate.obj(o1);
        animate.obj(o2);
        ignore.objs(o1);
        ignore.objs(o2);
    }
    if ((v221 == 200 ||
        v221 == 70))
    {
        load.view(View80);
        load.view(View11);
        load.view(View35);
        load.sound(Sound1);
        load.sound(Sound6);
        load.sound(Sound12);
        animate.obj(o1);
        ignore.objs(o1);
    }
    if (v221 == 250)
    {
        // [WARNING: this block contains no commands
        }
    load.pic(currentRoom);
    draw.pic(currentRoom);
    discard.pic(currentRoom);
    animate.obj(o4);
    set.view(o4, View95);
    set.cel(o4, 0);
    v36 = 3;
    cycle.time(o4, v36);
    ignore.blocks(o4);
    ignore.objs(o4);
    set.priority(o4, 9);
    position(o4, 77, 109);
    draw(o4);
    stop.update(o4);
    animate.obj(o5);
    set.view(o5, View232);
    set.loop(o5, 0);
    set.cel(o5, 0);
    v36 = 4;
    cycle.time(o5, v36);
    ignore.horizon(o5);
    ignore.blocks(o5);
    position(o5, 108, 10);
    draw(o5);
    if (v44 == 25)
    {
        set(f48);
    }
    if (isset(f48))
    {
        if ((previousRoom == 41 ||
            previousRoom == 42))
        {
            v40 = 73;
            v41 = 118;
        }
        if (previousRoom == 27)
        {
            if (v41 > 92 &&
                v41 < 97)
            {
                v41 = 92;
            }
        }
        if (previousRoom == 29)
        {
            if (v41 > 70 &&
                v41 < 74)
            {
                v41 = 70;
            }
            if (v41 > 142 &&
                v41 < 147)
            {
                v41 = 142;
            }
        }
        position.v(ego, v40, v41);
    }
    if (isset(f47))
    {
        draw(ego);
    }
    if (v221 == 70)
    {
        program.control();
        prevent.input();
        v220 = 70;
        set(f227);
    }
    if (v221 == 150)
    {
        v225 = 1;
        set.view(o2, View86);
        position(o2, 40, 130);
        v36 = 6;
        cycle.time(o2, v36);
        object.on.water(o2);
        draw(o2);
    }
    if ((v221 == 50 ||
        v221 == 100))
    {
        v225 = 4;
        program.control();
        stop.motion(ego);
        set.view(o1, View80);
        set.view(o2, View82);
        set.view(o3, View84);
        if (v221 == 50)
        {
            v220 = 50;
            set(f227);
            set(f220);
        }
        if (v221 == 100)
        {
            v220 = 100;
            position(o1, 148, 166);
            draw(o1);
            set.loop(o1, 1);
            move.obj(o1, 137, 155, 1, f227);
        }
    }
    call(Logic111);
    show.pic();
    if ((v221 == 50 ||
        v221 == 100))
    {
        sound(Sound34, f228);
    }
    return ();
}
v39 = 0;
if (posn(ego, 0, 94, 95, 167))
{
    v39 = 4;
}
if (isset(onWater))
{
    v39 = 1;
}
if (posn(ego, 70, 108, 84, 118))
{
    v39 = 3;
}
if ((posn(ego, 84, 115, 96, 125) ||
    posn(ego, 97, 98, 111, 121)))
{
    v39 = 5;
}
if (isset(haveInput))
{
    if (said("examine", "bear"))
    {
        if (v225 <= 0)
        {
            print("Where?");
        }
        if (v225 == 1)
        {
            print("%m1 To your surprise, you see a bear, wearing a dress, working in "

                    "the garden. It must be Mama Bear!");
        }
        if (v225 == 2)
        {
            print("He doesn't seem happy to see you.");
        }
        if (v225 == 4)
        {
            print("You see three fully-clothed bears!");
        }
    }
    if (said("call", "bear"))
    {
        if (v225 <= 0)
        {
            print("Where?");
        }
        else
        {
            if (v225 == 4)
            {
                print("Evidently, they don't hear you.");
            }
            else
            {
                if (v225 == 1)
                {
                    ++v226;
                    if (v226 == 1)
                    {
                        sound(Sound12, f41);
                        print("Your cordial greeting annoys the bear, and she growls back, "

                                "\"Grrrrrrrrrrrrreetings yourrrrrrrrrrself, young man. Stay "

                                "out of my garden!\"");
                    }
                    else
                    {
                        if (v226 == 2)
                        {
                            sound(Sound12, f41);
                            print("Again, you speak to the bear. \"Grrrrrrrrrrr!\" she growls "

                                    "menacingly. \"We don't take to strangers here. Go away!\"");
                        }
                        else
                        {
                            sound(Sound12, f41);
                            print("Insistently, you talk to the bear yet again. She ignores "

                                    "you, but you hear a constant low growl from deep within "

                                    "her.");
                        }
                    }
                }
            }
        }
        if (v225 > 0 &&
            said("capture", "bear"))
        {
            print("It is utterly impossible for you to catch a big bear.");
        }
        if (v225 > 0 &&
            said("kill", "bear"))
        {
            print("How could you hurt a big bear? You couldn't.");
        }
        if (v225 > 0 &&
            said("embrace", "bear"))
        {
            print("A strange idea.");
        }
    }
    if ((said("examine", "flower") ||
        said("look in", "flower") ||
        said("examine", "dew", "flower")))
    {
        if (v39 == 1)
        {
            print("You carefully peek into the pretty flowers of the flower garden. "

                    "Drops of glistening dew have gathered within their soft petals.");
        }
        else
        {
            if (v221 == 150)
            {
                print("%m1 To your surprise, you see a bear, wearing a dress, working "

                        "in the garden. It must be Mama Bear!");
            }
            else
            {
                print("There are lovely flowers growing in this well-tended garden. "

                        "Their sweet scent and beautiful colors delight you.");
            }
        }
    }
    if ((said("examine", "garden") ||
        said("examine", "flower", "garden") ||
        said("examine", "flower") ||
        said("examine", "flower", "flower", "garden")))
    {
        if (v221 == 150)
        {
            print("%m1 To your surprise, you see a bear, wearing a dress, working in "

                    "the garden. It must be Mama Bear!");
        }
        else
        {
            print("There are lovely flowers growing in this well-tended garden. Their "

                    "sweet scent and beautiful colors delight you.");
        }
    }
    if ((said("examine", "building") ||
        said("examine")))
    {
        print("This is the comfortable home of the Three Bears. A well-tended "

                "flower garden grows out front.");
    }
    if ((said("examine", "area") ||
        said("look in", "glass") ||
        said("examine", "glass")))
    {
        if (v39 == 5)
        {
            print("You peer through the window, but the inside is dimly lit and you "

                    "cannot make out any details.");
        }
        else
        {
            print("You need to move closer.");
        }
    }
    if ((said("examine", "door") ||
        said("examine", "door", "building")))
    {
        print("The heavy wooden door is closed.");
    }
    if ((said("capture", "flower") ||
        said("capture", "flower", "flower", "garden")))
    {
        if (v39 == 1)
        {
            print("You wouldn't want to spoil the lovely flower bed by picking one!");
        }
        else
        {
            print("You need to move closer.");
        }
    }
    if (v39 == 1 &&
        (said("examine", "dew") ||
        said("examine", "dew", "flower")))
    {
        print("The dew is beautiful.");
    }
    if ((said("capture", "dew") ||
        said("capture", "dew", "flower") ||
        said("capture", "dew", "flower", "garden") ||
        said("capture", "dew", "thimble") ||
        said("capture", "dew", "flower", "thimble") ||
        said("capture", "thimble", "dew") ||
        said("capture", "thimble", "dew", "flower") ||
        said("capture", "dew", "flower", "garden") ||
        said("capture", "dew", "from", "flower") ||
        said("capture", "dew", "from", "flower", "garden") ||
        said("capture", "dew", "flower", "thimble") ||
        said("capture", "dew", "from", "flower", "garden", "thimble") ||
        said("capture", "thimble", "dew") ||
        said("capture", "thimble", "dew", "from", "flower") ||
        said("capture", "thimble", "dew", "from", "flower", "garden")))
    {
        if (v39 != 1)
        {
            print("You need to move closer.");
        }
        else
        {
            if (has("Thimble and Dew*"))
            {
                print("Your thimble is already full of dew.");
            }
            else
            {
                if (!has("Thimble*"))
                {
                    print("You must have a thimble in order to get a thimbleful of dew.");
                }
                else
                {
                    drop("Thimble*");
                    get("Thimble and Dew*");
                    print("Holding the silver thimble beneath a dew-filled flower, you "

                            "gently tip the flower so its dew runs into the thimble. You "

                            "move from flower to flower, repeating the process until your "

                            "thimble is brimming with dew.");
                    if (!isset(f103))
                    {
                        set(f103);
                        currentScore += 1;
                    }
                }
            }
        }
    }
    if (!isset(f46) &&
        (said("bang") ||
        said("bang", "on", "door") ||
        said("bang", "door") ||
        said("bang", "door", "building") ||
        said("bang", "on", "building", "door")))
    {
        if (v39 != 3)
        {
            print("You need to move closer.");
        }
        else
        {
            if (v221 == 250)
            {
                print("You rap lightly on the door of the charming house.");
                print("No reply.");
                print("You knock again, louder.");
                print("Again, there is no response.");
                print("Perhaps no one is home?");
            }
            else
            {
                v220 = 201;
                stop.motion(ego);
                program.control();
                prevent.input();
                start.update(o4);
                end.of.loop(o4, f227);
            }
        }
    }
    if (!isset(f46) &&
        (said("lift", "door") ||
        said("move", "knob") ||
        said("move", "door", "knob") ||
        said("move", "knob", "door") ||
        said("move", "door", "handle") ||
        said("move", "handle", "door")))
    {
        if (v39 != 3)
        {
            print("You need to move closer.");
        }
        else
        {
            if ((v221 == 250 ||
                v221 == 50))
            {
                set(f220);
                set(f226);
            }
            else
            {
                v220 = 201;
                set(f227);
            }
        }
    }
    if (said("examine", "bluff"))
    {
        print("You see a lone mountain peak in the distance. Dark clouds swirl "

                "around its summit.");
    }
}
if (v221 == 150 &&
    v39 == 1 &&
    v220 <= 0)
{
    v220 = 150;
    set(f227);
}
if (v39 != 1 &&
    v220 == 151)
{
    accept.input();
    v220 = 0;
    set.view(o2, View86);
    normal.motion(o2);
    stop.motion(o2);
}
if (isset(f45))
{
    --v222;
    if (v222 == 1)
    {
        set(f227);
    }
    --v223;
    if (v39 == 4 &&
        v220 <= 0 &&
        v221 == 150 &&
        v223 <= 0)
    {
        v223 = 10;
        print("Mama Bear growls at you as you near the flower bed. Better stay away "

                "from it... and HER!");
    }
}
if (isset(f220))
{
    reset(f220);
    start.update(o4);
    end.of.loop(o4, f222);
}
if (isset(f222))
{
    reset(f222);
    set(f221);
    stop.update(o4);
    if ((v220 == 106 ||
        v220 == 50))
    {
        set(f227);
    }
}
if (isset(f223))
{
    reset(f223);
    reset(f221);
    start.update(o4);
    reverse.loop(o4, f224);
}
if (isset(f224))
{
    reset(f224);
    stop.update(o4);
}
if (isset(f227))
{
    reset(f227);
    ++v220;
    program.control();
    prevent.input();
    set(f46);
    if (v220 == 51)
    {
        stop.motion(ego);
        position(o1, 75, 124);
        set.loop(o1, 0);
        draw(o1);
        v225 = 4;
        move.obj(o1, 84, 124, 1, f227);
    }
    if (v220 == 52)
    {
        position(o2, 75, 124);
        set.loop(o2, 0);
        draw(o2);
        move.obj(o2, 106, 124, 1, f227);
        move.obj(o1, 95, 124, 1, f227);
    }
    if (v220 == 53)
    {
        position(o3, 75, 124);
        set.loop(o3, 0);
        draw(o3);
        move.obj(o3, 106, 124, 1, f227);
        move.obj(o1, 106, 124, 1, f227);
        print.at("What's this? Three clothed bears??\n\nYou hear Papa Bear exclaim, "

                    "\"What a beautiful day for a stroll through the forest.\"", 2, 2, 37);
        set(f223);
    }
    if (v220 == 54)
    {
        move.obj(o1, 148, 166, 1, f227);
    }
    if (v220 == 55)
    {
        move.obj(o2, 148, 166, 1, f227);
    }
    if (v220 == 56)
    {
        move.obj(o3, 149, 167, 1, f227);
    }
    if (v220 == 57)
    {
        erase(o1);
    }
    if (v220 == 58)
    {
        erase(o2);
    }
    if (v220 == 59)
    {
        erase(o3);
        v225 = 0;
        v221 = 250;
        stop.sound();
        reset(f228);
        v220 = 0;
    }
    if (v220 == 71)
    {
        set(f221);
        v225 = 2;
        set.view(o1, View80);
        set.loop(o1, 2);
        set.cel(o1, 0);
        set.priority(o1, 10);
        ignore.objs(o1);
        ignore.blocks(o1);
        position(o1, 74, 110);
        draw(o1);
        print("\"AND STAY OUT!!!\"");
        v220 = 205;
    }
    if (v220 == 101)
    {
        stop.motion(ego);
        v225 = 4;
        move.obj(o1, 128, 146, 1, f227);
        position(o2, 148, 166);
        set.loop(o2, 1);
        draw(o2);
        move.obj(o2, 106, 124, 1, f227);
    }
    if (v220 == 102)
    {
        move.obj(o1, 106, 124, 1, f227);
        position(o3, 149, 167);
        set.loop(o3, 1);
        draw(o3);
        move.obj(o3, 106, 124, 1, f227);
        print.at("There are three fully-clothed bears coming!\n\nYou hear Mama Bear "

                    "say, \"Thank you, Dear. That was a lovely walk.\"", 2, 2, 37);
    }
    if (v220 == 103)
    {
        move.obj(o1, 75, 124, 1, f227);
    }
    if (v220 == 104)
    {
        move.obj(o2, 75, 125, 1, f41);
    }
    if (v220 == 105)
    {
        move.obj(o3, 75, 126, 1, f41);
    }
    if (v220 == 106)
    {
        set(f220);
    }
    if (v220 == 107)
    {
        move.obj(o1, 75, 120, 1, f227);
    }
    if (v220 == 108)
    {
        erase(o1);
        move.obj(o2, 75, 120, 1, f227);
    }
    if (v220 == 109)
    {
        erase(o2);
        move.obj(o3, 75, 120, 1, f227);
    }
    if (v220 == 110)
    {
        erase(o3);
        set(f223);
        v221 = 200;
        v225 = 0;
        stop.sound();
        reset(f228);
        v220 = 0;
    }
    if (v220 == 151)
    {
        sound(Sound12, f41);
        print("Oh, dear! You have annoyed Mama Bear by trampling her precious "

                "flowers.");
        stop.motion(ego);
        set.view(o2, View82);
        follow.ego(o2, 10, f227);
    }
    if (v220 == 152)
    {
        stop.motion(o2);
        set.view(o2, View83);
        set.cel(o2, 0);
        end.of.loop(o2, f41);
        set.view(ego, View11);
        sound(Sound1, f41);
        set.priority(ego, 15);
        ignore.objs(ego);
        v38 = 166;
        v69 = 3;
        move.obj.v(ego, v40, v38, v69, f227);
        v221 = 0;
    }
    if (v220 == 153)
    {
        erase(ego);
        v44 = 18;
        edgeEgoHit = BOTTOM_EDGE;
        v220 = 0;
    }
    if (v220 == 202)
    {
        start.update(o4);
        end.of.loop(o4, f227);
    }
    if (v220 == 203)
    {
        set(f221);
        v225 = 2;
        set.view(o1, View80);
        set.loop(o1, 2);
        set.cel(o1, 0);
        set.priority(o1, 10);
        ignore.objs(o1);
        ignore.blocks(o1);
        position(o1, 74, 110);
        draw(o1);
        stop.cycling(o1);
        v222 = 4;
    }
    if (v220 == 204)
    {
        print.at("\"SCRAM!!\" growls Papa Bear. \"We're not interested!\"", 2, 4, 37);
        set.cel(o1, 0);
        v36 = 4;
        cycle.time(o1, v36);
        start.cycling(o1);
        sound(Sound12, f41);
        v222 = 6;
    }
    if (v220 == 205)
    {
        v36 = 1;
        cycle.time(o1, v36);
        set.view(o1, View80);
        set.loop(o1, 2);
        set.cel(o1, 0);
        stop.cycling(o1);
        set.view(ego, View11);
        set(f35);
        set.priority(ego, 15);
        ignore.blocks(ego);
        move.obj(ego, 86, 133, 3, f227);
        sound(Sound1, f41);
    }
    if (v220 == 206)
    {
        set.view(ego, View35);
        stop.motion(ego);
        v44 = 18;
        v224 = 5;
        set(f225);
        v222 = 3;
    }
    if (v220 == 207)
    {
        erase(o1);
        set(f223);
        v220 = 0;
        if (v221 == 150)
        {
            v225 = 1;
        }
        else
        {
            v225 = 0;
        }
    }
    if (v220 == 0 &&
        v44 != 18)
    {
        player.control();
        accept.input();
        start.motion(ego);
        reset(f46);
    }
}
if (isset(f45))
{
    --v224;
    if (v224 == 1)
    {
        player.control();
        accept.input();
        reset(f46);
        reset(f35);
        reset(f225);
        release.priority(ego);
        stop.sound();
        start.motion(ego);
        v44 = 0;
        set.view(ego, View0);
        observe.blocks(ego);
    }
}
if (isset(f225) &&
    v44 == 18)
{
    sound(Sound6, f225);
}
if (isset(f228) &&
    v225 > 0)
{
    sound(Sound34, f228);
}
call(Logic111);
if (isset(f226) &&
    isset(f221))
{
    new.room(Logic41);
}
if (edgeEgoHit == BOTTOM_EDGE)
{
    new.room(Logic13);
}
if (edgeEgoHit == TOP_EDGE)
{
    new.room(Logic23);
}
if (edgeEgoHit == LEFT_EDGE)
{
    new.room(Logic27);
}
if (edgeEgoHit == RIGHT_EDGE)
{
    new.room(Logic29);
}
return ();

[Messages
#message 1 "There are lovely flowers growing in this well-tended garden. Their sweet scent and beautiful colors delight you."
#message 2 "%m1 To your surprise, you see a bear, wearing a dress, working in the garden. It must be Mama Bear!"
#message 3 "You carefully peek into the pretty flowers of the flower garden. Drops of glistening dew have gathered within their soft petals."
#message 4 "This is the comfortable home of the Three Bears. A well-tended flower garden grows out front."
#message 5 "You peer through the window, but the inside is dimly lit and you cannot make out any details."
#message 6 "You need to move closer."
#message 7 "The heavy wooden door is closed."
#message 8 "You see three fully-clothed bears!"
#message 9 "You wouldn't want to spoil the lovely flower bed by picking one!"
#message 10 "Mama Bear growls at you as you near the flower bed. Better stay away from it... and HER!"
#message 11 "Oh, dear! You have annoyed Mama Bear by trampling her precious flowers."
#message 12 "\"AND STAY OUT!!!\""
#message 13 "Holding the silver thimble beneath a dew-filled flower, you gently tip the flower so its dew runs into the thimble. You move from flower to flower, repeating the process until your thimble is brimming with dew."
#message 14 "You must have a thimble in order to get a thimbleful of dew."
#message 15 "Your thimble is already full of dew."
#message 20 "What's this? Three clothed bears??\n\nYou hear Papa Bear exclaim, \"What a beautiful day for a stroll through the forest.\""
#message 21 "There are three fully-clothed bears coming!\n\nYou hear Mama Bear say, \"Thank you, Dear. That was a lovely walk.\""
#message 22 "Evidently, they don't hear you."
#message 23 "\"SCRAM!!\" growls Papa Bear. \"We're not interested!\""
#message 24 "He doesn't seem happy to see you."
#message 25 "The cottage is too dimly lit to make out any details."
#message 26 "You see a lone mountain peak in the distance. Dark clouds swirl around its summit."
#message 27 "The dew is beautiful."
#message 28 "Your cordial greeting annoys the bear, and she growls back, \"Grrrrrrrrrrrrreetings yourrrrrrrrrrself, young man. Stay out of my garden!\""
#message 29 "Again, you speak to the bear. \"Grrrrrrrrrrr!\" she growls menacingly. \"We don't take to strangers here. Go away!\""
#message 30 "Insistently, you talk to the bear yet again. She ignores you, but you hear a constant low growl from deep within her."
#message 31 "It is utterly impossible for you to catch a big bear."
#message 32 "How could you hurt a big bear? You couldn't."
#message 33 "A strange idea."
#message 34 "You rap lightly on the door of the charming house."
#message 35 "No reply."
#message 36 "You knock again, louder."
#message 37 "Again, there is no response."
#message 38 "Perhaps no one is home?"
#message 40 "Where?"

