if (isset(newRoom))
{  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.sound(Sound1);  load.sound(Sound26);  load.sound(Sound3);  load.logics(Logic112);  load.logics(Logic116);  reset(f34);  v56 = 7;  v57 = 37;  v58 = 125;  v32 = 95;  v31 = 127;  animate.obj(o1);  load.view(View166);  load.view(View156);  if (isset(f181))
  {    v223 = 22;    set.view(o1, View166);    position(o1, 49, 114);    set.loop(o1, 1);    v36 = 6;    cycle.time(o1, v36);    set(f222);    draw(o1);  }  else
  {    set.view(o1, View156);    random(1, 3, v36);    if (isset(f46))
    {      v36 = 1;    }    if (v36 == 1)
    {      reset(f222);    }    if (v36 == 2)
    {      set(f222);      position(o1, 49, 112);      follow.ego(o1, 5, f220);    }    if (v36 == 3)
    {      reset(f222);      position(o1, 1, 158);      random(5, 15, v222);    }    if (isset(f222))
    {      draw(o1);      sound(Sound26, f238);    }  }  load.view(View0);  load.view(View11);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  ignore.blocks(ego);  if (isset(f48))
  {    position(ego, 1, 145);  }  if (v44 == 30)
  {    set.view(ego, View0);    set(f48);    position.v(ego, v57, v58);    set(f47);  }  if (isset(f47))
  {    draw(ego);  }  v36 = 0;  if (v62 == 2)
  {    v36 = 1;  }  call(Logic112);  show.pic();  return();}call(Logic116);if (isset(f33) &&  v44 == 0)
{  ignore.blocks(ego);}--v223;if (v223 == 1)
{  sound(Sound3, f238);  set.cel(o1, 0);  end.of.loop(o1, f224);}if (isset(f224))
{  reset(f224);  v223 = 22;  stop.cycling(o1);}if (isset(f33) &&  !isset(f181))
{  if (isset(f222))
  {    if (v44 != 0)
    {      reset(f220);      stop.cycling(o1);      normal.motion(o1);      stop.motion(o1);      print("The pirate is so terrified by your display of magic that he cannot "        "move!");    }    else
    {      ignore.blocks(ego);      start.cycling(o1);      follow.ego(o1, 5, f220);    }  }  else
  {    v222 = 0;  }}if (v41 < 114 &&  v222 > 0)
{  v222 = 1;}if (isset(f45) &&  v222 > 0)
{  --v222;  if (v222 == 0)
  {    set(f222);    draw(o1);    sound(Sound26, f238);  }}if (!isset(f181) &&  isset(f222) &&  v44 == 0 &&  !isset(f223))
{  set(f223);  follow.ego(o1, 5, f220);}if (isset(f220))
{  reset(f220);  normal.motion(o1);  stop.motion(o1);  stop.cycling(o1);  if (!isset(f46))
  {    print("The nasty pirate growls, \"I gotcha, boy!\"");    set(f199);    new.room(Logic85);  }}if (v44 == 0 &&  isset(egoHitSpecial))
{  if (isset(f46))
  {    stop.motion(ego);  }  else
  {    if (isset(f222))
    {      stop.motion(o1);      stop.cycling(o1);      normal.motion(o1);    }    sound(Sound1, f238);    ignore.objs(ego);    set(f46);    reset(f221);    if ((posn(ego, 99, 108, 159, 152) ||      posn(ego, 85, 153, 159, 167)))
    {      v44 = 6;      fix.loop(ego);      set.priority(ego, 14);      v40 += 3;      v41 += 3;      if (v41 > 165)
      {        v41 = 165;      }      reposition.to.v(ego, v40, v41);      v38 = 167;      v36 = 4;      move.obj.v(ego, v40, v38, v36, f221);      v221 = 48;    }    if (posn(ego, 0, 0, 59, 115))
    {      v44 = 6;      set.priority(ego, 4);      fix.loop(ego);      v40 -= 3;      v41 += 3;      reposition.to.v(ego, v40, v41);      v38 = v41;      v38 += 25;      if (v38 > 167)
      {        v38 = 167;      }      v36 = 4;      move.obj.v(ego, v40, v38, v36, f221);      v221 = 48;    }    if (v44 != 6)
    {      v44 = 6;      set.priority(ego, 6);      set.view(ego, View11);      v40 -= 3;      v41 += 3;      reposition.to.v(ego, v40, v41);      v38 = 167;      v36 = 4;      move.obj.v(ego, v40, v38, v36, f221);      v221 = 84;    }  }}if (v44 == 6 &&  isset(f221))
{  reset(f221);  erase(ego);  reset(f46);  if (v221 == 84)
  {    new.room.v(v221);  }  else
  {    v44 = 0;    if (v62 != 4)
    {      new.room(Logic31);    }    else
    {      new.room(Logic48);    }  }}if ((said("examine") ||  said("examine", "ship")))
{  print("The lower deck has no railing.");}if (said("examine", "mast"))
{  print("The forward mast is slightly shorter than the others.");}if (said("examine", "ladder"))
{  print("The wooden ladder leads to the upper deck at the stern of the vessel.");}if ((said("look in", "carry") ||  said("examine", "carry")))
{  print("The hold is open to the elements.");}if ((said("examine", "desert") ||  said("examine", "bay") ||  said("examine", "liquid") ||  said("examine", "sky")))
{  if (v62 == 2)
  {    print("The sky is a deep, clear blue. You see birds high above you. The "      "ocean seems to go on forever.");  }  if (v62 == 3)
  {    print("The sky is a deep, clear blue. Sea gulls wing nearby. To the east "      "you see what might be land.");  }  if (v62 == 4)
  {    print("The sky is a deep, clear blue. Sea gulls wing nearby. The ship is "      "anchored in a small bay. Further north, a mountain range looms.");  }}if (v62 == 4 &&  (said("examine", "beach") ||    said("examine", "beach")))
{  print("The sky is a deep, clear blue. Sea gulls wing nearby. The ship is "    "anchored in a small bay. Further north, a mountain range looms.");}if (said("examine", "bandit"))
{  if (isset(f222))
  {    if (isset(f181))
    {      print("This pirate is fast asleep. If people look more innocent when "        "asleep, it certainly wasn't true with this one!");    }    else
    {      print("You'd better run!! That uncouth character is after you!");    }  }  else
  {    print("You don't see any pirates at the moment.");  }}if ((said("dive", "bay") ||  said("board", "bay") ||  said("capture", "bay") ||  said("jump") ||  said("jump", "ship") ||  said("jump", "bay") ||  said("dive") ||  said("dive", "liquid") ||  said("board", "liquid") ||  said("capture", "liquid") ||  said("jump") ||  said("jump", "ship") ||  said("jump", "liquid") ||  said("dive")))
{  print("Just walk off the side. I hope you know how to swim!");}call(Logic112);if (edgeEgoHit > NOT_HIT &&  (v44 == 25 ||    v44 == 26))
{  if (edgeEgoHit != LEFT_EDGE)
  {    if (v62 != 4)
    {      new.room(Logic31);    }    else
    {      new.room(Logic48);    }  }}if (edgeEgoHit == LEFT_EDGE)
{  new.room(Logic80);}return();[Messages#message 1 "The nasty pirate growls, \"I gotcha, boy!\""#message 2 "The lower deck has no railing."#message 3 "The forward mast is slightly shorter than the others."#message 4 "The wooden ladder leads to the upper deck at the stern of the vessel."#message 5 "The hold is open to the elements."#message 6 "The sky is a deep, clear blue. You see birds high above you. The ocean seems to go on forever."#message 7 "The sky is a deep, clear blue. Sea gulls wing nearby. To the east you see what might be land."#message 8 "This pirate is fast asleep. If people look more innocent when asleep, it certainly wasn't true with this one!"#message 9 "You'd better run!! That uncouth character is after you!"#message 10 "Just walk off the side. I hope you know how to swim!"#message 11 "The sky is a deep, clear blue. Sea gulls wing nearby. The ship is anchored in a small bay. Further north, a mountain range looms."#message 12 "You don't see any pirates at the moment."#message 13 "The pirate is so terrified by your display of magic that he cannot move!"
