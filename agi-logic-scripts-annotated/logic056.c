if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 4;  set(f61);  v57 = 44;  v58 = 154;  set.horizon(114);  load.logics(Logic103);  v34 = 166;  if (previousRoom == 55)
    {    load.logics(Logic117);    v191 = 1;    reset(f172);    }  else
    {    v191 = 0;    }  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
    {    if (previousRoom == 57)
      {      position(ego, 40, 167);      if (v44 == 15)
        {        v44 = 0;        set.view(ego, View0);        }      }    else
      {      if (previousRoom == 55)
        {        position(ego, 0, 139);        }      }    }  observe.blocks(ego);  if (isset(f47))
    {    draw(ego);    }  call(Logic103);  if (v191 == 1)
    {    call(Logic117);    set.priority(o15, 10);    set.loop(o15, 0);    position(o15, 0, 135);    }  show.pic();  return();  }if (!isset(haveInput))
  {  goto(Label1);  }if ((said("examine", "bluff") ||     said("examine", "up", "bluff") ||     said("examine", "up") ||     said("examine") ||     said("examine", "area") ||     said("examine", "down")))
  {  print("You have made the very top of the snowy mountain range. The snow path "        "ends here at a cliff. Far in the distance, you can see a vast green "        "valley. \"Could it be Daventry?\" you wonder. Your excitement mounts.");  }if (said("examine", "path"))
  {  print("The snow path leads to the edge of a very steep precipice. You look "        "about, but see that there is no place to go but straight down.");  }if ((said("examine", "brush") ||     said("examine", "forest") ||     said("capture", "flower") ||     said("capture", "flower") ||     said("examine", "flower")))
  {  print("Plants and trees are scarce in the snowy reaches of these mountains.");  }if (said("examine", "deck"))
  {  print("The ground is completely covered with cold, white snow.");  }if (said("examine", "sky"))
  {  print("The deep-blue sky contrasts sharply with the brilliant white mountain "        "peaks. You must admit, even while shivering, it is a beautiful sight.");  }if ((said("climb", "forest") ||     said("climb", "up", "forest")))
  {  print("There are no trees here.");  }if (said("examine", "snow"))
  {  print("White snow blankets everything here in the upper reaches of the great "        "mountains. It's beautiful, but it is VERY cold.");  }if (said("play", "snow"))
  {  print("Wheee!");  }if (said("examine", "canyon"))
  {  print("That must be Daventry!");  print("\"But why is Half Dome here?\" you wonder.");  print("\"But, of course,\" you think, \"it's a Sierra game!\"");  }Label1:if (isset(f33))
  {  if (v44 == 0)
    {    reset(f220);    }  }v39 = 0;if (isset(egoHitSpecial))
  {  if (v40 < 114)
    {    v39 = 1;    v40 = 114;    reposition.to.v(ego, v40, v41);    }  else
    {    if (v41 < 128)
      {      v39 = 2;      set.priority(ego, 4);      }    else
      {      if (posn(ego, 105, 130, 169, 160))
        {        v39 = 3;        set.priority(ego, 11);        }      else
        {        set.priority(ego, 14);        v39 = 4;        if (v40 > 140 &&             (egoDir == RIGHT ||             egoDir == UP_RIGHT ||             egoDir == DOWN_RIGHT))
          {          v39 = 5;          v40  += 4;          reposition.to.v(ego, v40, v41);          }        }      }    }  }if (v40 > 30 &&     !isset(f172) &&     v191 == 1)
  {  ++v191;  }if (isset(f172))
  {  if (v191 < 6)
    {    get.posn(o15, v37, v38);    if (v38 > 111)
      {      release.priority(o15);      }    else
      {      set.priority(o15, 10);      }    }  if (v191 == 3)
    {    ++v191;    follow.ego(o15, 11, f173);    observe.blocks(o15);    v170 = 1;    v171 = 135;    }  }call(Logic103);if (v191 > 0)
  {  call(Logic117);  }if (edgeEgoHit == BOTTOM_EDGE &&     (v44 == 26 ||     v44 == 25))
  {  edgeEgoHit = NOT_HIT;  v71 = 5;  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic55);  }if (edgeEgoHit == BOTTOM_EDGE)
  {  if (!isset(f62))
    {    print("Bravely, you grasp the ice laden rocks, and attempt to scale the "          "nearly vertical wall. Be careful, Gwydion!");    }  set.view(ego, View0);  currentEgoView = 0;  new.room(Logic57);  }return();[ Messages#message 1 "You have made the very top of the snowy mountain range. The snow path ends here at a cliff. Far in the distance, you can see a vast green valley. \"Could it be Daventry?\" you wonder. Your excitement mounts."#message 2 "The snow path leads to the edge of a very steep precipice. You look about, but see that there is no place to go but straight down."#message 3 "Plants and trees are scarce in the snowy reaches of these mountains."#message 4 "The ground is completely covered with cold, white snow."#message 5 "The deep-blue sky contrasts sharply with the brilliant white mountain peaks. You must admit, even while shivering, it is a beautiful sight."#message 6 "There are no trees here."#message 7 "White snow blankets everything here in the upper reaches of the great mountains. It's beautiful, but it is VERY cold."#message 8 ""#message 9 "Wheee!"#message 13 "Bravely, you grasp the ice laden rocks, and attempt to scale the nearly vertical wall. Be careful, Gwydion!"#message 14 ""#message 15 "That must be Daventry!"#message 16 "\"But why is Half Dome here?\" you wonder."#message 17 "\"But, of course,\" you think, \"it's a Sierra game!\""