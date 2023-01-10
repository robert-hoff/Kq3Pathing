if (isset(newRoom))
{  v56 = 5;  set(f54);  set(f34);  v57 = 2;  v58 = 156;  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.view(View0);  load.view(View11);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.sound(Sound1);  load.sound(Sound6);  if (isset(f48))
  {    if (previousRoom == 61)
    {      start.motion(ego);      position(ego, 2, 156);    }    if (previousRoom == 63)
    {      position(ego, 117, 43);    }  }  if (isset(f47))
  {    draw(ego);  }  if (isset(f182))
  {    load.logics(Logic119);    call(Logic119);  }  show.pic();  return();}if (!isset(f46) &&  isset(egoHitSpecial) &&  !isset(f220))
{  set(f46);  prevent.input();  set(f220);  ignore.blocks(ego);  get.priority(ego, v36);  set.priority.v(ego, v36);  set.view(ego, View11);  sound(Sound1, f238);  v36 = 4;  cycle.time(ego, v36);  v37 = v40;  v38 = 164;  v36 = 3;  move.obj.v(ego, v37, v38, v36, f221);}if (isset(f221))
{  reset(f221);  reset(f46);  erase(ego);  set(f44);  print("Watch out for that first step. It's a dilly.");}if (isset(f182))
{  call(Logic119);}if ((said("examine", "up") ||  said("examine", "down") ||  said("examine") ||  said("examine", "cave")))
{  print("This cave is merely the entrance to crumbly stone steps that lead "    "upward into the depths of the mountain. Pebbles and little rocks lie "    "scattered upon the cave floor.");}if ((said("examine", "up", "stair") ||  said("examine", "down", "stair") ||  said("examine", "stair")))
{  print("The stone steps go up into the very depths of this mountain. Not only "    "are they crumbly, but they are also very steep!");}if (said("examine", "deck"))
{  print("Little stones and pebbles from the steps have fallen and lie scattered "    "around the cave floor.");}if ((said("examine", "out") ||  said("examine", "out", "cave")))
{  print("You see the charred trees of Daventry outside the cave.");}if (v41 < 40)
{  new.room(Logic63);}if (edgeEgoHit == LEFT_EDGE)
{  new.room(Logic61);}return();[Messages#message 1 "This cave is merely the entrance to crumbly stone steps that lead upward into the depths of the mountain. Pebbles and little rocks lie scattered upon the cave floor."#message 2 "The stone steps go up into the very depths of this mountain. Not only are they crumbly, but they are also very steep!"#message 3 "Little stones and pebbles from the steps have fallen and lie scattered around the cave floor."#message 4 "You see the charred trees of Daventry outside the cave."#message 5 "Watch out for that first step. It's a dilly."
