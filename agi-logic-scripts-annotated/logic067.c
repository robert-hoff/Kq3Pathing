if (isset(newRoom))
  {  v56 = 5;  set.horizon(55);  v57 = 30;  v58 = 90;  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.sound(Sound1);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  if (isset(f48))
    {    if (previousRoom == 64)
      {      position(ego, 123, 102);      }    }  if (isset(f47))
    {    draw(ego);    }  if (isset(f182))
    {    position(ego, 0, 105);    load.logics(Logic119);    call(Logic119);    }  show.pic();  return();  }if (isset(f230) &&     v230 == 0)
  {  ++v230;  program.control();  move.obj(ego, 160, 105, 1, f230);  }if (!isset(f59))
  {  set(f59);  print("It feels strangely hot up here.");  }if (isset(f182))
  {  call(Logic119);  }if (v71 == 1)
  {  v71 = 0;  drop("Magic Map*");  print("As you unroll the delicate map, it crumbles in the intense heat!");  }if (v44 == 0 &&     (v41 > 162 ||     edgeEgoHit == RIGHT_EDGE ||     edgeEgoHit == TOP_EDGE))
  {  print("This mystical cloud land may never cease to amaze you, but...");  sound(Sound1, f238);  erase(ego);  v220 = 2;  set.scan.start();  if (isset(f45))
    {    --v220;    }  if (v220 <= 0)
    {    print("...it has ceased to support you!  Enjoy the trip.");    reset.scan.start();    set(f44);    }  return();  }if ((said("examine") ||     said("examine", "cloud")))
  {  print("Looking around, you see clouds surrounding this small bit of land like "        "a white, cottony sea. Charred stumps of trees spoil the scene.");  }if ((said("examine", "brush") ||     said("examine", "forest") ||     said("examine", "flower") ||     said("capture", "flower") ||     said("climb", "forest")))
  {  print("All of the trees and plants in this area have been burnt to stumps by "        "the evil three-headed dragon!");  }if (said("examine", "deck"))
  {  print("The ground is moist from the constant presence of clouds, but yet the "        "trees are burnt and blackened.");  }if (said("examine", "sky"))
  {  print("The sky is blue and cloudless above this strange cloud land.");  }if (said("examine", "deck"))
  {  print("This is a very strange cloud land. There is just a bit of land dotted "        "with charred trees encircled by a sea of white, fluffy clouds. This "        "gives you the odd feeling of floating upon a cottony ocean. A cave "        "entrance leads into a steep mountainside.");  }if (said("examine", "bluff"))
  {  print("The mountain rises steeply from this bizarre cloud land.  A cave goes "        "into its depths.");  }if (said("climb", "bluff"))
  {  print("The mountain is unclimbable as it is much too steep and rocky.");  }if ((said("examine", "cave") ||     said("look in", "cave")))
  {  print("The cave leads deep into the steep mountainside. Within, crumbly stone "        "steps lead downward to murky depths.");  }if (isset(egoHitSpecial))
  {  new.room(Logic64);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic66);  }return();[ Messages#message 1 "Looking around, you see clouds surrounding this small bit of land like a white, cottony sea. Charred stumps of trees spoil the scene."#message 2 "All of the trees and plants in this area have been burnt to stumps by the evil three-headed dragon!"#message 3 "The ground is moist from the constant presence of clouds, but yet the trees are burnt and blackened."#message 4 "The sky is blue and cloudless above this strange cloud land."#message 5 "This is a very strange cloud land. There is just a bit of land dotted with charred trees encircled by a sea of white, fluffy clouds. This gives you the odd feeling of floating upon a cottony ocean. A cave entrance leads into a steep mountainside."#message 6 "The mountain rises steeply from this bizarre cloud land.  A cave goes into its depths."#message 7 "The mountain is unclimbable as it is much too steep and rocky."#message 8 "It feels strangely hot up here."#message 9 "The cave leads deep into the steep mountainside. Within, crumbly stone steps lead downward to murky depths."#message 10 "This mystical cloud land may never cease to amaze you, but..."#message 11 "...it has ceased to support you!  Enjoy the trip."#message 12 "As you unroll the delicate map, it crumbles in the intense heat!"