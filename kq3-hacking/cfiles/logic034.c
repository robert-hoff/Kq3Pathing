if (isset(newRoom))
  {  if ((v76 > 0 ||       v75 > 0) &&       previousRoom == 7)
    {    v72 = previousRoom;    new.room(Logic87);    }  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 1;  v57 = 108;  v58 = 121;  v31 = 0;  v101 = 0;  load.logics(Logic104);  load.logics(Logic103);  v34 = 166;  set.horizon(93);  random(1, 2, v36);  if (has("Dough in Ears") &&       v36 == 1 &&       (!isset(f135) ||       !isset(f136) ||       !isset(f137) ||       !isset(f138)))
    {Label1:    random(1, 4, v36);    if (v36 == 1)
      {      if (isset(f135))
        {        goto(Label1);        }      else
        {        v232 = 135;        v229 = 33;        v230 = 35;        }      }    if (v36 == 2)
      {      if (isset(f136))
        {        goto(Label1);        }      else
        {        v232 = 136;        v229 = 36;        v230 = 37;        }      }    if (v36 == 3)
      {      if (isset(f137))
        {        goto(Label1);        }      else
        {        v232 = 137;        v229 = 38;        v230 = 39;        }      }    if (v36 == 4)
      {      if (isset(f138))
        {        goto(Label1);        }      else
        {        v232 = 138;        v229 = 40;        v230 = 43;        }      }    random(3, 10, v226);    }  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.view(View96);  load.view(View11);  load.view(View205);  load.view(View206);  load.view(View21);  load.view(View20);  animate.obj(o3);  position(o3, 38, 129);  set.view(o3, View96);  set.loop(o3, 0);  set.cel(o3, 0);  draw(o3);  stop.update(o3);  animate.obj(o4);  ignore.blocks(o4);  ignore.objs(o4);  position(o4, 92, 129);  set.view(o4, View96);  set.loop(o4, 1);  set.cel(o4, 0);  set.priority(o4, 10);  draw(o4);  stop.update(o4);  animate.obj(o1);  position(o1, 123, 123);  set.view(o1, View205);  draw(o1);  wander(o1);  v222 = 33;  animate.obj(o2);  position(o2, 120, 133);  set.view(o2, View205);  draw(o2);  wander(o2);  v221 = 44;  animate.obj(o5);  set.view(o5, View21);  set.loop(o5, 1);  set.cel(o5, 0);  set.priority(o5, 10);  position(o5, 97, 114);  ignore.objs(o5);  ignore.blocks(o5);  if (v44 == 30)
    {    set(f48);    }  if (isset(f48))
    {    if (previousRoom == 7)
      {      position(ego, 39, 131);      }    else
      {      if (previousRoom == 33)
        {        position(ego, 57, 167);        }      else
        {        position.v(ego, v57, v58);        }      }    }  if (isset(f47))
    {    draw(ego);    }  observe.blocks(ego);  call(Logic104);  reset(f34);  call(Logic103);  show.pic();  return();  }v39 = 0;if (posn(ego, 32, 130, 47, 137))
  {  v39 = 3;  }else
  {  if (posn(ego, 87, 101, 98, 106))
    {    v39 = 2;    }  else
    {    if (posn(ego, 93, 116, 100, 135))
      {      v39 = 4;      }    else
      {      if (posn(ego, 81, 116, 87, 135))
        {        v39 = 5;        }      }    }  }if (!isset(haveInput))
  {  goto(Label2);  }if ((said("examine", "bluff") ||     said("examine") ||     said("examine", "area") ||     said("examine", "abominable")))
  {  print("The lone mountain rises from the forests of Llewdor to this "        "cloud-encircled peak. Here is the somber house of Manannan, where you "        "and he reside.");  }if ((said("examine", "path") ||     said("examine", "down", "path")))
  {  print("The treacherous path is the only route down the mountain. If you are "        "contemplating taking it, you should be very cautious.");  }if ((said("examine", "forest") ||     said("examine", "flower") ||     said("capture", "flower") ||     said("climb", "forest") ||     said("examine", "brush")))
  {  print("The foliage is very scant on this steep mountainside.");  }if ((said("examine", "sky") ||     said("examine", "up", "sky")))
  {  print("The sky is dark here due to the swirling clouds surrounding this "        "summit.");  }if ((said("examine", "cloud") ||     said("examine", "up", "cloud") ||     said("examine", "sky") ||     said("examine", "cloud", "sky") ||     said("examine", "up", "cloud", "sky")))
  {  print("Dark clouds surround this peak adding a cold, sinister feeling to this "        "lonely mountain.");  }if ((said("climb", "bluff") ||     said("climb", "down", "bluff")))
  {  print("The mountain is too steep to climb. Use the path.");  }if (said("examine", "deck"))
  {  print("The ground is hard and rocky on this lonely mountaintop.");  }if ((said("examine", "building") ||     said("examine", "glass") ||     said("look in", "glass") ||     said("examine", "glass", "building")))
  {  print("This is the gloomy home of Manannan, the evil wizard who is your "        "master.");  }if ((said("examine", "door") ||     said("examine", "door", "building")))
  {  print("The door of the wizard's house is closed at the moment.");  }if ((said("bang", "door") ||     said("bang", "door", "building") ||     said("bang", "on", "door") ||     said("bang", "on", "building", "door")))
  {  print("Why don't you just open it; you DO live here.");  }if ((said("lift", "door") ||     said("lift", "door", "building")))
  {  if (v39 == 3)
    {    if (!isset(f46))
      {      set(f46);      start.update(o3);      end.of.loop(o3, f222);      }    else
      {      print("Not now!");      }    }  else
    {    print("Your arms are not long enough to reach it from here.");    }  }if ((said("examine", "bird") ||     said("examine", "bird", "cage") ||     said("examine", "cage") ||     said("look in", "cage") ||     said("look in", "bird", "cage") ||     said("examine", "inside", "cage")))
  {  if (v225 <= 0)
    {    print("A couple of chickens strut about their chicken coop. As all chickens "          "do, they peck, scratch, and cluck. The poor things; they will end up "          "as the old wizard's dinner one day. %m25");    }  else
    {    print("The chicken struggles in your arms, trying to peck you. Apparently, "          "it doesn't enjoy being held.");    }  }if (said("call", "bird"))
  {  print("The chickens pay no attention to you.");  }if (said("kill", "bird"))
  {  print("You never were very good at doing that. You'd really rather not.");  }if (has("Dough in Ears") &&     said("hear", "bird"))
  {  print("Shhh.  If you're quiet, perhaps you'll hear them.");  }if ((said("examine", "gate") ||     said("examine", "gate", "cage")))
  {  print("The gate is closed.");  }if ((said("lift", "gate") ||     said("lift", "gate", "cage")))
  {  if (v39 != 5 &&       v39 != 4)
    {    print("Your arms are not long enough to reach it from here.");    }  else
    {    if (v225 > 0)
      {      set(f221);      print("The chicken flies out of your grasp, and again struts around the "            "coop.");      }    set(f122);    v224 = 0;    }  }if ((said("capture", "bird") ||     said("capture", "bird")))
  {  if (!isset(f227))
    {    print("You cannot reach the chickens.");    }  else
    {    if (v225 > 0)
      {      print("What's wrong with the chicken you're holding?");      }    else
      {      distance(o1, ego, v36);      if (v36 < 10)
        {        get.posn(o1, v227, v228);        v225 = 1;        erase(o1);        }      if (v225 <= 0)
        {        distance(o2, ego, v36);        if (v36 < 10)
          {          get.posn(o2, v227, v228);          v225 = 2;          erase(o2);          }        }      if (v225 <= 0)
        {        print("The little varmint scoots out of reach.");        }      else
        {        set(f46);        set.view(ego, View20);        print("Gotcha! You've managed to catch a chicken. But, what are you "              "going to do with it?");        }      }    }  }if (v225 > 0 &&     (said("add", "bird") ||     said("add", "bird", "down") ||     said("throw", "bird")))
  {  set(f221);  }if ((said("capture", "feather") ||     said("capture", "feather", "from", "bird") ||     said("capture", "bird", "feather") ||     said("pluck", "bird") ||     said("pluck", "feather") ||     said("pluck", "bird", "feather") ||     said("pluck", "feather", "from", "bird") ||     said("move", "feather") ||     said("move", "bird", "feather") ||     said("move", "feather", "from", "bird")))
  {  if (!obj.in.room("Chicken Feather*", currentRoom))
    {    print("You already took a chicken feather.");    }  else
    {    if (v225 <= 0)
      {      print("You have to catch a chicken first.");      }    else
      {      get("Chicken Feather*");      currentScore  += 1;      set(f221);      print("Tucking the chicken firmly under one arm, you gently pluck a small "            "feather, then let it go.");      }    }  }if ((said("examine", "bag") ||     said("look in", "bag") ||     said("examine", "feed", "bag") ||     said("look in", "feed", "bag") ||     said("examine", "bag", "feed") ||     said("look in", "bag", "feed") ||     said("examine", "bird", "feed", "bag") ||     said("look in", "bird", "feed", "bag") ||     said("examine", "bag", "bird", "feed") ||     said("look in", "bag", "bird", "feed")))
  {  if (v39 != 2)
    {    print("There is a bag of chicken feed behind the fence, beside the chicken "          "coop.");    }  else
    {    print("The bag behind the fence is full of chicken feed.");    }  }if (said("drink", "bird"))
  {  print("Sorry, Colonel; they're not even dead yet!");  }if ((said("capture", "feed") ||     said("capture", "feed", "bag") ||     said("capture", "feed", "from", "bag") ||     said("capture", "flour") ||     said("capture", "flour", "bag") ||     said("capture", "flour", "from", "bag") ||     said("capture", "bird", "feed") ||     said("capture", "bird", "feed", "bag") ||     said("capture", "bird", "feed", "from", "bag")))
  {  print("You only need the chicken feed if you want to feed the chickens.");  }if ((said("feed", "bird") ||     said("capture", "feed", "feed", "bird") ||     said("capture", "bird", "feed", "feed", "bird") ||     said("feed", "bird", "feed") ||     said("feed", "feed", "bird") ||     said("capture", "feed", "throw", "bird") ||     said("throw", "feed", "bird") ||     said("feed", "feed") ||     said("throw", "feed") ||     said("capture", "bird", "feed", "feed", "bird") ||     said("feed", "bird", "bird", "feed") ||     said("feed", "bird", "feed", "bird") ||     said("capture", "bird", "feed", "throw", "bird") ||     said("throw", "bird", "feed", "bird") ||     said("feed", "bird", "feed") ||     said("throw", "bird", "feed")))
  {  if (v39 != 2)
    {    print("You can't reach it from here.");    }  else
    {    if (isset(f46))
      {      print("Not now!");      }    else
      {      set(f46);      program.control();      stop.motion(ego);      reposition.to(ego, 95, 104);      v220 = 0;      set(f228);      set(f35);      set.view(ego, View21);      set.loop(ego, 0);      v36 = 2;      cycle.time(ego, v36);      v222 = 0;      v221 = 0;      follow.ego(o1, 8, f223);      follow.ego(o2, 10, f224);      ignore.objs(o2);      v223 = 17;      if (v137 == 5)
        {        v137 = 0;        v110 = 0;        v109 = 0;        }      }    }  }Label2:if (isset(f45))
  {  --v223;  if (v223 == 1)
    {    v223 = 0;    v231 = 11;    set.view(ego, View0);    start.motion(ego);    reset(f35);    player.control();    reset(f46);    cycle.time(ego, v59);    reset(f228);    v220 = 0;    reset(noScript);    erase(o5);    }  --v231;  if (v231 == 1)
    {    reset(f225);    reset(f226);    observe.objs(o1);    observe.objs(o2);    v222 = 2;    v221 = 2;    }  }if (v223 > 0)
  {  if (isset(f228))
    {    reset(f228);    ++v220;    if (v220 == 1)
      {      set.cel(ego, 0);      set(f35);      end.of.loop(ego, f228);      }    if (v220 == 2)
      {      reset(f35);      set.cel(o5, 0);      draw(o5);      end.of.loop(o5, f228);      }    if (v220 == 3)
      {      v67 = 21;      v64 = 2;      v65 = 0;      random(93, 99, v37);      random(111, 116, v38);      v66 = 10;      v36 = 4;      add.to.pic.v(v67, v64, v65, v37, v38, v66, v36);      v220 = 0;      set(f228);      set(noScript);      }    }  }if (isset(f223))
  {  reset(f223);  stop.motion(o1);  set(f225);  set.view(o1, View206);  }if (isset(f224))
  {  reset(f224);  stop.motion(o2);  set(f226);  set.view(o2, View206);  observe.objs(o2);  }--v222;if (v222 == 22)
  {  normal.motion(o1);  stop.motion(o1);  set.view(o1, View206);  }if (v222 == 1)
  {  v222 = 33;  set.view(o1, View205);  wander(o1);  }--v221;if (v221 == 15)
  {  normal.motion(o2);  stop.motion(o2);  set.view(o2, View206);  }if (v221 == 1)
  {  v221 = 44;  set.view(o2, View205);  wander(o2);  }if (isset(f45) &&     v229 > 0 &&     v44 == 0 &&     v47 == v226)
  {  v226 = 0;  set.v(v232);Label3:  print.v(v229);  if (v229 < v230)
    {    ++v229;    goto(Label3);    }  }if (isset(f122))
  {  reset(f122);  ++v224;  program.control();  if (v224 == 1)
    {    start.update(o4);    end.of.loop(o4, f41);    ignore.blocks(ego);    set(f46);    if (v39 == 5)
      {      v233 = 84;      v234 = 125;      v235 = 96;      v236 = 125;      set(f227);      }    else
      {      if (v39 == 4)
        {        v233 = 96;        v234 = 125;        v235 = 84;        v236 = 125;        reset(f227);        }      }    v69 = 1;    move.obj.v(ego, v233, v234, v69, f122);    }  if (v224 == 2)
    {    move.obj.v(ego, v235, v236, v69, f122);    }  if (v224 == 3)
    {    observe.blocks(ego);    reverse.loop(o4, f122);    }  if (v224 == 4)
    {    reset(f46);    player.control();    v224 = 0;    }  }if (isset(f222))
  {  reset(f222);  reset(f46);  set(f220);  }if (isset(egoHitSpecial))
  {  v33 = 6;  if (v41 < 138)
    {    set.priority(ego, 5);    v34 = 146;    }  else
    {    set.priority(ego, 14);    v34 = 166;    }  call(Logic103);  }if (isset(f221))
  {  reset(f221);  reset(f46);  set.view(ego, View0);  force.update(ego);  if (v225 == 1)
    {    position.v(o1, v227, v228);    draw(o1);    }  else
    {    position.v(o2, v227, v228);    draw(o2);    }  v225 = 0;  }if (isset(f33))
  {  set(f227);  }call(Logic104);call(Logic103);if (isset(f220))
  {  new.room(Logic7);  }if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic33);  }return();[ Messages#message 1 "Not now!"#message 2 "The lone mountain rises from the forests of Llewdor to this cloud-encircled peak. Here is the somber house of Manannan, where you and he reside."#message 3 "The treacherous path is the only route down the mountain. If you are contemplating taking it, you should be very cautious."#message 4 "The foliage is very scant on this steep mountainside."#message 5 "The sky is dark here due to the swirling clouds surrounding this summit."#message 6 "Dark clouds surround this peak adding a cold, sinister feeling to this lonely mountain."#message 7 "The mountain is too steep to climb. Use the path."#message 8 "The ground is hard and rocky on this lonely mountaintop."#message 9 "This is the gloomy home of Manannan, the evil wizard who is your master."#message 10 "You can't reach it from here."#message 11 "The door of the wizard's house is closed at the moment."#message 12 "Why don't you just open it; you DO live here."#message 13 "Your arms are not long enough to reach it from here."#message 14 "A couple of chickens strut about their chicken coop. As all chickens do, they peck, scratch, and cluck. The poor things; they will end up as the old wizard's dinner one day. %m25"#message 15 "The gate is closed."#message 16 "Shhh.  If you're quiet, perhaps you'll hear them."#message 17 "You cannot reach the chickens."#message 18 "The little varmint scoots out of reach."#message 19 "Gotcha! You've managed to catch a chicken. But, what are you going to do with it?"#message 20 "The chicken flies out of your grasp, and again struts around the coop."#message 21 "You have to catch a chicken first."#message 22 "Tucking the chicken firmly under one arm, you gently pluck a small feather, then let it go."#message 23 "The chicken struggles in your arms, trying to peck you. Apparently, it doesn't enjoy being held."#message 24 "You already took a chicken feather."#message 25 "There is a bag of chicken feed behind the fence, beside the chicken coop."#message 26 "The bag behind the fence is full of chicken feed."#message 27 "You only need the chicken feed if you want to feed the chickens."#message 28 ""#message 29 "What's wrong with the chicken you're holding?"#message 30 "The chickens pay no attention to you."#message 31 "You never were very good at doing that. You'd really rather not."#message 32 "Sorry, Colonel; they're not even dead yet!"#message 33 "\"The poor boy,\" clucks one of the hens. \"He thinks his name is Gwydion.\""#message 34 "\"Wouldn't he be surprised to find out he's a prince!\" replies the other hen."#message 35 "\"Yes,\" cackles the first hen. \"He's really Prince Alexander.\""#message 36 "You hear one chicken say to the other, \"I feel so sorry for the boy. The old wizard treats him miserably.\""#message 37 "\"Yes, dear,\" replies the other one, \"but YOU ought to worry about your own neck. Look at the situation WE'RE in.\""#message 38 "\"Remember Gertrude,\" one of the chickens reminisces. \"Remember how one day the old wizard came out and got her.\""#message 39 "\"Oh, I know,\" clucks the other. \"It was horrible! I hear she ended up in his stew. I can't bear to think about it!\" "#message 40 "You overhear one of the hens speaking to the other, \"Whatever happened to your last batch of chicks, my dear?\""#message 41 "Answers the other, \"My poor babies were doing so well! I was just teaching them the proper methods of scratching when that old rascal came out and took them away!\""#message 42 "\"Where do you think he took them?\" wondered the first hen."#message 43 "\"I hate to think,\" the distraught mother hen replies. \"I just heard them peeping as they were carried off.\""