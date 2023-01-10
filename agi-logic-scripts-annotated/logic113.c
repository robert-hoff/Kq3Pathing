if (isset(newRoom))
  {  load.view(View7);  load.view(View2);  load.view(View3);  }if ((isset(f46) ||     isset(f49)))
  {  return();  }if (!isset(onWater))
  {  reset(f35);  v138 = 0;  }else
  {  reset(f35);  if (v138 <= 0)
    {    v138 = 3;    }  }set.view.v(ego, v138);if (v138 == 0)
  {  v44 = 0;  }if ((v138 == 2 ||     v138 == 7))
  {  v44 = 224;  }if (v138 == 3)
  {  v44 = 11;  set(f35);  }if (v44 != 11 &&     said("dive"))
  {  print("The water looks inviting, but be careful if you go out there.");  }return();[ Messages#message 1 "The water looks inviting, but be careful if you go out there."