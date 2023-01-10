if (!isset(haveInput))
  {  return();  }if (said("examine", "brush"))
  {  print("The lush foliage of the forest has given way to the hardy plants of "        "the shore. Sawgrass, bracken, and gnarled trees are all that grow "        "here.");  }if (said("examine", "forest"))
  {  print("The trees are bent and twisted by years of constant sea breezes.");  }if (said("examine", "bay"))
  {  print("Your eyes sweep the vast ocean before you. Blue water stretches as far "        "as you can see. Way in the distance it melts with the sky.");  }if (said("examine", "sky"))
  {  print("You see seagulls flying overhead.");  }if (said("examine", "liquid"))
  {  print("Your eyes sweep the vast ocean before you. Blue water stretches as far "        "as you can see. Way in the distance it melts with the sky.");  }if (said("examine", "bird"))
  {  print("The birds wheel and glide overhead.");  }if ((said("examine") ||     said("examine", "bluff") ||     said("examine", "deck") ||     said("examine", "beach")))
  {  print("The sandy beach stretches north and south below steep, grassy cliffs.");  }if ((said("dive") ||     said("dive", "bay") ||     said("dive", "liquid")))
  {  print("The water looks inviting, but be careful if you go out there.");  }if ((said("drink", "liquid") ||     said("drink", "bay", "liquid") ||     said("drink", "liquid", "bay") ||     said("drink", "liquid", "cup") ||     said("drink", "bay", "liquid", "cup") ||     said("drink", "grains of salt", "liquid", "cup") ||     said("drink", "grains of salt", "liquid")))
  {  print("Drinking salt water will only make you sick.");  }if ((said("capture", "liquid") ||     said("capture", "bay", "liquid") ||     said("capture", "liquid", "bay") ||     said("capture", "liquid", "cup") ||     said("capture", "bay", "liquid", "cup") ||     said("capture", "grains of salt", "liquid", "cup") ||     said("capture", "grains of salt", "liquid")))
  {  if (has("Ocean Water*"))
    {    print("Your cup is already full of water.");    }  else
    {    if (!isset(onWater))
      {      print("You need to move closer.");      }    else
      {      if (!has("Empty Cup"))
        {        print("You need a cup for the water.");        }      else
        {        print("You fill your cup with ocean water.");        get("Ocean Water*");        drop("Empty Cup");        if (!isset(f102))
          {          set(f102);          currentScore  += 1;          }        }      }    }  }return();[ Messages#message 1 "The lush foliage of the forest has given way to the hardy plants of the shore. Sawgrass, bracken, and gnarled trees are all that grow here."#message 2 "The trees are bent and twisted by years of constant sea breezes."#message 3 "The sandy beach stretches north and south below steep, grassy cliffs."#message 4 "Your eyes sweep the vast ocean before you. Blue water stretches as far as you can see. Way in the distance it melts with the sky."#message 5 "You see seagulls flying overhead."#message 6 "The water looks inviting, but be careful if you go out there."#message 7 "The birds wheel and glide overhead."#message 8 "You fill your cup with ocean water."#message 9 "You need a cup for the water."#message 10 "You need to move closer."#message 11 "Drinking salt water will only make you sick."#message 12 "Your cup is already full of water."