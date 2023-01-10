if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 4;  set(f58);  v57 = 111;  v58 = 45;  set.horizon(35);  load.logics(Logic103);  v34 = 166;  load.view(View225);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  animate.obj(o1);  set.view(o1, View225);  set.loop(o1, 0);  position(o1, 44, 49);  set.priority(o1, 5);  ignore.objs(o1);  v36 = 2;  cycle.time(o1, v36);  draw(o1);  animate.obj(o2);  set.view(o2, View225);  set.loop(o2, 1);  position(o2, 58, 96);  set.priority(o2, 5);  ignore.objs(o2);  draw(o2);  animate.obj(o3);  set.view(o3, View225);  set.loop(o3, 1);  set.cel(o3, 2);  position(o3, 65, 117);  set.priority(o3, 5);  ignore.objs(o3);  draw(o3);  animate.obj(o4);  set.view(o4, View225);  set.loop(o4, 2);  position(o4, 60, 87);  set.priority(o4, 5);  ignore.objs(o4);  draw(o4);  animate.obj(o5);  set.view(o5, View225);  set.loop(o5, 3);  position(o5, 68, 160);  set.priority(o5, 5);  ignore.objs(o5);  draw(o5);  call(Logic103);  if (isset(f48))
    {    if (previousRoom == 52)
      {      if (v41 < 71)
        {        v41 = 71;        }      if (v41 > 82)
        {        v41 = 81;        }      }    else
      {      if (previousRoom == 54)
        {        set.view(ego, View0);        v40 = 48;        }      else
        {        v40 = v57;        v41 = v58;        }      }    position.v(ego, v40, v41);    set.priority(ego, 6);    }  if (isset(f47))
    {    draw(ego);    }  show.pic();  return();  }if (!isset(haveInput))
  {  goto(Label1);  }if ((said("examine", "bluff") ||     said("examine", "top", "bluff") ||     said("examine", "up", "bluff") ||     said("examine", "down") ||     said("examine") ||     said("examine", "area") ||     said("examine", "up")))
  {  print("The mountains continue to march forever upward, as you trek higher and "        "higher. It's getting cold, and there are traces of snow. Below you "        "stretches a beautiful valley.");  }if (said("examine", "canyon"))
  {  print("Beautiful, isn't it? Too bad there is absolutely no way to get there.");  }if ((said("examine", "path") ||     said("examine", "up", "path")))
  {  print("Here, the path is narrower, it seems, than before. It travels "        "precariously along the side of a steep mountainside. Looking down, you "        "almost lose your balance. Watch out!");  }if ((said("examine", "brush") ||     said("examine", "forest")))
  {  print("A forest surrounds you, with tall evergreen trees and low bushes.");  }if (said("examine", "deck"))
  {  print("The ground goes... way up, or way down. Better be careful.");  }if ((said("examine", "sky") ||     said("examine", "up", "sky")))
  {  print("You look upward and see the mountain range looming toward the "        "beautiful blue sky.");  }if ((said("climb", "forest") ||     said("climb", "up", "forest")))
  {  print("There are no climbable trees here.");  }if ((said("capture", "flower") ||     said("capture", "flower") ||     said("examine", "flower")))
  {  print("There are few flowers here.");  }if ((said("examine", "creek") ||     said("examine", "liquid") ||     said("look in", "creek")))
  {  print("Melting snow creates a myriad of tiny rainbows as it burbles through "        "the rocks, forming tiny waterfalls on its way back to the sea.");  }if (said("examine", "snow"))
  {  print("Patches of white snow begin to appear. The air is definitely getting "        "colder, and you begin to shiver.");  }if ((said("drink", "liquid") ||     said("drink", "liquid", "creek") ||     said("capture", "liquid") ||     said("capture", "liquid", "creek") ||     said("capture", "drink") ||     said("capture", "drink", "creek") ||     said("capture", "drink", "liquid") ||     said("capture", "drink", "liquid", "creek") ||     said("drink", "liquid", "from", "creek") ||     said("capture", "liquid", "from", "creek") ||     said("capture", "drink", "from", "creek") ||     said("capture", "drink", "liquid", "from", "creek")))
  {  if (posn(ego, 41, 50, 66, 70))
    {    print("Ahhh. It tastes like Sierra water!");    }  else
    {    print("Your arms are not that long.");    }  }Label1:if (v40 < 60)
  {  set.horizon(44);  }else
  {  set.horizon(35);  }if (currentEgoView == 0)
  {  set.priority(ego, 6);  }if (isset(egoHitSpecial))
  {  v39 = 1;  v33 = 6;  if (v41 < 45)
    {    v39 = 2;    set.priority(ego, 4);    }  else
    {    if (v40 > 110)
      {      v39 = 3;      v40  += 4;      reposition.to.v(ego, v40, v41);      }    }  }call(Logic103);if (edgeEgoHit == TOP_EDGE)
  {  new.room(Logic54);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic52);  }return();[ Messages#message 1 "The mountains continue to march forever upward, as you trek higher and higher. It's getting cold, and there are traces of snow. Below you stretches a beautiful valley."#message 2 "Here, the path is narrower, it seems, than before. It travels precariously along the side of a steep mountainside. Looking down, you almost lose your balance. Watch out!"#message 3 "A forest surrounds you, with tall evergreen trees and low bushes."#message 4 "The ground goes... way up, or way down. Better be careful."#message 5 "You look upward and see the mountain range looming toward the beautiful blue sky."#message 6 "There are no climbable trees here."#message 7 "There are few flowers here."#message 8 "Melting snow creates a myriad of tiny rainbows as it burbles through the rocks, forming tiny waterfalls on its way back to the sea."#message 9 "Patches of white snow begin to appear. The air is definitely getting colder, and you begin to shiver."#message 10 "Ahhh. It tastes like Sierra water!"#message 11 "Your arms are not that long."#message 12 "Beautiful, isn't it? Too bad there is absolutely no way to get there."