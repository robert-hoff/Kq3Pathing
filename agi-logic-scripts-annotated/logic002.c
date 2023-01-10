if (isset(newRoom))
{
  load.view.v(currentEgoView);
  set.view.v(ego, currentEgoView);
  load.view(View0);
  v56 = 1;
  v57 = 84;
  v58 = 148;
  v32 = 20;
  v31 = 150;
  v100 = 82;
  v101 = 120;
  load.logics(Logic104);
  if (v128 != 20)
  {
    v128 = 0;
  }
  if (v127 == 4 &&
    v128 != 20)
  {
    load.logics(Logic105);
    set(f98);
    load.view(View194);
    load.view(View195);
    load.view(View199);
    load.sound(Sound3);
    load.sound(Sound2);
    v32 = 29;
    v31 = 117;
    v125 = 0;
  }
  else
  {
    if ((v127 == 1 ||
      v127 == 3) &&
      v137 <= 0 &&
      v128 != 20)
    {
      random(1, 4, v36);
      if (v36 == 1)
      {
        set(f98);
        load.logics(Logic105);
        random(6, 12, v125);
      }
    }
  }
  load.pic(currentRoom);
  draw.pic(currentRoom);
  discard.pic(currentRoom);
  load.view(View176);
  load.view(View90);
  load.view(View179);
  load.view(View180);
  animate.obj(o2);
  position(o2, 27, 133);
  set.view(o2, View176);
  draw(o2);
  stop.update(o2);
  animate.obj(o1);
  position(o1, 51, 70);
  set.view(o1, View0);
  set.priority(o1, 4);
  ignore.blocks(o1);
  ignore.objs(o1);
  ignore.horizon(o1);
  draw(o1);
  v36 = 2;
  animate.obj(o3);
  position(o3, 100, 115);
  set.view(o3, View90);
  set.priority(o3, 5);
  cycle.time(o3, v36);
  if (v230 > 0)
  {
    last.cel(o3, v36);
    set.cel.v(o3, v36);
  }
  else
  {
    set.cel(o3, 0);
  }
  draw(o3);
  stop.update(o3);
  animate.obj(o5);
  ignore.objs(o5);
  ignore.blocks(o5);
  position(o5, 63, 123);
  set.view(o5, View179);
  set.cel(o5, 0);
  cycle.time(o5, v36);
  set.priority(o5, 6);
  draw(o5);
  stop.update(o5);
  animate.obj(o4);
  ignore.objs(o4);
  ignore.blocks(o4);
  position(o4, 107, 146);
  set.view(o4, View180);
  set.cel(o4, 0);
  cycle.time(o4, v36);
  draw(o4);
  stop.update(o4);
  if (v44 == 25)
  {
    set(f48);
  }
  if (isset(f48))
  {
    if (previousRoom == 3)
    {
      position(ego, 41, 167);
    }
    else
    {
      position.v(ego, v57, v58);
    }
  }
  observe.blocks(ego);
  if (isset(f47))
  {
    draw(ego);
  }
  call(Logic104);
  if (isset(f98))
  {
    call(Logic105);
    if (v127 == 4)
    {
      set(f234);
      v220 = 44;
      v128 = 7;
      set.view(o15, View194);
      set.cel(o15, 0);
      stop.cycling(o15);
      position.v(o15, v32, v31);
      draw(o15);
      set(f99);
    }
    else
    {
      v128 = 0;
    }
  }
  show.pic();
  return ();
}
reset(f220);
if (posn(ego, 0, 0, 36, 141))
{
  set(f220);
}
reset(f221);
if (posn(ego, 21, 131, 44, 140))
{
  set(f221);
}
reset(f223);

if (posn(ego, 95, 127, 112, 131))
{
  set(f223);
}


reset(f224);
if (posn(ego, 58, 132, 70, 142))
{
  set(f224);
}
reset(f222);
if ((posn(ego, 77, 120, 91, 132) ||
  posn(ego, 0, 133, 27, 156)))
{
  set(f222);
}
reset(f225);
reset(f228);
if (posn(ego, 102, 134, 117, 153))
{
  set(f225);
  if (posn(ego, 108, 144, 112, 146))
  {
    set(f228);
  }
}
reset(f227);
reset(f226);
if (posn(ego, 0, 133, 75, 164))
{
  set(f226);
  if (posn(ego, 0, 133, 69, 156))
  {
    set(f227);
  }
}
if (!isset(haveInput))
{
  goto(Label1);
}
if ((said("examine", "area") ||
  said("examine", "building") ||
  said("examine") ||
  said("examine", "bedroom")))
{
  print("You look at Manannan's elegant bed chamber. You see fine furnishings "
    "from a regal bed to a beautifully carved closet. You can't help but "
    "compare this handsome room to your own meager cubicle.");
}
if (said("examine", "nightstand"))
{
  print("There is a small drawer in the front of the mahogany vanity.");
}

if (said("examine", "looking glass") || said("look in", "looking glass"))
{
  if (!isset(f224))
  {
    print("The beveled mirror appears wavy because of imperfections in the "
      "glass. %m41");
  }
  else
  {
    current.loop(ego, v36);
    if (v36 == 2)
    {
      print("The back of your hair looks cute.");
    }
    else
    {
      print("Imperfections in the glass make your reflection wavy; "
        "nevertheless, your rags show up all too clearly. But, though in "
        "rags, your face is handsome and your body strong.");
    }
  }
}
if (said("examine", "bed"))
{
  if (v128 == 7)
  {
    print("Manannan is asleep on his great bed. His snores are so loud they "
      "rumble off the walls. Be quiet; you wouldn't want to disturb him.");
  }
  else
  {
    print("Heavy velvet curtains drape the regal mahogany bed.");
  }
}

if (said("examine", "below", "bed"))
{
  if (isset(f221))
  {
    print("Dropping to your hands and knees, you peer under the bed. There is "
      "absolutely nothing there.");
  }
  else
  {
    print("You are not close enough.");
  }
}

if ((said("lay", "bed") ||
  said("lay", "on", "bed") ||
  said("lay", "down", "on", "bed") ||
  said("capture", "bed") ||
  said("capture", "on", "bed") ||
  said("board", "sleep") ||
  said("board", "bed")))
{
  print("As comfortable as the bed looks, you have no interest in lying on the "
    "hateful wizard's bed.");
}

if (said("examine", "carpet"))
{
  print("A beautiful rug adorns the floor. Its thick wool is woven into a "
    "colorful design.");
}

if (said("capture", "carpet"))
{
  print("The carpet is too big and heavy to carry around.");
}

if (said("examine", "below", "carpet"))
{
  if (isset(f227))
  {
    print("You tug at the rug for quite a while... before realizing you're "
      "standing on it!");
  }
  else
  {
    if (isset(f226))
    {
      print("You lift up the rug in several places and look under it. Sad to "
        "say, all you see is the dust you swept under there yesterday.");
    }
    else
    {
      print("You are not close enough.");
    }
  }
}

if ((said("examine", "top", "bureau") ||
  said("examine", "above", "bureau") ||
  said("examine", "on", "above", "bureau") ||
  said("examine", "on", "bureau") ||
  said("examine", "bureau", "top")))
{
  print("There is nothing exciting on top of the dresser.");
}
if (said("examine", "drawer") || said("examine", "bureau"))
{
  if (isset(f224))
  {
    print("There is a small drawer in the front of the mahogany vanity.");
  }
  else
  {
    print("The elegant dresser is made of mahogany. Its drawers are graced by "
      "beautiful gold knobs.");
  }
}

if ((said("look in", "bureau") ||
  said("look in", "drawer") ||
  said("look in", "nightstand") ||
  said("look in", "bureau", "drawer") ||
  said("look in", "nightstand", "drawer") ||
  said("look in", "drawer", "bureau") ||
  said("look in", "drawer", "nightstand") ||
  said("lift", "nightstand", "drawer") ||
  said("lift", "bureau", "drawer") ||
  said("lift", "drawer", "nightstand") ||
  said("lift", "drawer", "bureau") ||
  said("lift", "nightstand") ||
  said("lift", "bureau") ||
  said("lift", "drawer")))
{
  if (isset(f224))
  {
    if (v128 == 7)
    {
      set(f236);
      v229 = 100;
    }
    else
    {
      v226 = 44;
    }
  }
  else
  {
    if (isset(f225))
    {
      if (v128 == 7)
      {
        set(f236);
        v229 = 100;
      }
      else
      {
        if (isset(f228))
        {
          print("You bang the drawer against your shins repeatedly. (Try "
            "backing up!)");
        }
        else
        {
          v227 = 44;
        }
      }
    }
    else
    {
      if (isset(f223))
      {
        print("Quietly opening the drawer below the closet, you discover...");
        print("nothing that interests you.");
      }
      else
      {
        print("You are not close enough.");
      }
    }
  }
}

if (said("examine", "cabinet"))
{
  if (!isset(f223) && obj.in.room("Brass Key*", currentRoom))
  {
    print("%m2 There may be something metallic on its top.");
  }
  else
  {
    print("The closet is fashioned of ornately carved mahogany.");
  }
}

if (v230 == 0 &&
  (said("look in", "cabinet") ||
    said("examine", "inside", "cabinet") ||
    said("lift", "door") ||
    said("lift", "door", "cabinet") ||
    said("lift", "cabinet", "door") ||
    said("lift", "cabinet")))
{
  if (!isset(f223))
  {
    print("You are not close enough.");
  }
  else
  {
    if (v128 == 7)
    {
      set(f236);
      v229 = 100;
    }
    else
    {
      ++v230;
      start.update(o3);
      set.cel(o3, 0);
      end.of.loop(o3, f230);
    }
  }
}

if (v230 > 0)
{
  if (obj.in.room("Magic Map*", currentRoom) &&
    (said("examine", "cabinet") ||
      said("examine", "back", "rol") ||
      said("move", "anyword", "find", "rol") ||
      said("move", "clothes", "rol") ||
      said("move", "anyword") ||
      said("find", "cabinet")))
  {
    if (!isset(f223))
    {
      print("You are not close enough.");
    }
    else
    {
      v230 = 3;
      print("You're startled to discover an ancient parchment scroll. Its ink "
        "has faded, but it seems to be a map. Taking this treasure, you "
        "leave everything else exactly as it was.");
      get("Magic Map*");
      currentScore += 7;
    }
  }
  if ((said("look in", "cabinet") ||
    said("examine", "inside", "cabinet") ||
    said("examine", "clothes") ||
    said("examine", "cabinet") ||
    said("find", "cabinet")))
  {
    if (!isset(f223))
    {
      print("You are not close enough.");
    }
    else
    {
      print("You see voluminous velvet robes, satin slippers, peaked hats, and "
        "soft linen gowns.");
      v230 = 2;
    }
  }
}

if (v230 > 0 &&
  (said("close", "cabinet") ||
    said("close", "door", "cabinet") ||
    said("close", "cabinet", "door") ||
    said("close", "door")))
{
  if (!isset(f223))
  {
    print("You are not close enough.");
  }
  else
  {
    v230 = 0;
    start.update(o3);
    last.cel(o3, v36);
    set.cel.v(o3, v36);
    reverse.loop(o3, f230);
  }
}
if ((said("find", "above", "cabinet") ||
  said("find", "top", "cabinet") ||
  said("find", "on", "cabinet") ||
  said("find", "on", "above", "cabinet") ||
  said("examine", "above", "cabinet") ||
  said("examine", "top", "cabinet") ||
  said("examine", "on", "cabinet") ||
  said("examine", "on", "above", "cabinet")))
{
  if (!isset(f223))
  {
    print("You are not close enough to reach the top of the closet.");
  }
  else
  {
    if (!obj.in.room("Brass Key*", currentRoom))
    {
      print("You feel along the top of the closet. Your hand comes back dusty.");
    }
    else
    {
      get("Brass Key*");
      print("You run a hand along the top of the closet. Suddenly, you touch "
        "something metallic. Grabbing it, you discover... a small brass "
        "key! What could it unlock?");
      if (!isset(f92))
      {
        set(f92);
        currentScore += 3;
      }
    }
  }
}
if (said("lift", "glass") || said("close", "glass"))
{
  if (!isset(f222))
  {
    print("You are not close enough.");
  }
  else
  {
    print("Manannan's bedroom window is always open. He likes fresh air.");
  }
}

if ((said("examine", "basin") ||
  said("examine", "chamber pot") ||
  said("examine", "deck") ||
  said("examine", "chamber pot")))
{
  print("Manannan's chamber pot is on the floor beside his bed.");
}
if ((said("try", "basin") ||
  said("try", "chamber pot") ||
  said("try", "chamber pot")))
{
  if (!isset(f220))
  {
    print("You are not close enough.");
  }
  else
  {
    print("A feeling of great relief spreads over you.");
  }
}
if ((said("look in", "basin") ||
  said("look in", "chamber pot") ||
  said("look in", "chamber pot")))
{
  if (!isset(f220))
  {
    print("You are not close enough.");
  }
  else
  {
    print("You look inside Manannan's chamber pot...");
    print("and wish you hadn't!!");
  }
}
if (!isset(f46) &&
  (said("drain", "chamber pot") ||
    said("drain", "basin") ||
    said("drain", "chamber pot") ||
    said("capture", "chamber pot") ||
    said("capture", "basin") ||
    said("capture", "chamber pot")))
{
  if (!isset(f220))
  {
    print("You are not close enough.");
  }
  else
  {
    v224 = 0;
    set(f235);
  }
}
if (v128 == 7)
{
  if (said("examine", "enchanter"))
  {
    print("Manannan is asleep on his great bed. His snores are so loud they "

      "rumble off the walls. Be quiet; you wouldn't want to disturb him.");
  }
  if ((said("call", "enchanter") ||
    said("wake", "up", "enchanter") ||
    said("wake", "enchanter", "up") ||
    said("wake", "enchanter")))
  {
    if (!isset(f229))
    {
      set(f229);
      print("You speak softly to the sleeping wizard. \"Hhrrummph!\" he "

        "grumbles sleepily, thumbing his nose as if at a fly. But, soon the "

        "snoring resumes again.");
    }
    else
    {
      v229 = 200;
      set(f236);
    }
  }
}
Label1:
if (isset(f235))
{
  reset(f235);
  ++v224;
  v69 = 1;
  program.control();
  prevent.input();
  if (v224 == 1)
  {
    set(f46);
    start.update(o2);
    erase(o2);
    ignore.objs(o13);
    v222 = v40;
    v223 = v41;
    v37 = 82;
    move.obj.v(ego, v37, v41, v69, f235);
    if (v137 == 2)
    {
      v137 = 0;
      v110 = 0;
      v109 = 0;
    }
  }
  if (v224 == 2)
  {
    v38 = 122;
    move.obj.v(ego, v40, v38, v69, f235);
  }
  if (v224 == 3)
  {
    print("Wrinkling your nose in disgust, you throw the smelly contents of the "

      "chamber pot out the open window. What a way to make a living!");
    move.obj.v(ego, v40, v223, v69, f235);
  }
  if (v224 == 4)
  {
    move.obj.v(ego, v222, v223, v69, f235);
  }
  if (v224 == 5)
  {
    draw(o2);
    observe.objs(o13);
    player.control();
    accept.input();
    reset(f46);
  }
}
if (isset(f230))
{
  reset(f230);
  stop.update(o3);
}
--v226;
if (v226 == 43)
{
  stop.motion(ego);
  start.update(o5);
  end.of.loop(o5, f41);
}
if (v226 == 22)
{
  if (obj.in.room("Mirror*", currentRoom))
  {
    get("Mirror*");
    currentScore += 1;
    print("In the vanity drawer are many uninteresting items, although the "

      "wizard's hand mirror may come in handy. You grab it, then close the "

      "drawer.");
  }
  else
  {
    print("You find baubles and trinkets which do not interest you.");
  }
}
if (v226 == 1)
{
  reverse.loop(o5, f232);
}
if (isset(f232))
{
  reset(f232);
  stop.update(o5);
  start.motion(ego);
}
--v227;
if (v227 == 43)
{
  stop.motion(ego);
  start.update(o4);
  end.of.loop(o4, f41);
}
if (v227 == 22)
{
  if (obj.in.room("Rose Essence*", currentRoom))
  {
    get("Rose Essence*");
    currentScore += 1;
    print("%m34 Suddenly, your eye falls on something that does... a vial "

      "labeled \"Rose Petal Essence,\" which you eagerly take.");
  }
  else
  {
    print("You find baubles and trinkets which do not interest you.");
  }
}
if (v227 == 1)
{
  reverse.loop(o4, f233);
}
if (isset(f233))
{
  reset(f233);
  stop.update(o4);
  start.motion(ego);
}
if (isset(f99) &&
  !isset(f109))
{
  if (v128 == 7)
  {
    --v220;
    if (v220 == 1)
    {
      start.cycling(o15);
      end.of.loop(o15, f231);
      v220 = 22;
      sound(Sound3, f41);
    }
    if (isset(f231))
    {
      reset(f231);
      stop.cycling(o15);
      set.cel(o15, 0);
    }
  }
}
if (isset(f45))
{
  --v130;
  if (v130 == 1)
  {
    set(f236);
  }
  if (v84 <= 0 &&
    v83 < 8)
  {
    v83 = 8;
  }
}
if (v229 == 204)
{
  current.cel(o14, v36);
  if (v36 == 3)
  {
    set(f236);
  }
}
if (isset(f236))
{
  reset(f236);
  ++v229;
  if (v229 == 101)
  {
    prevent.input();
    program.control();
    stop.motion(ego);
    set(f46);
    v128 = 0;
    stop.cycling(o15);
    set.view(o15, View195);
    set.cel(o15, 0);
    reposition.to(o15, 38, 117);
    v130 = 4;
    v220 = 0;
  }
  if (v229 == 102)
  {
    set.cel(o15, 1);
    print("You try to be quiet, but an unfortunate squeak wakes Manannan. He "

      "turns in his bed, then sits up, staring angrily at you. \"You know "

      "you're to stay out of my things,\" he growls. \"I've no choice but "

      "to punish you for this.\"");
    v130 = 4;
  }
  if (v229 == 103)
  {
    set.view(o15, View190);
    reposition.to(o15, 37, 133);
    force.update(o15);
    v36 = 2;
    cycle.time(o15, v36);
    v127 = 1;
    v84 = 5;
    force.update(ego);
    unanimate.all();
    animate.obj(ego);
    draw(ego);
    force.update(ego);
    animate.obj(o15);
    draw(o15);
    force.update(o15);
    v123 = 15;
    set(f130);
    v229 = 0;
  }
  if (v229 == 201)
  {
    prevent.input();
    program.control();
    stop.motion(ego);
    set(f46);
    v128 = 103;
    stop.cycling(o15);
    set.view(o15, View195);
    set.cel(o15, 0);
    reposition.to(o15, 38, 117);
    v130 = 4;
    v220 = 0;
  }
  if (v229 == 202)
  {
    set.cel(o15, 1);
    print("This time your words awaken Manannan. A grumpy look comes to his "

      "face. \"Don't you have anything better to do, boy, than to come in "

      "MY bed chamber and wake me from my peaceful repose?\"");
    v130 = 4;
  }
  if (v229 == 203)
  {
    set.view(o15, View190);
    reposition.to(o15, 37, 133);
    v36 = 2;
    cycle.time(o15, v36);
    v127 = 1;
    v84 = 5;
    v129 = 2;
    v130 = 4;
  }
  if (v229 == 204)
  {
    animate.obj(o14);
    set.view(o14, View199);
    set.cel(o14, 0);
    v36 = 3;
    cycle.time(o14, v36);
    ignore.objs(o14);
    set.priority(o14, 15);
    position(o14, 37, 133);
    stop.motion(o14);
    start.cycling(o14);
    draw(o14);
    end.of.loop(o14, f236);
    sound(Sound2, f41);
  }
  if (v229 == 205)
  {
    erase(o15);
  }
  if (v229 == 206)
  {
    erase(o14);
    reset(f99);
    reset(f98);
    v32 = 20;
    v31 = 150;
    accept.input();
    player.control();
    start.motion(ego);
    reset(f46);
    erase(o14);
    v128 = 104;
    v229 = 0;
  }
}
if (isset(f114))
{
  erase(o1);
}
else
{
  if (v41 > 105)
  {
    current.view(ego, v36);
    set.view.v(o1, v36);
    current.loop(ego, v36);
    if (v36 == 3)
    {
      set.loop(o1, 2);
    }
    else
    {
      if (v36 == 2)
      {
        set.loop(o1, 3);
      }
      else
      {
        set.loop.v(o1, v36);
      }
    }
    current.cel(ego, v36);
    set.cel.v(o1, v36);
    get.posn(ego, v40, v38);
    v38 -= 132;
    v81 = 117;
    v81 -= v38;
    reposition.to.v(o1, v40, v81);
    if (!isset(f35) &&
      (egoDir == STOPPED ||
        egoDir == v82))
    {
      stop.cycling(o1);
    }
    else
    {
      start.cycling(o1);
    }
  }
}
call(Logic104);
if (isset(f98))
{
  call(Logic105);
}
if (edgeEgoHit == BOTTOM_EDGE &&
  v44 != 125 &&
  v40 > 36 &&
  v40 < 52)
{
  new.room(Logic3);
}
return ();

[Messages
#message 1 "You look at Manannan's elegant bed chamber. You see fine furnishings from a regal bed to a beautifully carved closet. You can't help but compare this handsome room to your own meager cubicle."
#message 2 "The closet is fashioned of ornately carved mahogany."
#message 3 "You see voluminous velvet robes, satin slippers, peaked hats, and soft linen gowns."
#message 4 "Imperfections in the glass make your reflection wavy; nevertheless, your rags show up all too clearly. But, though in rags, your face is handsome and your body strong."
#message 5 "You run a hand along the top of the closet. Suddenly, you touch something metallic. Grabbing it, you discover... a small brass key! What could it unlock?"
#message 6 "You feel along the top of the closet. Your hand comes back dusty."
#message 7 "Heavy velvet curtains drape the regal mahogany bed."
#message 8 "Dropping to your hands and knees, you peer under the bed. There is absolutely nothing there."
#message 9 "The elegant dresser is made of mahogany. Its drawers are graced by beautiful gold knobs."
#message 10 "There is nothing exciting on top of the dresser."
#message 11 "%m34 Suddenly, your eye falls on something that does... a vial labeled \"Rose Petal Essence,\" which you eagerly take."
#message 12 "You are not close enough to reach the top of the closet."
#message 13 "A beautiful rug adorns the floor. Its thick wool is woven into a colorful design."
#message 14 "You lift up the rug in several places and look under it. Sad to say, all you see is the dust you swept under there yesterday."
#message 15 "Ok."
#message 16 "You hurriedly return the key to the top of the closet."
#message 17 "Manannan's bedroom window is always open. He likes fresh air."
#message 18 "As comfortable as the bed looks, you have no interest in lying on the hateful wizard's bed."
#message 19 "Manannan is asleep on his great bed. His snores are so loud they rumble off the walls. Be quiet; you wouldn't want to disturb him."
#message 20 "You speak softly to the sleeping wizard. \"Hhrrummph!\" he grumbles sleepily, thumbing his nose as if at a fly. But, soon the snoring resumes again."
#message 21 "This time your words awaken Manannan. A grumpy look comes to his face. \"Don't you have anything better to do, boy, than to come in MY bed chamber and wake me from my peaceful repose?\""
#message 22 "You try to be quiet, but an unfortunate squeak wakes Manannan. He turns in his bed, then sits up, staring angrily at you. \"You know you're to stay out of my things,\" he growls. \"I've no choice but to punish you for this.\""
#message 23 "The back of your hair looks cute."
#message 24 "Wrinkling your nose in disgust, you throw the smelly contents of the chamber pot out the open window. What a way to make a living!"
#message 25 "You already have it."
#message 26 ""
#message 27 "The beveled mirror appears wavy because of imperfections in the glass. %m41"
#message 28 "You're startled to discover an ancient parchment scroll. Its ink has faded, but it seems to be a map. Taking this treasure, you leave everything else exactly as it was."
#message 29 "Manannan's chamber pot is on the floor beside his bed."
#message 30 "You tug at the rug for quite a while... before realizing you're standing on it!"
#message 31 "and wish you hadn't!!"
#message 32 "You are not close enough."
#message 33 "A feeling of great relief spreads over you."
#message 34 "You find baubles and trinkets which do not interest you."
#message 35 "You look inside Manannan's chamber pot..."
#message 36 "Quietly opening the drawer below the closet, you discover..."
#message 37 "In the vanity drawer are many uninteresting items, although the wizard's hand mirror may come in handy. You grab it, then close the drawer."
#message 38 "You bang the drawer against your shins repeatedly. (Try backing up!)"
#message 39 "nothing that interests you."
#message 40 "%m2 There may be something metallic on its top."
#message 41 "There is a small drawer in the front of the mahogany vanity."
#message 42 "The carpet is too big and heavy to carry around."



