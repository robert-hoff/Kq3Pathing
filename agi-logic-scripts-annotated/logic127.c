if (isset(newRoom))
{  v240 = 143;  return();}if ((!isset(haveInput) ||  isset(haveMatch)))
{  goto(Label1);}set(f120);++v103;if (said("carve", "cactii", "try", "dagger") || said("carve", "lift", "cactii", "try", "dagger"))
{  if (!has("Cactus*") || !has("Knife"))
  {    print("How can you use that which you do not have?");  }  else
  {    print("Using your kitchen carving knife, you cut a gash in the small "      "cactus. Juice begins to drip.");    if (v103 == 1)
    {      reset(f120);    }  }}

if (said("flatten", "cactii", "juice", "on", "ladle") ||    said("flatten", "cactii", "on", "ladle") ||    said("flatten", "cactii", "juice", "ladle") ||    said("flatten", "cactii", "ladle"))
{  if (!has("Cactus*"))
  {    print("How can you use that which you do not have?");  }  else
  {    print("Grabbing one of the measuring spoons from the oaken table, you grasp "      "the slit cactus in your hand, and squeeze it until you have a "      "spoonful of cactus juice. The small cactus is quite devoid of liquid "      "now, so you toss it away.");    drop("Cactus*");    if (v103 == 2)
    {      reset(f120);    }  }}
if (said("add", "one", "ladle", "cactii", "juice", "basin") ||    said("add", "ladle", "cactii", "juice", "basin") ||    said("add", "cactii", "juice", "basin") ||    said("drain", "one", "ladle", "cactii", "juice", "basin") ||    said("drain", "ladle", "cactii", "juice", "basin") ||    said("drain", "cactii", "juice", "basin"))
{  if (!has("Bowl"))
  {    print("How can you use that which you do not have?");  }  else
  {    print("You carefully add the spoonful of cactus juice to the bowl.");    if (v103 == 3)
    {      reset(f120);    }  }}
if (said("add", "one", "cup", "lard", "basin") ||    said("add", "cup", "lard", "basin") ||    said("add", "lard", "basin") ||    said("add", "one", "cup", "lard", "basin"))
{  if (!has("Lard*"))
  {    print("How can you use that which you do not have?");  }  else
  {    print("You scrape the lard into the mixing bowl, and keep the now-empty jar "      "nearby to store your finished formula.");    drop("Lard*");    get("Empty Lard Jar*");    if (v103 == 4)
    {      reset(f120);    }  }}if ((said("add", "two", "add", "frog", "spit", "basin") ||  said("add", "two", "add", "frog", "spit") ||  said("add", "frog", "spit", "basin") ||  said("add", "frog", "spit", "basin") ||  said("add", "frog", "spit")))
{  if (!has("Toad Spittle*"))
  {    print("How can you use that which you do not have?");  }  else
  {    print("You cautiously pour the two drops of toad spittle into the bowl.");    drop("Toad Spittle*");    if (v103 == 5)
    {      reset(f120);    }  }}if ((said("knead", "compound", "ladle") ||  said("knead", "compound", "try", "ladle") ||  said("knead", "basin", "try", "ladle") ||  said("knead", "ladle") ||  said("try", "ladle", "knead", "compound") ||  said("try", "ladle", "knead") ||  said("try", "ladle", "knead", "basin")))
{  print("Using one of the stirrers lying on the table, you mix the lard, cactus "    "juice, and toad spittle until it is smooth and blended.");  if (v103 == 6)
  {    reset(f120);    ++v103;  }}if ((said("aim", "rod") ||  said("aim", "magic", "rod")))
{  if (!has("Magic Wand*"))
  {    print("How can you use that which you do not have?");  }  else
  {    print("You wave the magic wand.");    if (v103 == 8)
    {      reset(f120);    }  }}if ((said("add", "ointment", "bottle") ||  said("add", "ointment", "drain", "bottle") ||  said("add", "ointment", "back", "bottle") ||  said("add", "ointment", "drain", "lard", "bottle")))
{  if (v103 == 9)
  {    print("You scoop the invisibility ointment out of the clay bowl and return "      "it to the lard jar.");    drop("Empty Lard Jar*");    get("Invisibility Ointment*");    reset(f120);  }}Label1:if (!isset(f120) &&  v104 < 4 &&  v103 == 7)
{  set(f120);  prevent.input();  set.text.attribute(BLACK, WHITE);  set.string(s1, " ");  if (v104 == 0)
  {    overlay.pic(v240);    show.pic();    set.string(s2, "cactus plant and horny toad,");    if (monitorType == MONO)
    {      open.dialogue();      get.string(s1, " ", 15, 1, 28);    }    else
    {      get.string(s1, " ", 13, 1, 28);    }    if (compare.strings(s1, s2))
    {      reset(f120);    }  }  if (v104 == 1)
  {    set.string(s2, "i now start down a dangerous road.");    if (monitorType == MONO)
    {      get.string(s1, " ", 16, 1, 34);    }    else
    {      get.string(s1, " ", 14, 1, 34);    }    if (compare.strings(s1, s2))
    {      reset(f120);    }  }  if (v104 == 2)
  {    set.string(s2, "combine with fire and mist to make");    if (monitorType == MONO)
    {      get.string(s1, " ", 17, 1, 34);    }    else
    {      get.string(s1, " ", 15, 1, 34);    }    if (compare.strings(s1, s2))
    {      reset(f120);    }  }  if (v104 == 3)
  {    set.string(s2, "me disappear without a trace.");    if (monitorType == MONO)
    {      get.string(s1, " ", 18, 1, 29);    }    else
    {      get.string(s1, " ", 16, 1, 29);    }    if (compare.strings(s1, s2))
    {      reset(f120);    }  }  set.text.attribute(WHITE, BLACK);  ++v104;  set.string(s1, " ");  set.string(s2, " ");  if ((isset(f120) ||    v104 == 4))
  {    if (monitorType == MONO)
    {      close.dialogue();    }    draw.pic(currentRoom);    show.pic();    accept.input();  }}v36 = v103;++v36;if (v36 == 10 &&  !isset(f120))
{  v103 = 255;}if (isset(f120))
{  v105 = 39;  v106 = 2;}return();[Messages#message 1 "How can you use that which you do not have?"#message 2 " "#message 3 "]"#message 4 "cactus plant and horny toad,"#message 5 "i now start down a dangerous road."#message 6 "combine with fire and mist to make"#message 7 "me disappear without a trace."#message 8 ""#message 9 ""#message 10 ""#message 11 "Using your kitchen carving knife, you cut a gash in the small cactus. Juice begins to drip."#message 12 "Grabbing one of the measuring spoons from the oaken table, you grasp the slit cactus in your hand, and squeeze it until you have a spoonful of cactus juice. The small cactus is quite devoid of liquid now, so you toss it away."#message 13 "You scrape the lard into the mixing bowl, and keep the now-empty jar nearby to store your finished formula."#message 14 "You carefully add the spoonful of cactus juice to the bowl."#message 15 "You cautiously pour the two drops of toad spittle into the bowl."#message 16 "Using one of the stirrers lying on the table, you mix the lard, cactus juice, and toad spittle until it is smooth and blended."#message 17 "You wave the magic wand."#message 18 "You scoop the invisibility ointment out of the clay bowl and return it to the lard jar."

