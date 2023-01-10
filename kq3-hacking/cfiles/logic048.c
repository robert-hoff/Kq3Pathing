if (isset(newRoom))
  {  v36 = currentRoom;  if (v62 != 4)
    {    v36  += 100;    }  load.pic(v36);  draw.pic(v36);  discard.pic(v36);  load.logics(Logic120);  load.logics(Logic112);  load.logics(Logic108);  load.sound(Sound38);  if (!isset(f52))
    {    currentScore  += 5;    v36 = 73;Label1:    if (v36 > 52)
      {      reset.v(v36);      --v36;      goto(Label1);      }    set(f52);    set(f54);    }  set.horizon(60);  v57 = 120;  v58 = 80;  load.view.v(currentEgoView);  load.view(View0);  load.view(View2);  load.view(View3);  load.view(View4);  set.view.v(ego, currentEgoView);  if (isset(f48))
    {    get.posn(ego, v40, v41);    if (v56 == 7)
      {      v40 = 20;      v41 = 74;      egoDir = DOWN;      v44 = 11;      set.view(ego, View3);      }    if (previousRoom == 49)
      {      // [ WARNING: this block contains no commands      }    }  if (isset(f47))
    {    draw(ego);    }  v56 = 4;  animate.obj(o4);  load.view(View56);  set.view(o4, View56);  position(o4, 0, 60);  object.on.water(o4);  draw(o4);  wander(o4);  reset(f222);  v36 = 0;  call(Logic112);  call(Logic120);  call(Logic108);  show.pic();  sound(Sound38, f238);  return();  }if (said("examine", "shark"))
  {  print("A prowling shark waits offshore.");  }if (said("capture", "shark"))
  {  print("You've got to be kidding?!");  }if (said("kill", "shark"))
  {  print("You have no way of killing a shark.");  }if (said("call", "shark"))
  {  print("He doesn't understand you.");  }if ((said("examine", "ship") ||    said("examine", "bandit", "ship")))
  {  if (v62 == 4)
    {    print("The pirate ship is anchored just offshore. You'd best be on your "          "way.");    }  else
    {    print("The pirate's ship is nowhere in sight!");    }  }if ((said("examine") ||    said("examine", "beach")))
  {  print("You are on a small beach to the south of a looming mountain range.");  }if (said("examine", "deck"))
  {  print("Yep. It's sandy here.");  }if (said("examine", "forest"))
  {  print("You see no trees.");  }if (said("examine", "bluff"))
  {  print("To the north, a mountain range beckons.");  }if (isset(f220) &&    (v44 == 11 ||    v44 == 224))
  {  set(f46);  erase(o4);  stop.motion(ego);  set(f35);  v44 = 13;  set.view(ego, View4);  set.cel(ego, 0);  v36 = 4;  cycle.time(ego, v36);  end.of.loop(ego, f221);  }if (isset(f221))
  {  reset(f221);  erase(ego);  set(f44);  print("Gosh! You barely made a mouthful for that hungry shark!");  }if ((v44 == 224 ||    v44 == 11))
  {  if (!isset(f222))
    {    set(f222);    follow.ego(o4, 8, f220);    }  }else
  {  reset(f220);  if (isset(f222))
    {    reset(f222);    wander(o4);    }  }if (objHitEdge == 4)
  {  get.dir(o4, v36);  if (edgeObjHit == RIGHT_EDGE)
    {    if (v36 == 2)
      {      v36 = 1;      }    if (v36 == 4)
      {      v36 = 5;      }    set.dir(o4, v36);    }  if (edgeObjHit == LEFT_EDGE)
    {    if (v36 == 8)
      {      v36 = 1;      }    if (v36 == 6)
      {      v36 = 5;      }    set.dir(o4, v36);    }  }if (isset(egoHitSpecial))
  {  set(onWater);  if (v44 == 11)
    {    v44 = 224;    set.view(ego, View2);    reset(f35);    }  if (v44 == 0)
    {    v44 = 224;    set.view(ego, View2);    }  }if (v44 == 224 &&    !isset(onWater) &&    !isset(egoHitSpecial))
  {  v44 = 0;  set.view(ego, View0);  }if (isset(onWater) &&    v44 == 224 &&    posn(ego, 0, 0, 70, 168))
  {  v44 = 11;  set.view(ego, View3);  set(onWater);  }call(Logic120);call(Logic112);call(Logic108);if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic49);  }if ((edgeEgoHit == LEFT_EDGE ||    edgeEgoHit == BOTTOM_EDGE))
  {  if ((v44 == 11 ||      v44 == 224))
    {    set.view(ego, View3);    current.view(ego, currentEgoView);    v44 = 11;    }  v176 = edgeEgoHit;  new.room(Logic31);  }return();[ Messages#message 1 "Gosh! You barely made a mouthful for that hungry shark!"#message 2 "A prowling shark waits offshore."#message 3 "You've got to be kidding?!"#message 4 "The pirate ship is anchored just offshore. You'd best be on your way."#message 5 "The pirate's ship is nowhere in sight!"#message 6 "You are on a small beach to the south of a looming mountain range."#message 7 "To the north, a mountain range beckons."#message 8 "Yep. It's sandy here."#message 9 "You see no trees."#message 10 "You have no way of killing a shark."#message 11 "He doesn't understand you."