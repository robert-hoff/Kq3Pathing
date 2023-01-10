if (isset(newRoom))
{
    random(1, 3, v36);
    if (currentRoom != 32 &&
        v36 == 1)
    {
        set(f252);
        set(f254);
        set(f255);
        load.view(View58);
        animate.obj(o11);
        set.view(o11, View58);
        random(10, 140, v37);
        random(70, 160, v38);
        position.v(o11, v37, v38);
        draw(o11);
        v250 = 2;
        animate.obj(o12);
        set.view(o12, View58);
        random(10, 140, v37);
        random(70, 160, v38);
        position.v(o12, v37, v38);
        draw(o12);
        v251 = 12;
        random(1, 2, v36);
        if (has("Dough in Ears") &&
            v36 == 1 &&
            (!isset(f143) ||
            !isset(f144) ||
            !isset(f145)))
        {
Label1:
            random(1, 3, v36);
            if (v36 == 1)
            {
                if (isset(f143))
                {
                    goto(Label1);
                }
                else
                {
                    v252 = 143;
                    v253 = 14;
                    v254 = 17;
                }
            }
            if (v36 == 2)
            {
                if (isset(f144))
                {
                    goto(Label1);
                }
                else
                {
                    v252 = 144;
                    v253 = 18;
                    v254 = 20;
                }
            }
            if (v36 == 3)
            {
                if (isset(f145))
                {
                    goto(Label1);
                }
                else
                {
                    v252 = 145;
                    v253 = 21;
                    v254 = 22;
                }
            }
            random(3, 8, v255);
        }
    }
    random(1, 5, v36);
    if (v36 == 1)
    {
        set(f251);
        load.view(View59);
        animate.obj(o10);
        set.view(o10, View59);
        random(10, 140, v37);
        random(70, 160, v38);
        position.v(o10, v37, v38);
        draw(o10);
        wander(o10);
    }
    return ();
}
if (!isset(haveInput))
{
    goto(Label2);
}
if ((said("examine", "desert") ||
    said("examine")))
{
    print("You find yourself at the edge of a great desert, stretching as far as "
          "the eye can see to the west.");
}
if (said("examine", "flower"))
{
    print("The flora in this hot, dry desert is scant. The only plants that grow "
          "are cactus, thorny shrubs, and an occasional stunted tree.");
}
if (said("examine", "forest"))
{
    print("Trees are practically non-existent in this dry desert. The few trees "
          "that do survive are stunted and dry-looking.");
}
if (said("examine", "forest"))
{
    print("Trees are practically non-existent in this dry desert. The few trees "
          "that do survive are stunted and dry-looking.");
}
if (said("examine", "bone"))
{
    print("They are just some old uninteresting bones.");
}
if (said("examine", "flower") || said("smell", "flower"))
{
    print("Occasionally, after a rare rain, flowers spring up everywhere in this "
          "great desert. There are no flowers now, as it has not rained for a "
          "long time.");
}

if (said("examine", "deck"))
{
    print("The hot, dry sands of the desert reach seemingly forever to the west. "
          "It is a parched land.");
}
if ((said("examine", "cactii") ||
    said("examine", "cactii", "deck") ||
    said("examine", "deck")))
{
    print("All of the cactus around here are too prickly to be touched. You could "
          "wind up with a handful of thorns.");
}
if (said("examine", "sky"))
{
    print("The sky in this desert is a cloudless, deep, deep blue. Overhead, the "
          "sun is very bright and very hot.");
}
if (said("capture", "flower") || said("capture", "flower"))
{
    print("There are no wildflowers to pick here.");
}

if (said("climb", "forest"))
{
    print("The few, scanty trees in this desert are not suitable for climbing.");
}

if (isset(f254) || isset(f255))
{
    if (said("examine", "lizard"))
    {
        print("They're just lizards, scurrying across the desert floor.");
    }
    if (said("call", "lizard"))
    {
        print("They can't understand you.");
    }
    if (has("Dough in Ears") && said("hear", "lizard"))
    {
        print("Maybe if you're quiet, you'll hear them.");
    }
    if (said("anyword", "lizard"))
    {
        print("The little lizards are much too quick for you.");
    }
}

if (isset(f251) && said("anyword", "reptile"))
{
    print("Any experienced traveller knows better than to mess with snakes!");
}

Label2:
--v250;
if (v250 == 1)
{
    toggle(f249);
    if (isset(f249))
    {
        set.view(o11, View58);
        wander(o11);
        start.cycling(o11);
        random(9, 33, v250);
    }
    else
    {
        normal.motion(o11);
        stop.motion(o11);
        stop.cycling(o11);
        random(33, 99, v250);
    }
}


--v251;
if (v251 == 1)
{
    toggle(f250);
    if (isset(f250))
    {
        set.view(o12, View58);
        wander(o12);
        start.cycling(o12);
        random(9, 33, v251);
    }
    else
    {
        normal.motion(o12);
        stop.motion(o12);
        stop.cycling(o12);
        random(33, 99, v251);
    }
}


if (isset(f45) &&
    v253 > 0 &&
    isset(f254) &&
    isset(f255) &&
    v44 == 0 &&
    v47 == v255)
{
    v255 = 0;
    set.v(v252);
Label3:
    print.v(v253);
    if (v253 < v254)
    {
        ++v253;
        goto(Label3);
    }
}


if (edgeObjHit > NOT_HIT && edgeObjHit != TOP_EDGE)
{
    if (isset(f254) &&
        objHitEdge == 11)
    {
        erase(o11);
        reset(f254);
        v250 = 0;
    }
    if (isset(f255) &&
        objHitEdge == 12)
    {
        erase(o12);
        reset(f255);
        v251 = 0;
    }
    if (isset(f251) &&
        objHitEdge == 10)
    {
        erase(o10);
        reset(f251);
    }
}
return ();


[Messages
#message 1 "You find yourself at the edge of a great desert, stretching as far as the eye can see to the west."
#message 2 "The flora in this hot, dry desert is scant. The only plants that grow are cactus, thorny shrubs, and an occasional stunted tree."
#message 3 "Trees are practically non-existent in this dry desert. The few trees that do survive are stunted and dry-looking."
#message 4 "They are just some old uninteresting bones."
#message 5 "Occasionally, after a rare rain, flowers spring up everywhere in this great desert. There are no flowers now, as it has not rained for a long time."
#message 6 "The hot, dry sands of the desert reach seemingly forever to the west. It is a parched land."
#message 7 "All of the cactus around here are too prickly to be touched. You could wind up with a handful of thorns."
#message 8 "They're just lizards, scurrying across the desert floor."
#message 9 "The sky in this desert is a cloudless, deep, deep blue. Overhead, the sun is very bright and very hot."
#message 10 "There are no wildflowers to pick here."
#message 11 "The few, scanty trees in this desert are not suitable for climbing."
#message 12 "The little lizards are much too quick for you."
#message 13 "Any experienced traveller knows better than to mess with snakes!"
#message 14 "You overhear one of the scaly lizards say to the other, \"There's that boy, Gwydion. You know how he came to be here in Llewdor, don't you?\""
#message 15 "\"No, I haven't heard that story,\" replies the other lizard. \"How did he get here?\""
#message 16 "\"Well,\" began the other one, \"When he was a baby, he was stolen from his cradle one night by that awful wizard, Manannan, who brought him here and raised him. I hear he treats the boy terribly.\""
#message 17 "\"That's too bad,\" comments the second lizard."
#message 18 "Says one lizard to the other, \"I wish I could do something for the poor boy. He seems so lost and confused.\""
#message 19 "\"I agree. What do you think he is doing here, anyway?\" questions the second lizard."
#message 20 "\"I would guess that he's probably trying to run away from the wizard,\" states the first one. \"I hate to think what will happen to him if Manannan finds him.\""
#message 21 "\"How do you get cactus stickers out of your tail?\" you hear one scaly lizard say to the other. \"I nearly had a brush with disaster this morning.\""
#message 22 "\"That's terrible,\" says the second lizard. \"I know how much they hurt. Best thing is--rub your tail against a rough rock. The stickers should come right out, and possibly your tail with it.\""
#message 23 "They can't understand you."
#message 24 "Maybe if you're quiet, you'll hear them."



