if (isset(newRoom))
{
  v240 = 143;
  return ();
}

if ((!isset(haveInput) || isset(haveMatch)))
{
  goto(Label1);
}

set(f120);
++v103;
if ((said("add", "bay", "liquid", "basin") ||
  said("add", "cup", "bay", "liquid", "basin") ||
  said("add", "one", "cup", "bay", "liquid", "basin") ||
  said("drain", "bay", "liquid", "basin") ||
  said("drain", "cup", "bay", "liquid", "basin") ||
  said("drain", "one", "cup", "bay", "liquid", "basin") ||
  said("add", "liquid", "basin") ||
  said("add", "cup", "liquid", "basin") ||
  said("add", "one", "cup", "liquid", "basin") ||
  said("drain", "liquid", "basin") ||
  said("drain", "cup", "liquid", "basin") ||
  said("drain", "one", "cup", "liquid", "basin")))
{
  if ((!has("Bowl") ||
    !has("Ocean Water*")))
  {
    print("How can you use that which you do not have?");
  }
  else
  {
    drop("Ocean Water*");
    get("Empty Cup");
    print("Carefully, you pour the cup of ocean water into the mixing bowl.");
    if (v103 == 1)
    {
      reset(f120);
    }
  }
}

if ((said("boil", "basin", "brazier") ||
  said("boil", "bay", "liquid", "brazier") ||
  said("boil", "basin", "bay", "liquid", "brazier") ||
  said("boil", "basin", "bay", "liquid", "above", "brazier") ||
  said("boil", "liquid", "brazier") ||
  said("boil", "basin", "on", "brazier") ||
  said("boil", "bay", "liquid", "on", "brazier") ||
  said("boil", "basin", "bay", "liquid", "on", "brazier") ||
  said("boil", "liquid", "on", "brazier") ||
  said("boil", "basin", "liquid", "on", "brazier") ||
  said("boil", "basin", "liquid", "brazier") ||
  said("boil", "basin", "liquid", "above", "brazier")))
{
  if (v107 <= 0 && v108 <= 0)
  {
    print("You place the clay bowl of ocean water on top of the little charcoal "
      "brazier. To your consternation, you discover that the brazier is "
      "unlit, and stone cold.");
  }
  else
  {
    print("Being cautious not to burn yourself, you gently place the bowl of "
      "ocean water on the hot charcoal brazier. You watch as the salt water "
      "slowly warms, then begins to steam. You remove it just before it "
      "boils.");
    if (v103 == 2)
    {
      reset(f120);
    }
  }
}


if ((said("add", "ladle", "mud", "basin", "liquid") ||
  said("add", "mud", "basin", "liquid") ||
  said("add", "mud", "basin") ||
  said("knead", "ladle", "mud", "basin") ||
  said("knead", "ladle", "mud", "basin", "liquid") ||
  said("knead", "mud", "basin", "liquid") ||
  said("add", "ladle", "mud", "basin", "bay", "liquid") ||
  said("add", "mud", "basin", "bay", "liquid") ||
  said("knead", "ladle", "mud", "basin", "bay", "liquid") ||
  said("knead", "mud", "basin", "bay", "liquid") ||
  said("knead", "ladle", "mud", "basin") ||
  said("add", "ladle", "mud", "basin") ||
  said("knead", "mud", "basin")))
{
  if (!has("Mud*"))
  {
    print("How can you use that which you do not have?");
  }
  else
  {
    print("Adding a spoonful of mud to the hot ocean water, you slowly stir the "
      "mixture. The mud turns the water a cloudy brown.");
    drop("Mud*");
    get("Spoon");
    if (v103 == 3)
    {
      reset(f120);
    }
  }
}
if ((said("add", "bit", "mushroom", "flour") ||
  said("add", "bit", "mushroom", "flour", "basin") ||
  said("add", "bit", "mushroom", "flour", "liquid")))
{
  if (!has("Toadstool Powder*"))
  {
    print("How can you use that which you do not have?");
  }
  else
  {
    print("You put just a pinch of toadstool powder in the bowl of hot, brown liquid.");
    drop("Toadstool Powder*");
    if (v103 == 4)
    {
      reset(f120);
    }
  }
}
if ((said("blow", "liquid") ||
  said("blow", "brew") ||
  said("blow", "bay", "liquid") ||
  said("blow", "basin")))
{
  if (v103 == 5)
  {
    print("Leaning over the hot brew, you forcefully blow your longest breath "
      "of air into the bowl, whirling the brew around and around.");
    reset(f120);
    ++v103;
  }
  else
  {
    reset(haveMatch);
  }
}


if ((said("aim", "rod") ||
  said("aim", "magic", "rod")))
{
  if (!has("Magic Wand*"))
  {
    print("How can you use that which you do not have?");
  }
  else
  {
    print("You wave the magic wand over the bowl of hot, brown liquid.");
    if (v103 == 7)
    {
      reset(f120);
    }
  }
}


if ((said("drain", "brew", "from", "basin", "bottle") ||
  said("drain", "brew", "bottle") ||
  said("add", "brew", "from", "basin", "bottle") ||
  said("add", "brew", "bottle")))
{
  if (!has("Empty Jar*"))
  {
    print("How can you use that which you do not have?");
  }
  else
  {
    if (v103 == 8)
    {
      print("Waiting until the liquid has cooled, you carefully pour the storm "
        "brew into an empty glass jar.");
      reset(f120);
      get("Storm Brew*");
      drop("Empty Jar*");
    }
    else
    {
      reset(haveMatch);
    }
  }
}



Label1:
if (!isset(f120) && v104 < 4 && v103 == 6)
{
  set(f120);
  prevent.input();
  set.text.attribute(BLACK, WHITE);
  set.string(s1, " ");
  if (v104 == 0)
  {
    overlay.pic(v240);
    show.pic();
    set.string(s2, "elements from the earth and sea,");
    if (monitorType == MONO)
    {
      open.dialogue();
      get.string(s1, " ", 15, 1, 32);
    }
    else
    {
      get.string(s1, " ", 13, 1, 32);
    }
    if (compare.strings(s1, s2))
    {
      reset(f120);
    }
  }
  if (v104 == 1)
  {
    set.string(s2, "combine to set the heavens free.");
    if (monitorType == MONO)
    {
      get.string(s1, " ", 16, 1, 32);
    }
    else
    {
      get.string(s1, " ", 14, 1, 32);
    }
    if (compare.strings(s1, s2))
    {
      reset(f120);
    }
  }
  if (v104 == 2)
  {
    set.string(s2, "when i stir this magic brew,");
    if (monitorType == MONO)
    {
      get.string(s1, " ", 17, 1, 28);
    }
    else
    {
      get.string(s1, " ", 15, 1, 28);
    }
    if (compare.strings(s1, s2))
    {
      reset(f120);
    }
  }
  if (v104 == 3)
  {
    set.string(s2, "great god thor, i call on you.");
    if (monitorType == MONO)
    {
      get.string(s1, " ", 18, 1, 30);
    }
    else
    {
      get.string(s1, " ", 16, 1, 30);
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
  if ((isset(f120) ||
    v104 == 4))
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
  v106 = 1;
}
return ();


[Messages
#message 1 "How can you use that which you do not have?"
#message 2 " "
#message 3 "]"
#message 4 "elements from the earth and sea,"
#message 5 "combine to set the heavens free."
#message 6 "when i stir this magic brew,"
#message 7 "great god thor, i call on you."
#message 8 ""
#message 9 "Carefully, you pour the cup of ocean water into the mixing bowl."
#message 10 "You place the clay bowl of ocean water on top of the little charcoal brazier. To your consternation, you discover that the brazier is unlit, and stone cold."
#message 11 "Being cautious not to burn yourself, you gently place the bowl of ocean water on the hot charcoal brazier. You watch as the salt water slowly warms, then begins to steam. You remove it just before it boils."
#message 12 "Adding a spoonful of mud to the hot ocean water, you slowly stir the mixture. The mud turns the water a cloudy brown."
#message 13 "You put just a pinch of toadstool powder in the bowl of hot, brown liquid."
#message 14 "Leaning over the hot brew, you forcefully blow your longest breath of air into the bowl, whirling the brew around and around."
#message 15 "You wave the magic wand over the bowl of hot, brown liquid."
#message 16 "Waiting until the liquid has cooled, you carefully pour the storm brew into an empty glass jar."



