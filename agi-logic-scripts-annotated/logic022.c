if (isset(newRoom))
  {  load.view.v(currentEgoView);  set.view.v(ego, currentEgoView);  v56 = 2;  set(f65);  set.horizon(56);  v31 = 0;  random(1, 3, v36);  if (v36 == 1)
    {    v57 = 27;    v58 = 70;    }  else
    {    if (v36 == 2)
      {      v57 = 69;      v58 = 150;      }    else
      {      v57 = 139;      v58 = 82;      }    }  if (v44 == 6)
    {    set(f46);    load.view(View24);    load.view(View11);    load.sound(Sound1);    }  else
    {    load.view(View0);    load.view(View33);    if (!isset(f78))
      {      random(1, 3, v36);      if (v36 == 1)
        {        set(f231);        load.logics(Logic115);        }      }    }  if ((previousRoom == 37 ||       previousRoom == 38))
    {    set(f232);    }  v223 = 122;  if (isset(f232))
    {    load.sound(Sound1);    load.view(View11);    load.view(View30);    load.view(View24);    load.pic(v223);    }  load.pic(currentRoom);  draw.pic(currentRoom);  discard.pic(currentRoom);  if (isset(f232))
    {    overlay.pic(v223);    discard.pic(v223);    }  load.view(View35);  load.sound(Sound6);  load.logics(Logic129);  load.logics(Logic111);  if ((isset(f48) ||       previousRoom == 35))
    {    if (previousRoom == 35)
      {      set(f48);      v40 = 113;      v41 = 135;      }    if (previousRoom == 37)
      {      if (v44 == 6)
        {        if (v40 > 92)
          {          v40 = 139;          }        else
          {          v40 = 124;          }        v41 = 36;        set.priority(ego, 11);        ignore.blocks(ego);        ignore.horizon(ego);        v69 = 3;        v38 = 124;        move.obj.v(ego, v40, v38, v69, f226);        v220 = 3;        sound(Sound1, f41);        }      else
        {        ignore.horizon(ego);        ignore.blocks(ego);        v220 = 3;        v40 = 131;        v41 = 57;        set.loop(ego, 0);        fix.loop(ego);        set.priority(ego, 11);        }      }    position.v(ego, v40, v41);    }  if (isset(f47))
    {    draw(ego);    }  call(Logic111);  if (isset(f231))
    {    call(Logic115);    }  show.pic();  return();  }if (v44 == 6)
  {  ignore.blocks(ego);  ignore.objs(ego);  ignore.horizon(ego);  }reset(f228);if (posn(ego, 72, 106, 159, 151))
  {  set(f228);  }reset(f229);if (posn(ego, 99, 129, 131, 140))
  {  set(f229);  }reset(f223);if (posn(ego, 82, 121, 150, 141))
  {  set(f223);  }reset(f227);if (posn(ego, 115, 129, 119, 142))
  {  set(f227);  }if (isset(haveInput))
  {  if ((said("examine", "area") ||       said("examine")))
    {    print("The beautiful trees of the forest to the east grow sparse as they "          "reach the edge of the great desert to the west. You do notice one "          "particularly large oak tree. \"What a fine oak,\" you think.");    }  if ((said("examine", "forest") ||       said("examine", "up", "forest")))
    {    print("You look up into the towering oak tree. You can only see large, "          "spreading branches and thick leaves. Looking down, you see a small "          "hole between the tree's large roots.");    }  if (posn(ego, 53, 90, 72, 135) &&       said("anyword", "flower"))
    {    print("The flowers are pretty, but otherwise uninteresting to you.");    }  if (said("climb", "forest"))
    {    if (isset(f228))
      {      print("You try to climb the huge oak tree, but cannot find a good hand "            "hold. You slip back, and all you gain for your efforts are "            "splinters.");      }    else
      {      print("There are no climbable trees nearby.");      }    }  if (!isset(f46) &&       (said("examine", "hole") ||       said("look in", "hole") ||       said("look in", "forest")))
    {    if (!isset(f223))
      {      print("You need to be closer.");      }    else
      {      v222 = 0;      set(f221);      v68 = 4;      }    }  if (!isset(f46) &&       isset(f112) &&       said("move", "rope"))
    {    set(f225);    }  if (!isset(f46) &&       (isset(f225) ||       said("carry", "hole") ||       said("add", "fingers", "hole") ||       said("add", "fingers", "forest") ||       said("move", "rope", "hole") ||       said("examine", "inside", "hole") ||       said("examine", "inside", "forest") ||       said("carry", "inside", "hole") ||       said("carry", "inside", "forest") ||       said("add", "fingers", "inside", "forest") ||       said("carry", "hole", "move", "rope") ||       said("carry", "fingers", "hole", "move", "rope")))
    {    reset(f225);    if (!isset(f223))
      {      print("You need to be closer.");      }    else
      {      v222 = 0;      set(f221);      if (isset(f232))
        {        v68 = 7;        }      else
        {        v68 = 5;        set(f224);        }      }    }  if ((said("examine", "ladder") ||       said("examine", "rope", "ladder") ||       said("examine", "ladder", "forest")))
    {    if (isset(f232))
      {      print("The rope ladder stretches up into the branches.");      }    else
      {      print("What ladder?");      }    }  if ((said("capture", "ladder") ||       said("capture", "rope", "ladder") ||       said("capture", "ladder", "forest")))
    {    if (isset(f232))
      {      print("The ladder is attached to the oak tree. You cannot remove it.");      }    else
      {      print("What ladder?");      }    }  if ((said("examine", "deck") ||       said("examine", "below", "forest")))
    {    print("There's nothing of interest here, just some acorns scattered around "          "this old oak tree.");    }  if ((said("examine", "acorn") ||       said("examine", "acorn", "deck") ||       said("examine", "acorn", "deck", "below", "forest")))
    {    print("The acorns surround the old oak tree, and crunch under your step.");    }  if ((said("capture", "acorn") ||       said("capture", "acorn", "deck") ||       said("capture", "acorn", "from", "deck")))
    {    if (!isset(f228))
      {      print("You need to be closer.");      }    else
      {      if (obj.in.room("Acorns*", currentRoom) &&           isset(f229))
        {        print("You pick and poke among the fallen acorns, looking for dried "              "ones. You eventually find three dried acorns, and take them with "              "you.");        get("Acorns*");        currentScore  += 1;        }      else
        {        print("You pick and poke among the fallen acorns looking for dried "              "ones. You don't find any; these are all newly fallen.");        }      }    }  }if (isset(egoHitSpecial))
  {  if (v220 <= 0)
    {    v220 = 3;    ignore.blocks(ego);    v44 = 15;    set.view(ego, View30);    start.motion(ego);    if (v41 == 119)
      {      set.loop(ego, 1);      set.priority(ego, 10);      }    else
      {      set.loop(ego, 0);      set.priority(ego, 11);      }    fix.loop(ego);    reposition.to(ego, 131, 117);    }  else
    {    v220 = 0;    reset(f46);    release.priority(ego);    observe.blocks(ego);    set.view(ego, View0);    v44 = 0;    start.motion(ego);    current.loop(ego, v64);    if (v64 <= 0)
      {      set.loop(ego, 3);      v38 = 124;      }    else
      {      set.loop(ego, 2);      v38 = 115;      }    reposition.to.v(ego, v40, v38);    release.loop(ego);    }  }if (v220 > 0)
  {  set(f46);  v220 = 1;  if (v41 < 100)
    {    v220 = 2;    }  if (v41 < 70)
    {    v220 = 3;    }  if (!posn(ego, 129, 0, 133, 122))
    {    v225 = v220;    v220 = 0;    set(f37);    v44 = 6;    if (v225 == 1)
      {      set.view(ego, View0);      }    else
      {      set.view(ego, View11);      set(f35);      }    current.loop(ego, v64);    if (v64 == 1)
      {      v38 = 115;      }    else
      {      v38 = 124;      }    release.loop(ego);    v69 = 3;    move.obj.v(ego, v40, v38, v69, f230);    }  }if (isset(f230))
  {  reset(f230);  reset(f37);  observe.blocks(ego);  observe.horizon(ego);  release.priority(ego);  if (v225 == 1)
    {    v44 = 0;    start.motion(ego);    reset(f35);    reset(f46);    }  else
    {    if (v225 == 2)
      {      set.view(ego, View35);      program.control();      prevent.input();      stop.motion(ego);      v44 = 18;      set(f220);      v221 = 5;      reset(f46);      }    else
      {      set(f226);      }    }  v225 = 0;  }if (isset(f226))
  {  reset(f226);  set.view(ego, View24);  program.control();  prevent.input();  stop.motion(ego);  stop.cycling(ego);  set(f44);  }if (isset(f45))
  {  --v221;  if (v221 == 1)
    {    player.control();    accept.input();    reset(f46);    reset(f35);    reset(f220);    stop.sound();    start.motion(ego);    v44 = 0;    set.view(ego, View0);    observe.blocks(ego);    }  }if (isset(f220) &&     v44 == 18)
  {  sound(Sound6, f220);  }if (isset(f45))
  {  --v224;  if (v224 == 1)
    {    set(f221);    }  }if (isset(f221))
  {  reset(f221);  ++v222;  program.control();  prevent.input();  set(f46);  if (v222 == 1)
    {    set(f35);    if (v41 > 126)
      {      v222 = 2;      }    else
      {      v38 = 127;      v69 = 1;      move.obj.v(ego, v40, v38, v69, f221);      }    }  if (v222 == 2)
    {    move.obj(ego, 114, 135, 1, f221);    }  if (v222 == 3)
    {    stop.motion(ego);    set.view(ego, View33);    set.loop(ego, 1);    set.cel(ego, 0);    v36 = 4;    cycle.time(ego, v36);    end.of.loop(ego, f221);    }  if (v222 == 4)
    {    reset(f35);    v224 = 3;    }  if (v222 == 5)
    {    print.v(v68);    v224 = 3;    if (isset(f224))
      {      reset(f224);      set(f232);      if (!isset(f112))
        {        set(f112);        currentScore  += 3;        }      load.view(View11);      load.view(View30);      load.view(View24);      load.pic(v223);      overlay.pic(v223);      discard.pic(v223);      show.pic();      }    }  if (v222 == 6)
    {    set(f35);    reverse.loop(ego, f221);    }  if (v222 == 7)
    {    v222 = 0;    set.view(ego, View0);    player.control();    accept.input();    reset(f46);    cycle.time(ego, v59);    reset(f35);    start.motion(ego);    }  }call(Logic129);call(Logic111);if (isset(f231))
  {  call(Logic115);  }if (edgeEgoHit == BOTTOM_EDGE)
  {  new.room(Logic27);  }if (edgeEgoHit == LEFT_EDGE)
  {  new.room(Logic21);  }if (edgeEgoHit == RIGHT_EDGE)
  {  new.room(Logic23);  }if (edgeEgoHit == TOP_EDGE)
  {  if (v44 == 15)
    {    new.room(Logic37);    }  else
    {    new.room(Logic17);    }  }if (v44 == 25 &&     isset(f227))
  {  if (!isset(f113))
    {    set(f113);    currentScore  += 5;    }  print("In your insect form, you fit easily through the hole in the tree.");  new.room(Logic35);  }return();[ Messages#message 1 "The beautiful trees of the forest to the east grow sparse as they reach the edge of the great desert to the west. You do notice one particularly large oak tree. \"What a fine oak,\" you think."#message 2 "You look up into the towering oak tree. You can only see large, spreading branches and thick leaves. Looking down, you see a small hole between the tree's large roots."#message 3 "You try to climb the huge oak tree, but cannot find a good hand hold. You slip back, and all you gain for your efforts are splinters."#message 4 "You lie down on the ground and look into the small hole. It is too dark inside to see anything."#message 5 "%m6You feel around inside the hollow tree and discover a rope, stretching up into the tree. You pull it and (to your amazement) a rope ladder falls from the branches above."#message 6 "You lie down on the ground and reach into the small hole. "#message 7 "%m6You feel around for the rope, but when you pull it, nothing happens. The ladder stays in place."#message 8 "The rope ladder stretches up into the branches."#message 9 "The ladder is attached to the oak tree. You cannot remove it."#message 10 "There's nothing of interest here, just some acorns scattered around this old oak tree."#message 11 "The acorns surround the old oak tree, and crunch under your step."#message 12 "You pick and poke among the fallen acorns, looking for dried ones. You eventually find three dried acorns, and take them with you."#message 13 "You pick and poke among the fallen acorns looking for dried ones. You don't find any; these are all newly fallen."#message 14 "There are no climbable trees nearby."#message 15 "What ladder?"#message 16 "You need to be closer."#message 17 "In your insect form, you fit easily through the hole in the tree."#message 18 "You are much too big to fit into that small hole."#message 19 "The flowers are pretty, but otherwise uninteresting to you."