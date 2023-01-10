if (isset(newRoom))
{  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 2;  set(f58);  set.horizon(64);  v32 = 16;  v31 = 161;  v57 = 143;  v58 = 102;  load.logics(Logic112);  load.logics(Logic120);  load.logics(Logic113);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
  {    if (previousRoom == 29)
    {      v40 = 4;    }    if (previousRoom == 30)
    {      v40 = 89;      if ((v138 == 7 ||        v44 == 224))
      {        v40 = 117;      }      if (v138 == 2)
      {        v40 = 125;      }      if ((v138 == 3 ||        v44 == 11))
      {        v40 = 142;      }    }    if (previousRoom == 20)
    {      if (v40 > 49 &&        v40 < 68)
      {        v40 = 49;      }      if ((v138 == 7 ||        v44 == 224))
      {        v40 = 123;      }      if (v138 == 2)
      {        v40 = 136;      }      if ((v138 == 3 ||        v44 == 11))
      {        v40 = 148;      }    }    if (previousRoom == 14)
    {      if (v41 > 140 &&        v41 < 147)
      {        v41 = 147;      }    }    position.v(ego, v40, v41);  }  if (isset(f47))
  {    draw(ego);  }  v36 = 1;  call(Logic112);  reposition.to(o12, 99, 19);  reposition.to(o13, 111, 11);  call(Logic120);  call(Logic113);  show.pic();  return();}v138 = 0;if (isset(onWater))
{  v138 = 7;}if ((posn(ego, 124, 0, 132, 89) ||  posn(ego, 133, 90, 141, 143) ||  posn(ego, 136, 144, 141, 167)))
{  v138 = 2;}if ((posn(ego, 133, 0, 159, 89) ||  posn(ego, 142, 90, 159, 167)))
{  v138 = 3;}if (isset(egoHitSpecial))
{  if (posn(ego, 40, 98, 58, 101))
  {    v37 = 0;    v38 = 7;    reposition(ego, v37, v38);  }  if (posn(ego, 59, 100, 70, 103))
  {    v37 = 0;    v38 = 15;    reposition(ego, v37, v38);  }  if (posn(ego, 71, 96, 80, 105))
  {    reposition.to(ego, 78, 116);  }  if (posn(ego, 50, 133, 60, 167))
  {    v37 = 72;    reposition.to.v(ego, v37, v41);  }}call(Logic112);call(Logic120);call(Logic113);if (edgeEgoHit == BOTTOM_EDGE)
{  new.room(Logic20);}if (edgeEgoHit == LEFT_EDGE)
{  new.room(Logic14);}if (edgeEgoHit == RIGHT_EDGE)
{  new.room(Logic31);}if (edgeEgoHit == TOP_EDGE)
{  if (v40 > 25)
  {    new.room(Logic30);  }  else
  {    new.room(Logic29);  }}return();[Messages
