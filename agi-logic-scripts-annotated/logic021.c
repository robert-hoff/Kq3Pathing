if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 2;  set(f64);  set.horizon(56);  v32 = 34;  if (isset(f111))
    {    v31 = 123;    }  random(1, 3, v36);  if (v36 == 1)
    {    v57 = 95;    v58 = 76;    }  else
    {    if (v36 == 2)
      {      v57 = 132;      v58 = 110;      }    else
      {      v57 = 24;      v58 = 122;      }    }  if (obj.in.room("Cactus*", currentRoom))
    {    load.view(View243);    }  load.logics(Logic128);  load.logics(Logic118);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
    {    if (previousRoom == 31)
      {      if (v41 > 80 &&           v41 < 85)
        {        v41 = 85;        }      }    if (previousRoom == 22)
      {      if (v41 > 91 &&           v41 < 99)
        {        v41 = 99;        }      }    position.v(ego, v40, v41);    }  if (isset(f47))
    {    draw(ego);    }  if (obj.in.room("Cactus*", currentRoom))
    {    animate.obj(o2);    position(o2, 40, 86);    set.view(o2, View243);    set.cel(o2, 0);    draw(o2);    stop.update(o2);    }  call(Logic128);  call(Logic118);  show.pic();  return();  }if (isset(haveInput))
  {  if (said("examine", "rock"))
    {    print("If you've seen one rock, you've seen them all.");    if (obj.in.room("Cactus*", currentRoom))
      {      print("You notice an unusual little cactus beside that large rock.");      }    }  if (obj.in.room("Cactus*", currentRoom))
    {    if ((said("examine") ||         said("examine", "brush") ||         said("examine", "cactii") ||         said("examine", "deck")))
      {      print("You notice an unusual little cactus beside that large rock.");      }    if ((said("try", "dagger", "carve", "cactii") ||         said("carve", "cactii", "try", "dagger")))
      {      print("You don't have the cactus.");      }    if ((said("capture", "cactii") ||         said("capture", "cactii", "from", "deck") ||         said("capture", "cactii") ||         said("capture", "cactii", "from", "deck")))
      {      distance(ego, o2, v36);      if (v36 > 20)
        {        print("You are not close enough.");        }      else
        {        print("Ok.");        get("Cactus*");        currentScore  += 1;        start.update(o2);        erase(o2);        }      }    }  }call(Logic128);call(Logic118);if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic26);  }if (edgeEgoHit == TOP_EDGE)
  {  new.room(Logic16);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic32);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic22);  }return();[ Messages#message 1 "Ok."#message 2 "You notice an unusual little cactus beside that large rock."#message 3 "You are not close enough."#message 4 "If you've seen one rock, you've seen them all."#message 5 "You don't have the cactus."