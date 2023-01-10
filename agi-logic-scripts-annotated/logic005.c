if (isset(newRoom))
{  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 1;  v57 = 88;  v58 = 143;  v32 = 70;  v31 = 130;  v100 = 44;  v101 = 145;  load.logics(Logic104);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.view(View32);  load.view(View92);  load.view(View93);  load.view(View175);  load.view(View174);  if ((v127 == 1 ||    v127 == 3) &&    v137 <= 0 &&    v128 != 20)
  {    random(1, 2, v36);    if (v36 == 1)
    {      load.logics(Logic105);      set(f98);      load.view(View196);      random(1, 2, v36);      if (v36 == 1)
      {        set(f225);        set(f222);        v125 = 0;      }      else
      {        random(6, 12, v125);      }    }  }  animate.obj(o1);  ignore.blocks(o1);  ignore.objs(o1);  position(o1, 23, 154);  set.view(o1, View92);  set.cel(o1, 0);  set.priority(o1, 14);  v36 = 2;  cycle.time(o1, v36);  draw(o1);  stop.cycling(o1);  stop.update(o1);  animate.obj(o2);  ignore.blocks(o2);  ignore.objs(o2);  position(o2, 95, 143);  set.view(o2, View93);  set.priority(o2, 4);  stop.cycling(o2);  v36 = 2;  cycle.time(o2, v36);  if (v95 == 2)
  {    last.cel(o2, v36);    set.cel.v(o2, v36);  }  else
  {    set.cel(o2, 0);  }  draw(o2);  stop.update(o2);  animate.obj(o3);  ignore.horizon(o3);  ignore.blocks(o3);  ignore.objs(o3);  position(o3, 123, 127);  set.view(o3, View175);  stop.cycling(o3);  v36 = 2;  cycle.time(o3, v36);  if (v95 == 0)
  {    set.cel(o3, 0);  }  else
  {    last.cel(o3, v36);    set.cel.v(o3, v36);  }  draw(o3);  stop.update(o3);  animate.obj(o4);  ignore.blocks(o4);  ignore.objs(o4);  position(o4, 18, 134);  set.view(o4, View174);  set.priority(o4, 14);  draw(o4);  stop.update(o4);  if (v44 == 25)
  {    set(f48);  }  if (isset(f48))
  {    if (previousRoom == 9)
    {      position(ego, 107, 125);      set.loop(ego, 0);      start.motion(ego);    }    else
    {      if (previousRoom == 7)
      {        position(ego, 96, 167);      }      else
      {        position.v(ego, v57, v58);      }    }  }  if (isset(f47))
  {    draw(ego);  }  if (isset(f98))
  {    v101 = 0;    call(Logic105);    if (isset(f222))
    {      v128 = 102;      v32 = 48;      v31 = 117;      set.view(o15, View196);      v36 = 2;      cycle.time(o15, v36);      set.cel(o15, 0);      stop.cycling(o15);      set.priority(o15, 13);      ignore.blocks(o15);      block(0, 0, 64, 133);      position.v(o15, v32, v31);      draw(o15);      set(f99);      v220 = 2;    }  }  call(Logic104);  ignore.objs(o13);  show.pic();  if (isset(f222))
  {    sound(Sound27, f41);    print.at("The wizard is writing at his desk. He looks up from his work, and "      "greets you with a scowl. \"Boy, you know I don't like you to "      "enter my private study, especially when I'm writing,\" he growls. "      "\"Leave now, or I'll make you leave!\"", 2, 2, 37);    v129 = 4;  }  return();}if (posn(ego, 23, 155, 32, 166))
{  v39 = 1;}else
{  if (posn(ego, 113, 125, 121, 140))
  {    v39 = 2;  }  else
  {    if (posn(ego, 36, 125, 67, 131))
    {      v39 = 3;    }    else
    {      v39 = 0;    }  }}if (!isset(haveInput))
{  goto(Label1);}if ((said("examine", "area") ||  said("examine", "building") ||  said("examine") ||  said("examine", "office")))
{  print("Manannan is very private with his study, and doesn't like you poking "    "around. The huge oak desk is covered with his writing implements. An "    "oak cabinet is in the corner. There is a chart on the rear wall. The "    "bookshelves are filled with books on every subject; the wizard fancies "    "himself to be quite a scholar.");}if ((said("examine", "basket") ||  said("look in", "basket")))
{  print("Don't you remember... you emptied it yesterday.");}if ((said("examine", "chart") ||  said("examine", "chart", "on", "cage") ||  said("examine", "chart", "cage")))
{  print("The chart has no meaning to you.");}if ((said("examine", "counter") ||  said("examine", "bench")))
{  print("The massive desk is made from oak. The wizard does all of his reading, "    "writing, and calculating here.");}if ((said("examine", "top", "counter") ||  said("examine", "on", "counter") ||  said("examine", "above", "counter")))
{  print("The desk is covered with the wizard's writing implements: quill pens, "    "jars of oak bark ink, and parchment paper. Manannan is a prolific "    "writer, recording his many ideas and formulas.");}if ((said("lift", "counter") ||  said("lift", "drawer", "counter") ||  said("lift", "drawer") ||  said("lift", "counter", "drawer") ||  said("examine", "inside", "counter") ||  said("examine", "drawer") ||  said("examine", "inside", "drawer")))
{  if (v39 != 3)
  {    print("You are not close enough.");  }  else
  {    if (isset(f99))
    {      print("The wizard wouldn't appreciate that.");    }    else
    {      print("You open the large desk's only drawer; but, you see nothing "        "interesting. Before you're caught, you close it.");    }  }}if (said("examine", "cabinet"))
{  print("The oak cabinet has a brass handle on its door. Your feather duster is "    "lying on its top.");}if ((said("unlock", "cabinet", "try", "key") ||  said("unlock", "cabinet") ||  said("unlock", "cabinet", "key") ||  said("unlock", "door") ||  said("unlock", "door", "try", "key") ||  said("lift", "cabinet") ||  said("lift", "cabinet", "try", "key") ||  said("lift", "cabinet", "key") ||  said("lift", "cabinet", "door") ||  said("lift", "door", "cabinet") ||  said("lift", "door") ||  said("examine", "inside", "cabinet") ||  said("look in", "cabinet") ||  said("look in", "door", "cabinet") ||  said("look in", "cabinet", "door") ||  said("try", "key", "unlock", "cabinet") ||  said("try", "key", "cabinet") ||  said("try", "key", "unlock", "door") ||  said("try", "key", "lift", "cabinet")))
{  if (v39 != 1)
  {    print("You are not close enough.");  }  else
  {    if (!has("Brass Key*"))
    {      print("You try to turn the handle, but, unfortunately, the door is "        "locked.");    }    else
    {      print("You unlock the oaken cabinet using the brass key.");      v223 = 44;      if (has("Magic Wand*"))
      {        set(f220);      }    }  }}if (has("Magic Wand*") &&  (said("add", "rod", "cabinet") ||    said("add", "rod", "back", "cabinet") ||    said("add", "rod", "back") ||    said("add", "magic", "rod", "back", "cabinet") ||    said("add", "magic", "rod", "cabinet")))
{  if (v39 != 1)
  {    print("You are not close enough.");  }  else
  {    if (!has("Brass Key*"))
    {      print("You try to turn the handle, but, unfortunately, the door is "        "locked.");    }    else
    {      print("You unlock the oaken cabinet using the brass key.");      set(f220);      v223 = 44;    }  }}if ((said("examine", "above", "cabinet") ||  said("examine", "top", "cabinet") ||  said("examine", "on", "cabinet") ||  said("examine", "on", "cabinet", "top") ||  said("examine", "cabinet", "top") ||  said("examine", "on", "above", "cabinet")))
{  print("There is just your feather duster on the cabinet.");}if (!isset(f46) &&  (said("capture", "duster") ||    said("clean", "furnishings") ||    said("clean", "area") ||    said("clean", "office") ||    said("capture", "feather", "duster")))
{  if (v39 != 1)
  {    print("You are not close enough.");  }  else
  {    v222 = 0;    set(f122);  }}if (said("examine", "bookcase"))
{  print("So many books line the bookshelf, you wonder when Manannan has time to "    "read them all. Titles cover many subjects: from \"Ancient Arabic "    "Mythology,\" to \"A Study of the Heavens,\" to \"The Philosophies of "    "Socrates.\"");}if (said("examine", "book"))
{  if (v39 == 2)
  {    print("Carefully examining the bookshelf, you notice a glint of metal "      "behind one huge volume.");  }  else
  {    print("So many books line the bookshelf, you wonder when Manannan has time "      "to read them all. Titles cover many subjects: from \"Ancient Arabic "      "Mythology,\" to \"A Study of the Heavens,\" to \"The Philosophies of "      "Socrates.\"");  }}if ((said("capture", "book") ||  said("capture", "book", "from", "bookcase") ||  said("capture", "book", "off", "bookcase") ||  said("capture", "book", "bookcase")))
{  if (v95 == 0)
  {    print("You glance at the titles of the books, but do not see any that "      "interest you. Wait... was that a glint of metal behind one large "      "book?");  }  else
  {    if (v95 == 1)
    {      print("You glance at the books, but see no others that interest you.");    }    else
    {      reset(haveMatch);    }  }}if ((said("examine", "glint")))
{  print("There may be something metallic behind that large book.");}if ((said("move", "book") ||  said("examine", "back", "book")))
{  if (v39 != 2)
  {    print("You are not close enough.");  }  else
  {    if (isset(f99))
    {      v95 = 1;    }    else
    {      v224 = 44;    }  }}if ((said("add", "book", "back") ||  said("add", "book", "back", "bookcase") ||  said("move", "book", "back") ||  said("move", "book", "back", "on", "bookcase") ||  said("add", "book", "back", "on", "bookcase")))
{  if (v39 != 2)
  {    print("You are not close enough.");  }  else
  {    v224 = 44;  }}if (said("examine", "handle"))
{  if (v95 == 0)
  {    print("You look everywhere in the room, but do not see a lever.");  }  else
  {    print("The metal lever is attached to the back of the bookshelf.");  }}if (said("capture", "handle"))
{  if (v95 == 0)
  {    print("You look everywhere in the room, but do not see a lever.");  }  else
  {    print("%m22 You cannot take it.");  }}if ((said("examine", "hatch") ||  said("examine", "down", "hatch") ||  said("look in", "hatch")))
{  if (v95 == 2)
  {    print("Peering into the dark, frightening trapdoor, you see treacherous "      "stone steps.");  }  else
  {    print("You look closely at the floor, but do not see any signs of one.");  }}if ((said("move", "handle") ||  said("move", "on", "handle")))
{  if (v39 != 2)
  {    print("You are not close enough.");  }  else
  {    if (v95 == 1)
    {      v95 = 2;      v225 = 44;      if (!isset(f95))
      {        set(f95);        currentScore += 5;      }    }    else
    {      if (v95 == 2)
      {        v95 = 1;        v225 = 44;      }      else
      {        reset(haveMatch);      }    }  }}if (isset(f99) &&  !isset(f109))
{  if (said("call", "enchanter") &&    isset(f222))
  {    ++v129;  }}Label1:--v224;if (v224 == 43)
{  start.update(o3);  if (v95 == 0)
  {    v95 = 1;    end.of.loop(o3, f41);  }  else
  {    if (v95 == 1)
    {      v95 = 0;      reverse.loop(o3, f41);    }    else
    {      v224 = 22;    }  }}if (v224 == 11)
{  if (v95 == 1)
  {    print("You push the large book aside, revealing a metal lever attached to "      "the back of the bookshelf.");  }  else
  {    if (v95 == 0)
    {      print("You move the big book back where you found it so it again conceals "        "the metal lever.");      if (v128 != 20)
      {        print("You don't want the old wizard to grow suspicious of your "          "activities.");      }    }    else
    {      print("Before you replace the book, you'd better shut the trapdoor.");      v224 = 1;    }  }}if (v224 == 1)
{  stop.update(o3);}--v223;if (v223 == 43)
{  start.update(o1);  end.of.loop(o1, f41);  stop.motion(ego);  prevent.input();}if (v223 == 22)
{  if (isset(f220))
  {    reset(f220);    print("You carefully replace the magic wand exactly as you found it.");    put("Magic Wand*", currentRoom);  }  else
  {    if (!obj.in.room("Magic Wand*", currentRoom))
    {      print("You find it is empty.");    }    else
    {      print("Inside, you find the wizard's magic wand.");      if (v128 != 20)
      {        print("You take it with you, knowing it could mean death if he finds it "          "missing.");      }      get("Magic Wand*");      if (!isset(f94))
      {        set(f94);        currentScore += 4;      }    }  }}if (v223 == 1)
{  reverse.loop(o1, f223);}if (isset(f223))
{  reset(f223);  stop.update(o1);  print("After closing the door, you carefully relock it.");  start.motion(ego);  accept.input();}--v225;if (v225 == 43)
{  start.update(o2);  stop.motion(ego);  prevent.input();  if (v95 == 2)
  {    end.of.loop(o2, f41);  }  if (v95 == 1)
  {    reverse.loop(o2, f41);  }}if (v225 == 22)
{  if (v95 == 2)
  {    print("A trapdoor opens, revealing steep stone steps leading into darkness.");  }  if (v95 == 1)
  {    print("The trapdoor groans shut, disappearing into the floorboards.");  }}if (v225 == 1)
{  start.motion(ego);  accept.input();  if (v95 == 1)
  {    set.priority(o2, 4);    stop.update(o2);  }}if (v95 == 2)
{  block(88, 126, 112, 144);  set.priority(o2, 12);  start.update(o2);}else
{  if (isset(f222))
  {    block(0, 0, 64, 133);  }  else
  {    unblock();  }}if (isset(f99) &&  !isset(f109))
{  if (!isset(f225))
  {    set(f225);    v124 = 0;    set(f101);  }  if (isset(f101))
  {    reset(f101);    ++v124;    if (v124 == 1)
    {      move.obj(o15, 51, 130, 1, f101);    }    if (v124 == 2)
    {      set(f222);      reposition.to(o15, 48, 117);      v36 = 1;      cycle.time(o15, v36);      set.view(o15, View196);      set.priority(o15, 13);      v220 = 2;    }  }  if (isset(f222))
  {    --v220;    if (v220 == 21)
    {      start.cycling(o15);    }    if (v220 == 1)
    {      v220 = 66;      stop.cycling(o15);    }  }  if (!isset(f109) &&    (isset(f117) ||      v95 > 0 ||      v224 > 0 ||      v225 > 0 ||      v223 > 0))
  {    print("Caught in the act! You can see his rage building as the wizard's "      "face turns red behind his white beard and his eyes bulge alarmingly. "      "He roars at you, \"You know you're not allowed to sneak around in my "      "private study!\"");    v123 = 15;    set(f130);  }}if (isset(f45))
{  --v227;  if (v227 == 1)
  {    v227 = 0;    v226 = 0;    set(f122);    v222 = 4;  }}--v226;if (v226 == 1)
{  set(f122);}if (isset(f122))
{  reset(f122);  ++v222;  v69 = 1;  set(f35);  program.control();  prevent.input();  set(f46);  if (v222 == 1)
  {    start.update(o4);    erase(o4);    v227 = 22;    get.posn(ego, v80, v81);    ignore.objs(ego);    v37 = 40;    move.obj.v(ego, v37, v81, v69, f122);    if (v137 == 4)
    {      v137 = 0;      v109 = 0;      v110 = 0;    }  }  if (v222 == 2)
  {    move.obj(ego, 40, 145, 1, f122);  }  if (v222 == 3)
  {    set.view(ego, View32);    set.loop(ego, 0);    fix.loop(ego);    random(26, 63, v37);    move.obj.v(ego, v37, v41, v69, f122);  }  if (v222 == 4)
  {    random(6, 33, v226);    set.loop(ego, 1);    fix.loop(ego);    v222 = 2;  }  if (v222 == 5)
  {    set.loop(ego, 0);    fix.loop(ego);    move.obj(ego, 40, 145, 1, f122);  }  if (v222 == 6)
  {    set.view(ego, View0);    release.loop(ego);    move.obj.v(ego, v40, v81, v69, f122);  }  if (v222 == 7)
  {    move.obj.v(ego, v80, v41, v69, f122);  }  if (v222 == 8)
  {    player.control();    accept.input();    reset(f46);    reset(f35);    set.view(ego, View0);    v44 = 0;    observe.objs(ego);    v222 = 0;    draw(o4);    stop.update(o4);  }}if (posn(ego, 94, 125, 102, 126) &&  v44 == 0 &&  v95 == 2)
{  new.room(Logic9);}if (posn(ego, 94, 140, 106, 152) &&  v44 == 25 &&  v95 == 2)
{  new.room(Logic9);}if (edgeEgoHit == BOTTOM_EDGE &&  v44 != 125 &&  v40 > 92 &&  v40 < 105)
{  new.room(Logic7);}call(Logic104);if (isset(f98))
{  call(Logic105);}if (isset(f99) &&  isset(f222))
{  v32 = 59;  v31 = 125;}if (isset(f99) &&  !isset(f109) &&  v123 > 0)
{  program.control();  stop.motion(ego);  reset(f35);  reset(f98);  if (isset(f222))
  {    reset(f222);    set.view(o15, View190);    reset(f46);    reposition.to(o15, 59, 125);    set.priority(o15, 11);    v32 = 59;    v31 = 125;  }}return();[Messages#message 1 "Manannan is very private with his study, and doesn't like you poking around. The huge oak desk is covered with his writing implements. An oak cabinet is in the corner. There is a chart on the rear wall. The bookshelves are filled with books on every subject; the wizard fancies himself to be quite a scholar."#message 2 "You already have it."#message 3 "You are not close enough."#message 4 "The massive desk is made from oak. The wizard does all of his reading, writing, and calculating here."#message 5 "The desk is covered with the wizard's writing implements: quill pens, jars of oak bark ink, and parchment paper. Manannan is a prolific writer, recording his many ideas and formulas."#message 6 "You open the large desk's only drawer; but, you see nothing interesting. Before you're caught, you close it."#message 7 "The oak cabinet has a brass handle on its door. Your feather duster is lying on its top."#message 8 "The chart has no meaning to you."#message 9 "There is just your feather duster on the cabinet."#message 10 "You try to turn the handle, but, unfortunately, the door is locked."#message 11 "Inside, you find the wizard's magic wand."#message 12 "You unlock the oaken cabinet using the brass key."#message 13 "You find it is empty."#message 14 "Carefully examining the bookshelf, you notice a glint of metal behind one huge volume."#message 15 "So many books line the bookshelf, you wonder when Manannan has time to read them all. Titles cover many subjects: from \"Ancient Arabic Mythology,\" to \"A Study of the Heavens,\" to \"The Philosophies of Socrates.\""#message 16 "After closing the door, you carefully relock it."#message 17 "You glance at the titles of the books, but do not see any that interest you. Wait... was that a glint of metal behind one large book?"#message 18 "You glance at the books, but see no others that interest you."#message 19 "You push the large book aside, revealing a metal lever attached to the back of the bookshelf."#message 20 "You move the big book back where you found it so it again conceals the metal lever."#message 21 "Don't you remember... you emptied it yesterday."#message 22 "The metal lever is attached to the back of the bookshelf."#message 23 "You look closely at the floor, but do not see any signs of one."#message 24 "Peering into the dark, frightening trapdoor, you see treacherous stone steps."#message 25 "You take it with you, knowing it could mean death if he finds it missing."#message 26 "You look everywhere in the room, but do not see a lever."#message 27 "%m22 You cannot take it."#message 28 "A trapdoor opens, revealing steep stone steps leading into darkness."#message 29 "The trapdoor groans shut, disappearing into the floorboards."#message 30 "The wizard wouldn't appreciate that."#message 31 "You carefully replace the magic wand exactly as you found it."#message 32 "Caught in the act! You can see his rage building as the wizard's face turns red behind his white beard and his eyes bulge alarmingly. He roars at you, \"You know you're not allowed to sneak around in my private study!\""#message 33 "Before you replace the book, you'd better shut the trapdoor."#message 34 "The wizard is writing at his desk. He looks up from his work, and greets you with a scowl. \"Boy, you know I don't like you to enter my private study, especially when I'm writing,\" he growls. \"Leave now, or I'll make you leave!\""#message 35 "You don't want the old wizard to grow suspicious of your activities."#message 36 "There may be something metallic behind that large book."
