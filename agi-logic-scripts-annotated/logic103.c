if (isset(newRoom))
{  reset(f37);  if (isset(f32))
  {    load.view(View35);    load.sound(Sound6);  }  load.view(View1);  load.view(View11);  load.sound(Sound1);  if (v44 == 6)
  {    v33 = 6;  }  else
  {    return();  }}if (isset(f45))
{  --v249;  if (v249 == 1)
  {    reset(f238);    print("Ouch!");    stop.sound();    v249 = 0;    v33 = 2;    if (monitorType != MONO)
    {      clear.lines(22, 22, BLACK);    }  }  --v253;  if (v253 == 1)
  {    if (monitorType != MONO)
    {      clear.lines(24, 24, BLACK);    }  }}if (v249 > 0 &&  isset(f238))
{  sound(Sound6, f238);}if (v44 != 6 &&  !isset(newRoom) &&  v252 <= 0 &&  isset(egoHitSpecial))
{  v33 = 6;}if (v33 == 2)
{  v33 = 0;  v44 = 0;  set.view(ego, View0);  release.priority(ego);  observe.blocks(ego);  observe.objs(ego);  v61 = 1;  v60 = 1;  v59 = 1;  step.size(ego, v61);  step.time(ego, v60);  cycle.time(ego, v59);  start.motion(ego);  reset(f35);  reset(f38);  reset(f37);  reset(f46);}if (v33 == 6)
{  edgeEgoHit = NOT_HIT;  v33 = 0;  v44 = 6;  v250 = v40;  v251 = v41;  set.view(ego, View11);  set(f35);  set(f38);  set(f37);  set(f46);  ignore.blocks(ego);  ignore.objs(ego);  if (v40 > 145)
  {    v40 = 145;    reposition.to.v(ego, v40, v41);  }  v69 = 3;  move.obj.v(ego, v40, v34, v69, f248);  sound(Sound1, f41);  if (monitorType != MONO)
  {    clear.lines(22, 22, BLACK);    clear.lines(24, 24, BLACK);  }  set.text.attribute(YELLOW, BLACK);  v253 = 5;  if (isset(f31) &&    monitorType != MONO)
  {    if (v39 > 0)
    {      display(24, 0, "Fell from %v250/%v251, area %v39");    }    else
    {      display(24, 0, "ERROR!! Fell from %v250/%v251.");    }  }  set.text.attribute(WHITE, BLACK);}if (isset(f248))
{  reset(f248);  stop.motion(ego);  if (monitorType != MONO)
  {    clear.lines(22, 22, BLACK);  }  if (!isset(f32))
  {    if (isset(f31))
    {      set(f40);    }    else
    {      erase(ego);      if (monitorType != MONO)
      {        clear.lines(22, 22, BLACK);      }      stop.cycling(ego);      set(f44);    }  }  else
  {    v253 = 10;    v44 = 18;    sound(Sound6, f238);    set.view(ego, View35);    v249 = 5;  }}if (isset(f31) &&  isset(f40))
{  reset(f40);  v33 = 2;  v249 = 0;  v252 = 33;  normal.motion(ego);  reposition.to.v(ego, v250, v251);}--v252;if (v252 > 0)
{  set(f37);  if (v252 == 1)
  {    reset(f37);  }}return();[Messages#message 1 ""#message 2 "Ouch!"#message 3 "Fell from %v250/%v251, area %v39"#message 4 "ERROR!! Fell from %v250/%v251."
