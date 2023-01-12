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
  vars.segmentStarted = false;
  vars.completedSegment = false;
}

startup
{
  settings.Add("begin-on-entering-mountain", true, "Begin timer when entering room 57");
	settings.Add("stop-time-on-exiting", true, "End timer when exiting the mountains by entering room 58");
}

update
{
}

start {
  if (settings["begin-on-entering-mountain"] && !vars.segmentStarted && current.currentRoom == 57 && current.previousRoom == 56) {
    vars.segmentStarted = true;
    return true;
  }
}

split
{
  if (settings["stop-time-on-exiting"] && !vars.completedSegment && current.currentRoom == 58)
  {
    vars.completedSegment = true;
    return true;
  }
}

// reset on bringing up the load dialog
reset {
  if (current.loadgameDialogShowing == 1) {
    vars.segmentStarted = false;
    vars.completedSegment = false;
    return true;
  }
}







