if (isset(newRoom))
  {  prevent.input();  program.control();  set(f42);  set(f46);  animationInterval = 2;  load.view(View0);  load.view(View96);  load.view(View205);  load.view(View206);  load.view(View190);  load.view(View193);  load.sound(Sound23);  v36 = 34;  load.pic(v36);  draw.pic(v36);  discard.pic(v36);  animate.obj(o3);  position(o3, 38, 129);  set.view(o3, View96);  set.loop(o3, 0);  set.cel(o3, 0);  v36 = 3;  cycle.time(o3, v36);  draw(o3);  stop.update(o3);  animate.obj(o4);  ignore.blocks(o4);  ignore.objs(o4);  position(o4, 92, 129);  set.view(o4, View96);  set.loop(o4, 1);  set.cel(o4, 0);  set.priority(o4, 10);  draw(o4);  stop.update(o4);  animate.obj(o1);  position(o1, 123, 123);  set.view(o1, View205);  draw(o1);  wander(o1);  v222 = 33;  animate.obj(o2);  position(o2, 120, 133);  set.view(o2, View205);  draw(o2);  wander(o2);  v221 = 44;  v32 = 0;  v31 = 0;  animate.obj(o15);  position(o15, 38, 132);  set.view(o15, View190);  set.loop(o15, 0);  v36 = 2;  cycle.time(o15, v36);  set.view(ego, View0);  set.loop(ego, 3);  stop.cycling(ego);  reset(f35);  position(ego, 82, 109);  draw(ego);  show.pic();  sound(Sound23, f223);  return();  }--v222;if (v222 == 22)
  {  normal.motion(o1);  stop.motion(o1);  set.view(o1, View206);  }if (v222 == 1)
  {  v222 = 33;  set.view(o1, View205);  wander(o1);  }--v221;if (v221 == 15)
  {  normal.motion(o2);  stop.motion(o2);  set.view(o2, View206);  }if (v221 == 1)
  {  v221 = 44;  set.view(o2, View205);  wander(o2);  }if (isset(f45))
  {  --v50;  if ((v47 == 10 ||       v47 == 15 ||       v47 == 20 ||       v50 == 1))
    {    set(f220);    }  }if (isset(f220))
  {  reset(f220);  ++v220;  if (v220 == 1)
    {    printTimeout = 31;    print.at("Gwydion is a lonely lad of seventeen who has lived for as long as "             "he can remember with an evil and cruel wizard, by the name of "             "Manannan. Gwydion gazes upon the countryside of Llewdor with "             "longing, wishing he were free to leave. But, alas, such is not "             "the case.", 2, 2, 37);    }  if (v220 == 2)
    {    printTimeout = 26;    print.at("Manannan treats the poor boy like his slave; ordering him about, "             "constantly threatening him, and refusing to ever let him leave "             "the premises. Often, Gwydion wonders who he really is, and how he "             "came to live with the old wizard. But, Manannan offers no help in "             "that area.", 2, 2, 37);    }  if (v220 == 3)
    {    start.update(o3);    end.of.loop(o3, f220);    }  if (v220 == 4)
    {    stop.update(o3);    draw(o15);    move.obj(o15, 65, 139, 0, f101);    printTimeout = 12;    print.at("Suddenly, the front door opens and out stalks Manannan, the "             "wizard! \"GWYDION!!\" he shouts harshly.", 2, 2, 37);    v50 = 3;    }  if (v220 == 5)
    {    set(f35);    move.obj(ego, 82, 138, 1, f220);    }  if (v220 == 6)
    {    move.obj(ego, 80, 138, 1, f220);    }  if (v220 == 7)
    {    reset(f35);    stop.cycling(ego);    printTimeout = 42;    print.at("Oh, oh! Gwydion rushes to his side, afraid he may be in trouble. "             "\"Why are you not WORKING, boy?\" the wizard sneers. Gwydion "             "mumbles a faint reply. \"The kitchen floor is FILTHY!\" Manannan "             "grumbles. \"Go sweep it. NOW!!\" Turning on his heel, the wizard "             "re-enters the house, slamming the door behind him.", 2, 2, 37);    set(f129);    v137 = 1;    v110 = 3;    v50 = 3;    }  if (v220 == 8)
    {    set.loop(o15, 1);    start.cycling(o15);    move.obj(o15, 38, 132, 1, f220);    }  if (v220 == 9)
    {    erase(o15);    start.update(o3);    reverse.loop(o3, f220);    }  if (v220 == 10)
    {    stop.update(o3);    v50 = 3;    }  if (v220 == 11)
    {    stop.cycling(ego);    set.loop(ego, 2);    set.cel(ego, 0);    v50 = 5;    }  if (v220 == 12)
    {    start.cycling(ego);    set(f35);    move.obj(ego, 39, 132, 1, f220);    printTimeout = 24;    print.at("Such is the story of young Gwydion's life to this point. What's a "             "poor boy to do? Oh, well. In resignation, Gwydion obediently "             "follows Manannan into the house.", 2, 2, 37);    }  if (v220 == 13)
    {    reset(f35);    stop.cycling(ego);    start.update(o3);    end.of.loop(o3, f220);    }  if (v220 == 14)
    {    new.room(Logic45);    }  }if (isset(f101))
  {  reset(f101);  stop.cycling(o15);  }if (isset(f223))
  {  sound(Sound23, f223);  }return();[ Messages#message 1 "Gwydion is a lonely lad of seventeen who has lived for as long as he can remember with an evil and cruel wizard, by the name of Manannan. Gwydion gazes upon the countryside of Llewdor with longing, wishing he were free to leave. But, alas, such is not the case."#message 2 "Manannan treats the poor boy like his slave; ordering him about, constantly threatening him, and refusing to ever let him leave the premises. Often, Gwydion wonders who he really is, and how he came to live with the old wizard. But, Manannan offers no help in that area."#message 3 "Suddenly, the front door opens and out stalks Manannan, the wizard! \"GWYDION!!\" he shouts harshly."#message 4 "Oh, oh! Gwydion rushes to his side, afraid he may be in trouble. \"Why are you not WORKING, boy?\" the wizard sneers. Gwydion mumbles a faint reply. \"The kitchen floor is FILTHY!\" Manannan grumbles. \"Go sweep it. NOW!!\" Turning on his heel, the wizard re-enters the house, slamming the door behind him."#message 5 "Such is the story of young Gwydion's life to this point. What's a poor boy to do? Oh, well. In resignation, Gwydion obediently follows Manannan into the house."