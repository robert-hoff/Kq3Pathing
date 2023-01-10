if (isset(newRoom))
{  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 1;  v57 = 120;  v58 = 143;  v32 = 29;  v31 = 140;  v100 = 131;  v101 = 144;  load.logics(Logic104);  if ((v127 == 1 ||    v127 == 3) &&    v128 != 20)
  {    if (v137 == 3)
    {      set(f220);      set(f98);      set(f221);      load.logics(Logic105);      v125 = 0;      load.view(View197);    }    else
    {      random(1, 2, v36);      if (v137 <= 0 &&        v36 == 1)
      {        set(f98);        load.logics(Logic105);        random(6, 12, v125);      }    }  }  load.view(View208);  load.view(View34);  load.view(View230);  load.view(View177);  load.sound(Sound2);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  animate.obj(o5);  ignore.blocks(o5);  ignore.objs(o5);  position(o5, 90, 121);  set.view(o5, View208);  set.priority(o5, 12);  stop.cycling(o5);  animate.obj(o1);  ignore.horizon(o1);  position(o1, 75, 81);  set.priority(o1, 13);  set.view(o1, View230);  set.cel(o1, 0);  draw(o1);  animate.obj(o2);  ignore.horizon(o2);  position(o2, 91, 81);  set.priority(o2, 13);  set.view(o2, View230);  set.cel(o2, 1);  draw(o2);  animate.obj(o3);  ignore.horizon(o3);  position(o3, 92, 75);  set.priority(o3, 12);  set.view(o3, View230);  set.cel(o3, 1);  draw(o3);  animate.obj(o4);  ignore.horizon(o4);  position(o4, 78, 75);  set.priority(o4, 12);  set.view(o4, View230);  set.cel(o4, 0);  draw(o4);  if (obj.in.room("Empty Cup", currentRoom))
  {    animate.obj(o6);    ignore.blocks(o6);    ignore.objs(o6);    position(o6, 72, 123);    set.view(o6, View177);    set.priority(o6, 12);    draw(o6);    stop.update(o6);  }  if ((isset(f48) ||    v44 == 25))
  {    if (previousRoom == 7)
    {      position(ego, 26, 138);    }    else
    {      if (previousRoom == 6)
      {        position(ego, 104, 121);      }      else
      {        position.v(ego, v57, v58);      }    }  }  if (isset(f47))
  {    draw(ego);  }  call(Logic104);  if (isset(f98))
  {    call(Logic105);    if (isset(f220))
    {      v128 = 106;      ignore.objs(o15);      set.view(o15, View197);      position(o15, 90, 119);      v32 = 91;      v31 = 129;      set.cel(o15, 0);      stop.cycling(o15);      draw(o15);      set(f99);    }  }  show.pic();  if (isset(f220))
  {    sound(Sound27, f41);    print.at("Manannan is impatiently waiting for his food! His stomach rumbles "      "as he drums his gnarled fingers on the table. You'd better feed "      "him quickly, or dire consequences may result.", 2, 2, 37);  }  return();}if (isset(f220))
{  block(80, 119, 101, 131);}else
{  unblock();}if (!isset(haveInput))
{  goto(Label1);}if ((said("examine", "area") ||  said("examine", "building") ||  said("examine")))
{  print("This is where Manannan eats his meals. You, of course, are not "    "supposed to eat here. YOU eat in the kitchen. There is a pine table "    "and benches large enough to seat at least ten people; but the wizard "    "has never HAD any guests for dinner.");}if (said("examine", "counter"))
{  print("The large dining table is made of pine planking. Matching benches run "    "its length on both sides. The table is big enough to seat at least ten "    "people.");  if (obj.in.room("Empty Cup", currentRoom))
  {    print("There is a little metal cup on the table.");  }}if (obj.in.room("Empty Cup", currentRoom) &&  said("examine", "cup"))
{  print("There is a little metal cup on the table.");}if ((said("examine", "top", "counter") ||  said("examine", "above", "counter") ||  said("examine", "counter", "top")))
{  if (obj.in.room("Empty Cup", currentRoom))
  {    print("There is a little metal cup on the table.");  }  else
  {    print("There is nothing on the dining table. You keep it very clean as "      "Manannan will not eat on a dirty table.");  }}if (said("examine", "below", "counter"))
{  print("You bend over and peer under the table. You see nothing but a few "    "crumbs left over from one of Manannan's meals.");}if ((said("examine", "moose") ||  said("examine", "cage") ||  said("examine", "moose", "cage")))
{  print("You scrutinize the moosehead very carefully. But, you see it is "    "nothing but an old head. You do feel sorry for the poor thing, though.");}if ((said("capture", "moose") ||  said("capture", "moose", "cage") ||  said("capture", "moose", "off", "cage") ||  said("drain", "moose") ||  said("drain", "moose", "cage")))
{  print("The moosehead is securely fastened to the wall. You cannot remove it.");}if ((said("examine", "burn") ||  said("examine", "fire")))
{  print("Flickering candles from the wrought iron lamp light the room.");}if (said("examine", "door"))
{  print("There are two doorways here. One leads to the kitchen, the other to "    "the entry hall.");}if ((said("capture", "cup") ||  said("capture", "cup", "counter") ||  said("capture", "cup", "from", "counter")))
{  if (!obj.in.room("Empty Cup", currentRoom))
  {    print("You already took it.");  }  else
  {    if (!posn(ego, 62, 126, 80, 150))
    {      print("You're too far away.");    }    else
    {      get("Empty Cup");      currentScore += 1;      start.update(o6);      erase(o6);      print("You pick up the little tin cup and carry it with you.");    }  }}if (isset(f227))
{  if (said("examine", "cat"))
  {    print("Manannan will never annoy anyone again.");  }  if (said("call", "cat"))
  {    print("Manannan seems unusually quiet, don't you think!");  }  if (said("anyword", "cat"))
  {    print("You'd better get on with your quest. Manannan is no longer a bother "      "to anyone!");  }}if ((said("get in", "counter") ||  said("get in") ||  said("get in", "down") ||  said("get in", "down", "counter") ||  said("get in", "on", "bench") ||  said("get in", "bench")))
{  if (isset(f220))
  {    print("Manannan wouldn't like that.");  }  else
  {    if ((v41 < 124 ||      v41 > 152 ||      v40 < 41 ||      v40 > 152))
    {      print("You're too far from the table.");    }    else
    {      if (!isset(f46))
      {        set(f122);        v39 = 0;      }      else
      {        reset(haveMatch);      }    }  }}if ((said("board", "counter") ||  said("rise") ||  said("capture", "up") ||  said("capture", "up", "from", "counter") ||  said("board", "bench") ||  said("rise", "up")))
{  if (v44 == 10)
  {    set(f228);  }  else
  {    if (v44 == 9)
    {      print("Finish chewing first.");    }    else
    {      print("You are standing.");    }  }}if (has("Bread") &&  (said("drink", "bread") ||    said("drink", "food") ||    said("drink", "food", "counter")))
{  v224 = 49;}if (has("Fruit") &&  (said("drink", "apple") ||    said("drink", "food") ||    said("drink", "food", "counter")))
{  v224 = 50;}if (has("Mutton") &&  (said("drink", "chop") ||    said("drink", "food") ||    said("drink", "food", "counter")))
{  v224 = 51;}if (!isset(f220))
{  if (isset(f99) &&    !isset(f109) &&    (said("feed", "enchanter") ||      said("feed", "anyword", "enchanter") ||      said("feed", "anyword", "anyword", "enchanter") ||      said("feed", "anyword", "enchanter", "anyword") ||      said("anyword", "apple", "enchanter") ||      said("anyword", "bread", "enchanter") ||      said("anyword", "chop", "enchanter") ||      said("apple", "anyword", "enchanter") ||      said("bread", "anyword", "enchanter") ||      said("chop", "anyword", "enchanter")))
  {    print("He doesn't seem to be hungry right now.");  }}else
{  if (said("examine", "enchanter"))
  {    if (v128 == 106)
    {      print("Manannan is impatiently waiting for his food! His stomach rumbles "        "as he drums his gnarled fingers on the table. You'd better feed "        "him quickly, or dire consequences may result.");    }    else
    {      if (v128 == 9)
      {        print("He seems to be quite hungry.");      }      else
      {        reset(haveMatch);      }    }  }  if ((said("call", "enchanter") ||    said("call", "abominable", "enchanter")))
  {    if (v128 == 9)
    {      print("He's too busy to reply.");    }    else
    {      if (v128 == 106)
      {        if (!isset(f222))
        {          set(f222);          print("Manannan is out of sorts right now. \"Don't jabber at me, boy! "            "Bring me my food, NOW!\" he bellows.");        }        else
        {          print("After speaking to the grouchy wizard again, he narrows his "            "bushy-white eyebrows and looks at you with ill-temper. "            "\"You're awfully thick-headed, aren't you?\" he snarls. \"It "            "seems you need to be taught a lesson or two about OBEYING!\"");          set.view(o15, View190);          reposition.to(o15, 91, 129);          v123 = 15;          set(f130);        }      }      else
      {        reset(haveMatch);      }    }  }  if ((said("feed", "enchanter") ||    said("feed", "food", "enchanter") ||    said("feed", "enchanter", "food") ||    said("add", "food", "counter") ||    said("add", "food", "on", "counter") ||    said("add", "food", "counter", "enchanter") ||    said("add", "food", "on", "counter", "enchanter") ||    said("feed", "food", "enchanter") ||    said("feed", "enchanter", "food")))
  {    if (!has("Bread") &&      !has("Fruit") &&      !has("Mutton") &&      !has("Porridge") &&      !has("Poisoned Porridge"))
    {      print("You have no food to give the wizard.");    }    else
    {      v225 = 0;      if (has("Bread") &&        !has("Fruit") &&        !has("Mutton") &&        !has("Porridge") &&        !has("Poisoned Porridge"))
      {        v225 = 49;      }      if (!has("Bread") &&        has("Fruit") &&        !has("Mutton") &&        !has("Porridge") &&        !has("Poisoned Porridge"))
      {        v225 = 50;      }      if (!has("Bread") &&        !has("Fruit") &&        has("Mutton") &&        !has("Porridge") &&        !has("Poisoned Porridge"))
      {        v225 = 51;      }      if (!has("Bread") &&        !has("Fruit") &&        !has("Mutton") &&        has("Porridge") &&        !has("Poisoned Porridge"))
      {        v225 = 24;      }      if (!has("Bread") &&        !has("Fruit") &&        !has("Mutton") &&        !has("Porridge") &&        has("Poisoned Porridge"))
      {        v225 = 25;      }      if (v225 <= 0)
      {        print("You are carrying more than one type of food. Which would you "          "like to give the wizard?");        v225 = 255;        goto(Label1);      }    }  }  if (has("Bread"))
  {    if ((said("feed", "bread", "enchanter") ||      said("feed", "enchanter", "bread") ||      said("add", "bread", "counter") ||      said("add", "bread", "counter", "enchanter") ||      said("feed", "bread", "enchanter") ||      said("feed", "enchanter", "bread")))
    {      v225 = 49;    }    if (v225 == 255 &&      said("bread"))
    {      v225 = 49;    }  }  if (has("Fruit"))
  {    if ((said("feed", "apple", "enchanter") ||      said("feed", "enchanter", "apple") ||      said("add", "apple", "counter") ||      said("add", "apple", "counter", "enchanter") ||      said("feed", "apple", "enchanter") ||      said("feed", "enchanter", "apple")))
    {      v225 = 50;    }    if (v225 == 255 &&      said("apple"))
    {      v225 = 50;    }  }  if (has("Mutton"))
  {    if ((said("feed", "chop", "enchanter") ||      said("feed", "enchanter", "chop") ||      said("add", "chop", "counter") ||      said("add", "chop", "counter", "enchanter") ||      said("feed", "chop", "enchanter") ||      said("feed", "enchanter", "chop")))
    {      v225 = 51;    }    if (v225 == 255 &&      said("chop"))
    {      v225 = 51;    }  }  if ((has("Porridge") ||    has("Poisoned Porridge")))
  {    if ((said("feed", "porridge", "enchanter") ||      said("feed", "enchanter", "porridge") ||      said("add", "porridge", "counter") ||      said("add", "porridge", "on", "counter") ||      said("add", "porridge", "counter", "enchanter") ||      said("add", "porridge", "on", "counter", "enchanter") ||      said("feed", "porridge", "enchanter") ||      said("feed", "poison", "porridge", "enchanter") ||      said("feed", "enchanter", "poison", "porridge") ||      said("add", "poison", "porridge", "counter") ||      said("add", "poison", "porridge", "on", "counter") ||      said("add", "poison", "porridge", "counter", "enchanter") ||      said("add", "poison", "porridge", "on", "counter", "enchanter") ||      said("feed", "poison", "porridge", "enchanter") ||      said("feed", "enchanter", "poison", "porridge")))
    {      v225 = 24;    }    if (v225 == 255 &&      said("porridge"))
    {      v225 = 24;    }  }  if (has("Poisoned Porridge"))
  {    if (v225 == 24)
    {      v225 = 25;    }    if ((said("feed", "porridge", "enchanter") ||      said("feed", "enchanter", "porridge") ||      said("add", "porridge", "counter") ||      said("add", "porridge", "on", "counter") ||      said("add", "porridge", "counter", "enchanter") ||      said("add", "porridge", "on", "counter", "enchanter") ||      said("feed", "porridge", "enchanter") ||      said("feed", "poison", "porridge", "enchanter") ||      said("feed", "enchanter", "poison", "porridge") ||      said("add", "poison", "porridge", "counter") ||      said("add", "poison", "porridge", "on", "counter") ||      said("add", "poison", "porridge", "counter", "enchanter") ||      said("add", "poison", "porridge", "on", "counter", "enchanter") ||      said("feed", "poison", "porridge", "enchanter") ||      said("feed", "enchanter", "poison", "porridge") ||      said("feed", "porridge", "enchanter") ||      said("feed", "enchanter", "porridge") ||      said("add", "porridge", "counter") ||      said("add", "porridge", "counter", "enchanter") ||      said("feed", "porridge", "enchanter") ||      said("feed", "enchanter", "porridge")))
    {      v225 = 25;    }    if (v225 == 255 &&      said("poison", "porridge"))
    {      v225 = 25;    }  }}if (v225 == 255)
{  v225 = 0;}Label1:if (isset(f99) &&  !isset(f109))
{  if (v225 > 0 &&    v225 != 255)
  {    if (!posn(ego, 75, 126, 105, 153))
    {      v225 = 0;      print("You're too far away.");    }    else
    {      if (v128 != 106)
      {        v225 = 0;        print("He doesn't seem to be hungry right now.");        goto(Label1);      }      if (v225 == 49)
      {        drop("Bread");        set.cel(o5, 4);      }      if (v225 == 50)
      {        drop("Fruit");        set.cel(o5, 5);      }      if (v225 == 51)
      {        drop("Mutton");        set.cel(o5, 3);      }      if (v225 == 24)
      {        drop("Porridge");        set.cel(o5, 7);      }      if (v225 == 25)
      {        drop("Poisoned Porridge");        set.cel(o5, 7);        set(f226);      }      v225 = 0;      draw(o5);      set(f46);      stop.motion(ego);      v220 = 23;      v128 = 9;      v221 = 2;      print("You place the food on the dining table before the hungry wizard. "        "Ravenously, he devours every bit of it.");      v36 = 3;      cycle.time(o15, v36);      if (v137 == 3)
      {        v137 = 0;        v110 = 0;        v109 = 0;      }    }  }  --v221;  if (v221 == 1)
  {    end.of.loop(o15, f224);  }  if (isset(f224))
  {    reset(f224);    set.cel(o15, 0);    stop.cycling(o15);    v221 = 15;  }  if (isset(f45))
  {    --v226;    if (v226 == 1)
    {      set(f101);    }    --v220;    if (v220 == 1)
    {      if (isset(f226))
      {        reset(f226);        reset(f46);        set(f101);        v124 = 50;        print("You fooled him! Manannan didn't realize the porridge was "          "tainted, and ate the whole bowl!");      }      else
      {        print("It's obvious the wizard enjoyed his meal as he lets out a "          "satisfied belch. He rises and leaves without so much as a "          "\"Thank you!\"");        erase(o5);        v128 = 103;        stop.cycling(o15);        v124 = 100;        v226 = 5;      }    }  }  if ((v124 == 51 ||    v124 == 101))
  {    current.cel(o14, v36);    if (v36 == 3)
    {      set(f101);    }  }  if (isset(f101))
  {    reset(f101);    ++v124;    prevent.input();    program.control();    stop.motion(ego);    if (v124 == 51)
    {      load.view(View203);      load.sound(Sound21);      sound(Sound21, f41);      erase(o5);      animate.obj(o14);      set.view(o14, View199);      set.priority(o14, 15);      set.cel(o14, 0);      v36 = 3;      cycle.time(o14, v36);      ignore.objs(o14);      stop.motion(o14);      position(o14, 87, 126);      draw(o14);      end.of.loop(o14, f101);    }    if (v124 == 52)
    {      erase(o15);      currentScore += 12;      v128 = 20;      v127 = 2;      reset(f220);      v84 = 0;      v83 = 0;      unblock();      animate.obj(o13);      set.view(o13, View203);      set(f116);      position(o13, 90, 130);      draw(o13);      move.obj(o13, 115, 130, 1, f41);    }    if (v124 == 53)
    {      erase(o14);      v226 = 3;    }    if (v124 == 54)
    {      print("Congratulations! Manannan will never again enslave you or the "        "people of Llewdor!! At last, you are free!");      wander(o13);      observe.objs(o13);      set(f227);      set(f116);      reset(f99);      reset(f46);      v124 = 0;    }    if (v124 == 101)
    {      stop.cycling(o15);      erase(o5);      animate.obj(o14);      set.view(o14, View199);      set.priority(o14, 15);      set.cel(o14, 0);      v36 = 3;      cycle.time(o14, v36);      ignore.objs(o14);      stop.motion(o14);      position(o14, 87, 126);      draw(o14);      end.of.loop(o14, f101);      sound(Sound2, f41);    }    if (v124 == 102)
    {      erase(o15);    }    if (v124 == 103)
    {      erase(o14);      reset(f99);      reset(f220);      unblock();      v128 = 104;      reset(f46);      v124 = 0;      v32 = 29;      v31 = 140;    }    if (v124 == 0)
    {      start.motion(ego);      accept.input();      player.control();    }  }}if (isset(f45))
{  --v227;  if (v227 == 1)
  {    set(f122);  }}if (isset(f122))
{  reset(f122);  ++v39;  get.posn(ego, v37, v38);  v69 = 1;  if (v39 == 1)
  {    set(f46);    program.control();    v44 = 2;    if (v41 > 141 &&      v41 < 144 &&      v40 > 50 &&      v40 < 115)
    {      v37 = 115;    }    else
    {      if (v41 < 131)
      {        v39 = 3;      }      else
      {        if (v41 < 148)
        {          v39 = 2;        }        else
        {          v38 = 148;        }      }      if (v40 < 81)
      {        v37 = 42;      }      else
      {        v37 = 115;      }    }    move.obj.v(ego, v37, v38, v69, f122);  }  if (v39 == 2)
  {    v38 = 129;    move.obj.v(ego, v37, v38, v69, f122);  }  if (v39 == 3)
  {    move.obj(ego, 90, 129, 0, f122);  }  if (v39 == 4)
  {    v44 = 10;    reposition.to(ego, 90, 118);    set.view(ego, View34);    set.cel(ego, 0);    reset(f35);    start.motion(ego);    v227 = 4;  }  if (v39 == 5)
  {    print("You take a well deserved moment's rest. But, you wonder if you have "      "time to be sitting here?");    v39 = 0;  }}if (v224 > 0)
{  if (isset(f220))
  {    print("Manannan wouldn't like that.");    v224 = 0;  }  else
  {    if (!isset(f46))
    {      if ((v41 < 124 ||        v41 > 152 ||        v40 < 41 ||        v40 > 152))
      {        print("You're too far from the table.");        v224 = 0;      }      else
      {        set(f122);        v39 = 0;      }    }    if (v44 == 10)
    {      if (v224 == 50)
      {        drop("Fruit");        set.cel(o5, 5);      }      if (v224 == 49)
      {        drop("Bread");        set.cel(o5, 4);      }      if (v224 == 51)
      {        drop("Mutton");        set.cel(o5, 3);      }      if (v224 == 24)
      {        drop("Porridge");        set.cel(o5, 7);      }      if (v224 == 25)
      {        set(f225);        drop("Poisoned Porridge");        set.cel(o5, 7);      }      v224 = 0;      draw(o5);      set(f46);      set(f35);      stop.motion(ego);      v36 = 3;      cycle.time(ego, v36);      v44 = 9;      v222 = 22;      v223 = 2;    }  }}if (isset(f45))
{  --v222;  if (v222 == 1)
  {    erase(o5);    if (isset(f225))
    {      reset(f225);      print("You purr contentedly. You will enjoy your new life as a cat!");      load.view(View39);      set.view(ego, View39);      set.loop(ego, 0);      set.priority(ego, 15);      reposition.to(ego, 91, 123);      start.cycling(ego);      v36 = 2;      cycle.time(ego, v36);      set(f44);    }    else
    {      set.cel(ego, 0);      stop.cycling(ego);      start.motion(ego);      reset(f35);      v222 = 0;      v223 = 0;      reset(f223);      v44 = 10;      set(f46);      print("Mmmmmm! You needed that.");    }  }}if (v44 == 9)
{  --v223;  if (v223 == 1)
  {    set(f35);    end.of.loop(ego, f223);  }  if (isset(f223))
  {    reset(f223);    set.cel(ego, 0);    reset(f35);    v223 = 15;  }}if (v44 == 10 &&  egoDir > STOPPED)
{  set(f228);}if (isset(f228))
{  reset(f228);  set.view(ego, View0);  reset(f35);  reset(f36);  reposition.to(ego, 90, 130);  player.control();  v59 = 1;  cycle.time(ego, v59);  v44 = 0;  v227 = 0;  reset(f46);}if (v44 != 125)
{  if (posn(ego, 101, 110, 115, 120))
  {    new.room(Logic6);  }  if (posn(ego, 21, 132, 25, 144))
  {    new.room(Logic7);  }}call(Logic104);if (isset(f98))
{  call(Logic105);}if (isset(f99) &&  isset(f220))
{  v32 = 91;  v31 = 129;}if (!isset(f99) &&  v137 == 3)
{  v109 = 55;}return();[Messages#message 1 "This is where Manannan eats his meals. You, of course, are not supposed to eat here. YOU eat in the kitchen. There is a pine table and benches large enough to seat at least ten people; but the wizard has never HAD any guests for dinner."#message 2 "He seems to be quite hungry."#message 3 "The large dining table is made of pine planking. Matching benches run its length on both sides. The table is big enough to seat at least ten people."#message 4 "There is nothing on the dining table. You keep it very clean as Manannan will not eat on a dirty table."#message 5 "You bend over and peer under the table. You see nothing but a few crumbs left over from one of Manannan's meals."#message 6 "You take a well deserved moment's rest. But, you wonder if you have time to be sitting here?"#message 7 "Mmmmmm! You needed that."#message 8 "You scrutinize the moosehead very carefully. But, you see it is nothing but an old head. You do feel sorry for the poor thing, though."#message 9 "The moosehead is securely fastened to the wall. You cannot remove it."#message 10 "Flickering candles from the wrought iron lamp light the room."#message 11 "There are two doorways here. One leads to the kitchen, the other to the entry hall."#message 12 "Manannan is impatiently waiting for his food! His stomach rumbles as he drums his gnarled fingers on the table. You'd better feed him quickly, or dire consequences may result."#message 13 "Manannan is out of sorts right now. \"Don't jabber at me, boy! Bring me my food, NOW!\" he bellows."#message 14 "After speaking to the grouchy wizard again, he narrows his bushy-white eyebrows and looks at you with ill-temper. \"You're awfully thick-headed, aren't you?\" he snarls. \"It seems you need to be taught a lesson or two about OBEYING!\""#message 15 "You are carrying more than one type of food. Which would you like to give the wizard?"#message 16 "You place the food on the dining table before the hungry wizard. Ravenously, he devours every bit of it."#message 17 "Evidently, Manannan has important things on his mind."#message 18 "It's obvious the wizard enjoyed his meal as he lets out a satisfied belch. He rises and leaves without so much as a \"Thank you!\""#message 19 "You have no food to give the wizard."#message 20 "Oh, Manannan is here! You wonder what mood he's in, as you never know from one minute to the next what he will do. To your relief, he is preoccupied. He's muttering mumbo-jumbos you don't understand."#message 21 "There is a little metal cup on the table."#message 22 "You pick up the little tin cup and carry it with you."#message 23 "You're too far away."#message 24 "He doesn't seem to be hungry right now."#message 25 "Manannan wouldn't like that."#message 26 "You're too far from the table."#message 27 "Finish chewing first."#message 28 "You are standing."#message 29 "You already took it."#message 30 "You fooled him! Manannan didn't realize the porridge was tainted, and ate the whole bowl!"#message 31 "You purr contentedly. You will enjoy your new life as a cat!"#message 32 "He's too busy to reply."#message 33 "Manannan will never annoy anyone again."#message 34 "Manannan seems unusually quiet, don't you think!"#message 35 "You'd better get on with your quest. Manannan is no longer a bother to anyone!"#message 36 "Congratulations! Manannan will never again enslave you or the people of Llewdor!! At last, you are free!"
