if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  v56 = 2;  set(f62);  set.horizon(52);  v32 = 65;  v31 = 101;  random(1, 3, v36);  if (v36 == 1)
    {    v57 = 80;    v58 = 75;    }  else
    {    if (v36 == 2)
      {      v57 = 140;      v58 = 75;      }    else
      {      v57 = 35;      v58 = 155;      }    }  load.logics(Logic111);  load.logics(Logic110);  load.logics(Logic114);  load.view(View223);  load.view(View0);  load.view(View7);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  animate.obj(o1);  ignore.objs(o1);  position(o1, 53, 82);  set.view(o1, View223);  set.priority(o1, 4);  draw(o1);  if (isset(f48))
    {    if (previousRoom == 18)
      {      if (v41 > 150 &&           v41 < 162)
        {        v41 = 162;        }      if (v41 < 139)
        {        v41 = 139;        }      }    position.v(ego, v40, v41);    }  if (isset(f47))
    {    draw(ego);    }  call(Logic110);  call(Logic111);  call(Logic114);  show.pic();  return();  }v39 = 0;reset(f75);if ((posn(ego, 41, 40, 88, 78) ||     posn(ego, 41, 78, 102, 107) ||     posn(ego, 102, 88, 159, 142)))
  {  set(f90);  set(f75);  }if ((posn(ego, 57, 61, 62, 80) ||     posn(ego, 63, 50, 70, 63) ||     posn(ego, 101, 104, 107, 105) ||     posn(ego, 119, 113, 159, 126)))
  {  set(onWater);  }call(Logic114);if (isset(haveInput))
  {  if (said("examine", "brush"))
    {    print("The soft grass soothes your aching feet.");    }  if ((said("examine") ||       said("examine", "forest")))
    {    print("A beautiful stream ripples through these stately trees.");    }  if ((said("examine", "cave") ||       said("examine", "hole")))
    {    print("There seems to be a cave in a hill to the north, but you are too far "          "away to see it clearly.");    }  }call(Logic110);call(Logic111);if (edgeEgoHit == TOP_EDGE)
  {  new.room(Logic14);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic18);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic20);  }if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic24);  }return();[ Messages#message 1 "The soft grass soothes your aching feet."#message 2 "A beautiful stream ripples through these stately trees."#message 3 "There seems to be a cave in a hill to the north, but you are too far away to see it clearly."