if (isset(newRoom))
  {  return();  }if (!isset(f46))
  {  if (isset(onWater) &&       !isset(f38) &&       v138 != 224)
    {    set.view(ego, View7);    v138 = 7;    }  if (!isset(onWater) &&       v138 != 0)
    {    set.view(ego, View0);    v138 = 0;    }  }if (!isset(haveInput))
  {  goto(Label1);  }if ((said("examine") ||     said("examine", "deck")))
  {  print("There is a rushing stream flowing through the forest floor.");  }if ((said("examine", "creek") ||     said("examine", "liquid")))
  {  print("Clear water flows over and around the rocks of the stream. Wet mud "        "lines its banks.");  }if ((said("capture", "mud") ||     said("capture", "mud", "creek") ||     said("capture", "mud", "from", "creek") ||     said("capture", "mud", "from", "creek", "try", "ladle") ||     said("capture", "mud", "try", "ladle")))
  {  if (has("Mud*"))
    {    print("You are already carrying it.");    }  else
    {    if (!isset(f90))
      {      print("There is no mud around here.");      }    else
      {      if (!has("Spoon"))
        {        print("The thought of carrying around a handful of mud doesn't appeal "              "to you.");        }      else
        {        print("With the wooden spoon you kneel and scoop a spoonful of wet mud "              "from the stream's bank. You carry it with you.");        get("Mud*");        drop("Spoon");        if (!isset(f110))
          {          set(f110);          currentScore  += 1;          }        }      }    }  }if ((said("capture", "liquid", "creek") ||     said("capture", "liquid") ||     said("capture", "liquid", "cup")))
  {  print("You have no need to carry around the stream water. If you are thirsty "        "then just get a drink.");  }if ((said("capture", "drink", "liquid", "creek") ||     said("creek", "capture", "drink", "liquid") ||     said("capture", "drink", "liquid") ||     said("capture", "drink") ||     said("drink", "liquid") ||     said("drink")))
  {  if (isset(f75))
    {    print("Cupping your hands, you bring the refreshing water to your lips and "          "drink deeply. Aaahhhh!!");    }  else
    {    print("You need to move closer.");    }  }Label1:return();[ Messages#message 1 "There is a rushing stream flowing through the forest floor."#message 2 ""#message 3 "Clear water flows over and around the rocks of the stream. Wet mud lines its banks."#message 4 "The thought of carrying around a handful of mud doesn't appeal to you."#message 5 "With the wooden spoon you kneel and scoop a spoonful of wet mud from the stream's bank. You carry it with you."#message 6 "You only need one spoonful of mud."#message 7 "You have no need to carry around the stream water. If you are thirsty then just get a drink."#message 8 "Cupping your hands, you bring the refreshing water to your lips and drink deeply. Aaahhhh!!"#message 9 "You are already carrying it."#message 10 "There is no mud around here."#message 11 "You need to move closer."#message 12 "You need a spoon to get mud."