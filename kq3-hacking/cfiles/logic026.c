if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 2;  set(f69);  set.horizon(56);  v32 = 137;  if (isset(f111))
    {    v31 = 100;    }  random(1, 3, v36);  if (v36 == 1)
    {    v57 = 140;    v58 = 125;    }  else
    {    if (v36 == 2)
      {      v57 = 80;      v58 = 80;      }    else
      {      v57 = 33;      v58 = 122;      }    }  load.logics(Logic128);  load.logics(Logic118);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
    {    // [ WARNING: this block contains no commands    }  if (isset(f47))
    {    draw(ego);    }  call(Logic128);  call(Logic118);  show.pic();  return();  }call(Logic128);call(Logic118);if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic11);  }if (edgeEgoHit == TOP_EDGE)
  {  new.room(Logic21);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic32);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic27);  }return();[ Messages