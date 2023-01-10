if (isset(newRoom))
{  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  v56 = 2;  set(f66);  set.horizon(56);  v32 = 124;  v31 = 129;  random(1, 3, v36);  if (v36 == 1)
  {    v57 = 18;    v58 = 76;  }  else
  {    if (v36 == 2)
    {      v57 = 74;      v58 = 56;    }    else
    {      v57 = 135;      v58 = 131;    }  }  load.logics(Logic111);  if (!isset(f78))
  {    random(1, 3, v36);    if (v36 == 1)
    {      set(f220);      load.logics(Logic115);      v31 = 0;    }  }  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
  {    if (previousRoom == 18)
    {      if (v40 > 24 &&        v40 < 70)
      {        v40 = 62;      }    }    if (previousRoom == 22)
    {      if (v41 > 139 &&        v41 < 147)
      {        v41 = 139;      }    }    position.v(ego, v40, v41);  }  if (isset(f47))
  {    draw(ego);  }  call(Logic111);  if (isset(f220))
  {    call(Logic115);  }  show.pic();  return();}if (isset(haveInput))
{  if ((said("examine", "brush") ||    said("examine", "deck")))
  {    print("The soft grass soothes your aching feet.");  }  if ((said("examine", "bluff") ||    said("examine", "top", "bluff")))
  {    print("A lone mountain rises sharply from the forest floor, its jagged peak "      "encircled by dark clouds. A treacherous path winds its way up the "      "steep mountainside. You, and the wizard Manannan, live at the top of "      "the peak.");  }  if ((said("examine", "path") ||    said("examine", "path", "bluff") ||    said("examine", "bluff", "path")))
  {    print("The dangerous, winding path leads up the side of the dark mountain.");  }  if ((said("climb") ||    said("climb", "bluff")))
  {    print("You need to be closer to the mountain for that.");  }}call(Logic111);if (isset(f220))
{  call(Logic115);}if (edgeEgoHit == BOTTOM_EDGE)
{  new.room(Logic28);}if (edgeEgoHit == TOP_EDGE)
{  new.room(Logic18);}if (edgeEgoHit == LEFT_EDGE)
{  new.room(Logic22);}if (edgeEgoHit == RIGHT_EDGE)
{  new.room(Logic24);}return();[Messages#message 1 "The soft grass soothes your aching feet."#message 2 "The many beautiful trees bring a sense of peace to this forest."#message 3 "A lone mountain rises sharply from the forest floor, its jagged peak encircled by dark clouds. A treacherous path winds its way up the steep mountainside. You, and the wizard Manannan, live at the top of the peak."#message 4 "The dangerous, winding path leads up the side of the dark mountain."#message 5 "You need to be closer to the mountain for that."
