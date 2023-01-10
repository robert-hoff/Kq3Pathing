if (isset(newRoom))
{  load.logics(Logic107);  load.view(View190);  load.view(View199);  load.sound(Sound2);  load.sound(Sound27);  animate.obj(o14);  animate.obj(o15);  v129 = 0;  v249 = 10;  v128 = 101;  if (isset(f31) &&    monitorType != MONO)
  {    set.text.attribute(GREEN, BLACK);    display(22, 0, "Wiz in %v125.");    set.text.attribute(WHITE, BLACK);  }  return();}if (!isset(f99))
{  goto(Label1);}if ((said("examine", "enchanter") ||  said("examine", "abominable", "enchanter")))
{  print("Manannan appears older than old. His long, white beard straggles "    "thinly past his waist, his skin resembles old parchment paper, and his "    "hands are gnarled and twisted. But, don't be fooled! The old wizard is "    "smart and powerful, and his magic is formidable.");}if (said("kill", "enchanter"))
{  print("Your own death would result from that! He's too powerful for you.");}if ((said("embrace", "enchanter") ||  said("pat", "enchanter") ||  said("drink", "enchanter")))
{  print("Ugh!! You don't want to do THAT, do you!?");}if ((said("capture", "enchanter") ||  said("capture", "enchanter")))
{  print("Do you really think you can catch a wizard?");}if ((said("cast", "spell") ||  said("cast", "spell", "enchanter") ||  said("cast", "spell", "on", "enchanter") ||  said("cast", "magic") ||  said("cast", "magic", "spell") ||  said("cast", "magic", "spell", "on", "enchanter") ||  said("cast", "magic", "spell", "enchanter")))
{  print("How can you without proper materials? Besides, you have to get up "    "pretty early to out-spell this old wizard.");}if (said("call", "enchanter"))
{  ++v129;}Label1:if (isset(f99) &&  (v127 == 1 ||    v127 == 3))
{  get.posn(o15, v32, v31);  reset(f107);  call(Logic107);  if ((v44 == 25 ||    isset(f49) ||    v44 == 26 ||    v71 > 0))
  {    v71 = 0;    print("\"Attempt to use magic around me, will you?!\"");    v123 = 22;  }  if (v123 > 0)
  {    set(f130);    goto(Label3);  }  if (isset(f45))
  {    --v251;    if (v251 == 1 &&      v137 > 0)
    {      v129 = 3;    }  }  if (v129 == 4)
  {    v129 = 2;    v250 = 0;    print("\"You aren't to be in this room without my express permission!\" "      "Manannan says gruffly. \"Go find something to do.\"");  }  if (v129 != v250)
  {    v250 = v129;    if (v129 == 1)
    {      random(13, 15, v36);      print.v(v36);    }    if (v129 == 2)
    {      if (v137 > 0)
      {        print("\"Instead of fooling around in here, you should have finished "          "that chore I assigned to you earlier!\"");        v110 = 3;        v123 = 15;      }      else
      {      Label2:        random(1, 5, v137);        if ((v137 == v136 ||          v137 == 3))
        {          goto(Label2);        }        if (v137 == 1 &&          currentRoom == 6)
        {          goto(Label2);        }        if (v137 == 2 &&          currentRoom == 2)
        {          goto(Label2);        }        if (v137 == 4 &&          currentRoom == 5)
        {          goto(Label2);        }        v110 = 3;        v84 = 3;        ++v84;        v36 = v137;        v136 = v137;        v36 += 15;        print.v(v36);        v251 = 25;      }    }    if (v123 > 0)
    {      set(f130);      goto(Label3);    }    if (v129 == 3)
    {      print("\"When I assign a chore, I want it done immediately!\"");      v123 = 15;    }  }  if (v123 > 0)
  {    set(f130);    goto(Label3);  }  --v249;  if (v249 <= 0)
  {    distance(o15, ego, v36);    if (v36 < 10)
    {      ++v248;      v249 = 30;      if (v248 == 1)
      {        print("\"Out of my way, Gwydion!\"");      }      if (v248 == 2)
      {        print("\"I mean it, boy... stay away from me!\"");      }      if (v248 == 3)
      {        print("\"Gwydion, let this be a lesson to you!\"");        v123 = 15;      }    }  }}if (v123 > 0)
{  set(f130);}else
{  if (isset(f45))
  {    if (isset(f31) &&      v47 == 5 &&      monitorType != MONO)
    {      clear.lines(22, 22, BLACK);    }    if (v47 == v125 &&      (v127 == 1 ||        v127 == 3))
    {      if (!isset(f46))
      {        set(f246);        v246 = 0;      }      else
      {        if (v125 < 200)
        {          v125 += 8;        }      }    }    --v247;    if (v247 == 1)
    {      set(f246);    }  }  if ((v246 == 1 ||    v246 == 5))
  {    current.cel(o14, v36);    if (v36 == 3)
    {      set(f246);    }  }  if (isset(f246))
  {    reset(f246);    ++v246;    if (v246 == 1)
    {      prevent.input();      program.control();      stop.motion(ego);      set(f46);      v128 = 102;      sound(Sound27, f41);      set.view(o15, View190);      position.v(o15, v32, v31);      v36 = 2;      step.time(o15, v36);      cycle.time(o15, v36);      v36 = v40;      if (v36 > 2)
      {        v36 -= 3;      }      if (v36 < v32)
      {        set.loop(o15, 1);      }      else
      {        set.loop(o15, 0);      }      set.view(o14, View199);      set.cel(o14, 0);      v36 = 3;      cycle.time(o14, v36);      ignore.objs(o14);      set.priority(o14, 15);      position.v(o14, v32, v31);      stop.motion(o14);      start.cycling(o14);      end.of.loop(o14, f246);      draw(o14);    }    if (v246 == 2)
    {      set.cel(o15, 0);      stop.cycling(o15);      draw(o15);    }    if (v246 == 3)
    {      set(f99);      accept.input();      player.control();      start.motion(ego);      reset(f46);      erase(o14);      random(3, 8, v247);    }    if (v246 == 4)
    {      random(3, 8, v247);      if (!isset(f129))
      {        set(f129);        v129 = 2;      }      else
      {        if ((currentRoom == 1 ||          currentRoom == 2 ||          currentRoom == 5))
        {          v129 = 4;          v247 = 0;        }        else
        {          random(1, 3, v36);          if (v36 == 1)
          {            random(24, 25, v36);            print.v(v36);          }        }      }    }    if (v246 == 5)
    {      prevent.input();      program.control();      stop.motion(ego);      set(f46);      reset(f99);      get.posn(o15, v32, v31);      position.v(o14, v32, v31);      set.view(o14, View199);      set.cel(o14, 0);      draw(o14);      start.cycling(o14);      end.of.loop(o14, f246);      sound(Sound2, f41);    }    if (v246 == 6)
    {      erase(o15);    }    if (v246 == 7)
    {      accept.input();      player.control();      start.motion(ego);      reset(f46);      erase(o14);      v128 = 104;      v246 = 0;    }  }}Label3:return();[Messages#message 1 "Manannan appears older than old. His long, white beard straggles thinly past his waist, his skin resembles old parchment paper, and his hands are gnarled and twisted. But, don't be fooled! The old wizard is smart and powerful, and his magic is formidable."#message 2 "Your own death would result from that! He's too powerful for you."#message 3 "Ugh!! You don't want to do THAT, do you!?"#message 4 "Do you really think you can catch a wizard?"#message 5 "How can you without proper materials? Besides, you have to get up pretty early to out-spell this old wizard."#message 6 ""#message 7 ""#message 8 "Wiz in %v125."#message 9 "\"Out of my way, Gwydion!\""#message 10 "\"I mean it, boy... stay away from me!\""#message 11 "\"Gwydion, let this be a lesson to you!\""#message 12 "\"Attempt to use magic around me, will you?!\""#message 13 "Manannan is bothered by your interruption. \"Gwydion, I've many things on my mind. Get to work, or I'll find you something to do.\""#message 14 "With annoyance, Manannan looks your way, \"Don't bother me, boy. I've got important things to think about.\""#message 15 "\"Shoo, boy! I don't want to be bothered!\""#message 16 "\"Your kitchen is filthy! Go clean it, now!\""#message 17 "\"Gwydion, my chamber pot needs servicing. Go empty it, immediately!\""#message 18 ""#message 19 "\"My office is dusty. Clean it at once!\""#message 20 "\"You've been neglecting my chickens again, Gwydion. Feed them, and quickly!!\""#message 21 "\"When I assign a chore, I want it done immediately!\""#message 22 "\"You aren't to be in this room without my express permission!\" Manannan says gruffly. \"Go find something to do.\""#message 23 "\"Instead of fooling around in here, you should have finished that chore I assigned to you earlier!\""#message 24 "Oh, oh. It's him, again!"#message 25 "You feel Manannan's cold gaze is quite unnerving."
