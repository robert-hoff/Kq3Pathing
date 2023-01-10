if (isset(newRoom))
{  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 2;  set(f59);  set.horizon(56);  v32 = 130;  if (isset(f111))
  {    v31 = 90;  }  random(1, 3, v36);  if (v36 == 1)
  {    v57 = 140;    v58 = 75;  }  else
  {    if (v36 == 2)
    {      v57 = 90;      v58 = 140;    }    else
    {      v57 = 10;      v58 = 70;    }  }  load.logics(Logic128);  load.logics(Logic118);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f47))
  {    draw(ego);  }  call(Logic128);  call(Logic118);  show.pic();  return();}call(Logic128);call(Logic118);if (edgeEgoHit == BOTTOM_EDGE)
{  new.room(Logic21);}if (edgeEgoHit == TOP_EDGE)
{  new.room(Logic11);}if (edgeEgoHit == LEFT_EDGE)
{  new.room(Logic32);}if (edgeEgoHit == RIGHT_EDGE)
{  new.room(Logic17);}return();[Messages
