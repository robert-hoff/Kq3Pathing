if (isset(newRoom))
{
  v241 = 143;
  return ();
}

if (!isset(haveInput) || isset(haveMatch))
{
  goto(Label1);
}
set(f120);
++v103;


if (said("add", "mandrake", "root", "flour", "basin") || said("drain", "mandrake", "root", "flour", "basin"))
{
  if (!has("Mandrake Root*") || !has("Bowl"))
  {
    print("How can you use that which you do not have?");
  }
  else
  {
    print("You pour the mandrake root powder into the bowl.");
    drop("Mandrake Root*");
    if (v103 == 1)
    {
      reset(f120);
    }
  }
}


if (said("add", "cat", "fur", "basin"))
{
  if (!has("Cat Hair*") || !has("Bowl"))
  {
    print("How can you use that which you do not have?");
  }
  else
  {
    drop("Cat Hair*");
    print("You put the ball of cat hair in the mixing bowl.");
    if (v103 == 2)
    {
      reset(f120);
    }
  }
}


if (said("add", "two", "ladle", "fish oil", "basin"))
{
  if (!has("Fish Oil*") || !has("Bowl"))
  {
    print("How can you use that which you do not have?");
  }
  else
  {
    print("You pour the fish oil into the bowl and keep the empty jar.");
    drop("Fish Oil*");
    get("Empty Jar*");
    if (v103 == 3)
    {
      reset(f120);
    }
  }
}



if ((said("knead", "compound", "try", "ladle") || said("knead", "compound") || said("knead", "try", "ladle")))
{
  if (v103 == 4)
  {
    print("You mix the ingredients together. The mixture turns into an oily, "

      "disagreeable dough with cat hairs sticking out of it.");
    reset(f120);
  }
  else
  {
    reset(haveMatch);
  }
}


if (said("add", "compound", "on", "counter") || said("drain", "compound", "on", "counter"))
{
  if (v103 == 5)
  {
    print("Scrunching your nose in distaste, you grab the oily dough from the "
      "clay bowl and put it on the oaken table.");
    reset(f120);
  }
  else
  {
    reset(haveMatch);
  }
}


if ((said("pat", "compound", "cookie") ||
  said("form", "compound", "cookie") ||
  said("form", "cookie", "from", "compound") ||
  said("pat", "cookie", "from", "compound")))
{
  if (v103 == 6)
  {
    print("Pushing the palm of your hand on the oily dough, you flatten it "
      "until it is in the shape of a cookie. After a bit, the cookie "
      "hardens.");
    reset(f120);
    ++v103;
  }
  else
  {
    reset(haveMatch);
  }
}

if (said("aim", "rod") || said("aim", "magic", "rod"))
{
  if (!has("Magic Wand*"))
  {
    print("How can you use that which you do not have?");
  }
  else
  {
    if (v103 == 8)
    {
      print("You wave the magic wand over the cookie, then take it from the "
        "table, and carry it with you.");
      reset(f120);
      get("Cat Cookie*");
    }
    else
    {
      reset(haveMatch);
    }
  }
}

Label1:
if (!isset(f120) && v104 < 4 && v103 == 7)
{
  set(f120);
  prevent.input();
  set.text.attribute(BLACK, WHITE);
  set.string(s1, " ");
  if (v104 == 0)
  {
    overlay.pic(v241);
    show.pic();
    set.string(s2, "mandrake root and hair of cat,");
    if (monitorType == MONO)
    {
      open.dialogue();
      get.string(s1, " ", 15, 1, 30);
    }
    else
    {
      get.string(s1, " ", 13, 1, 30);
    }
    if (compare.strings(s1, s2))
    {
      reset(f120);
    }
  }
  if (v104 == 1)
  {
    set.string(s2, "mix oil of fish and give a pat,");
    if (monitorType == MONO)
    {
      get.string(s1, " ", 16, 1, 31);
    }
    else
    {
      get.string(s1, " ", 14, 1, 31);
    }
    if (compare.strings(s1, s2))
    {
      reset(f120);
    }
  }
  if (v104 == 2)
  {
    set.string(s2, "a feline from the one who eats");
    if (monitorType == MONO)
    {
      get.string(s1, " ", 17, 1, 30);
    }
    else
    {
      get.string(s1, " ", 15, 1, 30);
    }
    if (compare.strings(s1, s2))
    {
      reset(f120);
    }
  }
  if (v104 == 3)
  {
    set.string(s2, "this appetizing magic treat.");
    if (monitorType == MONO)
    {
      get.string(s1, " ", 18, 1, 28);
    }
    else
    {
      get.string(s1, " ", 16, 1, 28);
    }
    if (compare.strings(s1, s2))
    {
      reset(f120);
    }
  }
  set.text.attribute(WHITE, BLACK);
  ++v104;
  set.string(s1, " ");
  set.string(s2, " ");
  if (isset(f120) || v104 == 4)
  {
    if (monitorType == MONO)
    {
      close.dialogue();
    }
    draw.pic(currentRoom);
    show.pic();
    accept.input();
  }
}


v36 = v103;
++v36;
if (v36 == 9 && !isset(f120))
{
  v103 = 255;
}

if (isset(f120))
{
  v105 = 39;
  v106 = 0;
}
return ();



[Messages
#message 1 "How can you use that which you do not have?"
#message 2 ""
#message 3 "You pour the mandrake root powder into the bowl."
#message 4 "mandrake root and hair of cat,"
#message 5 "mix oil of fish and give a pat,"
#message 6 "a feline from the one who eats"
#message 7 "this appetizing magic treat."
#message 8 "You put the ball of cat hair in the mixing bowl."
#message 9 " "
#message 10 "]"
#message 11 "You pour the fish oil into the bowl and keep the empty jar."
#message 12 "You mix the ingredients together. The mixture turns into an oily, disagreeable dough with cat hairs sticking out of it."
#message 13 "Scrunching your nose in distaste, you grab the oily dough from the clay bowl and put it on the oaken table."
#message 14 "Pushing the palm of your hand on the oily dough, you flatten it until it is in the shape of a cookie. After a bit, the cookie hardens."
#message 15 "You wave the magic wand over the cookie, then take it from the table, and carry it with you."


