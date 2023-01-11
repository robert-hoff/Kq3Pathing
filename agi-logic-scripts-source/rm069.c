// [ rm69.cg
// [ The room with the generic gnome

#include  "gamedefs.reh"
#include  "rm69.msg"

#define  script  lv0
#define  nextStep  lf0

if (init.log) {

                                                            // [  set(beenIn69);        // [ deferred for a princess message
    map.area = map.daventry;
    set.horizon(45);

    landing.x = 50;
    landing.y = 100;

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);
    set.horizon(64);

    load.sound(m.gnome);
    set(sound.done);

    load.view(v.ego);

    load.view.f(current.ego);
    set.view.f(ego, current.ego);
    if (positionEgo) {
        if (previous.room == 71) {
            position(ego, 37, 78);
        }
    }
    if (drawEgo) {
        draw(ego);
    }

    if (girlSaved) {
        load.logics(lgc.princess);
        call(lgc.princess);
    }

                                                            // [ gnomish doings

    if (!gnomeGone) {
        animate.obj(aGnome);
        load.view(v.gnome);
        set.view(aGnome, v.gnome);
        ignore.objs(aGnome);
        ignore.blocks(aGnome);
        work = 3;
        cycle.time(aGnome, work);
        set.priority(aGnome, 10);
        set.loop(aGnome, 0);                                // [ rocking
        position(aGnome, 81, 104);
        draw(aGnome);
        if (girlSaved) {                                    // [ start him leaving the room
            start.motion(ego);
            set.cel(aGnome, 0);
            end.of.loop(aGnome, nextStep);                  // [ provide some delay
        }
    }

    show.pic();
    return();
}

// [ princess dynamic
if (girlSaved) {
    call(lgc.princess);
}

set(beenIn69);

// [ gnome script

if (nextStep && script == 0) {                              // [ get up and leave chair behind
    ++script;
    start.cycling(aGnome);
    set.loop(aGnome, 1);
    fix.loop(aGnome);
    reposition.to(aGnome, 77, 105);
    add.to.pic(v.gnome, 3, 0, 81, 104, 10, 0);              // [ the chair
    work = 1;
    cycle.time(aGnome, work);
    move.obj(aGnome, 40, 124, 1, nextStep);
}

if (nextStep && script == 1) {                              // [ walk to center of lane
    ++script;
    #message 19  "\"Oh YIPPEE! You did it, your majesty!! The gnome squeals in
delight. \"I KNEW you could save us all. King Graham and Queen Valanice
will be overjoyed to see you two.\" He claps his gnarled hands. \"I must
run ahead to announce your arrival!\" The gnome spryly scampers toward
the castle.";
    set.loop(aGnome, 2);
    fix.loop(aGnome);
    move.obj(aGnome, 34, 61, 1, nextStep);
}

if (nextStep && script == 2) {                              // [ walk out the top
    ++script;
    reset(nextStep);
    erase(aGnome);
    set(gnomeGone);
}

// [ erase my gnome and set gnomeGone

if (!gnomeGone && sound.done) {
    sound(m.gnome, sound.done);
}

// [******** SAID STUFF ********]

if ((said(look) || said(look, room) || said(look, house))) {
    if (gnomeGone) {
        #message 2  "You stare at the run-down shack. It leans heavily to one side.
You wonder why it doesn't fall.";
    }
    else {
        #message 1  "You stare at the run-down shack. Upon the porch, a withered gnome rocks
in a creaky old rocking chair, whistling a merry tune.The shack
leans heavily to one sideand you wonder why it doesn't fall.";
    }
}

if ((said(look, fence) ||
    said(look, over, fence) ||
    said(climb, fence) ||
    said(jump, fence) ||
    said(jump, over, fence) ||
    said(climb, over, fence))) {
    if (ego.x < 80) {
        #message 3  "A stone wall travels to the north and south. You try to go over
it, but find it too high.There is nothing of any interest on the
other side of it, anyway.";
    }
    else {
        #message 4  "The ramshackle wooden fence runs to the north and south. You try to go over
it, but find it too high.There is nothing of any interest on the
other side of it, anyway.";
    }
}

if ((said(look, window) || said(look$in, window))) {
    #message 6  "You can't see anything through the window.";
}

if ((said(look, door) || said(look$in, door) || said(open, door))) {
    #message 7  "The door is locked. The gnome is wary of thieves.";
}

if (said(look, castle)) {
    #message 8  "In the distance, you notice a castle. Your excitement
mounts as you realize it is your home.Your parents,
King Grahamand Queen Valanice, whom you do not remember, reside there.";
}
if ((said(look, porch) || said(look, man, porch))) {
    if (gnomeGone) {
        #message 9  "There is nothing on the porch but the rocking chair (which isn't rocking).";
    }
    else {
        #message 10  "A wizened old gnome rocks in a creaky rocking chair on the front porch
of his rickety shack.He whistles a merry tune.";
    }
}
if (said(look, man)) {
    if (gnomeGone) {
        #message 11  "The last time you saw him he was headed north.";
    }
    else {
        #message 12  "This gnome looks to be at least a hundred years old. He's stooped with
age, and his face is as withered as an old prune.Grey, wispy hair
tops his head, and gnarled hands clutch the chair.As old as he
looks, however, his twinkling eyes suggest a youthful
mischievousness as he whistles a merry tune.";
    }
}

if (said(talk, man)) {
    if (gnomeGone) {
        #message 13  "You'll have to talk extra loud because he's not here.";
    }
    else {
        ++gnomeTalk;
        if (gnomeTalk == 1) {
            #message 14  "You speak directly to the old gnome. He chuckles softly to
himself, then replies, \"It's about time you got here, lad... I mean,
Prince Alexander.Welcome home!Heaven knows, we need you.Daventry's
been suffering for years now, since that despicable dragon came.\"";
            #message 15  "The old gnome narrows his eyes to slits and leans forward in his chair.
\"That monster demanded the sacrifice of your poor sister, Princess
Rosella, and I'm afraid time is running out. Your parents, the
King and Queen, are suffering such grief they have locked themselves in
yon castleand refuse to see anyone.\"";
            #message 16  "Staring intently at you, the gnome goes on, \"It's up to you, Alexander.
Your country and family need you.It's written in the wind.\" The
wizened gnome relaxes and settles back in his chair.He begins
whistling again.";
        }
        if (gnomeTalk == 2) {
            #message 17  "\"You must hurry, Prince Alexander,\" the old gnome urges. \"Time is
a - wasting.Go save us.\"";
        }
        if (gnomeTalk == 3) {
            #message 18  "The gnome now chooses to ignore you. He whistles and rocks in his
creaky chair.";
            --gnomeTalk;
        }
    }
}

if ((said(climb, up, tree) || said(climb, tree))) {
    #message 20  "There are no climbable trees around.";
}

if ((said(look, plant) || said(look, tree))) {
    #message 21  "Some plants and trees around Daventry have been burnt black and
leafless.";
}

if ((said(look, flower) || said(get, flower))) {
    #message 22  "Wildflowers no longer grow here.";
}

if (said(look, ground)) {
    #message 23  "There is nothing interesting on the ground but grass.";
}

if (said(look, sky)) {
    #message 24  "The sky is blue and the sun is shining, yet a feeling of sadness
lingers here.";
}

if (said(get, gnome)) {
    if (gnomeGone) {
        #message 11  "The last time you saw him he was headed north.";
    }
    else {
        #message 25  "He belongs to himself.";
    }
}

// [ ****** PAINLESS ROOM EXITS ******

if (edge.ego.hit == top) {
    new.room(71);
}

if (edge.ego.hit == 3) {
    new.room(68);
}


