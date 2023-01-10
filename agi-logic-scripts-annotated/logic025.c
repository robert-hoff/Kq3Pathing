if (isset(newRoom))
{  v56 = 2;  set(f68);  set.horizon(70);  v57 = 55;  v58 = 105;  v32 = 1;  v31 = 73;  load.logics(Logic112);  load.logics(Logic120);  load.view(View0);  load.view(View30);  load.view(View11);  load.view(View3);  load.view(View7);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.sound(Sound1);  load.sound(Sound11);  v36 = 25;  if (v62 == 1)
  {    v36 = 125;  }  load.pic(v36);  draw.pic(v36);  discard.pic(v36);  v36 = 0;  call(Logic112);  call(Logic120);  load.view(View229);  animate.obj(o1);  ignore.horizon(o1);  ignore.blocks(o1);  ignore.objs(o1);  position(o1, 103, 145);  set.view(o1, View229);  set.loop(o1, 0);  set.cel(o1, 2);  set.priority(o1, 13);  draw(o1);  animate.obj(o2);  ignore.horizon(o2);  ignore.blocks(o2);  ignore.objs(o2);  position(o2, 134, 145);  set.view(o2, View229);  set.loop(o2, 0);  set.cel(o2, 4);  set.priority(o2, 13);  draw(o2);  v36 = 2;  cycle.time(o1, v36);  v36 = 3;  cycle.time(o2, v36);  set(f220);  if (v44 == 14)
  {    set.priority(ego, 13);  }  if (isset(f48))
  {    get.posn(ego, v40, v41);    if (previousRoom == 20)
    {      reset(f220);      v44 = 0;      position(ego, 56, 77);      ignore.blocks(ego);    }    if (previousRoom == 31)
    {      reset(f220);      v40 = 130;      position.v(ego, v40, v41);    }    if (previousRoom == 30)
    {      reset(f220);      if (v44 == 11)
      {        set.view(ego, View3);        position(ego, 140, 164);      }      if (v44 == 224)
      {        set.view(ego, View7);        position(ego, 61, 164);      }      if (v44 == 0)
      {        if (v40 > 54)
        {          v40 = 54;        }        position.v(ego, v40, v41);      }    }    if (previousRoom == 24)
    {      if (v44 == 0)
      {        if (v41 > 114)
        {          v41 = 114;        }        if (v41 < 92)
        {          v41 = 92;        }        position.v(ego, v40, v41);        set(f220);        set.priority(ego, 13);      }    }    if (previousRoom == 75)
    {      if (v44 == 0)
      {        if (v41 > 114)
        {          v41 = 114;        }        if (v41 < 92)
        {          v41 = 92;        }        position.v(ego, v40, v41);        set(f220);        set.priority(ego, 13);      }      if (v44 == 11)
      {        reset(f220);      }    }  }  if (v44 == 30)
  {    set.view(ego, View0);    set(f220);    set.priority(ego, 13);    set(f48);    position.v(ego, v57, v58);    set(f47);  }  if (isset(f47))
  {    draw(ego);  }  show.pic();  return();}if (isset(f33) &&  v44 == 0)
{  set.view(ego, View0);  v44 = 0;  set(f220);  set.priority(ego, 13);}if (v44 == 0 &&  isset(f220))
{  if (posn(ego, 13, 89, 36, 113))
  {    ignore.blocks(ego);  }  else
  {    observe.blocks(ego);  }}if (v62 == 1 &&  v53 <= 0 &&  v52 < 30 &&  v52 > 0)
{  v52 = 30;}if (v62 > 1)
{  print("With a sinking feeling, you notice that the large ship is no longer "    "tied to the pier. It looks like you missed the boat!");  stop.cycling(ego);  set(f44);}if (v44 == 0)
{  if (isset(egoHitSpecial) &&    !isset(f46))
  {    set(f46);    v44 = 6;    sound(Sound1, f238);    ignore.blocks(ego);    set.view(ego, View11);    start.motion(ego);    if (v41 < 100)
    {      set.priority(ego, 4);      v36 = 3;      v38 = 135;      move.obj.v(ego, v40, v38, v36, f221);    }    if (v41 > 115)
    {      set.priority(ego, 15);      v36 = 3;      v38 = 167;      move.obj.v(ego, v40, v38, v36, f221);    }  }}if (v44 == 6 &&  isset(f221))
{  reset(f220);  reset(f46);  reset(f221);  release.priority(ego);  release.priority(ego);  set(f35);  set.view(ego, View3);  v44 = 11;  sound(Sound11, f238);}if (v44 == 0 &&  posn(ego, 8, 119, 11, 156))
{  set(f220);  ignore.blocks(ego);  set.priority(ego, 14);  set.view(ego, View30);  set.loop(ego, 0);  fix.loop(ego);  v36 = 2;  step.size(ego, v36);  v44 = 15;  reset(f35);}if (v44 == 15)
{  if (v41 < 119)
  {    release.loop(ego);    set.priority(ego, 13);    v44 = 0;    set.view(ego, View0);    set.loop(ego, 3);    v36 = 1;    step.size(ego, v36);    observe.blocks(ego);  }  if (v41 > 156)
  {    release.loop(ego);    release.priority(ego);    v44 = 0;    set.view(ego, View0);    v36 = 1;    step.size(ego, v36);    set.loop(ego, 3);    reset(f220);  }}if (!isset(f220) &&  !isset(f46))
{  if (posn(ego, 61, 0, 68, 166))
  {    reset(f35);    set.view(ego, View7);    ignore.blocks(ego);    v44 = 224;    set.priority(ego, 11);    set(onWater);  }  if (v40 > 68)
  {    set(f35);    ignore.blocks(ego);    set(onWater);    set.view(ego, View3);    v44 = 11;    if (v41 < 140)
    {      set.priority(ego, 10);    }    else
    {      release.priority(ego);    }  }  if (v40 < 61)
  {    reset(f35);    set.view(ego, View0);    v44 = 0;    observe.blocks(ego);    release.priority(ego);    reset(onWater);  }}if (v44 == 0 &&  !isset(f220))
{  if (posn(ego, 40, 86, 65, 88))
  {    ignore.blocks(ego);  }  else
  {    observe.blocks(ego);  }}if (isset(haveInput))
{  if ((said("examine", "boat") ||    said("examine", "ship") ||    said("examine", "bandit", "ship")))
  {    if (v62 == 1)
    {      print("A large ship is tied to the dock.");    }    else
    {      print("What ship?");    }  }  if ((said("jump", "on", "boat") ||    said("jump", "on", "ship") ||    said("board", "boat") ||    said("board", "ship") ||    said("jump", "ship")))
  {    if (v62 == 1)
    {      print("There does not seem to be any way to do that.");    }    else
    {      print("What ship?");    }  }  if (said("examine", "town"))
  {    print("A charming village sits atop a bluff overlooking the ocean.");  }}if (said("examine", "dock"))
{  print("A weathered dock leads into the ocean.");}call(Logic112);call(Logic120);if (edgeEgoHit == BOTTOM_EDGE)
{  new.room(Logic30);}if (edgeEgoHit == LEFT_EDGE)
{  new.room(Logic24);}if (edgeEgoHit == RIGHT_EDGE)
{  new.room(Logic75);}if (edgeEgoHit == TOP_EDGE)
{  if (v44 == 11)
  {    v176 = edgeEgoHit;    new.room(Logic31);  }  else
  {    new.room(Logic20);  }}return();[Messages#message 1 "A large ship is tied to the dock."#message 2 "What ship?"#message 3 "There does not seem to be any way to do that."#message 4 "A charming village sits atop a bluff overlooking the ocean."#message 5 "A weathered dock leads into the ocean."#message 6 "With a sinking feeling, you notice that the large ship is no longer tied to the pier. It looks like you missed the boat!"
