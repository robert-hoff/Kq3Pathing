if (errorNumber > 0)
{
    call(Logic98);
}
if (isset(gameRestored))
{
    set(enableMenu);
    disable.item(c29);
}
if (currentRoom <= 0)
{
    if (!isset(gameRestarted))
    {
        script.size(127);
        set.menu("Sierra ");
        set.menu.item("About KQ3 ", c27);
        set.menu.item("Help  <F1>", c2);
        set.menu("File ");
        set.menu.item("Save     <F5>", c3);
        set.menu.item("Restore  <F7>", c5);
        set.menu.item("-------------", c29);
        set.menu.item("Restart  <F9>", c7);
        set.menu.item("-------------", c29);
        set.menu.item("Quit  <Alt-Z>", c1);
        set.menu("Action ");
        set.menu.item("Inventory  <TAB>", c10);
        set.menu.item("See Object  <F4>", c26);
        set.menu("Special ");
        set.menu.item("Sound On/Off       <F2>", c16);
        if (machineType == PC &&
            monitorType != MONO &&
            monitorType != EGA)
        {
            set.menu.item("Graphics Mode  <Ctrl-R>", c12);
        }
        if (machineType == ATARI)
        {
            set.menu.item("", c15);
        }
        else
        {
            set.menu.item("Joystick       <Ctrl-J>", c15);
        }
        set.menu.item("Clock On/Off           ", c25);
        set.menu.item("Pause Game             ", c18);
        if (machineType != AMIGA)
        {
            set.menu("Speed ");
            set.menu.item("Normal       ", c32);
            set.menu.item("Slow         ", c31);
            set.menu.item("Fast         ", c33);
            set.menu.item("Fastest      ", c34);
            set.menu.item("-------------", c29);
            set.menu.item("Change  <F10>", c4);
        }
        submit.menu();
    }
    call(Logic101);
    if (v70 > 0)
    {
        new.room.v(v70);
    }
    if (isset(gameRestarted))
    {
        new.room(Logic7);
    }
    new.room(Logic45);
}
if (isset(f126) &&
    (isset(f76) ||
    isset(newRoom)))
{
    reset(f76);
    set.text.attribute(BLACK, WHITE);
    display(0, 20, "%v117:%v116|2:%v115|2 ");
    set.text.attribute(WHITE, BLACK);
}
if (isset(newRoom))
{
    call(Logic100);
    if (isset(f31))
    {
        load.logics(Logic99);
        load.logics(Logic96);
        set(enableTrace);
    }
    call.v(currentRoom);
    if (v44 == 30)
    {
        v44 = 0;
    }
    if (!isset(f48) &&
        !isset(f47) &&
        v44 != 26 &&
        v44 != 25)
    {
        position.v(ego, v57, v58);
    }
    if (v44 == 14)
    {
        v44 = 0;
        v90 = 2;
        load.view(View0);
        set.view(ego, View0);
        set(f47);
    }
    if (!isset(f47))
    {
        draw(ego);
    }
}
get.posn(ego, v40, v41);
reset(f40);
if (isset(f37))
{
    reset(egoHitSpecial);
}
if (isset(f38))
{
    reset(onWater);
}
if (isset(f80))
{
    edgeEgoHit = NOT_HIT;
}
if (controller(c35))
{
    menu.input();
}
if (controller(c6))
{
    set(f40);
}
if (controller(c22))
{
    set(f40);
}
if (controller(c18))
{
    pause();
}
if (controller(c9))
{
    echo.line();
}
if (controller(c17))
{
    cancel.line();
}
if (controller(c15))
{
    init.joy();
}
if (machineType == TANDY)
{
    if (attenuation < 15 &&
        controller(c39))
    {
        ++attenuation;
    }
    if (controller(c38))
    {
        --attenuation;
    }
}
if ((said("restart", "game") ||
    said("restart") ||
    said("begin", "above") ||
    controller(c7)))
{
    restart.game();
}
if ((said("restore", "game") ||
    said("restore") ||
    controller(c5)))
{
    restore.game();
}
if ((controller(c1) ||
    said("quit")))
{
    if (isset(f31))
    {
        quit(1);
    }
    else
    {
        quit(0);
    }
}
if (controller(c27))
{
    if (v118 > 0)
    {
        print("%m91%v118 days, %v117 hours, %v116 minutes and %v115 seconds.\n");
    }
    else
    {
        if (v117 > 0)
        {
            print("%m91%v117 hours, %v116 minutes and %v115 seconds.\n");
        }
        else
        {
            print("%m91%v116 minutes and %v115 seconds.\n");
        }
    }
}
if (controller(c25))
{
    toggle(f126);
    if (isset(f126))
    {
        set(f76);
    }
    else
    {
        status.line.off();
        status.line.on();
    }
}
if (v44 != 20 &&
    (said("save", "game") ||
    said("save") ||
    controller(c3)))
{
    save.game();
}

if (controller(c26))
{
    set(enableItemSelect);
    status();
    set(f76);
    if (selectedItem > 0 && selectedItem != 255)
    {
        // this is the magic map
        if (selectedItem == 54)
        {
            v71 = 1;
        }
        else
        {
            v36 = selectedItem;
            v36 += 100;
            show.obj.v(v36);
        }
        reset(enableItemSelect);
    }
}


if (controller(c16))
{
    toggle(soundOn);
    set(f76);
}
if ((said("examine", "status") ||
    said("status") ||
    said("all") ||
    controller(c10)))
{
    status();
    set(f76);
}

if (controller(c14) || said("mice", "ass"))
{
    toggle(f31);
    if (!isset(f31))
    {
        reset(enableTrace);
    }
    else
    {
        load.logics(Logic99);
        load.logics(Logic96);
        set(enableTrace);
        set(f50);
        print("\n     King's Quest III\n\n  Version 2.14  3/15/88   \n\n");
        version();
        accept.input();
        player.control();
    }
}
if (controller(c20))
{
    print("\n     King's Quest III\n\n  Version 2.14  3/15/88   \n\n");
    version();
}
if ((controller(c2) ||
    said("help") ||
    said("help", "alexander")))
{
    if (isset(f43))
    {
        print("The help screen won't work here. Try again elsewhere.");
    }
    else
    {
        call(Logic102);
    }
}
if (controller(c12))
{
    toggle.monitor();
}
reset(f125);
if (controller(c4))
{
    set(f125);
    ++animationInterval;
    if (animationInterval > 3)
    {
        animationInterval = 0;
    }
}
if ((controller(c31) ||
    said("slow")))
{
    set(f125);
    animationInterval = 3;
}
if ((controller(c32) ||
    said("normal")))
{
    set(f125);
    animationInterval = 2;
}
if ((controller(c33) ||
    said("fast")))
{
    set(f125);
    animationInterval = 1;
}
if ((controller(c34) ||
    said("fastest")))
{
    set(f125);
    animationInterval = 0;
}
if (isset(f125))
{
    reset(f125);
    if (monitorType != MONO)
    {
        v36 = 114;
        v36 += animationInterval;
        clear.lines(24, 24, BLACK);
        v38 = 24;
        v37 = 0;
        display.v(v38, v37, v36);
        v119 = 6;
    }
}

if (isset(f44))
{
    reset(f44);
    disable.item(c3);
    v44 = 20;
    load.sound(Sound25);
    stop.motion(ego);
    accept.input();
    v48 = 44;
}

if (v44 == 20)
{
    --v48;
    if (v48 == 1)
    {
        stop.sound();
        sound(Sound25, f41);
        print("Thanks for playing King's Quest III... next time, be more careful!");
    }
    if (isset(haveInput) &&
        !isset(haveMatch))
    {
        print("Since you're dead...\n\nall you can do is restore a saved game or "
                "start over.");
    }
    if (isset(f31))
    {
        call(Logic99);
    }
    return ();
}
if (egoDir == v82 &&
    v40 == v42 &&
    v41 == v43)
{
    stop.cycling(ego);
}
else
{
    start.cycling(ego);
}
if ((egoDir <= STOPPED ||
    isset(f36)))
{
    stop.cycling(ego);
}
if (isset(f35))
{
    start.cycling(ego);
}

if (elapsedSeconds != v120)
{
    v120 = elapsedSeconds;
    set(f45);
    set(f76);
    ++v47;
    --v83;
    --v109;
    --v111;
    --v54;
    --v107;
    --v52;
    --v75;
    --v119;
    if (currentRoom != 74)
    {
        ++v115;
    }
    if (v115 == 60)
    {
        v115 = 0;
        ++v116;
        if (v116 == 60)
        {
            v116 = 0;
            ++v117;
            if (v117 == 25)
            {
                v117 = 0;
                ++v118;
            }
        }
    }

    if (v119 == 1)
    {
        clear.lines(24, 24, BLACK);
    }

    if (v84 > 0 && v83 <= 0)
    {
        --v84;
        v83 = 60;
    }

    if (v110 > 0 && v109 <= 0)
    {
        --v110;
        v109 = 60;
    }

    if (v112 > 0 && v111 <= 0)
    {
        --v112;
        v111 = 60;
    }

    if (v111 == 1 && v112 <= 0)
    {
        if (v44 != 27)
        {
            set(f123);
        }
        else
        {
            reset(f46);
            v44 = 0;
            v90 = 3;
            v91 = v44;
        }
    }

    if (v55 > 0 && v54 <= 0)
    {
        --v55;
        v54 = 60;
    }

    if (v54 == 1 && v55 <= 0)
    {
        set(f127);
        if ((v44 == 26 ||
            v44 == 25))
        {
            v71 = 5;
        }
        if (isset(f49))
        {
            v71 = 6;
        }
        if (v44 != 126 && v44 != 125)
        {
            print("Your magic spell is wearing off!");
            set(f80);
        }
    }

    if (v108 > 0 && v107 <= 0)
    {
        --v108;
        v107 = 60;
    }

    if (v53 > 0 && v52 <= 0)
    {
        --v53;
        v52 = 60;
    }

    if (v52 == 1 && v53 <= 0)
    {
        ++v62;
        if (v62 == 2)
        {
            v53 = 14;
        }
        if (v62 == 3)
        {
            set(f77);
            v53 = 3;
        }
        if (v62 == 4)
        {
            set(f77);
            v53 = 3;
        }
    }



    if (v76 > 0 && v75 <= 0)
    {
        --v76;
        v75 = 60;
    }
    if (v75 == 1 && v76 <= 0)
    {
        v71 = 10;
    }
}
if (!isset(haveInput))
{
    goto(Label1);
}
if (unknownWordNum > 0)
{
    reset(haveInput);
    set(haveMatch);
    print.v(unknownWordNum);
}
if (said("who", "programmed", "game"))
{
    print("Al Lowe & Bob Heitman.");
}
if (said("thank", "rol"))
{
    print("\"You're welcome.\"");
}
if ((said("bye", "anyword") ||
    said("anyword", "bye")))
{
    print("\"'Bye.\"");
}
if (said("hello", "rol"))
{
    print("\"Hi.\"");
}
if ((said("ass", "rol") ||
    said("anyword", "ass", "rol") ||
    said("anyword", "anyword", "ass", "rol") ||
    said("anyword", "anyword", "anyword", "ass", "rol")))
{
    print("Obviously, you were raised by a naughty wizard!");
}
if ((said("how", "length", "game") ||
    said("how", "length", "play", "game") ||
    said("how", "length", "play") ||
    said("length", "game") ||
    said("game", "length") ||
    said("game", "time")))
{
    if (elapsedDays > 0)
    {
        print("%v118 days, %m18");
    }
    else
    {
        if (elapsedHours > 0)
        {
            print("%v117 hours, %m19");
        }
        else
        {
            print("%v116 minutes and %v115 seconds.");
        }
    }
}
if (said("anyword", "clock", "rol") || said("clock", "rol"))
{
    toggle(f126);
    if (isset(f126))
    {
        set(f76);
    }
    else
    {
        status.line.off();
        status.line.on();
    }
}


if (has("Cat Cookie*"))
{
    if ((said("feed", "cat", "cookie", "rol") ||
        said("feed", "cookie", "rol")))
    {
        print("They don't want it.");
    }
    if (has("Porridge") &&
        (said("add", "cat", "cookie", "porridge") ||
        said("add", "cookie", "porridge") ||
        said("add", "cat", "cookie", "basin", "porridge") ||
        said("add", "cookie", "basin", "porridge") ||
        said("crumble", "cat", "cookie", "porridge") ||
        said("crumble", "cookie", "porridge") ||
        said("crumble", "cat", "cookie", "basin", "porridge") ||
        said("crumble", "cookie", "basin", "porridge")))
    {
        drop("Cat Cookie*");
        drop("Porridge");
        get("Poisoned Porridge");
        print("The porridge conceals the crumbled cookie; it still looks as "
                "appetizing as ever.");
    }
}
if (v44 == 27)
{
    print("Ick! You're slimy!");
    set(haveMatch);
}

if (v71 == 11 && said("sleep", "henceforth"))
{
    v71 = 12;
}
if (v71 == 11)
{
    v71 = 0;
}

if (said("drain", "sleep", "flour", "on", "deck"))
{
    if (has("Sleep Powder*"))
    {
        v71 = 11;
        print("Ok.");
        drop("Sleep Powder*");
    }
    else
    {
        print("How can you do that?");
    }
}


if (said("pat", "magic", "rock") || said("pat", "rock") || said("pat", "amber", "rock"))
{
    if (has("Magic Stone*"))
    {
        v71 = 2;
    }
    else
    {
        print("How can you do that?");
    }
}

if (v44 == 26)
{
    if (said("eagle", "begone", "alexander", "add"))
    {
        v71 = 5;
    }
    else
    {
        print("Shhhh. (You're flying!)");
        set(haveMatch);
    }
}
if ((said("add", "eagle", "feather", "essence") ||
    said("add", "eagle", "feather", "magic", "essence")))
{
    if (has("Magic Rose Essence*") &&
        has("Eagle Feather*"))
    {
        v71 = 4;
    }
    else
    {
        print("How can you do that?");
    }
}
if (v44 == 25)
{
    if (said("bug", "begone", "alexander", "add"))
    {
        v71 = 5;
    }
    else
    {
        print("Buzzzzzz.");
        set(haveMatch);
    }
}
if ((said("add", "bug", "essence") ||
    said("add", "bug", "magic", "essence")))
{
    if (has("Magic Rose Essence*") &&
        has("Fly Wings*"))
    {
        v71 = 3;
    }
    else
    {
        print("How can you do that?");
    }
}
if ((said("examine", "magic", "map") ||
    said("examine", "map")))
{
    if (has("Magic Map*"))
    {
        v71 = 1;
    }
    else
    {
        print("How can you do that?");
    }
}
if (isset(f49) &&
    (said("clean", "ointment", "off") ||
    said("clean", "off", "ointment")))
{
    v71 = 6;
}
if ((said("pat", "ointment", "on", "alexander") ||
    said("pat", "ointment", "on") ||
    said("pat", "on", "ointment") ||
    said("pat", "ointment", "on", "body")))
{
    if (has("Invisibility Ointment*"))
    {
        v71 = 7;
    }
    else
    {
        print("How can you do that?");
    }
}
if (v71 == 8 &&
    said("brew", "storm", "butter churn", "up"))
{
    v71 = 9;
}
if (v71 == 8)
{
    v71 = 0;
}
if (said("knead", "brew", "try", "finger"))
{
    if (has("Storm Brew*"))
    {
        v71 = 8;
        print("Ok.");
    }
    else
    {
        print("How can you do that?");
    }
}
if ((v76 > 0 ||
    v75 > 0) &&
    said("brew", "storm", "clear", "up"))
{
    v71 = 10;
}
if (has("Nightshade Juice*") &&
    (said("drink", "juice") ||
    said("drink", "night shade", "juice") ||
    said("drink", "night shade") ||
    said("drink", "juice", "bottle") ||
    said("drink", "night shade", "juice", "bottle") ||
    said("drink", "juice", "from", "bottle") ||
    said("drink", "night shade", "juice", "from", "bottle")))
{
    drop("Nightshade Juice*");
    v94 = 36;
}
if (has("Mandrake Root*") &&
    (said("drink", "mandrake", "flour") ||
    said("drink", "mandrake", "root", "flour") ||
    said("drink", "root") ||
    said("drink", "mandrake", "flour", "from", "bottle") ||
    said("drink", "mandrake") ||
    said("drink", "mandrake", "root") ||
    said("drink", "mandrake", "root", "flour", "from", "bottle")))
{
    drop("Mandrake Root*");
    v94 = 38;
}


if (has("Toadstool Powder*") &&
    (said("drink", "mushroom") ||
    said("drink", "mushroom", "flour") ||
    said("drink", "mushroom", "flour", "from", "bottle")))
{
    drop("Toadstool Powder*");
    v94 = 39;
}
if (has("Poisoned Porridge") &&
    has("Spoon") &&
    (said("drink", "porridge", "try", "ladle") ||
    said("drink", "porridge", "ladle") ||
    said("try", "ladle", "drink", "porridge")))
{
    drop("Poisoned Porridge");
    v94 = 37;
}
if (has("Poisoned Porridge") &&
    said("drink", "porridge"))
{
    drop("Poisoned Porridge");
    v94 = 37;
}
if (has("Cat Cookie*") &&
    (said("drink", "cat", "cookie") ||
    said("drink", "cookie")))
{
    set(f46);
    print("Ok.");
    v90 = 3;
    v44 = 204;
    v91 = 204;
}
if ((has("Chicken Feather*") ||
    has("Eagle Feather*")) &&
    said("examine", "feather"))
{
    if (has("Chicken Feather*"))
    {
        show.obj(View101);
    }
    if (has("Eagle Feather*"))
    {
        show.obj(View109);
    }
}
if (has("Chicken Feather*") &&
    said("examine", "bird", "feather"))
{
    show.obj(View101);
}
if ((has("Dog Hair*") ||
    has("Cat Hair*")) &&
    said("examine", "fur"))
{
    if (has("Cat Hair*"))
    {
        show.obj(View102);
    }
    if (has("Dog Hair*"))
    {
        show.obj(View103);
    }
}
if (has("Cat Hair*") &&
    said("examine", "cat", "fur"))
{
    show.obj(View102);
}
if (has("Dog Hair*") &&
    said("examine", "dog", "fur"))
{
    show.obj(View103);
}
if (has("Snakeskin*") &&
    said("examine", "reptile skin"))
{
    show.obj(View104);
}
if (has("Powdered Fish Bone*") &&
    said("examine", "bone"))
{
    show.obj(View105);
}
if (has("Thimble*") &&
    said("examine", "thimble"))
{
    show.obj(View106);
}
if (has("Thimble and Dew*") &&
    (said("examine", "dew") ||
    said("examine", "dew", "thimble") ||
    said("examine", "thimble", "dew") ||
    said("examine", "thimble")))
{
    show.obj(View107);
}
if (has("Dough in Ears") &&
    said("examine", "compound", "ball"))
{
    show.obj(View108);
}
if (has("Eagle Feather*") &&
    said("examine", "eagle", "feather"))
{
    show.obj(View109);
}
if (has("Fly Wings*") &&
    said("examine", "bug"))
{
    show.obj(View110);
}
if (has("Saffron*") &&
    said("examine", "saffron"))
{
    show.obj(View111);
}
if (has("Rose Essence*") &&
    said("examine", "essence"))
{
    show.obj(View112);
}
if (has("Magic Rose Essence*") &&
    (said("examine", "essence") ||
    said("examine", "magic", "essence")))
{
    show.obj(View139);
}
if (has("Salt*") &&
    said("examine", "grains of salt"))
{
    show.obj(View113);
}
if (has("Amber Stone*") &&
    said("examine", "amber", "rock"))
{
    show.obj(View114);
}
if (has("Magic Stone*") &&
    (said("examine", "magic", "rock") ||
    said("examine", "amber", "rock")))
{
    show.obj(View116);
}
if (has("Mistletoe*") &&
    said("examine", "mistletoe"))
{
    show.obj(View115);
}
if (has("Nightshade Juice*") &&
    (said("examine", "night shade", "juice") ||
    said("examine", "juice")))
{
    show.obj(View117);
}
if (has("Acorns*") &&
    said("examine", "acorn"))
{
    show.obj(View118);
}
if (has("Mandrake Root*") &&
    (said("examine", "mandrake", "root") ||
    said("examine", "mandrake", "root", "flour") ||
    said("examine", "mandrake")))
{
    show.obj(View121);
}
if (has("Fish Oil*") &&
    (said("examine", "fish", "fish oil") ||
    said("examine", "fish oil")))
{
    show.obj(View122);
}
if (has("Cat Cookie*") &&
    (said("examine", "cookie") ||
    said("examine", "cat", "cookie")))
{
    show.obj(View123);
}
if (has("Porridge") &&
    said("examine", "porridge"))
{
    show.obj(View124);
}
if (has("Poisoned Porridge") &&
    said("examine", "porridge"))
{
    show.obj(View125);
}
if (has("Poisoned Porridge") &&
    said("examine", "poison", "porridge"))
{
    show.obj(View125);
}
if (has("Ocean Water*") &&
    (said("examine", "cup") ||
    said("examine", "liquid") ||
    said("examine", "cup", "liquid") ||
    said("examine", "cup", "bay", "liquid") ||
    said("examine", "bay", "liquid")))
{
    show.obj(View126);
}
if (has("Mud*") &&
    (said("examine", "mud") ||
    said("examine", "ladle", "mud") ||
    said("examine", "ladle")))
{
    show.obj(View127);
}
if (has("Toadstool Powder*") &&
    (said("examine", "frog", "flour") ||
    said("examine", "mushroom", "flour")))
{
    show.obj(View128);
}

if (has("Empty Jar*") &&
    (said("examine", "bottle") ||
    said("examine", "bottle")))
{
    show.obj(View129);
}

if (has("Storm Brew*") &&
    said("examine", "brew"))
{
    show.obj(View130);
}
if (has("Toad Spittle*") &&
    (said("examine", "frog", "spit") ||
    said("examine", "spit")))
{
    show.obj(View131);
}
if (has("Lard*") &&
    said("examine", "lard"))
{
    show.obj(View132);
}
if (has("Knife") &&
    said("examine", "dagger"))
{
    show.obj(View133);
}
if (has("Cactus*") &&
    said("examine", "cactii"))
{
    show.obj(View134);
}
if (has("Invisibility Ointment*") &&
    said("examine", "ointment"))
{
    show.obj(View136);
}
if (has("Magic Wand*") &&
    (said("examine", "rod") ||
    said("examine", "magic", "rod")))
{
    show.obj(View137);
}
if (has("Brass Key*") &&
    said("examine", "key"))
{
    show.obj(View138);
}
if (has("Bowl") &&
    said("examine", "basin"))
{
    show.obj(View140);
}
if (has("Spoon") &&
    said("examine", "ladle"))
{
    show.obj(View141);
}
if (has("Mirror*") &&
    (said("examine", "looking glass") ||
    said("examine", "fingers", "looking glass")))
{
    show.obj(View143);
}
if (has("Purse and Gold Coins*") &&
    (said("examine", "coin purse", "rol") ||
    said("lift", "coin purse", "rol") ||
    said("look in", "coin purse") ||
    said("examine", "coin", "rol")))
{
    show.obj(View148);
}
if (has("Empty Purse*") &&
    (said("examine", "coin purse", "rol") ||
    said("lift", "coin purse", "rol") ||
    said("look in", "coin purse") ||
    said("examine", "drain", "coin purse", "rol")))
{
    show.obj(View147);
}
if (has("Empty Pouch*") &&
    (said("examine", "drain", "pouch") ||
    said("examine", "pouch")))
{
    show.obj(View119);
}
if (has("Sleep Powder*") &&
    (said("examine", "flour") ||
    said("examine", "pouch") ||
    said("examine", "bag") ||
    said("examine", "sleep", "flour")))
{
    show.obj(View120);
}
if (has("Bread") &&
    said("examine", "bread"))
{
    show.obj(View149);
}
if (has("Fruit") &&
    said("examine", "apple"))
{
    show.obj(View150);
}
if (has("Mutton") &&
    said("examine", "chop"))
{
    show.obj(View151);
}
if (has("Shovel") &&
    said("examine", "shovel"))
{
    show.obj(View152);
}
if (has("Treasure Chest") &&
    (said("examine", "chest") ||
    said("examine", "treasure") ||
    said("lift", "chest") ||
    said("lift", "treasure") ||
    said("lift", "cap", "chest") ||
    said("lift", "cap", "treasure")))
{
    show.obj(View153);
}
if (said("examine", "food"))
{
    if (has("Bread"))
    {
        show.obj(View149);
        reset(haveMatch);
    }
    if (has("Fruit"))
    {
        show.obj(View150);
        reset(haveMatch);
    }
    if (has("Porridge"))
    {
        show.obj(View124);
        reset(haveMatch);
    }
    if (has("Poisoned Porridge"))
    {
        show.obj(View125);
        reset(haveMatch);
    }
    if (has("Mutton"))
    {
        show.obj(View151);
        reset(haveMatch);
    }
    if (isset(haveMatch))
    {
        print("%m68.");
    }
}
if ((has("Ocean Water*") ||
    has("Empty Cup")) &&
    said("examine", "cup"))
{
    if (has("Ocean Water*"))
    {
        show.obj(View126);
    }
    if (has("Empty Cup"))
    {
        show.obj(View142);
    }
}
Label1:
if (v94 > 0 &&
    !isset(f46))
{
    set(f46);
    program.control();
    stop.motion(ego);
    prevent.input();
    load.view(View23);
    set.view(ego, View23);
    set.cel(ego, 0);
    v36 = 3;
    cycle.time(ego, v36);
    set(f35);
    end.of.loop(ego, f121);
}
if (isset(f121))
{
    reset(f121);
    stop.cycling(ego);
    print.v(v94);
    set(f44);
}
if (isset(f42) &&
    have.key())
{
    v118 = 0;
    v117 = 0;
    v116 = 0;
    v115 = 0;
    set(enableMenu);
    set(f126);
    status.line.on();
    currentRoom = 34;
    new.room(Logic7);
}
if (v44 == 26)
{
    if (edgeEgoHit <= NOT_HIT &&
        v41 < 20)
    {
        edgeEgoHit = TOP_EDGE;
    }
    if (v82 <= 0 &&
        egoDir > STOPPED)
    {
        if (egoDir == UP)
        {
            egoDir = UP_LEFT;
        }
        if (egoDir == DOWN)
        {
            egoDir = DOWN_LEFT;
        }
    }
    if ((v82 == 3 ||
        v82 == 2 ||
        v82 == 4))
    {
        if (egoDir == UP)
        {
            egoDir = UP_RIGHT;
        }
        if ((egoDir <= STOPPED ||
            egoDir == DOWN))
        {
            egoDir = DOWN_RIGHT;
        }
    }
    if ((v82 == 7 ||
        v82 == 8 ||
        v82 == 6))
    {
        if (egoDir == UP)
        {
            egoDir = UP_LEFT;
        }
        if ((egoDir <= STOPPED ||
            egoDir == DOWN))
        {
            egoDir = DOWN_LEFT;
        }
    }
    if ((egoDir == DOWN_LEFT ||
        egoDir == DOWN_RIGHT))
    {
        if (egoDir == DOWN_LEFT)
        {
            set.loop(ego, 1);
        }
        if (egoDir == DOWN_RIGHT)
        {
            set.loop(ego, 0);
        }
        stop.cycling(ego);
        reset(f35);
        set.cel(ego, 2);
    }
    else
    {
        start.cycling(ego);
        set(f35);
    }
}
if (isset(f33))
{
    erase(o14);
    reset(f80);
    if (v44 == 14)
    {
        if (v135 > 0)
        {
            new.room.v(v135);
        }
        else
        {
            v44 = 0;
        }
    }
    if ((v44 == 25 ||
        v44 == 26))
    {
        set(f46);
        set(f37);
        set(f38);
        ignore.horizon(ego);
        v55 = 2;
        set.priority(ego, 15);
        if (v44 == 26)
        {
            v59 = 2;
            v60 = 2;
            v61 = 2;
            start.motion(ego);
        }
        else
        {
            set(f35);
            v59 = 1;
            v60 = 1;
            v61 = 1;
        }
    }
    if (v44 == 0)
    {
        normal.motion(ego);
        start.motion(ego);
        observe.blocks(ego);
        observe.objs(ego);
        observe.horizon(ego);
        release.priority(ego);
        reset(f35);
        reset(f36);
        reset(f37);
        reset(f38);
        v61 = 1;
        v60 = 1;
        v59 = 1;
        reset(f46);
    }
    if (v44 == 204)
    {
        print("You purr contentedly, enjoying your new life as a cat!");
        v36 = 3;
        cycle.time(ego, v36);
        start.cycling(ego);
        set(f44);
    }
    else
    {
        player.control();
        accept.input();
        cycle.time(ego, v59);
        step.time(ego, v60);
        step.size(ego, v61);
    }
}
if (v47 > 7 &&
    v128 != 20 &&
    v31 > 0 &&
    !isset(f109) &&
    currentEgoView == 0 &&
    !isset(f46))
{
    if (v123 <= 0)
    {
        if (v84 <= 0 &&
            v83 <= 0)
        {
            v123 = v127;
        }
        if ((v127 == 1 ||
            v127 == 3))
        {
            if (v137 > 0)
            {
                v123 = 0;
                if (v110 <= 0 &&
                    v109 <= 0)
                {
                    v123 = 8;
                }
            }
            if (v95 > 0)
            {
                v123 = 26;
            }
            v36 = 5;
            if (!obj.in.room("Magic Wand*", v36))
{
                v123 = 24;
            }
            if (currentRoom > 8 &&
                currentRoom < 87)
            {
                v123 = 20;
            }
        }
    }
    if (v123 > 0)
    {
        load.logics(Logic106);
        call(Logic106);
    }
}
if (v31 > 0 &&
    v128 != 20 &&
    isset(f130))
{
    reset(f130);
    edgeEgoHit = NOT_HIT;
    v44 = 0;
    currentEgoView = 0;
    load.logics(Logic106);
    call(Logic106);
}
get.posn(ego, v40, v41);
current.view(ego, currentEgoView);
if (isset(f109))
{
    call(Logic106);
}
if (!isset(newRoom))
{
    call.v(currentRoom);
}
if (isset(f31))
{
    call(Logic99);
}
if ((v44 == 25 ||
    v44 == 26 ||
    v44 == 125 ||
    v44 == 126))
{
    set(f46);
    set.priority(ego, 15);
    set(f37);
    set(f38);
    ignore.blocks(ego);
    ignore.horizon(ego);
    ignore.objs(ego);
    if ((v44 == 25 ||
        v44 == 125))
    {
        set.view(ego, View25);
        set(f35);
        start.cycling(ego);
    }
    if ((v44 == 26 ||
        v44 == 126))
    {
        set.view(ego, View26);
    }
}

if (v71 == 12)
{
    v71 = 0;
    print("Ok, but this place does not meet the spell's requirements.");
}
if (v71 == 9)
{
    v71 = 0;
    if (isset(f46))
    {
        print("You can't do that now.");
    }
    else
    {
        set(f46);
        v76 = 2;
        if (v56 == 7)
        {
            new.room(Logic70);
        }
        else
        {
            if (isset(f34))
            {
                program.control();
                prevent.input();
                stop.motion(ego);
                load.view(View39);
                set.view(ego, View39);
                set.loop(ego, 1);
                force.update(ego);
                print.at("Perhaps your magic would be more effective outside.", 2, 2, 37);
                start.cycling(ego);
                set(f35);
                set(f44);
            }
            else
            {
                v73 = v40;
                v74 = v41;
                new.room(Logic87);
            }
        }
    }
}
if (v71 == 10)
{
    if ((currentEgoView != 0 ||
        v44 != 0))
    {
        v75 = 4;
    }
    else
    {
        reset(f46);
        v71 = 0;
        v76 = 0;
        v75 = 0;
    }
}
if (v71 == 1)
{
    v71 = 0;
    if ((isset(f46) ||
        v44 == 11 ||
        isset(f81)))
    {
        print("You can't do that now.");
    }
    else
    {
        v73 = v40;
        v74 = v41;
        new.room(Logic89);
    }
}
if (v71 == 3)
{
    v71 = 0;
    if (isset(f46))
    {
        print("You can't do that now.");
    }
    else
    {
        v44 = 25;
        v90 = 3;
        v91 = 25;
        release.priority(ego);
        print("Ok.");
    }
}
if (v71 == 4)
{
    v71 = 0;
    if (isset(f46))
    {
        print("You can't do that now.");
    }
    else
    {
        if (isset(f34))
        {
            print("There's not enough room to fly in here.");
        }
        else
        {
            v44 = 26;
            v90 = 3;
            v91 = 26;
            set.priority(ego, 14);
            set(f37);
            set(f38);
            print("Ok.");
        }
    }
}
if (v71 == 5)
{
    v71 = 0;
    v55 = 0;
    v54 = 0;
    prevent.input();
    set.priority(ego, 15);
    move.obj.v(ego, v57, v58, v61, f97);
    if (v44 == 26)
    {
        v44 = 126;
        if (!isset(f127))
        {
            print("The urge to fly and soar has left%m110");
        }
    }
    if (v44 == 25)
    {
        v44 = 125;
        if (!isset(f127))
        {
            print("The impulse to buzz around has vanished. You feel yourself growing "



                    "bigger%m110");
        }
    }
}
if (isset(f97))
{
    reset(f97);
    v55 = 0;
    v54 = 0;
    ++v93;
    if (v93 > 2)
    {
        drop("Magic Rose Essence*");
        print("Your magic essence is all gone.");
    }
    v90 = 3;
    v91 = 0;
    v44 = 0;
    reset(f35);
}
if (v71 == 7)
{
    v71 = 0;
    if ((isset(f46) ||
        v44 != 0))
    {
        print("You can't do that now.");
    }
    else
    {
        if (currentRoom != 65 &&
            currentRoom != 67)
        {
            drop("Invisibility Ointment*");
            print("Ok, but this place does not meet the spell's requirements.");
        }
        else
        {
            set(f49);
            drop("Invisibility Ointment*");
            v90 = 3;
            v91 = 28;
            release.priority(ego);
            print("Ok.");
        }
    }
}
if (v71 == 6)
{
    v71 = 0;
    v44 = 0;
    reset(f49);
    v90 = 3;
    v91 = 0;
    v55 = 0;
    v54 = 0;
    if (!isset(f127))
    {
        print("Ok.");
    }
}
if (v71 == 2)
{
    v71 = 0;
    if (isset(f46))
    {
        print("You can't do that now.");
    }
    else
    {
        if (v56 == 2)
        {
            random(11, 32, v135);
        }
        if (v56 == 4)
        {
            random(48, 57, v135);
        }
        if (v56 == 5)
        {
            random(61, 67, v135);
        }
        if (v56 == 6)
        {
Label2:
            random(68, 72, v135);
            if (v135 == 70)
            {
                goto(Label2);
            }
        }
        if (v56 == 1)
        {
            random(1, 11, v135);
            if (v135 == 11)
            {
                v135 = 34;
            }
        }
        if (v56 == 7)
        {
            random(78, 87, v135);
            if (v135 == 87)
            {
                v135 = 31;
            }
        }
        if (v135 > 0)
        {
            v44 = 14;
            v90 = 1;
        }
        else
        {
            print("The stone won't work here.");
        }
    }
}
if (v90 > 0)
{
    set(f46);
    load.view(View199);
    load.sound(Sound2);
    set(f80);
    if (v90 == 3)
    {
        load.view.v(v91);
    }
    stop.motion(ego);
    program.control();
    prevent.input();
    animate.obj(o14);
    set.view(o14, View199);
    set.priority(o14, 15);
    ignore.objs(o14);
    v37 = v40;
    if (v37 > 3)
    {
        v37 -= 4;
    }
    position.v(o14, v37, v41);
    set.cel(o14, 0);
    draw(o14);
    v36 = 3;
    cycle.time(o14, v36);
    end.of.loop(o14, f33);
    sound(Sound2, f41);
    set.scan.start();
    current.cel(o14, v36);
    if (v36 != 3)
    {
        return ();
    }
    else
    {
        release.loop(ego);
        if (v90 == 2)
        {
            draw(ego);
            reset(f114);
        }
        if (v90 == 1)
        {
            erase(ego);
            set(f114);
        }
        if (v90 == 3)
        {
            set.view.v(ego, v91);
        }
        reset.scan.start();
    }
    v90 = 0;
}
if (isset(f49))
{
    current.view(ego, v67);
    if (v67 != 28)
    {
        v55 = 0;
        v54 = 0;
        reset(f49);
        print("You've broken the spell of invisibility.");
    }
}
if ((isset(haveMatch) ||
    !isset(haveInput) ||
    currentRoom == 43 ||
    v44 == 7 ||
    v44 == 18 ||
    v44 == 20))
{
    goto(Label3);
}
if ((has("Porridge") ||
    has("Poisoned Porridge")) &&
    said("feed", "porridge", "rol"))
{
    print("They're not hungry.");
}
if (has("Saffron*") &&
    said("drink", "saffron"))
{
    print("%m9 It tastes bitter!");
}
if (has("Invisibility Ointment*") &&
    said("drink", "ointment"))
{
    print("%m9 It tastes terrible!");
}
if (has("Sleep Powder*") &&
    said("drink", "sleep", "flour"))
{
    print("%m78 You spit it out, spilling the rest on the ground.");
    drop("Sleep Powder*");
}
if (has("Bread") &&
    said("drink", "bread"))
{
    print("Ok.");
    drop("Bread");
}
if (has("Fruit") &&
    said("drink", "apple"))
{
    print("Ok.");
    drop("Fruit");
}
if (has("Mutton") &&
    said("drink", "chop"))
{
    print("Ok.");
    drop("Mutton");
}
if (has("Porridge") &&
    said("drink", "porridge"))
{
    print("Ok.");
    drop("Porridge");
}
if (has("Mistletoe*") &&
    said("drink", "mistletoe"))
{
    print("%m9 It tastes terrible!");
    drop("Mistletoe*");
}
if (has("Acorns*") &&
    said("drink", "acorn"))
{
    print("%m9 It tastes terrible!");
    drop("Acorns*");
}
if (has("Salt*") &&
    said("drink", "grains of salt"))
{
    print("You eat a few grains of salt.");
}

if (has("Powdered Fish Bone*") && said("drink", "bone", "rol"))
{
    print("%m9 It tastes terrible!");
}


if (has("Cactus*") &&
    has("Knife") &&
    (said("try", "dagger", "carve", "cactii") ||
    said("carve", "cactii", "rol")))
{
    print("You don't need to... now.");
}
if (has("Bread") &&
    has("Knife") &&
    (said("try", "dagger", "carve", "bread") ||
    said("carve", "bread", "rol")))
{
    print("%m55bread without slicing it.");
}
if (has("Fruit") &&
    has("Knife") &&
    (said("try", "dagger", "carve", "apple") ||
    said("carve", "apple", "rol")))
{
    print("%m55fruit without cutting it.");
}
if (has("Mutton") &&
    has("Knife") &&
    (said("try", "dagger", "carve", "chop") ||
    said("carve", "chop", "rol")))
{
    print("%m55mutton without carving it.");
}
if (has("Lard*") &&
    said("drink", "lard"))
{
    print("%m9 It tastes terrible!");
}

if (has("Toad Spittle*") &&
    said("drink", "frog", "spit"))
{
    print("The thought turns your stomach!");
}

if (has("Rose Essence*") &&
    said("drink", "essence"))
{
    print("%m9 You decide it smells better than it tastes!");
    drop("Rose Essence*");
}

if (has("Magic Rose Essence*") &&
    (said("drink", "essence") ||
    said("drink", "magic", "essence")))
{
    print("%m9 You decide it smells better than it tastes!");
    drop("Magic Rose Essence*");
}
if ((has("Ocean Water*") ||
    has("Empty Cup")) &&
    (said("drink", "out", "cup") ||
    said("drink", "cup") ||
    said("drink", "anyword", "cup")))
{
    if (has("Empty Cup"))
    {
        print("Your cup is empty.");
    }
    if (has("Ocean Water*"))
    {
        print("%m9 It tastes terrible!");
        drop("Ocean Water*");
        get("Empty Cup");
    }
}

if (has("Ocean Water*") && (said("drink", "bay", "liquid") || said("drink", "liquid")))
{
    print("%m9 It tastes terrible!");
    drop("Ocean Water*");
    get("Empty Cup");
}

if (has("Fish Oil*") && said("drink", "fish", "fish oil"))
{
    print("%m9 It tastes terrible!");
    drop("Fish Oil*");
}


if (has("Thimble and Dew*") &&
    (said("drink", "dew") ||
    said("drink", "dew", "thimble") ||
    said("drink", "thimble", "dew")))
{
    print("%m9 Ummmm, not bad.");
    drop("Thimble and Dew*");
    get("Thimble*");
}
if ((has("Eagle Feather*") ||
    has("Chicken Feather*")) &&
    said("try", "feather"))
{
    print("%m53?");
}
if (has("Chicken Feather*") &&
    said("try", "bird", "feather"))
{
    print("%m53 %w3?");
}
if ((has("Cat Hair*") ||
    has("Dog Hair*")) &&
    said("try", "fur"))
{
    print("%m53?");
}
if (has("Cat Hair*") &&
    said("try", "cat", "fur"))
{
    print("%m53 %w3?");
}
if (has("Dog Hair*") &&
    said("try", "dog", "fur"))
{
    print("%m53 %w3?");
}
if (has("Snakeskin*") &&
    said("try", "reptile", "reptile skin"))
{
    print("%m53 %w3?");
}
if (has("Powdered Fish Bone*") &&
    said("try", "bone"))
{
    print("%m53 %w3?");
}
if (has("Thimble*") &&
    said("try", "thimble"))
{
    print("%m53?");
}
if (has("Thimble and Dew*") &&
    (said("try", "dew") ||
    said("try", "thimble")))
{
    print("%m53?");
}
if (has("Eagle Feather*") &&
    said("try", "eagle", "feather"))
{
    print("%m53 %w3?");
}
if (has("Fly Wings*") &&
    said("try", "bug"))
{
    print("%m53?");
}
if (has("Saffron*") &&
    said("try", "saffron"))
{
    print("%m53?");
}
if (has("Salt*") &&
    said("try", "grains of salt"))
{
    print("%m53?");
}
if (has("Mistletoe*") &&
    said("try", "mistletoe"))
{
    print("%m53?");
}
if (has("Nightshade Juice*"))
{
    if (said("try", "night shade", "juice"))
    {
        print("%m53 %w3?");
    }
    else
    {
        if (said("try", "juice"))
        {
            print("%m53?");
        }
    }
}
if (has("Acorns*") &&
    said("try", "acorn"))
{
    print("%m53?");
}
if (has("Empty Pouch*"))
{
    if (said("try", "drain", "pouch"))
    {
        print("%m53 %w3?");
    }
    else
    {
        if (said("try", "pouch"))
        {
            print("%m53?");
        }
    }
}
if (has("Mandrake Root*"))
{
    if (said("try", "mandrake", "root"))
    {
        print("%m53 %w3?");
    }
    else
    {
        if (said("try", "root"))
        {
            print("%m53?");
        }
    }
}

if (has("Fish Oil*") &&
    said("try", "fish", "fish oil"))
{
    print("%m53 %w3?");
}

if (has("Cat Cookie*"))
{
    if (said("try", "cookie"))
    {
        print("%m53?");
    }
    else
    {
        if (said("try", "cat", "cookie"))
        {
            print("%m53 %w3?");
        }
    }
}
if (has("Ocean Water*"))
{
    if (said("try", "bay", "liquid"))
    {
        print("%m53 %w3?");
    }
    else
    {
        if (said("try", "liquid"))
        {
            print("%m53?");
        }
    }
}
if (has("Mud*") &&
    (said("try", "mud") ||
    said("try", "ladle")))
{
    print("%m53?");
}

if (has("Toadstool Powder*") &&
    said("try", "mushroom", "flour"))
{
    print("%m53 %w3?");
}

if (has("Empty Jar*") &&
    said("try", "bottle"))
{
    print("%m53?");
}

if (has("Toad Spittle*"))
{
    if (said("try", "frog", "spit"))
    {
        print("%m53 %w3?");
    }
    else
    {
        if (said("try", "spit"))
        {
            print("%m53?");
        }
    }
}


if (has("Lard*") && said("try", "lard"))
{
    print("%m53?");
}

if (has("Knife") && said("try", "dagger"))
{
    print("%m53?");
}

if (has("Cactus*") && said("try", "cactii"))
{
    print("%m53?");
}

if (has("Magic Wand*") &&
    (said("try", "magic", "rod") ||
    said("try", "rod") ||
    said("aim", "magic", "rod") ||
    said("aim", "rod")))
{
    print("%m9 Nothing happens.");
}

if (has("Brass Key*") && said("try", "key"))
{
    print("Nothing here fits your key.");
}

if (has("Bowl") && said("try", "basin"))
{
    print("%m53?");
}
if (has("Spoon") && said("try", "ladle"))
{
    print("%m53?");
}
if (has("Empty Cup") &&
    said("try", "cup"))
{
    print("%m53?");
}
if (has("Mirror*") &&
    (said("try", "looking glass") ||
    said("try", "fingers", "looking glass")))
{
    print("You look cute.");
}
if ((has("Purse and Gold Coins*") ||
    has("Empty Purse*")) &&
    said("try", "coin purse"))
{
    print("%m53?");
}
if (has("Bread") &&
    said("try", "bread"))
{
    print("%m53?");
}
if (has("Fruit") &&
    said("try", "apple"))
{
    print("%m53?");
}
if (has("Mutton") &&
    said("try", "chop"))
{
    print("%m53?");
}
if (has("Shovel") &&
    said("try", "shovel"))
{
    print("%m53?");
}
if (has("Treasure Chest") &&
    said("try", "chest"))
{
    print("%m53?");
}
if ((has("Poisoned Porridge") ||
    has("Porridge")) &&
    said("try", "porridge"))
{
    print("%m53?");
}
if (has("Dough in Ears") &&
    (said("capture", "compound", "from", "ears") ||
    said("drain", "compound", "from", "ears") ||
    said("drain", "compound", "ears")))
{
    drop("Dough in Ears");
    print("As you remove the dough from your ears, it crumbles into dust and is lost!");
}
if (has("Amber Stone*") &&
    said("throw", "amber", "rock", "rol"))
{
    print("You missed!");
    drop("Amber Stone*");
}
if (has("Purse and Gold Coins*"))
{
    if ((said("count", "coin") ||
        said("count", "coin", "coin purse") ||
        said("count", "coin", "coin")))
    {
        print("You have %v63 gold coins.");
    }
    if ((said("buy", "rol") ||
        said("buy", "anyword", "coin")))
    {
        print("You can't buy that here.");
    }
}
if (has("Bowl") &&
    (said("add", "anyword", "basin")))
{
    print("You don't need to put the %w2 in the bowl.");
}

if (has("Empty Jar*") &&
    (said("look in", "bottle") ||
    said("lift", "bottle") ||
    said("capture", "cap", "off", "bottle")))
{
    print("The jar is empty.");
}

if (has("Empty Cup") &&
    said("add", "anyword", "cup"))
{
    print("There is no need to put it in the cup.");
}
if (has("Shovel") &&
    (said("dig", "rol") ||
    said("try", "shovel", "rol")))
{
    print("You can't dig here.");
}
if (has("Ocean Water*") &&
    said("cup"))
{
    drop("Ocean Water*");
    get("Empty Cup");
    print("The cup is now empty.");
}
if ((said("examine", "enchanter") ||
    said("examine", "spider") ||
    said("examine", "alexander") ||
    said("examine", "barmaid") ||
    said("examine", "bandit") ||
    said("examine", "barmaid") ||
    said("examine", "dragon") ||
    said("examine", "eagle") ||
    said("examine", "barmaid") ||
    said("examine", "bird")))
{
    print("Where!?");
}
if (v44 == 11 &&
    said("dive"))
{
    print("You ARE swimming.");
}
if ((said("call", "animal") ||
    said("call", "lizard") ||
    said("call", "reptile") ||
    said("call", "spider") ||
    said("call", "bandit") ||
    said("call", "barmaid") ||
    said("call", "bird")))
{
    print("Funny, no response.");
}
if (said("examine", "rock", "rol"))
{
    print("If you've seen one rock, you've seen them all.");
}
if (said("examine", "brush", "rol"))
{
    print("The shrubbery is nice, but you have better things to do.");
}
if (said("examine", "rol"))
{
    random(42, 44, v36);
    print.v(v36);
}
if (said("capture", "rol"))
{
    random(46, 48, v36);
    print.v(v36);
}
if (said("board", "rol"))
{
    print("Just walk there.");
}
if (said("try", "rol"))
{
    print("How can you use that which you do not have?");
}
if (said("capture", "rol"))
{
    print("You have no need to take it.");
}

if (said("drink", "rol"))
{
    print("Once you tasted it, you wouldn't want it!");
}



if (said("kill", "rol"))
{
    print("You're not that cruel.");
}
if (said("find", "rol"))
{
    print("Is it lost?");
}
if (said("add", "rol"))
{
    print("You might need it.");
}


Label3:
if (!isset(haveMatch) &&
    isset(haveInput))
{
    print("How can you do that?");
}
get.posn(ego, v42, v43);
v82 = egoDir;
reset(f33);
reset(f45);
reset(f127);
return ();

[ Messages#message 1 "%m10%w1?"#message 2 "%m10%w2?"#message 3 "%m10%w3?"#message 4 "%m10%w4?"#message 5 "%m10%w5?"#message 6 "%m10%w6?"#message 7 "%m10%w7?"#message 8 "%m10%w8?"#message 9 "Ok."#message 10 "What's a "#message 11 "\n     King's Quest III\n\n  Version 2.14  3/15/88   \n\n"#message 12 "The help screen won't work here. Try again elsewhere."#message 13 "Thanks for playing King's Quest III... next time, be more careful!"#message 14 "Since you're dead...\n\nall you can do is restore a saved game or start over."#message 15 "Ick! You're slimy!"#message 16 "Al Lowe & Bob Heitman."#message 17 "%v118 days, %m18"#message 18 "%v117 hours, %m19"#message 19 "%v116 minutes and %v115 seconds."#message 20 "Your magic spell is wearing off!"#message 22 "The stone won't work here."#message 23 "You purr contentedly, enjoying your new life as a cat!"#message 24 "You've broken the spell of invisibility."#message 25 "You might need it."#message 26 "\"Hi.\""#message 27 "You can't do that now."#message 28 "\"You're welcome.\""#message 29 "Obviously, you were raised by a naughty wizard!"#message 30 "%v117:%v116|2:%v115|2 "#message 31 "If you've seen one rock, you've seen them all."#message 32 "Shhhh. (You're flying!)"#message 33 "Buzzzzzz."#message 34 "They're not hungry."#message 35 "The porridge conceals the crumbled cookie; it still looks as appetizing as ever."#message 36 "Oops. Bad move!"#message 37 "Ok, some cat hair sticks to your teeth."#message 38 "Mandrake root powder might be a little poisonous!"#message 39 "\"This tastes pretty good,\" you think. You'd eat more, but you're too busy dying."#message 40 "You don't need to... now."#message 41 "Funny, no response."#message 42 "It doesn't look interesting."#message 43 "You see nothing special."#message 44 "It's just as it appears."#message 45 "How can you do that?"#message 46 "It's of no use."#message 47 "You don't need it."#message 48 "There's no reason to take it."#message 49 "Just walk there."#message 50 "You're not that cruel."#message 51 "%m53?"#message 52 "%m53 %w3?"#message 53 "What would you do with the %w2"#message 54 "How can you use that which you do not have?"#message 55 "You can eat the "#message 56 "%m9 It tastes bitter!"#message 57 "You don't need to put the %w2 in the bowl."#message 58 "Nothing here fits your key."#message 59 "%m55mutton without carving it."#message 60 "%m55fruit without cutting it."#message 61 "%m55bread without slicing it."#message 62 "Mmmm! Mama Bear makes great porridge!"#message 63 ""#message 64 ""#message 65 "%m68 that requires a spoon."#message 66 "%m68."#message 67 "Once you tasted it, you wouldn't want it!"#message 68 "You have no food"#message 69 "You can't dig here."#message 70 "They don't want it."#message 71 "The thought turns your stomach!"#message 72 "Where!?"#message 73 "Your cup is empty."#message 74 "Perhaps your magic would be more effective outside."#message 75 "There is no need to put it in the cup."#message 76 "You have no need to take it."#message 77 "%v0|3"#message 78 "%m9 It tastes terrible!"#message 79 "You ARE swimming."#message 80 "%m78 You spit it out, spilling the rest on the ground."#message 81 "The shrubbery is nice, but you have better things to do."#message 82 "%m9 Nothing happens."#message 83 "Ok, but this place does not meet the spell's requirements."#message 84 "The cup is now empty."#message 85 "You look cute."#message 86 "%m9 You decide it smells better than it tastes!"#message 87 "%m91%v118 days, %v117 hours, %v116 minutes and %v115 seconds.\n"#message 88 "%m91%v117 hours, %v116 minutes and %v115 seconds.\n"#message 89 "%m91%v116 minutes and %v115 seconds.\n"#message 90 "%m9 Ummmm, not bad."#message 91 "%m11\nYou've been playing for \n"#message 92 "You missed!"#message 93 "You have %v63 gold coins."#message 94 "You can't buy that here."#message 95 ""#message 96 "You eat a few grains of salt."#message 97 ""#message 98 ""#message 99 "Is it lost?"#message 100 "The jar is empty."#message 101 "As you remove the dough from your ears, it crumbles into dust and is lost!"#message 102 ""#message 103 "There's not enough room to fly in here."#message 104 ""#message 105 ""#message 106 ""#message 107 "The urge to fly and soar has left%m110"#message 108 ""#message 109 "The impulse to buzz around has vanished. You feel yourself growing bigger%m110"#message 110 ", so you head for what you hope is a safe place to land."#message 111 ""#message 112 "Your magic essence is all gone."#message 113 "\"'Bye.\""#message 114 "Fastest%m118"#message 115 "Fast%m118"#message 116 "Normal%m118"#message 117 "Slow%m118"#message 118 " speed."#message 120 "Joystick/Mouse <Ctrl-J>"#message 121 "Sierra "#message 122 "About KQ3 "#message 123 "Help  <F1>"#message 124 "File "#message 125 "Save     <F5>"#message 126 "Restore  <F7>"#message 127 "-------------"#message 128 "Restart  <F9>"#message 129 "Quit  <Alt-Z>"#message 130 "Action "#message 131 "Inventory  <TAB>"#message 132 "See Object  <F4>"#message 133 "Special "#message 134 "Sound On/Off       <F2>"#message 135 "Graphics Mode  <Ctrl-R>"#message 136 "Joystick       <Ctrl-J>"#message 137 "Clock On/Off           "#message 138 "Pause Game             "#message 139 "Speed "#message 140 "Normal       "#message 141 "Slow         "#message 142 "Fast         "#message 143 "Fastest      "#message 144 "Change  <F10>"


