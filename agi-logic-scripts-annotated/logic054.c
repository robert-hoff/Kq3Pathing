if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 4;  set(f59);  v57 = 95;  v58 = 83;  set.horizon(75);  load.view(View1);  load.view(View226);  random(1, 2, v36);  if (isset(f46))
    {    v36 = 2;    }  if (v36 == 1)
    {    load.logics(Logic117);    v191 = 1;    reset(f172);    v170 = 144;    v171 = 95;    }  else
    {    v191 = 0;    }  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  animate.obj(o1);  set.view(o1, View226);  position(o1, 38, 167);  ignore.objs(o1);  set.priority(o1, 4);  draw(o1);  if (isset(f48))
    {    if (previousRoom == 55)
      {      position(ego, 153, 95);      }    else
      {      if (previousRoom == 53)
        {        position(ego, 39, 167);        set.view(ego, View1);        }      }    }  observe.blocks(ego);  if (isset(f47))
    {    draw(ego);    }  if (v191 == 1)
    {    call(Logic117);    set.priority(o15, 4);    position(o15, 142, 77);    }  show.pic();  return();  }if (!isset(haveInput))
  {  goto(Label1);  }if ((said("examine", "bluff") ||     said("examine", "up", "bluff") ||     said("examine", "up") ||     said("examine") ||     said("examine", "area") ||     said("examine", "down")))
  {  print("You've reached the heights of the mountain range and snow and ice "        "surround you. You still see no end to the mountains. It's bitterly "        "cold, and you shiver in your thin rags. A path, through the snow, "        "leads onward.");  }if (said("examine", "path"))
  {  print("A path has been forged through the heavy snow. You wonder who made the "        "path as you see no sign of life.");  }if ((said("examine", "brush") ||     said("examine", "forest") ||     said("capture", "flower") ||     said("capture", "flower") ||     said("examine", "flower")))
  {  print("Plants and trees are scarce in the snowy reaches of these mountains.");  }if (said("examine", "deck"))
  {  print("The ground is completely covered with cold, white snow.");  }if (said("examine", "sky"))
  {  print("The deep-blue sky contrasts sharply with the brilliant white mountain "        "peaks. You must admit, even while shivering, it is a beautiful sight.");  }if ((said("climb", "forest") ||     said("climb", "up", "forest")))
  {  print("There are no trees here.");  }if (said("examine", "snow"))
  {  print("White snow blankets everything here in the upper reaches of the great "        "mountains. It's beautiful, but it is VERY cold.");  }if (said("play", "snow"))
  {  print("Wheee!");  }if ((said("examine", "creek") ||     said("examine", "liquid") ||     said("look in", "creek")))
  {  print("The runoff from melting snows feeds a tiny stream cascading down "        "through the jumble of stones.");  }if ((said("drink", "liquid") ||     said("drink", "liquid", "creek") ||     said("capture", "liquid") ||     said("capture", "liquid", "creek") ||     said("capture", "drink") ||     said("capture", "drink", "creek") ||     said("capture", "drink", "liquid") ||     said("capture", "drink", "liquid", "creek") ||     said("drink", "liquid", "from", "creek") ||     said("capture", "liquid", "from", "creek") ||     said("capture", "drink", "from", "creek") ||     said("capture", "drink", "liquid", "from", "creek")))
  {  if (v41 > 107)
    {    print("Ahhh. It tastes like Sierra water!");    }  else
    {    print("Your arms are not that long.");    }  }Label1:if (v44 == 0)
  {  if (v41 > 121)
    {    set.view(ego, View1);    }  else
    {    set.view(ego, View0);    }  }if (v40 > 70 &&     !isset(f172) &&     v191 == 1)
  {  ++v191;  }if (isset(f172))
  {  get.posn(o15, v37, v38);  if (v38 > 101)
    {    set.priority(o15, 15);    }  else
    {    release.priority(o15);    }  if (v191 == 3)
    {    ++v191;    v220 = 0;    move.obj(o15, 95, 77, 2, f220);    ignore.blocks(o15);    }  if (v191 == 4 &&       isset(f220))
    {    reset(f220);    ++v220;    if (v220 == 1)
      {      move.obj(o15, 95, 95, 2, f220);      }    if (v220 == 2)
      {      ignore.blocks(o15);      release.priority(o15);      follow.ego(o15, 11, f173);      v220 = 0;      v170 = 144;      v171 = 95;      }    }  }if (v191 > 0)
  {  call(Logic117);  }if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic53);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic55);  }return();[ Messages#message 1 "You've reached the heights of the mountain range and snow and ice surround you. You still see no end to the mountains. It's bitterly cold, and you shiver in your thin rags. A path, through the snow, leads onward."#message 2 "A path has been forged through the heavy snow. You wonder who made the path as you see no sign of life."#message 3 "Plants and trees are scarce in the snowy reaches of these mountains."#message 4 "The ground is completely covered with cold, white snow."#message 5 "The deep-blue sky contrasts sharply with the brilliant white mountain peaks. You must admit, even while shivering, it is a beautiful sight."#message 6 "There are no trees here."#message 7 "White snow blankets everything here in the upper reaches of the great mountains. It's beautiful, but it is VERY cold."#message 8 "The runoff from melting snows feeds a tiny stream cascading down through the jumble of stones."#message 9 "Wheee!"#message 10 "Ahhh. It tastes like Sierra water!"#message 11 "Your arms are not that long."