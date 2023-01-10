if (isset(newRoom))
  {  animate.obj(o15);  load.view(View73);  load.sound(Sound33);  if (!isset(f182))
    {    load.view(View74);    load.view(View75);    position(o15, 8, 108);    set.view(o15, View74);    v36 = 3;    cycle.time(o15, v36);    }  else
    {    set.view(o15, View73);    get.posn(ego, v37, v38);    if ((egoDir == UP ||         egoDir == UP_LEFT ||         egoDir == UP_RIGHT))
      {      v38  += 1;      }    if ((egoDir == DOWN_RIGHT ||         egoDir == DOWN ||         egoDir == DOWN_LEFT))
      {      v38 -= 1;      }    position.v(o15, v37, v38);    follow.ego(o15, 8, f184);    }  draw(o15);  return();  }if (currentRoom == 69 &&     !isset(f61))
  {  print("\"There's home!\" your sister cries in delight. \"Mum and Dad will be "        "SOOOOOO happy!!\"");  }if (isset(f182) &&     v71 > 0)
  {  print("This is no time for magic. Take Princess Rosella home.");  v71 = 0;  }if (isset(f44))
  {  normal.motion(o15);  stop.motion(o15);  stop.cycling(o15);  return();  }if (said("let go", "barmaid"))
  {  if (!isset(f182))
    {    distance(ego, o15, v36);    if (v36 > 16)
      {      print("You are not close enough to her.");      }    else
      {      currentScore  += 3;      set(f182);      if (isset(f183))
        {        print("You rapidly untie Princess Rosella from the wooden pole. She "              "looks bewildered as to who her benefactor may be. \"I'm your "              "long-lost brother, Prince Alexander,\" you proudly exclaim. The "              "girl looks doubtful.");        print("\"I'll explain it all later,\" you continue, realizing that now "              "is not the time for this. \"Just follow me. Let's go meet the "              "folks!\" With mixed emotions, the girl agrees to follow you.");        stop.sound();        sound(Sound33, f238);        set.view(o15, View73);        v36 = 1;        cycle.time(o15, v36);        follow.ego(o15, 6, f184);        }      }    }  else
    {    print("You've already untied her.");    }  }distance(ego, o15, v36);if (isset(f182) &&     isset(f184))
  {  if (v36 > 12)
    {    start.cycling(o15);    follow.ego(o15, 6, f184);    }  else
    {    stop.cycling(o15);    }  }if ((said("call", "try", "barmaid") ||     said("call", "barmaid")))
  {  if (!isset(f183))
    {    print("She can't hear you. She's too busy screaming!");    }  else
    {    if (!isset(f182))
      {      print("\"Help me!! Untie me!!\" Princess Rosella screams.");      }    else
      {      ++v180;      print.v(v180);      if (v180 > 5)
        {        --v180;        }      }    }  }if (said("capture", "barmaid"))
  {  if (isset(f182))
    {    print("She's already with you.");    }  else
    {    print("The girl is securely tied to the stake.");    }  }if (said("kill", "barmaid"))
  {  print("What manner of monster are you?");  }if (said("embrace", "barmaid"))
  {  if (isset(f182))
    {    print("You plant a brotherly kiss upon Princess Rosella's soft cheek.");    }  else
    {    print("Not now!");    }  }if (said("aim", "barmaid"))
  {  if (isset(f182))
    {    print("WATCH IT, FELLA!!");    }  else
    {    print("Not now!");    }  }if (said("examine", "barmaid"))
  {  if (!isset(f182))
    {    print("The girl is securely tied to the stake.");    }  else
    {    print("Princess Rosella is gorgeous! Why, you'd be interested in her if she "          "weren't your own sister! Her hair is long, silky, and golden. Her "          "eyes are as blue as the bluest sky. Her skin is creamy white. And "          "her BODY... well!! Embarrassed, you clear your throat and avert your "          "eyes.");    }  }return();[ Messages#message 1 "Bashfully, you introduce yourself to your long-lost sister. \"How can I be sure you're really my brother?\" Princess Rosella wonders. \"I know! My mother always said that Alexander had a cute birthmark on his bottom. Let me see if you have it.\" Embarrassed, you reveal your cute birthmark. \"Oh Alexander!\" she cries,\"You really ARE back! Mum and Dad will be SOOOOO happy!\""#message 2 "You ask Rosella about your parents. \"Mum and Dad were heart-broken when you disappeared as a baby,\" she explains. \"Dad searched EVERYWHERE for you. Obviously, he never found you.\" Pausing, she looks at you questioningly. \"By the way, where HAVE you been?\"  You explain that you have been living with an evil wizard in the land of Llewdor, and that you turned him into a cat by using magic. \"How awful for you!\" she exclaims. \"Well, I'm so glad you're back!!\""#message 3 "You ask Princess Rosella to tell you about Daventry. She replies, \"Hard times hit Daventry right after you were kidnapped. Dad and Mum tried, but it was like they had lost their will.\" Clenching her fist, Rosella continues. \"We were down on our guard, and the terrible dragon came. We all thought it was the end.\""#message 4 "\"I was scared, you know,\" your sister answers. \"But, I DID want to be brave. I was hoping my sacrifice might somehow help.\" She brightens a bit. \"Maybe, it did. Because of me, YOU came. Now, we're together again, and together we can put Daventry right!\""#message 5 "You comment upon the spoiled scenery of Daventry. Princess Rosella looks disgusted as she replies, \"The dragon did all that. He burnt our countryside, and we were all terrified to even come out of our houses. You don't remember, but it used to be very beautiful.\""#message 6 "You and Princess Rosella engage in idle pleasantries. You discover that your sister is not only beautiful, but very strong-willed and brave. You admire that in a woman."#message 7 "This is no time for magic. Take Princess Rosella home."#message 8 "She's already with you."#message 9 "What manner of monster are you?"#message 10 "You plant a brotherly kiss upon Princess Rosella's soft cheek."#message 11 "WATCH IT, FELLA!!"#message 12 "She can't hear you. She's too busy screaming!"#message 13 "\"Help me!! Untie me!!\" Princess Rosella screams."#message 14 "\"There's home!\" your sister cries in delight. \"Mum and Dad will be SOOOOOO happy!!\""#message 15 "You are not close enough to her."#message 16 "You rapidly untie Princess Rosella from the wooden pole. She looks bewildered as to who her benefactor may be. \"I'm your long-lost brother, Prince Alexander,\" you proudly exclaim. The girl looks doubtful."#message 17 "You've already untied her."#message 18 "\"I'll explain it all later,\" you continue, realizing that now is not the time for this. \"Just follow me. Let's go meet the folks!\" With mixed emotions, the girl agrees to follow you."#message 19 "Princess Rosella is gorgeous! Why, you'd be interested in her if she weren't your own sister! Her hair is long, silky, and golden. Her eyes are as blue as the bluest sky. Her skin is creamy white. And her BODY... well!! Embarrassed, you clear your throat and avert your eyes."#message 20 "The girl is securely tied to the stake."#message 21 "Not now!"