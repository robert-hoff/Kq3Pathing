if (isset(newRoom))
{  v240 = 143;  return();}if ((!isset(haveInput) ||  isset(haveMatch)))
{  goto(Label1);}set(f120);++v103;if ((said("add", "bit", "saffron", "essence") ||  said("add", "saffron", "capsule", "essence") ||  said("add", "bit", "saffron", "capsule", "essence") ||  said("add", "bit", "saffron", "capsule") ||  said("add", "saffron", "essence") ||  said("add", "saffron", "capsule")))
{  if ((!has("Saffron*") ||    !has("Rose Essence*")))
  {    print("It is difficult to use that which you do not have.");  }  else
  {    drop("Saffron*");    print("You carefully sprinkle the precious saffron into the vial of rose "      "petal essence.");    if (v103 == 1)
    {      reset(f120);      ++v103;    }  }}if ((said("aim", "rod") ||  said("aim", "magic", "rod")))
{  if (!has("Magic Wand*"))
  {    print("It is difficult to use that which you do not have.");  }  else
  {    print("You wave the magic wand over the vial of rose petal essence.");    if (v103 == 3)
    {      drop("Rose Essence*");      get("Magic Rose Essence*");      reset(f120);    }  }}Label1:if (!isset(f120) &&  v104 < 4 &&  v103 == 2)
{  set(f120);  prevent.input();  set.text.attribute(BLACK, WHITE);  set.string(s1, " ");  if (v104 == 0)
  {    overlay.pic(v240);    show.pic();    set.string(s2, "oh winged spirits, set me free");    if (monitorType == MONO)
    {      open.dialogue();      get.string(s1, " ", 15, 1, 30);    }    else
    {      get.string(s1, " ", 13, 1, 30);    }    if (compare.strings(s1, s2))
    {      reset(f120);    }  }  if (v104 == 1)
  {    set.string(s2, "of earthly bindings, just like thee.");    if (monitorType == MONO)
    {      open.dialogue();      get.string(s1, " ", 16, 1, 36);    }    else
    {      get.string(s1, " ", 14, 1, 36);    }    if (compare.strings(s1, s2))
    {      reset(f120);    }  }  if (v104 == 2)
  {    set.string(s2, "in this essence, behold the might");    if (monitorType == MONO)
    {      open.dialogue();      get.string(s1, " ", 17, 1, 33);    }    else
    {      get.string(s1, " ", 15, 1, 33);    }    if (compare.strings(s1, s2))
    {      reset(f120);    }  }  if (v104 == 3)
  {    set.string(s2, "to grant the precious gift of flight.");    if (monitorType == MONO)
    {      open.dialogue();      get.string(s1, " ", 18, 1, 37);    }    else
    {      get.string(s1, " ", 16, 1, 37);    }    if (compare.strings(s1, s2))
    {      reset(f120);    }  }  set.text.attribute(WHITE, BLACK);  ++v104;  set.string(s1, " ");  set.string(s2, " ");  if ((isset(f120) ||    v104 == 4))
  {    if (monitorType == MONO)
    {      close.dialogue();    }    draw.pic(currentRoom);    show.pic();    accept.input();  }}v36 = v103;++v36;if (v36 == 4 &&  !isset(f120))
{  v103 = 255;}if (isset(f120))
{  v105 = 38;  v106 = 1;}return();[Messages#message 1 "It is difficult to use that which you do not have."#message 2 "You carefully sprinkle the precious saffron into the vial of rose petal essence."#message 3 "You wave the magic wand over the vial of rose petal essence."#message 4 "oh winged spirits, set me free"#message 5 "of earthly bindings, just like thee."#message 6 "in this essence, behold the might"#message 7 "to grant the precious gift of flight."#message 8 ""#message 9 " "#message 10 "]"
