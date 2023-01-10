if (isset(newRoom))
{  set.horizon(1);  prevent.input();  program.control();  status.line.off();  set(f42);  animationInterval = 1;  load.sound(Sound21);  load.sound(Sound22);  load.view(View60);  load.view(View61);  load.view(View62);  load.view(View64);  load.view(View65);  v227 = 47;  load.pic(v227);  v220 = 46;  load.pic(v220);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  sound(Sound21, f229);  add.to.pic(View62, 0, 0, 59, 148, 4, 4);  add.to.pic(View62, 0, 1, 75, 148, 4, 4);  add.to.pic(View62, 0, 2, 87, 148, 4, 4);  v226 = 0;  v221 = 2;  v222 = 3;  v223 = 4;  v224 = 5;  v225 = 10;  set.view(ego, View65);  set.loop(ego, 1);  set.cel(ego, 0);  position(ego, 122, 77);  v36 = 4;  cycle.time(ego, v36);  reset(f35);  animate.obj(o1);  ignore.objs(o1);  set.view(o1, View62);  set.loop(o1, 2);  set.priority(o1, 15);  animate.obj(o2);  ignore.objs(o2);  set.view(o2, View62);  set.loop(o2, 2);  set.priority(o2, 15);  animate.obj(o3);  ignore.objs(o3);  set.view(o3, View62);  set.loop(o3, 2);  set.priority(o3, 15);  animate.obj(o4);  ignore.objs(o4);  set.view(o4, View62);  set.loop(o4, 2);  set.priority(o4, 15);  animate.obj(o5);  set.view(o5, View65);  set.cel(o5, 0);  position(o5, 93, 154);  animate.obj(o6);  set.view(o6, View62);  set.loop(o6, 1);  fix.loop(o6);  animate.obj(o7);  animate.obj(o8);  set.view(o8, View62);  set.loop(o8, 3);  fix.loop(o8);  ignore.objs(o8);  set.priority(o8, 15);  animate.obj(o9);  set.view(o9, View62);  set.loop(o9, 3);  fix.loop(o9);  ignore.objs(o9);  set.priority(o9, 15);  animate.obj(o10);  set.view(o10, View62);  set.loop(o10, 3);  fix.loop(o10);  ignore.objs(o10);  set.priority(o10, 15);  animate.obj(o11);  set.view(o11, View62);  set.loop(o11, 3);  fix.loop(o11);  ignore.objs(o11);  set.priority(o11, 15);  animate.obj(o12);  set.view(o12, View62);  set.loop(o12, 3);  fix.loop(o12);  ignore.objs(o12);  set.priority(o12, 15);  animate.obj(o13);  set.view(o13, View62);  set.loop(o13, 3);  fix.loop(o13);  ignore.objs(o13);  set.priority(o13, 15);  animate.obj(o14);  set.view(o14, View62);  set.loop(o14, 3);  fix.loop(o14);  ignore.objs(o14);  set.priority(o14, 15);  animate.obj(o15);  set.view(o15, View62);  set.loop(o15, 3);  fix.loop(o15);  ignore.objs(o15);  set.priority(o15, 15);  show.pic();  reset(f46);  return();}set(f46);if (isset(f229))
{  if (isset(soundOn) &&    (v226 == 1 ||      v226 == 3))
  {    reset(f220);    v225 = 2;  }  if (v226 != 3)
  {    sound(Sound22, f229);  }}if (isset(f45))
{  --v225;  if (v225 == 1)
  {    set(f220);  }}if (isset(f220))
{  reset(f220);  ++v226;  if (v226 == 1)
  {    if (monitorType != MONO)
    {      display(22, 13, "");      display(23, 3, "Adventure Game Development System");      display(24, 4, "(C) 1987 by Sierra On-Line, Inc.");    }    v225 = 9;  }  if (v226 == 2)
  {    v225 = 40;    if (monitorType != MONO)
    {      clear.lines(22, 24, BLACK);    }    reset(f221);    reset(f222);    reset(f223);    reset(f224);    erase(o1);    erase(o2);    erase(o3);    erase(o4);    v221 = 0;    v222 = 0;    v223 = 0;    v224 = 0;    draw.pic(v220);    add.to.pic(View64, 0, 0, 112, 160, 4, 4);    draw(o5);    end.of.loop(o5, f41);    draw(ego);    set(f35);    end.of.loop(ego, f228);    show.pic();  }  if (v226 == 3)
  {    draw.pic(v227);    unanimate.all();    show.pic();    display(3, 4, "Viewmaster:");    display(4, 9, "Dale Carlson");    display(6, 4, "Quality Assurance:");    display(7, 9, "Larry Weissenborn");    display(8, 9, "Bob Ballew");    display(9, 9, "Andrea Monsalve");    display(10, 9, "Russ Truelove");    display(11, 9, "Kim Covert");    display(12, 9, "Linda Bye");    display(14, 4, "Packaging and Documentation:");    display(15, 9, "Annette Childs");    display(16, 9, "Greg Steffen");    display(18, 4, "Key Grip:");    display(19, 9, "Ken Williams");    if (monitorType == MONO)
    {      display(22, 13, "");      display(23, 3, "Adventure Game Development System");      display(24, 4, "(C) 1987 by Sierra On-Line, Inc.");    }    v225 = 22;  }  if (v226 == 4)
  {    new.room(Logic46);  }}--v221;if (v221 == 1)
{  random(1, 13, v36);  if (v36 == 1)
  {    v37 = 39;    v38 = 77;  }  if (v36 == 2)
  {    v37 = 48;    v38 = 107;  }  if (v36 == 3)
  {    v37 = 68;    v38 = 73;  }  if (v36 == 4)
  {    v37 = 92;    v38 = 79;  }  if (v36 == 5)
  {    v37 = 105;    v38 = 106;  }  if (v36 == 6)
  {    v37 = 126;    v38 = 88;  }  if (v36 == 7)
  {    v37 = 132;    v38 = 106;  }  if (v36 == 8)
  {    v37 = 55;    v38 = 57;  }  if (v36 == 9)
  {    v37 = 99;    v38 = 46;  }  if (v36 == 10)
  {    v37 = 55;    v38 = 150;  }  if (v36 == 11)
  {    v37 = 100;    v38 = 153;  }  if (v36 == 12)
  {    v37 = 94;    v38 = 136;  }  if (v36 == 13)
  {    v37 = 72;    v38 = 63;  }  position.v(o1, v37, v38);  set.cel(o1, 0);  draw(o1);  end.of.loop(o1, f221);}if (isset(f221))
{  reset(f221);  erase(o1);  random(4, 10, v221);}--v222;if (v222 == 1)
{  random(1, 13, v36);  if (v36 == 1)
  {    v37 = 39;    v38 = 77;  }  if (v36 == 2)
  {    v37 = 48;    v38 = 107;  }  if (v36 == 3)
  {    v37 = 68;    v38 = 73;  }  if (v36 == 4)
  {    v37 = 92;    v38 = 79;  }  if (v36 == 5)
  {    v37 = 105;    v38 = 106;  }  if (v36 == 6)
  {    v37 = 126;    v38 = 88;  }  if (v36 == 7)
  {    v37 = 132;    v38 = 106;  }  if (v36 == 8)
  {    v37 = 55;    v38 = 57;  }  if (v36 == 9)
  {    v37 = 99;    v38 = 46;  }  if (v36 == 10)
  {    v37 = 55;    v38 = 150;  }  if (v36 == 11)
  {    v37 = 100;    v38 = 153;  }  if (v36 == 12)
  {    v37 = 94;    v38 = 136;  }  if (v36 == 13)
  {    v37 = 72;    v38 = 63;  }  position.v(o2, v37, v38);  draw(o2);  set.cel(o2, 0);  end.of.loop(o2, f222);}if (isset(f222))
{  reset(f222);  erase(o2);  random(4, 10, v222);}--v223;if (v223 == 1)
{  random(1, 13, v36);  if (v36 == 1)
  {    v37 = 39;    v38 = 77;  }  if (v36 == 2)
  {    v37 = 48;    v38 = 107;  }  if (v36 == 3)
  {    v37 = 68;    v38 = 73;  }  if (v36 == 4)
  {    v37 = 92;    v38 = 79;  }  if (v36 == 5)
  {    v37 = 105;    v38 = 106;  }  if (v36 == 6)
  {    v37 = 126;    v38 = 88;  }  if (v36 == 7)
  {    v37 = 132;    v38 = 106;  }  if (v36 == 8)
  {    v37 = 55;    v38 = 57;  }  if (v36 == 9)
  {    v37 = 99;    v38 = 46;  }  if (v36 == 10)
  {    v37 = 55;    v38 = 150;  }  if (v36 == 11)
  {    v37 = 100;    v38 = 153;  }  if (v36 == 12)
  {    v37 = 94;    v38 = 136;  }  if (v36 == 13)
  {    v37 = 72;    v38 = 63;  }  position.v(o3, v37, v38);  set.cel(o3, 0);  draw(o3);  end.of.loop(o3, f223);}if (isset(f223))
{  reset(f223);  erase(o3);  random(4, 10, v223);}--v224;if (v224 == 1)
{  random(1, 13, v36);  if (v36 == 1)
  {    v37 = 39;    v38 = 77;  }  if (v36 == 2)
  {    v37 = 48;    v38 = 107;  }  if (v36 == 3)
  {    v37 = 68;    v38 = 73;  }  if (v36 == 4)
  {    v37 = 92;    v38 = 79;  }  if (v36 == 5)
  {    v37 = 105;    v38 = 106;  }  if (v36 == 6)
  {    v37 = 126;    v38 = 88;  }  if (v36 == 7)
  {    v37 = 132;    v38 = 106;  }  if (v36 == 8)
  {    v37 = 55;    v38 = 57;  }  if (v36 == 9)
  {    v37 = 99;    v38 = 46;  }  if (v36 == 10)
  {    v37 = 55;    v38 = 150;  }  if (v36 == 11)
  {    v37 = 100;    v38 = 153;  }  if (v36 == 12)
  {    v37 = 94;    v38 = 136;  }  if (v36 == 13)
  {    v37 = 72;    v38 = 63;  }  position.v(o4, v37, v38);  set.cel(o4, 0);  draw(o4);  end.of.loop(o4, f224);}if (isset(f224))
{  reset(f224);  erase(o4);  random(4, 10, v224);}v36 = 0;current.cel(o5, v36);if (v36 == 2)
{  position(o6, 90, 120);  draw(o6);  move.obj(o6, 54, 84, 5, f225);}if (isset(f225))
{  reset(f225);  erase(o6);  position(o8, 54, 70);  position(o9, 54, 70);  position(o10, 54, 70);  position(o11, 54, 70);  position(o12, 54, 70);  position(o13, 54, 70);  position(o14, 54, 70);  position(o15, 54, 70);  draw(o8);  draw(o9);  draw(o10);  draw(o11);  draw(o12);  draw(o13);  draw(o14);  draw(o15);  move.obj(o8, 54, 30, 5, f227);  move.obj(o9, 84, 30, 5, f227);  move.obj(o10, 84, 70, 5, f227);  move.obj(o11, 84, 110, 5, f227);  move.obj(o12, 54, 110, 5, f227);  move.obj(o13, 14, 110, 5, f227);  move.obj(o14, 14, 70, 5, f227);  move.obj(o15, 14, 30, 5, f227);}if (isset(f227))
{  reset(f227);  erase(o8);  erase(o9);  erase(o10);  erase(o11);  erase(o12);  erase(o13);  erase(o14);  erase(o15);  ++v228;  if (v228 == 1)
  {    set.view(o7, View60);    set.loop(o7, 0);    v37 = 19;    v38 = 80;    v81 = 31;  }  if (v228 == 2)
  {    set.view(o7, View60);    set.loop(o7, 1);    v37 = 20;    v38 = 90;    v81 = 40;  }  if (v228 == 3)
  {    set.view(o7, View60);    set.loop(o7, 2);    v37 = 17;    v38 = 92;    v81 = 43;  }  if (v228 == 4)
  {    set.view(o7, View61);    set.loop(o7, 0);    v37 = 25;    v38 = 86;    v81 = 32;  }  if (v228 == 5)
  {    set.view(o7, View61);    set.loop(o7, 2);    v37 = 24;    v38 = 86;    v81 = 33;  }  fix.loop(o7);  position.v(o7, v37, v38);  v69 = 2;  draw(o7);  move.obj.v(o7, v37, v81, v69, f226);  set.cel(ego, 0);}if (isset(f226))
{  reset(f226);  erase(o7);  if (v228 < 5)
  {    set.cel(o5, 0);    end.of.loop(o5, f41);    set(f35);    end.of.loop(ego, f228);  }  else
  {    reset(f220);    v225 = 2;  }}if (isset(f228))
{  reset(f228);  reset(f35);  v229 = 14;}--v229;if (v229 == 1)
{  set.cel(ego, 0);}return();[Messages#message 1 ""#message 2 "Adventure Game Development System"#message 3 "(C) 1987 by Sierra On-Line, Inc."#message 11 "Viewmaster:"#message 12 "Dale Carlson"#message 21 "Quality Assurance:"#message 22 "Larry Weissenborn"#message 23 "Bob Ballew"#message 24 "Andrea Monsalve"#message 25 "Russ Truelove"#message 26 "Kim Covert"#message 27 "Linda Bye"#message 31 "Packaging and Documentation:"#message 32 "Annette Childs"#message 33 "Greg Steffen"#message 41 "Key Grip:"#message 42 "Ken Williams"
