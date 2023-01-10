if (isset(newRoom))
  {  load.view.v(currentEgoView);  load.view(View0);  set.view.v(ego, currentEgoView);  v56 = 2;  set(f55);  set.horizon(60);  v32 = 89;  v31 = 138;  v57 = 137;  v58 = 128;  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.logics(Logic129);  load.logics(Logic111);  load.logics(Logic114);  if (isset(f48))
    {    if (previousRoom == 17)
      {      if (v40 > 136)
        {        v40 = 136;        }      }    if (previousRoom == 13)
      {      if (v41 > 130 &&           v41 < 109)
        {        v41 = 109;        }      if (v41 > 127 &&           v41 < 133)
        {        v41 = 127;        }      if (v41 > 155)
        {        v41 = 155;        }      }    position.v(ego, v40, v41);    }  if (isset(f47))
    {    draw(ego);    }  call(Logic111);  call(Logic114);  show.pic();  return();  }reset(f91);if (posn(ego, 0, 0, 27, 80))
  {  set(f91);  }call(Logic114);call(Logic129);call(Logic111);if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic17);  }if (edgeEgoHit == TOP_EDGE)
  {  new.room(Logic27);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic11);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic13);  }return();[ Messages