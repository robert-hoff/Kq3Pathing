if (isset(newRoom))
{  load.view(View40);  load.view(View41);  load.view(View42);  animate.obj(o15);  ignore.blocks(o15);  ignore.objs(o15);  set.view(o15, View40);  v36 = 2;  step.size(o15, v36);  observe.horizon(o15);  random(12, 25, v240);  if (v191 == 2)
  {    goto(Label1);  }  return();}if (isset(f172) &&  isset(haveInput))
{  if (said("examine", "dragon"))
  {    print("The hairy creature is huge and monstrous!! It advances toward you "      "menacingly. Don't just stand there, RUN!!!");  }  if (said("call", "dragon"))
  {    print("You attempt to speak to the hairy monster, but are cut off by a "      "ferocious ROOAAARRRRR!!");  }  if ((said("capture", "dragon") ||    said("capture", "dragon")))
  {    print("Now THAT'S the most ridiculous thing I've EVER hoid!!");  }  if ((said("kill", "dragon") ||    said("hit", "dragon")))
  {    print("Get serious!!");  }  if ((said("embrace", "dragon") ||    said("pat", "dragon") ||    said("pat", "dragon")))
  {    print("Sure. Right. Uh huh.");  }}Label1:if (isset(f45))
{  --v240;  if (v240 == 1)
  {    v191 = 2;  }}if (v191 == 2)
{  v240 = 0;  set(f172);  reset(f173);  draw(o15);  if (!isset(newRoom) &&    currentRoom != 60)
  {    print("What is this thing? OH, NO! It's the abominable snowman!!");  }  ++v191;}if (v191 == 4 &&  v44 == 0 &&  isset(f33))
{  start.motion(o15);  start.cycling(o15);  follow.ego(o15, 11, f173);  observe.blocks(o15);}if (isset(f172))
{  if (isset(f173))
  {    reset(f173);    ++v191;    if (v191 == 5 &&      v241 <= 0)
    {      v36 = 1;      cycle.time(o15, v36);      step.size(o15, v36);      if (!isset(f46) &&        !isset(f49))
      {        stop.motion(o15);        normal.motion(o15);        stop.cycling(o15);        v241 = 1;      }      else
      {        v191 = 101;      }    }    if (v191 == 6)
    {      set.view(o15, View42);      start.motion(o15);      start.cycling(o15);      v44 = 29;      print("The terrible, hairy creature grabs you with bone-crushing force! "        "You resist, but it is no use.");      ignore.blocks(o15);      if (currentRoom == 60)
      {        erase(o15);        print("The despicable creature grabs you roughly around the neck and... "          "and... it's too horrible to describe! Suffice it to say, you are "          "quite dead.");        set(f44);      }      else
      {        move.obj.v(o15, v170, v171, v36, f173);      }    }    if (v191 == 7)
    {      erase(o15);      print("He carries you away to his cave, where you meet an early (and "        "unspeakable) demise.");      set(f44);    }    if (v191 == 101)
    {      print("The abominable snowman seems quite confused by this! He stares in "        "amazement, then heads back to his cave.");      ignore.blocks(o15);      set.priority(o15, 15);      normal.motion(o15);      move.obj.v(o15, v170, v171, v36, f173);    }    if (v191 == 102)
    {      erase(o15);    }  }}if (v191 == 6)
{  set.priority(o15, 15);}if (v241 > 0)
{  ++v241;  if (v241 == 2)
  {    set(f46);    program.control();    prevent.input();    ignore.blocks(o15);    set.view(o15, View41);    set.cel(o15, 0);    stop.motion(ego);    reset(f35);    set(f36);    current.loop(o15, v36);    if (v36 == 0)
    {      set.loop(ego, 1);      set.loop(o15, 0);      if (v40 > 16)
      {        v37 = v40;        v37 -= 17;      }      else
      {        v37 = 0;      }      reposition.to.v(o15, v37, v41);    }    else
    {      set.loop(ego, 0);      set.loop(o15, 1);      reposition.to.v(o15, v40, v41);    }  }  if (v241 == 7)
  {    set.cel(o15, 1);  }  if (v241 == 12)
  {    set.cel(o15, 2);  }  if (v241 == 17)
  {    set.cel(o15, 3);    erase(ego);  }  if (v241 > 22)
  {    toggle(f240);    if (isset(f240))
    {      set.cel(o15, 4);    }    else
    {      set.cel(o15, 5);    }  }  if (v241 > 66)
  {    set(f173);    v241 = 0;  }}if (v191 > 4 &&  v191 < 101)
{  edgeEgoHit = NOT_HIT;}if (v241 > 0)
{  edgeEgoHit = NOT_HIT;}return();[Messages#message 1 "What is this thing? OH, NO! It's the abominable snowman!!"#message 2 "The abominable snowman seems quite confused by this! He stares in amazement, then heads back to his cave."#message 3 "The terrible, hairy creature grabs you with bone-crushing force! You resist, but it is no use."#message 4 "He carries you away to his cave, where you meet an early (and unspeakable) demise."#message 5 "The despicable creature grabs you roughly around the neck and... and... it's too horrible to describe! Suffice it to say, you are quite dead."#message 6 ""#message 7 ""#message 8 "The hairy creature is huge and monstrous!! It advances toward you menacingly. Don't just stand there, RUN!!!"#message 9 "You attempt to speak to the hairy monster, but are cut off by a ferocious ROOAAARRRRR!!"#message 10 "Now THAT'S the most ridiculous thing I've EVER hoid!!"#message 11 "Get serious!!"#message 12 "Sure. Right. Uh huh."
