if (!isset(f109))
{  set(f109);  set(f46);  program.control();  prevent.input();  normal.motion(ego);  stop.motion(ego);  set(f38);  set(f37);  ignore.blocks(ego);  load.view(View191);  load.view(View13);  load.sound(Sound4);  load.sound(Sound5);  load.sound(Sound2);  load.view(View193);  load.view(View199);  animate.obj(o14);  set.view(o14, View199);  set.priority(o14, 15);  set.cel(o14, 0);  v36 = 3;  cycle.time(o14, v36);  ignore.objs(o14);  stop.motion(o14);  v135 = 0;  reset(f104);  reset(f106);  reset(f105);  v133 = 0;  if (isset(f99))
  {    reset(f98);    set.view(o15, View190);    reset(f104);    normal.motion(o15);    stop.motion(o15);    v133 = 2;    set(f108);  }  else
  {    set(f104);    end.of.loop(o14, f108);    load.sound(Sound27);    animate.obj(o15);    position.v(o15, v32, v31);  }  set.view(o15, View193);  v36 = v40;  if (v36 > 2)
  {    v36 -= 3;  }  v37 = v32;  if (v36 < v37)
  {    set.loop(o15, 1);    v37 += 8;  }  else
  {    set.loop(o15, 0);    v37 += 4;  }  position.v(o14, v37, v31);  v36 = 2;  cycle.time(o15, v36);  set.cel(o15, 0);  stop.cycling(o15);  if (!isset(f99))
  {    set(f99);    sound(Sound27, f41);    draw(o14);  }}if (isset(f45))
{  --v132;  if (v132 == 1)
  {    set(f108);  }}if ((v133 == 0 ||  v133 == 13 ||  v133 == 10))
{  current.cel(o14, v36);  if (v36 == 3)
  {    set(f108);  }}if (isset(f108))
{  reset(f108);  ++v133;  if (v133 == 1)
  {    draw(o15);  }  if (v133 == 2)
  {    erase(o14);    v132 = 4;  }  if (v133 == 3)
  {    if ((v123 == 15 ||      v123 > 15) &&      v123 < 20)
    {      reset(f106);      reset(f104);      set(f105);    }    else
    {      if (v123 == 22)
      {        set(f106);        set(f104);        reset(f105);      }      else
      {        if (v84 <= 0 &&          v83 <= 0)
        {          ++v127;          if (v127 > 4)
          {            v127 = 1;            v84 = 5;          }          if (v127 == 2)
          {            v84 = 25;          }          if (v127 == 3)
          {            v84 = 5;          }          if (v127 == 4)
          {            v84 = 25;          }          v123 = v127;          reset(f106);          set(f104);          reset(f105);        }        if (v137 > 0 &&          v110 <= 0 &&          v109 <= 0)
        {          v123 = 8;          v123 += v137;          v137 = 0;          reset(f106);          reset(f104);          set(f105);        }        if (currentRoom > 8 &&          currentRoom < 87)
        {          if (currentRoom > 10 &&            v56 != 7 &&            !isset(f124))
          {            set(f124);            v44 = 14;            v135 = 8;            v123 = 21;            reset(f106);            reset(f104);            set(f105);          }          else
          {            if ((v56 == 7 ||              v134 > 4))
            {              v123 = 25;              set(f106);              set(f104);              reset(f105);            }            else
            {              v123 = 20;              reset(f106);              reset(f104);              set(f105);            }          }        }        set(f107);        call(Logic107);        if (v123 > 26)
        {          set(f106);          set(f104);          reset(f105);        }        if (v95 > 0)
        {          v123 = 26;          set(f106);          set(f104);          reset(f105);        }        v36 = 5;        if (!obj.in.room("Magic Wand*", v36))
        {          v123 = 24;          set(f106);          set(f104);          reset(f105);        }      }    }    if ((isset(f105) ||      isset(f106)))
    {      v133 = 4;    }    else
    {      v133 = 13;    }    if ((v123 < 15 ||      v123 > 20 ||      v123 == 20))
    {      print.v(v123);    }    if (v123 == v127 &&      v127 == 3)
    {      v137 = 3;      v110 = 3;    }    if (v123 == v127 &&      isset(f155) &&      v127 == 1)
    {      v137 = 3;      v110 = 3;      print("\"I am ravenous. Fix me something immediately!\"");    }  }  if (v133 == 4)
  {    start.cycling(o15);    end.of.loop(o15, f108);    if (isset(f105))
    {      ++v134;      if (v134 > 5)
      {        v123 = 25;        print.v(v123);        set(f106);        set(f104);        reset(f105);      }    }  }  if (v133 == 5)
  {    if (isset(f105))
    {      v133 = 10;    }    else
    {      v133 = 6;    }  }  if (v133 == 6)
  {    set.view(o14, View191);    v37 = v40;    v37 -= 8;    v38 = v41;    v38 -= 9;    position.v(o14, v37, v38);    draw(o14);    stop.cycling(o14);    set.cel(o14, 0);    sound(Sound4, f41);    shake.screen(1);    set.cel(o14, 1);    force.update(o14);    sound(Sound4, f41);    shake.screen(1);    set.cel(o14, 0);    force.update(o14);    sound(Sound4, f41);    shake.screen(1);    set.cel(o14, 1);    force.update(o14);    sound(Sound4, f41);    shake.screen(1);    start.cycling(o14);    sound(Sound4, f41);    v132 = 2;  }  if (v133 == 7)
  {    erase(o14);    v133 = 8;  }  if (v133 == 8)
  {    set.view(ego, View13);    stop.motion(ego);    set.cel(ego, 0);    set(f35);    v36 = 2;    cycle.time(ego, v36);    end.of.loop(ego, f108);    sound(Sound5, f41);  }  if (v133 == 9)
  {    v133 = 13;    reset(f35);    stop.cycling(ego);    stop.motion(ego);    set(f104);  }  if (v133 == 10)
  {    v37 = v40;    if (v37 > 3)
    {      v37 -= 4;    }    position.v(o14, v37, v41);    set.view(o14, View199);    set.cel(o14, 0);    draw(o14);    end.of.loop(o14, f108);    sound(Sound2, f41);  }  if (v133 == 11)
  {    erase(ego);    set(f114);  }  if (v133 == 12)
  {    erase(o14);    if (v123 == 21)
    {      v135 = 8;      v133 = 16;      load.view(View0);      set.view(ego, View0);    }    else
    {      v112 = 1;      if (v123 > 15 &&        v123 < 20)
      {        v36 = v123;      }      else
      {      Label1:        random(16, 19, v36);      }      if (v36 == 16)
      {        v44 = 27;        v135 = 3;      }      if (v36 == 17)
      {        v44 = 21;        v135 = 6;      }      if (v36 == 18)
      {        v44 = 23;        v135 = 7;      }      if (v36 == 19)
      {        v44 = 22;        v135 = 4;      }      if (v135 == currentRoom)
      {        goto(Label1);      }      print.v(v36);      v133 = 16;    }  }  if (v133 == 13)
  {    if (!isset(f104))
    {      v133 = 16;    }    else
    {      get.posn(o15, v32, v31);      current.loop(o15, v36);      v36 = v32;      if (v36 == 1)
      {        v36 += 8;      }      else
      {        v36 += 4;      }      position.v(o14, v36, v31);      set.view(o14, View199);      set.cel(o14, 0);      draw(o14);      end.of.loop(o14, f108);      sound(Sound2, f41);    }  }  if (v133 == 14)
  {    erase(o15);  }  if (v133 == 15)
  {    reset(f99);    erase(o14);    v133 = 16;  }  if (v133 == 16)
  {    v123 = 0;    v133 = 0;    reset(f109);    if (isset(f105))
    {      currentRoom = 106;      new.room.v(v135);    }    if (isset(f106))
    {      stop.motion(ego);      stop.cycling(ego);      set(f44);    }    if (!isset(f44))
    {      reset(f46);      player.control();      accept.input();      start.motion(ego);      reset(f38);      reset(f37);      observe.blocks(ego);    }  }}return();[Messages#message 1 "\"%m6, I have awakened.\""#message 2 "\"%m6, I have decided to take a journey.\""#message 3 "\"I have returned, %m6, and am ready to eat.\""#message 4 "\"I am going to bed, %m6. Do not disturb me.\""#message 5 " When will you learn to OBEY!\" Up goes the dreaded finger."#message 6 "Gwydion"#message 7 "Manannan"#message 8 "\"%m6! You were assigned a chore. You know what happens to lazy boys!\" %m7 shakes his head in disgust. \""#message 9 "%m8The kitchen is still dirty.%m5"#message 10 "%m8You failed to empty my chamber pot.%m5"#message 11 "%m8I am still hungry.%m5"#message 12 "%m8You did not dust my study.%m5"#message 13 "%m8You failed to feed my fowl.%m5"#message 14 "You are forbidden to be here!"#message 15 ""#message 16 "\"Perhaps you'd like a closer view of the ground, %m6,\" says %m7."#message 17 "\"Try hanging around in the kitchen a while, %m6,\" growls %m7."#message 18 "\"You need to work off a little of that weight, %m6,\" snarls %m7."#message 19 "%m7 leers, \"Like a bad little boy, you need to spend some time in your room!\""#message 20 "\"%m14\" hisses the old wizard, displaying no emotion, his face stony and cold."#message 21 "%m7's eyes narrow to slits. \"%m6!! %m14 I've a good mind to...\" His face softens as he continues, \"Well, maybe next time. For now... GO HOME!\""#message 22 "\"Attempting magic around me will always fail,\" %m7 laughs. \"Be gone, %m6; you bore me!\""#message 23 "\"I am ravenous. Fix me something immediately!\""#message 24 "\"My magic wand is missing!! It's time to teach you a LESSON, boy!\""#message 25 "\"I've tried to be patient with you, %m6, but this is the final straw.\" With a snaggle-toothed grin, %m7 raises his finger."#message 26 "\"You're up to no good, %m6\" %m7 snarls through clenched teeth. \"Never again will you discover my secrets!\""#message 27 "\"There's no way you could have collected these things without disobeying me, %m6\" the hateful wizard hisses as he takes the offensive objects from you."#message 28 "\"You'll create no magic around me, %m6\" the hateful wizard growls as he takes the offending ingredients from you."#message 29 "\"You've discovered the secrets of `The Sorcery of Old.' Never again will you disobey me, %m6!!\""
