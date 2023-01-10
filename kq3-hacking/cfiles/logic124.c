if (isset(newRoom))
  {  v241 = 143;  return();  }if ((!isset(haveInput) ||     isset(haveMatch)))
  {  goto(Label1);  }set(f120);++v103;if ((said("crumble", "acorn", "mortar") ||     said("crumble", "three", "acorn", "mortar")))
  {  if (!has("Acorns*"))
    {    print("How can you use that which you do not have?");    }  else
    {    if (v103 == 1)
      {      print("Putting the dried acorns into the stone mortar, you use the pestle "            "to grind them into a rough acorn powder.");      drop("Acorns*");      reset(f120);      }    else
      {      reset(haveMatch);      }    }  }if ((said("add", "acorn", "flour", "basin") ||     said("drain", "acorn", "flour", "basin")))
  {  if (!has("Bowl"))
    {    print("You don't have a bowl.");    }  else
    {    if (v103 == 2)
      {      print("Turning the heavy stone mortar upside down, you carefully pour the "            "acorn powder into the bowl, then return the mortar to the table.");      reset(f120);      }    else
      {      reset(haveMatch);      }    }  }if ((said("add", "cup", "night shade", "basin") ||     said("add", "cup", "night shade", "juice", "basin") ||     said("add", "one", "cup", "night shade", "juice", "basin") ||     said("add", "one", "cup", "night shade", "basin") ||     said("add", "night shade", "basin") ||     said("add", "night shade", "juice", "basin") ||     said("drain", "cup", "juice", "basin") ||     said("drain", "cup", "night shade", "basin") ||     said("drain", "cup", "night shade", "juice", "basin") ||     said("drain", "one", "cup", "night shade", "juice", "basin") ||     said("drain", "one", "cup", "night shade", "basin") ||     said("drain", "night shade", "juice", "basin")))
  {  if (!has("Nightshade Juice*"))
    {    print("How can you use that which you do not have?");    }  else
    {    if (v103 == 3)
      {      print("You very carefully pour a cupful of nightshade juice into the clay "            "bowl so as to not to spill a single drop.");      print("There is now an ugly, brown, mealy, liquid mixture in the bowl.");      drop("Nightshade Juice*");      reset(f120);      }    else
      {      reset(haveMatch);      }    }  }if ((said("knead", "compound", "ladle") ||     said("knead", "try", "ladle") ||     said("knead", "compound", "try", "ladle") ||     said("knead", "compound")))
  {  if (v103 == 4)
    {    print("You gently stir the unappetizing liquid.");    reset(f120);    }  else
    {    reset(haveMatch);    }  }if ((said("boil", "compound", "brazier") ||     said("boil", "compound", "above", "brazier") ||     said("boil", "compound", "on", "brazier") ||     said("boil", "basin", "on", "brazier") ||     said("boil", "basin", "brazier") ||     said("boil", "basin", "above", "brazier") ||     said("add", "basin", "brazier") ||     said("add", "basin", "above", "brazier") ||     said("add", "basin", "on", "brazier") ||     said("add", "basin", "on", "brazier", "boil")))
  {  if (!has("Bowl"))
    {    print("How can you use that which you do not have?");    }  else
    {    print("You gingerly place the clay bowl of ugly brown liquid on the "          "charcoal brazier.");    if (v107 <= 0 &&         v108 <= 0)
      {      print("How you wish you had lit the burner!");      }    else
      {      if (v103 == 5)
        {        print("Soon, the hot brazier brings the mixture to a bubble, then a "              "boil, releasing a bitter smelling steam.");        print("You let it boil until the nightshade juice is nearly gone, then "              "remove it from the brazier.");        reset(f120);        }      else
        {        reset(haveMatch);        }      }    }  }if ((said("flatten", "compound", "counter") ||     said("flatten", "compound", "on", "counter")))
  {  if (v103 == 6)
    {    print("You pour the bowl's contents onto the oaken table, then spread the "          "hot sticky mixture over the table top. In a few minutes, it has "          "dried to a very crumbly, coarse sleeping powder.");    reset(f120);    ++v103;    }  else
    {    reset(haveMatch);    }  }if (said("capture", "sleep", "flour"))
  {  if (v103 == 9)
    {    print("You try to pick up the sleep powder and drop it all over the "          "laboratory floor, where it mixes into the dirt. How you wish you had "          "brought a pouch in which to carry it!");    }  else
    {    reset(haveMatch);    }  }if ((said("add", "sleep", "flour", "pouch") ||     said("drain", "sleep", "flour", "pouch")))
  {  if (!has("Empty Pouch*"))
    {    print("How can you use that which you do not have?");    }  else
    {    if (v103 == 9)
      {      print("You untie the small leather pouch, scoop the powder from the "            "table, and place it within. You now have a pouch full of sleep "            "powder.");      reset(f120);      drop("Empty Pouch*");      get("Sleep Powder*");      }    else
      {      reset(haveMatch);      }    }  }if ((said("aim", "rod") ||     said("aim", "magic", "rod")))
  {  if (!has("Magic Wand*"))
    {    print("How can you use that which you do not have?");    drop("Sleep Powder*");    }  else
    {    if (v103 == 8)
      {      print("You pass the magic wand over the table.");      reset(f120);      }    else
      {      drop("Sleep Powder*");      reset(haveMatch);      }    }  }Label1:if (!isset(f120) &&     v104 < 4 &&     v103 == 7)
  {  set(f120);  prevent.input();  set.text.attribute(BLACK, WHITE);  set.string(s1, " ");  if (v104 == 0)
    {    overlay.pic(v241);    show.pic();    set.string(s2, "acorn powder ground so fine,");    if (monitorType == MONO)
      {      open.dialogue();      get.string(s1, " ", 15, 1, 28);      }    else
      {      get.string(s1, " ", 13, 1, 28);      }    if (compare.strings(s1, s2))
      {      reset(f120);      }    }  if (v104 == 1)
    {    set.string(s2, "nightshade juice, like bitter wine,");    if (monitorType == MONO)
      {      get.string(s1, " ", 16, 1, 35);      }    else
      {      get.string(s1, " ", 14, 1, 35);      }    if (compare.strings(s1, s2))
      {      reset(f120);      }    }  if (v104 == 2)
    {    set.string(s2, "silently in darkness you creep,");    if (monitorType == MONO)
      {      get.string(s1, " ", 17, 1, 31);      }    else
      {      get.string(s1, " ", 15, 1, 31);      }    if (compare.strings(s1, s2))
      {      reset(f120);      }    }  if (v104 == 3)
    {    set.string(s2, "to bring a soporific sleep.");    if (monitorType == MONO)
      {      get.string(s1, " ", 18, 1, 27);      }    else
      {      get.string(s1, " ", 16, 1, 27);      }    if (compare.strings(s1, s2))
      {      reset(f120);      }    }  set.text.attribute(WHITE, BLACK);  ++v104;  set.string(s1, " ");  set.string(s2, " ");  if ((isset(f120) ||       v104 == 4))
    {    if (monitorType == MONO)
      {      close.dialogue();      }    draw.pic(currentRoom);    show.pic();    accept.input();    }  }v36 = v103;++v36;if (v36 == 10 &&     !isset(f120))
  {  v103 = 255;  }if (isset(f120))
  {  v105 = 38;  v106 = 3;  }return();[ Messages#message 1 "How can you use that which you do not have?"#message 2 "acorn powder ground so fine,"#message 3 "nightshade juice, like bitter wine,"#message 4 "silently in darkness you creep,"#message 5 "to bring a soporific sleep."#message 6 " "#message 7 "]"#message 8 "You pass the magic wand over the table."#message 9 "Putting the dried acorns into the stone mortar, you use the pestle to grind them into a rough acorn powder."#message 10 "Turning the heavy stone mortar upside down, you carefully pour the acorn powder into the bowl, then return the mortar to the table."#message 11 "You very carefully pour a cupful of nightshade juice into the clay bowl so as to not to spill a single drop."#message 12 "There is now an ugly, brown, mealy, liquid mixture in the bowl."#message 13 ""#message 14 "You pour the contents of the cup into the bowl."#message 15 "You gently stir the unappetizing liquid."#message 16 "You gingerly place the clay bowl of ugly brown liquid on the charcoal brazier."#message 17 "How you wish you had lit the burner!"#message 18 "Soon, the hot brazier brings the mixture to a bubble, then a boil, releasing a bitter smelling steam."#message 19 "You let it boil until the nightshade juice is nearly gone, then remove it from the brazier."#message 20 "You pour the bowl's contents onto the oaken table, then spread the hot sticky mixture over the table top. In a few minutes, it has dried to a very crumbly, coarse sleeping powder."#message 21 ""#message 22 "You untie the small leather pouch, scoop the powder from the table, and place it within. You now have a pouch full of sleep powder."#message 23 "You try to pick up the sleep powder and drop it all over the laboratory floor, where it mixes into the dirt. How you wish you had brought a pouch in which to carry it!"#message 24 ""#message 25 "You don't have a bowl."#message 26 "You must grind the acorns first."