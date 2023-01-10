if (isset(newRoom))
{  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.sound(Sound6);  load.sound(Sound1);  load.sound(Sound26);  load.sound(Sound3);  load.logics(Logic116);  call(Logic116);  set(f34);  v57 = 127;  v58 = 115;  v32 = 130;  v31 = 138;  v56 = 7;  animate.obj(o3);  load.view(View160);  set.view(o3, View160);  ignore.blocks(o3);  position(o3, 38, 165);  stop.cycling(o3);  if (isset(f188))
  {    set.cel(o3, 3);  }  else
  {    set.cel(o3, 0);  }  draw(o3);  stop.update(o3);  if (v62 != 4)
  {    animate.obj(o4);    if (isset(f181))
    {      v227 = 22;      load.view(View166); // captain sleeping      set.view(o4, View166);      v36 = 6;      cycle.time(o4, v36);      position(o4, 68, 148);      set.priority(o4, 14);      set.loop(o4, 0);    }    else
    {      load.view(View167);      load.view(View159);      set.view(o4, View159);      ignore.blocks(o4);      random(1, 3, v36);      if (previousRoom == 82)
      {        v36 = 1;      }      if (isset(f46))
      {        v36 = 1;      }      if (v36 == 3)
      {        v226 = 3;        set.view(o4, View167);        position(o4, 69, 117);        v222 = 66;      }      else
      {        random(10, 40, v221);        position(o4, 12, 129);        v226 = 0;        if (v36 == 1)
        {          v221 = 0;        }      }    }    draw(o4);    if (v226 == 0)
    {      stop.update(o4);    }  }  load.view(View0);  load.view(View11);  load.view(View30);  load.view(View35);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  if (v44 == 15)
  {    v44 = 15;    ignore.horizon(ego);    ignore.blocks(ego);    if (previousRoom == 80)
    {      position(ego, 145, 55);    }    else
    {      position(ego, 142, 133);    }    set.priority(ego, 11);    set.view(ego, View30);    set.loop(ego, 0);    fix.loop(ego);  }  else
  {    set.view(ego, View0);    get.posn(ego, v40, v41);    if (previousRoom == 84)
    {      if (v41 > 134)
      {        v41 = 137;      }      else
      {        v41 = 110;      }      position.v(ego, v40, v41);    }    if (previousRoom == 82)
    {      position(ego, 28, 125);    }    if (previousRoom == 80)
    {      position(ego, 120, 55);      set.view(ego, View11);    }  }  if (v44 == 30)
  {    set.view(ego, View0);    position.v(ego, v57, v58);    set(f48);    set(f47);  }  if (isset(f47))
  {    draw(ego);  }  show.pic();  return();}call(Logic116);--v227;if (v227 == 1)
{  sound(Sound3, f238);  set.cel(o4, 0);  end.of.loop(o4, f227);}if (isset(f227))
{  reset(f227);  v227 = 22;  stop.cycling(o4);}if (v40 > 90)
{  v220 = 1;}else
{  v220 = 0;}if (v221 > 0 &&  isset(f45))
{  --v221;  if (v221 == 0)
  {    set(f225);  }}get.posn(o4, v37, v38);if (v226 == 1)
{  if (v37 > 32)
  {    set(f226);  }  else
  {    reset(f226);  }}else
{  if ((v226 == 2 ||    v226 == 3))
  {    set(f226);  }  else
  {    reset(f226);  }}if (v220 == 0 &&  v44 == 0 &&  isset(f226))
{  v226 = 4;  set(f225);  print("The Captain doesn't want you snooping in his quarters. You're in "    "trouble now!");  prevent.input();}if (!isset(f46) &&  v226 == 0 &&  isset(f225))
{  reset(f225);  v226 = 1;  start.update(o4);  move.obj(o4, 40, 129, 1, f225);  sound(Sound26, f238);}if (v226 == 1 &&  isset(f225))
{  reset(f225);  v226 = 2;  move.obj(o4, 69, 117, 1, f225);}if (v226 == 2 &&  isset(f225))
{  reset(f225);  v226 = 3;  set.view(o4, View167);  reposition.to(o4, 69, 117);  v222 = 66;}if (v226 == 3)
{  --v222;  if (v222 == 21)
  {    start.cycling(o4);  }  if (v222 == 1)
  {    v222 = 66;    stop.cycling(o4);  }}if (v226 == 4 &&  isset(f225))
{  reset(f225);  v226 = 5;  stop.motion(ego);  set.view(o4, View159);  program.control();  start.cycling(o4);  follow.ego(o4, 10, f225);}if (v226 == 5 &&  isset(f225))
{  ++v226;  reset(f225);  set(f199);  if (v187 == 1)
  {    print("\"Yer more trouble than yer worth!\" the Captain thunders. \"'Tis "      "the plank fer ya now!\"");  }  else
  {    print("\"I'll not tolerate ya snoopin' around me quarters!\" the Captain "      "thunders. \"If I ketch ya in here again ya'll walk the plank!\"");  }  player.control();  accept.input();  new.room(Logic85);}if (v44 == 6)
{  v37 = 6;  v38 = 124;}else
{  if (v44 == 15 &&    !obj.in.box(ego, 140, 33, 153, 166))
  {    v44 = 6;    v37 = 3;    v38 = 144;  }  else
  {    if (v44 == 0 &&      isset(egoHitSpecial))
    {      v44 = 6;      sound(Sound1, f238);      set.view(ego, View11);      reposition.to(ego, 130, 125);      set(f35);      set.priority(ego, 10);      move.obj(ego, 130, 165, 3, f220);      set.scan.start();      if (isset(f220))
      {        reset.scan.start();        new.room(Logic85);      }      return();    }    if (obj.in.box(ego, 140, 125, 153, 133))
    {      if (v44 == 15)
      {        if (egoDir != UP &&          egoDir != DOWN &&          egoDir != STOPPED)
        {          v44 = 0;          release.loop(ego);          observe.blocks(ego);          observe.horizon(ego);          release.priority(ego);          set.view(ego, View0);          reposition.to(ego, 141, 134);          start.motion(ego);        }      }      else
      {        start.motion(ego);        reposition.to(ego, 142, 133);        ignore.horizon(ego);        ignore.blocks(ego);        set.priority(ego, 11);        set.view(ego, View30);        v44 = 15;        set.loop(ego, 0);        fix.loop(ego);      }    }    if ((said("examine", "area") ||      said("examine")))
    {      if (v220 == 0)
      {        print("This must be the Captain's cabin. He seems to be a bit more tidy "          "than his mates, as the room is clean and orderly. Against one "          "wall rests his bunk with a large chest at its foot. Across the "          "room is his desk with a chart tacked to the wall.");      }      if (v220 == 1)
      {        print("You look curiously around. Out a porthole you see the swell of "          "the ocean. A device for turning the ship's rudder sets in the "          "floor. A rope ladder extends up through an opening in the "          "ceiling.");      }    }    if ((said("look in", "carry") ||      said("examine", "carry")))
    {      if (v220 == 1)
      {        print("You peer into the dark opening. It's impossible to make out any "          "details.");      }      else
      {        print("You can't see that very well from here.");      }    }    if (said("examine", "below", "bed"))
    {      print("You see nothing you haven't seen before.");    }    if (said("examine", "bed"))
    {      if (v220 == 0)
      {        if (isset(f181) && v62 != 4)
        {          print("The captain is snoring peacefully in his bunk.");        }        else
        {          print("The Captain's bunk has been very neatly made. You look it over "            "carefully, but find nothing of interest.");        }      }      else
      {        print("You can't see that very well from here.");      }    }    if ((said("examine", "bandit", "on", "bed") ||      said("examine", "bandit", "bed") ||      said("examine", "bandit")))
    {      if (v220 == 0)
      {        print("The captain is snoring peacefully in his bunk.");      }      else
      {        print("You can't see anything from here.");      }    }    if (said("examine", "ladder"))
    {      if (v220 == 1)
      {        print("The rope ladder is still there.");      }      else
      {        print("You can't see that very well from here.");      }    }    if ((said("examine", "out", "hole") ||      said("examine", "hole")))
    {      if (v220 == 1)
      {        print("You see the rise and fall of the ocean as you gaze out the "          "porthole.");      }      else
      {        print("You can't see that very well from here.");      }    }    if (isset(f188))
    {      stop.update(o3);    }    if ((said("examine", "chest") ||      said("capture", "all", "rol") ||      said("look in", "chest")))
    {      if (v220 == 1)
      {        print("You can't see that very well from here.");      }      else
      {        if (!isset(f188))
        {          print("The chest at the foot of the Captain's bunk is closed.");        }        else
        {          distance(ego, o3, v36);          if (v36 > 18)
          {            print("The open chest bears closer examination.");          }          else
          {            if (isset(f185))
            {              reset(f185);              print("You've found all of your missing possessions! You take "                "them with you.");              if (!isset(f206))
              {                currentScore += 3;                set(f206);              }              v36 = 1;              v224 = 255;            Label1:              if (v36 < 55)
              {                get.room.v(v36, v225);                if (v225 == currentRoom)
                {                  put.v(v36, v224);                }                ++v36;                goto(Label1);              }            }            else
            {              print("You look in the chest and find nothing.");            }          }        }      }    }    if ((said("look in", "counter") ||      said("look in", "drawer") ||      said("examine", "counter")))
    {      if (v220 == 0 &&        posn(ego, 63, 112, 83, 120))
      {        print("You gaze with interest at the Captain's desk. The desk top is "          "very neat, holding only writing implements. Curiously, you open "          "a drawer or two. There is nothing of interest among the charts "          "and logbooks. Quickly, you close them again.");      }      else
      {        print("You can't see that very well from here.");      }    }    if ((said("examine", "chart") ||      said("examine", "chart", "on", "cage")))
    {      if (v220 == 0)
      {        print("You stare at the chart tacked to the wall. It traces the route "          "the ship is now sailing. It leaves Llewdor, crossing a wide "          "ocean, and arriving at the foot of a mountain range. An \"X\" "          "has been marked at the arrival point.");      }      else
      {        print("You can't see that very well from here.");      }    }    if ((said("lift", "up", "chest") ||      said("lift", "cap") ||      said("lift", "cap", "chest") ||      said("lift", "chest")))
    {      if (isset(f188))
      {        print("The chest is already open.");      }      else
      {        distance(ego, o3, v36);        if (v36 > 18)
        {          print("How do you propose to do that from where you're standing?");        }        else
        {          start.update(o3);          set.cel(o3, 0);          end.of.loop(o3, f188);        }      }    }    if ((said("close", "cap") ||      said("close", "cap", "chest") ||      said("close", "chest")))
    {      if (!isset(f188))
      {        print("The chest is already closed.");      }      else
      {        distance(ego, o3, v36);        if (v36 > 18)
        {          print("How do you propose to do that from where you're standing?");        }        else
        {          start.update(o3);          set.cel(o3, 3);          reverse.loop(o3, f188);          set.scan.start();          if (isset(f188))
          {            reset(f188);            stop.update(o3);            reset.scan.start();          }          return();        }      }    }    if ((said("lay", "on", "bed") ||      said("capture", "on", "bed") ||      said("sleep", "on", "bed") ||      said("lay", "on", "bed") ||      said("lay", "bed")))
    {      if (v220 == 0)
      {        print("You really have better things to do than lie around. It would be "          "wise to get out of there.");      }      else
      {        print("How do you propose to do that from where you're standing?");      }    }    if ((said("get in", "on", "bench") ||      said("get in", "bench")))
    {      if (v220 == 0)
      {        print("You really have better things to do than sit around. It would be "          "wise to get out of there.");      }      else
      {        print("How do you propose to do that from where you're standing?");      }    }    if ((said("look in", "door") ||      said("examine", "door")))
    {      if (v220 == 0)
      {        print("Through one doorway, you see the rope ladder snaking its way "          "down into the cargo hold. Out the other, you see nothing but the "          "endless ocean.");      }      else
      {        print("You can't see that very well from here.");      }    }    if ((said("examine", "glass") ||      said("examine", "out", "glass")))
    {      if (v220 == 0)
      {        print("You look out the window and see the bright, blue ocean.");      }      else
      {        print("You can't see that very well from here.");      }    }    if (v44 == 15 &&      v41 < 50)
    {      new.room(Logic80);    }    if (v44 == 15 &&      v41 > 143)
    {      new.room(Logic85);    }    if (obj.in.box(ego, 11, 114, 29, 130))
    {      new.room(Logic82);    }    if (edgeEgoHit == RIGHT_EDGE)
    {      new.room(Logic84);    }    return();  }}set.view(ego, View11);sound(Sound1, f238);ignore.blocks(ego);move.obj.v(ego, v40, v38, v37, f220);set.scan.start();if (isset(f220))
{  release.priority(ego);  reset(f220);  program.control();  v44 = 18;  sound(Sound6, f224);  v223 = 5;  set.view(ego, View35);  set(f35);  set.scan.start();  if (isset(f45))
  {    --v223;  }  program.control();  if (v223 <= 0)
  {    reset(f35);    player.control();    set.view(ego, View0);    observe.blocks(ego);    release.priority(ego);    release.loop(ego);    v44 = 0;    reset.scan.start();  }  if (v223 > 0 &&    isset(f224))
  {    sound(Sound6, f224);  }  return();}return();[Messages#message 1 "You can't see that very well from here."#message 2 "This must be the Captain's cabin. He seems to be a bit more tidy than his mates, as the room is clean and orderly. Against one wall rests his bunk with a large chest at its foot. Across the room is his desk with a chart tacked to the wall."#message 3 "You look curiously around. Out a porthole you see the swell of the ocean. A device for turning the ship's rudder sets in the floor. A rope ladder extends up through an opening in the ceiling."#message 4 "You peer into the dark opening. It's impossible to make out any details."#message 5 "You can't see anything from here."#message 6 "The Captain's bunk has been very neatly made. You look it over carefully, but find nothing of interest."#message 7 "The rope ladder is still there."#message 8 "You see the rise and fall of the ocean as you gaze out the porthole."#message 9 "The chest at the foot of the Captain's bunk is closed."#message 10 "How do you propose to do that from where you're standing?"#message 11 "You gaze with interest at the Captain's desk. The desk top is very neat, holding only writing implements. Curiously, you open a drawer or two. There is nothing of interest among the charts and logbooks. Quickly, you close them again."#message 12 "You stare at the chart tacked to the wall. It traces the route the ship is now sailing. It leaves Llewdor, crossing a wide ocean, and arriving at the foot of a mountain range. An \"X\" has been marked at the arrival point."#message 13 "You really have better things to do than lie around. It would be wise to get out of there."#message 14 "You really have better things to do than sit around. It would be wise to get out of there."#message 15 "Through one doorway, you see the rope ladder snaking its way down into the cargo hold. Out the other, you see nothing but the endless ocean."#message 16 "The Captain doesn't want you snooping in his quarters. You're in trouble now!"#message 17 "You look in the chest and find nothing."#message 18 "\"Yer more trouble than yer worth!\" the Captain thunders. \"'Tis the plank fer ya now!\""#message 19 "\"I'll not tolerate ya snoopin' around me quarters!\" the Captain thunders. \"If I ketch ya in here again ya'll walk the plank!\""#message 20 "You've found all of your missing possessions! You take them with you."#message 21 "The open chest bears closer examination."#message 22 "The chest is already open."#message 23 "The chest is already closed."#message 24 "Adding insult to injury, all of your belongings have been taken from you again."#message 25 "You look out the window and see the bright, blue ocean."#message 26 "You see nothing you haven't seen before."#message 27 "The captain is snoring peacefully in his bunk."
