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
  byte loadgameDialogShowing: 0x1B58E20, 0xD99D;
  byte restartDialogShowing: 0x1B58E20, 0xD99F;
}

init
{
  refreshRate = 60;
  vars.prevPlayerXPos = 0;
  vars.prevPlayerYPos = 0;
  vars.gameScore = 0;
  vars.gotDaMap = false;
  vars.houseExit = false;
  vars.mountainComplete = false;
	vars.dogPet = false;
}


startup
{
  settings.Add("begin-on-reset", true, "Begin run");
  settings.Add("split-on-getting-map", true, "Split on picking up the map");
  settings.Add("split-on-starting-the-mountain", true, "Split on starting the mountain");
  settings.Add("split-on-finishing-mountain", true, "Split on finishing mountain");
  settings.Add("split-on-dog-pet", true, "Split on giving the dog a pet");
}

update
{
  if (current.restartDialogShowing == 1) {
    vars.prevPlayerXPos = current.playerXPos;
    vars.prevPlayerYPos = current.playerYPos;
  }
}

start {
  print(""+current.currentRoom);

  if (settings["begin-on-reset"] && current.currentRoom == 7
    && current.secondsPassed < 1 && current.minutesPassed == 0
    && vars.prevPlayerXPos == 96 && vars.prevPlayerYPos == 137) {
    vars.prevPlayerXPos = 0;
    vars.prevPlayerYPos = 0;
    vars.gotDaMap = false;
    vars.houseExit = false;
    vars.mountainComplete = false;
    vars.dogPet = false;
    return true;
  }
}

split
{
  if (settings["split-on-getting-map"] && !vars.gotDaMap && current.currentRoom == 2 && current.gameScore == 7)
  {
    vars.gotDaMap = true;
    return true;
  }
  if (settings["split-on-starting-the-mountain"] && !vars.houseExit && current.currentRoom ==33 && current.gameScore == 7)
  {
    vars.houseExit = true;
    return true;
  }
  if (settings["split-on-finishing-mountain"] && !vars.mountainComplete && current.currentRoom == 18 && current.playerYPos > 100)
  {
    vars.mountainComplete = true;
    return true;
  }
  if (settings["split-on-dog-pet"] && !vars.dogPet && current.currentRoom == 39 && current.gameScore == 8)
  {
    vars.dogPet = true;
    return true;
  }
}

// reset if hitting restart anywhere in the run
reset {
  if (current.restartDialogShowing == 1) {
    return true;
  }
}







