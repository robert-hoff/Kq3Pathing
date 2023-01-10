if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  v56 = 1;  v57 = 12;  v58 = 92;  v32 = 137;  v31 = 69;  set.horizon(49);  load.logics(Logic103);  reset(f32);  v34 = 166;  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f48))
    {    if (previousRoom == 34)
      {      position(ego, 17, 51);      }    else
      {      if (previousRoom == 18)
        {        position(ego, 22, 167);        start.motion(ego);        }      else
        {        position.v(ego, v57, v58);        }      }    }  if (isset(f47))
    {    draw(ego);    }  reset(f37);  call(Logic103);  show.pic();  return();  }if (!isset(haveInput))
  {  goto(Label1);  }if ((said("examine", "path") ||     said("examine", "up", "path") ||     said("examine") ||     said("examine", "down", "path")))
  {  print("The winding path spirals steeply down the mountainside. It leads from "        "the wizard's house at the top, to the forests of Llewdor below.");  }if ((said("examine", "sky") ||     said("examine", "up", "sky")))
  {  print("The sky is darker near the top of the mountain as there are dark, "        "swirling clouds surrounding its summit.");  }if ((said("examine", "cloud") ||     said("examine", "up", "cloud") ||     said("examine", "sky") ||     said("examine", "cloud", "sky") ||     said("examine", "up", "cloud", "sky")))
  {  print("Dark clouds surround the mountain peak, adding a cold and sinister "        "feeling.");  }if ((said("examine", "bluff") ||     said("examine", "abominable")))
  {  print("The lone mountain, with its steep path, rises from the forests of "        "Llewdor to a cloud-encircled peak.");  }if ((said("examine", "forest") ||     said("examine", "flower") ||     said("capture", "flower") ||     said("climb", "forest") ||     said("examine", "brush")))
  {  print("The foliage is very scant on this steep mountainside.");  }if ((said("examine", "area") ||     said("examine", "building")))
  {  print("It is very difficult to see the wizard's house from this viewpoint.");  }Label1:v39 = 0;if (isset(egoHitSpecial))
  {  v33 = 6;  if (posn(ego, 9, 60, 18, 78))
    {    v39 = 1;    v40  += 6;    reposition.to.v(ego, v40, v41);    set.priority(ego, 6);    }  if (v39 <= 0 &&       (posn(ego, 0, 0, 21, 59) ||       posn(ego, 0, 60, 8, 68)))
    {    v39 = 2;    set.priority(ego, 4);    }  if (v39 <= 0 &&       posn(ego, 7, 79, 31, 87))
    {    v39 = 3;    set.priority(ego, 6);    }  if (v39 <= 0 &&       posn(ego, 0, 89, 53, 100))
    {    v39 = 4;    set.priority(ego, 8);    }  if (v39 <= 0 &&       (posn(ego, 47, 75, 72, 80) ||       posn(ego, 46, 81, 56, 88)))
    {    v39 = 5;    set.priority(ego, 7);    }  if (v39 <= 0 &&       posn(ego, 54, 65, 59, 74))
    {    v39 = 6;    v40  += 6;    reposition.to.v(ego, v40, v41);    set.priority(ego, 6);    }  if (v39 <= 0 &&       posn(ego, 140, 64, 154, 71))
    {    v39 = 7;    set.priority(ego, 5);    v40 = 145;    reposition.to.v(ego, v40, v41);    }  if (v39 <= 0 &&       posn(ego, 62, 84, 115, 89))
    {    v39 = 8;    set.priority(ego, 7);    }  if (v39 <= 0 &&       posn(ego, 54, 87, 62, 130))
    {    v39 = 9;    v40 -= 8;    reposition.to.v(ego, v40, v41);    set.priority(ego, 8);    }  if (v39 <= 0 &&       posn(ego, 77, 95, 132, 131))
    {    v39 = 10;    set.priority(ego, 8);    }  if (v39 <= 0 &&       (posn(ego, 65, 132, 123, 157) ||       posn(ego, 29, 153, 65, 167)))
    {    v39 = 11;    set.priority(ego, 13);    }  if (v39 <= 0 &&       posn(ego, 12, 145, 29, 167))
    {    v39 = 12;    v40 -= 8;    reposition.to.v(ego, v40, v41);    set.priority(ego, 11);    }  if (v39 <= 0 &&       posn(ego, 29, 141, 49, 147))
    {    v39 = 13;    set.priority(ego, 11);    }  if (v39 <= 0 &&       posn(ego, 49, 130, 63, 146))
    {    v39 = 14;    v40 -= 8;    reposition.to.v(ego, v40, v41);    set.priority(ego, 12);    }  if (v39 <= 0 &&       posn(ego, 32, 65, 120, 74))
    {    v39 = 15;    set.priority(ego, 6);    }  }if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic18);  }if (edgeEgoHit == TOP_EDGE)
  {  new.room(Logic34);  }call(Logic103);return();[ Messages#message 1 "The winding path spirals steeply down the mountainside. It leads from the wizard's house at the top, to the forests of Llewdor below."#message 2 "The sky is darker near the top of the mountain as there are dark, swirling clouds surrounding its summit."#message 3 "Dark clouds surround the mountain peak, adding a cold and sinister feeling."#message 4 "The lone mountain, with its steep path, rises from the forests of Llewdor to a cloud-encircled peak."#message 5 "The foliage is very scant on this steep mountainside."#message 6 "It is very difficult to see the wizard's house from this viewpoint."