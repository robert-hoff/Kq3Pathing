if (isset(newRoom))
  {  set.horizon(74);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 2;  set(f73);  v32 = 20;  v31 = 110;  random(2, 3, v36);  if (v36 == 2)
    {    v57 = 56;    v58 = 130;    }  else
    {    v57 = 142;    v58 = 119;    }  load.logics(Logic112);  load.logics(Logic120);  load.logics(Logic113);  load.view(View232);  load.view(View11);  load.view(View3);  load.view(View7);  load.view(View2);  if (v44 == 6)
    {    load.view(View24);    load.sound(Sound1);    }  if (v62 == 1)
    {    load.view(View170);    }  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (v62 == 1)
    {    add.to.pic(View170, 1, 0, 104, 46, 4, 4);    discard.view(View170);    }  animate.obj(o2);  set.view(o2, View232);  set.loop(o2, 2);  set.cel(o2, 2);  set.priority(o2, 4);  ignore.horizon(o2);  position(o2, 76, 27);  v36 = 6;  cycle.time(o2, v36);  draw(o2);  animate.obj(o3);  set.view(o3, View232);  set.loop(o3, 2);  set.priority(o3, 4);  ignore.horizon(o3);  position(o3, 89, 27);  v36 = 6;  cycle.time(o3, v36);  draw(o3);  if ((previousRoom == 29 ||       previousRoom == 24 ||       v44 == 6))
    {    set(f48);    set(f47);    }  if (isset(f48))
    {    if ((previousRoom == 29 ||         previousRoom == 24 ||         v44 == 6))
      {      prevent.input();      program.control();      set(f46);      set(f35);      ignore.blocks(ego);      ignore.horizon(ego);      v40 = 43;      v41 = 33;      move.obj(ego, 43, 121, 3, f220);      sound(Sound1, f41);      }    else
      {      if (previousRoom == 15)
        {        v40 = 60;        if (v138 == 7)
          {          v40 = 122;          set.view(ego, View7);          }        if (v138 == 2)
          {          v40 = 140;          set.view(ego, View2);          }        if (v138 == 3)
          {          v40 = 153;          v41 = 130;          set.view(ego, View3);          }        }      else
        {        if (previousRoom == 25)
          {          v40 = 77;          if (v44 == 224)
            {            v40 = 112;            set.view(ego, View7);            }          if (v44 == 11)
            {            v40 = 144;            set.view(ego, View3);            }          }        else
          {          if ((previousRoom == 31 ||               previousRoom == 75 ||               previousRoom == 76))
            {            v40 = 150;            v41 = 74;            set.view(ego, View3);            }          }        }      }    position.v(ego, v40, v41);    }  if (isset(f47))
    {    draw(ego);    }  v36 = 1;  call(Logic112);  reposition.to(o12, 99, 19);  reposition.to(o13, 111, 11);  call(Logic120);  call(Logic113);  show.pic();  return();  }v138 = 0;if (isset(onWater))
  {  v138 = 7;  }if ((posn(ego, 119, 0, 126, 94) ||     posn(ego, 124, 95, 135, 112) ||     posn(ego, 125, 113, 140, 130) ||     posn(ego, 129, 131, 159, 167)))
  {  v138 = 2;  }if ((posn(ego, 127, 0, 159, 94) ||     posn(ego, 136, 95, 159, 112) ||     posn(ego, 141, 113, 159, 130)))
  {  v138 = 3;  }if (isset(haveInput))
  {  if (v62 == 1 &&       (said("examine", "dock") ||       said("examine", "ship")))
    {    print("There is a ship docked at the pier.");    }  if (said("examine", "town"))
    {    print("A charming village sits atop a bluff overlooking the ocean.");    }  if (said("examine", "bluff"))
    {    print("The cliffs are very steep.");    }  if (said("examine", "dock"))
    {    print("A weathered dock leads into the ocean.");    }  }if (isset(f220))
  {  reset(f220);  set.view(ego, View24);  v38 = 247;  v37 = 0;  reposition(ego, v37, v38);  v44 = 20;  set(f44);  stop.cycling(ego);  }if (isset(f45) &&     v62 == 1 &&     v53 <= 0 &&     v52 > 0 &&     v52 < 30)
  {  v52 = 30;  }call(Logic112);call(Logic120);call(Logic113);if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic15);  }if (edgeEgoHit == TOP_EDGE)
  {  new.room(Logic25);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic31);  }return();[ Messages#message 1 "There is a ship docked at the pier."#message 2 "A charming village sits atop a bluff overlooking the ocean."#message 3 "The cliffs are very steep."#message 4 "A weathered dock leads into the ocean."