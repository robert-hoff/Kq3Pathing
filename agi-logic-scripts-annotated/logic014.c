if (isset(newRoom))
{  if ((v76 > 0 ||    v75 > 0) &&    previousRoom == 36)
  {    v72 = previousRoom;    new.room(Logic87);  }  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  v56 = 2;  set(f57);  set.horizon(52);  v57 = 42;  v58 = 124;  load.view(View0);  load.view(View7);  load.view(View222);  load.view(View68);  if (!isset(f115))
  {    load.view(View66);    load.view(View67);  }  load.logics(Logic111);  load.logics(Logic110);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  animate.obj(o2);  position(o2, 40, 154);  set.view(o2, View222);  v36 = 3;  cycle.time(o2, v36);  ignore.objs(o2);  set.priority(o2, 4);  draw(o2);  if (isset(f115))
  {    add.to.pic(View68, 0, 1, 83, 79, 8, 4);  }  else
  {    add.to.pic(View68, 0, 0, 83, 79, 8, 4);    animate.obj(o1);    set.view(o1, View66);    position(o1, 87, 20);    ignore.horizon(o1);    v36 = 3;    cycle.time(o1, v36);    set.priority(o1, 8);  }  if (isset(f48))
  {    if (previousRoom == 13)
    {      if (v41 > 80 &&        v41 < 85)
      {        v41 = 85;      }      if (v41 > 126 &&        v41 < 133)
      {        v41 = 133;      }      if (v41 > 144)
      {        v41 = 144;      }    }    if (previousRoom == 15)
    {      if (v41 > 69 &&        v41 < 88)
      {        v41 = 88;      }    }    if (previousRoom == 19)
    {      if (v40 < 56)
      {        v40 = 56;      }    }    if (previousRoom == 36)
    {      v40 = 92;      v41 = 86;    }    position.v(ego, v40, v41);  }  if (isset(f47))
  {    draw(ego);  }  call(Logic110);  call(Logic111);  show.pic();  return();}if ((posn(ego, 0, 133, 35, 149) ||  posn(ego, 48, 156, 61, 167)))
{  set(onWater);}reset(f90);reset(f75);if ((posn(ego, 35, 133, 74, 167) ||  posn(ego, 75, 146, 95, 167) ||  posn(ego, 35, 125, 55, 132)))
{  set(f90);  set(f75);}if (isset(onWater))
{  set(f75);  reset(f90);}reset(f225);if (posn(ego, 76, 88, 114, 96))
{  set(f225);}
if (isset(f222) && v71 == 5)
{  v71 = 0;  print("Not now!");}if (isset(haveInput))
{  if (said("examine"))
  {    print("A stream flows by a huge, dark cave.");  }  if (said("examine", "forest"))
  {    print("It's a nice tree, but totally uninteresting.");  }  if (said("look in", "cave"))
  {    print("You can see nothing inside but darkness.");  }  if ((said("carve", "spiderweb") ||    said("break", "spiderweb") ||    said("break", "spiderweb", "try", "dagger") ||    said("carve", "spiderweb", "try", "dagger")))
  {    print("You need to be closer.");  }  if ((said("examine", "cave") ||    said("examine", "hole")))
  {    if (!isset(f115))
    {      print("There is an opening in the side of the hill which is covered by a "        "huge spider web. Inside, it is as black as pitch.");    }    else
    {      print("The cave opens ominously into the side of the hill.");    }  }  if ((said("examine", "spiderweb") ||    said("examine", "spider", "spiderweb") ||    said("look in", "spider", "spiderweb") ||    said("look in", "spiderweb")))
  {    if (!isset(f115))
    {      print("It's the largest web you've ever seen! You can't help but wonder "        "about the spider which could create such a web.");    }    else
    {      print("The spider web has been torn apart.");    }  }  if (said("examine", "spider"))
  {    print("You inspect the entrance of the cave, but can see nothing from this "      "distance.");  }  if (has("Knife") &&    (said("throw", "dagger") ||      said("throw", "dagger", "spider") ||      said("kill", "spider", "dagger") ||      said("throw", "dagger", "spider", "spiderweb") ||      said("throw", "dagger", "spiderweb")))
  {    v36 = 36;    put("Knife", v36);    print("You throw the knife at the web. Your aim is true, and the deadly "      "blade speeds toward the web.");    print("Your knife passes between the strands and clatters harmlessly inside "      "the dark confines of the cave.");  }}if (v44 != 26 &&  !isset(f46) &&  isset(egoHitSpecial))
{  if (isset(f115))
  {    set(f223);  }  else
  {    if (v221 <= 0)
    {      set(f220);      v221 = 0;    }  }}if (v44 == 25 &&  !isset(f115) &&  v221 <= 0 &&  posn(ego, 85, 31, 107, 85))
{  set(f220);  v221 = 100;}if (isset(f45))
{  --v223;  if (v223 == 1)
  {    set(f220);  }}if (isset(f220))
{  reset(f220);  ++v221;  set(f46);  program.control();  v69 = 1;  if (v221 == 1)
  {    stop.motion(ego);    prevent.input();    draw(o1);    move.obj(o1, 87, 48, 1, f220);    print.at("As you touch the sticky web, a giant spider drops down from her "      "lair in the tree above. You attempt to escape, but her sticky web "      "holds you fast!", 14, 2, 37);  }  if (v221 == 2)
  {    v37 = v40;    v37 -= 7;    v38 = 62;    move.obj.v(o1, v37, v38, v69, f220);  }  if (v221 == 3)
  {    v36 = 5;    cycle.time(o1, v36);    set.view(o1, View67);    v37 = 0;    v38 = 20;    reposition(o1, v37, v38);    set.cel(o1, 0);    end.of.loop(o1, f220);    erase(ego);  }  if (v221 == 4)
  {    v223 = 4;    set.view(o1, View66);    v37 = 0;    v38 = 236;    reposition(o1, v37, v38);    start.cycling(o1);  }  if (v221 == 5)
  {    block(83, 53, 95, 70);    observe.blocks(o1);    normal.motion(o1);    start.motion(o1);    wander(o1);    set(f44);  }  if (v221 == 101)
  {    stop.motion(ego);    prevent.input();    draw(o1);    move.obj(o1, 87, 48, 1, f220);    print.at("As you touch the sticky web, a giant spider drops down from her "      "lair in the tree above. You attempt to escape, but her sticky web "      "holds you fast!", 14, 2, 37);    erase(ego);  }  if (v221 == 102)
  {    v37 = v40;    v37 -= 7;    v38 = 62;    move.obj.v(o1, v37, v38, v69, f220);  }  if (v221 == 103)
  {    print("Don't you know? Spiders LOVE flies! Yum. Yum!");    move.obj(o1, 87, 62, 1, f220);  }  if (v221 == 104)
  {    v223 = 4;  }  if (v221 == 105)
  {    block(83, 53, 95, 70);    observe.blocks(o1);    normal.motion(o1);    start.motion(o1);    wander(o1);    set(f44);  }}if (v220 > 0 &&  v220 < 4)
{  v37 = v40;  v38 = v41;  v37 += 8;  v38 += 9;  reposition.to.v(o1, v37, v38);}if (v44 == 26)
{  if (posn(ego, 32, 0, 159, 96) &&    v220 <= 0 &&    !isset(f221) &&    !isset(f115))
  {    set(f221);    set.loop(o1, 0);    position(o1, 88, 52);    set.priority(o1, 15);    draw(o1);  }  if (isset(f221) &&    !isset(f115))
  {    if (posn(ego, 60, 38, 79, 78))
    {      set(f222);      program.control();      set(f115);      currentScore += 4;      move.obj(ego, 79, 43, 2, f224);    }    else
    {      if (posn(ego, 80, 38, 120, 78))
      {        program.control();        set(f115);        currentScore += 4;        move.obj(ego, 98, 43, 2, f224);      }    }  }}if (isset(f45) &&  v220 > 0)
{  v54 = 6;  v55 = 0;}if (isset(f224))
{  reset(f224);  ++v220;  program.control();  prevent.input();  set.priority(ego, 15);  if (v220 == 1)
  {    set(f46);    start.cycling(o1);    add.to.pic(View68, 0, 1, 83, 79, 8, 4);    print.at("You swoop close to the spider-web and find the huge spider "      "guarding the entrance. Taking her in your beak, you vow to get "      "rid of her once and for all!", 4, 2, 37);    move.obj(ego, 132, 35, 2, f224);  }  if (v220 == 2)
  {    v36 = 15;    load.pic(v36);    draw.pic(v36);    discard.pic(v36);    v37 = 2;    v38 = 30;    reposition.to.v(ego, v37, v38);    v37 += 8;    v38 += 9;    reposition.to.v(o1, v37, v38);    erase(o2);    show.pic();    move.obj(ego, 132, 35, 2, f224);  }  if (v220 == 3)
  {    load.view(View162);    load.sound(Sound11);    v36 = 31;    load.pic(v36);    draw.pic(v36);    discard.pic(v36);    v37 = 2;    v38 = 30;    reposition.to.v(ego, v37, v38);    v37 += 8;    v38 += 9;    reposition.to.v(o1, v37, v38);    show.pic();    move.obj(ego, 50, 35, 2, f224);  }  if (v220 == 4)
  {    move.obj(o1, 90, 80, 2, f224);  }  if (v220 == 5)
  {    set.view(o1, View162);    set.cel(o1, 0);    v36 = 2;    cycle.time(o1, v36);    end.of.loop(o1, f224);    sound(Sound11, f41);  }  if (v220 == 6)
  {    erase(o1);    move.obj(ego, 2, 35, 2, f224);  }  if (v220 == 7)
  {    v36 = 15;    load.pic(v36);    draw.pic(v36);    discard.pic(v36);    reposition.to(ego, 126, 35);    show.pic();    move.obj(ego, 2, 35, 2, f224);  }  if (v220 == 8)
  {    v36 = 14;    load.pic(v36);    draw.pic(v36);    discard.pic(v36);    add.to.pic(View68, 0, 1, 83, 79, 8, 4);    reposition.to(ego, 126, 35);    draw(o2);    show.pic();    v220 = 0;    reset(f222);  }}call(Logic110);call(Logic111);if (edgeEgoHit == LEFT_EDGE)
{  new.room(Logic13);}if (edgeEgoHit == RIGHT_EDGE)
{  new.room(Logic15);}if (edgeEgoHit == BOTTOM_EDGE)
{  new.room(Logic19);}if (edgeEgoHit == TOP_EDGE)
{  new.room(Logic29);}if (isset(f223))
{  new.room(Logic36);}return();[Messages#message 1 "There is an opening in the side of the hill which is covered by a huge spider web. Inside, it is as black as pitch."#message 2 "The cave opens ominously into the side of the hill."#message 3 "It's the largest web you've ever seen! You can't help but wonder about the spider which could create such a web."#message 4 "You inspect the entrance of the cave, but can see nothing from this distance."#message 5 "You need to be closer."#message 6 "You can see nothing inside but darkness."#message 7 "A stream flows by a huge, dark cave."#message 8 "You throw the knife at the web. Your aim is true, and the deadly blade speeds toward the web."#message 9 "Your knife passes between the strands and clatters harmlessly inside the dark confines of the cave."#message 10 "It's a nice tree, but totally uninteresting."#message 11 "Don't you know? Spiders LOVE flies! Yum. Yum!"#message 12 "The spider web has been torn apart."#message 13 ""#message 14 "As you touch the sticky web, a giant spider drops down from her lair in the tree above. You attempt to escape, but her sticky web holds you fast!"#message 15 "You swoop close to the spider-web and find the huge spider guarding the entrance. Taking her in your beak, you vow to get rid of her once and for all!"#message 16 "Not now!"
