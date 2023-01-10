if (isset(newRoom))
{  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 1;  set.horizon(40);  v57 = 58;  v58 = 124;  v32 = 11;  v31 = 54;  v101 = 0;  load.logics(Logic104);  load.view(View35);  load.view(View11);  load.view(View231);  load.sound(Sound6);  load.sound(Sound1);  load.view(View88);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  add.to.pic(View88, 0, 0, 82, 141, 15, 4);  add.to.pic(View88, 0, 1, 123, 140, 15, 4);  add.to.pic(View88, 0, 2, 98, 133, 15, 4);  add.to.pic(View88, 0, 3, 100, 144, 15, 4);  discard.view(View88);  animate.obj(o1);  ignore.horizon(o1);  ignore.blocks(o1);  ignore.objs(o1);  position(o1, 49, 58);  set.view(o1, View231);  draw(o1);  animate.obj(o2);  ignore.horizon(o2);  ignore.blocks(o2);  ignore.objs(o2);  position(o2, 115, 33);  set.view(o2, View231);  draw(o2);  if (v44 == 25)
  {    set(f48);  }  if (isset(f48))
  {    if (previousRoom == 43)
    {      if (v105 <= 0)
      {        v39 = 3;        position(ego, 104, 133);        start.motion(ego);      }      else
      {        set(f229);        load.view.v(v105);        set.view.v(ego, v105);        set.loop.v(ego, v106);        fix.loop(ego);        if (v106 == 3)
        {          position(ego, 52, 143);        }        else
        {          position(ego, 57, 143);        }        set.priority(ego, 15);        set(f35);        program.control();        stop.motion(ego);        set(f46);        draw(ego);        v220 = 5;      }    }    else
    {      if (previousRoom == 9)
      {        if (v44 == 6)
        {          load.view(View24);          v39 = 0;          position(ego, 40, 42);          set(f37);          set.view(ego, View11);          ignore.blocks(ego);          move.obj(ego, 43, 135, 3, f220);          set(f35);          set.priority(ego, 15);          sound(Sound1, f41);          draw(ego);        }        else
        {          set(f228);          ignore.blocks(ego);          reset(f37);          v39 = 1;          position(ego, 30, 42);        }      }    }  }  if (v44 == 30)
  {    position.v(ego, v57, v58);    set(f48);  }  if (isset(f47))
  {    draw(ego);  }  call(Logic104);  show.pic();  return();}if (isset(egoHitSpecial) &&  posn(ego, 35, 143, 55, 167))
{  reset(egoHitSpecial);  if ((egoDir == LEFT ||    egoDir == UP_LEFT ||    egoDir == DOWN_LEFT))
  {    set(f228);    ignore.blocks(ego);  }  else
  {    reset(f228);    observe.blocks(ego);  }}if (isset(f229))
{  set.priority(ego, 15);  set(f35);  v39 = 4;}else
{  if (isset(f228))
  {    v39 = 1;    set.priority(ego, 14);  }  else
  {    release.priority(ego);    if (posn(ego, 92, 139, 119, 139))
    {      v39 = 3;    }    else
    {      if (posn(ego, 58, 90, 96, 109))
      {        v39 = 2;      }      else
      {        v39 = 0;      }    }  }}if (!isset(haveInput))
{  goto(Label1);}if ((said("examine", "book") ||  said("read", "book") ||  said("examine", "abominable", "book")))
{  print("Covered with gold trimmings, the old book's leather cover is cracked "    "and worn, its pages yellowed and brittle. The title, however, is "    "clear: %m32.\"");  print("You eagerly thumb through page after page of what you assume to be "    "magic formulas. The ink of the old handwriting is faint, and barely "    "readable.");  print("Most of the formulas are indecipherable, but a few are in a language "    "you know. You treat the old book with great care as you can tell it "    "contains recipes for some very old and powerful magic spells. Your "    "hands shake as you realize this book could be the key to your escape "    "from the evil Manannan.");}if (v39 != 3)
{  if ((said("book", "anyword") ||    said("anyword", "book") ||    said("book", "anyword", "anyword") ||    said("anyword", "book", "anyword") ||    said("anyword", "anyword", "book") ||    said("lift", "book", "book", "anyword") ||    said("lift", "book", "book", "anyword") ||    said("move", "book", "anyword") ||    said("move", "book") ||    said("lift", "book", "book", "anyword")))
  {    print("You can't reach the book from here.");  }}else
{  if ((said("move", "book", "ii") ||    said("move", "book", "book", "ii") ||    said("examine", "book", "ii") ||    said("read", "book", "ii") ||    said("lift", "book", "ii") ||    said("lift", "book", "book", "ii")))
  {    v102 = 121;  }  if ((said("move", "book", "iv") ||    said("move", "book", "book", "iv") ||    said("examine", "book", "iv") ||    said("read", "book", "iv") ||    said("lift", "book", "iv") ||    said("lift", "book", "book", "iv")))
  {    v102 = 122;  }  if ((said("move", "book", "vii") ||    said("move", "book", "book", "vii") ||    said("examine", "book", "vii") ||    said("read", "book", "vii") ||    said("lift", "book", "vii") ||    said("lift", "book", "book", "vii")))
  {    v102 = 123;  }  if ((said("move", "book", "xiv") ||    said("move", "book", "book", "xiv") ||    said("examine", "book", "xiv") ||    said("read", "book", "xiv") ||    said("lift", "book", "xiv") ||    said("lift", "book", "book", "xiv")))
  {    v102 = 124;  }  if ((said("move", "book", "xxv") ||    said("move", "book", "book", "xxv") ||    said("examine", "book", "xxv") ||    said("read", "book", "xxv") ||    said("lift", "book", "xxv") ||    said("lift", "book", "book", "xxv")))
  {    v102 = 125;  }  if ((said("move", "book", "lxxxiv") ||    said("move", "book", "book", "lxxxiv") ||    said("examine", "book", "lxxxiv") ||    said("read", "book", "lxxxiv") ||    said("lift", "book", "lxxxiv") ||    said("lift", "book", "book", "lxxxiv")))
  {    v102 = 126;  }  if ((said("move", "book", "clxix") ||    said("move", "book", "book", "clxix") ||    said("examine", "book", "clxix") ||    said("read", "book", "clxix") ||    said("lift", "book", "clxix") ||    said("lift", "book", "book", "clxix")))
  {    v102 = 127;  }  if ((said("move", "book", "rol") ||    said("move", "book", "book", "rol") ||    said("examine", "book", "rol") ||    said("read", "book", "rol") ||    said("move", "book", "book", "rol") ||    said("lift", "book", "book", "rol") ||    said("lift", "book", "rol") ||    said("read", "book", "rol")))
  {    print("Not being an experienced sorcerer, most spells in this book are too "      "complicated for you to understand.");  }}if ((said("examine", "area") ||  said("examine", "building") ||  said("examine") ||  said("examine", "lab")))
{  print("You look in awe around this torch-lit underground room. It appears to "    "be a laboratory... a \"wizard's\" laboratory.");  print("Against the earthen walls there are rows of shelves holding numerous "    "jars which contain strange, unknown ingredients.");  print("The shelves also hold skeletons of small animals and birds, some human "    "skulls and bones, and other odd instruments, whose use you do not "    "know. %m8 %m7");}if ((said("examine", "counter") ||  said("examine", "top", "counter") ||  said("examine", "counter", "top")))
{  if (posn(ego, 77, 95, 128, 120))
  {    print("The wizard's desk is curiously empty. You have no further interest "      "in it.");  }  else
  {    print("%m8 Atop the oak table are a large leather-bound book, a mortar and "      "pestle, a little brazier holding charcoal, and a flint, plus "      "measuring cups, beakers, flasks, and stirrers.");  }}if (said("examine", "below", "counter"))
{  print("You lean down and peek under the table. You see nothing but an earthen "    "floor.");}if ((said("examine", "stair") ||  said("examine", "up", "stair")))
{  print("The narrow stone steps lead up to the wizard's study.");}if (said("capture", "flint"))
{  print("The flint%m52");}if (said("examine", "flint"))
{  print("The flint is used for lighting the brazier.");}if (said("examine", "beaker"))
{  print("There are many measuring, stirring, and mixing implements on the "    "laboratory table.");}if (said("capture", "beaker"))
{  print("You consider taking it, but decide there is no need to carry it%m38");}if (said("capture", "charcoal"))
{  print("The charcoal%m52");}if (said("examine", "burn"))
{  print("The burning torches throw flickering shadows across the walls, making "    "the room even more ominous.");}if (said("examine", "bookcase"))
{  print("You curiously gaze at the strange jars of ingredients, the animal and "    "human bones, and other odd implements which line the rows of shelves. "    "You see jars of ingredients resting on labeled shelves... shelves "    "bearing such ghastly names as \"Powdered Fish Bone,\" \"Nightshade "    "Juice,\" \"Mandrake Root Powder,\" \"Saffron,\" \"Toad Spittle,\" and "    "\"Toadstool Powder.\"");}if (said("close", "book"))
{  print("The wizard would notice if the book were closed.");}if (said("lift", "book"))
{  print("It's already open.");}if (said("capture", "book"))
{  if (v128 != 20)
  {    print("Manannan would be very suspicious if he were to discover %m32\" "      "missing.");  }  else
  {    print("There are many measuring, stirring, and mixing implements on the "      "laboratory table.");  }}if ((said("form", "magic") ||  said("cast", "magic") ||  said("knead", "magic") ||  said("form", "magic", "spell") ||  said("cast", "magic", "spell") ||  said("knead", "magic", "spell")))
{  print("You must open %m32\" to the proper page to read the instructions for a "    "magic spell.");}if ((said("examine", "beaker") ||  said("look in", "beaker") ||  said("lift", "beaker") ||  said("capture", "cap", "off", "beaker") ||  said("capture", "cap", "from", "beaker") ||  said("capture", "cap", "beaker")))
{  print("You have no flask.");}if (said("examine", "equipment"))
{  print("There is much equipment here: a mortar and pestle, a charcoal brazier "    "and flint, measuring cups, beakers, flasks, stirrers, and many jars "    "and vials of strange ingredients.");}if (said("capture", "fish oil"))
{  print("Where?");}if ((said("capture", "burn") ||  said("capture", "burn", "off", "cage") ||  said("capture", "burn", "cage") ||  said("capture", "burn", "anyword", "cage")))
{  print("The torches are firmly attached to the earthen wall. You cannot loosen "    "them.");}if (isset(f221))
{  reset(f221);  if ((said("bone", "rol") ||    said("bone", "rol")))
  {    set(f222);  }  if ((said("night shade", "juice") ||    said("night shade")))
  {    set(f223);  }  if ((said("mandrake", "root", "flour") ||    said("mandrake", "flour") ||    said("mandrake") ||    said("mandrake", "root")))
  {    set(f224);  }  if ((said("saffron") ||    said("saffron", "flour")))
  {    set(f227);  }  if ((said("frog", "spit") ||    said("frog") ||    said("spit")))
  {    set(f225);  }  if ((said("mushroom", "flour") ||    said("mushroom")))
  {    set(f226);  }}if (said("anyword", "burn"))
{  print("The torches will not help you.");}if ((said("capture", "bottle", "flour", "from", "bookcase") ||  said("capture", "bottle", "from", "bookcase") ||  said("capture", "bottle", "bookcase") ||  said("capture", "bottle") ||  said("capture", "flour") ||  said("capture", "flour", "bookcase") ||  said("capture", "flour", "from", "bookcase")))
{  if (v39 != 2)
  {    print("You can't reach it from here.");  }  else
  {    if ((obj.in.room("Powdered Fish Bone*", currentRoom) ||      obj.in.room("Nightshade Juice*", currentRoom) ||      obj.in.room("Mandrake Root*", currentRoom) ||      obj.in.room("Toad Spittle*", currentRoom) ||      obj.in.room("Saffron*", currentRoom) ||      obj.in.room("Toadstool Powder*", currentRoom)))
    {      print("There are many jars of ingredients on the laboratory shelves. "        "Which do you want?");      set(f221);    }    else
    {      print("You already have all the jars of ingredients you are likely to "        "need. You have no interest in any other.");    }  }}if ((said("capture", "bone", "rol") ||  said("capture", "bottle", "bone", "rol") ||  said("capture", "bottle", "bone") ||  said("capture", "bone", "bottle", "rol")))
{  if (v39 != 2)
  {    print("You can't reach it from here.");  }  else
  {    set(f222);  }}if ((said("capture", "juice") ||  said("capture", "night shade", "juice") ||  said("capture", "juice", "bookcase") ||  said("capture", "night shade", "juice", "bookcase") ||  said("capture", "juice", "from", "bookcase") ||  said("capture", "bottle", "juice", "from", "bookcase") ||  said("capture", "night shade", "juice", "from", "bookcase") ||  said("capture", "bottle", "night shade", "juice", "bookcase") ||  said("capture", "bottle", "night shade", "juice") ||  said("capture", "bottle", "night shade", "juice", "from", "bookcase") ||  said("capture", "night shade", "juice", "bottle", "bookcase") ||  said("capture", "night shade", "juice", "bottle", "from", "bookcase")))
{  if (v39 != 2)
  {    print("You can't reach it from here.");  }  else
  {    set(f223);  }}if ((said("capture", "mandrake", "flour") ||  said("capture", "mandrake", "flour", "bookcase") ||  said("capture", "mandrake", "flour", "from", "bookcase") ||  said("capture", "mandrake", "flour", "bottle", "bookcase") ||  said("capture", "mandrake", "flour", "bottle", "from", "bookcase") ||  said("capture", "bottle", "mandrake", "flour", "bookcase") ||  said("capture", "bottle", "mandrake", "flour", "from", "bookcase") ||  said("capture", "mandrake") ||  said("capture", "mandrake", "root", "flour") ||  said("capture", "mandrake", "root", "flour", "bookcase") ||  said("capture", "mandrake", "root", "flour", "from", "bookcase") ||  said("capture", "mandrake", "root", "flour", "bottle", "bookcase") ||  said("capture", "mandrake", "root", "flour", "bottle", "from", "bookcase") ||  said("capture", "bottle", "mandrake", "root") ||  said("capture", "bottle", "mandrake", "root", "flour") ||  said("capture", "bottle", "mandrake", "root", "flour", "bookcase") ||  said("capture", "bottle", "mandrake", "root", "flour", "from", "bookcase")))
{  if (v39 != 2)
  {    print("You can't reach it from here.");  }  else
  {    set(f224);  }}if ((said("capture", "saffron") ||  said("capture", "saffron", "bookcase") ||  said("capture", "saffron", "from", "bookcase") ||  said("capture", "saffron", "bottle", "bookcase") ||  said("capture", "saffron", "bottle", "from", "bookcase") ||  said("capture", "bottle", "saffron", "bookcase") ||  said("capture", "bottle", "saffron", "from", "bookcase") ||  said("capture", "bottle", "saffron") ||  said("capture", "bottle", "saffron", "bookcase") ||  said("capture", "bottle", "saffron", "from", "bookcase")))
{  if (v39 != 2)
  {    print("You can't reach it from here.");  }  else
  {    set(f227);  }}if ((said("capture", "mushroom", "flour") ||  said("capture", "mushroom") ||  said("capture", "mushroom", "flour", "bookcase") ||  said("capture", "bottle", "mushroom", "flour", "bookcase") ||  said("capture", "mushroom", "flour", "from", "bookcase") ||  said("capture", "bottle", "mushroom", "flour", "from", "bookcase") ||  said("capture", "bottle", "mushroom", "flour") ||  said("capture", "bottle", "mushroom", "flour", "bookcase") ||  said("capture", "mushroom", "flour", "bottle", "bookcase") ||  said("capture", "mushroom", "flour", "bottle", "from", "bookcase")))
{  if (v39 != 2)
  {    print("You can't reach it from here.");  }  else
  {    set(f226);  }}if ((said("capture", "bottle", "spit", "from", "bookcase") ||  said("capture", "spit") ||  said("capture", "frog", "spit") ||  said("capture", "spit", "bookcase") ||  said("capture", "spit", "from", "bookcase") ||  said("capture", "frog", "spit") ||  said("capture", "frog", "spit", "bookcase") ||  said("capture", "frog", "spit", "from", "bookcase") ||  said("capture", "bottle", "frog", "spit", "from", "bookcase") ||  said("capture", "bottle", "frog", "spit", "bookcase") ||  said("capture", "bottle", "frog", "spit") ||  said("capture", "frog", "spit", "bottle", "from", "bookcase") ||  said("capture", "frog", "spit", "bottle", "bookcase") ||  said("capture", "bottle", "frog", "spit", "bookcase") ||  said("capture", "bottle", "frog", "spit", "from", "bookcase") ||  said("capture", "frog", "spit", "bottle", "from", "bookcase")))
{  if (v39 != 2)
  {    print("You can't reach it from here.");  }  else
  {    set(f225);  }}if ((said("capture", "mortar") ||  said("capture", "mortar", "from", "counter") ||  said("capture", "mortar", "off", "counter")))
{  print("%m36mortar and pestle%m38");}if ((said("examine", "mortar") ||  said("examine", "mortar", "counter") ||  said("look in", "mortar")))
{  if (v39 != 3)
  {    print("You are not close enough.");  }  else
  {    print("The mortar is a bowl-shaped implement made of stone. The pestle is a "      "rounded stone that fits into the mortar. The mortar and pestle are "      "used for grinding things into a powder. They are resting on the oak "      "table.");  }}if (said("try", "mortar"))
{  if (v39 != 3)
  {    print("You can't reach it from here.");  }  else
  {    print("What would you do with the mortar and pestle?");  }}if ((said("crumble", "anyword", "mortar") ||  said("add", "anyword", "mortar")))
{  if (v39 != 3)
  {    print("You can't reach it from here.");  }  else
  {    print("You consider doing that, but then realize it wouldn't work.");  }}if ((said("capture", "brazier") ||  said("capture", "brazier", "from", "counter") ||  said("capture", "brazier", "off", "counter") ||  said("capture", "charcoal", "brazier") ||  said("capture", "charcoal", "brazier", "from", "counter") ||  said("capture", "charcoal", "brazier", "off", "counter")))
{  print("%m36charcoal brazier%m38");}if ((said("try", "brazier") ||  said("try", "charcoal", "brazier")))
{  if (v39 != 3)
  {    print("You can't reach it from here.");  }  else
  {    print("What would you do with the brazier?");  }}if ((said("burn", "brazier") ||  said("burn", "charcoal", "brazier") ||  said("burn", "charcoal")))
{  if (v39 != 3)
  {    print("You can't reach it from here.");  }  else
  {    if ((v107 > 0 ||      v108 > 0))
    {      print("It is already burning.");    }    else
    {      print("You fill the brazier with charcoal from the small supply Manannan "        "keeps here and strike the flint on it. Soon, the brazier burns "        "hotly.");      v108 = 3;    }  }}if ((said("add", "anyword", "on", "brazier") ||  said("add", "anyword", "on", "top", "brazier") ||  said("boil", "anyword", "on", "brazier") ||  said("boil", "anyword", "on", "top", "brazier") ||  said("add", "anyword", "on", "brazier", "boil") ||  said("add", "anyword", "on", "top", "brazier", "boil") ||  said("add", "anyword", "on", "charcoal", "brazier") ||  said("add", "anyword", "on", "top", "charcoal", "brazier") ||  said("boil", "anyword", "on", "charcoal", "brazier") ||  said("boil", "anyword", "on", "top", "charcoal", "brazier") ||  said("add", "anyword", "on", "charcoal", "brazier", "boil") ||  said("add", "anyword", "on", "top", "charcoal", "brazier", "boil")))
{  if (v39 != 3)
  {    print("You can't reach it from here.");  }  else
  {    print("%m50 Now is not the proper time.");  }}if ((said("examine", "brazier") ||  said("examine", "brazier", "counter") ||  said("look in", "brazier") ||  said("examine", "charcoal", "brazier") ||  said("examine", "charcoal", "brazier", "counter") ||  said("look in", "charcoal", "brazier")))
{  if (v39 != 3)
  {    print("You are not close enough.");  }  else
  {    print("Resting on the table is a small metal brazier. It holds charcoal and "      "is used for heating or cooking things.");    if ((v107 > 0 ||      v108 > 0))
    {      print("%m54 You could heat things quickly with the brazier, right now.");    }    else
    {      print("%m66stone cold.");    }  }}if ((said("capture", "charcoal") ||  said("capture", "charcoal", "from", "brazier")))
{  if (v39 != 3)
  {    print("You can't reach it from here.");  }  else
  {    print("The charcoal");  }}if (said("examine", "charcoal"))
{  if (v39 != 3)
  {    print("You are not close enough.");  }  else
  {    if ((v107 > 0 ||      v108 > 0))
    {      print("%m66very hot!");    }    else
    {      print("%m66stone cold.");    }  }}Label1:if (isset(f45) &&  v107 == 1 &&  v108 <= 0)
{  print("The brazier has burned all the charcoal, and is now cool.");}if (isset(f222))
{  reset(f221);  reset(f222);  if (obj.in.room("Powdered Fish Bone*", currentRoom))
  {    print("%m3labeled \"Powdered Fish Bone\"%m12");    get("Powdered Fish Bone*");    currentScore += 1;  }  else
  {    if (has("Powdered Fish Bone*"))
    {      print("You already have it.");    }    else
    {      print("You already took it.");    }  }}if (isset(f223))
{  reset(f221);  reset(f223);  if (obj.in.room("Nightshade Juice*", currentRoom))
  {    print("%m3of \"Nightshade Juice\"%m12");    get("Nightshade Juice*");    currentScore += 1;  }  else
  {    if (has("Nightshade Juice*"))
    {      print("You already have it.");    }    else
    {      print("You already took it.");    }  }}if (isset(f224))
{  reset(f221);  reset(f224);  if (obj.in.room("Mandrake Root*", currentRoom))
  {    print("%m3labeled \"Mandrake Root Powder\"%m12");    get("Mandrake Root*");    currentScore += 1;  }  else
  {    if (has("Mandrake Root*"))
    {      print("You already have it.");    }    else
    {      print("You already took it.");    }  }}if (isset(f227))
{  reset(f221);  reset(f227);  if (obj.in.room("Saffron*", currentRoom))
  {    print("%m3labeled \"Saffron\"%m12");    get("Saffron*");    currentScore += 1;  }  else
  {    if (has("Saffron*"))
    {      print("You already have it.");    }    else
    {      print("You already took it.");    }  }}if (isset(f225))
{  reset(f221);  reset(f225);  if (obj.in.room("Toad Spittle*", currentRoom))
  {    print("%m3labeled \"Toad Spittle\"%m12");    get("Toad Spittle*");    currentScore += 1;  }  else
  {    if (has("Toad Spittle*"))
    {      print("You already have it.");    }    else
    {      print("You already took it.");    }  }}if (isset(f226))
{  reset(f221);  reset(f226);  if (obj.in.room("Toadstool Powder*", currentRoom))
  {    print("%m3of \"Toadstool Powder\"%m12");    get("Toadstool Powder*");    currentScore += 1;  }  else
  {    if (has("Toadstool Powder*"))
    {      print("You already have it.");    }    else
    {      print("You already took it.");    }  }}if (isset(egoHitSpecial))
{  if (v39 == 1)
  {    set(f37);    set.view(ego, View11);    ignore.blocks(ego);    move.obj(ego, 43, 135, 3, f220);    set(f35);    set.priority(ego, 15);    sound(Sound1, f41);    program.control();  }}if (isset(f220))
{  reset(f220);  if (v44 == 6)
  {    set.view(ego, View24);    reset(f35);    stop.cycling(ego);    set(f44);  }  else
  {    set.view(ego, View35);    stop.motion(ego);    v36 = 0;    step.size(ego, v36);    stop.sound();    v221 = 5;    v44 = 18;    set(f230);  }}if (isset(f45))
{  --v221;  if (v221 == 1)
  {    player.control();    accept.input();    reset(f46);    reset(f35);    reset(f230);    stop.sound();    start.motion(ego);    v44 = 0;    set.view(ego, View0);    v36 = 1;    step.size(ego, v36);    reset(f37);    observe.blocks(ego);    release.priority(ego);    reset(f228);  }}if (isset(f230) &&  v44 == 18)
{  sound(Sound6, f230);}if (isset(f45))
{  --v220;  if (isset(f229) &&    v220 == 1)
  {    set(f44);    start.cycling(ego);    if (v105 == 38)
    {      v68 = 57;    }    else
    {      v68 = 61;    }    v68 += v106;    print.v(v68);    if (v68 == 60)
    {      v36 = 3;      cycle.time(ego, v36);    }  }}if (v44 != 125)
{  if (edgeEgoHit == TOP_EDGE &&    v44 == 25 &&    v40 > 46 &&    v40 < 75)
  {    new.room(Logic9);  }  if (edgeEgoHit == TOP_EDGE)
  {    new.room(Logic9);  }}if (v102 > 0)
{  print("With trembling hands you turn the pages of %m32,\" and prepare to "    "follow its instructions precisely.");  new.room(Logic43);}call(Logic104);return();[Messages#message 1 "Where?"#message 2 "Not being an experienced sorcerer, most spells in this book are too complicated for you to understand."#message 3 "You remove the jar "#message 4 "You look in awe around this torch-lit underground room. It appears to be a laboratory... a \"wizard's\" laboratory."#message 5 "%m50 Now is not the proper time."#message 6 "The shelves also hold skeletons of small animals and birds, some human skulls and bones, and other odd instruments, whose use you do not know. %m8 %m7"#message 7 "The narrow stone steps lead up to the wizard's study."#message 8 "Against the earth wall is a massive oak table with a spacious worktop."#message 9 "%m8 Atop the oak table are a large leather-bound book, a mortar and pestle, a little brazier holding charcoal, and a flint, plus measuring cups, beakers, flasks, and stirrers."#message 10 "You can't reach the book from here."#message 11 "You lean down and peek under the table. You see nothing but an earthen floor."#message 12 " from the laboratory shelf and carry it with you."#message 13 "The flint%m52"#message 14 "The burning torches throw flickering shadows across the walls, making the room even more ominous."#message 15 "The torches are firmly attached to the earthen wall. You cannot loosen them."#message 16 "You curiously gaze at the strange jars of ingredients, the animal and human bones, and other odd implements which line the rows of shelves. You see jars of ingredients resting on labeled shelves... shelves bearing such ghastly names as \"Powdered Fish Bone,\" \"Nightshade Juice,\" \"Mandrake Root Powder,\" \"Saffron,\" \"Toad Spittle,\" and \"Toadstool Powder.\""#message 17 "You can't reach it from here."#message 18 "%m3labeled \"Saffron\"%m12"#message 19 "You already took it."#message 20 "The wizard's desk is curiously empty. You have no further interest in it."#message 21 "You have no flask."#message 22 "Manannan would be very suspicious if he were to discover %m32\" missing."#message 23 "There is much equipment here: a mortar and pestle, a charcoal brazier and flint, measuring cups, beakers, flasks, stirrers, and many jars and vials of strange ingredients."#message 24 "The charcoal%m52"#message 25 "The flint is used for lighting the brazier."#message 26 "The torches will not help you."#message 27 "There are many jars of ingredients on the laboratory shelves. Which do you want?"#message 28 "You already have all the jars of ingredients you are likely to need. You have no interest in any other."#message 29 "%m3labeled \"Powdered Fish Bone\"%m12"#message 30 "With trembling hands you turn the pages of %m32,\" and prepare to follow its instructions precisely."#message 31 "%m3of \"Nightshade Juice\"%m12"#message 32 "\"The Sorcery of Old"#message 33 "%m3labeled \"Mandrake Root Powder\"%m12"#message 34 "Against the earthen walls there are rows of shelves holding numerous jars which contain strange, unknown ingredients."#message 35 "%m3of \"Toadstool Powder\"%m12"#message 36 "There is no need for you to carry the "#message 37 "%m3labeled \"Toad Spittle\"%m12"#message 38 " around with you. It will remain on the table for you to use as you wish."#message 39 "%m36mortar and pestle%m38"#message 40 "%m36charcoal brazier%m38"#message 41 "The mortar is a bowl-shaped implement made of stone. The pestle is a rounded stone that fits into the mortar. The mortar and pestle are used for grinding things into a powder. They are resting on the oak table."#message 42 "What would you do with the mortar and pestle?"#message 43 "Resting on the table is a small metal brazier. It holds charcoal and is used for heating or cooking things."#message 44 "It's already open."#message 45 "What would you do with the brazier?"#message 46 "The wizard would notice if the book were closed."#message 47 "You are not close enough."#message 48 "You fill the brazier with charcoal from the small supply Manannan keeps here and strike the flint on it. Soon, the brazier burns hotly."#message 49 "The charcoal"#message 50 "You consider doing that, but then realize it wouldn't work."#message 51 "%m54 You could heat things quickly with the brazier, right now."#message 52 " belongs here. You have no need for it elsewhere."#message 53 "%m66stone cold."#message 54 "%m66very hot!"#message 55 "The brazier has burned all the charcoal, and is now cool."#message 56 "It is already burning."#message 57 "You're all ears now, Gwydion!"#message 58 "Oooooooh, Gwydion! What big eyes you have!!"#message 59 "It appears that stone has a flaw."#message 60 "Night-night, Gwydion."#message 61 "That was a-mew-sing, Gwydion."#message 62 "There's no silver lining in this cloud, Gwydion."#message 63 "Gwydion! Oh, Gwydion!!\n\n(What Gwydion? Where??)"#message 64 "You have no need for it."#message 65 "There are many measuring, stirring, and mixing implements on the laboratory table."#message 66 "The charcoal in the metal brazier is "#message 67 "You already have it."#message 68 "You must open %m32\" to the proper page to read the instructions for a magic spell."#message 69 "Covered with gold trimmings, the old book's leather cover is cracked and worn, its pages yellowed and brittle. The title, however, is clear: %m32.\""#message 70 "You eagerly thumb through page after page of what you assume to be magic formulas. The ink of the old handwriting is faint, and barely readable."#message 71 "Most of the formulas are indecipherable, but a few are in a language you know. You treat the old book with great care as you can tell it contains recipes for some very old and powerful magic spells. Your hands shake as you realize this book could be the key to your escape from the evil Manannan."#message 72 "You consider taking it, but decide there is no need to carry it%m38"
