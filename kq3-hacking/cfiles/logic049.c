if (isset(newRoom))
  {  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.sound(Sound38);  reset(f238);  load.logics(Logic112);  load.logics(Logic120);  load.logics(Logic108);  set.horizon(70);  v56 = 4;  set(f54);  v57 = 20;  v58 = 74;  load.view(View0);  load.view(View24);  load.view(View2);  load.view(View3);  load.view(View4);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  if (isset(f48))
    {    if (previousRoom == 31)
      {      // [ WARNING: this block contains no commands      }    if (previousRoom == 48)
      {      // [ WARNING: this block contains no commands      }    if (previousRoom == 51)
      {      v40 = 114;      position.v(ego, v40, v41);      }    if (previousRoom == 50)
      {      v40 = 24;      position.v(ego, v40, v41);      }    }  if (isset(f47))
    {    draw(ego);    }  animate.obj(o4);  load.view(View56);  set.view(o4, View56);  position(o4, 150, 150);  object.on.water(o4);  draw(o4);  wander(o4);  if (v62 == 4)
    {    set(f81);    set(f226);    animate.obj(o1);    load.view(View163);    load.view(View165);    set.view(o1, View163);    position(o1, 80, 120);    object.on.land(o1);    if ((isset(f49) ||        v44 != 0))
      {      wander(o1);      }    else
      {      follow.ego(o1, 5, f224);      }    draw(o1);    object.on.land(o1);    }  v36 = 0;  call(Logic112);  call(Logic120);  call(Logic108);  show.pic();  sound(Sound38, f238);  return();  }if (said("examine", "shark"))
  {  print("A prowling shark waits offshore.");  }if (said("capture", "shark"))
  {  print("You've got to be kidding.");  }if (said("kill", "shark"))
  {  print("You have no way of killing a shark.");  }if (said("call", "shark"))
  {  print("He can't understand you.");  }if (isset(f226) &&    (said("capture", "bandit") ||    said("kill", "bandit")))
  {  print("You're no match for him!");  }if (isset(f226) &&    said("examine", "bandit"))
  {  print("A nasty pirate is here!");  }if (isset(f226) &&    said("call", "bandit"))
  {  print("\"Arrr! I'm gonna git ya laddie!\"");  }if (said("climb", "forest"))
  {  print("You have better things to do than to try to climb this tree.");  }if ((said("examine") ||    said("examine", "beach")))
  {  print("You are on a small beach to the south of a looming mountain range.");  }if (said("examine", "bluff"))
  {  print("To the north, a mountain range beckons.");  }if (said("examine", "forest"))
  {  print("A lone palm tree graces this beach.");  }if (said("examine", "deck"))
  {  print("Yep. It's sandy here.");  }if (isset(f33) &&    isset(f226))
  {  if (v44 != 0)
    {    start.cycling(o1);    wander(o1);    }  else
    {    start.cycling(o1);    follow.ego(o1, 5, f224);    }  }if (isset(f226) &&    !isset(f227))
  {  set(f227);  print("Not again! One of the nasty pirates is here on the beach, and he would "        "like to capture you. You'd better run!");  }if (isset(f224))
  {  reset(f224);  if (!isset(f46))
    {    print("How could you! You let yourself get caught again! Well, it's "          "curtains for you this time.");    set(f46);    program.control();    set.view(o1, View165);    set.cel(o1, 0);    end.of.loop(o1, f225);    }  else
    {    stop.cycling(o1);    }  }if (isset(f225))
  {  reset(f225);  set.view(ego, View24);  set(f44);  reset(f46);  }if (isset(f220) &&    (v44 == 11 ||    v44 == 224))
  {  reset(f220);  if (!isset(f46))
    {    set(f46);    erase(o4);    stop.motion(ego);    set(f35);    v44 = 13;    set.view(ego, View4);    set.cel(ego, 0);    v36 = 4;    cycle.time(ego, v36);    end.of.loop(ego, f222);    }  }if (isset(f222))
  {  reset(f222);  erase(ego);  set(f44);  print("Gosh! You barely made a mouthful for that hungry shark!");  }if ((v44 == 224 ||    v44 == 11))
  {  if (!isset(f223))
    {    set(f223);    follow.ego(o4, 8, f220);    }  }else
  {  reset(f220);  if (isset(f223))
    {    reset(f223);    wander(o4);    }  }if (objHitEdge == 4)
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
  {  v44 = 0;  set.view(ego, View0);  }if (isset(onWater) &&    v44 == 224 &&    (posn(ego, 118, 140, 160, 167) ||    posn(ego, 138, 84, 160, 167)))
  {  v44 = 11;  set.view(ego, View3);  set(f35);  }call(Logic112);call(Logic120);call(Logic108);if (edgeEgoHit == TOP_EDGE)
  {  if ((v44 == 11 ||      v44 == 224))
    {    set.view(ego, View0);    current.view(ego, currentEgoView);    reset(f35);    v44 = 0;    }  v62 = 5;  set(f181);  if (v40 > 76)
    {    new.room(Logic51);    }  else
    {    new.room(Logic50);    }  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic48);  }if ((edgeEgoHit == BOTTOM_EDGE ||    edgeEgoHit == RIGHT_EDGE))
  {  if ((v44 == 11 ||      v44 == 224))
    {    set.view(ego, View3);    current.view(ego, currentEgoView);    }  v176 = edgeEgoHit;  new.room(Logic31);  }return();[ Messages#message 1 "Not again! One of the nasty pirates is here on the beach, and he would like to capture you. You'd better run!"#message 2 "Gosh! You barely made a mouthful for that hungry shark!"#message 3 "You've got to be kidding."#message 4 "A prowling shark waits offshore."#message 5 "He can't understand you."#message 6 "You are on a small beach to the south of a looming mountain range."#message 7 "To the north, a mountain range beckons."#message 8 "Yep. It's sandy here."#message 9 "You have no way of killing a shark."#message 10 "You have better things to do than to try to climb this tree."#message 11 "A lone palm tree graces this beach."#message 12 "How could you! You let yourself get caught again! Well, it's curtains for you this time."#message 13 "He doesn't understand you."#message 14 "A nasty pirate is here!"#message 15 "\"Arrr! I'm gonna git ya laddie!\""#message 16 "You're no match for him!"