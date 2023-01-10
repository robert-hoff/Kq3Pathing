if (isset(newRoom))
  {  if (isset(f42))
    {    reset(f42);    reset(f35);    reset(f36);    reset(f46);    set(f48);    if (monitorType != MONO)
      {      clear.lines(22, 24, BLACK);      }    currentEgoView = 0;    animationInterval = 2;    player.control();    accept.input();    v84 = 5;    v127 = 1;    if (isset(f129))
      {      v110 = 3;      v109 = 0;      }    }  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 1;  v57 = 96;  v58 = 137;  v32 = 39;  v31 = 92;  v100 = 81;  v101 = 123;  load.logics(Logic104);  observe.blocks(o13);  load.view(View230);  if (v44 == 23)
    {    set(f46);    reset(f35);    reset(f36);    reset(f37);    reset(f38);    load.view(View199);    load.view(View29);    load.sound(Sound36);    load.sound(Sound2);    }  else
    {    if ((v127 == 1 ||         v127 == 3) &&         v137 <= 0 &&         v128 != 20)
      {      random(1, 4, v36);      if (!isset(f129))
        {        v36 = 1;        }      if (v36 == 1)
        {        load.logics(Logic105);        set(f98);        random(6, 12, v125);        if (!isset(f129))
          {          v125 = 6;          }        }      }    }  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  animate.obj(o1);  ignore.objs(o1);  position(o1, 86, 84);  set.view(o1, View230);  draw(o1);  animate.obj(o2);  ignore.objs(o2);  position(o2, 114, 85);  set.view(o2, View230);  set.cel(o2, 1);  draw(o2);  if (v44 == 25)
    {    set(f48);    }  if (isset(f48))
    {    if (previousRoom == 3)
      {      set(f221);      set.priority(ego, 14);      v40 = 95;      v41 = 46;      }    else
      {      if (previousRoom == 5)
        {        v40 = 97;        v41 = 121;        }      else
        {        if (previousRoom == 8)
          {          v40 = 128;          v41 = 140;          }        else
          {          if (previousRoom == 34)
            {            v40 = 95;            v41 = 165;            }          else
            {            v40 = v57;            v41 = v58;            }          }        }      }    position.v(ego, v40, v41);    }  if (v44 == 30)
    {    position.v(ego, v57, v58);    set(f48);    }  if (v44 == 23)
    {    reset(f47);    set(f48);    v90 = 2;    set.view(ego, View29);    position(ego, 97, 131);    v59 = 1;    v60 = 1;    v61 = 1;    program.control();    stop.motion(ego);    random(5, 15, v220);    }  if (isset(f47))
    {    draw(ego);    }  if (v44 == 23)
    {    set(f47);    }  call(Logic104);  if (isset(f98))
    {    call(Logic105);    }  show.pic();  return();  }if (!isset(haveInput))
  {  goto(Label1);  }if (v44 == 23)
  {  print("Pant, pant, pant, pant, pant!!");  set(haveMatch);  }if ((said("examine", "area") ||     said("examine", "building") ||     said("examine") ||     said("examine", "hall")))
  {  print("This is the main entry room of the wizard's house. The front door is "        "to the south, creaky stairs go upstairs, and doorways lead north and "        "east.");  }if (said("examine", "stair"))
  {  print("The stairway leading upward has wide steps. Several of them are very "        "creaky, though. You always try to avoid them when going up or down "        "these stairs.");  }if (said("examine", "door"))
  {  print("The three doors lead outside, to the north, and to the east.");  }if ((said("lift", "anyword", "door") ||     said("lift", "door") ||     said("lift", "door", "area") ||     said("lift", "anyword", "door", "area")))
  {  if (posn(ego, 86, 163, 109, 167))
    {    print("You open the front door of the house and go outside.");    new.room(Logic34);    }  else
    {    print("You can't reach the door from there!");    }  }if ((said("close", "anyword", "door") ||     said("close", "door") ||     said("close", "door", "area") ||     said("close", "anyword", "door", "area")))
  {  print("The front door is already closed.");  }if ((said("examine", "burn") ||     said("examine", "cage") ||     said("examine", "burn", "on", "cage") ||     said("examine", "burn", "cage")))
  {  print("There are two candles attached to the wall to light your way up the "        "dim staircase.");  }if ((said("capture", "burn") ||     said("capture", "burn", "off", "cage") ||     said("capture", "burn", "from", "cage") ||     said("capture", "burn", "cage")))
  {  print("The candles are firmly attached to the wall. Try as you might, you "        "cannot get them free.");  }Label1:if (isset(onWater))
  {  if ((egoDir == UP ||       egoDir == UP_LEFT ||       egoDir == UP_RIGHT))
    {    reset(f221);    }  if ((egoDir == DOWN ||       egoDir == DOWN_LEFT ||       egoDir == DOWN_RIGHT))
    {    set(f221);    }  }if (isset(f221))
  {  ignore.blocks(ego);  set.priority(ego, 13);  }else
  {  release.priority(ego);  observe.blocks(ego);  }if (isset(f221) &&     isset(egoHitSpecial) &&     posn(ego, 45, 87, 62, 107))
  {  egoDir = STOPPED;  start.motion(ego);  reposition.to.v(ego, v42, v43);  }if (isset(f45))
  {  --v220;  if (v220 == 1)
    {    random(5, 15, v220);    random(0, 3, v36);    set.loop.v(ego, v36);    }  }if (v44 == 23)
  {  if (isset(f33))
    {    set(f222);    set(f46);    program.control();    accept.input();    stop.motion(ego);    set(f35);    reset(f221);    print("Boy, do you hate these little sessions. But, \"No pain, no magic.\"");    v122 = animationInterval;    animationInterval = 0;    v36 = 5;    cycle.time(o1, v36);    cycle.time(o2, v36);    }  if (isset(f123))
    {    reset(f123);    reset(f46);    v44 = 0;    accept.input();    player.control();    start.motion(ego);    reset(f35);    set.view(ego, View0);    v220 = 0;    stop.sound();    reset(f222);    animationInterval = v122;    v36 = 1;    cycle.time(o1, v36);    cycle.time(o2, v36);    print("Whew!");    }  if (isset(f222))
    {    sound(Sound36, f222);    }  }if (v44 != 125)
  {  if (posn(ego, 93, 116, 110, 118))
    {    new.room(Logic5);    }  if (posn(ego, 131, 134, 140, 144))
    {    new.room(Logic8);    }  if (posn(ego, 93, 42, 109, 44))
    {    new.room(Logic3);    }  if (edgeEgoHit == BOTTOM_EDGE &&       v44 != 27 &&       v44 != 25)
    {    print("You open the front door of the house and go outside.");    new.room(Logic34);    }  }call(Logic104);if (isset(f98))
  {  call(Logic105);  }return();[ Messages#message 1 "This is the main entry room of the wizard's house. The front door is to the south, creaky stairs go upstairs, and doorways lead north and east."#message 2 "Pant, pant, pant, pant, pant!!"#message 3 "Boy, do you hate these little sessions. But, \"No pain, no magic.\""#message 4 "The stairway leading upward has wide steps. Several of them are very creaky, though. You always try to avoid them when going up or down these stairs."#message 5 "The three doors lead outside, to the north, and to the east."#message 6 "You open the front door of the house and go outside."#message 7 "You can't reach the door from there!"#message 8 "The front door is already closed."#message 9 "Whew!"#message 10 "There are two candles attached to the wall to light your way up the dim staircase."#message 11 "The candles are firmly attached to the wall. Try as you might, you cannot get them free."