if (isset(newRoom))
{  load.sound(Sound38);  load.logics(Logic112);  load.view(View56);  load.view(View54);  load.view(View3);  load.view(View4);  load.view(View0);  load.view.v(currentEgoView);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  set.horizon(55);  v57 = 70;  v58 = 100;  set.view.v(ego, currentEgoView);  if (v44 != 14 &&    v44 != 26 &&    v44 != 25 &&    v44 != 30)
  {    set.view(ego, View3);    set(f35);    v44 = 11;  }  if (isset(f47))
  {    draw(ego);  }  if (v56 == 4 &&    (previousRoom == 48 ||      previousRoom == 49 ||      previousRoom == 31))
  {    animate.obj(o4);    set.view(o4, View56);    position.v(o4, v40, v41);    v36 = 2;    step.size(o4, v36);    v232 = 3;  }  v225 = 6;  animate.obj(o5);  set.view(o5, View54);  position(o5, 100, 100);  set.cel(o5, 0);  stop.cycling(o5);  ignore.objs(o5);  animate.obj(o6);  set.view(o6, View54);  position(o6, 104, 103);  set.cel(o6, 0);  stop.cycling(o6);  ignore.objs(o6);  if (v44 != 30 &&    previousRoom != currentRoom)
  {    reset(f201);    v173 = 6;    v174 = 0;    if (v44 == 14)
    {      previousRoom = 31;    }    v178 = previousRoom;    if (v56 == 7)
    {      if (v62 == 3)
      {        previousRoom = 48;        v178 = 48;        v176 = 4;        v56 = 4;      }      else
      {        v176 = 0;        v178 = 31;      }    }    v192 = 0;    if ((previousRoom == 25 ||      previousRoom == 75 ||      previousRoom == 76))
    {      if (v176 == 1)
      {        v192 = 20;      }      if (v176 == 3)
      {        v192 = 30;      }    }    if (v176 <= 0 && v56 == 2)
    {      v176 = 2;    }    if (v176 == 1)
    {      v176 = 3;    }    else
    {      if (v176 == 3)
      {        v176 = 1;      }      else
      {        if (v176 == 4)
        {          v176 = 2;        }        else
        {          if (v176 == 2)
          {            v176 = 4;          }        }      }    }  }  if (v56 == 2)
  {    set(f223);  }  else
  {    reset(f223);  }  draw(o6);  draw(o5);  v36 = 0;  if (v62 != 2)
  {    v36 = 1;  }  call(Logic112);  if (v173 <= 0 && v44 != 26)
  {    v36 = 180;    v36 -= 5;    v174 = v36;  }  show.pic();  return();}if (has("Storm Brew*") &&  v71 == 8)
{  v71 = 0;  print("The jar of storm brew slips from your fingers as you try to open it. "    "In dismay, you watch it sink out of sight. It is gone forever.");  drop("Storm Brew*");}if (v44 == 14 &&  v176 > 0)
{  v176 = 0;}if (isset(f31) &&  monitorType != MONO)
{  display(22, 0, "Exit edge = %v176  ");}if (isset(f33) &&  v44 == 0)
{  set.view(ego, View3);  set(f35);  v44 = 11;}if (isset(f45) &&  v232 > 0)
{  --v232;  if (v232 == 0)
  {    if ((v44 != 11 ||      isset(f46)))
    {      v232 = 3;    }    else
    {      sound(Sound38, f238);      draw(o4);      follow.ego(o4, 10, f229);    }  }}if (isset(f229))
{  reset(f229);  if (isset(f46))
  {    erase(o4);    v232 = 3;  }  else
  {    erase(o4);    v44 = 29;    program.control();    stop.motion(ego);    set(f35);    prevent.input();    set.view(ego, View4);    set(f46);    v231 = 5;  }}if (isset(f45) &&  v225 > 0 &&  !isset(f221))
{  --v225;  if (v225 <= 0)
  {    random(3, 7, v225);    random(5, 140, v226);    random(65, 160, v227);    if (v44 == 25)
    {      v226 = v40;      v227 = v41;    }    reposition.to.v(o5, v226, v227);    end.of.loop(o5, f224);    v226 -= 3;    v227 -= 5;    random(1, 8, v228);    set(f221);  }}if (v228 > 0)
{  current.cel(o5, v36);  if (v36 != v228)
  {    goto(Label1);  }  reposition.to.v(o6, v226, v227);  end.of.loop(o6, f225);  v228 = 0;  random(1, 3, v36);  if (v36 == 1 &&    v44 == 25)
  {    erase(ego);    reset(f223);    set(f228);  }}Label1:if (isset(f224))
{  set.cel(o5, 0);  reset(f224);}if (isset(f225))
{  set.cel(o6, 0);  reset(f225);  reset(f221);  if (isset(f228))
  {    print.at("\"My, that was a tasty little bug.\"", 2, 2, 37);    set(f44);  }}if (v44 != 11)
{  goto(Label3);}current.cel(o6, v37);random(2, 5, v36);
if (isset(f223) && isset(f221) && has("Dough in Ears") && v36 == 5 && v37 > 1)
{  random(1, 4, v36);  v229 = 0;  v230 = 0;  if (v36 == 1 &&    !isset(f192))
  {    set(f192);    v229 = 8;    v230 = 10;  }  if (v36 == 2 &&    !isset(f193))
  {    set(f193);    v229 = 10;    v230 = 12;  }  if (v36 == 3 &&    !isset(f194))
  {    set(f194);    v229 = 12;    v230 = 14;  }  if (v36 == 4 &&    !isset(f195))
  {    set(f195);    v229 = 14;    v230 = 16;  }Label2:  if (v229 < v230)
  {    set(f227);    print.at.v(v229, 2, 2, 37);    ++v229;    goto(Label2);  }  reset(f223);}Label3:if (isset(haveInput))
{  if ((said("examine") ||    said("examine", "bay") ||    said("examine", "area") ||    said("examine", "liquid")))
  {    if (isset(f221))
    {      print("%m1 You notice a couple of colorful fish swimming nearby.");    }    else
    {      print("You see nothing but ocean in every direction.");    }  }  if (said("examine", "fish"))
  {    print("This ocean is full of colorful fish.");  }  if (said("capture", "fish"))
  {    print("They are too difficult to catch.");  }  if (said("call", "fish"))
  {    print("They don't understand you.");  }  if (said("hear", "fish"))
  {    print("Shhhh. If you're quiet, maybe you can hear them.");  }  if ((said("dive", "below", "liquid") ||    said("examine", "below", "liquid")))
  {    print("You dip your head under the water, but see nothing. It's too deep, "      "anyway.");  }  if (said("examine", "sky"))
  {    print("The sky is a clear, cloudless blue.");  }}
if (isset(f45) && v44 == 11)
{  if (v173 <= 0)
  {    v174 = 180;  }  ++v174;  if (v174 == 120)
  {    print("Your arms are getting very tired. You had better turn around and "      "head for shore.");  }  if (v174 > 180)
  {    v44 = 13;    program.control();    stop.motion(ego);    set(f35);    prevent.input();    set.view(ego, View4);    set(f46);    v231 = 5;    print("You have reached the limits of your strength. You panic and start to "      "struggle hopelessly.");  }}if (isset(f45) &&  v231 > 0)
{  --v231;  if (v231 <= 0)
  {    erase(ego);    erase(o5);    erase(o6);    set(f44);    if (v44 == 29)
    {      print("Gosh! You barely made a mouthful for that hungry shark!");    }  }}call(Logic112);if (edgeEgoHit <= NOT_HIT)
{  return();}else
{  --v173;}if (v56 == 2)
{  if (!isset(f201) &&    edgeEgoHit == v176)
  {    v176 = 0;    new.room.v(v178);  }  else
  {    if (v192 > 0 &&      !isset(f201) &&      edgeEgoHit == LEFT_EDGE)
    {      v176 = 0;      new.room.v(v192);    }    else
    {      set(f201);      random(1, 10, v36);      if (v36 == 1 &&        edgeEgoHit == v176)
      {        v176 = 0;        new.room.v(v178);      }      else
      {        if (v192 > 0 &&          v36 == 1 &&          edgeEgoHit == LEFT_EDGE)
        {          v176 = 0;          new.room.v(v192);        }        else
        {          new.room(Logic31);        }      }    }  }}
if (v56 == 4)
{  if (edgeEgoHit == v176 && !isset(f201))
  {    v176 = 0;    new.room.v(v178);  }  else
  {    if (v178 == 49 &&      edgeEgoHit == LEFT_EDGE)
    {      v178 = 48;      new.room(Logic31);    }    else
    {      if (v178 == 48 &&        edgeEgoHit == RIGHT_EDGE)
      {        v178 = 49;        new.room(Logic31);      }      else
      {        set(f201);        random(1, 10, v36);        if (v36 == 1 &&          edgeEgoHit == v176)
        {          v176 = 0;          new.room.v(v178);        }        else
        {          new.room(Logic31);        }      }    }  }}if (v56 == 7)
{  new.room(Logic31);}return();[Messages#message 1 "You see nothing but ocean in every direction."#message 2 "%m1 You notice a couple of colorful fish swimming nearby."#message 3 "Your arms are getting very tired. You had better turn around and head for shore."#message 4 "This ocean is full of colorful fish."#message 5 "They are too difficult to catch."#message 6 "They don't understand you."#message 7 "The jar of storm brew slips from your fingers as you try to open it. In dismay, you watch it sink out of sight. It is gone forever."#message 8 "\"See that boy swimming here?\" one colorful fish says to a friend. \"He's really from the Kingdom of Daventry. \"Do you think he's trying to swim back there?\""#message 9 "States the second fish, \"No, that's impossible. Daventry's too far! It's way across this ocean, and once there, he'd still have to climb a huge mountain range. He'd never make it this way.\""#message 10 "You listen with interest as two fish speak to each other. \"There's that boy from Daventry,\" one states. \"I wonder if he would like to return there?\""#message 11 "\"I doubt it,\" responds the second fish. \"I hear Daventry's going through some hard times; even worse than Llewdor. No, he wouldn't want to go there.\""#message 12 "\"How are your smallfry doing in school?\" one frolicking fish asks another."#message 13 "Answers the other, \"Not well, I'm afraid. The school's much too crowded. They don't know if they're coming or going!\""#message 14 "\"That boy ought to swim back to shore,\" you overhear one fish say to another. \"I'm afraid he'll drown way out here.\""#message 15 "\"Well, humans are pretty stupid creatures. They're always trying to defy Mother Nature,\" the second fish declares. \"There's nothing you can do about it, anyway.\""#message 16 "You have reached the limits of your strength. You panic and start to struggle hopelessly."#message 17 "\"My, that was a tasty little bug.\""#message 18 "Exit edge = %v176  "#message 19 "The sky is a clear, cloudless blue."#message 20 "You dip your head under the water, but see nothing. It's too deep, anyway."#message 21 "Shhhh. If you're quiet, maybe you can hear them."#message 22 "Gosh! You barely made a mouthful for that hungry shark!"
