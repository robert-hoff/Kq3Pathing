if (isset(newRoom))
{
  if (!isset(f111))
  {
    load.view(View240);
    load.view(View241);
    load.view(View14);
    load.sound(Sound10);
    load.sound(Sound26);
    animate.obj(o3);
    set.view(o3, View240);
    v36 = 2;
    step.size(o3, v36);
    v240 = 5;
    random(70, 160, v241);
    position.v(o3, v240, v241);
    set.loop(o3, 0);
    random(3, 6, v244);
  }
  if (isset(f111) &&
    v97 == currentRoom)
  {
    v67 = 241;
    load.view.v(v67);
    v64 = 0;
    v65 = 8;
    v37 = v98;
    v38 = v99;
    v66 = 0;
    v36 = 0;
    add.to.pic.v(v67, v64, v65, v37, v38, v66, v36);
  }
  return ();
}
if (!isset(f111) && isset(f242))
{
  if (isset(haveInput))
  {
    if (has("Mirror*") &&
      (said("try", "looking glass") ||
        said("carry", "looking glass") ||
        said("aim", "looking glass") ||
        said("examine", "barmaid", "looking glass") ||
        said("aim", "barmaid", "looking glass") ||
        said("examine", "looking glass", "barmaid") ||
        said("aim", "looking glass", "barmaid") ||
        said("try", "fingers", "looking glass") ||
        said("carry", "fingers", "looking glass") ||
        said("aim", "fingers", "looking glass") ||
        said("examine", "barmaid", "fingers", "looking glass") ||
        said("aim", "barmaid", "fingers", "looking glass") ||
        said("examine", "fingers", "looking glass", "barmaid") ||
        said("aim", "fingers", "looking glass", "barmaid")))
    {
      distance(ego, o3, v36);
      if (v36 > 50)
      {
        print("You are too far away for her to see it.");
      }
      else
      {
        set(f111);
        currentScore += 5;
        normal.motion(o3);
        stop.motion(o3);
        get.posn(o3, v98, v99);
        v97 = currentRoom;
        set.view(o3, View241);
        set.cel(o3, 0);
        v36 = 4;
        cycle.time(o3, v36);
        end.of.loop(o3, f243);
        sound(Sound10, f41);
      }
    }
    if (said("kill", "barmaid"))
    {
      print("Good idea! But, how can you do that?");
    }
    if (said("call", "barmaid"))
    {
      print("Apparently, Medusa doesn't speak. The only sounds that emit from "

        "her mouth are terrible grunts and groans.");
    }
    if (said("examine", "barmaid"))
    {
      set(f240);
      set(f245);
    }
  }
}
if (!isset(f242) &&
  !isset(f111))
{
  if (isset(f45))
  {
    --v244;
    if (v244 == 1)
    {
      print("The most hideous-looking being has made its appearance! It's "
        "Medusa!");
      draw(o3);
      set(f242);
      sound(Sound26, f41);
      follow.ego(o3, 6, f240);
    }
  }
}
if (isset(f242) &&
  !isset(f111))
{
  distance(ego, o3, v242);
  if (v44 == 0 &&
    !isset(f111))
  {
    get.posn(o3, v240, v241);
    v37 = v240;
    v38 = v241;
    v37 -= v40;
    v38 -= v41;
    if (v37 > 128)
    {
      v36 = 0;
      v36 -= v37;
      v37 = v36;
    }
    if (v38 > 128)
    {
      v36 = 0;
      v36 -= v38;
      v38 = v36;
    }
    current.loop(ego, v64);
    if (v64 == 2 &&
      v241 > v41 &&
      v38 > v37)
    {
      set(f240);
    }
    if (v64 == 0 &&
      v240 > v40 &&
      v38 < v37)
    {
      set(f240);
    }
    if (v64 == 1 &&
      v240 < v40 &&
      v38 < v37)
    {
      set(f240);
    }
    if (v64 == 3 &&
      v241 < v41 &&
      v38 > v37)
    {
      set(f240);
    }
  }
}
if (isset(f111) &&
  v97 == currentRoom)
{
  if (said("kill", "barmaid"))
  {
    print("Medusa is now just a stone statue, perfectly harmless.");
  }
  if (said("capture", "barmaid"))
  {
    print("The statue is much too heavy to carry.");
  }
  if (said("examine", "barmaid"))
  {
    print("Even as a statue, Medusa is indescribably ugly.");
  }
}
if (isset(f240) &&
  !isset(f111))
{
  reset(f240);
  if (v44 != 0)
  {
    set(f244);
    wander(o3);
  }
  else
  {
    set(f46);
    program.control();
    prevent.input();
    stop.motion(ego);
    wander(o3);
    set(f35);
    set.view(ego, View14);
    v36 = 4;
    cycle.time(ego, v36);
    end.of.loop(ego, f241);
    v44 = 17;
    sound(Sound10, f41);
    if ((v242 > 15 ||
      isset(f245)))
    {
      print("Your eyes fall upon a face so hideous, so gruesome, that the "
        "horror of it is beyond description. People who look upon the face "
        "of Medusa, with her hair of writhing, live snakes, turn instantly "
        "to stone. Suddenly, your body feels cold and stiffens hard as a "
        "rock. You make a nice statue, Gwydion.");
    }
    else
    {
      print("Oh no! Medusa's touch is like ice! A cold chill shivers down your "
        "spine, turning to a stiffness that soon hardens your body like a "
        "rock. You are now nothing but a statue.");
    }
  }
}
if (edgeObjHit > NOT_HIT &&
  objHitEdge == 3 &&
  (v44 == 17 ||
    isset(f244)))
{
  erase(o3);
  reset(f242);
}
if (isset(f241))
{
  reset(f241);
  reset(f35);
  set(f44);
  stop.cycling(ego);
  erase(o3);
  reset(f242);
}
if (isset(f243))
{
  reset(f243);
  stop.cycling(o3);
  print("Averting your eyes, you aim the wizard's hand mirror at Medusa's face. "
    "A scream pierces the air as she beholds her own hideous reflection... "
    "then... nothing. You dare to look. Medusa has turned herself to stone!");
}

if (v44 == 18 || v44 == 17)
{
  edgeEgoHit = NOT_HIT;
}
return ();


[Messages
#message 1 ""
#message 2 "You are too far away for her to see it."
#message 3 ""
#message 4 "Medusa is now just a stone statue, perfectly harmless."
#message 5 "Good idea! But, how can you do that?"
#message 6 ""
#message 7 ""
#message 8 "Apparently, Medusa doesn't speak. The only sounds that emit from her mouth are terrible grunts and groans."
#message 9 "The statue is much too heavy to carry."
#message 10 "Averting your eyes, you aim the wizard's hand mirror at Medusa's face. A scream pierces the air as she beholds her own hideous reflection... then... nothing. You dare to look. Medusa has turned herself to stone!"
#message 11 "Even as a statue, Medusa is indescribably ugly."
#message 12 "You need to move closer."
#message 15 "The most hideous-looking being has made its appearance! It's Medusa!"
#message 16 "Your eyes fall upon a face so hideous, so gruesome, that the horror of it is beyond description. People who look upon the face of Medusa, with her hair of writhing, live snakes, turn instantly to stone. Suddenly, your body feels cold and stiffens hard as a rock. You make a nice statue, Gwydion."
#message 17 "Oh no! Medusa's touch is like ice! A cold chill shivers down your spine, turning to a stiffness that soon hardens your body like a rock. You are now nothing but a statue."




