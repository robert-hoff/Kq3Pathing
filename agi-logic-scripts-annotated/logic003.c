if (isset(newRoom))
{  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 1;  v57 = 43;  v58 = 135;  v32 = 125;  v31 = 140;  v100 = 72;  v101 = 118;  load.logics(Logic104);  if ((v127 == 1 ||    v127 == 3) &&    v44 != 27 &&    v137 <= 0 &&    v128 != 20)
  {    random(1, 2, v36);    if (v36 == 1)
    {      load.logics(Logic105);      set(f98);      random(6, 12, v125);    }  }  if (v44 == 27)
  {    set(f46);    load.view(View27);  }  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (v44 == 25)
  {    set(f48);  }  if (isset(f48))
  {    if (previousRoom == 7)
    {      release.priority(ego);      v40 = 90;      v41 = 167;    }    else
    {      if (previousRoom == 2)
      {        v40 = 40;        v41 = 120;      }      else
      {        if (previousRoom == 1)
        {          v40 = 133;          v41 = 54;        }        else
        {          if (previousRoom == 4)
          {            v40 = 133;            if (v41 < 133)
            {              v41 = 133;            }          }          else
          {            v40 = v57;            v41 = v58;          }        }      }    }    position.v(ego, v40, v41);  }  if (v44 == 27)
  {    set.view(ego, View27);    v59 = 12;    cycle.time(ego, v59);    v60 = 12;    step.time(ego, v60);    if (previousRoom == 106)
    {      reset(f47);      set(f48);      set(f46);      v90 = 2;      position.v(ego, v57, v58);    }  }  observe.blocks(ego);  observe.objs(ego);  if (isset(f47))
  {    draw(ego);  }  if (v44 == 27)
  {    set(f47);  }  call(Logic104);  if (isset(f98))
  {    call(Logic105);  }  show.pic();  return();}if (!isset(haveInput))
{  goto(Label1);}if ((said("examine", "area") ||  said("examine", "building") ||  said("examine") ||  said("examine", "hall")))
{  print("This hallway is on the second level of the old wizard's house. There "    "are two stairways here. One goes up and the other leads down. An open "    "doorway is to the north.");}if ((said("examine", "stair") ||  said("examine", "up", "stair") ||  said("examine", "down", "stair")))
{  print("There are two sets of stairs here. The stairway leading upward is "    "steep and narrow. The stairway going down is wider, but rather creaky.");}if (said("examine", "door"))
{  print("There is a doorway leading into a room to the north.");}Label1:if (isset(f33) &&  v44 == 27)
{  player.control();  start.motion(ego);  reset(f35);  reset(f36);  reset(f37);  reset(f38);  print("Suddenly, you feel squishy and slimy, with an awful weight on your "    "back. Your tentacled eyes swivel around to see your shell. OH, NO! "    "He's turned you into a snail!");}if (v44 != 125)
{  if (edgeEgoHit == BOTTOM_EDGE &&    v40 > 84 &&    v40 < 105)
  {    new.room(Logic7);  }  if (posn(ego, 38, 90, 53, 118))
  {    new.room(Logic2);  }  if (posn(ego, 120, 50, 139, 52))
  {    new.room(Logic1);  }  if (posn(ego, 139, 133, 159, 166))
  {    new.room(Logic4);  }}call(Logic104);if (isset(f98))
{  call(Logic105);}return();[Messages#message 1 "This hallway is on the second level of the old wizard's house. There are two stairways here. One goes up and the other leads down. An open doorway is to the north."#message 2 "There are two sets of stairs here. The stairway leading upward is steep and narrow. The stairway going down is wider, but rather creaky."#message 3 ""#message 4 ""#message 5 ""#message 6 "There is a doorway leading into a room to the north."#message 7 ""#message 8 "Suddenly, you feel squishy and slimy, with an awful weight on your back. Your tentacled eyes swivel around to see your shell. OH, NO! He's turned you into a snail!"
