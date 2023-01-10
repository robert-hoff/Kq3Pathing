if (isset(newRoom)) {  load.view(View249);  animate.obj(o12);  set.view(o12, View249);  position(o12, 20, 6);  ignore.objs(o12);  ignore.horizon(o12);  wander(o12);  set(f202);
  if (v36 > 0)
  {    set.loop(o12, 1);  }  else
  {    set.loop(o12, 0);  }  fix.loop(o12);  set.cel(o12, 2);  set.priority(o12, 4);  draw(o12);  animate.obj(o13);  set.view(o13, View249);  if (v36 > 0)
  {    set.loop(o13, 1);  }  else
  {    set.loop(o13, 0);  }  fix.loop(o13);  position(o13, 20, 4);  ignore.horizon(o13);  ignore.objs(o13);  wander(o13);  set(f203);  set.priority(o13, 4);  draw(o13);}
get.posn(o12, v37, v38);if (v38 > 35)
  {  normal.motion(o12);  v38 = 1;  set.dir(o12, v38);  reset(f202);  }else
  {  if (!isset(f202))
    {    wander(o12);    set(f202);    }  }get.posn(o13, v37, v38);if (v38 > 35)
  {  normal.motion(o13);  v38 = 1;  set.dir(o13, v38);  reset(f203);  }else
  {  if (!isset(f203))
    {    set(f203);    wander(o13);    }  }get.dir(o12, v38);if (v38 > 3 &&    v38 < 7)
  {  current.loop(o12, v36);  if (v36 <= 0)
    {    set.cel(o12, 4);    }  else
    {    set.cel(o12, 0);    }  stop.cycling(o12);  }else
  {  start.cycling(o12);  }get.dir(o13, v38);if (v38 > 3 &&    v38 < 7)
  {  current.loop(o13, v36);  if (v36 <= 0)
    {    set.cel(o13, 4);    }  else
    {    set.cel(o13, 0);    }  stop.cycling(o13);  }else
  {  start.cycling(o13);  }if (isset(f44))
  {  block(0, 0, 159, 40);  start.cycling(o12);  wander(o12);  start.cycling(o13);  wander(o13);  }if (said("examine", "bird"))
  {  print("The gulls soar gracefully on the sea breezes.");  }if (said("capture", "bird"))
  {  print("The gulls are too wary of humans for them to be easily caught.");  }return();[ Messages#message 1 "The gulls soar gracefully on the sea breezes."#message 2 "The gulls are too wary of humans for them to be easily caught."