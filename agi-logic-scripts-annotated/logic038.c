if (isset(newRoom))
  {  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.sound(Sound26);  load.view(View217);  animate.obj(o2);  v32 = 45;  v31 = 149;  v57 = 87;  v58 = 147;  set(f34);  load.view(View0);  load.view(View11);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  if (isset(f48))
    {    set.view(ego, View0);    position(ego, 89, 167);    start.motion(ego);    egoDir = UP;    v44 = 0;    }  set.view(o2, View217);  position(o2, 75, 108);  set.loop(o2, 0);  set.cel(o2, 0);  v36 = 4;  cycle.time(o2, v36);  draw(o2);  stop.update(o2);  animate.obj(o1);  load.view(View211);  load.view(View214);  if (v172 == 1 &&       v44 == 0)
    {    v172 = 1;    set.view(o1, View211);    position(o1, 89, 140);    v36 = 1;    cycle.time(o1, v36);    v222 = 1;    prevent.input();    set(f230);    }  else
    {    set.view(o1, View214);    v36 = 12;    cycle.time(o1, v36);    set.priority(o1, 13);    position(o1, 48, 137);    v222 = 0;    }  draw(o1);  if (obj.in.room("Purse and Gold Coins*", currentRoom))
    {    animate.obj(o3);    load.view(View216);    set.view(o3, View216);    set.priority(o3, 15);    position(o3, 60, 106);    draw(o3);    stop.update(o3);    }  if (isset(f47))
    {    draw(ego);    }  show.pic();  if (v44 != 30)
    {    sound(Sound26, f238);    if (v172 == 1)
      {      print("You have entered the bandits' hideout; one of them is coming after "            "you now!");      }    else
      {      print("You have entered the bandits' hideout; one of them is sleeping at "            "a small table.");      }    }  return();  }v39 = 0;if (posn(ego, 70, 106, 101, 124))
  {  v39 = 1;  }if (posn(ego, 55, 117, 69, 139))
  {  v39 = 2;  }if (!isset(f46) &&     v172 == 0 &&     isset(f45))
  {  random(1, 255, v37);  if (v37 == 1 &&       v44 == 0)
    {    v172 = 1;    set(f230);    }  }if (v222 == 0 &&     isset(f230))
  {  ++v222;  prevent.input();  v36 = 1;  cycle.time(o1, v36);  set.view(o1, View211);  move.obj(o1, 69, 137, 1, f230);  release.priority(o1);  v172 = 1;  print("The bandit opens his eyes and sees you in his hideout. He jumps up "        "from the chair and chases you.");  }if (v222 == 1 &&     isset(f230))
  {  ++v222;  follow.ego(o1, 8, f230);  }if (v222 == 2 &&     isset(f230) &&     v44 == 0)
  {  if (isset(f46))
    {    normal.motion(o1);    stop.motion(o1);    stop.cycling(o1);    }  else
    {    ++v222;    set(f46);    start.cycling(o1);    ignore.blocks(ego);    ignore.blocks(o1);    program.control();    get.posn(o1, v37, v38);    v37  += 2;    v38  += 6;    reposition.to.v(ego, v37, v38);    set.loop(ego, 2);    set.loop(o1, 2);    move.obj(o1, 86, 163, 1, f230);    move.obj(ego, 86, 163, 1, f230);    }  }if (v222 == 3 &&     isset(f230))
  {  ++v222;  reset(f230);  set.view(ego, View11);  v44 = 6;  edgeEgoHit = BOTTOM_EDGE;  print("The heartless thug drags you out the door and pushes you off the "        "porch.");  player.control();  currentRoom = 37;  new.room(Logic22);  }if (isset(f227))
  {  reset(f227);  stop.update(o2);  print("You slowly lift the lid, and hope the squeaky hinges do not wake the "        "bandit.");  }if (isset(f228))
  {  reset(f228);  stop.update(o2);  }if (isset(haveInput))
  {  if ((said("examine") ||       said("examine", "building")))
    {    print("The hideout is made of rough planks, sparsely furnished with a "          "table, a chair, and a small, wooden bin in the corner.");    }  if (said("examine", "bandit"))
    {    if (v172 == 1)
      {      print("The ugly bandit is dressed in dirty clothes. He looks, and smells, "            "as if he hasn't had a bath in months. He has a very threatening "            "look in his eyes!");      }    else
      {      print("The scoundrel is fast asleep at the table. He is dressed in dirty, "            "ragged clothes, and emits a very unpleasant odor.");      }    }  if ((said("examine", "counter") ||       said("examine", "above", "counter") ||       said("examine", "counter", "top")))
    {    if (obj.in.room("Purse and Gold Coins*", currentRoom))
      {      print("There is a leather coin purse lying on top of a wobbly table.");      }    else
      {      print("The wobbly, wooden table is made out of rough planks.");      }    }  if ((said("capture", "coin purse", "from", "counter") ||       said("capture", "coin purse", "counter") ||       said("capture", "coin") ||       said("capture", "coin purse")))
    {    if (obj.in.room("Purse and Gold Coins*", currentRoom) &&         v172 == 0)
      {      if (v39 == 2)
        {        start.update(o3);        erase(o3);        get("Purse and Gold Coins*");        if (!isset(f205))
          {          currentScore  += 4;          v63 = 8;          set(f205);          }        print("You very carefully lift the coin purse off the table; "              "practically out from under the sleeping bandit's nose!");        }      else
        {        print("You need to be closer.");        }      }    else
      {      print("That is not possible!");      }    }  if ((said("examine", "chest") ||       said("look in", "chest") ||       said("look in", "bin") ||       said("examine", "bin")))
    {    if (isset(f224))
      {      if (v39 == 1)
        {        if (isset(f78))
          {          print("This must be where the bandits store their loot! You see all "                "of your stolen possessions inside the bin.");          }        else
          {          print("There is nothing in the bin.");          }        }      else
        {        print("You need to be closer.");        }      }    else
      {      print("The shabby, wooden bin is built into a corner of the treehouse. It "            "is covered by a hinged lid.");      }    }  if ((said("lift", "chest") ||       said("lift", "cap", "chest") ||       said("lift", "bin") ||       said("lift", "cap", "bin") ||       said("lift", "cap")))
    {    if (v172 == 1)
      {      print("That is not possible!");      }    else
      {      if (isset(f224))
        {        print("The bin is already open.");        }      else
        {        if (v39 == 1)
          {          start.update(o2);          end.of.loop(o2, f227);          set(f224);          }        else
          {          print("You need to be closer.");          }        }      }    }  if ((said("close", "chest") ||       said("close", "cap", "chest") ||       said("close", "bin") ||       said("close", "cap", "bin") ||       said("close", "cap")))
    {    if (v172 == 1)
      {      print("That is not possible!");      }    else
      {      if (!isset(f224))
        {        print("The lid is closed.");        }      else
        {        if (v39 == 1)
          {          start.update(o2);          reverse.loop(o2, f228);          reset(f224);          }        else
          {          print("You need to be closer.");          }        }      }    }  if (said("kill", "bandit"))
    {    if (v172 == 1)
      {      print("He looks pretty big and mean. Perhaps you should run instead.");      }    else
      {      print("What kind of person would kill a sleeping man?!");      }    }  if (v172 == 0 &&       (said("call", "bandit") ||       said("wake", "bandit") ||       said("aim", "bandit")))
    {    release.priority(o1);    v172 = 1;    set.view(o1, View211);    v36 = 1;    cycle.time(o1, v36);    set(f230);    }  if ((said("examine", "deck") ||       said("examine", "deck") ||       said("examine", "below", "counter") ||       said("examine", "below", "bench")))
    {    print("You see the stained and dirty floor, and through the cracks, between "          "the planks, you see the ground far below.");    }  if ((said("examine", "out", "door") ||       said("examine", "door") ||       said("examine", "out", "glass") ||       said("examine", "glass") ||       said("examine", "out")))
    {    print("You see the limbs and leaves of the tree swaying in the breeze.");    }  if (said("capture", "all", "rol"))
    {    if (isset(f224))
      {      reset(f225);      reset(f78);      v223 = 1;Label1:      if (v223 < 55)
        {        if (v223 == 48)
          {          ++v223;          goto(Label1);          }        get.room.v(v223, v221);        if (v221 == 38)
          {          set(f225);          get.v(v223);          }        ++v223;        goto(Label1);        }      if (isset(f225))
        {        print("Ok.");        }      else
        {        print("There is nothing in the bin.");        }      }    else
      {      print("The lid is closed.");      }    }  }if (v40 > 84 &&     v40 < 98 &&     edgeEgoHit == BOTTOM_EDGE)
  {  if (v44 == 6)
    {    new.room(Logic22);    }  else
    {    new.room(Logic37);    }  }return();[ Messages#message 1 "You have entered the bandits' hideout; one of them is coming after you now!"#message 2 "You have entered the bandits' hideout; one of them is sleeping at a small table."#message 3 "The hideout is made of rough planks, sparsely furnished with a table, a chair, and a small, wooden bin in the corner."#message 4 "The ugly bandit is dressed in dirty clothes. He looks, and smells, as if he hasn't had a bath in months. He has a very threatening look in his eyes!"#message 5 "The scoundrel is fast asleep at the table. He is dressed in dirty, ragged clothes, and emits a very unpleasant odor."#message 6 "There is a leather coin purse lying on top of a wobbly table."#message 7 "The wobbly, wooden table is made out of rough planks."#message 8 "You very carefully lift the coin purse off the table; practically out from under the sleeping bandit's nose!"#message 9 "That is not possible!"#message 10 "This must be where the bandits store their loot! You see all of your stolen possessions inside the bin."#message 11 "There is nothing in the bin."#message 12 "The shabby, wooden bin is built into a corner of the treehouse. It is covered by a hinged lid."#message 13 "The bin is already open."#message 14 "You slowly lift the lid, and hope the squeaky hinges do not wake the bandit."#message 15 "He looks pretty big and mean. Perhaps you should run instead."#message 16 "What kind of person would kill a sleeping man?!"#message 17 "The bandit opens his eyes and sees you in his hideout. He jumps up from the chair and chases you."#message 18 "You see the limbs and leaves of the tree swaying in the breeze."#message 19 "Ok."#message 20 "There is nothing in the bin."#message 21 "The lid is closed."#message 22 "You need to be closer."#message 23 "You see the stained and dirty floor, and through the cracks, between the planks, you see the ground far below."#message 24 "The heartless thug drags you out the door and pushes you off the porch."