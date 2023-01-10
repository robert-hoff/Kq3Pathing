if (isset(newRoom))
  {  v56 = 7;  v57 = 68;  v58 = 164;  v32 = 0;  v31 = 0;  load.logics(Logic112);  load.logics(Logic116);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.sound(Sound1);  load.sound(Sound26);  load.sound(Sound3);  load.view(View250);  animate.obj(o5);  random(0, 159, v37);  random(140, 164, v38);  position.v(o5, v37, v38);  set.view(o5, View250);  set.cel(o5, 0);  set.priority(o5, 4);  draw(o5);  end.of.loop(o5, f222);  animate.obj(o6);  random(1, 159, v37);  random(140, 164, v38);  position.v(o6, v37, v38);  set.view(o6, View250);  set.cel(o6, 1);  set.priority(o6, 4);  draw(o6);  end.of.loop(o6, f223);  animate.obj(o7);  random(0, 159, v37);  random(126, 140, v38);  position.v(o7, v37, v38);  set.view(o7, View250);  set.loop(o7, 1);  set.cel(o7, 2);  set.priority(o7, 4);  draw(o7);  end.of.loop(o7, f224);  animate.obj(o8);  random(0, 159, v37);  random(126, 140, v38);  position.v(o8, v37, v38);  set.view(o8, View250);  set.cel(o8, 0);  set.loop(o8, 1);  set.priority(o8, 4);  draw(o8);  end.of.loop(o8, f225);  load.view(View185);  set.view(o2, View185);  position(o2, 133, 89);  animate.obj(o2);  set.priority(o2, 5);  draw(o2);  v38 = 2;  cycle.time(o2, v38);  animate.obj(o1);  load.view(View173);  position(o1, 64, 42);  set.view(o1, View173);  set.priority(o1, 14);  v38 = 4;  cycle.time(o1, v38);  if (isset(f181))
    {    set.loop(o1, 1);    v221 = 22;    }  else
    {    set.loop(o1, 0);    }  load.view(View0);  load.view(View30);  load.view(View11);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  set.priority(ego, 14);  set.loop(ego, 0);  fix.loop(ego);  if (isset(f48) &&      v44 == 15)
    {    position(ego, 68, 164);    }  if (v44 == 30)
    {    set.view(ego, View30);    set(f48);    position.v(ego, v57, v58);    set(f47);    v44 = 15;    }  if (isset(f47))
    {    draw(ego);    }  v36 = 0;  if (v62 == 2)
    {    v36 = 1;    }  call(Logic112);  show.pic();  return();  }call(Logic116);--v221;if (v221 == 1)
  {  sound(Sound3, f238);  reset(f228);  v221 = 22;  }if (isset(f222))
  {  random(1, 159, v37);  random(140, 164, v38);  reposition.to.v(o5, v37, v38);  set.cel(o5, 0);  end.of.loop(o5, f222);  }if (isset(f223))
  {  random(1, 159, v37);  random(140, 164, v38);  reposition.to.v(o6, v37, v38);  set.cel(o6, 0);  end.of.loop(o6, f223);  }if (isset(f224))
  {  random(1, 159, v37);  random(126, 140, v38);  reposition.to.v(o7, v37, v38);  set.cel(o7, 0);  end.of.loop(o7, f224);  }if (isset(f225))
  {  random(1, 159, v37);  random(126, 140, v38);  reposition.to.v(o8, v37, v38);  set.cel(o8, 0);  end.of.loop(o8, f225);  }if (isset(f33) &&    v44 == 0)
  {  set.view(ego, View30);  v44 = 15;  set.priority(ego, 14);  set.loop(ego, 0);  fix.loop(ego);  }if (v41 < 80)
  {  v220 = 1;  }else
  {  v220 = 2;  }if (v220 == 1 &&    v44 == 15 &&    !isset(f181))
  {  prevent.input();  v44 = 6;  stop.motion(ego);  set.cel(o1, 0);  draw(o1);  sound(Sound26, f238);  start.cycling(o1);  end.of.loop(o1, f226);  }if (isset(f226))
  {  reset(f226);  }else
  {  if (isset(egoHitSpecial) &&      v44 == 15)
    {    // [ WARNING: Block end outside of nested block (0) at position 503    set(f227);    }  else
    {    goto(Label1);    }  }v44 = 6;sound(Sound1, f238);release.loop(ego);set.view(ego, View11);move.obj(ego, 68, 165, 4, f220);Label1:if (isset(f220))
  {  reset(f220);  erase(ego);  set(f44);  if (isset(f227))
    {    print("Whoops! You've unsuccessfully defied the law of gravity.");    }  else
    {    print("A burly pirate has noticed you from inside the crow's nest! Before "          "you can react, he yells, \"Yer dead meat, Bucko!\" and slashes at "          "you with his sword. He misses, but you lose your balance. Down you "          "tumble... to your untimely death.");    }  }if ((said("examine") ||    said("examine", "ship") ||    said("examine", "down", "ship")))
  {  print("Looking down from this height makes you dizzy and you almost fall. "        "Holding tight, you look up and notice a crow's nest at the top of the "        "mast.");  }if ((said("examine", "desert") ||    said("examine", "liquid") ||    said("examine", "bay")))
  {  if (v62 == 3)
    {    print("You scan the horizon. You see land to the east.");    }  if (v62 == 2)
    {    print("The ocean seems to be endless. In every direction, you see nothing "          "but deep, blue water.");    }  if (v62 == 4)
    {    print("The ship has anchored just offshore of a small beach. Further north, "          "in the distance, looms a mountain range.");    }  }if (v62 == 4 &&    (said("examine", "beach") ||    said("examine", "beach")))
  {  print("The ship has anchored just offshore of a small beach. Further north, "        "in the distance, looms a mountain range.");  }if (said("examine", "mast"))
  {  print("The ship's mast dominates your view. Though sturdy, the pitching of "        "the vessel causes it to sway to and fro.");  }if ((said("examine", "up", "banner") ||    said("examine", "banner")))
  {  print("An ominous jolly-roger blows in the breeze.");  }if ((said("examine", "crows nest") ||    said("look in", "crows nest")))
  {  if (isset(f181))
    {    print("You hear loud snoring coming from inside the crow's nest. The "          "keen-eyed lookout has fallen asleep on the job.");    }  else
    {    print("A crow's nest perches atop the mast you are climbing. Curiously, you "          "gaze up at it. But, from this vantage point, you cannot see into it.");    }  }if (said("examine", "bandit"))
  {  print("At the moment, you can see no pirates.");  }if ((said("examine", "rope", "ladder") ||    said("examine", "ladder")))
  {  print("The rope ladder looks flimsy. A careless step might be fatal!");  }if ((said("examine", "sky") ||    said("examine", "up", "sky")))
  {  if (v62 == 2)
    {    print("The sky is cloudless. Some shore birds can be seen far to the east.");    }  else
    {    print("The sky is cloudless. Some shore birds are wheeling overhead.");    }  }call(Logic112);if (edgeEgoHit > NOT_HIT &&    (v44 == 25 ||    v44 == 26))
  {  if ((edgeEgoHit == TOP_EDGE ||      edgeEgoHit == BOTTOM_EDGE))
    {    if (v62 != 4)
      {      new.room(Logic31);      }    else
      {      new.room(Logic48);      }    }  if (edgeEgoHit == LEFT_EDGE)
    {    new.room(Logic82);    }  if (edgeEgoHit == RIGHT_EDGE)
    {    new.room(Logic81);    }  }if (v44 == 15 &&    edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic80);  }return();[ Messages#message 1 "Whoops! You've unsuccessfully defied the law of gravity."#message 2 "Looking down from this height makes you dizzy and you almost fall. Holding tight, you look up and notice a crow's nest at the top of the mast."#message 3 "The rope ladder looks flimsy. A careless step might be fatal!"#message 4 "You scan the horizon. You see land to the east."#message 5 "The ocean seems to be endless. In every direction, you see nothing but deep, blue water."#message 6 "The ship has anchored just offshore of a small beach. Further north, in the distance, looms a mountain range."#message 7 "The ship's mast dominates your view. Though sturdy, the pitching of the vessel causes it to sway to and fro."#message 8 "%m9"#message 9 "A crow's nest perches atop the mast you are climbing. Curiously, you gaze up at it. But, from this vantage point, you cannot see into it."#message 10 "You hear loud snoring coming from inside the crow's nest. The keen-eyed lookout has fallen asleep on the job."#message 11 "At the moment, you can see no pirates."#message 12 "The sky is cloudless. Some shore birds can be seen far to the east."#message 13 "The sky is cloudless. Some shore birds are wheeling overhead."#message 14 "A burly pirate has noticed you from inside the crow's nest! Before you can react, he yells, \"Yer dead meat, Bucko!\" and slashes at you with his sword. He misses, but you lose your balance. Down you tumble... to your untimely death."#message 15 "An ominous jolly-roger blows in the breeze."