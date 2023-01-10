if (isset(newRoom))
{  reset(f240);  if ((currentRoom == 48 ||    currentRoom == 49))
  {    load.view(View6);    animate.obj(o3);    load.view(View161);    set.view(o3, View161);    set.cel(o3, 0);    set.priority(o3, 4);    ignore.horizon(o3);    ignore.blocks(o3);    set(f240);  }}if (said("examine", "shovel"))
{  if (has("Shovel"))
  {    show.obj(View152);  }  else
  {    print("It's just an ordinary shovel.");  }}if (said("capture", "shovel"))
{  if (isset(f186))
  {    print("You already have it.");  }  else
  {    distance(ego, o12, v240);    if (v240 > 12)
    {      print("You can't get it from there.");    }    else
    {      get("Shovel");      set(f186);      erase(o12);      currentScore += 1;    }  }}if ((said("try", "shovel") ||  said("dig", "hole", "try", "shovel") ||  said("dig", "hole") ||  said("dig") ||  said("dig", "hole", "deck", "try", "shovel") ||  said("dig", "beach") ||  said("dig", "treasure") ||  said("dig", "deck") ||  said("dig", "hole", "deck")))
{  set(f242);}if (isset(f242))
{  if (currentRoom != 48 &&    currentRoom != 49)
  {    print("Now is not the time to think about digging a hole!");  }  else
  {    if (!has("Shovel"))
    {      print("You dig in the sand with your bare hands, but to no avail.");    }    else
    {      if (currentRoom == 48 &&        !posn(ego, 120, 81, 153, 138))
      {        print("You're too close to the ocean to dig. The hole would fill in too "          "quickly.");      }      else
      {        if (currentRoom == 49 &&          !posn(ego, 0, 67, 75, 118))
        {          print("You're too close to the ocean to dig. The hole would fill in "            "too quickly.");        }        else
        {          if (v44 != 0)
          {            print("");          }          else
          {            if (isset(f46))
            {              print("Now is not the time to think about digging a hole!");            }            else
            {              if (!has("Treasure Chest") &&                posn(ego, 53, 82, 58, 85))
              {                goto(Label1);              }              if (isset(f194) &&                !has("Treasure Chest") &&                posn(ego, 48, 80, 63, 88))
              {              Label1:                set(f243);                set.loop(o3, 0);              }              else
              {                reset(f243);                set.loop(o3, 1);              }              if (!isset(f181))
              {                reset(f243);                set.loop(o3, 1);              }              stop.motion(ego);              normal.motion(ego);              fix.loop(o3);              v241 = 1;              get.posn(ego, v242, v243);              v242 += 4;              v243 -= 1;              position.v(o3, v242, v243);              set(f241);            }          }        }      }    }  }  reset(f242);}if (isset(f241) &&  v241 == 1)
{  ++v241;  program.control();  set.view(ego, View6);  set.cel(ego, 0);  set(f35);  v36 = 2;  cycle.time(ego, v36);  end.of.loop(ego, f241);}if (isset(f241) &&  v241 == 2)
{  ++v241;  set.cel(o3, 0);  draw(o3);  stop.cycling(o3);  set.cel(ego, 0);  end.of.loop(ego, f241);}if (isset(f241) &&  v241 == 3)
{  current.cel(o3, v36);  if (v36 == 6)
  {    ++v241;  }  else
  {    ++v36;    set.cel.v(o3, v36);    set.cel(ego, 0);    end.of.loop(ego, f241);  }}if (isset(f241) &&  v241 == 4)
{  reset(f241);  if (isset(f243))
  {    get("Treasure Chest");    if (!isset(f207))
    {      set(f207);      currentScore += 7;    }    print.at("You have uncovered a small chest. You remove it from the hole and "      "open it. Inside you find precious gems and ingots of gold and "      "silver. You close the chest and take it and its contents with "      "you.", 2, 2, 37);  }  else
  {    print.at("You dig and dig, but unfortunately... find nothing.", 2, 2, 37);  }  current.loop(o3, v64);  v65 = 7;  v245 = 4;  current.view(o3, v67);  set(noScript);  add.to.pic.v(v67, v64, v65, v242, v243, v245, v245);  reset(noScript);  erase(o3);  v36 = 1;  cycle.time(ego, v36);  set.view(ego, View0);  reset(f35);  player.control();}return();[Messages#message 1 "It's just an ordinary shovel."#message 2 "You already have it."#message 3 "You can't get it from there."#message 4 "You have uncovered a small chest. You remove it from the hole and open it. Inside you find precious gems and ingots of gold and silver. You close the chest and take it and its contents with you."#message 5 "You dig and dig, but unfortunately... find nothing."#message 6 "You dig in the sand with your bare hands, but to no avail."#message 7 "You're too close to the ocean to dig. The hole would fill in too quickly."#message 8 ""#message 9 "Now is not the time to think about digging a hole!"
