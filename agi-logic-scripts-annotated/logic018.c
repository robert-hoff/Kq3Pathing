if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 2;  set(f61);  v32 = 131;  v31 = 104;  set.horizon(40);  random(1, 3, v36);  if (v36 == 1)
    {    v57 = 145;    v58 = 145;    }  else
    {    if (v36 == 2)
      {      v57 = 70;      v58 = 140;      }    else
      {      v57 = 5;      v58 = 130;      }    }  load.logics(Logic111);  load.logics(Logic114);  load.logics(Logic103);  reset(f32);  v34 = 164;  load.view(View11);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
    {    if (previousRoom == 33)
      {      start.motion(ego);      v40 = 14;      v41 = 44;      }    if (previousRoom == 17)
      {      if (v41 < 114)
        {        v41 = 114;        }      }    if (previousRoom == 19)
      {      if (v41 < 139)
        {        v41 = 139;        }      }    position.v(ego, v40, v41);    }  if (isset(f47))
    {    draw(ego);    }  call(Logic114);  call(Logic103);  show.pic();  return();  }call(Logic114);
if (isset(haveInput))
  {  if ((said("examine", "bluff") ||      said("examine", "top", "bluff") ||      said("examine")))
    {    print("A lone mountain rises sharply from the forest floor, its jagged peak "          "encircled by dark clouds. A treacherous path winds its way up the "          "steep mountainside. You, and the wizard Manannan, live at the top of "          "this peak.");    }  if ((said("examine", "path") ||      said("examine", "path", "bluff") ||      said("examine", "bluff", "path")))
    {    print("The winding path leads dangerously up the steep side of the dark "          "mountain.");    }  if ((said("climb") ||      said("climb", "bluff")))
    {    print("It would be nearly impossible to scale a mountain this steep. Try "          "using the path.");    }  }
if (isset(egoHitSpecial) &&  !isset(f221))
  {  get.priority(ego, v36);  set.priority.v(ego, v36);  v39 = 0;  if (posn(ego, 27, 48, 75, 57))
    {    v39 = 1;    }  if (posn(ego, 75, 58, 87, 69))
    {    v39 = 2;    v40 -= 8;    reposition.to.v(ego, v40, v41);    v33 = 6;    }  if (posn(ego, 89, 71, 97, 81))
    {    v39 = 3;    v40 -= 8;    reposition.to.v(ego, v40, v41);    v33 = 6;    }  if (posn(ego, 98, 83, 112, 94))
    {    v39 = 4;    }  if (posn(ego, 112, 95, 123, 109))
    {    v39 = 5;    v40 -= 8;    reposition.to.v(ego, v40, v41);    v33 = 6;    }  if (posn(ego, 67, 96, 104, 108))
    {    v39 = 6;    get.priority(ego, v36);    --v36;    set.priority.v(ego, v36);    }  if (posn(ego, 40, 102, 53, 122))
    {    v39 = 7;    v40 -= 8;    reposition.to.v(ego, v40, v41);    v33 = 6;    }  if (posn(ego, 16, 113, 25, 119))
    {    v39 = 8;    v40  += 8;    reposition.to.v(ego, v40, v41);    v33 = 6;    }  if (posn(ego, 133, 95, 139, 111))
    {    v39 = 9;    set.priority(ego, 10);    v40  += 8;    reposition.to.v(ego, v40, v41);    v33 = 6;    }  if (posn(ego, 57, 112, 67, 125))
    {    v39 = 10;    set.priority(ego, 10);    v40  += 8;    reposition.to.v(ego, v40, v41);    v33 = 6;    }  if (posn(ego, 68, 111, 146, 118))
    {    v39 = 11;    }  if (posn(ego, 106, 127, 126, 130))
    {    v39 = 12;    get.priority(ego, v36);    --v36;    set.priority.v(ego, v36);    }  }call(Logic103);call(Logic111);if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic23);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic17);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic19);  }if (posn(ego, 0, 41, 10, 47))
  {  new.room(Logic33);  }return();[ Messages#message 1 ""#message 2 ""#message 3 "A lone mountain rises sharply from the forest floor, its jagged peak encircled by dark clouds. A treacherous path winds its way up the steep mountainside. You, and the wizard Manannan, live at the top of this peak."#message 4 "The winding path leads dangerously up the steep side of the dark mountain."#message 5 "It would be nearly impossible to scale a mountain this steep. Try using the path."