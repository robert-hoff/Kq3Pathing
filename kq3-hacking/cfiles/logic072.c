if (isset(newRoom))
  {  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  v57 = 90;  v58 = 153;  v56 = 6;  set(f64);  animate.obj(o1);  load.view(View186);  set.view(o1, View186);  ignore.horizon(o1);  if (isset(f182))
    {    position(o1, 5, 18);    }  else
    {    position(o1, 5, 34);    }  draw(o1);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  if (isset(f48))
    {    if (previousRoom == 71)
      {      position(ego, 0, 153);      }    }  if (isset(f47))
    {    draw(ego);    }  if (isset(f182))
    {    load.logics(Logic119);    call(Logic119);    }  show.pic();  return();  }if (isset(f182))
  {  call(Logic119);  }if ((said("examine") ||     said("examine", "castle")))
  {  if (!isset(f182))
    {    print("You gaze sadly at the shabby castle. It's obvious that it was once a "          "proud and beautiful place. But now, its banners are torn, its stones "          "and statue work are crumbling, and the moat has been drained. It's "          "as if no one cares anymore.");    }  else
    {    print("Atop the castle, the banners are proudly waving. The heavy feeling "          "of oppression is gone; hope has at last returned to Daventry!");    }  }if (said("examine", "banner"))
  {  if (!isset(f182))
    {    print("Sadly, the torn banners of the shabby castle are flying at "          "half-mast.");    }  else
    {    print("The worn banners atop the crumbling castle proudly wave.");    }  }if ((said("climb", "moat") ||     said("jump", "moat") ||     said("jump", "above", "moat") ||     said("climb", "down", "moat") ||     said("examine", "moat")))
  {  print("The moat is too wide to cross. There is nothing of interest there, "        "anyway.");  }if (said("examine", "forest"))
  {  print("A once green woodland spreads out before you. Now, its many trees and "        "bushes are cruelly charred.");  }if (said("examine", "brush"))
  {  print("You see no flowers about.");  }if ((said("climb", "up", "forest") ||     said("climb", "forest")))
  {  print("There are no climbable trees around.");  }if ((said("examine", "up", "sky") ||     said("examine", "sky")))
  {  print("The sky is blue and the sun is shining, but yet a feeling of sadness "        "lingers here.");  }if ((said("examine", "on", "deck") ||     said("examine", "deck")))
  {  print("There is nothing interesting on the ground but green grass.");  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic71);  }if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic69);  }return();[ Messages#message 1 "You gaze sadly at the shabby castle. It's obvious that it was once a proud and beautiful place. But now, its banners are torn, its stones and statue work are crumbling, and the moat has been drained. It's as if no one cares anymore."#message 2 "Atop the castle, the banners are proudly waving. The heavy feeling of oppression is gone; hope has at last returned to Daventry!"#message 3 ""#message 4 ""#message 6 ""#message 7 ""#message 8 ""#message 9 "Sadly, the torn banners of the shabby castle are flying at half-mast."#message 10 "The worn banners atop the crumbling castle proudly wave."#message 11 "The moat is too wide to cross. There is nothing of interest there, anyway."#message 12 ""#message 13 ""#message 14 "A once green woodland spreads out before you. Now, its many trees and bushes are cruelly charred."#message 15 "You see no flowers about."#message 16 "There are no climbable trees around."#message 17 "The sky is blue and the sun is shining, but yet a feeling of sadness lingers here."#message 18 "There is nothing interesting on the ground but green grass."