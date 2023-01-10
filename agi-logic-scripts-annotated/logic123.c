if (isset(newRoom))
{  v240 = 143;  return();}if ((!isset(haveInput) ||  isset(haveMatch)))
{  goto(Label1);}set(f120);++v103;if ((said("add", "grains of salt", "ladle") ||  said("add", "grains of salt", "mortar") ||  said("drain", "grains of salt", "mortar") ||  said("crumble", "grains of salt", "mortar") ||  said("add", "ladle", "grains of salt", "mortar") ||  said("drain", "ladle", "grains of salt", "mortar") ||  said("add", "ladle", "grains of salt", "mortar") ||  said("crumble", "ladle", "grains of salt", "mortar")))
{  if (v103 == 1)
  {    set(f240);  }  else
  {    reset(haveMatch);  }}if (said("crumble", "mistletoe", "mortar"))
{  if (!has("Mistletoe*"))
  {    print("You cannot use that which you do not have.");  }  else
  {    drop("Mistletoe*");    print("Placing the dried sprig of mistletoe in the stone mortar, you crush "      "it with the pestle.");    if (v103 == 2)
    {      reset(f120);      print("Soon, you have a crushed mixture of salt and mistletoe in the "        "mortar. You remove the pestle and lay it aside.");    }  }}if ((said("pat", "amber", "rock", "compound") ||  said("pat", "amber", "rock", "mortar") ||  said("pat", "rock", "compound") ||  said("pat", "rock", "mortar")))
{  if (!has("Amber Stone*"))
  {    print("You cannot use that which you do not have.");  }  else
  {    print("You place the beautiful amber stone in the stone mortar.");    if (v103 == 3)
    {      reset(f120);      print("Very carefully, so as not to miss a single spot, you rub the amber "        "stone around in the mixture of ground salt and mistletoe. When you "        "have finished, you remove the amber stone and discard the "        "remaining powder.");    }  }}if ((said("embrace", "amber", "rock") ||  said("embrace", "rock")))
{  if (v103 == 4)
  {    print("Smack!");    reset(f120);    ++v103;  }  else
  {    reset(haveMatch);  }}if ((said("aim", "rod") ||  said("aim", "magic", "rod")))
{  if (!has("Magic Wand*"))
  {    print("You cannot use that which you do not have.");  }  else
  {    print("You wave the magic wand over the encrusted amber stone.");    if (v103 == 6)
    {      reset(f120);      drop("Amber Stone*");      get("Magic Stone*");    }  }}Label1:if (!isset(f120) &&  v104 < 4 &&  v103 == 5)
{  set(f120);  prevent.input();  set.text.attribute(BLACK, WHITE);  set.string(s1, " ");  if (v104 == 0)
  {    overlay.pic(v240);    show.pic();    set.string(s2, "with this kiss, I thee impart,");    if (monitorType == MONO)
    {      open.dialogue();      get.string(s1, " ", 15, 1, 30);    }    else
    {      get.string(s1, " ", 13, 1, 30);    }    if (compare.strings(s1, s2))
    {      reset(f120);    }  }  if (v104 == 1)
  {    set.string(s2, "power most dear to my heart.");    if (monitorType == MONO)
    {      open.dialogue();      get.string(s1, " ", 16, 1, 28);    }    else
    {      get.string(s1, " ", 14, 1, 28);    }    if (compare.strings(s1, s2))
    {      reset(f120);    }  }  if (v104 == 2)
  {    set.string(s2, "take me now from this place hither,");    if (monitorType == MONO)
    {      open.dialogue();      get.string(s1, " ", 17, 1, 35);    }    else
    {      get.string(s1, " ", 15, 1, 35);    }    if (compare.strings(s1, s2))
    {      reset(f120);    }  }  if (v104 == 3)
  {    set.string(s2, "to another place far thither.");    if (monitorType == MONO)
    {      open.dialogue();      get.string(s1, " ", 18, 1, 29);    }    else
    {      get.string(s1, " ", 16, 1, 29);    }    if (compare.strings(s1, s2))
    {      reset(f120);    }  }  set.text.attribute(WHITE, BLACK);  ++v104;  set.string(s1, " ");  set.string(s2, " ");  if ((isset(f120) ||    v104 == 4))
  {    if (monitorType == MONO)
    {      close.dialogue();    }    draw.pic(currentRoom);    show.pic();    accept.input();  }}if (isset(f240))
{  reset(f240);  if (!has("Salt*"))
  {    print("You cannot use that which you do not have.");  }  else
  {    drop("Salt*");    print("You place a spoonful of coarse salt grains in the mortar. Then, "      "using the stone pestle, you grind the salt until it is very fine.");    if (v103 == 1)
    {      reset(f120);    }  }}v36 = v103;++v36;if (v36 == 7 &&  !isset(f120))
{  v103 = 255;}if (isset(f120))
{  v105 = 38;  v106 = 2;}return();[Messages#message 1 "You cannot use that which you do not have."#message 2 ""#message 3 "You place a spoonful of coarse salt grains in the mortar. Then, using the stone pestle, you grind the salt until it is very fine."#message 4 ""#message 5 "Placing the dried sprig of mistletoe in the stone mortar, you crush it with the pestle."#message 6 "Soon, you have a crushed mixture of salt and mistletoe in the mortar. You remove the pestle and lay it aside."#message 7 "You place the beautiful amber stone in the stone mortar."#message 8 "Very carefully, so as not to miss a single spot, you rub the amber stone around in the mixture of ground salt and mistletoe. When you have finished, you remove the amber stone and discard the remaining powder."#message 9 "Smack!"#message 10 "with this kiss, I thee impart,"#message 11 "power most dear to my heart."#message 12 "take me now from this place hither,"#message 13 "to another place far thither."#message 14 "You wave the magic wand over the encrusted amber stone."#message 15 ""#message 16 "]"#message 17 " "
