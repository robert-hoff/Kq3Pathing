if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 4;  v57 = 62;  v58 = 122;  set.horizon(1);  set(f34);  random(1, 4, v36);  if (isset(f30))
    {    v36 = 2;    }  if (v36 > 2)
    {    v191 = 0;    }  else
    {    load.logics(Logic117);    v191 = 1;    reset(f172);    if (v36 == 1)
      {      set(f221);      }    }  load.view(View49);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  add.to.pic(View49, 0, 0, 122, 157, 14, 0);  add.to.pic(View49, 0, 1, 74, 132, 12, 0);  add.to.pic(View49, 0, 2, 83, 144, 13, 0);  add.to.pic(View49, 0, 3, 87, 120, 11, 0);  discard.view(View49);  if (isset(f48))
    {    if (previousRoom == 55)
      {      position(ego, 17, 167);      }    }  observe.blocks(ego);  if (isset(f47))
    {    draw(ego);    }  if (v191 == 1)
    {    v170 = 0;    v171 = 0;    if (!isset(f221))
      {      call(Logic117);      set.loop(o15, 2);      set.priority(o15, 4);      position(o15, 1, 82);      }    else
      {      position(o15, 37, 132);      ++v191;      call(Logic117);      set.loop(o15, 1);      release.priority(o15);      observe.blocks(o15);      follow.ego(o15, 11, f173);      v170 = 0;      v171 = 0;      ++v191;      }    }  show.pic();  return();  }if (!isset(haveInput))
  {  goto(Label1);  }if ((said("examine", "cave") ||     said("look in", "cave") ||     said("examine") ||     said("examine", "area")))
  {  print("This cave is disgusting! It reeks of rotting flesh. Half-chewed bones "        "of numerous creatures are scattered everywhere. Your skin creeps as "        "you look at the sight before you. This is definitely not a good place "        "to be!");  }if ((said("examine", "bone") ||     said("capture", "bone")))
  {  print("You have absolutely no interest in these horrible bones! Your only "        "interest is in getting OUT OF THERE!");  }if ((said("examine", "out") ||     said("examine", "out", "cave") ||     said("examine", "out")))
  {  print("The cold snow sparkles on the mountaintop as you glance out of the "        "cave. It would be better to be OUT there than IN here.");  }Label1:if (isset(f172))
  {  if (v191 == 3)
    {    ++v191;    v220 = 0;    move.obj(o15, 1, 43, 2, f220);    ignore.blocks(o15);    }  if (v191 == 4 &&       isset(f220))
    {    reset(f220);    ++v220;    if (v220 == 1)
      {      set.priority(o15, 8);      move.obj(o15, 1, 124, 2, f220);      }    if (v220 == 2)
      {      move.obj(o15, 24, 147, 2, f220);      }    if (v220 == 3)
      {      observe.blocks(o15);      release.priority(o15);      follow.ego(o15, 11, f173);      v220 = 0;      }    }  }if (v71 == 3)
  {  v71 = 0;  if (isset(f46))
    {    print("You can't do that now.");    }  else
    {    print("The mountain air is too thin to support insect flight.");    }  }if (v191 > 0)
  {  call(Logic117);  }if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic55);  }return();[ Messages#message 1 "This cave is disgusting! It reeks of rotting flesh. Half-chewed bones of numerous creatures are scattered everywhere. Your skin creeps as you look at the sight before you. This is definitely not a good place to be!"#message 2 "You have absolutely no interest in these horrible bones! Your only interest is in getting OUT OF THERE!"#message 3 "The cold snow sparkles on the mountaintop as you glance out of the cave. It would be better to be OUT there than IN here."#message 4 ""#message 5 ""#message 6 "Horrors! You have just entered the awful cave of the Abominable Snowman, and to your extreme bad luck he happens to be home!"#message 7 "No message."#message 16 "You can't do that now."#message 17 "The mountain air is too thin to support insect flight."