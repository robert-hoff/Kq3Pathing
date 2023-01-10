if (isset(newRoom))
{
    set.horizon(1);
    reset(f46);
    set(f34);
    v105 = 0;
    v106 = 0;
    v104 = 0;
    v103 = 0;
    reset(f120);
    load.logics.v(v102);
    load.sound(Sound35);
    v36 = 143;
    load.pic(v36);
    load.pic(currentRoom);
    draw.pic(currentRoom);
    show.pic();
    call.v(v102);
    print("You know you must work with the utmost care. Every step is critical; "
            "each must be done in the proper way, in the proper sequence. You "
            "tremble in anticipation.");
    set(f221);
    return ();
}

set(f46);
if (!isset(haveInput))
{
    goto(Label1);
}
if (said("try", "brazier"))
{
    print("What would you do with the brazier?");
}
if ((said("burn", "brazier") ||
    said("burn", "charcoal", "brazier") ||
    said("burn", "charcoal")))
{
    if ((v107 > 0 || v108 > 0))
    {
        print("It is already burning.");
    }
    else
    {
        print("Making sure there is fresh charcoal in the brazier (there is a small "
                "supply here), you light it with the flint. Soon, the brazier is hot.");
        v108 = 3;
    }
}
if ((said("examine", "brazier") ||
    said("examine", "brazier", "counter") ||
    said("look in", "brazier")))
{
    print("The small brazier is made of metal shaped into a bowl, with four small "
            "legs. It is filled with charcoal and topped with a metal grill. It is "
            "used for heating or cooking things.");
    if (v107 > 0 || v108 > 0)
    {
        print("%m17 You could heat things quickly with the brazier right now.");
    }
    else
    {
        print("%m18stone cold.");
    }
}

if (said("capture", "charcoal") || said("capture", "charcoal", "from", "brazier"))
{
    print("The charcoal belongs in the brazier. You have no need for it anywhere "
            "else.");
}

if ((said("examine", "charcoal") || said("examine", "charcoal", "brazier")))
{
    if ((v107 > 0 || v108 > 0))
    {
        print("%m18very hot!");
    }
    else
    {
        print("%m18stone cold.");
    }
}

if ((said("board", "area") ||
    said("quit", "anyword", "spell") ||
    said("examine", "area") ||
    said("add", "area") ||
    said("examine", "lab") ||
    said("add", "lab") ||
    said("quit", "anyword") ||
    said("quit", "anyword")))
{
    set(f220);
}

Label1:
if (isset(f45) && v107 == 1 && v108 <= 0)
{
    print.at("The brazier has burned all the charcoal, and is now cool.", 2, 2, 36);
}

if (isset(f120))
{
    stop.sound();
    reset(f221);
    set(f220);
    if (!isset(soundOn))
    {
        print("The mysterious music stops. What could this mean?");
    }
}

if (isset(f221))
{
    sound(Sound35, f221);
    if (!isset(f222))
    {
        set(f222);
        if (!isset(soundOn))
        {
            print("A mysterious music fills the laboratory!");
        }
    }
}

if (v103 == 255)
{
    print("Successfully completing the spell, you again look at the wizard's laboratory.");
    set(f220);
    if (!isset(f151) &&
        v102 == 121)
    {
        set(f151);
        currentScore += 10;
    }
    if (!isset(f152) &&
        v102 == 122)
    {
        set(f152);
        currentScore += 10;
    }
    if (!isset(f153) &&
        v102 == 123)
    {
        set(f153);
        currentScore += 10;
    }
    if (!isset(f154) &&
        v102 == 124)
    {
        set(f154);
        currentScore += 10;
    }
    if (!isset(f155) &&
        v102 == 125)
    {
        set(f155);
        currentScore += 10;
    }
    if (!isset(f156) &&
        v102 == 126)
    {
        set(f156);
        currentScore += 10;
    }
    if (!isset(f157) &&
        v102 == 127)
    {
        set(f157);
        currentScore += 10;
    }
}

if (isset(f220))
{
    reset(f220);
    if (v103 <= 0)
    {
        print("You scratch your head at the confusing old book, and turn away in "
                "puzzlement.");
    }
    else
    {
        if (v103 != 255)
        {
            set(haveMatch);
            set(f120);
            call.v(v102);
            print("A strange feeling comes over you. You wonder if you could have "
                    "made a mistake!");
        }
    }
    v104 = 0;
    v103 = 0;
    v102 = 0;
    set.string(inputPrompt, "]");
    reset(f46);
    new.room(Logic10);
}
call.v(v102);
if ((said("add", "anyword", "on", "brazier") ||
    said("add", "anyword", "on", "top", "brazier") ||
    said("boil", "anyword", "on", "brazier") ||
    said("boil", "anyword", "on", "top", "brazier") ||
    said("add", "anyword", "on", "brazier", "boil") ||
    said("add", "anyword", "on", "top", "brazier", "boil")))
{
    print("For a moment you consider doing that, but then realize it wouldn't work.");
}
return ();



[Messages
#message 1 "You know you must work with the utmost care. Every step is critical; each must be done in the proper way, in the proper sequence. You tremble in anticipation."
#message 2 "You scratch your head at the confusing old book, and turn away in puzzlement."
#message 3 "A strange feeling comes over you. You wonder if you could have made a mistake!"
#message 4 "A mysterious music fills the laboratory!"
#message 5 "The mysterious music stops. What could this mean?"
#message 6 "Successfully completing the spell, you again look at the wizard's laboratory."
#message 7 "]"
#message 8 "What would you do with the brazier?"
#message 9 "It is already burning."
#message 10 "Making sure there is fresh charcoal in the brazier (there is a small supply here), you light it with the flint. Soon, the brazier is hot."
#message 11 "The brazier has burned all the charcoal, and is now cool."
#message 12 "For a moment you consider doing that, but then realize it wouldn't work."
#message 13 "The small brazier is made of metal shaped into a bowl, with four small legs. It is filled with charcoal and topped with a metal grill. It is used for heating or cooking things."
#message 14 "%m17 You could heat things quickly with the brazier right now."
#message 15 "%m18stone cold."
#message 16 "The charcoal belongs in the brazier. You have no need for it anywhere else."
#message 17 "%m18very hot!"
#message 18 "The charcoal in the metal brazier is "



