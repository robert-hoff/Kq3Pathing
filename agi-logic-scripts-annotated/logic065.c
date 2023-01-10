if (isset(newRoom))
{  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  set(f57);  v56 = 5;  set.horizon(37);  v57 = 30;  v58 = 90;  if (isset(f182))
  {    load.logics(Logic119);  }  load.view(View0);  load.view(View11);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.sound(Sound1);  if (isset(f48))
  {    // [ WARNING: this block contains no commands  }  if (isset(f47))
  {    draw(ego);  }  show.pic();  if (isset(f182))
  {    call(Logic119);  }}if (v44 == 0 &&  edgeEgoHit == TOP_EDGE)
{  set(egoHitSpecial);}if (isset(egoHitSpecial))
{  print("You have skillfully detected the boundaries of cloud land. The rest of "    "your quest will go quickly...");  erase(ego);  v220 = 5;  sound(Sound1, f238);  set.scan.start();  if (isset(f45))
  {    --v220;  }  if (v220 <= 0)
  {    stop.sound();    print("...downward!");    reset.scan.start();    set(f44);  }  return();}if (isset(f182))
{  call(Logic119);}if (v71 == 1)
{  v71 = 0;  drop("Magic Map*");  print("As you unroll the delicate map, it crumbles in the intense heat!");}if ((said("examine") ||  said("examine", "cloud")))
{  print("Looking around, you see clouds surrounding this small bit of land like "    "a white, cottony sea. Charred stumps of trees spoil the scene.");}if ((said("examine", "brush") ||  said("examine", "forest") ||  said("examine", "flower") ||  said("capture", "flower") ||  said("climb", "forest")))
{  print("All of the trees and plants in this area have been burnt to stumps by "    "the evil three-headed dragon!");}if (said("examine", "deck"))
{  print("The ground is moist from the constant presence of clouds, but yet the "    "trees are burnt and blackened.");}if ((said("examine", "up") ||  said("examine", "up", "sky") ||  said("examine", "sky")))
{  print("The sky is blue and cloudless above this strange cloud land.");}if (edgeEgoHit == RIGHT_EDGE)
{  new.room(Logic66);}return();[Messages#message 1 "Looking around, you see clouds surrounding this small bit of land like a white, cottony sea. Charred stumps of trees spoil the scene."#message 2 "All of the trees and plants in this area have been burnt to stumps by the evil three-headed dragon!"#message 3 "The ground is moist from the constant presence of clouds, but yet the trees are burnt and blackened."#message 4 "The sky is blue and cloudless above this strange cloud land."#message 5 "You have skillfully detected the boundaries of cloud land. The rest of your quest will go quickly..."#message 6 "...downward!"#message 7 "As you unroll the delicate map, it crumbles in the intense heat!"
