if (isset(newRoom))
{  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 4;  set(f64);  v57 = 150;  v58 = 126;  set.horizon(1);  load.logics(Logic103);  v34 = 166;  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
  {    if (previousRoom == 58)
    {      position(ego, 0, 49);    }  }  if (isset(f47))
  {    draw(ego);  }  call(Logic103);  show.pic();  return();}if (!isset(haveInput))
{  goto(Label1);}if ((said("examine", "bluff") ||  said("examine", "up", "bluff") ||  said("examine", "up") ||  said("examine") ||  said("examine", "area") ||  said("examine", "down")))
{  print("You carefully make your way down the eastern side of these mountains. "    "The path travels along the top of a narrow ridge. Looking back, you "    "see the snowy peaks through which you so recently journeyed. Whew! You "    "wipe your brow as you feel the worst is now behind you.");}if (said("examine", "path"))
{  print("You are trekking along a steep ridgetop on a treacherous path. One "    "wrong step could mean instant death. Be careful!");}if ((said("examine", "brush") ||  said("examine", "forest")))
{  print("You see numerous evergreen trees and bushes. The forest is very "    "tranquil.");}if (said("examine", "deck"))
{  print("The ground is covered with a crunchy carpet of pine needles.");}if (said("examine", "sky"))
{  print("Looking back, you see snow-capped peaks thrusting their way upward "    "toward an azure sky.");}if ((said("climb", "forest") ||  said("climb", "up", "forest")))
{  print("There are no climbable trees here.");}if ((said("capture", "flower") ||  said("capture", "flower") ||  said("examine", "flower")))
{  print("You see no flowers around here.");}Label1:v39 = 0;if (isset(egoHitSpecial))
{  v33 = 6;  if ((posn(ego, 0, 37, 44, 51) ||    posn(ego, 39, 51, 108, 64) ||    posn(ego, 108, 61, 159, 71)))
  {    v39 = 1;    set.priority(ego, 4);  }  else
  {    set.priority(ego, 7);    if (posn(ego, 90, 79, 130, 94))
    {      v39 = 2;      v40 = 90;      reposition.to.v(ego, v40, v41);    }    else
    {      v39 = 3;    }  }}call(Logic103);if (edgeEgoHit == BOTTOM_EDGE)
{  new.room(Logic61);}if (edgeEgoHit == LEFT_EDGE)
{  new.room(Logic58);}return();[Messages#message 1 "You carefully make your way down the eastern side of these mountains. The path travels along the top of a narrow ridge. Looking back, you see the snowy peaks through which you so recently journeyed. Whew! You wipe your brow as you feel the worst is now behind you."#message 2 "You are trekking along a steep ridgetop on a treacherous path. One wrong step could mean instant death. Be careful!"#message 3 "You see numerous evergreen trees and bushes. The forest is very tranquil."#message 4 "The ground is covered with a crunchy carpet of pine needles."#message 5 "Looking back, you see snow-capped peaks thrusting their way upward toward an azure sky."#message 6 "There are no climbable trees here."#message 7 "You see no flowers around here."
