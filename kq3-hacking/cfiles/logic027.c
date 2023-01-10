if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  v56 = 2;  set(f70);  set.horizon(56);  v32 = 87;  v31 = 130;  random(1, 3, v36);  if (v36 == 1)
    {    v57 = 14;    v58 = 70;    }  else
    {    if (v36 == 2)
      {      v57 = 76;      v58 = 85;      }    else
      {      v57 = 143;      v58 = 109;      }    }  load.logics(Logic129);  load.logics(Logic111);  if (!isset(f78))
    {    random(1, 3, v36);    if (v36 == 1)
      {      set(f220);      load.logics(Logic115);      v31 = 0;      }    }  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
    {    if (previousRoom == 26)
      {      if (v41 > 117 &&           v41 < 122)
        {        v41 = 117;        }      }    position.v(ego, v40, v41);    }  if (isset(f47))
    {    draw(ego);    }  ignore.objs(ego);  call(Logic111);  if (isset(f220))
    {    call(Logic115);    }  show.pic();  return();  }reset(f91);if (posn(ego, 7, 98, 20, 135))
  {  set(f91);  }call(Logic129);call(Logic111);if (isset(f220))
  {  call(Logic115);  }if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic12);  }if (edgeEgoHit == TOP_EDGE)
  {  new.room(Logic22);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic26);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic28);  }return();[ Messages