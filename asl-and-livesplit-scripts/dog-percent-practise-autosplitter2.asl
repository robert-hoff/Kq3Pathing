// Splitter for Dosbox ECE r4319

state("dosbox", "ECE r4319")
{
  byte currentRoom: 0x1B58E20, 0xC789;
  byte previousRoom: 0x1B58E20, 0xC78A;
  byte gameScore: 0x1B58E20, 0xC78C;
  byte secondsPassed: 0x1B58E20, 0xC7FC;
  byte minutesPassed: 0x1B58E20, 0xC7FD;
  byte playerXPos: 0x1B58E20, 0xC7B1;
  byte playerYPos: 0x1B58E20, 0xC7B2;
  byte spellFlags1: 0x1B58E20, 0xC89B;
  byte spellFlags2: 0x1B58E20, 0xC89C;
  byte reloadDialogShowing: 0x1B58E20, 0xD99D;
  byte restartDialogShowing: 0x1B58E20, 0xD99F;
}

init
{
  refreshRate = 60;
  vars.arrivedAtMap = false;
}

startup
{
  settings.Add("startonfirstmove", true, "Start the timer on arriving at first waypoint in starting room");
  settings.Add("split-on-map-arrive", true, "Split on horizontal mountain walk");
}

// This gets called when hitting the GAME reset (F9) or load (F7) (from anywhere in the run)
reset {
  if (current.restartDialogShowing == 1 || current.reloadDialogShowing == 1) {
    return true;
  }
}


// After reset when this condition is met the timer will start
start
{
  if (settings["startonfirstmove"] && current.currentRoom == 33) {
    vars.arrivedAtMap = false;
    return true;
  }
}

split
{
  if (settings["split-on-map-arrive"] && !vars.arrivedAtMap && current.currentRoom == 33 && current.playerXPos == 99 && current.playerYPos == 89)
	{
    vars.arrivedAtMap = true;
		return true;
	}

}


update
{
  // print(""+current.currentRoom);
  // print(""+current.playerXPos);
  // print(""+current.playerYPos);

}








