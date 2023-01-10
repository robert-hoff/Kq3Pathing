if (isset(newRoom))
  {  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  v57 = 14;  v58 = 123;  v56 = 5;  load.view(View35);  load.view(View11);  load.view(View0);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.sound(Sound1);  load.sound(Sound6);  if (isset(f48))
    {    get.posn(ego, v40, v41);    if (previousRoom == 59)
      {      position(ego, 103, 40);      }    if (previousRoom == 62)
      {      position(ego, 108, 79);      }    if (previousRoom == 68)
      {      v40 = 2;      position.v(ego, v40, v41);      }    }  if (isset(f47))
    {    draw(ego);    }  if (isset(f182))
    {    load.logics(Logic119);    call(Logic119);    }  show.pic();  if (!isset(f53))
    {    set(f53);    v36 = 73;Label1:    if (v36 > 53)
      {      reset.v(v36);      --v36;      goto(Label1);      }    }  return();  }if (!isset(f46) &&     isset(egoHitSpecial) &&     !isset(f221))
  {  set(f46);  v44 = 6;  sound(Sound1, f238);  set(f221);  ignore.blocks(ego);  ignore.objs(ego);  get.priority(ego, v36);  set.priority.v(ego, v36);  set.view(ego, View11);  if (posn(ego, 86, 32, 120, 71))
    {    v220 = 1;    v38 = 94;    v37 = 101;    v36 = 3;    set.priority(ego, 15);    }  else
    {    v220 = 2;    v37 = v40;    v38 = 164;    v36 = 4;    }  move.obj.v(ego, v37, v38, v36, f220);  }if (isset(f220))
  {  stop.sound();  reset(f220);  reset(f221);  reset(f46);  if (v220 == 2)
    {    erase(ego);    set(f44);    print("You successfully fall for twenty meters before you hit the bottom. "          "You get a 4.1 from the Russian judge.");    }  else
    {    print("Whoops, you slipped!");    program.control();    v44 = 18;    sound(Sound6, f238);    v221 = 5;    set.view(ego, View35);    set(f35);    set.scan.start();    if (isset(f45))
      {      --v221;      }    if (v221 <= 0)
      {      reset(f35);      player.control();      set.view(ego, View0);      observe.blocks(ego);      observe.objs(ego);      release.priority(ego);      release.loop(ego);      v44 = 0;      v36 = 1;      cycle.time(ego, v36);      reset.scan.start();      }    if (v221 > 0 &&         isset(f238))
      {      sound(Sound6, f238);      }    return();    }  }if (isset(f182))
  {  call(Logic119);  }if ((said("examine", "area") ||     said("examine", "bluff") ||     said("examine")))
  {  print("You look upward and view the mountain range you so arduously crossed. "        "Well, you made it to Daventry! But, what is this? It looks like a cave "        "leading deep into the mountain. You see evidence that a door once "        "covered this cave entrance. Huge boulders lie scattered about, "        "apparently from tumbling down the mountain.");  }if ((said("look in", "cave") ||     said("examine", "cave")))
  {  print("You gaze into the cave-like entrance. You see nothing but crumbly "        "stone steps leading upward.");  }if ((said("look in", "canyon") ||     said("examine", "canyon") ||     said("examine", "above", "canyon")))
  {  print("A deep chasm has split the earth on this side of the mountain. You "        "wonder if an earthquake had once struck Daventry and caused the "        "destruction you see before you. You see nothing of interest across it.");  }if ((said("jump", "above", "canyon") ||     said("climb", "canyon") ||     said("climb", "down", "canyon") ||     said("jump", "down", "canyon") ||     said("board", "above", "canyon") ||     said("jump", "canyon")))
  {  print("The chasm is much too wide to jump across, and too treacherous to "        "climb.");  }if ((said("examine", "brush") ||     said("examine", "forest")))
  {  print("A once green woodland spreads out before you. Now though, many trees "        "and bushes have been cruelly charred.");  }if (said("examine", "deck"))
  {  print("The ground is strewn with large boulders. A deep chasm cuts into it.");  }if (said("examine", "sky"))
  {  print("You see a mysterious cloud cover straight above you in the sky.");  }if ((said("examine", "flower") ||     said("capture", "flower")))
  {  print("You see no flowers about.");  }if (said("examine", "stair"))
  {  print("The stone steps within the cave entrance look mighty crumbly. "        "Curiously, they lead straight up into the mountain!");  }if (said("climb", "forest"))
  {  print("There are no climbable trees around.");  }if ((said("jump", "above", "canyon") ||     said("climb", "down") ||     said("jump", "canyon")))
  {  print("The chasm is much too wide to jump across, and too treacherous to "        "climb.");  }if (v44 == 0 &&     obj.in.box(ego, 118, 59, 133, 68))
  {  new.room(Logic62);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic68);  }return();[ Messages#message 1 "You look upward and view the mountain range you so arduously crossed. Well, you made it to Daventry! But, what is this? It looks like a cave leading deep into the mountain. You see evidence that a door once covered this cave entrance. Huge boulders lie scattered about, apparently from tumbling down the mountain."#message 2 "You gaze into the cave-like entrance. You see nothing but crumbly stone steps leading upward."#message 3 "A deep chasm has split the earth on this side of the mountain. You wonder if an earthquake had once struck Daventry and caused the destruction you see before you. You see nothing of interest across it."#message 4 "A once green woodland spreads out before you. Now though, many trees and bushes have been cruelly charred."#message 5 "The ground is strewn with large boulders. A deep chasm cuts into it."#message 6 "You see a mysterious cloud cover straight above you in the sky."#message 7 "You see no flowers about."#message 8 "The stone steps within the cave entrance look mighty crumbly. Curiously, they lead straight up into the mountain!"#message 9 "There are no climbable trees around."#message 10 "You successfully fall for twenty meters before you hit the bottom. You get a 4.1 from the Russian judge."#message 11 "Whoops, you slipped!"#message 12 "The chasm is much too wide to jump across, and too treacherous to climb."