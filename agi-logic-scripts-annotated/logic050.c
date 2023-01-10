if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 4;  v57 = 127;  v58 = 96;  set(f32);  load.logics(Logic103);  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
    {    if (previousRoom == 49)
      {      if (v40 < 18)
        {        v40 = 18;        }      }    else
      {      if (previousRoom == 51)
        {        if (v41 < 55 &&             v41 > 47)
          {          v41 = 47;          }        if (v41 < 96 &&             v41 > 94)
          {          v41 = 94;          }        if (v41 < 87 &&             v41 > 84)
          {          v41 = 87;          }        }      else
        {        v40 = v57;        v41 = v58;        }      }    position.v(ego, v40, v41);    }  if (isset(f47))
    {    draw(ego);    }  call(Logic103);  show.pic();  return();  }if (!isset(haveInput))
  {  goto(Label1);  }if ((said("examine", "bluff") ||     said("examine", "top", "bluff") ||     said("examine", "up", "bluff") ||     said("examine") ||     said("examine", "area") ||     said("examine", "up")))
  {  print("You are at the foot of a high, snowy mountain range. A cliff looms "        "before you with a tricky path winding its way up the steep face.");  }if ((said("examine", "path") ||     said("examine", "up", "path")))
  {  print("The narrow path winding up the steep cliff looks precarious and "        "confusing. \"Must I climb this?\" you wonder.");  }if ((said("examine", "brush") ||     said("examine", "forest") ||     said("capture", "flower") ||     said("capture", "flower") ||     said("examine", "flower")))
  {  print("The shrubbery is scant here, growing only between boulders.");  }if (said("examine", "deck"))
  {  print("The ground is strewn with large boulders.");  }if ((said("examine", "sky") ||     said("examine", "up", "sky")))
  {  print("You look upward and see the mountain range looming toward the "        "beautiful blue sky.");  }if ((said("climb", "forest") ||     said("climb", "up", "forest")))
  {  print("There are no climbable trees here.");  }if (has("Shovel"))
  {  if ((said("dig", "hole") ||       said("dig") ||       said("dig", "hole", "deck") ||       said("dig", "try", "shovel")))
    {    print("Not here.");    }  }Label1:v39 = 0;if (v41 > 62)
  {  v39 = 1;  v34 = 120;  }else
  {  if (v40 < 80)
    {    v39 = 2;    v34 = 79;    }  else
    {    v39 = 3;    v34 = 87;    }  }if (v44 == 0)
  {  if (isset(onWater))
    {    set.view(ego, View1);    }  else
    {    set.view(ego, View0);    }  }call(Logic103);if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic49);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic51);  }return();[ Messages#message 1 "You are at the foot of a high, snowy mountain range. A cliff looms before you with a tricky path winding its way up the steep face."#message 2 "The narrow path winding up the steep cliff looks precarious and confusing. \"Must I climb this?\" you wonder."#message 3 "The shrubbery is scant here, growing only between boulders."#message 4 "The ground is strewn with large boulders."#message 5 "You look upward and see the mountain range looming toward the beautiful blue sky."#message 6 "There are no climbable trees here."#message 7 "Not here."