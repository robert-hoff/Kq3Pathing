if (isset(newRoom))
  {  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  v32 = 58;  v31 = 115;  v57 = 68;  v58 = 122;  set(f34);  load.sound(Sound3);  load.sound(Sound1);  load.view(View18);  load.view(View0);  load.view(View12);  load.view(View11);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  if (isset(f48))
    {    position(ego, 51, 116);    set.loop(ego, 3);    }  if (v44 == 30)
    {    set.view(ego, View0);    set(f48);    position.v(ego, v57, v58);    set(f47);    }  if (isset(f47))
    {    draw(ego);    }  animate.obj(o2);  load.view(View182);  set.view(o2, View182);  position(o2, 96, 96);  set.loop(o2, 0);  set.cel(o2, 0);  v36 = 2;  cycle.time(o2, v36);  draw(o2);  stop.update(o2);  animate.obj(o1);  load.view(View80);  set.view(o1, View80);  position(o1, 49, 116);  set.loop(o1, 0);  set.cel(o1, 0);  show.pic();  return();  }if (v44 == 0)
  {  v39 = 0;  if (posn(ego, 94, 109, 101, 110))
    {    set(f225);    }  else
    {    reset(f225);    }  if (posn(ego, 86, 129, 124, 165))
    {    v39 = 1;    }  if (posn(ego, 34, 143, 54, 165))
    {    v39 = 2;    }  if (posn(ego, 85, 108, 111, 128))
    {    v39 = 3;    }  }if (isset(f45) &&     v225 > 0)
  {  --v225;  }if (v44 == 17)
  {  if (isset(haveInput))
    {    print("Shhhh! You'll wake yourself up.");    }  }if (v44 == 7)
  {  if (isset(haveInput) &&       (said("wake", "up") ||       said("board", "bed") ||       said("capture", "up", "bed") ||       said("capture", "up", "from", "bed") ||       said("capture", "up")))
    {    print("Good idea. You've got too much to do to be lying around in a strange "          "bed.");    v225 = 2;    v39 = 1;    }  }if (v44 == 0 &&     (said("board", "bed") ||     said("lay", "on", "bed") ||     said("lay", "bed") ||     said("try", "out", "bed") ||     said("board", "sleep") ||     said("sleep", "on", "bed") ||     said("sleep", "bed") ||     said("get in", "bed") ||     said("capture", "on", "bed")))
  {  if (v39 == 0)
    {    print("You need to move closer.");    }  else
    {    set(f46);    get.posn(ego, v226, v227);    set.view(ego, View12);    set.cel(ego, 0);    set.priority(ego, 15);    v44 = 7;    start.motion(ego);    program.control();    if (v39 == 1)
      {      reposition.to(ego, 100, 132);      print("You flop onto the biggest (and hardest) bed!");      set.cel(ego, 2);      set.loop(ego, 0);      v225 = 10;      }    if (v39 == 2)
      {      reposition.to(ego, 32, 143);      print("You jump onto the medium-sized bed and sink deep into its fluffy "            "depths.");      set.loop(ego, 1);      v225 = 10;      }    if (v39 == 3)
      {      reposition.to(ego, 87, 107);      print("You lie upon the smallest bed, and snuggle down into the pillow.");      set.loop(ego, 0);      v225 = 10;      }    }  }if (isset(f45) &&     v44 == 7)
  {  if (v225 == 5)
    {    if (v39 == 1)
      {      print("This bed is MUCH too hard!");      }    if (v39 == 2)
      {      print("This bed is MUCH too soft!");      }    if (v39 == 3)
      {      v36 = 3;      cycle.time(ego, v36);      print("Ahhhh! This bed is just right. You've fallen asleep.");      v230 = 2;      prevent.input();      }    }  if (v225 == 1)
    {    if ((v39 == 1 ||         v39 == 2))
      {      set.view(ego, View0);      reposition.to.v(ego, v226, v227);      release.priority(ego);      v44 = 0;      reset(f46);      player.control();      reset(f35);      }    else
      {      v44 = 17;      v220 = 0;      v228 = 10;      }    }  }--v230;if (v230 == 1)
  {  sound(Sound3, f238);  set(f35);  set.cel(ego, 0);  end.of.loop(ego, f221);  }if (isset(f221))
  {  reset(f221);  v230 = 22;  reset(f35);  }if (isset(f45) &&     v228 > 0)
  {  --v228;  if (v228 == 0)
    {    set(f220);    }  }if (isset(f220))
  {  program.control();  prevent.input();  }if (isset(f220) &&     v220 == 0)
  {  reset(f220);  set(f46);  ++v220;  draw(o1);  move.obj(o1, 55, 110, 1, f220);  }if (isset(f220) &&     v220 == 1)
  {  reset(f220);  ++v220;  move.obj(o1, 95, 110, 1, f220);  }if (isset(f220) &&     v220 == 2)
  {  reset(f220);  ++v220;  set.loop(o1, 2);  v228 = 1;  }if (isset(f220) &&     v220 == 3)
  {  reset(f220);  ++v220;  print.at("Oh No! Papa Bear has found you sleeping in Baby Bear's bed! You are "           "in for it now!", 2, 2, 37);  ignore.blocks(ego);  ignore.objs(ego);  set.view(ego, View18);  reset(f35);  v230 = 0;  move.obj(o1, 55, 110, 1, f220);  v44 = 0;  }if (v220 == 4)
  {  get.posn(o1, v37, v38);  v37 -= 7;  v38  += 1;  reposition.to.v(ego, v37, v38);  get.priority(o1, v36);  set.priority.v(ego, v36);  }if (isset(f220) &&     v220 == 4)
  {  reset(f220);  ++v220;  set.loop(o1, 2);  stop.cycling(o1);  set.view(ego, View11);  sound(Sound1, f238);  set.priority(ego, 6);  v36 = 1;  cycle.time(ego, v36);  move.obj(ego, 48, 167, 4, f220);  }if (isset(f220) &&     v220 == 5)
  {  player.control();  ++v220;  reset(f220);  v44 = 0;  reset(f46);  player.control();  accept.input();  new.room(Logic28);  }--v224;if (v224 == 1)
  {  stop.update(o2);  if (v223 == 1)
    {    if (obj.in.room("Thimble*", currentRoom))
      {      print("You open the drawer, and among the clothes, you see a pretty "            "silver thimble.");      }    else
      {      print("You open the drawer and see some bear-sized clothes.");      }    }  }if (isset(haveInput))
  {  if (said("examine", "bed"))
    {    if (v39 == 0)
      {      print("You are in the Bear family's cozy bedroom. You see three beds and "            "a chest of drawers.");      }    if (v39 == 1)
      {      print("This is a big, old bed. It must be Papa Bear's.");      }    if (v39 == 2)
      {      print("This looks like a nice, soft bed. Maybe it's Mama Bear's.");      }    if (v39 == 3)
      {      print("This bed looks just the right size for you.");      }    }  if ((said("lift", "drawer") ||       said("lift", "chest") ||       said("lift", "bureau", "drawer")))
    {    if (isset(f225))
      {      if (v223 == 1)
        {        print("It is already open.");        }      else
        {        start.update(o2);        end.of.loop(o2, f224);        v223 = 1;        v224 = 30;        }      }    else
      {      print("You need to move closer.");      }    }  if ((said("close", "drawer") ||       said("close", "chest") ||       said("close", "bureau", "drawer")))
    {    if (isset(f225))
      {      if (v223 == 0)
        {        print("The drawer is already closed.");        }      else
        {        start.update(o2);        reverse.loop(o2, f224);        v223 = 0;        v224 = 30;        }      }    else
      {      print("A dresser sits in the corner of the room.");      }    }  if (said("examine", "below", "bed"))
    {    if (v39 == 0)
      {      print("You need to move closer.");      }    else
      {      print("There is nothing of interest under the bed.");      }    }  if (said("capture", "thimble"))
    {    if (!obj.in.room("Thimble*", currentRoom))
      {      print("You have already taken it!");      }    else
      {      if (!isset(f225))
        {        print("You need to move closer.");        }      else
        {        if (v223 == 0)
          {          print("You open the drawer, take the thimble, and close the drawer in "                "one fluid movement.");          }        else
          {          print("You pick up the thimble and carry it with you.");          }        get("Thimble*");        currentScore  += 1;        }      }    }  if (said("capture", "clothes"))
    {    print("They wouldn't fit you.");    }  if ((said("look in", "drawer") ||       said("examine", "drawer")))
    {    if (isset(f225))
      {      if (v223 == 0)
        {        print("The drawers are shut.");        }      else
        {        if (!obj.in.room("Thimble*", currentRoom))
          {          print("You see a few bear-sized clothes.");          }        else
          {          print("You see a few bear-sized clothes and a silver thimble.");          }        }      }    else
      {      print("You need to move closer.");      }    }  if ((said("examine") ||       said("examine", "area") ||       said("examine", "bedroom") ||       said("examine", "building")))
    {    print("You are in the Bear family's cozy bedroom. You see three beds and a "          "chest of drawers.");    }  if ((said("examine", "chest") ||       said("examine", "bureau")))
    {    print("A dresser sits in the corner of the room.");    }  }if (isset(egoHitSpecial) &&     v44 == 0)
  {  new.room(Logic41);  }return();[ Messages#message 1 "You jump onto the medium-sized bed and sink deep into its fluffy depths."#message 2 "You flop onto the biggest (and hardest) bed!"#message 3 "You lie upon the smallest bed, and snuggle down into the pillow."#message 4 "There is nothing of interest under the bed."#message 5 "You open the drawer, take the thimble, and close the drawer in one fluid movement."#message 6 ""#message 7 "You open the drawer, and among the clothes, you see a pretty silver thimble."#message 8 "You pick up the thimble and carry it with you."#message 9 "The drawer is already closed."#message 10 "You see a few bear-sized clothes and a silver thimble."#message 11 "You see a few bear-sized clothes."#message 12 "It is already open."#message 13 "You have already taken it!"#message 14 "You open the drawer and see some bear-sized clothes."#message 15 "You are in the Bear family's cozy bedroom. You see three beds and a chest of drawers."#message 16 "A dresser sits in the corner of the room."#message 17 "You need to move closer."#message 18 "This bed is MUCH too hard!"#message 19 "Shhhh! You'll wake yourself up."#message 20 "Oh No! Papa Bear has found you sleeping in Baby Bear's bed! You are in for it now!"#message 21 "The drawers are shut."#message 22 "Ahhhh! This bed is just right. You've fallen asleep."#message 23 "Good idea. You've got too much to do to be lying around in a strange bed."#message 24 "I'm not asleep, are you?"#message 25 "This bed is MUCH too soft!"#message 26 "They wouldn't fit you."#message 27 "This is a big, old bed. It must be Papa Bear's."#message 28 "This looks like a nice, soft bed. Maybe it's Mama Bear's."#message 29 "This bed looks just the right size for you."