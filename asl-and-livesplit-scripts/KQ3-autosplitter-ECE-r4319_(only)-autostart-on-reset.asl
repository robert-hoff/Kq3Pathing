// only works on ECE r4319

state("dosbox", "ECE r4319")
{
  // starting position and room is (96,137)7
  byte currentRoom: 0x1B58E20, 0xC789;
  byte gameScore: 0x1B58E20, 0xC78C;
  byte secondsPassed: 0x1B58E20, 0xC7FC;
  byte minutesPassed: 0x1B58E20, 0xC7FD;
  byte playerXPos: 0x1B58E20, 0xC7B1;
  byte playerYPos: 0x1B58E20, 0xC7B2;
  byte spellFlags1: 0x1B58E20, 0xC89B;
  byte spellFlags2: 0x1B58E20, 0xC89C;
  byte restartDialogShowing: 0x1B58E20, 0xD99F;

}

init
{
  refreshRate = 60;
  vars.prevPlayerXPos = 0;
  vars.prevPlayerYPos = 0;
  vars.gameScore = 0;
  vars.eagleSpell = false;
  vars.allWarez = false;
  vars.madeAllSpells = false;
	vars.tookCareOfWizard = false;
  vars.reachedIsland = false;
  vars.completedGame = false;
}

startup
{
  settings.Add("begin-on-reset", true, "Begin run");
  settings.Add("split-on-eagle-spell", true, "Split on making eagle/fly apell");
  settings.Add("split-on-collecting-all-things-for-spells", true, "Split on getting things for making spells");
  settings.Add("split-making-all-spells", true, "Split on making all the spells");
  settings.Add("split-on-wizard-death", true, "Split on turning wizard into a cat");
  settings.Add("split-on-reaching-island", true, "Split on reaching island");
	settings.Add("split-on-game-complete", true, "Split on finishing game");
}

update
{
  if (current.restartDialogShowing == 1) {
    vars.prevPlayerXPos = current.playerXPos;
    vars.prevPlayerYPos = current.playerYPos;
  }
}

// it's best to check the player position as well
// this allows for hitting F9 to get back to start screen and then to prepare whatever
// string one wants to F3. As well as checking speed setting (which needs to be above Fast)
start {
  if (settings["begin-on-reset"] && current.currentRoom == 7
    && current.secondsPassed < 1 && current.minutesPassed == 0
    && vars.prevPlayerXPos == 96 && vars.prevPlayerYPos == 137) {
    vars.prevPlayerXPos = 0;
    vars.prevPlayerYPos = 0;
    vars.eagleSpell = false;
    vars.allWarez = false;
    vars.tookCareOfWizard = false;
    vars.reachedIsland = false;
    vars.completedGame = false;
    return true;
  }
}

split
{
  if (settings["split-on-eagle-spell"] && !vars.eagleSpell && current.gameScore == 50)
  {
    vars.eagleSpell = true;
    return true;
  }
  if (settings["split-on-collecting-all-things-for-spells"] && !vars.allWarez && current.gameScore == 100)
	{
    vars.allWarez = true;
		return true;
	}
  if (settings["split-making-all-spells"] && !vars.madeAllSpells && current.gameScore == 160)
	{
    vars.madeAllSpells = true;
		return true;
	}
  if (settings["split-on-wizard-death"] && !vars.tookCareOfWizard && current.gameScore == 172)
	{
    vars.tookCareOfWizard = true;
		return true;
	}
  if (settings["split-on-reaching-island"] && !vars.reachedIsland && current.gameScore == 185)
	{
    vars.reachedIsland = true;
		return true;
	}
  if (settings["split-on-game-complete"] && !vars.completedGame && current.gameScore == 210)
	{
    vars.completedGame = true;
		return true;
	}
}

// reset if hitting restart anywhere in the run
reset {
  if (current.restartDialogShowing == 1) {
    return true;
  }
}




