if (isset(newRoom))
{  prevent.input();  load.view(View0);  animate.obj(o1);  load.view(View170);  set.view(o1, View170);  set.loop(o1, 2);  v36 = 2;  step.time(o1, v36);  fix.loop(o1);  position(o1, 0, 60);  load.sound(Sound30);  load.sound(Sound39);  set(f220);  v36 = 31;  load.pic(v36);  draw.pic(v36);  discard.pic(v36);  draw(o1);  move.obj(o1, 160, 60, 1, f41);  v56 = 7;  if (!isset(f51))
  {    set(f51);    v36 = 73;  Label1:    if (v36 > 51)
    {      reset.v(v36);      --v36;      goto(Label1);    }  }  sound(Sound30, f238);  show.pic();  v62 = 1;  v52 = 2;  v53 = 0;  return();}get.posn(o1, v37, v38);if (isset(f238))
{  if (isset(f220))
  {    if (v37 < 30)
    {      sound(Sound30, f238);    }    else
    {      reset(f220);      print("Nothing like a little salt air to perk up a boy's spirits. All "        "things being equal, you might have enjoyed this ocean voyage...");    }  }  else
  {    print("...however, you have found your accommodations to be slightly less "      "than satisfactory.");    reset(f220);    reset(f238);    sound(Sound39, f220);  }}if (objHitEdge > 0)
{  accept.input();  player.control();  new.room(Logic85);}return();[Messages#message 1 "Nothing like a little salt air to perk up a boy's spirits. All things being equal, you might have enjoyed this ocean voyage..."#message 2 "...however, you have found your accommodations to be slightly less than satisfactory."
