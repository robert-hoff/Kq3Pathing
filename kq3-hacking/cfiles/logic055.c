if (isset(newRoom))
  {  if ((v76 > 0 ||       v75 > 0) &&       previousRoom == 60)
    {    v72 = previousRoom;    new.room(Logic87);    }  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 4;  set(f60);  v57 = 30;  v58 = 95;  set.horizon(76);  random(1, 2, v36);  if (previousRoom == 60)
    {    v36 = 0;    }  if (isset(f46))
    {    v36 = 0;    }  if (v36 == 1)
    {    load.logics(Logic117);    v191 = 1;    reset(f172);    }  else
    {    v191 = 0;    }  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
    {    if (previousRoom == 60)
      {      release.priority(ego);      position(ego, 118, 112);      }    else
      {      if (previousRoom == 56)
        {        release.priority(ego);        position(ego, 152, 142);        }      else
        {        position(ego, 0, 99);        set.priority(ego, 14);        }      }    }  observe.blocks(ego);  if (isset(f47))
    {    draw(ego);    }  if (v191 == 1)
    {    call(Logic117);    release.priority(o15);    set.loop(o15, 1);    position(o15, 130, 106);    ignore.blocks(o15);    }  show.pic();  return();  }if (!isset(haveInput))
  {  goto(Label1);  }if ((said("examine", "bluff") ||     said("examine", "up", "bluff") ||     said("examine", "up") ||     said("examine") ||     said("examine", "area") ||     said("examine", "down")))
  {  print("You have reached the summit, but still the snowy mountains continue "        "relentlessly forward. What is this? A cave with a snowy path leading "        "to it! Hmmmmm. What could it all mean?");  }if (said("examine", "path"))
  {  print("A narrow path forges its way through the snowdrifts, and another leads "        "into a large cave! Nervously, you look around.");  }if ((said("examine", "cave") ||     said("look in", "cave") ||     said("examine", "inside", "cave")))
  {  print("The snowy cave is very large with thick icicles hanging from its "        "entrance. It's very dark inside.");  }if ((said("examine", "brush") ||     said("examine", "forest") ||     said("capture", "flower") ||     said("capture", "flower") ||     said("examine", "flower")))
  {  print("Plants and trees are scarce in the snowy reaches of these mountains.");  }if (said("examine", "deck"))
  {  print("The ground is completely covered with cold, white snow.");  }if (said("examine", "sky"))
  {  print("The deep-blue sky contrasts sharply with the brilliant white mountain "        "peaks. You must admit, even while shivering, it is a beautiful sight.");  }if (said("examine", "snow"))
  {  print("White snow blankets everything here in the upper reaches of the great "        "mountains. It's beautiful, but it is VERY cold.");  }if (said("play", "snow"))
  {  print("Wheee!");  }Label1:if (v44 == 0)
  {  if (v40 > 113)
    {    release.priority(ego);    }  else
    {    set.priority(ego, 13);    }  }if (v40 > 62 &&     !isset(f172) &&     v191 == 1)
  {  ++v191;  }if (isset(f172))
  {  if (v191 == 3)
    {    ++v191;    v220 = 0;    move.obj(o15, 100, 106, 2, f220);    ignore.blocks(o15);    }  if (v191 == 4 &&       isset(f220))
    {    reset(f220);    ++v220;    if (v220 == 1)
      {      set.priority(o15, 10);      move.obj(o15, 100, 85, 2, f220);      }    if (v220 == 2)
      {      set.priority(o15, 13);      move.obj(o15, 74, 96, 2, f220);      if (v40 > 84)
        {        v220 = 3;        }      }    if (v220 == 3)
      {      follow.ego(o15, 11, f173);      v220 = 0;      v170 = 106;      v171 = 96;      }    }  }if (v191 > 0)
  {  call(Logic117);  }if (!isset(f46) &&     currentEgoView == 0 &&     posn(ego, 112, 110, 120, 111))
  {  new.room(Logic60);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic54);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic56);  }return();[ Messages#message 1 "You have reached the summit, but still the snowy mountains continue relentlessly forward. What is this? A cave with a snowy path leading to it! Hmmmmm. What could it all mean?"#message 2 "A narrow path forges its way through the snowdrifts, and another leads into a large cave! Nervously, you look around."#message 3 "The snowy cave is very large with thick icicles hanging from its entrance. It's very dark inside."#message 4 "The ground is completely covered with cold, white snow."#message 5 "The deep-blue sky contrasts sharply with the brilliant white mountain peaks. You must admit, even while shivering, it is a beautiful sight."#message 7 "White snow blankets everything here in the upper reaches of the great mountains. It's beautiful, but it is VERY cold."#message 9 "Wheee!"#message 13 "Plants and trees are scarce in the snowy reaches of these mountains."