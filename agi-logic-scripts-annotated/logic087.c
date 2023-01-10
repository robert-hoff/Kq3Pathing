if (isset(newRoom))
{  load.pic(currentRoom);  draw.pic(currentRoom);  set.horizon(80);  load.sound(Sound9);  load.sound(Sound15);  load.view(View0);  load.view.v(currentEgoView);  set.view(ego, View0);  set(f46);  v57 = 76;  v58 = 100;  position.v(ego, v57, v58);  draw(ego);  animate.obj(o13);  load.view(View236);  set.view(o13, View236);  ignore.horizon(o13);  set.cel(o13, 1);  position(o13, 30, 35);  draw(o13);  set(f220);  show.pic();  return();}if (!isset(f221))
{  set(f221);  print("Dark storm clouds begin to gather around until you are enveloped by "    "them. You hear loud reports of thunderclaps and lightning flashes "    "frighteningly close.");}if (v220 > 8)
{  stop.cycling(o13);}if (v220 == 8)
{  sound(Sound15, f238);  start.cycling(o13);}if (v220 <= 0)
{  sound(Sound9, f238);  shake.screen(1);  random(15, 40, v220);  random(1, 144, v37);  v38 = 35;  reposition.to.v(o13, v37, v38);  random(0, 1, v64);  set.loop.v(o13, v64);  set.cel(o13, 1);  stop.cycling(o13);}--v220;if (v71 == 10)
{  set(f222);}if (v76 <= 0 &&  v75 <= 0)
{  set(f222);}if (isset(f222))
{  v44 = 30;  if (v72 > 0)
  {    currentRoom = v72;    v44 = 0;  }  v76 = 0;  v75 = 0;  v72 = 0;  reset(f46);  new.room.v(previousRoom);}return();[Messages#message 1 "Dark storm clouds begin to gather around until you are enveloped by them. You hear loud reports of thunderclaps and lightning flashes frighteningly close."#message 2 ""
