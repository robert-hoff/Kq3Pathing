if (isset(newRoom))
{  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  v56 = 7;  set(f34);  v57 = 120;  v58 = 145;  v32 = 54;  v31 = 151;  load.logics(Logic116);  load.logics(Logic109);  call(Logic109);  load.view(View36);  load.view(View0);  load.view(View37);  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  if (isset(f48))
  {    v37 = 10;    position.v(ego, v37, v41);  }  if (isset(f47))
  {    draw(ego);  }  random(2, 3, v36);  if (v36 == 3)
  {    set(f221);    v220 = 5;    load.view(View171);    animate.obj(o2);    set.view(o2, View171);    v36 = 2;    step.size(o2, v36);    v38 = 145;    random(1, 130, v37);    position.v(o2, v37, v38);    wander(o2);    draw(o2);    animate.obj(o3);    set.view(o3, View171);    v36 = 2;    step.size(o3, v36);    v38 = 145;    random(1, 130, v37);    position.v(o3, v37, v38);    wander(o3);    draw(o3);  }  show.pic();  return();}call(Logic116);call(Logic109);if (isset(f45) &&  v220 > 0)
{  --v220;}distance(o2, o3, v36);if (isset(f221) &&  v220 <= 0 &&  has("Dough in Ears") &&  v36 < 15)
{  v220 = 5;  random(1, 5, v36);  v221 = 0;  v222 = 0;  if (v36 == 1 &&    !isset(f193))
  {    set(f193);    v221 = 10;    v222 = 13;  }  if (v36 == 2 &&    !isset(f194))
  {    set(f194);    v221 = 13;    v222 = 17;  }  if (v36 == 3 &&    !isset(f195))
  {    set(f195);    v221 = 17;    v222 = 21;  }  if (v36 == 4 &&    !isset(f196))
  {    set(f196);    v221 = 21;    v222 = 24;  }  if (v36 == 5 &&    !isset(f197))
  {    set(f197);    v221 = 24;    v222 = 27;  }Label1:  if (v221 < v222)
  {    v220 = 120;    print.at.v(v221, 2, 2, 37);    ++v221;    goto(Label1);  }}if ((said("examine", "area") ||  said("examine") ||  said("examine", "carry")))
{  print("You look warily around the dark, dank cargo hold. There seems to be "    "nothing but stacks of wooden crates piled around.");}if ((said("examine", "up", "ceiling") ||  said("examine", "ceiling")))
{  print("You see an open grating far above you. Too bad you can't reach it.");}if (said("examine", "mice"))
{  if (isset(f221))
  {    print("A couple of little gray mice scurry to and fro on the floor of the "      "hold.");  }  else
  {    print("What mice?");  }}if (said("hear", "mice"))
{  print("Shhhh. If you're quiet, maybe you can hear them.");}if (said("call", "mice"))
{  if (isset(f221))
  {    print("The little mice totally ignore your attempted conversation.");  }  else
  {    print("What mice?");  }}if (said("capture", "mice"))
{  if (isset(f221))
  {    print("The mice move much too quickly for you to ever catch.");  }  else
  {    print("What mice?");  }}if (said("kill", "mice"))
{  if (isset(f221))
  {    print("How cruel!! You wouldn't want to do that!");  }  else
  {    print("What mice?");  }}if ((said("board", "carry") ||  said("climb", "out", "carry")))
{  print("Good idea! How?");}if (edgeEgoHit == LEFT_EDGE)
{  new.room(Logic85);}return();[Messages#message 1 "You look warily around the dark, dank cargo hold. There seems to be nothing but stacks of wooden crates piled around."#message 2 "Shhhh. If you're quiet, maybe you can hear them."#message 3 "You see an open grating far above you. Too bad you can't reach it."#message 4 "Good idea! How?"#message 5 "What mice?"#message 6 "A couple of little gray mice scurry to and fro on the floor of the hold."#message 7 "The little mice totally ignore your attempted conversation."#message 8 "The mice move much too quickly for you to ever catch."#message 9 "How cruel!! You wouldn't want to do that!"#message 10 "\"Do you know where the pirates are taking us?\" one gray mouse asks the other."#message 11 "\"I heard them talking about a buried treasure chest,\" the other mouse answers. \"I think it's buried on a beach, and they're going to dig it up.\""#message 12 "\"Oh, I remember!\" squeaks the first mouse. \"Remember when they first buried the treasure? It was on a small beach, and behind the beach was a high mountain range. I remember hearing one pirate say that nobody has ever crossed those mountains alive.\""#message 13 "\"You know the pirate's buried treasure?\" you hear one of the mice say to the other."#message 14 "\"What about it?\" asks the second mouse."#message 15 "Says the first, \"Well, I just heard the captain talking about it with one of his men. He said it was buried... now let me see if I can remember. Oh, yeah! He said it was buried near a lone palm tree. From the palm, you walk five paces to the east and then start digging.\""#message 16 "\"Too bad we can't do anything about it,\" muses the other mouse."#message 17 "\"What do you think the pirates will do with the boy they shang-hai'd,\" a little gray mouse squeaks to a companion."#message 18 "\"They'll probably make him a cabin boy,\" answered the other mouse."#message 19 "\"What happened to the last cabin boy they had?\""#message 20 "\"Didn't you hear? They fed him to the sharks just for sport.\""#message 21 "You listen as two mice talk to each other. One says, \"I heard the pirates talking about bringing a CAT on board!\""#message 22 "\"No! Don't scare me like that!\" exclaimed the other mouse."#message 23 "Retorts the first, \"I mean it! They said there's getting to be too many mice on this ship. We need to call a \"mouse counsel\" and decide what to do about this situation!\""#message 24 "\"It's getting so musty and damp down here, don't you think?\" you hear one gray mouse ask the other."#message 25 "\"That's water seeping through the hull,\" explains the second mouse. \"But, I agree with you, it is getting uncomfortable. Why, I have a hard time keeping mildew off my nest!\""#message 26 "\"Yes, but it is safer down here,\" returns the first. \"I guess we gotta take the bad with the good.\""
