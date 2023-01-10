if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 1;  set.horizon(33);  v57 = 140;  v58 = 140;  v32 = 130;  v31 = 0;  v100 = 122;  v101 = 129;  load.logics(Logic104);  load.logics(Logic103);  v34 = 200;  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (v44 == 25)
    {    set(f48);    }  if (isset(f48))
    {    if (previousRoom == 5)
      {      set.priority(ego, 9);      position(ego, 107, 35);      start.motion(ego);      if (v44 != 25)
        {        set.loop(ego, 2);        }      }    else
      {      if (previousRoom == 10)
        {        position(ego, 89, 166);        }      else
        {        position.v(ego, v57, v58);        }      }    }  if (isset(f47))
    {    draw(ego);    }  observe.blocks(ego);  call(Logic103);  call(Logic104);  if (isset(f116))
    {    object.on.water(o13);    }  show.pic();  return();  }if ((posn(ego, 92, 31, 122, 97) ||     posn(ego, 114, 73, 126, 99)))
  {  set.priority(ego, 9);  }else
  {  release.priority(ego);  }if (!isset(haveInput))
  {  goto(Label1);  }if ((said("examine", "area") ||     said("examine", "building") ||     said("examine") ||     said("examine", "passage")))
  {  print("You are on a flight of steep underground stone steps. They curve "        "downward toward a dim light. The open trapdoor is above you.");  }if ((said("examine", "stair") ||     said("examine", "up", "stair") ||     said("examine", "down", "stair") ||     said("examine", "down") ||     said("examine", "up")))
  {  print("The steps are made of narrow, rough stones, crudely constructed.");  }if ((said("examine", "hatch") ||     said("examine", "out", "hatch")))
  {  print("The trapdoor from the wizard's study is open.");  }if (said("close", "hatch"))
  {  print("You reach up and grab the trapdoor intending to close it. It won't "        "move from this side. You'll just have to leave it open.");  }if (said("lift", "hatch"))
  {  print("The trapdoor is already open.");  }if ((said("climb", "stair") ||     said("climb", "down", "stair") ||     said("climb", "up", "stair")))
  {  print("Climb them yourself.");  }Label1:if (posn(ego, 90, 100, 150, 150))
  {  v31 = 132;  }if (isset(f116) &&     !isset(f220) &&     v44 == 0)
  {  distance(ego, o13, v36);  if (v36 < 12 &&       v36 != 0)
    {    set(egoHitSpecial);    set(f220);    }  }if (isset(f220) &&     v41 > 163)
  {  reset(f220);  print("OH, OH!! That darn cat really did it to you this time! Tripping over "        "the cat, you fall to your death.");  if (has("Dough in Ears"))
    {    print("\"You look mighty funny falling down those stairs, Gwydion,\" he "          "snickers.");    }  }if (v44 != 125)
  {  if (edgeEgoHit == BOTTOM_EDGE &&       v40 > 74 &&       v40 < 146)
    {    release.priority(ego);    new.room(Logic10);    }  if (edgeEgoHit == TOP_EDGE &&       v40 > 104 &&       v40 < 118)
    {    release.priority(ego);    new.room(Logic5);    }  }call(Logic104);call(Logic103);return();[ Messages#message 1 "You are on a flight of steep underground stone steps. They curve downward toward a dim light. The open trapdoor is above you."#message 2 "The steps are made of narrow, rough stones, crudely constructed."#message 3 "The trapdoor from the wizard's study is open."#message 4 "You reach up and grab the trapdoor intending to close it. It won't move from this side. You'll just have to leave it open."#message 5 "The trapdoor is already open."#message 6 "Climb them yourself."#message 7 "OH, OH!! That darn cat really did it to you this time! Tripping over the cat, you fall to your death."#message 8 "\"You look mighty funny falling down those stairs, Gwydion,\" he snickers."