if (isset(newRoom))
  {  set(f34);  v32 = 104;  v31 = 134;  v57 = 55;  v58 = 141;  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.sound(Sound32);  reset(f238);  load.view(View0);  load.view(View24);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  animate.obj(o2);  load.view(View79);  set.view(o2, View79);  add.to.pic(View79, 0, 0, 51, 136, 1, 1);  position(o2, 51, 136);  v36 = 3;  cycle.time(o2, v36);  stop.cycling(o2);  ignore.blocks(o2);  draw(o2);  animate.obj(o1);  load.view(View78);  set.view(o1, View78);  position(o1, 61, 109);  v36 = 2;  step.time(o1, v36);  cycle.time(o1, v36);  draw(o1);  if ((isset(f48) ||       v44 == 25))
    {    position(ego, 117, 136);    if (v44 == 0)
      {      set(f221);      move.obj(ego, 92, 136, 1, f223);      }    else
      {      v222 = 4;      set(f221);      }    }  if (v44 == 30)
    {    set(f48);    set(f47);    set(f221);    position(ego, 92, 136);    }  if (isset(f47))
    {    draw(ego);    }  show.pic();  sound(Sound32, f238);  return();  }if (isset(f223))
  {  reset(f223);  start.motion(ego);  }if (isset(f33))
  {  set(f221);  if (v44 != 0)
    {    v222 = 4;    v223 = 0;    }  }v39 = 0;if (posn(ego, 58, 131, 108, 133))
  {  v39 = 1;  }if (posn(ego, 48, 131, 67, 140))
  {  v225 = 6;  v39 = 2;  }if (isset(f45) &&     v225 > 0)
  {  start.cycling(o2);  if (!isset(f46))
    {    --v225;    }  if (v225 == 0)
    {    set.cel(o2, 0);    stop.cycling(o2);    }  }if (isset(f45) &&     v223 > 0)
  {  if (!isset(f46))
    {    --v223;    }  if (v223 == 0)
    {    set(f221);    }  }if (isset(f221) &&     v222 == 0)
  {  ++v222;  v223 = 0;  v37 = 92;  v38 = 109;  v36 = 1;  start.cycling(o1);  move.obj.v(o1, v37, v38, v36, f221);  }if (isset(f221) &&     v222 == 1)
  {  ++v222;  v223 = 0;  set.loop(o1, 2);  stop.cycling(o1);  reset(f221);  v223 = 1;  }if (isset(f221) &&     v222 == 2)
  {  ++v222;  v223 = 0;  if (v224 == 0)
    {    print("\"Good day to you, young man,\" greets the store keeper. \"What can "          "I do for you?\"");    ++v224;    }  else
    {    print("The storekeeper asks \"Now, what can I do for you?\"");    }  reset(f221);  v223 = 30;  }if (isset(f221) &&     v222 == 3)
  {  ++v222;  reset(f222);  v223 = 0;  print("\"I've got some dusting to do,\" the shopkeeper says, turning around. "        "\"Just let me know when you need something.\"");  set(f221);  }if (isset(f221) &&     v222 == 4)
  {  ++v222;  v223 = 0;  start.cycling(o1);  v38 = 109;  random(56, 92, v37);  v36 = 1;  move.obj.v(o1, v37, v38, v36, f221);  }if (isset(f221) &&     v222 == 5)
  {  v223 = 0;  v222 = 4;  reset(f221);  set.loop(o1, 3);  start.cycling(o1);  random(2, 3, v223);  }if (isset(f221) &&     v222 == 6)
  {  ++v222;  v223 = 0;  v38 = 109;  v226 = v40;  random(56, 92, v37);  v36 = 1;  start.cycling(o1);  move.obj.v(o1, v37, v38, v36, f221);  prevent.input();  program.control();  }if (isset(f221) &&     v222 == 7)
  {  v223 = 0;  ++v222;  set.loop(o1, 3);  set.cel(o1, 0);  start.cycling(o1);  prevent.input();  program.control();  reset(f221);  }if (v222 == 8)
  {  current.cel(o1, v36);  if (v36 == 6)
    {    set(f221);    }  }if (isset(f221) &&     v222 == 8)
  {  v223 = 0;  ++v222;  v38 = 109;  start.cycling(o1);  v36 = 1;  move.obj.v(o1, v226, v38, v36, f221);  prevent.input();  program.control();  }if (isset(f221) &&     v222 == 9)
  {  reset(f221);  print.v(v227);  set.loop(o1, 2);  print("\"What else can I get for you?\" asks the amiable storekeeper.");  set(f222);  stop.cycling(o1);  v222 = 3;  v223 = 10;  accept.input();  player.control();  }if (v221 != v63)
  {  v221 = v63;  if (v63 == 0)
    {    if (has("Purse and Gold Coins*"))
      {      drop("Purse and Gold Coins*");      }    get("Empty Purse*");    }  }if (isset(haveInput))
  {  if (said("dog", "last"))
    {    print("Why, \"Ration\", of course!");    }  if ((said("examine") ||       said("examine", "area") ||       said("examine", "shop")))
    {    print("The store is full of general merchandise and supplies to meet the "          "needs of the village. A friendly storekeeper bustles busily behind "          "the counter.");    }  if ((said("examine", "goods") ||       said("examine", "bookcase")))
    {    print("The shelves are filled with all sorts of useful items. There are a "          "few items of particular interest to you: leather pouches, salt, fish "          "oil, and lard.");    }  if ((said("examine", "bandit") ||       said("examine", "shop", "bandit")))
    {    print("The short, balding storekeeper seems to be an amiable fellow.");    }  if ((said("examine", "out", "glass") ||       said("examine", "out", "door") ||       said("examine", "out")))
    {    print("Outside, you see the village and the ocean.");    }  if ((said("examine", "on", "deck") ||       said("examine", "deck")))
    {    print("A brown-spotted dog lies on the floor.");    }  if (said("examine", "door"))
    {    print("The door is open fully to the sea breezes.");    }  if ((said("examine", "oven") ||       said("examine", "oven")))
    {    print("The woodstove is hard at work heating the little store. It is chilly "          "here, so close to the ocean.");    }  if (said("pat", "dog"))
    {    if (v39 != 2)
      {      print("You need to be closer.");      }    else
      {      v225 = 5;      if (!obj.in.room("Dog Hair*", currentRoom))
        {        print("As you pet him, Kenny licks your hand and thumps his tail in "              "appreciation.");        }      else
        {        get("Dog Hair*");        currentScore  += 1;        print("%m40 A small wad of dog fur collects in your hand, and you tuck "              "it into your pocket for later use.");        }      }    }  if ((said("capture", "fur") ||       said("capture", "dog", "fur") ||       said("capture", "fur", "dog")))
    {    if (!obj.in.room("Dog Hair*", currentRoom))
      {      print("You already have some dog fur.");      }    else
      {      if (v39 != 2)
        {        print("You need to be closer.");        }      else
        {        v225 = 6;        get("Dog Hair*");        currentScore  += 1;        print("%m40 A small wad of dog fur collects in your hand, and you tuck "              "it into your pocket for later use.");        }      }    }  if (said("call", "dog"))
    {    v225 = 6;    print("You speak to the dog in a soothing voice, and his ears perk up. \"Go "          "ahead and pet him,\" says the storekeeper. \"Kenny loves "          "attention.\"");    }  if (said("examine", "dog"))
    {    print("The dog lying on the floor is obviously a mutt. The name, \"Kenny\", "          "is embossed on his leather collar.");    }  if ((said("hit", "dog") ||       said("drink", "dog")))
    {    print("You must be kidding.");    }  if (said("capture", "dog"))
    {    print("Kenny belongs to the storekeeper.");    }  if (said("capture", "bandit"))
    {    print("He won't let you!");    }  if ((said("kill", "dog") ||       said("kill", "bandit")))
    {    print("You're not that cruel!");    }  if (said("capture", "anyword"))
    {    print("This is a business, not a charity. You have to buy the things you "          "want.");    }  if (said("jump"))
    {    print("How high? Are you a rabbit?");    }  if ((said("jump", "counter") ||       said("jump", "above", "counter")))
    {    print("Don't jump the counter. The storekeeper would get mad.");    }  if (said("rob", "anyword"))
    {    print("That is not a smart idea. The storekeeper is keeping an eye on you!");    }  if (said("buy"))
    {    print("The storekeeper asks \"Now, what can I do for you?\"");    }  if (said("buy", "anyword"))
    {    if (v39 != 1)
      {      print("You need to move closer to the counter.");      }    else
      {      if (v63 == 0)
        {        print("You don't have any money.");        }      else
        {        reset(haveMatch);        if (said("buy", "grains of salt"))
          {          if (!obj.in.room("Salt*", currentRoom))
            {            print("You already bought it. You don't need any more.");            goto(Label1);            }          get("Salt*");          currentScore  += 1;          }        if (said("buy", "lard"))
          {          if (!obj.in.room("Lard*", currentRoom))
            {            print("You already bought it. You don't need any more.");            goto(Label1);            }          get("Lard*");          currentScore  += 1;          }        if ((said("buy", "fish", "fish oil") ||             said("buy", "fish oil") ||             said("buy", "fish oil")))
          {          if (!obj.in.room("Fish Oil*", currentRoom))
            {            print("You already bought it. You don't need any more.");            goto(Label1);            }          get("Fish Oil*");          currentScore  += 1;          }        if ((said("buy", "pouch") ||             said("buy", "abominable", "pouch")))
          {          if (!obj.in.room("Empty Pouch*", currentRoom))
            {            print("You already bought it. You don't need any more.");            goto(Label1);            }          get("Empty Pouch*");          currentScore  += 1;          }        if (isset(haveMatch))
          {          random(21, 25, v227);          --v63;          v223 = 0;          v222 = 6;          set(f221);          }Label1:        if (said("buy", "food"))
          {          print("\"Try the tavern across the street,\" the friendly storekeeper "                "says.");          }        if (said("buy", "goods"))
          {          print("\"The store is full of supplies,\" the balding shopkeeper "                "tells you. \"What would you like?\"");          }        if ((said("buy", "ale") ||             said("buy", "ale") ||             said("buy", "ale")))
          {          print("\"Try the tavern across the street,\" the friendly storekeeper "                "says.");          }        if (said("buy", "anyword"))
          {          print("You have no use for %w2.");          }        }      }    }  if (said("call", "bandit"))
    {    if (v39 != 1)
      {      random(31, 37, v36);      print.v(v36);      }    else
      {      v222 = 0;      set(f221);      }    }  }if (isset(egoHitSpecial))
  {  new.room(Logic24);  }else
  {  if (v37 > 123)
    {    new.room(Logic24);    }  }return();[ Messages#message 1 "The door is open fully to the sea breezes."#message 2 "The store is full of general merchandise and supplies to meet the needs of the village. A friendly storekeeper bustles busily behind the counter."#message 3 "The shelves are filled with all sorts of useful items. There are a few items of particular interest to you: leather pouches, salt, fish oil, and lard."#message 4 "The short, balding storekeeper seems to be an amiable fellow."#message 5 "Outside, you see the village and the ocean."#message 6 "The woodstove is hard at work heating the little store. It is chilly here, so close to the ocean."#message 7 "That is not a smart idea. The storekeeper is keeping an eye on you!"#message 8 "The storekeeper asks \"Now, what can I do for you?\""#message 9 "\"I'll be right with you sir,\" the storekeeper tells you."#message 10 "You don't have any money."#message 11 "\"Try the tavern across the street,\" the friendly storekeeper says."#message 12 "\"The store is full of supplies,\" the balding shopkeeper tells you. \"What would you like?\""#message 13 "\"I've got some dusting to do,\" the shopkeeper says, turning around. \"Just let me know when you need something.\""#message 14 "The shopkeeper offers, \"Let me know if I can be of any help to you, sir.\""#message 15 "You have no use for %w2."#message 16 ""#message 17 "This is a business, not a charity. You have to buy the things you want."#message 18 "How high? Are you a rabbit?"#message 19 "You need to move closer to the counter."#message 20 "That will be one gold coin."#message 21 "Smiling, the storekeeper says, \"You will be very happy with this %w2, %m20\""#message 22 "\"A fine choice indeed, young man,\" the storekeeper says, smiling. \"%m20\""#message 23 "\"You have purchased the finest %w2 in the land,\" the friendly storekeeper informs you. \"%m20\""#message 24 "With a smile the storekeeper says, \"I guarantee you will be happy with this %w2, young sir. %m20\""#message 25 "\"A wise purchase sir,\" the balding storekeeper states. \"You will find no better %w2 in the land. %m20\""#message 26 "\"Good day to you, young man,\" greets the store keeper. \"What can I do for you?\""#message 27 "\"What else can I get for you?\" asks the amiable storekeeper."#message 28 "Don't jump the counter. The storekeeper would get mad."#message 29 "You do not have it."#message 30 "You already bought it. You don't need any more."#message 31 "You speak to the storekeeper. He answers, \"Feel free to browse, sir. If you want to buy something, let me know.\""#message 32 "\"The weather is unsettled. We may have a storm soon,\" the storekeeper comments."#message 33 "\"What may I do for you today, sir?\" the storekeeper offers."#message 34 "The clerk responds, \"The day's turned a bit nippy, eh?\""#message 35 "\"How do you do, sir. Hope the day is treating you well,\" the shopkeeper says with a smile."#message 36 "\"Wasn't it a shame about the wreck of the Lisa May?\" the storekeeper responds."#message 37 "The storekeeper looks you over, \"Looks like you could use some new clothes, sonny.\""#message 38 "You need to be closer."#message 39 ""#message 40 "As you pet him, Kenny licks your hand and thumps his tail in appreciation."#message 41 "%m40 A small wad of dog fur collects in your hand, and you tuck it into your pocket for later use."#message 42 "You already have some dog fur."#message 43 "You speak to the dog in a soothing voice, and his ears perk up. \"Go ahead and pet him,\" says the storekeeper. \"Kenny loves attention.\""#message 44 "The dog lying on the floor is obviously a mutt. The name, \"Kenny\", is embossed on his leather collar."#message 45 "You must be kidding."#message 46 "Why, \"Ration\", of course!"#message 47 "A brown-spotted dog lies on the floor."#message 49 "Kenny belongs to the storekeeper."#message 50 "You're not that cruel!"#message 51 "He won't let you!"