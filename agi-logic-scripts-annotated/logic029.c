if (isset(newRoom))
{
  load.view.v(currentEgoView);
  set.view.v(ego, currentEgoView);
  v56 = 2;
  set(f72);
  set.horizon(55);
  v32 = 88;
  v31 = 140;
  random(1, 3, v36);
  if (v36 == 1)
  {
    v57 = 23;
    v58 = 110;
  }
  else
  {
    if (v36 == 2)
    {
      v57 = 57;
      v58 = 66;
    }
    else
    {
      v57 = 106;
      v58 = 145;
    }
  }
  load.view(View11);
  load.view(View232);
  load.logics(Logic111);
  load.logics(Logic114);
  load.logics(Logic112);
  load.logics(Logic103);
  v34 = 222;
  if (obj.in.room("Mistletoe*", currentRoom))
  {
    load.view(View63);
  }
  if (v62 == 1)
  {
    load.view(View170);
  }
  load.pic(currentRoom);
  draw.pic(currentRoom);
  discard.pic(currentRoom);
  if (v62 == 1)
  {
    add.to.pic(View170, 0, 0, 137, 47, 4, 4);
    discard.view(View170);
  }
  if (obj.in.room("Mistletoe*", currentRoom))
  {
    animate.obj(o4);
    set.view(o4, View63);
    position(o4, 23, 92);
    ignore.objs(o4);
    set.priority(o4, 11);
    draw(o4);
    stop.update(o4);
  }
  if (isset(f48))
  {
    if (previousRoom == 15)
    {
      v40 = 118;
      v41 = 167;
    }
    if (previousRoom == 14)
    {
      if (v40 > 118)
      {
        v40 = 118;
      }
    }
    if (previousRoom == 24)
    {
      if (v40 > 100)
      {
        v40 = 100;
      }
    }
    position.v(ego, v40, v41);
  }
  if (isset(f47))
  {
    draw(ego);
  }
  animate.obj(o2);
  set.view(o2, View232);
  v36 = 4;
  cycle.time(o2, v36);
  ignore.horizon(o2);
  position(o2, 108, 27);
  set.loop(o2, 3);
  set.cel(o2, 3);
  draw(o2);
  animate.obj(o3);
  set.view(o3, View232);
  cycle.time(o3, v36);
  ignore.horizon(o3);
  position(o3, 122, 27);
  set.loop(o3, 3);
  draw(o3);
  v36 = 1;
  call(Logic112);
  reposition.to(o12, 99, 19);
  reposition.to(o13, 111, 11);
  call(Logic103);
  call(Logic114);
  show.pic();
  return ();
}
reset(f222);
if (posn(ego, 10, 109, 27, 122))
{
  set(f222);
}
call(Logic114);
if (!isset(haveInput))
{
  goto(Label1);
}
if ((said("examine", "town") ||
  said("examine", "building")))
{
  print("You see a small seaside village up the coast to the north. Smoke rises "

    "lazily from chimneys and mingles with the ocean air.");
}
if (said("examine", "forest"))
{
  if (!obj.in.room("Mistletoe*", currentRoom))
  {
    print("The trees are not as large, being so near the coast.");
  }
  else
  {
    print("One of the trees has a light-green colored plant growing upon it. On "

      "closer inspection, you see that it's mistletoe.");
  }
}
if ((said("examine", "mistletoe") ||
  said("examine", "mistletoe", "forest")))
{
  if (!isset(f222))
  {
    print("One of the trees has a light-green colored plant growing upon it. On "

      "closer inspection, you see that it's mistletoe.");
  }
  else
  {
    if (obj.in.room("Mistletoe*", currentRoom))
    {
      print("The mistletoe hangs from the branches of the tree. There are a few "

        "dried sprigs mingled with the green mistletoe.");
    }
    else
    {
      print("You look through the remaining mistletoe, but find none that is "

        "dry.");
    }
  }
}
if ((said("rise", "below", "mistletoe") ||
  said("embrace", "below", "mistletoe") ||
  said("embrace", "mistletoe")))
{
  if (!isset(f222))
  {
    print("You are not close enough.");
  }
  else
  {
    print("You give yourself a big smack. (Is this fun?)");
  }
}
if ((said("capture", "mistletoe") ||
  said("capture", "mistletoe", "forest") ||
  said("climb", "forest", "capture", "mistletoe")))
{
  if (!isset(f222))
  {
    print("You are not close enough.");
  }
  else
  {
    if (!obj.in.room("Mistletoe*", currentRoom))
    {
      print("You look through the remaining mistletoe, but find none that is "

        "dry.");
    }
    else
    {
      start.update(o4);
      erase(o4);
      get("Mistletoe*");
      currentScore += 1;
      print("You search among the hanging mistletoe until you find a sprig that "

        "has dried. You break it off, and carry it with you.");
    }
  }
}
if ((said("examine", "ship") ||
  said("examine", "boat") ||
  said("examine", "ship", "dock")))
{
  if (v62 == 1)
  {
    print("There is a three-masted ship docked at the pier. By her sturdy lines "

      "and broad beam, you guess it to be a merchant vessel, trading goods "

      "in the town.");
  }
  else
  {
    print("Where?");
  }
}
if (said("examine", "dock"))
{
  if (v62 == 1)
  {
    print("%m9 You see a vessel tied up there now!");
  }
  else
  {
    print("A pier extends from the village and out into the bay. It is built of "

      "heavy timbers to withstand winter storms.");
  }
}
if ((said("examine", "bay") ||
  said("examine", "beach")))
{
  print("You look out over the vast, blue-gray ocean. You wonder what lands and "

    "people reside across it. If only you could know!");
}
if ((said("examine") ||
  said("examine", "bluff")))
{
  print("You are standing atop a bluff overlooking the ocean, and see a village "

    "to the north. %m14 The trees here are stunted and twisted by strong "

    "ocean winds.");
}
if ((said("examine", "sky")))
{
  print("You see seagulls flying overhead.");
}
if ((said("examine", "deck") ||
  said("examine", "deck") ||
  said("examine", "down")))
{
  print("The soft grass of the forest has been replaced by the coarse grass of "

    "the seashore.");
}
if ((said("jump", "down") ||
  said("climb", "down") ||
  said("climb", "down", "bluff")))
{
  print("You are not close enough.");
}
if ((said("climb", "forest") ||
  said("climb", "up", "forest")))
{
  print("There is no need to climb this tree.");
}
Label1:
if (isset(egoHitSpecial) &&
  v44 != 6)
{
  get.priority(ego, v39);
  if ((v39 == 13 ||
    v39 == 11 ||
    v39 == 9))
  {
    --v39;
  }
  else
  {
    if (v39 < 9)
    {
      v39 = 5;
    }
  }
  set.priority.v(ego, v39);
  v40 += 6;
  if (v40 > 145)
  {
    v40 = 145;
  }
  reposition.to.v(ego, v40, v41);
  v33 = 6;
}
if (isset(f45) &&
  v62 == 1 &&
  v53 <= 0 &&
  v52 > 0 &&
  v52 < 30)
{
  v52 = 30;
}
call(Logic112);
if (edgeEgoHit == TOP_EDGE)
{
  new.room(Logic24);
}
if (edgeEgoHit == LEFT_EDGE)
{
  new.room(Logic28);
}
if (edgeEgoHit == RIGHT_EDGE)
{
  new.room(Logic25);
}
if (edgeEgoHit == BOTTOM_EDGE)
{
  if (v44 == 6)
  {
    if (isset(f31))
    {
      set(f40);
    }
    else
    {
      new.room(Logic30);
    }
  }
  else
  {
    if (v40 > 110)
    {
      new.room(Logic15);
    }
    else
    {
      new.room(Logic14);
    }
  }
}
call(Logic103);
call(Logic111);
return ();

[Messages
#message 1 "You see a small seaside village up the coast to the north. Smoke rises lazily from chimneys and mingles with the ocean air."
#message 2 "One of the trees has a light-green colored plant growing upon it. On closer inspection, you see that it's mistletoe."
#message 3 "The mistletoe hangs from the branches of the tree. There are a few dried sprigs mingled with the green mistletoe."
#message 4 "You search among the hanging mistletoe until you find a sprig that has dried. You break it off, and carry it with you."
#message 5 "You are not close enough."
#message 6 "There is a three-masted ship docked at the pier. By her sturdy lines and broad beam, you guess it to be a merchant vessel, trading goods in the town."
#message 7 "Where?"
#message 8 "%m9 You see a vessel tied up there now!"
#message 9 "A pier extends from the village and out into the bay. It is built of heavy timbers to withstand winter storms."
#message 10 "You give yourself a big smack. (Is this fun?)"
#message 11 "The trees are not as large, being so near the coast."
#message 12 "You look out over the vast, blue-gray ocean. You wonder what lands and people reside across it. If only you could know!"
#message 13 "You are standing atop a bluff overlooking the ocean, and see a village to the north. %m14 The trees here are stunted and twisted by strong ocean winds."
#message 14 "The soft grass of the forest has been replaced by the coarse grass of the seashore."
#message 15 "There is no need to climb this tree."
#message 16 "You see seagulls flying overhead."
#message 17 "You look through the remaining mistletoe, but find none that is dry."



