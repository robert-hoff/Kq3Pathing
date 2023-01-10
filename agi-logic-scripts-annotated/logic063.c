if (isset(newRoom))
  {  v56 = 5;  set(f55);  set(f34);  v57 = 92;  v58 = 156;  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.view(View0);  load.view(View11);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.sound(Sound1);  if (isset(f48))
    {    if (previousRoom == 62)
      {      position(ego, 92, 165);      }    if (previousRoom == 64)
      {      position(ego, 45, 39);      }    }  if (v44 == 30)
    {    set.view(ego, View0);    set(f48);    position.v(ego, v57, v58);    set(f47);    }  if (isset(f47))
    {    draw(ego);    }  if (isset(f182))
    {    load.logics(Logic119);    call(Logic119);    }  show.pic();  return();  }if (!isset(f46) &&     isset(egoHitSpecial) &&     !isset(f220))
  {  set(f46);  prevent.input();  set(f220);  ignore.blocks(ego);  set.view(ego, View11);  sound(Sound1, f238);  v36 = 4;  cycle.time(ego, v36);  v37 = v40;  v38 = 164;  v36 = 3;  set.priority(ego, 15);  move.obj.v(ego, v37, v38, v36, f221);  }if (isset(f221))
  {  reset(f46);  reset(f221);  erase(ego);  set(f44);  print("Darn those steps!");  }if (isset(f182))
  {  call(Logic119);  }if ((said("examine", "up") ||     said("examine", "down") ||     said("examine") ||     said("examine", "cave")))
  {  print("Crumbled stone steps go upward into the depths of this mountain. To "        "your amazement, you see light coming down from above. Looking down, "        "you see the stairs steeply descending below you.");  }if ((said("examine", "up", "stair") ||     said("examine", "down", "stair") ||     said("examine", "stair")))
  {  print("The stone steps go up into the very depths of this mountain. Not only "        "are they crumbly, but they are also very steep!");  }if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic62);  }if (edgeEgoHit == TOP_EDGE)
  {  new.room(Logic64);  }return();[ Messages#message 1 "Crumbled stone steps go upward into the depths of this mountain. To your amazement, you see light coming down from above. Looking down, you see the stairs steeply descending below you."#message 2 "The stone steps go up into the very depths of this mountain. Not only are they crumbly, but they are also very steep!"#message 3 ""#message 5 "Darn those steps!"