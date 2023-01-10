if (isset(newRoom))
{  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  v57 = 76;  v58 = 160;  set(f34);  if (isset(f48))
  {    if (previousRoom == 71)
    {      position(ego, 76, 163);    }  }  if (!isset(f198))
  {    set(f198);    currentScore += 4;  }  if (v44 == 30)
  {    set.view(ego, View0);    set(f48);    position.v(ego, v57, v58);    set(f47);  }  if (isset(f47))
  {    draw(ego);  }  if (isset(f182))
  {    load.logics(Logic119);    call(Logic119);  }  show.pic();  move.obj(ego, 71, 120, 1, f220);  return();}if (isset(f182))
{  call(Logic119);}if (isset(f220) &&  !isset(f221))
{  move.obj(ego, 0, 120, 1, f220);  set(f221);}if (said("examine", "castle"))
{  print("You and Princess Rosella have entered a hallway of the dilapidated "    "castle. Cracks mar the walls and dusty floor. Cobwebs drape an "    "overhanging lamp. Sadly, your sister remarks, \"Alexander, I wish you "    "could have seen it in better days. It wasn't always like this, you "    "know.\"");}if (said("examine", "burn"))
{  print("Cobwebs have not been cleaned from the overhanging chandelier.");}if (said("examine", "door"))
{  print("The doors of this castle are wide open.");}if (edgeEgoHit == BOTTOM_EDGE)
{  new.room(Logic71);}if (edgeEgoHit == LEFT_EDGE)
{  new.room(Logic74);}if (isset(f220) &&  isset(f221))
{  new.room(Logic74);}return();[Messages#message 1 "You and Princess Rosella have entered a hallway of the dilapidated castle. Cracks mar the walls and dusty floor. Cobwebs drape an overhanging lamp. Sadly, your sister remarks, \"Alexander, I wish you could have seen it in better days. It wasn't always like this, you know.\""#message 2 "Cobwebs have not been cleaned from the overhanging chandelier."#message 3 "The doors of this castle are wide open."
