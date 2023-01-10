if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 2;  set(f63);  v32 = 20;  v31 = 140;  random(1, 3, v36);  if (v36 == 1)
    {    v57 = 100;    v58 = 83;    }  else
    {    if (v36 == 2)
      {      v57 = 102;      v58 = 149;      }    else
      {      v57 = 18;      v58 = 89;      }    }  load.view(View227);  load.logics(Logic112);  load.logics(Logic110);  load.logics(Logic120);  load.logics(Logic113);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  animate.obj(o1);  position(o1, 51, 122);  set.view(o1, View227);  set.priority(o1, 3);  ignore.objs(o1);  draw(o1);  if (isset(f48))
    {    if (previousRoom == 25)
      {      v40 = 121;      if (v44 == 11)
        {        v40 = 153;        v41 = 87;        }      if (v44 == 224)
        {        v40 = 150;        v41 = 120;        }      }    if (previousRoom == 15)
      {      if (v40 > 69)
        {        v40 = 90;        }      else
        {        v40 = 52;        }      if ((v44 == 11 ||           v138 == 3))
        {        v40 = 147;        }      if (v138 == 2)
        {        v40 = 134;        }      if ((v44 == 224 ||           v138 == 7))
        {        v40 = 126;        }      }    position.v(ego, v40, v41);    }  if (v40 < 70)
    {    set.horizon(62);    }  else
    {    set.horizon(74);    }  if (isset(f47))
    {    draw(ego);    }  v36 = 1;  call(Logic112);  reposition.to(o12, 99, 19);  reposition.to(o13, 111, 11);  call(Logic110);  call(Logic120);  call(Logic113);  show.pic();  return();  }if (v40 < 70)
  {  set.horizon(62);  }else
  {  set.horizon(74);  }reset(f75);if ((posn(ego, 84, 138, 94, 141) ||     posn(ego, 53, 107, 62, 108) ||     posn(ego, 82, 124, 85, 130) ||     posn(ego, 83, 124, 85, 128) ||     posn(ego, 47, 109, 68, 118) ||     posn(ego, 93, 102, 111, 110)))
  {  set(onWater);  set(f75);  }if (posn(ego, 0, 105, 45, 140))
  {  set(f75);  }reset(f220);if (posn(ego, 71, 101, 159, 147))
  {  set(f220);  }reset(f90);if ((posn(ego, 0, 105, 36, 116) ||     posn(ego, 0, 124, 27, 134)))
  {  set(f90);  }v138 = 0;if (isset(onWater))
  {  v138 = 7;  }if (posn(ego, 134, 63, 140, 86))
  {  v138 = 2;  }if (posn(ego, 141, 63, 159, 88))
  {  v138 = 3;  }if ((said("examine") ||     said("examine", "deck")))
  {  print("The sandy beach is bordered by grass. A stream cuts through the grass "        "and sand to complete its journey to the sea.");  }if (isset(f220))
  {  if ((said("examine", "liquid") ||       said("examine", "creek")))
    {    print("The water in this inter-tidal zone is very brackish. It's not "          "suitable for much of anything.");    }  if ((said("drink", "liquid") ||       said("drink", "bay", "liquid") ||       said("drink", "liquid", "bay") ||       said("drink", "liquid", "cup") ||       said("drink", "bay", "liquid", "cup") ||       said("drink", "grains of salt", "liquid", "cup") ||       said("drink", "grains of salt", "liquid") ||       said("capture", "liquid", "creek") ||       said("capture", "liquid") ||       said("capture", "liquid", "cup") ||       said("capture", "drink", "liquid", "creek") ||       said("creek", "capture", "drink", "liquid") ||       said("capture", "drink", "liquid") ||       said("capture", "drink") ||       said("drink")))
    {    print("The water in this inter-tidal zone is very brackish. It's not "          "suitable for much of anything.");    }  }if ((said("examine", "liquid") ||     said("examine", "creek")))
  {  print("There is water everywhere around here.");  }if (isset(egoHitSpecial))
  {  if (posn(ego, 50, 58, 79, 98))
    {    v37 = 8;    v38 = 9;    reposition(ego, v37, v38);    }  if (posn(ego, 32, 99, 67, 109))
    {    v41 = 110;    reposition.to.v(ego, v40, v41);    }  }call(Logic112);if (v40 < 68)
  {  call(Logic110);  }call(Logic120);call(Logic113);if (edgeEgoHit == TOP_EDGE)
  {  new.room(Logic15);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic19);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic31);  }if (edgeEgoHit == BOTTOM_EDGE)
  {  if (v40 < 87)
    {    new.room(Logic24);    }  else
    {    new.room(Logic25);    }  }return();[ Messages#message 1 "The sandy beach is bordered by grass. A stream cuts through the grass and sand to complete its journey to the sea."#message 2 "There is water everywhere around here."#message 3 "The water in this inter-tidal zone is very brackish. It's not suitable for much of anything."