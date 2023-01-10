set.cursor.char("_");set.string(inputPrompt, "]");set.game.id("KQ3");trace.info(Logic96, 1, 6);set.text.attribute(WHITE, BLACK);maxScore = 210;if (monitorType != MONO)
{  clear.lines(22, 24, BLACK);}configure.screen(1, 23, 0);set(enableMenu);disable.item(c29);set(soundOn);set(f126);v61 = 1;v60 = 1;v59 = 1;v141 = 1;v142 = 2;v143 = 3;v144 = 4;v145 = 5;if (v70 <= 0)
{  if (!isset(gameRestarted))
  {    set(f42);    program.control();    prevent.input();    animationInterval = 2;    reset(f126);    reset(enableMenu);    status.line.off();  }  else
  {    enable.item(c3);    set(f42);    status.line.on();    return();  }}set.key(0, 59, c2);set.key(0, 60, c16);set.key(0, 61, c9);set.key(0, 62, c26);set.key(0, 63, c3);set.key(0, 64, c24);set.key(0, 65, c5);set.key(0, 66, c23);set.key(0, 67, c7);set.key(0, 68, c4);if (machineType == TANDY)
{  set.key(43, 0, c38);  set.key(61, 0, c38);  set.key(45, 0, c39);}set.key(9, 0, c10);if (machineType == AMIGA)
{  set.key(27, 0, c18);}else
{  set.key(27, 0, c35);}set.key(3, 0, c17);set.key(5, 0, c9);set.key(10, 0, c15);set.key(18, 0, c12);set.key(19, 0, c16);set.key(0, 50, c13);set.key(0, 47, c20);set.key(0, 44, c1);if (machineType == PCJR)
{  set.key(49, 0, c2);  set.key(50, 0, c16);  set.key(51, 0, c9);  set.key(53, 0, c3);  set.key(54, 0, c24);  set.key(55, 0, c5);  set.key(56, 0, c23);  set.key(57, 0, c7);  set.key(48, 0, c4);}if (machineType == ATARI)
{  set.key(1, 1, c35);  set.key(1, 3, c10);  set(enableDblClick);  dblClickDelay = 3;}else
{  set.key(1, 1, c35);  set.key(1, 2, c10);}return();[Messages#message 1 "_"#message 2 "]"#message 3 "KQ3"
