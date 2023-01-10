if (isset(newRoom))
  {  if (isset(f46))
    {    return();    }  if (currentRoom != 17 &&       currentRoom != 22 &&       currentRoom != 23 &&       currentRoom != 27)
    {    return();    }  load.view(View210);  load.view(View211);  load.view(View35);  load.sound(Sound26);  load.sound(Sound6);  animate.obj(o1);  animate.obj(o2);  set.view(o1, View210);  set.view(o2, View211);  if (currentRoom == 17)
    {    random(1, 2, v36);    if (v36 == 1)
      {      position(o1, 113, 128);      move.obj(o1, 83, 128, 2, f244);      }    else
      {      position(o1, 137, 91);      move.obj(o1, 115, 91, 2, f244);      }    random(1, 2, v36);    if (v36 == 1)
      {      position(o2, 54, 166);      move.obj(o2, 64, 156, 2, f244);      }    else
      {      position(o2, 50, 61);      move.obj(o2, 62, 73, 2, f244);      }    }  if (currentRoom == 22)
    {    random(1, 2, v36);    if (v36 == 1)
      {      position(o1, 111, 112);      move.obj(o1, 94, 112, 2, f244);      }    else
      {      position(o1, 129, 68);      move.obj(o1, 114, 68, 2, f244);      }    random(1, 2, v36);    if (v36 == 1)
      {      position(o2, 42, 68);      move.obj(o2, 54, 68, 2, f244);      }    else
      {      position(o2, 25, 105);      move.obj(o2, 55, 105, 2, f244);      }    }  if (currentRoom == 23)
    {    random(1, 2, v36);    if (v36 == 1)
      {      position(o1, 145, 156);      move.obj(o1, 133, 145, 2, f244);      }    else
      {      position(o1, 34, 92);      move.obj(o1, 66, 92, 2, f244);      }    random(1, 2, v36);    if (v36 == 1)
      {      position(o2, 121, 97);      move.obj(o2, 100, 97, 2, f244);      }    else
      {      position(o2, 9, 123);      move.obj(o2, 48, 123, 2, f244);      }    }  if (currentRoom == 27)
    {    random(1, 2, v36);    if (v36 == 1)
      {      position(o1, 121, 139);      move.obj(o1, 97, 139, 2, f244);      }    else
      {      position(o1, 60, 166);      move.obj(o1, 75, 151, 2, f244);      }    random(1, 2, v36);    if (v36 == 1)
      {      position(o2, 31, 141);      set.loop(o2, 0);      move.obj(o2, 53, 141, 2, f244);      }    else
      {      position(o2, 125, 68);      move.obj(o2, 108, 68, 2, f244);      }    }  random(5, 11, v240);  if (isset(f31) &&       monitorType != MONO)
    {    set.text.attribute(RED, BLACK);    display(22, 0, "Bandits in %v240.");    set.text.attribute(WHITE, BLACK);    }  return();  }if (!isset(f241) &&     !isset(f242))
  {  goto(Label1);  }if (said("examine", "bandit"))
  {  print("They are dirty and unkempt, their hair is wild and their clothes "        "smell. Mean looks darken their faces. These are two to avoid!");  }if (said("call", "bandit"))
  {  print("This is no time for conversation! Get out of here!! ");  }if ((said("capture", "bandit") ||     said("capture", "bandit")))
  {  print("If you think you can capture these two you'd better think again.");  }if ((said("kill", "bandit") ||     said("hit", "bandit")))
  {  print("You think you can hurt two husky bandits!? Think again.");  }Label1:if (isset(f45))
  {  if (isset(f31) &&       v47 == 5 &&       monitorType != MONO)
    {    clear.lines(22, 22, BLACK);    }  --v240;  if (v240 == 1)
    {    set(f244);    }  }if (isset(f244) &&     !isset(f245))
  {  reset(f244);  ++v241;  if (v241 == 1)
    {    if (isset(f46))
      {      v241 = 0;      }    else
      {      set(f241);      set(f242);      draw(o1);      draw(o2);      sound(Sound26, f41);      }    }  if (v241 == 2)
    {    v36 = 2;    step.size(o1, v36);    step.size(o2, v36);    if ((isset(f49) ||         isset(f46) ||         v44 == 26 ||         v44 == 25))
      {      set(f245);      wander(o1);      wander(o2);      }    else
      {      follow.ego(o1, 5, f244);      follow.ego(o2, 5, f244);      print("These two are certainly unsavory rogues! They look like they'd rob "            "you blind!!");      }    }  if (v241 == 3)
    {    if ((isset(f49) ||         isset(f46) ||         v44 == 26 ||         v44 == 25))
      {      set(f245);      wander(o1);      wander(o2);      }    else
      {      set(f246);      program.control();      stop.update(o1);      stop.update(o2);      prevent.input();      stop.motion(ego);      ignore.objs(ego);      set.view(ego, View35);      set(f35);      v44 = 18;      set(f243);      v240 = 4;      }    }  if (v241 == 4)
    {    v240 = 15;    start.update(o1);    start.update(o2);    wander(o1);    wander(o2);    v36 = 2;    step.size(o1, v36);    step.size(o2, v36);    v36 = 1;    v67 = 38;    reset(f240);Label2:    get.room.v(v36, v64);    if (v64 == 255)
      {      put.v(v36, v67);      set(f240);      }    ++v36;    if (v36 == 8)
      {      ++v36;      }    if (v36 < 55)
      {      goto(Label2);      }    }  if (v241 == 5)
    {    erase(o1);    reset(f241);    erase(o2);    reset(f242);    player.control();    accept.input();    reset(f46);    reset(f35);    reset(f243);    release.priority(ego);    stop.sound();    start.motion(ego);    observe.objs(ego);    v44 = 0;    set.view(ego, View0);    if (isset(f246))
      {      reset(f246);      if (isset(f240))
        {        print("%m5Taking stock of your holdings, you discover that all of your "              "possessions have been stolen.");        set(f78);        }      else
        {        print("%m5At least you had nothing for the two bandits to steal.");        }      }    }  }if (objHitEdge > 0)
  {  if (objHitEdge == 1)
    {    erase(o1);    reset(f241);    }  if (objHitEdge == 2)
    {    erase(o2);    reset(f242);    }  if (!isset(f241) &&       !isset(f242) &&       !isset(f245))
    {    set(f244);    v241 = 4;    }  }if (isset(f243) &&     v44 == 18)
  {  sound(Sound6, f243);  }if (v44 == 18)
  {  edgeEgoHit = NOT_HIT;  }return();[ Messages#message 1 "They are dirty and unkempt, their hair is wild and their clothes smell. Mean looks darken their faces. These are two to avoid!"#message 2 "These two are certainly unsavory rogues! They look like they'd rob you blind!!"#message 3 "%m5Taking stock of your holdings, you discover that all of your possessions have been stolen."#message 4 "%m5At least you had nothing for the two bandits to steal."#message 5 "After recovering from a whack on the head at the hands of the bandits, you stand unsteadily. "#message 6 "This is no time for conversation! Get out of here!! "#message 7 "If you think you can capture these two you'd better think again."#message 8 "You think you can hurt two husky bandits!? Think again."#message 10 "Bandits in %v240."