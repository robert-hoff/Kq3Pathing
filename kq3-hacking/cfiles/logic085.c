if (isset(newRoom))
  {  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  set(f34);  if (previousRoom == 77)
    {    v84 = 0;    }  v57 = 60;  v58 = 147;  v32 = 85;  v31 = 148;  v56 = 7;  load.sound(Sound1);  load.logics(Logic109);  call(Logic109);  load.logics(Logic116);  load.view(View30);  load.view(View0);  load.view(View36);  load.view(View37);  load.view(View11);  load.view(View24);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  if (v44 == 6)
    {    set.view(ego, View11);    position(ego, 103, 33);    }  if (v44 == 15)
    {    set.view(ego, View30);    position(ego, 110, 20);    set.loop(ego, 0);    fix.loop(ego);    }  if (v44 == 0)
    {    if (isset(f48))
      {      get.posn(ego, v40, v41);      if ((isset(f199) ||           previousRoom == 77))
        {        v226 = 1;        v227 = 83;Label1:        if (v226 < 55)
          {          if (v226 == 8)
            {            ++v226;            goto(Label1);            }          get.room.v(v226, v228);          if (v228 == 255)
            {            set(f185);            set(f223);            put.v(v226, v227);            }          ++v226;          goto(Label1);          }        if (!isset(f199))
          {          reset(f223);          }        else
          {          reset(f199);          ++v187;          if (v187 == 2)
            {            v183 = 1;            new.room(Logic82);            }          }        start.motion(ego);        set.loop(ego, 2);        position.v(ego, v57, v58);        }      else
        {        if (previousRoom == 86)
          {          if (v41 > 144)
            {            position(ego, 146, 145);            }          else
            {            position(ego, 146, 138);            }          }        }      }    release.loop(ego);    }  if (v44 == 30)
    {    set(f48);    position.v(ego, v57, v58);    set.view(ego, View0);    set(f47);    }  if (isset(f47))
    {    draw(ego);    }  show.pic();  return();  }if (isset(f223))
  {  reset(f223);  print("Adding insult to injury, all of your belongings have been taken from "        "you again!");  }if (v44 == 15 &&     isset(egoHitSpecial))
  {  set.view(ego, View11);  v44 = 6;  }if (v44 == 6 &&     !isset(f46))
  {  sound(Sound1, f238);  set(f46);  get.posn(ego, v40, v41);  v41 = 120;  ignore.blocks(ego);  set.priority(ego, 13);  v36 = 3;  move.obj.v(ego, v40, v41, v36, f222);  }if (isset(f222))
  {  stop.sound();  reset(f222);  set.view(ego, View24);  reposition.to(ego, 104, 125);  set(f44);  }if (v44 == 15 &&     !obj.in.box(ego, 108, 20, 118, 94))
  {  prevent.input();  ignore.blocks(ego);  ignore.objs(ego);  release.loop(ego);  start.motion(ego);  set.view(ego, View0);  set.loop(ego, 3);  v38 = 124;  v225 = 6;  move.obj.v(ego, v40, v38, v225, f220);  set.scan.start();  if (isset(f220))
    {    reset(f220);    v44 = 201;    set.priority(ego, 13);    observe.blocks(ego);    observe.objs(ego);    accept.input();    reset.scan.start();    }  return();  }call(Logic109);call(Logic116);if ((said("examine", "area") ||     said("examine") ||     said("examine", "carry")))
  {  print("You are in the dank cargo hold of the pirate ship. With caution, you "        "look around the dim surroundings. Mostly, you see stacks of wooden "        "crates. Looking upward, you notice a rope ladder dangling partway "        "through an opening in the hold ceiling. The ladder is directly over "        "the largest crate.");  }if (said("examine", "hole"))
  {  print("You see the opening for the cargo hold high above you. A thin rope "        "ladder hangs halfway down.");  }if ((said("board", "carry") ||     said("climb", "out", "carry")))
  {  print("Good idea! How?");  }if ((said("examine", "up") ||     said("examine", "up", "ladder") ||     said("examine", "ladder")))
  {  if (v44 == 201)
    {    print("The ladder is just out of reach.");    }  if (v44 == 15)
    {    print("The ladder is sagging under your weight.");    }  if ((v44 == 0 ||       v44 == 200))
    {    print("The ladder is far above you.");    }  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic86);  }if (v44 == 15 &&     edgeEgoHit == TOP_EDGE)
  {  if (!isset(f204))
    {    currentScore  += 2;    set(f204);    }  new.room(Logic83);  }return();[ Messages#message 1 "You are in the dank cargo hold of the pirate ship. With caution, you look around the dim surroundings. Mostly, you see stacks of wooden crates. Looking upward, you notice a rope ladder dangling partway through an opening in the hold ceiling. The ladder is directly over the largest crate."#message 3 "You see the opening for the cargo hold high above you. A thin rope ladder hangs halfway down."#message 4 "Good idea! How?"#message 5 "The ladder is just out of reach."#message 6 "The ladder is sagging under your weight."#message 7 "The ladder is far above you."#message 8 "Adding insult to injury, all of your belongings have been taken from you again!"#message 9 ""#message 10 ""#message 11 ""