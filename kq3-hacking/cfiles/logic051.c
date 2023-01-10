if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 4;  set(f56);  v57 = 132;  v58 = 110;  set.horizon(34);  set(f32);  load.logics(Logic103);  v34 = 105;  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
    {    if (previousRoom == 49)
      {      if (v40 > 144)
        {        v40 = 144;        }      }    else
      {      if (previousRoom == 50)
        {        if (v41 < 48)
          {          v41 = 48;          }        }      else
        {        if (previousRoom == 52)
          {          v40 = 69;          v41 = 36;          }        else
          {          v40 = v57;          v41 = v58;          }        }      }    position.v(ego, v40, v41);    }  if (isset(f47))
    {    draw(ego);    }  call(Logic103);  show.pic();  return();  }if (!isset(haveInput))
  {  goto(Label1);  }if ((said("examine", "bluff") ||     said("examine", "top", "bluff") ||     said("examine", "up", "bluff") ||     said("examine") ||     said("examine", "area") ||     said("examine", "up")))
  {  print("You are at the foot of a high, snowy mountain range. A cliff looms "        "before you with a tricky path winding its way up the steep face.");  }if ((said("examine", "path") ||     said("examine", "up", "path")))
  {  print("There is a narrow path winding up the steep cliff.");  }if ((said("examine", "brush") ||     said("examine", "forest") ||     said("capture", "flower") ||     said("capture", "flower") ||     said("examine", "flower")))
  {  print("The shrubbery is scant here.");  }if (said("examine", "deck"))
  {  print("The ground is strewn with large boulders.");  }if ((said("examine", "sky") ||     said("examine", "up", "sky")))
  {  print("You look upward and see the mountain range looming toward the "        "beautiful blue sky.");  }if ((said("climb", "forest") ||     said("climb", "up", "forest")))
  {  print("There are no climbable trees here.");  }if (has("Shovel"))
  {  if ((said("dig", "hole") ||       said("dig") ||       said("dig", "hole", "deck") ||       said("dig", "try", "shovel")))
    {    print("Not here.");    }  }Label1:if (isset(egoHitSpecial))
  {  v39 = 0;  v34 = 102;  set(f32);  if (posn(ego, 0, 94, 65, 114))
    {    v39 = 2;    v34 = 134;    }  if (posn(ego, 0, 38, 71, 62))
    {    v39 = 3;    v34 = 96;    }  if (posn(ego, 72, 38, 89, 50))
    {    v39 = 4;    v34 = 71;    }  if (posn(ego, 32, 75, 70, 88))
    {    v39 = 5;    v34 = 99;    }  if (posn(ego, 71, 71, 110, 87))
    {    v39 = 6;    v34 = 106;    }  if (posn(ego, 111, 66, 119, 75))
    {    v39 = 7;    v34 = 115;    v40 = 119;    reposition.to.v(ego, v40, v41);    v33 = 6;    }  if (posn(ego, 120, 66, 159, 75))
    {    v39 = 8;    v34 = 117;    }  if ((posn(ego, 0, 0, 90, 37) ||       posn(ego, 86, 0, 122, 53)))
    {    reset(f32);    v39 = 1;    v34 = 106;    if (v40 < 97)
      {      v40 = 97;      }    reposition.to.v(ego, v40, v41);    set.priority(ego, 4);    v33 = 6;    }  }call(Logic103);if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic49);  }if (edgeEgoHit == TOP_EDGE)
  {  new.room(Logic52);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic50);  }return();[ Messages#message 1 "You are at the foot of a high, snowy mountain range. A cliff looms before you with a tricky path winding its way up the steep face."#message 2 "There is a narrow path winding up the steep cliff."#message 3 "The shrubbery is scant here."#message 4 "The ground is strewn with large boulders."#message 5 "You look upward and see the mountain range looming toward the beautiful blue sky."#message 6 "There are no climbable trees here."#message 7 "Not here."