if (isset(newRoom))
{  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  load.view(View0);  load.view(View7);  v56 = 2;  v32 = 27;  v31 = 103;  v57 = 20;  v58 = 85;  set(f56);  set.horizon(52);  load.logics(Logic111);  load.logics(Logic110);  load.logics(Logic114);  if (v44 == 18)
  {    load.view(View35);    load.sound(Sound6);  }  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  load.view(View221);  animate.obj(o1);  position(o1, 101, 61);  set.view(o1, View221);  set.loop(o1, 0);  ignore.blocks(o1);  ignore.objs(o1);  set.priority(o1, 15);  draw(o1);  animate.obj(o2);  position(o2, 103, 118);  set.view(o2, View221);  set.loop(o2, 0);  set.cel(o2, 1);  set.priority(o2, 15);  ignore.blocks(o2);  ignore.objs(o2);  draw(o2);  animate.obj(o3);  position(o3, 96, 126);  set.view(o3, View221);  set.loop(o3, 1);  set.priority(o3, 15);  ignore.blocks(o3);  ignore.objs(o3);  v36 = 2;  cycle.time(o3, v36);  draw(o3);  animate.obj(o4);  position(o4, 130, 147);  set.view(o4, View221);  set.loop(o4, 2);  set.priority(o4, 15);  ignore.blocks(o4);  ignore.objs(o4);  draw(o4);  if (isset(f48))
  {    if (previousRoom == 12)
    {      if (v41 > 103 &&        v41 < 108)
      {        v41 = 108;      }      if (v41 > 114 &&        v41 < 121)
      {        v41 = 121;      }      if (v41 > 57 &&        v41 < 61)
      {        v41 = 61;      }    }    if (previousRoom == 14)
    {      if (v41 > 80 &&        v41 < 85)
      {        v41 = 85;      }      if (v41 > 126 &&        v41 < 133)
      {        v41 = 133;      }      if (v41 > 144)
      {        v41 = 144;      }    }    if (previousRoom == 28 &&      v44 == 18)
    {      set(f46);      program.control();      prevent.input();      stop.motion(ego);      set.view(ego, View35);      set(f35);      v220 = 5;      set(f220);    }    position.v(ego, v40, v41);  }  if (isset(f47))
  {    draw(ego);  }  call(Logic110);  call(Logic111);  call(Logic114);  show.pic();  return();}reset(f75);if ((posn(ego, 88, 58, 152, 115) ||  posn(ego, 59, 48, 88, 58) ||  posn(ego, 99, 69, 114, 74) ||  posn(ego, 92, 61, 107, 69) ||  posn(ego, 64, 50, 94, 62) ||  posn(ego, 125, 116, 155, 141)))
{  set(f75);}reset(f90);if ((posn(ego, 93, 0, 143, 76) ||  posn(ego, 103, 77, 145, 167) ||  isset(onWater)))
{  set(f90);  set(f75);}if ((posn(ego, 107, 74, 127, 75) ||  posn(ego, 112, 90, 116, 97) ||  posn(ego, 115, 95, 119, 97) ||  posn(ego, 116, 98, 126, 106) ||  posn(ego, 124, 107, 133, 110) ||  posn(ego, 127, 111, 138, 115) ||  posn(ego, 135, 116, 144, 120) ||  posn(ego, 140, 121, 149, 123) ||  posn(ego, 142, 124, 152, 126) ||  posn(ego, 133, 126, 144, 127) ||  posn(ego, 133, 128, 159, 144)))
{  set(onWater);}reset(f221);if (v41 < 74)
{  reset(onWater);  if (isset(f75))
  {    reset(f75);    set(f221);  }}if (posn(ego, 35, 100, 66, 166) &&  said("anyword", "flower"))
{  print("The flowers are pretty, but otherwise uninteresting to you.");}call(Logic114);if ((said("examine") ||  said("examine", "forest")))
{  print("The many beautiful trees bring a sense of peace to this forest. You "    "see an impassable mountain to the South.");}if (said("examine", "bluff"))
{  print("That's the mountain upon which you live, Gwydion.");}if (isset(f221) &&  (said("capture", "mud") ||    said("capture", "mud", "creek") ||    said("capture", "mud", "from", "creek") ||    said("capture", "mud", "from", "creek", "try", "ladle") ||    said("capture", "mud", "try", "ladle") ||    said("capture", "liquid", "creek") ||    said("capture", "liquid") ||    said("capture", "liquid", "cup") ||    said("capture", "drink", "liquid", "creek") ||    said("creek", "capture", "drink", "liquid") ||    said("capture", "drink", "liquid") ||    said("capture", "drink") ||    said("drink", "liquid") ||    said("drink")))
{  print("Up here, the stream is nearly imperceptible, but it widens to the "    "south.");}if (isset(f45))
{  --v220;  if (v220 == 1)
  {    player.control();    accept.input();    reset(f46);    reset(f35);    reset(f220);    stop.sound();    start.motion(ego);    v44 = 0;    set.view(ego, View0);  }}if (isset(f220) &&  v44 == 18)
{  sound(Sound6, f220);}call(Logic110);call(Logic111);if (edgeEgoHit == TOP_EDGE)
{  new.room(Logic28);}if (edgeEgoHit == LEFT_EDGE)
{  new.room(Logic12);}if (edgeEgoHit == RIGHT_EDGE)
{  new.room(Logic14);}return();[Messages#message 1 "The flowers are pretty, but otherwise uninteresting to you."#message 2 "The many beautiful trees bring a sense of peace to this forest. You see an impassable mountain to the South."#message 3 "That's the mountain upon which you live, Gwydion."#message 4 "There is a rushing stream flowing through the forest floor."#message 5 "Up here, the stream is nearly imperceptible, but it widens to the south."
