if (isset(newRoom))
{  reset(f46);  set(f34);  if (!isset(f197))
  {    set(f197);    currentScore += 2;  }  v57 = 93;  v58 = 136;  ignore.blocks(ego);  load.view(View0);  load.view(View11);  load.view(View30);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.sound(Sound1);  load.sound(Sound6);  if (v44 == 25)
  {    set(f48);    set(f47);  }  if (isset(f48))
  {    if (previousRoom == 38)
    {      start.motion(ego);      egoDir = RIGHT;      position(ego, 83, 110);      if (v172 == 1)
      {        animate.obj(o1);        load.view(View210);        set.view(o1, View210);        ignore.blocks(o1);        ignore.objs(o1);        position(o1, 70, 113);        v36 = 2;        cycle.time(o1, v36);        draw(o1);        follow.ego(o1, 5, f221);        start.motion(ego);        program.control();      }    }    if (previousRoom == 22)
    {      v44 = 15;      position(ego, 93, 165);      set.view(ego, View30);      set.loop(ego, 0);      fix.loop(ego);    }  }  if (previousRoom != 89 &&    previousRoom != 38)
  {    random(1, 255, v36);    if (v36 > 64)
    {      v172 = 1;    }    else
    {      v172 = 0;    }  }  if (v44 == 30)
  {    set(f48);    set(f47);    v44 = 15;    position(ego, 93, 165);    set.view(ego, View30);    set.loop(ego, 0);    fix.loop(ego);  }  if (isset(f47))
  {    draw(ego);  }  show.pic();  return();}if (isset(f33) &&  v44 == 0)
{  ignore.blocks(ego);  v44 = 15;  set.view(ego, View30);  set.loop(ego, 0);  fix.loop(ego);}v39 = 0;if (posn(ego, 89, 110, 91, 116))
{  v39 = 2;}if (posn(ego, 70, 98, 73, 114))
{  v39 = 1;}if (v44 == 0 &&  v39 == 2 &&  (egoDir == RIGHT ||    egoDir == DOWN_RIGHT ||    egoDir == UP_RIGHT))
{  set.view(ego, View30);  set.loop(ego, 0);  fix.loop(ego);  v40 = 93;  reposition.to.v(ego, v40, v41);  start.motion(ego);  v44 = 15;}if (v44 == 15 &&  v39 == 2 &&  (egoDir == LEFT ||    egoDir == DOWN_LEFT ||    egoDir == UP_LEFT))
{  release.loop(ego);  set.view(ego, View0);  v40 = 87;  reposition.to.v(ego, v40, v41);  start.motion(ego);  set.loop(ego, 1);  v44 = 0;}if (v44 == 6)
{  set(f221);}if (isset(f221))
{  reset(f221);  stop.motion(o1);  normal.motion(o1);  stop.cycling(o1);  set(egoHitSpecial);}if (v44 != 6 &&  isset(egoHitSpecial))
{  sound(Sound1, f238);  set.view(ego, View11);  set.priority(ego, 15);  v38 = 167;  v36 = 6;  move.obj.v(ego, v40, v38, v36, f220);  v44 = 6;}if (isset(f220))
{  reset(f220);  edgeEgoHit = BOTTOM_EDGE;  erase(ego);}if (has("Storm Brew*") &&  v71 == 8)
{  v71 = 0;  print("On second thought, you decide not to make a storm. You remember how "    "dangerous it is to be in a tree during a storm.");}if (isset(haveInput))
{  if ((said("examine") ||    said("examine", "building") ||    said("examine", "forest")))
  {    print("You are standing outside a shack that has been built in the branches "      "of the spreading oak tree. A rope ladder leads down toward the "      "ground.");  }  if ((said("look in", "building") ||    said("look in") ||    said("look in", "door", "building") ||    said("examine", "inside", "area") ||    said("look in", "door")))
  {    if (v172 == 1)
    {      print("There seems to be somebody moving around inside the treehouse.");    }    else
    {      print("You can see very little of the interior from out here. But there "        "seems to be a figure sleeping in a chair.");    }  }  if (said("examine", "door"))
  {    print("The doorway of the treehouse is only a rough opening in the planks.");  }  if (said("anyword", "glass"))
  {    print("There is no window, only a hole cut in the side.");  }  if ((said("examine", "rope", "ladder") ||    said("examine", "ladder")))
  {    print("The rope ladder drops down through the leaves of the huge tree "      "toward the ground below.");  }  if ((said("climb", "forest") ||    said("climb", "up", "forest") ||    said("climb", "down", "forest")))
  {    print("The tree looks very difficult to climb around on, but you can try if "      "you wish.");  }  if ((said("examine", "sky") ||    said("examine", "up")))
  {    print("The thick leaves of the oak tree allow only rare glimpses of the sky "      "above.");  }  if ((said("examine", "deck") ||    said("examine", "down")))
  {    print("The thick leaves and massive branches obscure the ground below.");  }  if (said("examine", "bandit"))
  {    if (v172 == 1)
    {      print("You can see someone moving about, but can not make out details "        "from here.");    }    else
    {      print("You see no one else around.");    }  }}if (edgeEgoHit == BOTTOM_EDGE)
{  new.room(Logic22);}if (v39 == 1 &&  v44 == 0)
{  new.room(Logic38);}return();[Messages#message 1 "You are standing outside a shack that has been built in the branches of the spreading oak tree. A rope ladder leads down toward the ground."#message 2 "There seems to be somebody moving around inside the treehouse."#message 3 "You can see very little of the interior from out here. But there seems to be a figure sleeping in a chair."#message 4 "The doorway of the treehouse is only a rough opening in the planks."#message 5 "There is no window, only a hole cut in the side."#message 6 "The rope ladder drops down through the leaves of the huge tree toward the ground below."#message 7 "The tree looks very difficult to climb around on, but you can try if you wish."#message 8 "The thick leaves of the oak tree allow only rare glimpses of the sky above."#message 9 "The thick leaves and massive branches obscure the ground below."#message 10 "You can see someone moving about, but can not make out details from here."#message 11 "You see no one else around."#message 12 "It's hard to tell without entering."#message 13 "On second thought, you decide not to make a storm. You remember how dangerous it is to be in a tree during a storm."
