if (isset(newRoom))
  {  v36 = 76;  if (v62 == 1)
    {    v36 = 176;    }  load.pic(v36);  draw.pic(v36);  discard.pic(v36);  v57 = 66;  v58 = 100;  v32 = 131;  v31 = 109;  v56 = 2;  set.horizon(72);  load.sound(Sound1);  load.sound(Sound11);  load.view(View0);  load.view(View3);  load.view(View11);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.logics(Logic112);  load.logics(Logic120);  load.view(View229);  animate.obj(o4);  ignore.horizon(o4);  ignore.blocks(o4);  ignore.objs(o4);  position(o4, 12, 146);  set.view(o4, View229);  set.loop(o4, 0);  set.cel(o4, 2);  set.priority(o4, 13);  draw(o4);  animate.obj(o5);  ignore.horizon(o5);  ignore.blocks(o5);  ignore.objs(o5);  position(o5, 39, 146);  set.view(o5, View229);  set.loop(o5, 0);  set.cel(o5, 4);  set.priority(o5, 13);  draw(o5);  animate.obj(o6);  ignore.horizon(o6);  ignore.blocks(o6);  ignore.objs(o6);  position(o6, 62, 145);  set.view(o6, View229);  set.loop(o6, 0);  set.cel(o6, 1);  set.priority(o6, 13);  draw(o6);  animate.obj(o7);  ignore.horizon(o7);  ignore.blocks(o7);  ignore.objs(o7);  position(o7, 83, 146);  set.view(o7, View229);  set.loop(o7, 0);  set.cel(o7, 3);  set.priority(o7, 13);  draw(o7);  v36 = 2;  cycle.time(o4, v36);  v36 = 3;  cycle.time(o5, v36);  v36 = 2;  cycle.time(o6, v36);  v36 = 3;  cycle.time(o7, v36);  if (v44 == 14)
    {    set.priority(ego, 14);    }  if (isset(f48))
    {    get.posn(ego, v40, v41);    if (v44 == 0)
      {      set.priority(ego, 14);      if (v41 > 114)
        {        v41 = 114;        }      if (v41 < 92)
        {        v41 = 92;        }      position.v(ego, v40, v41);      }    if (v44 == 11)
      {      release.priority(ego);      if (v41 < 105)
        {        ignore.blocks(ego);        }      else
        {        observe.blocks(ego);        }      }    position.v(ego, v40, v41);    }  if (v44 == 30)
    {    set(f220);    set.view(ego, View0);    set.priority(ego, 14);    set(f48);    position.v(ego, v57, v58);    set(f47);    }  if (isset(f47))
    {    draw(ego);    }  v36 = 0;  call(Logic112);  call(Logic120);  show.pic();  return();  }if (v62 == 1 &&     v53 <= 0 &&     v52 < 30 &&     v52 > 0)
  {  v52 = 30;  }if (v62 > 1)
  {  print("With a sinking feeling, you notice that the large ship is no longer "        "tied to the pier. It looks like you missed the boat!");  stop.cycling(ego);  set(f44);  }if (isset(f33) &&     v44 == 0)
  {  set.view(ego, View0);  set.priority(ego, 14);  v44 = 0;  }if (v44 == 11)
  {  release.priority(ego);  if (v41 < 138)
    {    ignore.blocks(ego);    }  else
    {    observe.blocks(ego);    }  }if (v44 == 0)
  {  if (isset(egoHitSpecial) &&       !isset(f46))
    {    set(f46);    sound(Sound1, f238);    v44 = 6;    ignore.blocks(ego);    set.view(ego, View11);    if (v41 < 87)
      {      set.priority(ego, 4);      v36 = 3;      v38 = 135;      move.obj.v(ego, v40, v38, v36, f221);      }    if (v41 > 114)
      {      set.priority(ego, 15);      v36 = 3;      v38 = 167;      move.obj.v(ego, v40, v38, v36, f221);      }    if (posn(ego, 106, 91, 128, 113))
      {      set.priority(ego, 11);      v36 = 3;      v38 = v41;      v38  += 38;      move.obj.v(ego, v40, v38, v36, f221);      }    }  }if (v44 == 6 &&     isset(f221))
  {  reset(f46);  reset(f221);  release.priority(ego);  observe.blocks(ego);  set(f35);  set.view(ego, View3);  v44 = 11;  sound(Sound11, f238);  }reset(onWater);if (v44 == 11)
  {  set(onWater);  if (v41 > 138)
    {    observe.blocks(ego);    }  else
    {    ignore.blocks(ego);    }  }if (isset(haveInput))
  {  if ((said("examine", "ship") ||       said("examine", "bandit", "ship")))
    {    if (v62 == 1)
      {      print("A large ship is tied to the dock.");      }    else
      {      print("What ship?");      }    }  if ((said("board", "ship") ||       said("jump", "ship")))
    {    if (v62 == 1)
      {      print("There is no way to do that.");      }    else
      {      print("What ship?");      }    }  if (said("examine", "town"))
    {    print("A charming village sits atop a bluff overlooking the ocean.");    }  if (said("examine", "dock"))
    {    print("A weathered dock leads into the ocean.");    }  }call(Logic112);call(Logic120);if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic30);  }if (edgeEgoHit == TOP_EDGE)
  {  v176 = edgeEgoHit;  new.room(Logic31);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic75);  }if (edgeEgoHit == RIGHT_EDGE)
  {  v176 = edgeEgoHit;  new.room(Logic31);  }return();[ Messages#message 1 "A large ship is tied to the dock."#message 2 "What ship?"#message 3 "There is no way to do that."#message 4 "A charming village sits atop a bluff overlooking the ocean."#message 5 "A weathered dock leads into the ocean."#message 6 "With a sinking feeling, you notice that the large ship is no longer tied to the pier. It looks like you missed the boat!"