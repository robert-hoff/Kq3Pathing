if (isset(newRoom))
{  set(f56);  v56 = 5;  set(f34);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  v57 = 153;  v58 = 165;  load.view(View0);  load.view(View11);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.sound(Sound1);  if (isset(f48))
  {    if (previousRoom == 67)
    {      position(ego, 14, 91);    }    if (previousRoom == 63)
    {      position(ego, 153, 165);    }  }  if (isset(f47))
  {    draw(ego);  }  if (isset(f182))
  {    if (previousRoom == 67)
    {      position(ego, 0, 88);    }    if (previousRoom == 63)
    {      position(ego, 153, 165);    }    load.logics(Logic119);    call(Logic119);  }  show.pic();  return();}if (isset(f230) &&  v230 == 0)
{  ++v230;  program.control();  move.obj(ego, 78, 88, 1, f230);}if (isset(f230) &&  v230 == 1)
{  ++v230;  program.control();  move.obj(ego, 154, 168, 1, f230);}if (!isset(f46) &&  isset(egoHitSpecial) &&  !isset(f220))
{  set(f46);  prevent.input();  set(f220);  ignore.blocks(ego);  get.priority(ego, v36);  set.priority.v(ego, v36);  set.view(ego, View11);  sound(Sound1, f238);  v36 = 4;  cycle.time(ego, v36);  v37 = v40;  v38 = 164;  v36 = 3;  move.obj.v(ego, v37, v38, v36, f221);}if (isset(f221))
{  reset(f221);  erase(ego);  set(f44);  print("No fair taking short cuts!");  reset(f46);}if (isset(f182))
{  call(Logic119);}if ((said("examine", "up") ||  said("examine", "down") ||  said("examine") ||  said("examine", "cave") ||  said("look in", "cave")))
{  print("Finally, the top of the cave! You notice bright light streaming in "    "from outside the cave. Looking down, you see the crumbly stone steps "    "precariously descending into the bowels of the mountain.");}if ((said("examine", "up", "stair") ||  said("examine", "down", "stair") ||  said("examine", "stair")))
{  print("You gaze nervously down the steep stone steps leading into the pit of "    "the mountain. Swallowing hard, you realize how dangerous they are.");}if ((said("examine", "out") ||  said("examine", "out", "cave")))
{  print("It's very bright outside.  You think you see clouds.");}if ((edgeEgoHit == RIGHT_EDGE ||  edgeEgoHit == BOTTOM_EDGE))
{  new.room(Logic63);}if (edgeEgoHit == LEFT_EDGE)
{  new.room(Logic67);}return();[Messages#message 1 "Finally, the top of the cave! You notice bright light streaming in from outside the cave. Looking down, you see the crumbly stone steps precariously descending into the bowels of the mountain."#message 2 "You gaze nervously down the steep stone steps leading into the pit of the mountain. Swallowing hard, you realize how dangerous they are."#message 3 "It's very bright outside.  You think you see clouds."#message 5 "No fair taking short cuts!"
