if (isset(newRoom))
  {  load.view(View0);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  v56 = 2;  set(f60);  set.horizon(60);  v32 = 12;  v31 = 142;  random(1, 3, v36);  if (v36 == 1)
    {    v57 = 80;    v58 = 150;    }  else
    {    if (v36 == 2)
      {      v57 = 20;      v58 = 110;      }    else
      {      v57 = 110;      v58 = 85;      }    }  load.logics(Logic129);  load.logics(Logic111);  if (!isset(f78))
    {    random(1, 3, v36);    if (v36 == 1)
      {      set(f220);      load.logics(Logic115);      v31 = 0;      }    }  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  ignore.objs(ego);  if (isset(f48))
    {    if (previousRoom == 12)
      {      if (v40 > 87)
        {        v40 = 87;        }      }    if (previousRoom == 16)
      {      if (v41 > 117 &&           v41 < 121)
        {        v41 = 121;        }      }    if (previousRoom == 18)
      {      if (v41 < 115)
        {        v41 = 115;        }      }    position.v(ego, v40, v41);    }  if (isset(f47))
    {    draw(ego);    }  call(Logic111);  if (isset(f220))
    {    call(Logic115);    }  show.pic();  return();  }reset(f91);if (posn(ego, 0, 94, 20, 143))
  {  set(f91);  }call(Logic129);call(Logic111);if (isset(f220))
  {  call(Logic115);  }if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic22);  }if (edgeEgoHit == TOP_EDGE)
  {  new.room(Logic12);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic16);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic18);  }return();[ Messages