if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 1;  v57 = 77;  v58 = 147;  v32 = 105;  v31 = 147;  v100 = 70;  v101 = 123;  load.logics(Logic104);  object.on.water(o13);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.view(View208);  load.view(View10);  if (v44 == 21)
    {    load.logics(Logic107);    load.view(View190);    load.sound(Sound2);    load.sound(Sound27);    load.sound(Sound1);    load.sound(Sound6);    load.view(View199);    }  else
    {    if ((v127 == 1 ||         v127 == 3) &&         v137 <= 0 &&         v128 != 20)
      {      random(1, 4, v36);      if (v36 == 1)
        {        load.logics(Logic105);        set(f98);        random(6, 12, v125);        }      }    }  animate.obj(o1);  position(o1, 63, 119);  set.view(o1, View208);  set.cel(o1, 0);  stop.cycling(o1);  ignore.blocks(o1);  draw(o1);  stop.update(o1);  if (obj.in.room("Knife", currentRoom))
    {    animate.obj(o2);    position(o2, 62, 92);    set.view(o2, View208);    set.cel(o2, 1);    stop.cycling(o2);    draw(o2);    stop.update(o2);    }  if (obj.in.room("Spoon", currentRoom))
    {    animate.obj(o3);    position(o3, 65, 93);    set.view(o3, View208);    set.cel(o3, 2);    stop.cycling(o3);    draw(o3);    stop.update(o3);    }  if (obj.in.room("Mutton", currentRoom))
    {    animate.obj(o7);    position(o7, 125, 105);    set.view(o7, View208);    set.cel(o7, 3);    stop.cycling(o7);    draw(o7);    stop.update(o7);    }  if (obj.in.room("Bread", currentRoom))
    {    animate.obj(o5);    position(o5, 127, 112);    set.view(o5, View208);    set.cel(o5, 4);    stop.cycling(o5);    draw(o5);    stop.update(o5);    }  if (obj.in.room("Fruit", currentRoom))
    {    animate.obj(o6);    position(o6, 131, 122);    set.view(o6, View208);    set.cel(o6, 5);    stop.cycling(o6);    draw(o6);    stop.update(o6);    }  if (obj.in.room("Bowl", currentRoom))
    {    animate.obj(o4);    position(o4, 32, 74);    set.view(o4, View208);    set.cel(o4, 6);    stop.cycling(o4);    draw(o4);    stop.update(o4);    }  if (v44 == 25)
    {    set(f48);    }  if (isset(f48))
    {    if (previousRoom == 8)
      {      position(ego, 104, 166);      }    else
      {      position.v(ego, v57, v58);      }    }  call(Logic104);  if (isset(f98))
    {    call(Logic105);    }  if (v44 == 21)
    {    load.view(View18);    load.view(View11);    load.view(View35);    reset(f47);    set(f48);    v90 = 2;    set(f46);    set.view(ego, View18);    position(ego, 72, 78);    }  if (isset(f47))
    {    draw(ego);    }  if (v44 == 21)
    {    set(f47);    }  show.pic();  return();  }if (posn(ego, 111, 124, 159, 150))
  {  v39 = 1;  }else
  {  if (posn(ego, 55, 123, 70, 133))
    {    v39 = 3;    }  else
    {    if (posn(ego, 10, 123, 54, 133))
      {      v39 = 2;      }    else
      {      v39 = 0;      }    }  }if (!isset(haveInput))
  {  goto(Label1);  }if (v44 == 21)
  {  print(".won taht od t'nac uoY");  if (!isset(f31))
    {    set(haveMatch);    }  }else
  {  if (v44 == 12)
    {    print("You're too busy sweeping.");    if (!isset(f31))
      {      set(haveMatch);      }    }  else
    {    if ((said("examine", "area") ||         said("examine", "building") ||         said("examine") ||         said("examine", "kitchen")))
      {      print("This is the kitchen of the wizard's house. Other than your own bed "            "chamber, this is the only place in the house that you feel you can "            "call \"your own.\" The wizard rarely enters the kitchen. On cold "            "days, the fireplace is a cozy place to sit.");      }    if ((said("examine", "fireplace") ||         said("look in", "fireplace")))
      {      print("As it is now summer, the need to light a fire and cook hot food "            "was diminished. The fireplace is, at the moment, not burning.");      }    if ((said("examine", "barrel") ||         said("look in", "barrel") ||         said("capture", "barrel")))
      {      print("The barrels only contain foodstuffs. They are too huge to move.");      }    if (said("examine", "counter"))
      {      print("You use the heavy oak table when you prepare food for the wizard.");      if (obj.in.room("Bread", currentRoom) &&           obj.in.room("Fruit", currentRoom) &&           obj.in.room("Mutton", currentRoom))
        {        print("%m11%m7,%m8, and%m9%m12.");        }      else
        {        if (obj.in.room("Bread", currentRoom) &&             obj.in.room("Fruit", currentRoom))
          {          print("%m11%m7 and%m8%m12.");          }        else
          {          if (obj.in.room("Bread", currentRoom) &&               obj.in.room("Mutton", currentRoom))
            {            print("%m11%m7 and%m9%m12.");            }          else
            {            if (obj.in.room("Fruit", currentRoom) &&                 obj.in.room("Mutton", currentRoom))
              {              print("%m11%m8 and%m9%m12.");              }            else
              {              if (obj.in.room("Bread", currentRoom))
                {                print("%m11%m7%m12.");                }              else
                {                if (obj.in.room("Fruit", currentRoom))
                  {                  print("%m11%m8%m12.");                  }                else
                  {                  if (obj.in.room("Mutton", currentRoom))
                    {                    print("%m11%m9%m12.");                    }                  }                }              }            }          }        }      }    if (said("examine", "below", "counter"))
      {      print("It's clean under there.");      }    if ((said("examine", "bookcase") ||         said("examine", "kitchen", "bookcase")))
      {      if (obj.in.room("Bowl", currentRoom))
        {        print("%m19 One useful item that catches your eye is the clay bowl you "              "use for all of your mixing.");        }      else
        {        print("The kitchen shelf holds many ingredients and kitchen implements "              "for cooking.");        }      }    if (said("examine", "chamber pot"))
      {      print("There are pots, pans, and skillets hanging on the wall beside the "            "fireplace.");      }    if ((said("examine", "cage") ||         said("examine", "holder") ||         said("examine", "holder", "cage")))
      {      print("There is an iron rack hanging on the wall by the fireplace.");      if (obj.in.room("Knife", currentRoom))
        {        print("Your trusty knife%m24");        }      if (obj.in.room("Spoon", currentRoom))
        {        print("Your wooden serving spoon%m24");        }      }    if (said("examine", "basket"))
      {      print("There are large baskets hanging from the ceiling beam, and smaller "            "baskets on the kitchen shelves.");      }    if ((said("examine", "butter churn") ||         said("look in", "butter churn")))
      {      print("Looking at the butter churn makes your muscles ache as you "            "remember the long hours churning cream to make butter. Otherwise, "            "you have no interest in it.");      }    if ((said("examine", "bucket") ||         said("look in", "bucket")))
      {      print("It's just your old, oaken bucket.");      }    if ((said("examine", "ceiling") ||         said("examine", "beam")))
      {      print("There are pots, pans, baskets, and drying herbs and spices hanging "            "here.");      }    if (said("examine", "herb"))
      {      print("There are many hanging here. %m35");      }    if ((said("capture", "basket") ||         said("capture", "basket", "from", "cage")))
      {      print("You can think of no use for baskets right now.");      }    if ((said("capture", "chamber pot") ||         said("capture", "chamber pot", "from", "cage")))
      {      print("You are not in the mood for cooking at the moment, so the pots do "            "not interest you.");      }    if (said("capture", "butter churn"))
      {      print("Looking at the butter churn makes your muscles ache as you "            "remember the long hours churning cream to make butter. Otherwise, "            "you have no interest in it.");      }    if ((said("capture", "holder") ||         said("capture", "holder", "from", "cage")))
      {      print("The iron rack is securely attached to the wall. You cannot remove "            "it no matter how hard you try.");      }    if (said("capture", "herb"))
      {      print("You have no use for these particular herbs and spices.");      }    if ((said("capture", "all", "food", "counter") ||         said("capture", "food", "counter") ||         said("capture", "food") ||         said("capture", "all", "food", "from", "counter") ||         said("capture", "food", "from", "counter") ||         said("capture", "all", "food")))
      {      if (!obj.in.room("Bread", currentRoom) &&           !obj.in.room("Fruit", currentRoom) &&           !obj.in.room("Mutton", currentRoom))
        {        print("You already have it.");        }      else
        {        set(f220);        }      }    if ((said("capture", "bread") ||         said("capture", "bread", "from", "counter") ||         said("capture", "bread", "counter")))
      {      set(f221);      }    if ((said("capture", "apple") ||         said("capture", "apple", "from", "counter") ||         said("capture", "apple", "counter")))
      {      set(f222);      }    if ((said("capture", "chop") ||         said("capture", "chop", "from", "counter") ||         said("capture", "chop", "chop", "from", "counter") ||         said("capture", "chop", "chop")))
      {      set(f223);      }    if ((said("capture", "ladle") ||         said("capture", "ladle", "holder") ||         said("capture", "ladle", "from", "holder")))
      {      if (!obj.in.room("Spoon", currentRoom))
        {        print("You already have it.");        }      else
        {        if (v39 != 3)
          {          print("You're too far away.");          }        else
          {          print("You take the wooden spoon from the iron rack and keep it with "                "you.");          get("Spoon");          currentScore  += 1;          start.update(o3);          erase(o3);          }        }      }    if ((said("capture", "dagger") ||         said("capture", "dagger", "holder") ||         said("capture", "dagger", "from", "holder")))
      {      if (!obj.in.room("Knife", currentRoom))
        {        print("You already have it.");        }      else
        {        if (v39 != 3)
          {          print("You're too far away.");          }        else
          {          print("You take the carving knife from the iron rack and keep it with "                "you.");          get("Knife");          currentScore  += 1;          start.update(o2);          erase(o2);          }        }      }    if ((said("capture", "basin", "bookcase") ||         said("capture", "basin", "from", "bookcase") ||         said("capture", "basin")))
      {      if (!obj.in.room("Bowl", currentRoom))
        {        print("You already have it.");        }      else
        {        if (v39 != 2)
          {          print("You're too far away.");          }        else
          {          print("You retrieve the clay bowl from the kitchen shelf and take it "                "with you.");          get("Bowl");          currentScore  += 1;          start.update(o4);          erase(o4);          }        }      }    if ((said("add", "forest", "fireplace") ||         said("capture", "forest")))
      {      print("There is no need for you to start a fire in the fireplace, as it "            "is now summer and warm outside.");      }    if ((said("begin", "fire", "fireplace") ||         said("form", "fire", "fireplace") ||         said("begin", "fire") ||         said("burn", "fire") ||         said("form", "fire") ||         said("burn", "fire", "fireplace")))
      {      print("There is no need for you to start a fire in the fireplace, as it "            "is now summer and warm outside.");      }    if (!isset(f46) &&         (said("clean", "deck", "try", "broom") ||         said("clean", "deck") ||         said("clean", "kitchen") ||         said("clean", "kitchen", "try", "broom") ||         said("try", "broom", "clean", "kitchen") ||         said("try", "broom", "clean", "deck") ||         said("try", "broom", "clean", "area") ||         said("clean", "kitchen", "deck") ||         said("clean", "area") ||         said("clean", "area", "try", "broom") ||         said("capture", "broom")))
      {      if (v39 != 3)
        {        print("You're too far away.");        }      else
        {        start.update(o1);        erase(o1);        set(f46);        block(36, 120, 121, 154);        get.posn(ego, v78, v79);        v221 = 26;        v44 = 12;        set.view(ego, View10);        program.control();        set(f35);        v222 = 0;        v224 = 22;        if (v137 == 1)
          {          v137 = 0;          v110 = 0;          v109 = 0;          }        }      }    }  }Label1:if ((isset(f220) ||     isset(f221)))
  {  reset(f221);  if (obj.in.room("Bread", currentRoom))
    {    if (v39 != 1)
      {      reset(f220);      print("You aren't near the table.");      }    else
      {      print("You take the loaf of bread and carry it with you.");      get("Bread");      currentScore  += 1;      start.update(o5);      erase(o5);      }    }  else
    {    if (!isset(f220))
      {      print("You already have it.");      }    }  if (isset(f220))
    {    set(f222);    }  }if ((isset(f220) ||     isset(f222)))
  {  reset(f222);  if (obj.in.room("Fruit", currentRoom))
    {    if (v39 != 1)
      {      reset(f220);      print("You aren't near the table.");      }    else
      {      print("You take the fruit and carry it with you.");      get("Fruit");      currentScore  += 1;      start.update(o6);      erase(o6);      }    }  else
    {    if (!isset(f220))
      {      print("You already have it.");      }    }  if (isset(f220))
    {    set(f223);    }  }if ((isset(f220) ||     isset(f223)))
  {  reset(f223);  if (obj.in.room("Mutton", currentRoom))
    {    if (v39 != 1)
      {      reset(f220);      print("You aren't near the table.");      }    else
      {      print("You take the mutton chop and carry it with you.");      get("Mutton");      currentScore  += 1;      start.update(o7);      erase(o7);      }    }  else
    {    if (!isset(f220))
      {      print("You already have it.");      }    }  reset(f220);  }if (v44 == 12)
  {  if (isset(f45))
    {    --v221;    if (v221 == 1)
      {      v221 = 0;      v222 = 0;      v224 = 0;      unblock();      ignore.blocks(ego);      ignore.objs(ego);      move.obj(ego, 64, 125, 1, f229);      }    }  --v222;  if (v222 == 1)
    {    start.motion(ego);    wander(ego);    random(11, 33, v224);    }  --v224;  if (v224 == 1)
    {    normal.motion(ego);    stop.motion(ego);    set.loop(ego, 2);    random(11, 33, v222);    }  }if (isset(f229))
  {  reset(f229);  reset(f46);  player.control();  observe.blocks(ego);  observe.objs(ego);  set.view(ego, View0);  reset(f35);  normal.motion(ego);  v44 = 0;  draw(o1);  }if (isset(f33))
  {  accept.input();  reset(f36);  reset(f37);  reset(f38);  if (v44 == 21)
    {    program.control();    stop.motion(ego);    print("You feel the blood rushing to your head as you realize that you are "          "upside-down. Straining to look up, you notice your feet have been "          "magically attached to a kitchen rafter. You struggle, but can't "          "release yourself. What a vexing situation!");    v59 = 2;    cycle.time(ego, v59);    v223 = 23;    }  }if (v44 == 21)
  {  --v223;  if (v223 == 12)
    {    set(f35);    }  if (v223 == 1)
    {    reset(f35);    v223 = 44;    }  }if (isset(f123))
  {  reset(f123);  ignore.blocks(ego);  ignore.objs(ego);  set.priority(ego, 15);  v44 = 6;  prevent.input();  program.control();  set.view(ego, View11);  v37 = 4;  v38 = 0;  reposition(ego, v37, v38);  set(f35);  v223 = 0;  v59 = 1;  cycle.time(ego, v59);  v38 = 134;  v69 = 3;  sound(Sound1, f41);  move.obj.v(ego, v40, v38, v69, f225);  }if (isset(f225))
  {  reset(f225);  v44 = 18;  set.view(ego, View35);  release.priority(ego);  stop.motion(ego);  prevent.input();  program.control();  set(f35);  v220 = 5;  set(f224);  }if (isset(f45))
  {  --v225;  if (v225 == 1)
    {    set(f228);    }  --v220;  if (v220 == 1)
    {    v44 = 0;    player.control();    accept.input();    reset(f46);    reset(f35);    reset(f224);    stop.sound();    start.motion(ego);    set.view(ego, View0);    discard.view(View35);    discard.view(View11);    discard.view(View18);    print("You feel dizzy and nauseated at the sudden changes in body position. "          "It's at least some consolation to find yourself on the floor again.");    observe.blocks(ego);    observe.objs(ego);    }  }if (isset(f224) &&     v44 == 18)
  {  sound(Sound6, f224);  }if (v222 <= 0 &&     v221 <= 0 &&     edgeEgoHit == BOTTOM_EDGE &&     v44 != 125 &&     v40 > 99 &&     v40 < 113)
  {  new.room(Logic8);  }call(Logic104);if (isset(f98))
  {  call(Logic105);  }return();[ Messages#message 1 "This is the kitchen of the wizard's house. Other than your own bed chamber, this is the only place in the house that you feel you can call \"your own.\" The wizard rarely enters the kitchen. On cold days, the fireplace is a cozy place to sit."#message 2 "Near the fireplace is a crude broom made of straw."#message 3 "As it is now summer, the need to light a fire and cook hot food was diminished. The fireplace is, at the moment, not burning."#message 4 "There is no need for you to start a fire in the fireplace, as it is now summer and warm outside."#message 5 "You use the heavy oak table when you prepare food for the wizard."#message 6 "%m11%m7,%m8, and%m9%m12."#message 7 " a loaf of bread"#message 8 " some fruit"#message 9 " a mutton chop"#message 10 "%m11%m7%m12."#message 11 "Right now, there is"#message 12 " on the table"#message 13 "%m11%m8%m12."#message 14 "%m11%m9%m12."#message 15 "%m11%m7 and%m8%m12."#message 16 "%m11%m7 and%m9%m12."#message 17 "%m11%m8 and%m9%m12."#message 18 "%m19 One useful item that catches your eye is the clay bowl you use for all of your mixing."#message 19 "The kitchen shelf holds many ingredients and kitchen implements for cooking."#message 20 "There are pots, pans, and skillets hanging on the wall beside the fireplace."#message 21 "There is an iron rack hanging on the wall by the fireplace."#message 22 "Your trusty knife%m24"#message 23 "Your wooden serving spoon%m24"#message 24 " is hanging on the rack."#message 25 "It's clean under there."#message 26 ""#message 27 ""#message 28 ""#message 29 "There are large baskets hanging from the ceiling beam, and smaller baskets on the kitchen shelves."#message 30 "Looking at the butter churn makes your muscles ache as you remember the long hours churning cream to make butter. Otherwise, you have no interest in it."#message 31 "There are pots, pans, baskets, and drying herbs and spices hanging here."#message 32 "You can think of no use for baskets right now."#message 33 "You are not in the mood for cooking at the moment, so the pots do not interest you."#message 34 "The iron rack is securely attached to the wall. You cannot remove it no matter how hard you try."#message 35 "You have no use for these particular herbs and spices."#message 36 "The barrels only contain foodstuffs. They are too huge to move."#message 37 ""#message 38 "You take the loaf of bread and carry it with you."#message 39 ""#message 40 "You take the fruit and carry it with you."#message 41 ""#message 42 "You take the mutton chop and carry it with you."#message 43 ""#message 44 "You take the wooden spoon from the iron rack and keep it with you."#message 45 "You already have it."#message 46 "You take the carving knife from the iron rack and keep it with you."#message 47 ""#message 48 "You retrieve the clay bowl from the kitchen shelf and take it with you."#message 49 ""#message 50 ""#message 51 ""#message 52 ""#message 53 "Using your fingers?"#message 54 "You feel the blood rushing to your head as you realize that you are upside-down. Straining to look up, you notice your feet have been magically attached to a kitchen rafter. You struggle, but can't release yourself. What a vexing situation!"#message 55 ""#message 56 ""#message 57 "You aren't near the table."#message 58 "You're too far away."#message 59 "There are many hanging here. %m35"#message 60 "You feel dizzy and nauseated at the sudden changes in body position. It's at least some consolation to find yourself on the floor again."#message 61 ".won taht od t'nac uoY"#message 62 "You're too busy sweeping."#message 63 "It's just your old, oaken bucket."