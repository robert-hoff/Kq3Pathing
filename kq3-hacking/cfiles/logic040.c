if (isset(newRoom))
  {  v32 = 89;  v31 = 154;  v57 = 91;  v58 = 153;  set(f34);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.view(View0);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  if ((isset(f48) ||       v44 == 25))
    {    position(ego, 72, 165);    }  if (v44 == 25)
    {    v230 = 7;    }  block(59, 128, 62, 131);  animate.obj(o4);  load.view(View76);  set.view(o4, View76);  position(o4, 78, 121);  draw(o4);  stop.cycling(o4);  set.loop(o4, 2);  v229 = 5;  if (v62 == 1)
    {    v221 = 1;    load.view(View164);    animate.obj(o3);    set.view(o3, View164);    position(o3, 58, 149);    set.loop(o3, 2);    set.cel(o3, 3);    stop.cycling(o3);    draw(o3);    animate.obj(o1);    set.view(o1, View164);    position(o1, 43, 154);    set.loop(o1, 0);    set.cel(o1, 0);    stop.cycling(o1);    draw(o1);    animate.obj(o2);    set.view(o2, View164);    position(o2, 52, 152);    set.loop(o2, 1);    set.cel(o2, 2);    stop.cycling(o2);    draw(o2);    }  else
    {    random(1, 3, v36);    if (v36 < 2)
      {      v221 = 0;      }    else
      {      v221 = 2;      load.view(View209);      animate.obj(o1);      set.view(o1, View209);      position(o1, 41, 143);      set.loop(o1, 1);      set.cel(o1, 0);      set.priority(o1, 13);      stop.cycling(o1);      ignore.objs(o1);      draw(o1);      animate.obj(o2);      set.view(o2, View209);      position(o2, 52, 152);      set.loop(o2, 0);      set.cel(o2, 0);      set.priority(o2, 14);      stop.cycling(o2);      draw(o2);      }    }  if (isset(f47))
    {    draw(ego);    }  v225 = 1;  if (v221 != 0)
    {    random(3, 7, v226);    }  if (v221 == 1)
    {    load.sound(Sound29);    sound(Sound29, f238);    }  if (v221 == 2)
    {    load.sound(Sound26);    sound(Sound26, f238);    }  if (v221 == 0)
    {    load.sound(Sound28);    sound(Sound28, f238);    }  show.pic();  return();  }if (v62 == 1 &&     v53 <= 0 &&     v52 < 30 &&     v52 > 0)
  {  v52 = 30;  }v39 = 0;if (posn(ego, 40, 134, 73, 162))
  {  v39 = 1;  }if (posn(ego, 56, 124, 114, 133))
  {  v39 = 2;  }if (isset(f45) &&     v226 > 0)
  {  if (!isset(f46))
    {    --v226;    }  if (v226 == 0)
    {    set(f225);    }  }if (isset(f225) &&     v225 == 0)
  {  ++v225;  stop.cycling(o4);  set.loop(o4, 2);  reset(f225);  }if (isset(f225) &&     v225 == 1)
  {  if (!isset(f228))
    {    if (v221 == 1)
      {      print("One of the rowdy seamen yells to the barmaid, \"Wench! Come o'er "            "here with more rum!\"");      }    else
      {      print("One of the surly-looking characters yells to the barmaid, \"Wench! "            "Come o'er here with more ale!\"");      }    }  reset(f228);  ++v225;  start.cycling(o4);  move.obj(o4, 49, 125, 1, f225);  }if (isset(f225) &&     v225 == 2)
  {  ++v225;  start.cycling(o4);  move.obj(o4, 49, 140, 1, f225);  }if (isset(f225) &&     v225 == 3)
  {  ++v225;  stop.cycling(o4);  reset(f225);  v226 = 3;  }if (isset(f225) &&     v225 == 4)
  {  ++v225;  start.cycling(o4);  move.obj(o4, 49, 125, 1, f225);  }if (isset(f225) &&     v225 == 5)
  {  ++v225;  start.cycling(o4);  move.obj(o4, 77, 125, 1, f225);  }if (isset(f225) &&     v225 == 6)
  {  v225 = 0;  stop.cycling(o4);  move.obj(o4, 77, 121, 1, f225);  random(30, 120, v226);  }random(1, 20, v36);if (v221 == 1)
  {  if (v36 == 1)
    {    last.cel(o3, v37);    current.cel(o3, v38);    ++v38;    if (v38 > v37)
      {      v38 = 0;      }    if (isset(f222))
      {      v38 = 0;      }    set.cel.v(o3, v38);    }  if (v36 == 2)
    {    last.cel(o1, v37);    current.cel(o1, v38);    ++v38;    if (v38 > v37)
      {      v38 = 0;      }    set.cel.v(o1, v38);    }  if (v36 == 3)
    {    last.cel(o2, v37);    current.cel(o2, v38);    ++v38;    if (v38 > v37)
      {      v38 = 0;      }    set.cel.v(o2, v38);    }  }if (v221 == 2)
  {  if (v36 == 1)
    {    last.cel(o1, v37);    current.cel(o1, v38);    ++v38;    if (v38 > v37)
      {      v38 = 0;      }    set.cel.v(o1, v38);    }  if (v36 == 2)
    {    last.cel(o2, v37);    current.cel(o2, v38);    ++v38;    if (v38 > v37)
      {      v38 = 0;      }    set.cel.v(o2, v38);    }  }if (v221 != 0 &&     posn(ego, 33, 138, 70, 154) &&     (v44 == 0 ||     v44 == 19))
  {  start.motion(ego);  reposition.to.v(ego, v42, v43);  }if (isset(f45) &&     v227 > 0)
  {  --v227;  if (v227 == 0)
    {    reset(f227);    player.control();    release.loop(ego);    v44 = 0;    }  }if (v44 == 19 &&     egoDir != STOPPED)
  {  --v228;  if (v228 == 1)
    {    if (isset(f227))
      {      reset(f227);      player.control();      release.loop(ego);      v228 = 6;      }    else
      {      set(f227);      program.control();      fix.loop(ego);Label1:      random(1, 8, v36);      if (v36 == egoDir)
        {        goto(Label1);        }      egoDir = v36;      v228 = 5;      }    }  }if (isset(f33) &&     v44 == 25)
  {  v230 = 7;  }if (isset(f45))
  {  --v230;  if (v230 == 1 &&       v44 == 25 &&       posn(ego, 0, 0, 160, 160) &&       v221 == 2 &&       !isset(f221))
    {    print("You overhear snatches of the two bandits' conversation, "          "\"...squirmed jist like a pig. An' that rope ya rigged inside o' "          "that big oak tree works great! Now nobody'll 'ere find ar' hideout. "          "Why, I'll bet even that wizard...\"");    set(f221);    currentScore  += 3;    }  }if (isset(f222) &&     !isset(f224))
  {  --v51;  if (v51 == 0)
    {    print.v(v222);    ++v222;    v51 = 200;    if (v222 == 31)
      {      set(f224);      }    }  }if (v223 != v63)
  {  v223 = v63;  if (v63 == 0)
    {    if (has("Purse and Gold Coins*"))
      {      drop("Purse and Gold Coins*");      }    get("Empty Purse*");    }  }if (has("Purse and Gold Coins*") &&     v63 > 0)
  {  set(f220);  }else
  {  reset(f220);  }if (isset(haveInput))
  {  if ((said("get in", "counter") ||       said("get in", "down", "counter")))
    {    if (v221 == 0)
      {      print("You don't have time to be sitting around in taverns.");      }    else
      {      print("Your presence would not be appreciated.");      }    }  v36 = v221;  if ((said("examine") ||       said("examine", "area") ||       said("examine", "bar") ||       said("look in", "bar")))
    {    v36  += 3;    print.v(v36);    }  if ((said("examine", "barrel") ||       said("look in", "barrel")))
    {    print("Kegs of ale line the wall.");    }  if (said("examine", "counter"))
    {    if (v221 == 0)
      {      print("A table, devoid of customers, rests against the wall.");      }    else
      {      v36  += 7;      print.v(v36);      }    }  if ((said("examine", "bandit") ||       said("examine", "bandit")))
    {    v36  += 7;    print.v(v36);    }  if (said("examine", "barmaid"))
    {    print("The buxom barmaid has an air of hardened determination. You get the "          "feeling that she doesn't take any guff from anybody.");    }  if ((said("examine", "out", "glass") ||       said("examine", "glass") ||       said("examine", "door") ||       said("examine", "out")))
    {    print("You see the buildings of the village, and the ocean beyond.");    }  if (said("lift", "glass"))
    {    print("The window does not open.");    }  if ((said("capture", "bandit") ||       said("aim", "oven") ||       said("capture", "oven") ||       said("kill", "anyword")))
    {    print("Surely, you jest!");    }  if (said("examine", "oven"))
    {    print("It is a little pot-bellied woodstove.");    }  if (said("examine", "bar"))
    {    print("The bar is a rough-hewn slab of oak.");    }  if ((said("examine", "sword") ||       said("examine", "drapery") ||       said("examine", "cage")))
    {    print("A tattered, faded tapestry hangs next to a pair of rusty swords.");    }  if ((said("capture", "sword") ||       said("capture", "drapery")))
    {    print("The decorations are firmly attached to the wall, and will not come "          "off.");    }  if (said("examine", "below", "drapery"))
    {    print("You lift a corner of the tapestry, and see the dirty wall behind it.");    }  if (said("capture", "ale"))
    {    print("You need to buy it first.");    }  if ((said("examine", "bookcase") ||       said("examine", "bottle")))
    {    print("Bottles of rum and wine sit atop shelves behind the bar.");    }  if (said("examine", "ale"))
    {    print("Bottles of rum and wine sit atop shelves behind the bar. Kegs of ale "          "line the wall.");    }  if ((said("capture", "barmaid") ||       said("embrace", "barmaid")))
    {    print("\"Watch it, fella!\"");    }  if (v221 == 0)
    {    if ((said("call") ||         said("call", "barmaid")))
      {      print("She tosses her head, and replies, \"What'll it be fer ya, sir? A "            "good pull o' ale, or'd ya rather a dram o' rum? My, aren't ye the "            "han'some one!\"");      }    if ((said("call", "bandit") ||         said("examine", "bandit")))
      {      print("There is nobody here except the pretty barmaid.");      }    }  if ((said("buy", "drinks") ||       said("buy", "drinks", "bandit")))
    {    if (v221 == 0)
      {      print("There is nobody here except you and the barmaid.");      }    else
      {      if (!isset(f220))
        {        print("The barmaid retorts, \"Go on, ya deadbeat. Drinks cost money, ya "              "know!\"");        }      else
        {        --v63;        if (v225 == 1)
          {          print("\"Right ya go, sir.\" says the pretty barmaid. \"This round's "                "on you!\" \"It'll be one gold coin.\"");          v226 = 2;          set(f228);          }        else
          {          print("\"Right ya go, sir.\" says the pretty barmaid. \"The next "                "round's on you!\" \"That'll be one gold coin.\"");          }        }      }    }  if ((said("buy", "drink") ||       said("buy", "ale") ||       said("buy", "ale")))
    {    if (v225 != 1)
      {      print("\"I'll be right with ya sir,\" the barmaid says, winking.");      }    else
      {      if (v39 == 2)
        {        if (!isset(f220))
          {          print("The barmaid retorts, \"Go on, ya deadbeat. Drinks cost money, "                "ya know!\"");          }        else
          {          --v63;          if (v229 < 120)
            {            v229  += v229;            }          v227 = v229;          v228 = 10;          if (v44 != 19)
            {            v44 = 19;            print("The barmaid hands you a glass, and the potent liquid burns "                  "as it slides down your parched throat. It hits bottom, and "                  "you suddenly feel a bit woozy.");            }          else
            {            print("That one tasted even better than the last. Just one more "                  "sounds like a good idea.");            }          }        }      else
        {        print("You are too far away.");        }      }    }  if (v221 == 1)
    {    if ((said("call") ||         said("call", "barmaid")))
      {      print("%m36 \"What can I do fer ya sir? Can I get ya somethin'? I can't "            "spend much time with ya, 'cause I gotta handle these seafarin' "            "scoundrels that come inta town t'day.\"");      }    if (said("call"))
      {      print("Talk to whom?");      }    if (said("call", "bandit"))
      {      if (!isset(f222))
        {        if (v53 <= 0 &&             v52 <= 0)
          {          v53 = 15;          }        else
          {          if (v53 < 5)
            {            v53 = 5;            }          }        v222 = 28;        set(f222);        v226 = 0;        }      else
        {        v51 = 2;        }      if (isset(f224))
        {        print("The sailors just ignore you.");        }      }    if (isset(f222) &&         (said("feed", "coin", "rol") ||         said("feed", "coin purse", "rol")))
      {      if (isset(f224))
        {        print("The sailors just ignore you.");        }      else
        {        reset(f222);        if (isset(f220))
          {          currentScore  += 3;          drop("Purse and Gold Coins*");          v63 = 0;          v221 = 0;          erase(o1);          erase(o2);          erase(o3);          set(f79);          print("%m31 \"Aye lad, I sees ya do have a wee bit 'o gold. It's "                "less'n me reg'lar  fare, but I'll gives ya passage anyways. "                "We'll be waitin' fer ya at the wharf, but not fer long.\" The "                "captain and his men down their rum in one long draught, then "                "leave the tavern.");          }        else
          {          set(f224);          if (has("Empty Purse*"))
            {            drop("Empty Purse*");            print("%m31 %m33");            }          else
            {            print("\"Ya little cheat! Ya've got not a farthing! Ya was tryin' "                  "t' weasel aboard me ship!! Go on with ya, git outta me "                  "sight!\"");            }          }        }      }    }  if (v221 == 2)
    {    if ((said("call") ||         said("call", "barmaid")))
      {      print("%m36 Without taking her eyes off the two men, she says, \"I'll be "            "happy to take yer order, but be quick 'bout it 'cause those two "            "are keepin' me hoppin'.\"");      }    if (said("call"))
      {      print("Talk to whom?");      }    if (said("call", "bandit"))
      {      if (!isset(f226))
        {        set(f226);        print("One of the ugly rogues scowls at you as he says, \"Beat it, "              "kid!\"");        }      else
        {        print("The bandits are pointedly ignoring you. Don't press your luck.");        }      }    if (said("examine", "bandit"))
      {      print("The two scroungy thieves are dirty and unkempt, and their clothes "            "are smelly. Cruelty darkens their faces. These look like good "            "people to avoid.");      }    if ((said("kill", "bandit") ||         said("rob", "bandit")))
      {      print("Surely, you jest!");      }    }  }if (edgeEgoHit == BOTTOM_EDGE &&     v40 > 63 &&     v40 < 75)
  {  if (v44 == 19)
    {    v44 = 0;    }  new.room(Logic24);  }return();[ Messages#message 1 "One of the rowdy seamen yells to the barmaid, \"Wench! Come o'er here with more rum!\""#message 2 "Bottles of rum and wine sit atop shelves behind the bar."#message 3 "%m2 A pretty barmaid stands there."#message 4 "%m2 A loud group of seafaring men are drinking rum at the table. They are swapping yarns about past voyages. You overhear as they speak of setting sail today for a distant land across the ocean."#message 5 "%m2 Two surly-looking characters are drinking ale at the table. Looking closer, you see that they are the bandits from the forest!"#message 6 "\"There ya go, boys. Now, drink up an' behave yer selves."#message 7 "There is nobody here except you and the barmaid."#message 8 "The sailors have obviously been drinking heavily for some time, and are very loud and rowdy!"#message 9 "The two ruffians at the table see you looking at them, and glare back at you menacingly. It's the bandits from the forest!"#message 10 "The buxom barmaid has an air of hardened determination. You get the feeling that she doesn't take any guff from anybody."#message 11 "You overhear snatches of the two bandits' conversation, \"...squirmed jist like a pig. An' that rope ya rigged inside o' that big oak tree works great! Now nobody'll 'ere find ar' hideout. Why, I'll bet even that wizard...\""#message 12 "You see the buildings of the village, and the ocean beyond."#message 13 "Surely, you jest!"#message 14 "It is a little pot-bellied woodstove."#message 15 "The bar is a rough-hewn slab of oak."#message 16 "A tattered, faded tapestry hangs next to a pair of rusty swords."#message 17 "The decorations are firmly attached to the wall, and will not come off."#message 18 "You lift a corner of the tapestry, and see the dirty wall behind it."#message 19 "She tosses her head, and replies, \"What'll it be fer ya, sir? A good pull o' ale, or'd ya rather a dram o' rum? My, aren't ye the han'some one!\""#message 20 "The barmaid retorts, \"Go on, ya deadbeat. Drinks cost money, ya know!\""#message 21 "The barmaid hands you a glass, and the potent liquid burns as it slides down your parched throat. It hits bottom, and you suddenly feel a bit woozy."#message 22 "That one tasted even better than the last. Just one more sounds like a good idea."#message 23 "There is nobody here except the pretty barmaid."#message 24 "Talk to whom?"#message 25 "The sailors just ignore you."#message 26 "One of the ugly rogues scowls at you as he says, \"Beat it, kid!\""#message 27 "\"I'll be right with ya sir,\" the barmaid says, winking."#message 28 "The sailors peer at you through bleary eyes, and continue swilling their rum. One, who looks like the captain, pauses, and drunkenly slurs, \"Aye, me bucko, be ya wantin' passage on me ship? Whatcha runnin' from? Aw, s'no matter, 's long as ya got gold. Lets me see how much ya got!\""#message 29 "The drunken sea captain looks angry as he asks again, \" Don't ignore me laddie! I asked ya how much gold ya got fer passage on me ship?\""#message 30 "\"Too late bucko,\" the sea captain slurs. \"I ain' in'ersted in ya no more. Go pester some'un else.\""#message 31 "As you bring out the purse, the captain snatches it from your hand and says,"#message 32 "%m31 \"Aye lad, I sees ya do have a wee bit 'o gold. It's less'n me reg'lar  fare, but I'll gives ya passage anyways. We'll be waitin' fer ya at the wharf, but not fer long.\" The captain and his men down their rum in one long draught, then leave the tavern."#message 33 "\"Ya little cheat! Ya've got not a farthing! Ya was tryin' t' weasel aboard me ship!! Go on with ya, git outta me sight!\""#message 34 "%m36 \"What can I do fer ya sir? Can I get ya somethin'? I can't spend much time with ya, 'cause I gotta handle these seafarin' scoundrels that come inta town t'day.\""#message 35 "%m36 Without taking her eyes off the two men, she says, \"I'll be happy to take yer order, but be quick 'bout it 'cause those two are keepin' me hoppin'.\""#message 36 "\"Keep yer shirts on, ya ornery buzzards,\" the barmaid yells. \"I'll be there quick enough!\""#message 37 "You are too far away."#message 38 "The two scroungy thieves are dirty and unkempt, and their clothes are smelly. Cruelty darkens their faces. These look like good people to avoid."#message 39 "You signal the barmaid, \"I'd like to buy these two gentlemen a round.\""#message 40 "%m39 When she brings the drinks, you discover that you only have one coin. With a look of scorn, she takes your last coin and leaves one drink for the two oafs to fight over."#message 41 "%m39 If ya says so, sir,\" she replies. \"That'll be two gold, if ya please.\" The bandits down the drinks with nary a thank you."#message 42 "%m31 %m33"#message 43 "The bandits are pointedly ignoring you. Don't press your luck."#message 44 "You don't have time to be sitting around in taverns."#message 45 "Your presence would not be appreciated."#message 46 "Kegs of ale line the wall."#message 47 "You need to buy it first."#message 48 "\"Watch it, fella!\""#message 49 "A table, devoid of customers, rests against the wall."#message 50 "One of the surly-looking characters yells to the barmaid, \"Wench! Come o'er here with more ale!\""#message 51 "\"Right ya go, sir.\" says the pretty barmaid. \"This round's on you!\" \"It'll be one gold coin.\""#message 52 "\"Right ya go, sir.\" says the pretty barmaid. \"The next round's on you!\" \"That'll be one gold coin.\""#message 53 "The window does not open."#message 54 "Bottles of rum and wine sit atop shelves behind the bar. Kegs of ale line the wall."