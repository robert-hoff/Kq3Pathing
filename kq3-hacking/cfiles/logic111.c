if (isset(newRoom))
  {  random(1, 4, v36);  if ((v36 > 2 ||       v44 == 26 ||       v44 == 25))
    {    return();    }  if (currentRoom != 12 &&       currentRoom != 13 &&       currentRoom != 17 &&       currentRoom != 27)
    {    return();    }  if (v36 == 1)
    {    set(f248);    load.view(View52);    animate.obj(o12);    set.view(o12, View52);    ignore.horizon(o12);    ignore.objs(o12);    set.priority(o12, 15);    stop.cycling(o12);    animate.obj(o13);    set.view(o13, View52);    ignore.horizon(o13);    ignore.objs(o13);    set.priority(o13, 15);    stop.cycling(o13);    if (currentRoom == 12)
      {      set.loop(o12, 3);      set.loop(o13, 2);      position(o12, 116, 51);      position(o13, 93, 50);      }    if (currentRoom == 13)
      {      set.loop(o12, 0);      set.loop(o13, 1);      position(o12, 5, 113);      position(o13, 34, 114);      }    if (currentRoom == 17)
      {      set.loop(o12, 0);      set.loop(o13, 1);      position(o12, 89, 58);      position(o13, 103, 54);      }    if (currentRoom == 27)
      {      set.loop(o12, 0);      set.loop(o13, 1);      position(o12, 58, 65);      position(o13, 71, 89);      }    random(1, 2, v36);    if (has("Dough in Ears") &&         v36 == 1 &&         (!isset(f131) ||         !isset(f132) ||         !isset(f133) ||         !isset(f134)))
      {Label1:      random(1, 4, v36);      if (v36 == 1)
        {        if (isset(f131))
          {          goto(Label1);          }        else
          {          v253 = 131;          v248 = 21;          v249 = 23;          }        }      if (v36 == 2)
        {        if (isset(f132))
          {          goto(Label1);          }        else
          {          v253 = 132;          v248 = 24;          v249 = 26;          }        }      if (v36 == 3)
        {        if (isset(f133))
          {          goto(Label1);          }        else
          {          v253 = 133;          v248 = 27;          v249 = 29;          }        }      if (v36 == 4)
        {        if (isset(f134))
          {          goto(Label1);          }        else
          {          v253 = 134;          v248 = 30;          v249 = 31;          }        }      random(3, 10, v250);      }    }  else
    {    set(f247);    load.view(View51);    animate.obj(o12);    set.view(o12, View51);    ignore.horizon(o12);    ignore.objs(o12);    set.priority(o12, 15);    stop.cycling(o12);    animate.obj(o13);    set.view(o13, View51);    ignore.horizon(o13);    ignore.objs(o13);    set.priority(o13, 15);    stop.cycling(o13);    if (currentRoom == 12)
      {      set.loop(o12, 2);      set.loop(o13, 3);      position(o12, 139, 134);      position(o13, 150, 116);      }    if (currentRoom == 13)
      {      set.loop(o12, 2);      set.loop(o13, 3);      position(o12, 0, 118);      position(o13, 31, 122);      }    if (currentRoom == 17)
      {      set.loop(o12, 0);      set.loop(o13, 1);      position(o12, 34, 41);      position(o13, 59, 30);      }    if (currentRoom == 27)
      {      set.loop(o12, 0);      set.loop(o13, 1);      position(o12, 50, 118);      position(o13, 74, 107);      }    random(1, 2, v36);    if (has("Dough in Ears") &&         v36 == 1 &&         (!isset(f139) ||         !isset(f140) ||         !isset(f141) ||         !isset(f142)))
      {Label2:      random(1, 4, v36);      if (v36 == 1)
        {        if (isset(f139))
          {          goto(Label2);          }        else
          {          v253 = 139;          v248 = 32;          v249 = 36;          }        }      if (v36 == 2)
        {        if (isset(f140))
          {          goto(Label2);          }        else
          {          v253 = 140;          v248 = 37;          v249 = 39;          }        }      if (v36 == 3)
        {        if (isset(f141))
          {          goto(Label2);          }        else
          {          v253 = 141;          v248 = 40;          v249 = 41;          }        }      if (v36 == 4)
        {        if (isset(f142))
          {          goto(Label2);          }        else
          {          v253 = 142;          v248 = 42;          v249 = 44;          }        }      random(3, 10, v250);      }    }  draw(o12);  draw(o13);  v251 = 2;  v252 = 12;  }if (isset(haveInput))
  {  if ((said("examine", "brush") ||       said("examine", "deck")))
    {    print("The soft grass soothes your aching feet.");    }  if ((said("examine", "forest") ||       said("examine", "forest") ||       said("examine")))
    {    print("The many beautiful trees bring a sense of peace to this forest.");    }  if (said("examine", "desert"))
    {    print("If you look way off to the west, you can see the desert.");    }  if (said("examine", "flower"))
    {    print("This is the wrong time of the year for wildflowers.");    }  if (said("examine", "sky"))
    {    print("The clear, blue sky is brilliant with an occasional white cloud.");    }  if ((said("capture", "flower") ||       said("capture", "flower")))
    {    print("There are no flowers in this area.");    }  if ((said("climb", "forest") ||       said("climb", "forest")))
    {    print("You see no suitable trees for climbing.");    }  if (said("examine", "rock"))
    {    print("If you've seen one rock, you've seen them all.");    }  if (said("examine", "bird"))
    {    if (isset(f248))
      {      print("You see two pretty birds looking at you.");      }    else
      {      print("You don't see any right now.");      }    }  if (said("examine", "animal"))
    {    if (isset(f247))
      {      print("You see two squirrels chattering to each other.");      }    else
      {      print("You don't see any right now.");      }    }  if (said("capture", "animal"))
    {    if (isset(f247))
      {      print("They're too difficult to catch.");      }    else
      {      print("You don't see any right now.");      }    }  if (said("capture", "bird"))
    {    if (isset(f248))
      {      print("They're too difficult to catch.");      }    else
      {      print("You don't see any right now.");      }    }  if (isset(f248) &&       has("Dough in Ears") &&       said("hear", "bird"))
    {    print("Maybe if you're quiet, you'll hear them.");    }  if (isset(f247) &&       has("Dough in Ears") &&       said("hear", "animal"))
    {    print("Maybe if you're quiet, you'll hear them.");    }  if (!isset(f91))
    {    if (said("anyword", "cactii"))
      {      print("Where?");      }    }  else
    {    if (said("capture", "cactii"))
      {      print("All of the cactus around here are too prickly to be touched. You "            "could wind up with a handful of thorns.");      }    if (said("anyword", "cactii"))
      {      print("It is a handsome example of the species, but not one you'd care to "            "handle. Look at those thorns!");      }    }  }--v251;if (v251 == 1)
  {  toggle(f250);  if (isset(f250))
    {    start.cycling(o12);    random(9, 22, v251);    }  else
    {    stop.cycling(o12);    random(9, 44, v251);    }  }--v252;if (v252 == 1)
  {  toggle(f251);  if (isset(f251))
    {    start.cycling(o13);    random(9, 22, v252);    }  else
    {    stop.cycling(o13);    random(9, 44, v252);    }  }if (isset(f45) &&     v248 > 0 &&     v44 == 0 &&     v47 == v250)
  {  v250 = 0;  set.v(v253);Label3:  print.v(v248);  if (v248 < v249)
    {    ++v248;    goto(Label3);    }  }return();[ Messages#message 1 "The soft grass soothes your aching feet."#message 2 "The many beautiful trees bring a sense of peace to this forest."#message 3 "If you look way off to the west, you can see the desert."#message 4 "This is the wrong time of the year for wildflowers."#message 5 "%m1"#message 6 "The clear, blue sky is brilliant with an occasional white cloud."#message 7 "There are no flowers in this area."#message 8 "You see no suitable trees for climbing."#message 9 "If you've seen one rock, you've seen them all."#message 10 "You see two pretty birds looking at you."#message 11 "You see two squirrels chattering to each other."#message 12 "They're too difficult to catch."#message 13 "You don't see any right now."#message 14 "Maybe if you're quiet, you'll hear them."#message 15 "All of the cactus around here are too prickly to be touched. You could wind up with a handful of thorns."#message 16 "Where?"#message 17 "It is a handsome example of the species, but not one you'd care to handle. Look at those thorns!"#message 21 "You listen with great interest as one little bird chirps to the other, \"Notice that boy down there? He's got a sister he doesn't even know. A TWIN sister.\""#message 22 "Answers the second bird, \"How sad. I don't know what I'd do without all my brothers and sisters. I'd be so alone.\""#message 23 "\"I know what you mean,\" agrees the first."#message 24 "Your ears perk up as you hear one twittering bird say to her friend, \"Do you think that young man looks anything like his twin sister in Daventry?\""#message 25 "\"I don't know, but I hear her beauty is legendary,\" chirps the other bird."#message 26 "\"Well, he ain't exactly chopped liver, either,\" the first little bird states."#message 27 "\"I'm getting so frustrated!\" one little bird twitters to the other. \"No matter how early I get up, I just can't seem to ever catch that darn worm!!\""#message 28 "\"Poor dear,\" says her friend. \"I know you can do it. You can't let a dumb worm outsmart you!\""#message 29 "\"Hah!\" the first bird laments. \"That's easy for you to say. I bet you've never even tried!\""#message 30 "You hear one of the birds speak to the other, \"See that young fellow over there? When that old wizard, Manannan, kidnapped him, I heard tell his real parents were heartbroken over his loss.\""#message 31 "\"I would think so!\" chirped the other bird. \"I'd sure miss my brood if they disappeared!\""#message 32 "You notice one squirrel chattering to the other squirrel, \"See that young man over there?\""#message 33 "\"Yes, what about him?\" the second one inquires."#message 34 "\"Poor thing, he doesn't even know who his parents are,\" says the first squirrel."#message 35 "Asks the other, \"Well, who are they?\""#message 36 "\"He's really a prince. His parents are King Graham and Queen Valanice of Daventry,\" replies the first."#message 37 "\"That boy over there lives with the terrible wizard,\" one scampering squirrel remarks to its companion."#message 38 "\"How awful for him,\" says the other squirrel. \"I wonder how he can stand it.\""#message 39 "Comments the first, \"I bet he can't. He ought to learn magic. He's got to fight fire with fire.\""#message 40 "Chatters one squirrel to the other, \"Manannan's terrorizing the countryside again. I'm afraid for my life.\""#message 41 "\"I know how you feel,\" replies the second. \"I understand he's fond of squirrel tails.\""#message 42 "You overhear the squirrels chattering. \"Have you got your winter's supply of nuts gathered?\" one inquires."#message 43 "\"Not quite yet,\" answers the other. \"Do you?\""#message 44 "\"Oh sure,\" states the first squirrel. \"Ages ago. You'd better get to it, I'd say.\""