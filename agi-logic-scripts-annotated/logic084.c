// front end of ship's basement

if (isset(newRoom))
{  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  set(f34);  v56 = 7;  v57 = 17;  v58 = 147;  v32 = 0;  v31 = 0;  load.sound(Sound1);  load.sound(Sound26);  load.sound(Sound3);  if (isset(f186) || obj.in.room("Shovel", currentRoom))
  {    load.logics(Logic108);  }  load.logics(Logic116);
  if (obj.in.room("Shovel", currentRoom))
  {    animate.obj(o12);    load.view(View169);    set.view(o12, View169);    stop.cycling(o12);    ignore.blocks(o12);    position(o12, 9, 131);    draw(o12);    stop.update(o12);  }  load.view(View0);  load.view(View11);  load.view(View24);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);
  if (v44 == 14)
  {    v41 = v58;  }  if (isset(f48))
  {    if (v44 == 0)
    {      get.posn(ego, v40, v41);      if (previousRoom == 84)
      {        if (v41 > 128)
        {          v41 = 150;        }        else
        {          v41 = 114;        }        position.v(ego, v40, v41);      }    }    if (v44 == 6)
    {      set(f46);      set.priority(ego, 13);      ignore.blocks(ego);      ignore.objs(ego);      position(ego, 52, 75);      move.obj(ego, 52, 155, 3, f222);      sound(Sound1, f238);    }  }  if (v44 == 30)
  {    set.view(ego, View0);    set(f48);    position.v(ego, v57, v58);    set(f47);  }  if (isset(f47))
  {    draw(ego);  }  animate.obj(o1);
  if (isset(f181))
  {    set(f220);    v223 = 22;    load.view(View166);    set.view(o1, View166);    set.priority(o1, 14);    set.loop(o1, 0);    v36 = 6;    cycle.time(o1, v36);    position(o1, 95, 133);    draw(o1);  }  else
  {    set(f81);    if (v62 != 4)
    {      load.view(View157); // captain or sailor walking      set.view(o1, View157);      random(1, 4, v36);      if (v36 > 2 && !isset(f46))
      {        set(f220);        set(f224);        v37 = 50;        position.v(o1, v37, v41);        draw(o1);      }      if (v36 == 2 && !isset(f46))
      {        set(f227);        stop.cycling(o1);        position(o1, 78, 127);      }    }  }  show.pic();  return();}

if (v40 > 88)
{  v220 = 2;}else
{  v220 = 1;}
call(Logic116);--v223;if (v223 == 1)
{  sound(Sound3, f238);  set.cel(o1, 0);  end.of.loop(o1, f221);}
if (isset(f221))
{  reset(f221);  v223 = 22;  set.cel(o1, 0);  stop.cycling(o1);}distance(ego, o1, v36);
if (!isset(f46) && isset(f227) && v36 < 50)
{  reset(f227);  set(f220);  set(f224);  draw(o1);  start.cycling(o1);}
if (isset(f224))
{  reset(f224);  set(f225);  print("Oh no! One of the crew has spotted you! You'd better run.");  sound(Sound26, f238);}
if (isset(f225))
{  if (isset(f33))
  {    if (v44 == 25)
    {      print("Your magical transformation has frozen the pirate in his tracks.");      stop.cycling(o1);      normal.motion(o1);      stop.motion(o1);      reset(f226);    }    else
    {      reset(f223);    }  }  if (!isset(f223) && !isset(f46))
  {    set(f223);    start.cycling(o1);    follow.ego(o1, 8, f226);  }}
if (isset(f226))
{  reset(f226);  stop.cycling(o1);  reset(f223);  if (!isset(f46))
  {    print("The pirate growls, \"What ar' ya doin' snoopin' around me digs, "      "laddie. I gotcha' now, boy!");    set(f199);    new.room(Logic85);  }}
if (isset(f222))
{  reset(f222);  set.view(ego, View24);  reposition.to(ego, 52, 143);  program.control();  set(f44);}
if ((isset(f186) ||  obj.in.room("Shovel", currentRoom)))
{  call(Logic108);}if (said("examine", "bandit"))
{  if (isset(f220))
  {    if (isset(f181))
    {      if (v220 == 2)
      {        print("A pirate is fast asleep in his bunk.");      }      else
      {        print("You can't see it from here.");      }    }    else
    {      print("You'd better leave before the pirate catches you.");    }  }  else
  {    print("You don't see anyone else in the area.");  }}if ((said("examine") ||  said("examine", "area")))
{  if (v220 == 2)
  {    print("This is where your average pirate sleeps. Actually, these bunks "      "don't look much more comfortable than your own miserable cot used to "      "be and the space is just as cramped.");  }  else
  {    if (!obj.in.room("Shovel", currentRoom))
    {      print("You have found yourself below the lower deck. They keep the ship's "        "lifeboat stored here. There are open doorways at either end of the "        "compartment.");    }    else
    {      print("%m2 There is a shovel lying by the lifeboat.");    }  }}if ((said("examine", "below") ||  said("look in", "boat") ||  said("examine", "boat")))
{  if (v220 == 2)
  {    print("You can't see it from here.");  }  else
  {    if (!obj.in.room("Shovel", currentRoom))
    {      print("You scrutinize the boat inside and out, but find it to be empty "        "and uninteresting.");    }    else
    {      print("%m3 There is a shovel lying by the lifeboat.");    }  }}if ((said("look in", "door") ||  said("examine", "out", "door") ||  said("examine", "door")))
{  if (v220 == 2)
  {    print("You stare out the open doorway and see the wooden lifeboat.");  }  else
  {    print("You peer through the doorway and see rows of bunks. It must be the "      "crew's quarters.");  }}if ((said("look in", "bed") ||  said("examine", "on", "bed") ||  said("examine", "bed")))
{  if (v220 == 2)
  {    print("Rows of hard bunks line the walls of the crew's quarters. They don't "      "look very inviting to lie upon. You can't imagine the pirates would "      "get a good night's sleep down here in the cramped bow of the ship.");  }  else
  {    print("You can't see it from here.");  }}if ((said("lay", "on", "bed") ||  said("capture", "on", "bed") ||  said("sleep", "on", "bed") ||  said("lay", "bed")))
{  if (v220 == 2)
  {    print("The beds look incredibly hard and uncomfortable. No, thank you.");  }  else
  {    print("You can't see it from here.");  }}if (edgeEgoHit == LEFT_EDGE)
{  new.room(Logic83);}return();[Messages#message 1 "This is where your average pirate sleeps. Actually, these bunks don't look much more comfortable than your own miserable cot used to be and the space is just as cramped."#message 2 "You have found yourself below the lower deck. They keep the ship's lifeboat stored here. There are open doorways at either end of the compartment."#message 3 "You scrutinize the boat inside and out, but find it to be empty and uninteresting."#message 4 "Rows of hard bunks line the walls of the crew's quarters. They don't look very inviting to lie upon. You can't imagine the pirates would get a good night's sleep down here in the cramped bow of the ship."#message 5 "The beds look incredibly hard and uncomfortable. No, thank you."#message 6 "You already have the shovel."#message 7 "The pirate growls, \"What ar' ya doin' snoopin' around me digs, laddie. I gotcha' now, boy!"#message 8 "You can't see it from here."#message 9 "You'd better leave before the pirate catches you."#message 10 "You don't see anyone else in the area."#message 11 "A pirate is fast asleep in his bunk."#message 12 "You stare out the open doorway and see the wooden lifeboat."#message 13 "You peer through the doorway and see rows of bunks. It must be the crew's quarters."#message 14 "Oh no! One of the crew has spotted you! You'd better run."#message 15 "%m2 There is a shovel lying by the lifeboat."#message 16 "%m3 There is a shovel lying by the lifeboat."#message 17 "Poofing in."#message 18 "Your magical transformation has frozen the pirate in his tracks."





