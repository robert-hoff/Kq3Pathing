// at the stern of the ship
if (isset(newRoom))
{  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  v56 = 7;  v57 = 84;  v58 = 68;  v32 = 0;  v31 = 0;  load.logics(Logic112);  load.logics(Logic116);  if (v62 < 4)
  {    load.view(View172);    animate.obj(o5);    set.view(o5, View172);    set.loop(o5, 0);    position(o5, 58, 156);    ignore.objs(o5);    v36 = 2;    cycle.time(o5, v36);    draw(o5);    animate.obj(o6);    set.view(o6, View172);    set.loop(o6, 1);    position(o6, 31, 147);    v36 = 2;    cycle.time(o6, v36);    ignore.objs(o6);    draw(o6);  }  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  if (v183 > 0)
  {    set(f46);    prevent.input();    program.control();    load.view(View159);    add.to.pic(View159, 1, 4, 80, 66, 13, 4);    discard.view(View159);    load.view(View156);    add.to.pic(View156, 1, 0, 87, 70, 13, 4);    discard.view(View156);    load.sound(Sound7);    load.sound(Sound1);    load.view(View162);    load.view(View16);    set.view(ego, View16);    set.loop(ego, 1);    set.priority(ego, 15);    position(ego, 78, 68);    ignore.objs(ego);    ignore.blocks(ego);    draw(ego);    animate.obj(o3);    set.view(o3, View16);    set.loop(o3, 0);    set.priority(o3, 15);    position(o3, 64, 72);    draw(o3);    block(0, 130, 36, 167);    animate.obj(o4);    load.view(View56);    set.view(o4, View56);    position(o4, 15, 140);    set.loop(o4, 0);    fix.loop(o4);    wander(o4);    draw(o4);  }  else
  {    load.view(View0);    set.priority(ego, 13);    if (isset(f48))
    {      position(ego, 87, 68);    }    if (v44 == 30)
    {      set.view(ego, View0);      set(f48);      position.v(ego, v57, v58);      set(f47);      set.priority(ego, 13);    }    if (isset(f47))
    {      draw(ego);    }  }  v36 = 0;  if (v62 == 2)
  {    v36 = 1;  }  call(Logic112);  show.pic();  return();}
if (isset(f77) && v62 == 4)
{  erase(o5);  erase(o6);}call(Logic116);

if (isset(f33) && v44 == 0)
{  set.priority(ego, 13);}
if (v183 == 1)
{  print("Now you've gone and done it!");  ++v183;  move.obj(ego, 60, 68, 1, f220);}
if (isset(f220))
{  program.control();}
if (v183 == 2 && isset(f220))
{  ++v183;  set(f36);  sound(Sound1, f238);  move.obj(ego, 60, 150, 6, f220);}
if (v183 == 3 && isset(f220))
{  ++v183;  sound(Sound7, f238);  v36 = 0;  reset(f36);  set(f35);  set.cel(ego, 0);  set.view(ego, View162);  get.posn(ego, v37, v38);  v37 -= 6;  v38 -= 4;  reposition.to.v(ego, v37, v38);  end.of.loop(ego, f220);}
if (v183 == 4 && isset(f220))
{  ++v183;  get.posn(ego, v40, v41);  erase(ego);  unblock();  v36 = 1;  move.obj.v(o4, v40, v41, v36, f220);}
if (v183 == 5 && isset(f220))
{  ++v183;  erase(o4);  reset(f220);  print("As you sink beneath the waves you hear the crew rooting for the shark!");  stop.cycling(ego);  set(f44);}call(Logic112);
if (said("examine") || said("examine", "ship"))
{  print("You are standing at the aft end of the ship.");}
if (said("examine", "up", "sky") || said("examine", "sky")))
{if (v62 == 2)
{  print("The sky is cloudless. Some sea birds can be seen in the far distance.");}else
{  print("The sky is cloudless. Some shore birds are wheeling overhead. It "    "appears that the ship is near land!");}}
if ((said("examine", "desert") ||  said("examine", "above", "bay") ||  said("examine", "bay") ||  said("examine", "above", "liquid") ||  said("examine", "liquid")))
{  if (v62 == 2)
  {    print("The deep, blue ocean stretches out to the horizon. There is no land "      "in sight.");  }  if (v62 == 3)
  {    print("The ocean is calm and untroubled. Sea gulls wing nearby. To the east "      "you see what might be land.");  }  if (v62 == 4)
  {    print("The ocean is calm and untroubled. Sea gulls wing nearby. The ship is "      "anchored in a small bay. Further north, a mountain range looms.");  }}
if (v62 == 4 && (said("examine", "beach") || said("examine", "beach")))
{  print("The ocean is calm and untroubled. Sea gulls wing nearby. The ship is "    "anchored in a small bay. Further north, a mountain range looms.");}
if ((said("dive", "bay") ||  said("board", "bay") ||  said("capture", "bay") ||  said("jump") ||  said("jump", "ship") ||  said("jump", "bay") ||  said("dive") ||  said("dive", "liquid") ||  said("board", "liquid") ||  said("capture", "liquid") ||  said("jump") ||  said("jump", "ship") ||  said("jump", "liquid") ||  said("dive")))
{  print("You endeavor to climb over the railing, but change your mind as you "    "feel it might be unsafe!");}

if (edgeEgoHit > NOT_HIT && (v44 == 25 || v44 == 26))
{  if (edgeEgoHit != RIGHT_EDGE)
  {    if (v62 != 4)
    {      new.room(Logic31);    }    else
    {      new.room(Logic48);    }  }  else
  {    new.room(Logic80);  }}if (isset(egoHitSpecial) && v44 == 0)
{  release.priority(ego);  new.room(Logic83);}return();

[Messages#message 1 "You are standing at the aft end of the ship."#message 2 "The sky is cloudless. Some sea birds can be seen in the far distance."#message 3 "The sky is cloudless. Some shore birds are wheeling overhead. It appears that the ship is near land!"#message 4 "The deep, blue ocean stretches out to the horizon. There is no land in sight."#message 5 "As you sink beneath the waves you hear the crew rooting for the shark!"#message 6 "Now you've gone and done it!"#message 7 "You endeavor to climb over the railing, but change your mind as you feel it might be unsafe!"#message 9 "The ocean is calm and untroubled. Sea gulls wing nearby. To the east you see what might be land."#message 10 "The ocean is calm and untroubled. Sea gulls wing nearby. The ship is anchored in a small bay. Further north, a mountain range looms."
