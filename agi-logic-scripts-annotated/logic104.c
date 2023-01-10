if (isset(newRoom))
  {  set(f34);  v240 = 0;  if (currentRoom == 8 &&       v137 == 3)
    {    return();    }  random(1, 3, v36);  if (v36 == 1 &&       v101 > 0 &&       !isset(f116) &&       !isset(f98))
    {    load.view(View203);    load.view(View204);    load.view(View19);    load.sound(Sound13);    animate.obj(o13);    set.view(o13, View204);    set.cel(o13, 0);    position.v(o13, v100, v101);    draw(o13);    stop.motion(o13);    v36 = 3;    cycle.time(o13, v36);    set(f116);    if ((currentRoom == 9 ||         currentRoom == 5 ||         currentRoom == 6))
      {      object.on.water(o13);      }    else
      {      object.on.anything(o13);      }    v240 = 250;    v241 = 2;    }  else
    {    reset(f116);    }  }if ((said("break", "glass") ||     said("break", "lift", "glass")))
  {  print("You don't need to break windows. Use the front door.");  }if ((said("examine", "out", "glass") ||     said("examine", "glass") ||     said("examine", "out") ||     said("look in", "glass")))
  {  if ((v76 > 0 ||       v75 > 0))
    {    print("A horribly intense thunderstorm is raging outside.");    }  else
    {    if (currentRoom < 9)
      {      print("You can see most of the countryside of Llewdor from this vantage "            "point.");      }    else
      {      print("What window?");      }    }  }if (said("lift", "glass"))
  {  if (currentRoom < 9)
    {    print("These windows do not open.");    }  else
    {    print("What window?");    }  }if (!isset(f116))
  {  goto(Label1);  }if (said("examine", "cat"))
  {  print("That detestable pet of Manannan's is a constant annoyance.");  }if (said("call", "cat"))
  {  if (has("Dough in Ears"))
    {    print("\"Get lost, Gwydion, you creep!\"");    }  else
    {    random(16, 18, v36);    print.v(v36);    }  }if ((said("embrace", "cat") ||     said("pat", "cat")))
  {  print("The thought of doing anything nice to that obscene ball of fur makes "        "you sick.");  set(f242);  v240 = 88;  }if (said("hit", "cat"))
  {  distance(ego, o13, v36);  if (v36 > 11)
    {    if (has("Dough in Ears"))
      {      print("\"Ha, ha! Missed me!!\"");      }    else
      {      print("You're too far away.");      }    }  else
    {    sound(Sound13, f41);    if (has("Dough in Ears"))
      {      random(24, 26, v36);      print.v(v36);      }    else
      {      print("\"Screeeeeeeeeeeeech!!!!!!!!\"");      }    print("(heh, heh, heh)");    set(f242);    v240 = 88;    }  }if (said("kill", "cat"))
  {  print("Good idea, but how? As much as you'd love to, you haven't the heart.");  set(f242);  v240 = 88;  }if (v44 != 0)
  {  goto(Label1);  }if (!isset(f46) &&     (said("capture", "cat") ||     said("carry", "cat") ||     said("capture", "cat")))
  {  distance(ego, o13, v36);  if (v36 > 8)
    {    if (has("Dough in Ears"))
      {      print("%m5 As he does so he snickers, \"Ha, ha! Missed me!\"");      }    else
      {      print("You're too far away.");      }    }  else
    {    random(1, 4, v36);    if (v36 > 1)
      {      print("The despicable cat slips away from your grasp with a fierce "            "scratch to your arm.");      set(f242);      v240 = 88;      }    else
      {      set(f46);      erase(o13);      v240 = 0;      v241 = 0;      set.view(ego, View19);      start.motion(ego);      egoDir = STOPPED;      set(f240);      set(f35);      print("Nimbly, you grab the nasty cat by the scruff of its neck, avoiding "            "its needle-sharp claws. Now that you have it, what are you going "            "to do with it?");      }    }  }if (said("add", "cat"))
  {  if (!isset(f240))
    {    print("You don't have it.");    }  else
    {    set(f241);    }  }if ((said("capture", "fur", "cat") ||     said("capture", "cat", "fur") ||     said("capture", "fur") ||     said("move", "fur") ||     said("move", "cat", "fur") ||     said("move", "fur", "cat") ||     said("capture", "cat", "fur", "from", "cat") ||     said("capture", "fur", "from", "cat") ||     said("move", "fur", "from", "cat") ||     said("move", "cat", "fur", "from", "cat") ||     said("move", "fur", "cat", "from", "cat")))
  {  if (!isset(f240))
    {    print("You don't have the cat.");    }  else
    {    get("Cat Hair*");    sound(Sound13, f41);    print("\"Screeeeeeeeeeeeech!!!!!!!!\"");    print("(heh, heh, heh)");    if (has("Dough in Ears"))
      {      random(24, 27, v36);      print.v(v36);      }    if (!isset(f128))
      {      set(f128);      currentScore  += 1;      print("You manage to pluck some fur before he viciously scratches, and "            "leaps from your arms. With grim satisfaction, you survey your "            "wounds. \"Stupid cat,\" you scoff, \"whether you know it or not, "            "you just helped me.\"");      }    set(f241);    }  }Label1:if (!isset(f240) &&     isset(f116))
  {  --v240;  if (!isset(f243))
    {    --v241;    if (v241 < 19)
      {      start.cycling(o13);      }    if (v241 == 1)
      {      v241 = 150;      stop.cycling(o13);      }    }  if (v240 == 19)
    {    set(f242);    }  if (v240 == 1)
    {    reset(f243);    v240 = 250;    normal.motion(o13);    stop.motion(o13);    stop.cycling(o13);    set.view(o13, View204);    set.cel(o13, 0);    v36 = 3;    cycle.time(o13, v36);    }  }if (isset(f240) &&     egoDir > STOPPED)
  {  set(f241);  }if (isset(f241))
  {  reset(f241);  reset(f240);  reset(f35);  reset(f46);  set.view(ego, View0);  force.update(ego);  draw(o13);  set(f242);  v240 = 88;  print("The detestable cat leaps from your arms, snarling and screeching!");  }if (isset(f242) &&     !isset(f240) &&     isset(f116))
  {  reset(f242);  set(f243);  set.view(o13, View203);  v36 = 1;  cycle.time(o13, v36);  start.cycling(o13);  start.motion(o13);  wander(o13);  }return();[ Messages#message 1 "You don't need to break windows. Use the front door."#message 2 "That detestable pet of Manannan's is a constant annoyance."#message 3 "The thought of doing anything nice to that obscene ball of fur makes you sick."#message 4 "You're too far away."#message 5 "The despicable cat slips away from your grasp with a fierce scratch to your arm."#message 6 "A horribly intense thunderstorm is raging outside."#message 7 "Good idea, but how? As much as you'd love to, you haven't the heart."#message 8 "Nimbly, you grab the nasty cat by the scruff of its neck, avoiding its needle-sharp claws. Now that you have it, what are you going to do with it?"#message 9 "You don't have it."#message 10 "The detestable cat leaps from your arms, snarling and screeching!"#message 11 "You don't have the cat."#message 12 "\"Screeeeeeeeeeeeech!!!!!!!!\""#message 13 "(heh, heh, heh)"#message 14 "\"Get lost, Gwydion, you creep!\""#message 15 "%m5 As he does so he snickers, \"Ha, ha! Missed me!\""#message 16 "The cat's only response is an arched back and a hiss."#message 17 "The cat stares at you with cold eyes, his tail twitching slightly."#message 18 "Manannan's pet totally ignores you as you speak to him."#message 19 "You manage to pluck some fur before he viciously scratches, and leaps from your arms. With grim satisfaction, you survey your wounds. \"Stupid cat,\" you scoff, \"whether you know it or not, you just helped me.\""#message 20 "You can see most of the countryside of Llewdor from this vantage point."#message 21 "What window?"#message 22 "These windows do not open."#message 23 "\"Ha, ha! Missed me!!\""#message 24 "\"HEY! That hurt!!\""#message 25 "\"Ow! I'll get you for that, Gwydion!\""#message 26 "\"Wait till I catch you on the steps, you creep!\""#message 27 "\"The next scratch is gonna be on your jug'lar, Chicken Boy!!\""