if (isset(newRoom))
  {  v240 = 143;  return();  }if ((!isset(haveInput) ||     isset(haveMatch)))
  {  goto(Label1);  }set(f120);++v103;if ((said("add", "bird", "feather", "basin") ||     said("add", "one", "bird", "feather", "basin")))
  {  set(f242);  }if ((said("add", "eagle", "feather", "basin") ||     said("add", "one", "eagle", "feather", "basin")))
  {  set(f241);  }if (said("add", "feather", "basin"))
  {  if ((!has("Chicken Feather*") ||       !has("Bowl")))
    {    print("It is difficult to use that which you do not have.");    }  else
    {    if (has("Chicken Feather*"))
      {      set(f242);      }    else
      {      if (has("Eagle Feather*"))
        {        set(f241);        }      }    }  }if (isset(f243))
  {  reset(f243);  if ((said("cat") ||       said("cat", "fur")))
    {    set(f244);    }  if ((said("dog") ||       said("dog", "fur")))
    {    set(f245);    }  }if (said("add", "fur", "basin"))
  {  if (!has("Cat Hair*") &&       !has("Dog Hair*"))
    {    print("It is difficult to use that which you do not have.");    }  else
    {    if (has("Cat Hair*") &&         has("Dog Hair*"))
      {      set(f243);      reset(f120);      --v103;      print("Which tuft of fur?");      }    if (!isset(f243))
      {      if (has("Dog Hair*"))
        {        set(f245);        }      if (has("Cat Hair*"))
        {        set(f244);        }      }    }  }if (said("add", "cat", "fur", "basin"))
  {  set(f244);  }if (said("add", "dog", "fur", "basin"))
  {  set(f245);  }if ((said("add", "reptile", "reptile skin", "basin") ||     said("add", "reptile", "basin") ||     said("add", "reptile skin", "basin")))
  {  if (!has("Snakeskin*"))
    {    print("What snake skin?");    }  else
    {    if (!has("Bowl"))
      {      print("It is difficult to use that which you do not have.");      }    else
      {      drop("Snakeskin*");      print("You put the dried snake skin in the clay bowl.");      if (v103 == 3)
        {        reset(f120);        }      }    }  }if ((said("add", "ladle", "bone") ||     said("add", "bone", "basin") ||     said("add", "ladle", "bone") ||     said("add", "ladle", "bone", "basin") ||     said("add", "ladle", "bone", "basin")))
  {  if ((!has("Powdered Fish Bone*") ||       !has("Bowl")))
    {    print("It is difficult to use that which you do not have.");    }  else
    {    print("You pour a spoonful of fish bone powder into the clay bowl.");    drop("Powdered Fish Bone*");    if (v103 == 4)
      {      reset(f120);      }    }  }if ((said("add", "one", "thimble", "dew", "basin") ||     said("add", "thimble", "dew", "basin") ||     said("add", "dew", "basin")))
  {  if (!has("Thimble and Dew*"))
    {    print("It is difficult to use that which you do not have.");    }  else
    {    drop("Thimble and Dew*");    get("Thimble*");    print("You pour the thimbleful of dew into the clay bowl.");    if (v103 == 5)
      {      reset(f120);      }    }  }if ((said("knead", "fingers") ||     said("knead", "compound", "fingers") ||     said("knead", "compound", "basin", "fingers") ||     said("knead", "try", "fingers") ||     said("knead", "compound", "try", "fingers") ||     said("knead", "compound", "basin", "try", "fingers")))
  {  if (v103 == 6)
    {    print("You knead the ingredients in the clay bowl with your hands. It turns "          "into a stiff, dough-like substance.");    reset(f120);    }  else
    {    reset(haveMatch);    }  }if ((said("divide", "compound", "two", "ball") ||     said("divide", "two", "ball") ||     said("form", "two", "ball") ||     said("form", "two", "ball", "from", "compound") ||     said("form", "compound", "two", "ball") ||     said("move", "compound", "two", "ball")))
  {  if (v103 == 7)
    {    print("You grasp the doughy mixture in the bowl and divide it into two "          "pieces.");    reset(f120);    }  else
    {    reset(haveMatch);    }  }if ((said("add", "two", "ball", "compound", "ears") ||     said("add", "two", "compound", "ball", "ears") ||     said("add", "compound", "ball", "ears") ||     said("add", "compound", "ears") ||     said("add", "ball", "ears") ||     said("add", "ball", "compound", "ears")))
  {  if (v103 == 8)
    {    print("You VERY gently place the two pieces of dough in your ears and pull "          "your hair down over them. You prepare to recite the magical "          "incantation.");    reset(f120);    ++v103;    }  else
    {    reset(haveMatch);    }  }if ((said("aim", "rod") ||     said("aim", "magic", "rod")))
  {  if (!has("Magic Wand*"))
    {    print("It is difficult to use that which you do not have.");    }  else
    {    if (v103 == 10)
      {      print("You wave the magic wand over your dough-filled ears.");      reset(f120);      get("Dough in Ears");      }    else
      {      reset(haveMatch);      }    }  }Label1:if (!isset(f120) &&     v104 < 4 &&     v103 == 9)
  {  set(f120);  prevent.input();  set.text.attribute(BLACK, WHITE);  set.string(s1, " ");  if (v104 == 0)
    {    overlay.pic(v240);    show.pic();    set.string(s2, "feather of fowl and bone of fish,");    if (monitorType == MONO)
      {      open.dialogue();      get.string(s1, " ", 15, 1, 33);      }    else
      {      get.string(s1, " ", 13, 1, 33);      }    if (compare.strings(s1, s2))
      {      reset(f120);      }    }  if (v104 == 1)
    {    set.string(s2, "molded together in this dish,");    if (monitorType == MONO)
      {      open.dialogue();      get.string(s1, " ", 16, 1, 29);      }    else
      {      get.string(s1, " ", 14, 1, 29);      }    if (compare.strings(s1, s2))
      {      reset(f120);      }    }  if (v104 == 2)
    {    set.string(s2, "give me wisdom to understand");    if (monitorType == MONO)
      {      open.dialogue();      get.string(s1, " ", 17, 1, 28);      }    else
      {      get.string(s1, " ", 15, 1, 28);      }    if (compare.strings(s1, s2))
      {      reset(f120);      }    }  if (v104 == 3)
    {    set.string(s2, "creatures of air, sea and land.");    if (monitorType == MONO)
      {      open.dialogue();      get.string(s1, " ", 18, 1, 31);      }    else
      {      get.string(s1, " ", 16, 1, 31);      }    if (compare.strings(s1, s2))
      {      reset(f120);      }    }  set.text.attribute(WHITE, BLACK);  ++v104;  set.string(s1, " ");  set.string(s2, " ");  if ((isset(f120) ||       v104 == 4))
    {    if (monitorType == MONO)
      {      close.dialogue();      }    draw.pic(currentRoom);    show.pic();    accept.input();    }  }if (isset(f242))
  {  reset(f242);  if ((!has("Chicken Feather*") ||       !has("Bowl")))
    {    print("It is difficult to use that which you do not have.");    }  else
    {    drop("Chicken Feather*");    print("You place the soft, downy chicken feather in your clay mixing bowl.");    if (v103 == 1)
      {      reset(f120);      }    }  }if (isset(f241))
  {  reset(f241);  if (!has("Eagle Feather*"))
    {    print("It is difficult to use that which you do not have.");    }  else
    {    print("The eagle feather is too big for this particular recipe. It won't "          "work.");    }  }if (isset(f244))
  {  reset(f244);  if (!has("Cat Hair*"))
    {    print("It is difficult to use that which you do not have.");    }  else
    {    drop("Cat Hair*");    print("You put the tuft of cat hair in the clay bowl.");    if (v103 == 2)
      {      reset(f120);      }    }  }if (isset(f245))
  {  reset(f245);  if (!has("Dog Hair*"))
    {    print("It is difficult to use that which you do not have.");    }  else
    {    drop("Dog Hair*");    print("You put the tuft of dog hair in the clay bowl.");    if (v103 == 2)
      {      reset(f120);      }    }  }v36 = v103;++v36;if (v36 == 11 &&     !isset(f120))
  {  v103 = 255;  }if (isset(f120))
  {  v105 = 38;  v106 = 0;  }return();[ Messages#message 1 ""#message 2 ""#message 3 "The eagle feather is too big for this particular recipe. It won't work."#message 4 "You place the soft, downy chicken feather in your clay mixing bowl."#message 5 "feather of fowl and bone of fish,"#message 6 "molded together in this dish,"#message 7 "give me wisdom to understand"#message 8 "creatures of air, sea and land."#message 9 ""#message 10 ""#message 11 "You put the tuft of cat hair in the clay bowl."#message 12 "You put the tuft of dog hair in the clay bowl."#message 13 "You put the dried snake skin in the clay bowl."#message 14 "You can't do that."#message 15 "You have two feathers. Which do you mean?"#message 16 "You pour a spoonful of fish bone powder into the clay bowl."#message 17 ""#message 18 "It is difficult to use that which you do not have."#message 19 "You pour the thimbleful of dew into the clay bowl."#message 20 "You knead the ingredients in the clay bowl with your hands. It turns into a stiff, dough-like substance."#message 21 "You grasp the doughy mixture in the bowl and divide it into two pieces."#message 22 "Which tuft of fur?"#message 23 "You VERY gently place the two pieces of dough in your ears and pull your hair down over them. You prepare to recite the magical incantation."#message 24 ""#message 25 "You wave the magic wand over your dough-filled ears."#message 26 "]"#message 27 " "#message 28 ""#message 29 "What snake skin?"