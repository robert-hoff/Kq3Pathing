if (isset(newRoom))
{  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 4;  set(f63);  v57 = 60;  v58 = 111;  set.horizon(1);  load.logics(Logic103);  v34 = 166;  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
  {    if (previousRoom == 57)
    {      position(ego, 0, 138);    }    else
    {      if (previousRoom == 59)
      {        position(ego, 152, 155);      }    }  }  if (isset(f47))
  {    draw(ego);  }  call(Logic103);  show.pic();  return();}if (!isset(haveInput))
{  goto(Label1);}if ((said("examine", "bluff") ||  said("examine", "up", "bluff") ||  said("examine") ||  said("examine", "up") ||  said("examine", "area") ||  said("examine", "down")))
{  print("You carefully make your way down the eastern side of these mountains. "    "The path travels along the top of a narrow ridge. Looking back, you "    "see the snowy peaks through which you so recently journeyed. Whew! You "    "wipe your brow as you feel the worst is now behind you.");}if (said("examine", "path"))
{  print("You are walking along a steep ridgetop on a treacherous path. One "    "wrong step could mean instant death. Be careful!");}if ((said("examine", "brush") ||  said("examine", "forest")))
{  print("You see numerous evergreen trees and bushes. The forest is very "    "tranquil.");}if (said("examine", "deck"))
{  print("The ground is covered with a crunchy carpet of pine needles.");}if (said("examine", "sky"))
{  print("Looking back, you see snow-capped peaks thrusting their way upward "    "toward an azure sky.");}if ((said("climb", "forest") ||  said("climb", "up", "forest")))
{  print("There are no climbable trees here.");}if ((said("capture", "flower") ||  said("capture", "flower") ||  said("examine", "flower")))
{  print("You see no flowers around here.");}Label1:v39 = 0;if (isset(egoHitSpecial))
{  if (v41 < 116)
  {    v39 = 1;    set.priority(ego, 4);  }  else
  {    if (posn(ego, 143, 138, 159, 145))
    {      v39 = 2;      set.priority(ego, 9);    }    else
    {      if (posn(ego, 126, 127, 144, 139))
      {        v39 = 3;        set.priority(ego, 9);      }      else
      {        v39 = 4;        set.priority(ego, 14);      }    }  }}call(Logic103);if (edgeEgoHit == LEFT_EDGE)
{  if ((v44 == 25 ||    v44 == 26))
  {    edgeEgoHit = NOT_HIT;    v71 = 5;  }  else
  {    new.room(Logic57);  }}if (edgeEgoHit == RIGHT_EDGE)
{  new.room(Logic59);}return();[Messages#message 1 "You carefully make your way down the eastern side of these mountains. The path travels along the top of a narrow ridge. Looking back, you see the snowy peaks through which you so recently journeyed. Whew! You wipe your brow as you feel the worst is now behind you."#message 2 "You are walking along a steep ridgetop on a treacherous path. One wrong step could mean instant death. Be careful!"#message 3 "You see numerous evergreen trees and bushes. The forest is very tranquil."#message 4 "The ground is covered with a crunchy carpet of pine needles."#message 5 "Looking back, you see snow-capped peaks thrusting their way upward toward an azure sky."#message 6 "There are no climbable trees here."#message 7 "You see no flowers around here."
