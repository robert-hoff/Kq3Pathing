// [ rm 116 - Logic of landHo for the pirates

// [ This rooms sole function is to detect a change of state that...

#include  "gamedefs.reh"
#include  "rm116.msg"

if (landHo) {
    reset(landHo);
    if (shipShape == nearLand) {
        #message 1  "You hear one of the pirates shout, \"Land ho, Captain!\"";
    }
    if (shipShape == atBeach) {
        #message 2  "You hear the first mate shout, \"Drop anchor,
an' prepare ta go ashore!\"";
    }
}

if (aSecondPassed && shipShape == departed) {
    #message 3  "You hear the sounds of the ship setting sail. With a grim sense
of foreboding, you realize that you are doomed to the life of a
cabin boy.";
    stop.cycling(ego);
    set(certain.death);
}

