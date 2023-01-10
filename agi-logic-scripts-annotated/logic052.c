if (isset(newRoom))
{  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 4;  set(f57);  v57 = 50;  v58 = 93;  set.horizon(35);  load.logics(Logic103);  v34 = 166;  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
  {    if (previousRoom == 53)
    {      if (v41 < 82)
      {        v41 = 82;      }      if (v41 > 90)
      {        v41 = 90;      }    }    else
    {      if (previousRoom == 51)
      {        v40 = 42;        v41 = 167;      }      else
      {        v40 = v57;        v41 = v58;      }    }    position.v(ego, v40, v41);  }  if (isset(f47))
  {    draw(ego);  }  call(Logic103);  show.pic();  return();}if (!isset(haveInput))
{  goto(Label1);}if ((said("examine", "bluff") ||  said("examine", "top", "bluff") ||  said("examine", "up", "bluff") ||  said("examine") ||  said("examine", "down") ||  said("examine", "area") ||  said("examine", "up")))
{  print("The snow-capped mountains advance forever upward. A narrow path skims "    "along the top of a precipitous ridge. As you look down, you see the "    "steep cliff below you.");}if ((said("examine", "path") ||  said("examine", "up", "path")))
{  print("The thin path runs along the top of a steep ridge. You must be very "    "careful as one wrong step will mean death!");}if ((said("examine", "brush") ||  said("examine", "forest")))
{  print("A forest begins, with tall evergreen trees and low bushes.");}if (said("examine", "deck"))
{  print("The ground goes... way up, or way down. Better be careful.");}if ((said("examine", "sky") ||  said("examine", "up", "sky")))
{  print("You look upward and see the mountain range looming toward the "    "beautiful blue sky.");}if ((said("climb", "forest") ||  said("climb", "up", "forest")))
{  print("There are no climbable trees here.");}if ((said("capture", "flower") ||  said("capture", "flower") ||  said("examine", "flower")))
{  print("There are few flowers among the tall evergreens.");}Label1:v39 = 1;v34 = 166;if (posn(ego, 0, 0, 48, 106))
{  v39 = 2;  v34 = 156;  if (isset(egoHitSpecial))
  {    set.priority(ego, 4);    v33 = 6;  }}else
{  if (posn(ego, 55, 0, 84, 90))
  {    v39 = 3;    if (isset(egoHitSpecial))
    {      set.priority(ego, 4);      v33 = 6;      if (v40 > 76)
      {        v39 = 4;        v40 = 76;        reposition.to.v(ego, v40, v41);      }    }  }  else
  {    v39 = 5;    if (isset(egoHitSpecial))
    {      set.priority(ego, 11);      v33 = 6;      if (v40 < 33)
      {        v40 = 33;        reposition.to.v(ego, v40, v41);        v34 = 163;      }    }  }}call(Logic103);if (edgeEgoHit == BOTTOM_EDGE)
{  new.room(Logic51);}if (edgeEgoHit == RIGHT_EDGE)
{  new.room(Logic53);}return();[Messages#message 1 "The snow-capped mountains advance forever upward. A narrow path skims along the top of a precipitous ridge. As you look down, you see the steep cliff below you."#message 2 "The thin path runs along the top of a steep ridge. You must be very careful as one wrong step will mean death!"#message 3 "A forest begins, with tall evergreen trees and low bushes."#message 4 "The ground goes... way up, or way down. Better be careful."#message 5 "You look upward and see the mountain range looming toward the beautiful blue sky."#message 6 "There are no climbable trees here."#message 7 "There are few flowers among the tall evergreens."
