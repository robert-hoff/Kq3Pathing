if (isset(newRoom))
{  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 4;  set(f62);  v57 = 44;  v58 = 62;  set.horizon(34);  set(f235);  load.logics(Logic103);  v34 = 166;  load.view(View1);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
  {    set(f46);    if (previousRoom == 56)
    {      start.motion(ego);      set.view(ego, View1);      if (v40 < 60)
      {        position(ego, 49, 35);      }      else
      {        position(ego, 98, 35);        set(f220);      }    }    else
    {      if (previousRoom == 58)
      {        set.view(ego, View0);        position(ego, 151, 164);      }    }  }  if (isset(f47))
  {    draw(ego);  }  call(Logic103);  show.pic();  return();}if (v44 == 6)
{  goto(Label2);}if (isset(f236) &&  !isset(f171))
{  set(f171);  currentScore += 4;  print("You congratulate yourself on successfully eluding the abominable "    "snowman.");}set(f236);if (!isset(haveInput))
{  goto(Label1);}if ((said("examine", "bluff") ||  said("examine", "up", "bluff") ||  said("examine") ||  said("examine", "up") ||  said("examine", "area") ||  said("examine", "down")))
{  print("This is a very steep (and dangerous) cliff! Numerous caves honeycomb "    "its face. You could get lost in the caves, IF you survive the cliff.");}if (said("examine", "path"))
{  print("A narrow path continues onward.");}if ((said("examine", "brush") ||  said("examine", "forest") ||  said("capture", "flower") ||  said("capture", "flower") ||  said("examine", "flower")))
{  print("There are no plants on this rocky cliff.");}if (said("examine", "deck"))
{  print("The ground is far below you. Be careful!");}if (said("examine", "sky"))
{  print("The cliff face before you towers into the deep, blue sky.");}if ((said("climb", "forest") ||  said("climb", "up", "forest")))
{  print("What trees?");}if ((said("examine", "cave") ||  said("look in", "cave")))
{  print("The caverns in this mountain form a labyrinth of amazing complexity.");}if (said("examine", "snow"))
{  print("The snow here has formed an icepack so hard it is impossible to gain a "    "handhold.");}if (said("play", "snow"))
{  print("Not now!");}Label1:v220 = 0;v39 = 1;if (v222 > 0)
{  egoDir = v82;  reset(egoHitSpecial);  set(onWater);}if (isset(f45))
{  --v222;  if (v222 == 1)
  {    draw(ego);    v222 = 0;  }}if (posn(ego, 123, 43, 132, 47))
{  v220 = 1;  set(onWater);}if (posn(ego, 87, 138, 107, 160))
{  v220 = 2;  set(onWater);}if (posn(ego, 20, 138, 30, 154))
{  v220 = 3;  set(onWater);}if (posn(ego, 73, 86, 80, 94))
{  v220 = 4;  set(onWater);}if (posn(ego, 118, 137, 159, 167))
{  v220 = 5;  set(onWater);}if (posn(ego, 24, 51, 38, 57))
{  v220 = 6;  set(onWater);}if (posn(ego, 77, 158, 107, 163))
{  v220 = 7;  set(onWater);}if (posn(ego, 42, 49, 46, 58))
{  v220 = 11;  set(f221);}if (posn(ego, 110, 39, 118, 46))
{  v220 = 12;  set(f221);}if (posn(ego, 83, 84, 90, 99))
{  v220 = 13;  set(f221);}if (posn(ego, 75, 138, 86, 152))
{  v220 = 14;  set(f221);}if (posn(ego, 32, 133, 39, 150))
{  v220 = 15;  set(f221);}if (posn(ego, 37, 49, 38, 59))
{  v220 = 16;  set(f221);}if (isset(f221))
{  reset(f221);  ignore.blocks(ego);}else
{  observe.blocks(ego);}if (posn(ego, 35, 51, 36, 57))
{  v220 = 21;  erase(ego);  position(ego, 125, 43);  v222 = 6;  if (!isset(f174))
  {    set(f174);    print("Boy, are these caves dark!");  }}if (posn(ego, 123, 43, 124, 44))
{  v220 = 22;  erase(ego);  position(ego, 34, 54);  v222 = 6;}if (posn(ego, 90, 140, 91, 148))
{  v220 = 23;  erase(ego);  position(ego, 27, 145);  v222 = 4;}if (posn(ego, 28, 141, 29, 149))
{  v220 = 24;  erase(ego);  position(ego, 92, 144);  v222 = 4;}if (posn(ego, 79, 86, 80, 94))
{  v220 = 25;  erase(ego);  position(ego, 129, 140);  v222 = 5;}if (posn(ego, 127, 138, 128, 142))
{  v220 = 26;  erase(ego);  position(ego, 78, 90);  v222 = 5;}if (posn(ego, 43, 150, 51, 161) &&  !isset(onWater))
{  v40 = 42;  reposition.to.v(ego, v40, v41);}if (isset(onWater))
{  reset(egoHitSpecial);  v44 = 2;  release.priority(ego);  set.view(ego, View0);}else
{  if (!isset(egoHitSpecial))
  {    v44 = 15;    set.view(ego, View1);    set.priority(ego, 14);  }  else
  {    set.priority(ego, 15);  }}
if (v71 == 2 && v44 == 15)
{  v71 = 0;  print("Removing your hands from the sheer rock wall to rub the magic "    "stone,%m22");  set(egoHitSpecial);  set(f224);  set.priority(ego, 15);  set(f220);  drop("Magic Stone*");}if (v71 == 3)
{  v71 = 0;  drop("Fly Wings*");  print("As you reach for your fly wings, a sharp gust of wind blows them from "    "your grasp.");}if (v71 == 4)
{  v71 = 0;  drop("Eagle Feather*");  print("You watch as your feather floats up, up and away on a sudden blast of "    "frigid air.");}Label2:set(f46);call(Logic103);if (isset(f220))
{  if (!isset(f224))
  {    set(f224);    set(egoHitSpecial);    print("Unable to grasp the ice pack,%m22");  }  if (v44 == 6 &&    v41 > 162)
  {    reset(f220);    print("Your assessment was correct!");  }}if (isset(f31) &&  isset(f235) &&  monitorType != MONO)
{  display(22, 22, "%v40/%v41, Area=%v220 ");  if (!isset(egoHitSpecial))
  {    display(23, 22, " ");  }  else
  {    toggle(f222);    if (isset(f222))
    {      display(23, 22, " S");    }    else
    {      display(23, 22, "S ");    }  }  if (!isset(onWater))
  {    display(23, 27, " ");  }  else
  {    toggle(f223);    if (isset(f223))
    {      display(23, 27, " W");    }    else
    {      display(23, 27, "W ");    }  }}if (edgeEgoHit > NOT_HIT)
{  reset(f46);  if (edgeEgoHit == TOP_EDGE &&    v40 < 60)
  {    new.room(Logic56);  }  if (edgeEgoHit == RIGHT_EDGE)
  {    new.room(Logic58);  }  if (edgeEgoHit == BOTTOM_EDGE)
  {    set(egoHitSpecial);  }}return();[Messages#message 1 "This is a very steep (and dangerous) cliff! Numerous caves honeycomb its face. You could get lost in the caves, IF you survive the cliff."#message 2 "A narrow path continues onward."#message 3 "There are no plants on this rocky cliff."#message 4 "The ground is far below you. Be careful!"#message 5 "The cliff face before you towers into the deep, blue sky."#message 6 "What trees?"#message 7 "Unable to grasp the ice pack,%m22"#message 8 "Your assessment was correct!"#message 9 "%v40/%v41, Area=%v220 "#message 10 "Boy, are these caves dark!"#message 11 " "#message 12 " S"#message 13 "S "#message 14 " W"#message 15 "W "#message 18 "The caverns in this mountain form a labyrinth of amazing complexity."#message 19 "The snow here has formed an icepack so hard it is impossible to gain a handhold."#message 20 "Not now!"#message 21 "Removing your hands from the sheer rock wall to rub the magic stone,%m22"#message 22 " you quickly assess your chances of surviving a 700-foot fall."#message 23 "As you reach for your fly wings, a sharp gust of wind blows them from your grasp."#message 24 "You watch as your feather floats up, up and away on a sudden blast of frigid air."#message 25 "You congratulate yourself on successfully eluding the abominable snowman."
