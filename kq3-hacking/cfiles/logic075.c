if (isset(newRoom))
  {  v36 = 75;  if (v62 == 1)
    {    v36 = 175;    }  load.pic(v36);  draw.pic(v36);  discard.pic(v36);  load.view(View0);  load.view(View11);  load.view(View3);  load.view(View24);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  set.horizon(72);  v56 = 2;  v32 = 32;  v31 = 79;  v57 = 119;  v58 = 100;  load.logics(Logic112);  load.logics(Logic120);  load.sound(Sound1);  load.sound(Sound11);  load.sound(Sound26);  load.view(View229);  animate.obj(o4);  ignore.horizon(o4);  ignore.blocks(o4);  ignore.objs(o4);  position(o4, 7, 146);  set.view(o4, View229);  set.loop(o4, 0);  set.cel(o4, 2);  set.priority(o4, 13);  draw(o4);  animate.obj(o5);  ignore.horizon(o5);  ignore.blocks(o5);  ignore.objs(o5);  position(o5, 37, 146);  set.view(o5, View229);  set.loop(o5, 0);  set.cel(o5, 4);  set.priority(o5, 13);  draw(o5);  animate.obj(o6);  ignore.horizon(o6);  ignore.blocks(o6);  ignore.objs(o6);  position(o6, 68, 146);  set.view(o6, View229);  set.loop(o6, 0);  set.cel(o6, 1);  set.priority(o6, 13);  draw(o6);  animate.obj(o7);  ignore.horizon(o7);  ignore.blocks(o7);  ignore.objs(o7);  position(o7, 102, 147);  set.view(o7, View229);  set.loop(o7, 0);  set.cel(o7, 3);  set.priority(o7, 13);  draw(o7);  animate.obj(o8);  ignore.horizon(o8);  ignore.blocks(o8);  ignore.objs(o8);  position(o8, 135, 146);  set.view(o8, View229);  set.loop(o8, 0);  set.cel(o8, 0);  set.priority(o8, 13);  draw(o8);  v36 = 2;  cycle.time(o4, v36);  v36 = 3;  cycle.time(o5, v36);  v36 = 2;  cycle.time(o6, v36);  v36 = 3;  cycle.time(o7, v36);  v36 = 2;  cycle.time(o8, v36);  if (v62 == 1)
    {    animate.obj(o3);    load.view(View155);    set.view(o3, View155);    set.priority(o3, 12);    position(o3, 23, 90);    set.cel(o3, 0);    stop.cycling(o3);    draw(o3);    stop.update(o3);    animate.obj(o2);    load.view(View165);    load.view(View163);    set.view(o2, View165);    set.cel(o2, 0);    if (isset(f79))
      {      position(o2, 18, 73);      ignore.objs(o3);      }    else
      {      position(o2, 23, 85);      set.priority(o2, 13);      }    stop.cycling(o2);    draw(o2);    stop.update(o2);    if (isset(f79))
      {      v221 = 10;      v222 = 8;      v50 = 100;      reset(f177);      animate.obj(o1);      load.view(View156);      set.view(o1, View156);      position(o1, 54, 70);      set.priority(o1, 12);      stop.cycling(o1);      set.loop(o1, 1);      draw(o1);      stop.update(o1);      animate.obj(o9);      load.view(View159);      set.view(o9, View159);      ignore.horizon(o9);      position(o9, 130, 46);      draw(o9);      move.obj(o9, 65, 46, 1, f229);      }    }  if (v44 == 14)
    {    set.priority(ego, 13);    set(f220);    }  if (isset(f48))
    {    get.posn(ego, v40, v41);    if (v44 == 0)
      {      set.priority(ego, 13);      set(f220);      if (v41 > 114)
        {        v41 = 114;        }      if (v41 < 92)
        {        v41 = 92;        }      position.v(ego, v40, v41);      }    if (v44 == 11)
      {      reset(f220);      release.priority(ego);      set(f35);      if (v41 > 138)
        {        observe.blocks(ego);        }      else
        {        ignore.blocks(ego);        }      }    position.v(ego, v40, v41);    }  if (v44 == 30)
    {    set(f220);    set.view(ego, View0);    set.priority(ego, 13);    set(f48);    position.v(ego, v57, v58);    set(f47);    }  if (isset(f47))
    {    draw(ego);    }  v36 = 0;  call(Logic112);  show.pic();  return();  }if (v62 == 1 &&     v53 <= 0 &&     v52 < 30 &&     v52 > 0)
  {  v52 = 30;  }if (v62 > 1)
  {  print("With a sinking feeling, you notice that the large ship is no longer "        "tied to the pier. It looks like you missed the boat!");  stop.cycling(ego);  set(f44);  }if (posn(ego, 28, 71, 37, 77))
  {  if (v44 == 0 &&       !isset(f46))
    {    set(f46);    v224 = 10;    set(f229);    }  }if (isset(f45) &&     v225 > 0)
  {  if (!isset(f46))
    {    --v225;    }  if (v225 == 0)
    {    set(f229);    }  }if (isset(f229) &&     v224 == 0)
  {  ++v224;  reposition.to(o9, 62, 57);  v225 = 2;  reset(f229);  }if (isset(f229) &&     v224 == 1)
  {  ++v224;  move.obj(o9, 47, 57, 1, f229);  }if (isset(f229) &&     v224 == 2)
  {  ++v224;  reset(f229);  print("\"You'd bet'er get aboard boy, or we'll sail without ya.\"");  stop.cycling(o9);  stop.update(o9);  v225 = 15;  }if (isset(f229) &&     v224 == 3)
  {  ++v224;  reset(f229);  print("You hear one of the sailors shout down to you, \"Get yer self aboard, "        "laddie. We be sailin' on th' tide, wi' or wi'out ye.\"");  v225 = 15;  }if (isset(f229) &&     v224 == 4)
  {  reset(f229);  print("From the deck of the ship you hear, \"Are ye deaf, or just daft, boyo? "        "I said come aboard a'fore we leave ye here.\"");  }if (isset(f229) &&     v224 == 10)
  {  ++v224;  stop.motion(ego);  set.priority(ego, 12);  start.update(o3);  program.control();  v36 = 6;  cycle.time(o3, v36);  end.of.loop(o3, f229);  }if (isset(f229) &&     v224 == 11)
  {  ++v224;  print("As the gangplank is drawn in you hear the Captain shout to his men, "        "\"Take 'is things an put 'im in the 'old until I figures out what ta "        "do with 'im.\"");  start.update(o2);  end.of.loop(o2, f41);  start.update(o1);  start.cycling(o1);  sound(Sound26, f238);  move.obj(o1, 35, 70, 1, f229);  }if (isset(f229) &&     v224 == 12)
  {  ++v224;  currentScore  += 2;  reset(f229);  print("You have a sneaking suspicion that you have made a big mistake. These "        "are pirates!");  player.control();  reset(f46);  new.room(Logic77);  }if (isset(f33))
  {  if (v44 == 0)
    {    set(f220);    set.priority(ego, 13);    }  else
    {    if (isset(f177))
      {      normal.motion(o2);      stop.motion(o2);      stop.cycling(o2);      reset(f230);      }    }  }if (v44 == 0)
  {  if (isset(egoHitSpecial) &&       !isset(f46))
    {    set(f46);    reset(f220);    v44 = 6;    sound(Sound1, f238);    ignore.blocks(ego);    set.view(ego, View11);    start.motion(ego);    if (v41 < 85)
      {      set.priority(ego, 4);      v36 = 3;      v38 = 135;      move.obj.v(ego, v40, v38, v36, f221);      }    if (v41 > 115)
      {      set.priority(ego, 15);      v36 = 3;      v38 = 167;      move.obj.v(ego, v40, v38, v36, f221);      }    }  }if (v44 == 6 &&     isset(f221))
  {  reset(f46);  reset(f221);  release.priority(ego);  observe.blocks(ego);  set(f35);  set.view(ego, View3);  v44 = 11;  sound(Sound11, f238);  }reset(onWater);if (v44 == 11)
  {  set(onWater);  if (v41 > 138)
    {    observe.blocks(ego);    release.priority(ego);    }  else
    {    ignore.blocks(ego);    set.priority(ego, 4);    }  }if (!isset(f46) &&     isset(f45) &&     v227 > 0)
  {  --v227;  distance(o2, ego, v36);  if (v227 == 0)
    {    if (v36 < 30)
      {      set(f177);      print("\"That's it!\" he shouts. \"I warned ya to quit hangin' aroun'.\"");      }    else
      {      ++v227;      }    }  }if (isset(f177) &&     !isset(f230) &&     v44 == 0)
  {  set(f230);  v227 = 0;  start.update(o2);  start.cycling(o2);  set.view(o2, View163);  ignore.blocks(o2);  ignore.objs(o2);  follow.ego(o2, 10, f227);  }if (!isset(f46) &&     isset(f230) &&     v44 != 0)
  {  get.posn(o2, v37, v38);  if (v37 == v40)
    {    stop.cycling(o2);    }  else
    {    v36 = 1;    start.cycling(o2);    move.obj.v(o2, v40, v38, v36, f227);    }  }if (isset(f227) &&     v44 == 0)
  {  if (isset(f46))
    {    reset(f227);    stop.cycling(o2);    normal.motion(o2);    stop.motion(o2);    }  else
    {    set(f46);    reset(f227);    reset(f230);    program.control();    stop.motion(ego);    get.posn(ego, v40, v41);    get.posn(o2, v37, v38);    v38 = v41;    v38 -= 2;    ignore.blocks(o2);    reposition.to.v(o2, v37, v38);    prevent.input();    set.view(o2, View165);    set.cel(o2, 0);    v36 = 2;    cycle.time(o2, v36);    set.priority(ego, 14);    end.of.loop(o2, f228);    v44 = 29;    v223 = 50;    }  }if (isset(f228))
  {  reset(f228);  set.view(ego, View24);  print.at("The old seaman draws his sharp cutlass, runs you clean through, and "           "you drop to the dock... dead.", 2, 2, 37);  }--v223;if (v223 == 1)
  {  stop.cycling(ego);  set(f44);  }if (isset(haveInput))
  {  if ((said("examine", "ship") ||       said("examine", "bandit", "ship")))
    {    if (v62 == 1)
      {      print("A large ship is tied to the dock.");      }    else
      {      print("What ship?");      }    }  if (v62 == 1 &&       (said("board", "ship") ||       said("jump", "ship")))
    {    if (isset(f79))
      {      print("Sounds like a good idea. Just walk across the gang plank.");      }    else
      {      print("There is no way to do that.");      }    }  if (said("examine", "town"))
    {    print("A charming village sits atop a bluff overlooking the ocean.");    }  if ((said("call", "try", "bandit") ||       said("call", "bandit")))
    {    if (v62 == 1)
      {      if (!isset(f220))
        {        print("Nobody can hear you!");        }      else
        {        if (isset(f79))
          {          print("\"Climb aboard, laddie! We won't be awaiting all day for ye.\"");          }        else
          {          ++v222;          if (v222 == 1)
            {            print("You politely speak to the old sailor on the dock. In "                  "response, he growls, \"Quit yer yammerin', boy. I ain't got "                  "no time fer ya. I gotta keep trespassers away from this here "                  "jolly-boat. Scram!\"");            }          if (v222 == 2)
            {            v227 = 8;            print("Insistently, you speak to the old salt again. He seems "                  "displeased as he snarls, \"I'm warnin' ya, boy. I gots a "                  "tricky sword hand. Better go away afore I cain't stop "                  "meself!\"");            }          if (v222 == 3)
            {            v227 = 0;            print("\"That's it!\" he shouts. \"I warned ya to quit hangin' "                  "aroun'.\"");            set(f177);            }          if (v222 > 3)
            {            print("You had better stop talking, and run for your life.");            }          }        }      }    else
      {      print("There is nobody here but you.");      }    }  if (said("examine", "bandit"))
    {    if (v62 == 1)
      {      if (!isset(f79))
        {        print("The life of a seaman has definitely taken its toll on this "              "grizzled old sea dog. His skin is brown and cracked from years "              "in the salty air, his voice rasps from too many smokes and too "              "much rum, and he stoops from countless swabbings of countless "              "decks. His clothes are none too clean, either.");        }      else
        {        print("The Captain and his crew are waiting for you to come aboard.");        }      }    else
      {      print("There is nobody here but you.");      }    }  if (said("examine", "dock"))
    {    print("A weathered dock leads into the ocean.");    }  if ((said("capture", "bandit") ||       said("kill", "bandit")))
    {    if (!isset(f79))
      {      print("You're no match for him.");      }    else
      {      print("Surely, you jest?");      }    }  }call(Logic112);call(Logic120);if (edgeEgoHit > NOT_HIT &&     isset(f230))
  {  if (!isset(f46))
    {    print("\"Ya better skedaddle, sonny!\"");    }  }if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic30);  }if (edgeEgoHit == TOP_EDGE)
  {  v176 = edgeEgoHit;  new.room(Logic31);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic25);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic76);  }return();[ Messages#message 1 "A large ship is tied to the dock."#message 2 "What ship?"#message 3 "There is no way to do that."#message 4 "A charming village sits atop a bluff overlooking the ocean."#message 5 "Sounds like a good idea. Just walk across the gang plank."#message 6 "The life of a seaman has definitely taken its toll on this grizzled old sea dog. His skin is brown and cracked from years in the salty air, his voice rasps from too many smokes and too much rum, and he stoops from countless swabbings of countless decks. His clothes are none too clean, either."#message 7 "The old seaman draws his sharp cutlass, runs you clean through, and you drop to the dock... dead."#message 8 "You hear one of the sailors shout down to you, \"Get yer self aboard, laddie. We be sailin' on th' tide, wi' or wi'out ye.\""#message 9 "From the deck of the ship you hear, \"Are ye deaf, or just daft, boyo? I said come aboard a'fore we leave ye here.\""#message 10 "You have a sneaking suspicion that you have made a big mistake. These are pirates!"#message 11 "You politely speak to the old sailor on the dock. In response, he growls, \"Quit yer yammerin', boy. I ain't got no time fer ya. I gotta keep trespassers away from this here jolly-boat. Scram!\""#message 12 "Insistently, you speak to the old salt again. He seems displeased as he snarls, \"I'm warnin' ya, boy. I gots a tricky sword hand. Better go away afore I cain't stop meself!\""#message 13 "\"That's it!\" he shouts. \"I warned ya to quit hangin' aroun'.\""#message 14 "As the gangplank is drawn in you hear the Captain shout to his men, \"Take 'is things an put 'im in the 'old until I figures out what ta do with 'im.\""#message 15 "%m14 You notice the captain looking at you and laughing with one of the crew, and you decide they are as happy to be starting this voyage as you are."#message 16 "%m14 You have this dreadful feeling that you've missed something important as you walk down the now-deserted pier."#message 17 "\"You'd bet'er get aboard boy, or we'll sail without ya.\""#message 18 "\"Ya better skedaddle, sonny!\""#message 19 "\"Climb aboard, laddie! We won't be awaiting all day for ye.\""#message 20 "The Captain and his crew are waiting for you to come aboard."#message 21 "There is nobody here but you."#message 22 "A weathered dock leads into the ocean."#message 23 "You're no match for him."#message 24 "Surely, you jest?"#message 25 "You had better stop talking, and run for your life."#message 26 "With a sinking feeling, you notice that the large ship is no longer tied to the pier. It looks like you missed the boat!"#message 27 "Nobody can hear you!"