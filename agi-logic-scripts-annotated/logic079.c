if (isset(newRoom))
{  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.logics(Logic116);  set(f34);  v57 = 107;  v58 = 150;  v32 = 70;  v31 = 150;  v56 = 7;  load.sound(Sound26);  load.sound(Sound3);  load.view(View0);  set.view(ego, View0);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  if (isset(f48))
  {    start.motion(ego);    egoDir = LEFT;    if (v41 > 120)
    {      position(ego, 120, 150);    }    else
    {      position(ego, 86, 125);    }    get.posn(ego, v40, v41);  }  else
  {    v41 = v58;  }  if (isset(f47))
  {    draw(ego);  }  if (v44 == 14)
  {    v41 = v58;  }  animate.obj(o1);  load.view(View158);  load.view(View166);  if (isset(f181))
  {    v221 = 22;    set.view(o1, View166);    set.loop(o1, 2);    v36 = 6;    cycle.time(o1, v36);    set.priority(o1, 14);    position(o1, 20, 152);  }  else
  {    set(f81);    v36 = 40;    position.v(o1, v36, v41);    set.view(o1, View158);    sound(Sound26, f238);    if (v44 == 0)
    {      follow.ego(o1, 10, f220);    }    else
    {      stop.cycling(o1);    }  }  draw(o1);  show.pic();  return();}--v221;if (v221 == 1)
{  sound(Sound3, f238);  set.cel(o1, 0);  end.of.loop(o1, f221);}if (isset(f221))
{  reset(f221);  v221 = 22;  stop.cycling(o1);}call(Logic116);if (isset(f33) &&  !isset(f181))
{  if (v44 != 0)
  {    reset(f220);    stop.cycling(o1);    normal.motion(o1);    stop.motion(o1);  }  else
  {    start.cycling(o1);    follow.ego(o1, 10, f220);  }}if (isset(f220))
{  if (isset(f46))
  {    stop.cycling(o1);    normal.motion(o1);    stop.motion(o1);  }  else
  {    reset(f220);    print("\"What d'ya think yer up ta, boy!?\"");    set(f199);    new.room(Logic85);  }}if ((said("examine") ||  said("examine", "area") ||  said("examine", "ship")))
{  print("This is the galley of the pirate ship. A large iron stove dominates "    "one wall. Pots, pans, and barrels surround it. There is a long dining "    "table at the other end of the room.");}if (said("examine", "bandit"))
{  if (!isset(f181))
  {    print("Get out of here before the ship's cook cuts you up!");  }  else
  {    print("The ship's cook is fast asleep in the evening meal. His snores are "      "so loud they seem to rattle the walls.");  }}if (said("examine", "oven"))
{  print("It's just an old wood stove used for cooking. Nothing special about "    "it.");}if (said("examine", "chamber pot"))
{  print("The pots and pans are used for cooking the pirate's meals.");}if (said("examine", "barrel"))
{  print("The barrel seems to be full of rum, but you have better things to do "    "at the moment than drink.");}if (said("examine", "counter"))
{  print("The wooden dining table is not too clean. The remains of many meals "    "are lodged between the oaken planks. Its top is deeply gouged and "    "stained.");}if (said("examine", "below", "counter"))
{  print("It's obvious the pirate's eating habits are less than desirable. You "    "see nothing but crumbs and stains under the table.");}if ((said("get in", "down") ||  said("get in", "counter") ||  said("get in", "down", "counter") ||  said("get in")))
{  print("You have better things to do than sit around.");}if ((said("examine", "door") ||  said("examine", "out", "door")))
{  print("The sight of the rolling swells make you a little queasy. To your "    "relief, you see no pirates coming.");}if (isset(egoHitSpecial))
{  new.room(Logic80);}return();[Messages#message 1 "This is the galley of the pirate ship. A large iron stove dominates one wall. Pots, pans, and barrels surround it. There is a long dining table at the other end of the room."#message 2 "The ship's cook is fast asleep in the evening meal. His snores are so loud they seem to rattle the walls."#message 3 "Get out of here before the ship's cook cuts you up!"#message 4 "It's just an old wood stove used for cooking. Nothing special about it."#message 5 "The pots and pans are used for cooking the pirate's meals."#message 6 "The barrel seems to be full of rum, but you have better things to do at the moment than drink."#message 7 "The wooden dining table is not too clean. The remains of many meals are lodged between the oaken planks. Its top is deeply gouged and stained."#message 8 "It's obvious the pirate's eating habits are less than desirable. You see nothing but crumbs and stains under the table."#message 9 "You have better things to do than sit around."#message 10 "The sight of the rolling swells make you a little queasy. To your relief, you see no pirates coming."#message 11 "\"What d'ya think yer up ta, boy!?\""#message 12 "%m2"
