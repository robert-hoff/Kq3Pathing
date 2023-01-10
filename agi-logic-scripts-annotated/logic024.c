if (isset(newRoom))
  {  if ((v76 > 0 ||       v75 > 0) &&       (previousRoom == 39 ||       previousRoom == 40))
    {    v72 = previousRoom;    new.room(Logic87);    }  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  v56 = 2;  set(f67);  set.horizon(56);  v32 = 137;  v31 = 100;  random(2, 3, v36);  if (v36 == 2)
    {    v57 = 117;    v58 = 100;    }  else
    {    v57 = 28;    v58 = 151;    }  load.view(View0);  load.view(View232);  load.view(View94);  load.logics(Logic111);  load.logics(Logic103);  load.view(View220);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  add.to.pic(View220, 0, 0, 112, 37, 14, 4);  add.to.pic(View220, 1, 0, 82, 71, 14, 5);  discard.view(View220);  animate.obj(o2);  set.view(o2, View94);  set.loop(o2, 0);  set.cel(o2, 0);  set.priority(o2, 8);  position(o2, 117, 81);  draw(o2);  stop.update(o2);  animate.obj(o3);  set.view(o3, View94);  set.loop(o3, 1);  set.cel(o3, 0);  set.priority(o3, 11);  stop.cycling(o3);  ignore.objs(o3);  position(o3, 75, 129);  draw(o3);  animate.obj(o1);  ignore.horizon(o1);  set.priority(o1, 14);  set.view(o1, View232);  set.loop(o1, 1);  v36 = 5;  cycle.time(o1, v36);  position(o1, 32, 15);  draw(o1);  if ((previousRoom == 39 ||       previousRoom == 40))
    {    set(f48);    }  if (isset(f48))
    {    if (previousRoom == 39)
      {      v40 = 80;      v41 = 129;      start.cycling(o3);      last.cel(o3, v36);      set.cel.v(o3, v36);      reverse.loop(o3, f229);      }    if (previousRoom == 40)
      {      v40 = 119;      v41 = 84;      start.update(o2);      last.cel(o2, v36);      set.cel.v(o2, v36);      start.update(o2);      reverse.loop(o2, f235);      }    if (previousRoom == 23)
      {      if (v41 > 57 &&           v41 < 61)
        {        v41 = 61;        }      }    if (previousRoom == 25)
      {      if (v41 < 91)
        {        v41 = 91;        }      }    if (previousRoom == 20)
      {      v40 = 90;      v41 = 66;      }    position.v(ego, v40, v41);    }  if (isset(f47))
    {    draw(ego);    }  call(Logic103);  call(Logic111);  show.pic();  return();  }reset(f236);if ((posn(ego, 98, 84, 108, 91) ||     posn(ego, 127, 84, 141, 91) ||     posn(ego, 84, 110, 99, 123) ||     posn(ego, 38, 139, 53, 152) ||     posn(ego, 11, 132, 37, 144)))
  {  set(f236);  }if ((posn(ego, 109, 84, 131, 96) ||     posn(ego, 80, 106, 96, 110)) &&     currentEgoView != 26 &&     currentEgoView != 25)
  {  set.priority(ego, 9);  }else
  {  release.priority(ego);  }if (posn(ego, 111, 114, 141, 118) &&     v44 != 26 &&     v44 != 25 &&     (egoDir == RIGHT ||     egoDir == DOWN_RIGHT ||     egoDir == DOWN_LEFT ||     egoDir == LEFT))
  {  v38 = 119;  reposition.to.v(ego, v40, v38);  }v39 = 0;if (posn(ego, 64, 123, 82, 131))
  {  v39 = 2;  }if (posn(ego, 68, 124, 70, 130))
  {  v39 = 1;  }if (posn(ego, 108, 83, 126, 86))
  {  v39 = 3;  }if (posn(ego, 145, 131, 158, 167))
  {  v39 = 4;  }if (v44 == 25)
  {  if (posn(ego, 115, 76, 126, 82) &&       isset(f232))
    {    set(f233);    }  if (posn(ego, 68, 116, 73, 131) &&       isset(f226))
    {    set(f227);    }  }if (!isset(f222) &&     egoDir == RIGHT &&     v40 == 30 &&     v41 == 151)
  {  set(f222);  print("Ouch!");  }observe.blocks(ego);if (isset(f226) &&     posn(ego, 60, 124, 86, 131))
  {  ignore.blocks(ego);  }if (isset(haveInput))
  {  if (said("examine", "deck"))
    {    print("The soft grass of the forest has been replaced by the coarse grass "          "of the seashore.");    }  if ((said("examine") ||       said("examine", "town") ||       said("examine", "building")))
    {    print("You have entered a quaint, seaside town. Smoke curls lazily from the "          "houses and shops overlooking the ocean. A pier stretches out into "          "the bay. Near the pier, you notice a store and a tavern.");    }  if (said("examine", "shop"))
    {    print("The store is on the south side of the pier.");    }  if (said("examine", "forest"))
    {    print("The trees are not as large, being so near the coast.");    }  if (said("examine", "bar"))
    {    print("The tavern is on the north side of the pier.");    }  if (said("examine", "door"))
    {    print("It's just a door; it opens and closes.");    }  if (said("examine", "dock"))
    {    if (v62 == 1)
      {      print("%m5 There is a ship tied to the dock.");      }    else
      {      print("The pier is made of rough, but sturdy, timbers, and stretches out "            "into the bay.");      }    }  if (said("examine", "below", "dock"))
    {    print("Waves lap gently against the pilings. But, there is nothing else "          "interesting down there.");    }  if ((said("examine", "anchor") ||       said("capture", "anchor")))
    {    print("The old, rusted anchor is much too heavy to move.");    }  if ((said("examine", "glass") ||       said("look in", "glass") ||       said("examine", "glass", "anyword")))
    {    if (isset(f236))
      {      print("You peer into the window, but cannot make out any details of the "            "dim interior.");      }    else
      {      print("Wouldn't it help to be near a window?");      }    }  if ((said("lift", "glass") ||       said("break", "glass")))
    {    print("If you want to enter, why not try the door?");    }  if ((said("bang", "anyword", "door") ||       said("bang", "door", "anyword") ||       said("bang", "door") ||       said("bang")))
    {    if ((v39 == 3 ||         v39 == 2))
      {      print("You don't have to knock, just open the door and go in.");      }    else
      {      print("You are not close enough.");      }    }  if ((said("lift", "bar", "door") ||       said("lift", "door") ||       said("lift", "door", "bar")))
    {    if (v39 == 3)
      {      if (isset(f232))
        {        print("The door is already open.");        }      else
        {        set(f230);        }      }    else
      {      reset(haveMatch);      if (v39 != 2 &&           said("lift", "door"))
        {        print("You are not close enough.");        }      }    }  if ((said("lift", "shop", "door") ||       said("lift", "door") ||       said("lift", "door", "shop")))
    {    if (v39 != 2)
      {      print("You are not close enough.");      }    else
      {      if (isset(f226))
        {        print("The door is already open.");        }      else
        {        set(f224);        }      }    }  if ((said("close", "bar", "door") ||       said("close", "door") ||       said("close", "door", "bar")))
    {    if (v39 == 3)
      {      if (!isset(f232))
        {        print("The door is already closed.");        }      else
        {        set(f234);        }      }    else
      {      reset(haveMatch);      if (v39 != 2 &&           said("close", "door"))
        {        print("You are not close enough.");        }      }    }  if ((said("close", "shop", "door") ||       said("close", "door") ||       said("close", "door", "shop")))
    {    if (v39 != 2)
      {      print("You are not close enough.");      }    else
      {      if (!isset(f226))
        {        print("The door is already open.");        }      else
        {        set(f228);        }      }    }  }if (isset(f230))
  {  reset(f230);  set.priority(ego, 9);  start.update(o2);  end.of.loop(o2, f231);  }if (isset(f231))
  {  reset(f231);  set(f232);  stop.update(o2);  release.priority(ego);  }if (isset(f234))
  {  reset(f234);  set.priority(ego, 9);  start.update(o2);  reverse.loop(o2, f235);  }if (isset(f235))
  {  reset(f235);  reset(f232);  stop.update(o2);  release.priority(ego);  }if (isset(f224))
  {  reset(f224);  start.cycling(o3);  end.of.loop(o3, f225);  }if (isset(f225))
  {  reset(f225);  set(f226);  stop.cycling(o3);  }if (isset(f228))
  {  reset(f228);  start.cycling(o3);  reverse.loop(o3, f229);  }if (isset(f229))
  {  reset(f229);  reset(f226);  stop.cycling(o3);  }if (v39 == 3 &&     isset(f232) &&     v44 != 26 &&     (egoDir == UP ||     egoDir == UP_RIGHT ||     egoDir == UP_LEFT))
  {  set(f233);  }if (v39 == 1 &&     v44 != 26 &&     isset(f226))
  {  set(f227);  }if (isset(egoHitSpecial) &&     v39 == 4)
  {  v40 = 145;  reposition.to.v(ego, v40, v41);  v33 = 6;  }if (isset(f221))
  {  new.room(Logic30);  }if (isset(f227))
  {  new.room(Logic39);  }if (isset(f233))
  {  new.room(Logic40);  }if (edgeEgoHit == TOP_EDGE)
  {  new.room(Logic19);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic23);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic25);  }if (edgeEgoHit == BOTTOM_EDGE)
  {  if (v44 == 6)
    {    new.room(Logic30);    }  else
    {    new.room(Logic29);    }  }call(Logic103);call(Logic111);return();[ Messages#message 1 "You have entered a quaint, seaside town. Smoke curls lazily from the houses and shops overlooking the ocean. A pier stretches out into the bay. Near the pier, you notice a store and a tavern."#message 2 "The store is on the south side of the pier."#message 3 "The tavern is on the north side of the pier."#message 4 "%m5 There is a ship tied to the dock."#message 5 "The pier is made of rough, but sturdy, timbers, and stretches out into the bay."#message 6 "Waves lap gently against the pilings. But, there is nothing else interesting down there."#message 7 "The old, rusted anchor is much too heavy to move."#message 8 "You peer into the window, but cannot make out any details of the dim interior."#message 9 "If you want to enter, why not try the door?"#message 10 "Ouch!"#message 11 "The door is already open."#message 12 "You are not close enough."#message 13 "You don't have to knock, just open the door and go in."#message 14 "It's just a door; it opens and closes."#message 15 "Wouldn't it help to be near a window?"#message 16 "The soft grass of the forest has been replaced by the coarse grass of the seashore."#message 17 "The door is already closed."#message 18 "The trees are not as large, being so near the coast."