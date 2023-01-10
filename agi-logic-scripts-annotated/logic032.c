if (isset(newRoom))
{  v56 = 2;  set.horizon(65);  v32 = 90;  v31 = 0;  v57 = 21;  v58 = 69;  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  load.view(View23);  load.view(View24);  load.view(View248);  load.view(View243);  load.view(View248);  load.view(View244);  load.view(View245);  load.view(View246);  load.logics(Logic128);  load.pic(currentRoom);  draw.pic(currentRoom);  call(Logic128);  if (previousRoom != currentRoom)
  {    reset(f201);    v174 = 0;    v175 = 0;    if (v44 == 14)
    {      previousRoom = 32;    }    v178 = previousRoom;    v177 = 60;  }  if (isset(f47))
  {    draw(ego);  }  v66 = 0;  v221 = 0;  random(1, 3, v36);  v64 = 0;  v67 = 243;Label1:  if (v36 > 0)
  {    --v36;    random(0, 137, v37);    random(112, 165, v38);    random(0, 3, v65);    add.to.pic.v(v67, v64, v65, v37, v38, v66, v221);    goto(Label1);  }  random(1, 6, v36);  v67 = 244;  v64 = 0;Label2:  if (v36 > 0)
  {    --v36;    random(0, 148, v37);    random(86, 160, v38);    random(0, 2, v65);    add.to.pic.v(v67, v64, v65, v37, v38, v66, v221);    goto(Label2);  }  random(0, 4, v65);  v64 = 0;  v67 = 245;  if (v65 < 2)
  {    random(1, 140, v37);    random(90, 110, v38);    add.to.pic.v(v67, v64, v65, v37, v38, v66, v221);  }  if (v65 == 2)
  {    random(1, 120, v37);    random(90, 140, v38);    add.to.pic.v(v67, v64, v65, v37, v38, v66, v221);  }  v67 = 248;  random(1, 10, v36);  if (v36 < 4)
  {    set(f224);    animate.obj(o1);    load.view(View248);    set.view(o1, View248);    v38 = 4;    cycle.time(o1, v38);    ignore.horizon(o1);    random(20, 100, v37);    v38 = 20;    position.v(o1, v37, v38);    set.loop(o1, 0);    draw(o1);  }  v221 = 0;  v66 = 5;  random(1, 10, v36);  --v36;  v64 = 0;  v65 = 0;  v38 = 44;  v67 = 246;  add.to.pic.v(v67, v64, v65, v177, v38, v66, v221);  show.pic();  return();}if (said("examine", "deck"))
{  print("The hot ground is parched and dry.");}if (said("examine", "bluff"))
{  print("The mountain to the north seems to float on the horizon.");}if ((said("drink") ||  said("capture", "drink") ||  said("drink", "liquid") ||  said("drink", "bay", "liquid")))
{  if (has("Ocean Water*"))
  {    print("Drinking the salty ocean water intensifies your thirst.");    drop("Ocean Water*");  }  else
  {    print("You have no water. Your desperate mind must be playing tricks on "      "you.");  }}if ((said("examine") ||  said("examine", "desert")))
{  if (!isset(f201))
  {    print("You have entered a great desert.");  }  else
  {    print("You look around and see no familiar landmarks. A tight knot of fear "      "begins to form in your stomach as you realize you don't know how to "      "get out of this desert.");  }}if ((said("capture", "bird") ||  said("examine", "bird")))
{  print("You see buzzards circling high above you.");}call(Logic128);if (isset(f45))
{  if (v174 < 60)
  {    ++v174;  }  else
  {    v174 = 0;    ++v175;  }}if (v175 == 2 &&  v174 == 0)
{  ++v174;  print.at("You are getting very hot and tired. You'd better find your way out "    "of this desert soon.", 2, 2, 37);}if (v44 == 0 &&  v175 == 3 &&  v174 == 0)
{  ++v174;  program.control();  start.motion(ego);  set(f35);  set(f46);  if (!isset(f31))
  {    prevent.input();  }  set.view(ego, View23);  set.cel(ego, 0);  v36 = 2;  cycle.time(ego, v36);  end.of.loop(ego, f221);}if (isset(f221))
{  reset(f221);  set(f46);  set.view(ego, View24);  v220 = 100;  print.at("You can't take the relentless sun anymore, and collapse from heat "    "stroke. Miserably, you die in this dreadful desert.", 2, 2, 37);  program.control();}--v220;if (v220 == 1)
{  stop.cycling(ego);  set(f44);}if (v44 == 26)
{  v226 = 6;}else
{  v226 = 15;}if (edgeEgoHit == LEFT_EDGE)
{  set(f201);  v177 += 2;  if (v177 > 118)
  {    v177 = 118;  }  new.room(Logic32);}if ((edgeEgoHit == TOP_EDGE ||  edgeEgoHit == BOTTOM_EDGE))
{  set(f201);  new.room(Logic32);}if (edgeEgoHit == RIGHT_EDGE)
{  if (!isset(f201))
  {    new.room.v(v178);  }  else
  {    v177 -= 2;    random(1, 15, v36);    if (v36 < v226)
    {      new.room(Logic32);    }    else
    {      random(1, 4, v36);      if (v36 == 1)
      {        new.room(Logic11);      }      if (v36 == 2)
      {        new.room(Logic16);      }      if (v36 == 3)
      {        new.room(Logic21);      }      if (v36 == 4)
      {        new.room(Logic26);      }    }  }}return();[Messages#message 1 "You look around and see no familiar landmarks. A tight knot of fear begins to form in your stomach as you realize you don't know how to get out of this desert."#message 2 "Drinking the salty ocean water intensifies your thirst."#message 3 "You have no water. Your desperate mind must be playing tricks on you."#message 4 "You are getting very hot and tired. You'd better find your way out of this desert soon."#message 5 "You can't take the relentless sun anymore, and collapse from heat stroke. Miserably, you die in this dreadful desert."#message 6 "The mountain to the north seems to float on the horizon."#message 7 "The snake scurries around without noticing you."#message 8 "That is not a wise idea. The snake is probably dangerous."#message 9 "What snake?"#message 10 "You have entered a great desert."#message 11 "You see buzzards circling high above you."#message 12 "The hot ground is parched and dry."
