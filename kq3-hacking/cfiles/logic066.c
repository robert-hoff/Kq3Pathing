if (isset(newRoom))
{
    set(f58);
    v56 = 5;
    set.horizon(55);
    v57 = 18;
    v58 = 101;
    load.sound(Sound1);
    load.sound(Sound8);
    load.sound(Sound15);
    load.sound(Sound9);
    animate.obj(o13);
    load.view(View236);
    set.view(o13, View236);
    set.priority(o13, 9);
    ignore.horizon(o13);
    ignore.objs(o13);
    set.cel(o13, 1);
    position(o13, 30, 35);
    stop.cycling(o13);
    draw(o13);
    if (!isset(f183))
    {
        load.pic(currentRoom);
        draw.pic(currentRoom);
        discard.pic(currentRoom);
        load.view(View46);
        animate.obj(o1);
        set.priority(o1, 8);
        ignore.horizon(o1);
        ignore.blocks(o1);
        ignore.objs(o1);
        set.view(o1, View46);
        set.loop(o1, 0);
        v36 = 3;
        cycle.time(o1, v36);
        position(o1, 52, 64);
        set.cel(o1, 3);
        draw(o1);
        animate.obj(o2);
        set.priority(o2, 8);
        ignore.horizon(o2);
        ignore.blocks(o2);
        ignore.objs(o2);
        set.view(o2, View46);
        set.loop(o2, 1);
        v36 = 2;
        cycle.time(o2, v36);
        position(o2, 67, 30);
        draw(o2);
        animate.obj(o3);
        set.priority(o3, 8);
        ignore.horizon(o3);
        ignore.blocks(o3);
        ignore.objs(o3);
        set.view(o3, View46);
        set.loop(o3, 2);
        v36 = 3;
        cycle.time(o3, v36);
        position(o3, 107, 52);
        draw(o3);
        set(f226);
        load.view(View47);
        animate.obj(o11);
        set.view(o11, View47);
        set.loop(o11, 1);
        fix.loop(o11);
        set.priority(o11, 11);
        ignore.objs(o11);
        ignore.horizon(o11);
        ignore.blocks(o11);
        v36 = 2;
        cycle.time(o11, v36);
        animate.obj(o12);
        set.view(o12, View47);
        set.loop(o12, 0);
        fix.loop(o12);
        set.priority(o12, 11);
        ignore.objs(o12);
        ignore.horizon(o12);
        ignore.blocks(o12);
        v36 = 2;
        cycle.time(o12, v36);
    }
    else
    {
        v36 = 166;
        load.pic(v36);
        draw.pic(v36);
        discard.pic(v36);
    }
    load.logics(Logic119);
    call(Logic119);
    load.view(View0);
    load.view(View11);
    load.view(View8);
    load.view.v(currentEgoView);
    set.view.v(ego, currentEgoView);
    get.posn(ego, v40, v41);
    if (isset(f48))
    {
        v41 = 106;
        if (previousRoom == 67)
        {
            v40 = 152;
            v224 = 246;
        }
        if (previousRoom == 65)
        {
            v40 = 0;
            v224 = 18;
        }
        position.v(ego, v40, v41);
        if (!isset(f183) &&
            v44 == 0 &&
            !isset(f49))
        {
            prevent.input();
            v40 += v224;
            move.obj.v(ego, v40, v41, v141, f225);
            set(f232);
        }
    }
    if (isset(f47))
    {
        draw(ego);
    }
    show.pic();
    return ();
}
if (!isset(f183) &&
    v71 == 6)
{
    v71 = 0;
    v55 = 0;
    v54 = 30;
}
if (!isset(f183) &&
    isset(f49))
{
    if (v55 == 0 &&
        v54 < 40)
    {
        v54 = 40;
    }
}
if (!isset(f183) &&
    isset(f33) &&
    v44 == 0)
{
    set(f225);
    reset(f232);
}
if (isset(f182) &&
    !isset(f183))
{
    reset(f182);
    set(f229);
    set(f225);
    reset(f232);
}
if (isset(f225))
{
    reset(f232);
    stop.motion(ego);
    program.control();
    if (isset(f226) &&
        !isset(f221) &&
        !isset(f222))
    {
        reset(f225);
        v222 = 0;
        if (v40 > 80)
        {
            v223 = 3;
        }
        else
        {
            v223 = 1;
        }
        if (isset(f229))
        {
            print.at("The dragon notices Princess Rosella being untied, and blasts "
                        "you both with a long, licking tongue of flame.", 14, 2, 37);
        }
        else
        {
            print.at("A huge, fire-breathing dragon is here and it has SEEN you! "
                        "Hypnotized by its baleful glare, you stand frozen in your "
                        "tracks!! What a way to go; ending up as a dragon's barbeque!", 14, 2, 37);
        }
        set(f227);
        goto(Label1);
    }
}
if (!isset(f183))
{
    if (isset(f226) &&
        v222 <= 0)
    {
        random(1, 3, v223);
Label1:
        reset(f226);
        if (v223 == 1)
        {
            stop.update(o2);
            stop.update(o3);
            start.update(o1);
            set.cel(o1, 0);
            end.of.loop(o1, f226);
        }
        if (v223 == 2)
        {
            stop.update(o1);
            stop.update(o3);
            start.update(o2);
            current.cel(o2, v36);
            last.cel(o2, v65);
            start.cycling(o2);
            if (v36 == v65)
            {
                reverse.loop(o2, f226);
            }
            else
            {
                end.of.loop(o2, f226);
            }
        }
        if (v223 == 3)
        {
            stop.update(o1);
            stop.update(o2);
            start.update(o3);
            set.cel(o3, 0);
            end.of.loop(o3, f226);
        }
    }
    if (v222 > 0)
    {
        --v222;
    }
    current.cel(o1, v36);
    if (!isset(f232) &&
        v36 == 2 &&
        !isset(f221) &&
        !isset(f183))
    {
        ++v36;
        set.cel.v(o1, v36);
        set(f221);
        position(o11, 22, 83);
        set.cel(o11, 0);
        draw(o11);
        if (isset(f238))
        {
            sound(Sound8, f238);
        }
        start.cycling(o11);
        if (isset(f229))
        {
            move.obj(o11, 0, 166, 1, f223);
        }
        stop.update(o1);
    }
    current.cel(o3, v36);
    if (!isset(f232) &&
        v36 == 2 &&
        !isset(f222) &&
        !isset(f183))
    {
        ++v36;
        set.cel.v(o3, v36);
        set(f222);
        position(o12, 118, 80);
        set.cel(o12, 0);
        draw(o12);
        start.cycling(o12);
        if (isset(f238))
        {
            sound(Sound8, f238);
        }
        start.update(o3);
    }
    current.cel(o11, v36);
    if (isset(f221) &&
        v36 == 5)
    {
        erase(o11);
        reset(f221);
        normal.motion(o11);
        start.update(o1);
    }
    else
    {
        current.cel(o12, v36);
        if (isset(f222) &&
            v36 == 5)
        {
            // [WARNING: Block end outside of nested block(0) at position 710
            erase(o12);
            reset(f222);
            normal.motion(o12);
            start.update(o3);
        }
        else
        {
            goto(Label2);
        }
    }
    if (isset(f227))
    {
        reset(f227);
        set(f46);
        set.view(ego, View8);
        set.cel(ego, 0);
        set(f35);
        v36 = 4;
        cycle.time(ego, v36);
        end.of.loop(ego, f228);
        v44 = 0;
        if (isset(f229))
        {
            reset(f229);
            set.view(o15, View75);
            set.cel(o15, 0);
            start.cycling(o15);
            end.of.loop(o15, f230);
        }
        else
        {
            goto(Label2);
        }
    }
Label2:
    if (isset(f230))
    {
        reset(f230);
        stop.motion(o15);
        stop.cycling(o15);
    }
    if (isset(f228))
    {
        reset(f228);
        reset(f35);
        program.control();
        stop.cycling(ego);
        erase(o11);
        erase(o12);
        start.update(o2);
        start.update(o1);
        start.update(o3);
        stop.cycling(ego);
        set(f44);
        stop.cycling(ego);
    }
}
call(Logic119);
if (v71 == 1)
{
    v71 = 0;
    drop("Magic Map*");
    print("As you unroll the delicate map, it crumbles in the intense heat!");
}
if (v71 == 9)
{
    stop.motion(ego);
    program.control();
    prevent.input();
    set(f46);
    v71 = 0;
    erase(o11);
    erase(o12);
    currentScore += 7;
    v36 = 88;
    load.pic(v36);
    draw.pic(v36);
    discard.pic(v36);
    load.view(View48);
    set.view(o1, View48);
    set.loop(o1, 0);
    set.view(o2, View48);
    set.loop(o2, 1);
    set.view(o3, View48);
    set.loop(o3, 2);
    show.pic();
    force.update(o1);
    force.update(o2);
    force.update(o3);
    stop.update(ego);
    stop.update(o15);
    v221 = 10;
    set.scan.start();
    if (v220 > 8)
    {
        stop.cycling(o13);
    }
    else
    {
        if (v220 == 8)
        {
            stop.update(o1);
            stop.update(o2);
            stop.update(o3);
        }
        else
        {
            goto(Label2);
        }
        start.cycling(o13);
        sound(Sound15, f238);
    }
    if (v220 <= 0)
    {
        sound(Sound9, f238);
        shake.screen(1);
        random(10, 15, v220);
        random(47, 115, v37);
        random(32, 40, v38);
        reposition.to.v(o13, v37, v38);
        random(0, 1, v64);
        set.loop.v(o13, v64);
        set.cel(o13, 1);
        stop.cycling(o13);
        start.update(o1);
        start.update(o2);
        start.update(o3);
    }
    --v220;
    if (isset(f45))
    {
        --v221;
        if (v221 == 1)
        {
            print("Bolts of lightning strike the huge dragon. He howls in pain and "
                    "falls to the ground... dead.");
        }
        else
        {
            goto(Label2);
        }
    }
    if (v221 > 0)
    {
        return ();
    }
    else
    {
        reset(f46);
        erase(o13);
        set(f183);
        stop.update(o1);
        stop.update(o2);
        stop.update(o3);
        set.priority(o1, 0);
        set.priority(o2, 0);
        set.priority(o3, 0);
        set.view(o1, View46);
        set.view(o2, View46);
        set.view(o3, View46);
        discard.view(View48);
        v36 = 166;
        load.pic(v36);
        draw.pic(v36);
        discard.pic(v36);
        show.pic();
        v55 = 0;
        v54 = 5;
        start.update(ego);
        start.update(o15);
        player.control();
        start.motion(ego);
        reset.scan.start();
    }
}
if (said("kill", "dragon"))
{
    if (!isset(f183))
    {
        print("And just how do you propose to do that?");
    }
    else
    {
        print("That would be overkill.");
    }
}
if ((said("throw", "dagger") ||
    said("throw", "dagger", "dragon") ||
    said("kill", "dragon", "try", "dagger")))
{
    if (!has("Knife"))
    {
        print("You don't have a knife.");
    }
    else
    {
        if (isset(f183))
        {
            print("Do you really think that is necessary?");
        }
        else
        {
            print("Your little knife would barely nick that big dragon!");
        }
    }
}
if ((said("examine") ||
    said("examine", "cloud")))
{
    print("The dragon has laid waste to this area. The earth is scorched and all "
            "the trees and plants are charred.");
}

if (said("examine", "dragon"))
{
    if (!isset(f183))
    {
        print("The dragon's green scaly body is huge! Its three ugly heads blow "
                "flame and smoke, while its necks twist and writhe. Ugh!! The sight "
                "of it makes you shiver.");
    }
    else
    {
        print("The dragon lies dead upon the ground. He was no match for the fury "
                "of your magical storm!");
    }
}
if (said("call", "dragon"))
{
    if (!isset(f183))
    {
        print("Shhh!!! The dragon will hear you!");
    }
    else
    {
        print("This dragon is dead.");
    }
}
if (said("examine", "forest"))
{
    print("All of the trees and plants in this area have been burnt to stumps by "
            "the evil three-headed dragon!");
}
if (said("examine", "brush"))
{
    print("%m14");
}
if ((said("climb", "up", "forest") ||
    said("climb", "forest")))
{
    print("There are no climbable trees around.");
}
if ((said("examine", "up", "sky") ||
    said("examine", "sky")))
{
    print("The sky is blue and cloudless above this strange cloud land.");
}
if ((said("examine", "on", "deck") ||
    said("examine", "deck")))
{
    print("The ground is moist from the constant presence of clouds, but yet the "
            "trees are burnt and blackened.");
}
if (v44 == 0 &&
    (v41 > 162 ||
    edgeEgoHit == TOP_EDGE))
{
    if (isset(f49))
    {
        print("It seems that you have confused being invisible...");
    }
    else
    {
        print("While you have regained visibility...");
    }
    sound(Sound1, f238);
    erase(ego);
    v225 = 2;
    set.scan.start();
    if (isset(f45))
    {
        --v225;
    }
    if (v225 <= 0)
    {
        if (isset(f49))
        {
            print("...with being weightless.");
        }
        else
        {
            print("...you'll never regain conciousness.");
        }
        reset.scan.start();
        erase(o11);
        erase(o12);
        start.update(o1);
        start.update(o2);
        start.update(o3);
        erase(o13);
        stop.cycling(ego);
        set(f44);
    }
    return ();
}
if (edgeEgoHit == RIGHT_EDGE)
{
    new.room(Logic67);
}
if (edgeEgoHit == LEFT_EDGE)
{
    new.room(Logic65);
}
return ();

[Messages
#message 1 "The dragon has laid waste to this area. The earth is scorched and all the trees and plants are charred."
#message 2 "The dragon's green scaly body is huge! Its three ugly heads blow flame and smoke, while its necks twist and writhe. Ugh!! The sight of it makes you shiver."
#message 3 "The dragon lies dead upon the ground. He was no match for the fury of your magical storm!"
#message 4 "A huge, fire-breathing dragon is here and it has SEEN you! Hypnotized by its baleful glare, you stand frozen in your tracks!! What a way to go; ending up as a dragon's barbeque!"
#message 5 "The dragon notices Princess Rosella being untied, and blasts you both with a long, licking tongue of flame."
#message 6 "That was a mistake; now he knows you're here!"
#message 7 "It seems that you have confused being invisible..."
#message 8 "...with being weightless."
#message 9 "Bolts of lightning strike the huge dragon. He howls in pain and falls to the ground... dead."
#message 10 "Shhh!!! The dragon will hear you!"
#message 11 "This dragon is dead."
#message 12 "And just how do you propose to do that?"
#message 13 "That would be overkill."
#message 14 "All of the trees and plants in this area have been burnt to stumps by the evil three-headed dragon!"
#message 15 "%m14"
#message 16 "There are no climbable trees around."
#message 17 "The sky is blue and cloudless above this strange cloud land."
#message 18 "The ground is moist from the constant presence of clouds, but yet the trees are burnt and blackened."
#message 19 "You don't have a knife."
#message 20 "Your little knife would barely nick that big dragon!"
#message 21 "Do you really think that is necessary?"
#message 22 "As you unroll the delicate map, it crumbles in the intense heat!"
#message 23 "While you have regained visibility..."
#message 24 "...you'll never regain conciousness."



