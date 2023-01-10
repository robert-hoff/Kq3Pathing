if (isset(newRoom))
  {  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  v57 = 57;  v58 = 153;  v56 = 6;  set(f63);  animate.obj(o3);  load.view(View97);  set.view(o3, View97);  position(o3, 104, 120);  if (isset(f182))
    {    set.cel(o3, 2);    }  else
    {    set.cel(o3, 0);    }  draw(o3);  stop.update(o3);  animate.obj(o1);  load.view(View186);  set.view(o1, View186);  ignore.horizon(o1);  if (isset(f182))
    {    position(o1, 130, 16);    }  else
    {    position(o1, 130, 34);    }  v36 = 3;  cycle.time(o1, v36);  draw(o1);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  if (isset(f48))
    {    if (previousRoom == 69)
      {      position(ego, 89, 164);      }    }  if (isset(f47))
    {    draw(ego);    }  if (isset(f182))
    {    load.logics(Logic119);    call(Logic119);    }  show.pic();  if (isset(f182))
    {    move.obj(ego, 110, 120, 1, f220);    print("The castle doors are wide open to welcome home a long-missing son, "          "and a much-loved daughter. Atop the castle, the banners proudly "          "wave. The heavy feeling of oppression is gone; hope has at last "          "returned to Daventry!");    prevent.input();    }  return();  }v39 = 0;if (posn(ego, 102, 119, 121, 126))
  {  v39 = 1;  }if (isset(f182))
  {  call(Logic119);  }if ((said("examine") ||     said("examine", "castle")))
  {  if (!isset(f182))
    {    print("You gaze sadly at the deteriorated castle. It's obvious that it was "          "once proud and beautiful. But now, its banners are torn, its stones "          "and statue work crumbling, and the moat has been drained. It's as if "          "no one cares anymore.");    }  else
    {    print("The castle doors are wide open to welcome home a long-missing son, "          "and a much-loved daughter. Atop the castle, the banners proudly "          "wave. The heavy feeling of oppression is gone; hope has at last "          "returned to Daventry!");    }  }if ((said("examine", "door", "castle") ||     said("examine", "door")))
  {  if (!isset(f182))
    {    print("The massive wooden doors of the castle are closed.");    }  else
    {    print("%m2");    }  }if (said("call", "rol"))
  {  print("No one answers.");  }if (said("lift", "door"))
  {  if (v39 == 1)
    {    print("The huge doors of the castle are bolted shut. Try as you might, you "          "cannot open them.");    }  else
    {    print("And just how do you intend to do that from where you're standing.");    }  }if (!isset(f182) &&     (said("bang", "door") ||     said("bang", "on", "door")))
  {  if (v39 == 1)
    {    print("You rap loudly upon the massive wooden doors of the castle. "          "Hollowly, emptily, the sound reverberates within. No one answers.");    }  else
    {    print("And just how do you intend to do that from where you're standing.");    }  }if (said("unlock", "door") &&     !isset(f182))
  {  if (v39 == 1)
    {    print("You obviously do not have the key to this castle.");    }  else
    {    print("And just how do you intend to do that from where you're standing.");    }  }if (said("break", "door") &&     !isset(f182))
  {  if (v39 == 1)
    {    print("Your body is no match for these huge wooden doors.");    }  else
    {    print("And just how do you intend to do that from where you're standing.");    }  }if (said("examine", "banner"))
  {  if (!isset(f182))
    {    print("Sadly, the torn banners of the shabby castle fly at half staff.");    }  else
    {    print("The worn banners atop the crumbling castle proudly wave.");    }  }if ((said("climb", "moat") ||     said("jump", "moat") ||     said("jump", "above", "moat") ||     said("climb", "down", "moat") ||     said("examine", "above", "moat") ||     said("examine", "moat")))
  {  print("The moat is too wide and too deep to cross. There is nothing of "        "interest there, anyway.");  }if (said("examine", "forest"))
  {  print("A once green woodland spreads out before you. Now, its many trees and "        "bushes are cruelly charred.");  }if (said("examine", "brush"))
  {  print("You see no flowers about.");  }if ((said("climb", "up", "forest") ||     said("climb", "forest")))
  {  print("There are no climbable trees around.");  }if ((said("examine", "up", "sky") ||     said("examine", "sky")))
  {  print("The sky is blue and the sun is shining, but yet a feeling of sadness "        "lingers here.");  }if ((said("examine", "on", "deck") ||     said("examine", "deck")))
  {  print("There is nothing interesting on the ground but green grass.");  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic72);  }if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic69);  }if (isset(f182) &&     posn(ego, 105, 121, 116, 122))
  {  new.room(Logic73);  }return();[ Messages#message 1 "You gaze sadly at the deteriorated castle. It's obvious that it was once proud and beautiful. But now, its banners are torn, its stones and statue work crumbling, and the moat has been drained. It's as if no one cares anymore."#message 2 "The castle doors are wide open to welcome home a long-missing son, and a much-loved daughter. Atop the castle, the banners proudly wave. The heavy feeling of oppression is gone; hope has at last returned to Daventry!"#message 3 "The massive wooden doors of the castle are closed."#message 4 "%m2"#message 5 "The huge doors of the castle are bolted shut. Try as you might, you cannot open them."#message 6 "You rap loudly upon the massive wooden doors of the castle. Hollowly, emptily, the sound reverberates within. No one answers."#message 7 "You obviously do not have the key to this castle."#message 8 "Your body is no match for these huge wooden doors."#message 9 "Sadly, the torn banners of the shabby castle fly at half staff."#message 10 "The worn banners atop the crumbling castle proudly wave."#message 11 "The moat is too wide and too deep to cross. There is nothing of interest there, anyway."#message 12 "And just how do you intend to do that from where you're standing."#message 13 "No one answers."#message 14 "A once green woodland spreads out before you. Now, its many trees and bushes are cruelly charred."#message 15 "You see no flowers about."#message 16 "There are no climbable trees around."#message 17 "The sky is blue and the sun is shining, but yet a feeling of sadness lingers here."#message 18 "There is nothing interesting on the ground but green grass."