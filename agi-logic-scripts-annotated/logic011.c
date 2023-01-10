if (isset(newRoom))
{
    load.view.v(currentEgoView);
    set.view.v(ego, currentEgoView);
    load.view(View0);
    v56 = 2;
    set(f54);
    set.horizon(52);
    v32 = 50;
    if (isset(f111))
    {
        v31 = 112;
    }
    v57 = 21;
    v58 = 69;
    load.logics(Logic128);
    load.logics(Logic118);
    if (obj.in.room("Snakeskin*", currentRoom))
    {
        load.view(View242);
    }
    load.pic(currentRoom);
    draw.pic(currentRoom);
    discard.pic(currentRoom);
    if (isset(f48))
    {
        // [WARNING: this block contains no commands
    }
    if (isset(f47))
    {
        draw(ego);
    }
    if (obj.in.room("Snakeskin*", currentRoom))
{
        animate.obj(o1);
        position(o1, 88, 99);
        set.view(o1, View242);
        draw(o1);
        stop.update(o1);
    }
    call(Logic128);
    call(Logic118);
    show.pic();
    return ();
}
reset(f222);


if (posn(ego, 45, 100, 75, 110) || posn(ego, 15, 125, 40, 140) || posn(ego, 15, 60, 40, 65))
{
    set(f222);
}
reset(f221);

if (obj.in.room("Snakeskin*", currentRoom))
{
    distance(ego, o1, v36);
    if (v36 < 20)
    {
        set(f221);
    }
    if (said("examine", "reptile skin") || said("examine", "deck"))
    {
        print("The parched sands of the desert seem to reach forever westward. You "
                "notice a dried snake skin lying on the hot ground.");
    }
    if (said("capture", "reptile skin") || said("capture", "reptile"))
    {
        if (isset(f221))
        {
            erase(o1);
            get("Snakeskin*");
            currentScore += 1;
            print("You retrieve the dried snake skin from the hot desert sand. It is "
                    "delicate and could easily crumble.");
        }
        else
        {
            print("You're not close enough.");
        }
    }
}

if (said("examine", "desert") || said("examine"))
{
    print("The parched sands of the desert seem to reach forever westward.");
}

if (said("examine", "brush"))
{
    if (isset(f222))
    {
        print("The flora in this hot, dry desert is scant. The only plants that "
                "grow are cactus, thorny shrubs, and an occasional stunted tree.");
    }
    else
    {
        print("All of the cactus around here are too prickly to be touched. You "
                "could wind up with a handful of thorns.");
    }
}

if (said("capture", "brush") || said("capture", "brush"))
{
    if (isset(f222))
    {
        print("All of the cactus around here are too prickly to be touched. You "
                "could wind up with a handful of thorns.");
    }
    else
    {
        print("You're not close enough.");
    }
}
call(Logic128);
call(Logic118);

if (edgeEgoHit == BOTTOM_EDGE)
{
    new.room(Logic16);
}
if (edgeEgoHit == TOP_EDGE)
{
    new.room(Logic26);
}
if (edgeEgoHit == LEFT_EDGE)
{
    new.room(Logic32);
}
if (edgeEgoHit == RIGHT_EDGE)
{
    new.room(Logic12);
}
return ();

[Messages
#message 1 "You retrieve the dried snake skin from the hot desert sand. It is delicate and could easily crumble."
#message 2 "The parched sands of the desert seem to reach forever westward. You notice a dried snake skin lying on the hot ground."
#message 3 "It is an old, dried snakeskin."
#message 4 "The flora in this hot, dry desert is scant. The only plants that grow are cactus, thorny shrubs, and an occasional stunted tree."
#message 7 "All of the cactus around here are too prickly to be touched. You could wind up with a handful of thorns."
#message 8 ""
#message 9 "The sky in this desert is a cloudless, deep, deep blue. The sun is very bright and very hot in this beautiful, blue sky."
#message 10 "You're not close enough."
#message 11 "The parched sands of the desert seem to reach forever westward."






