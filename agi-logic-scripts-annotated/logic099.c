if (isset(newRoom) &&  monitorType != MONO)
{  display(24, 26, "%v0|3");}if (controller(c11))
{  set.text.attribute(BLACK, WHITE);  text.screen();  v37 = 0;  v38 = 3;  v68 = 32;  v45 = 1;Label1:  display.v(v38, v37, v68);  ++v45;  ++v38;  if (v45 == 19)
  {    v37 = 12;    v38 = 3;  }  if (v45 == 37)
  {    v37 = 26;    v38 = 3;  }  if (v45 < 55)
  {    goto(Label1);  }  display(23, 1, "(Sorry. Do the best you can!)");Label2:  if (!have.key())
  {    goto(Label2);  }  set.text.attribute(WHITE, BLACK);  graphics();}if (monitorType != MONO)
{  if (isset(f46))
  {    display(24, 35, "H");  }  else
  {    display(24, 35, " ");  }}if (said("all", "area"))
{  get.num("Object number:", v46);  get.room.v(v46, v45);  print("Object %v46 is in room %v45.");}if (controller(c13))
{  show.mem();}if ((controller(c19) ||  said("examine", "priority")))
{  show.pri.screen();}if (said("add", "priority"))
{  get.num("New priority:", v46);  set.priority.v(ego, v46);}if (said("let go", "priority"))
{  release.priority(ego);}if (said("tp"))
{  get.num("New room:", v45);  v44 = 14;  new.room.v(v45);}if (said("position"))
{  get.num("X coordinate:", v45);  get.num("Y coordinate:", v46);  erase(ego);  position.v(ego, v45, v46);  draw(ego);}if ((controller(c28) ||  said("examine", "position") ||  said("sp")))
{  toggle(f50);  clear.lines(24, 24, BLACK);}if ((controller(c21) ||  said("find")))
{  v45 = 0;  obj.status.v(v45);}if ((controller(c36) ||  said("examine", "all") ||  said("all")))
{  get.num("Object number:", v45);  if (v45 > 15)
  {    v45 = 15;  }  obj.status.v(v45);}if (said("capture", "all"))
{  get.num("Object number:", v45);  get.v(v45);}if (said("examine", "banner"))
{  get.num("Flag number:", v45);  if (issetv(v45))
  {    print("Flag %v45 set");  }  else
  {    print("Flag %v45 not set");  }}if (said("add", "banner"))
{  get.num("Flag number:", v45);  set.v(v45);}if (said("reset", "banner"))
{  get.num("Flag number:", v45);  reset.v(v45);}if (said("examine", "var"))
{  get.num("Variable number:", v45);  v46 = *v45;  print("Variable %v45 = %v46");}if (said("add", "var"))
{  get.num("Variable number:", v45);  get.num("New value:", v46);  *v45 = v46;}if ((said("area", "number") ||  said("area")))
{  print("Current room = %v0");}if (unknownWordNum > 0)
{  if (unknownWordNum == 1)
  {    log("%m20%w1\"");  }  if (unknownWordNum == 2)
  {    log("%m20%w2\"");  }  if (unknownWordNum == 3)
  {    log("%m20%w3\"");  }  if (unknownWordNum == 4)
  {    log("%m20%w4\"");  }  if (unknownWordNum == 5)
  {    log("%m20%w5\"");  }  if (unknownWordNum == 6)
  {    log("%m20%w6\"");  }  if (unknownWordNum == 7)
  {    log("%m20%w7\"");  }  if (unknownWordNum > 7)
  {    log("%m20%w8\"");  }}if (isset(f50) &&  monitorType != MONO)
{  v45 = v40;  v46 = v41;  set.text.attribute(BROWN, BLACK);  display(24, 16, "%v45|3/%v46|3");  set.text.attribute(WHITE, BLACK);}if (said("sleep", "enchanter"))
{  if (monitorType != MONO)
  {    display(0, 0, "He's sleeping.");  }  v128 = 7;  v127 = 4;  v84 = 20;  v83 = 0;}if (said("here", "enchanter"))
{  if (monitorType != MONO)
  {    display(0, 0, "Coming, Dear!");  }  v128 = 0;  v84 = 0;  v83 = 0;  if (v137 > 0)
  {    print("He won't show up until you \"do chore.\"");  }}if (said("cast", "chore"))
{  if (monitorType != MONO)
  {    display(0, 0, "Done.");  }  v137 = 0;  v110 = 0;  v109 = 0;}if (said("bye", "bye", "enchanter"))
{  if (monitorType != MONO)
  {    display(0, 0, "He's dead.");  }  v128 = 20;  v84 = 0;  v83 = 0;}if (controller(c30) || said("gimme", "gimme") || said("add", "up", "spell"))
{  call(Logic97);}if (said("add", "up", "bluff"))
{  call(Logic95);}if (said("add", "up", "boat"))
{  call(Logic94);}if (said("gimme", "spell"))
{  call(Logic93);}if (said("enchanter", "status"))
{  call(Logic92);}return();[Messages#message 1 "New room:"#message 2 "X coordinate:"#message 3 "Y coordinate:"#message 4 "Object number:"#message 5 "Flag number:"#message 6 "New value:"#message 7 "Current room = %v0"#message 8 "Variable number:"#message 9 "Variable %v45 = %v46"#message 10 "Flag %v45 set"#message 11 "Flag %v45 not set"#message 12 "New priority:"#message 13 "Object %v46 is in room %v45."#message 14 "%v45|3/%v46|3"#message 15 "%v0|3"#message 16 "He's sleeping."#message 17 "Coming, Dear!"#message 18 "He's dead."#message 19 "He won't show up until you \"do chore.\""#message 20 "Unknown wor  \""#message 21 "%m20%w1\""#message 22 "%m20%w2\""#message 23 "%m20%w3\""#message 24 "%m20%w4\""#message 25 "%m20%w5\""#message 26 "%m20%w6\""#message 27 "%m20%w7\""#message 28 "%m20%w8\""#message 29 "H"#message 30 " "#message 31 "Done."#message 32 " %v45|2 %o45"#message 33 "(Sorry. Do the best you can!)"
