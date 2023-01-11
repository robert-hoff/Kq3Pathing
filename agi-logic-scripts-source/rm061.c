// [ rm61.cg
// [ outside the cave of the steps

#include  "gamedefs.reh"
#include  "rm61.msg"

#define  hitBottom    lf0
#define  egoFalling  lf1

#define  egoLoc    lv0
#define  toSteps  1
#define  toDeath  2
#define  isStunned  3

#define  stunTimer    lv1

if (init.log) {
    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    landing.x = 14;
    landing.y = 123;

    map.area = map.clouds;

    load.view(v.ego.stunned);
    load.view(v.ego.falling);
    load.view(v.ego);

    load.view.f(current.ego);
    set.view.f(ego, current.ego);

                                                            // [ sound stuff
    load.sound(s.ego.falling);
    load.sound(s.ego.stunned);

    if (positionEgo) {
        get.posn(ego, ego.x, ego.y);
        if (previous.room == 59) {
            position(ego, 103, 40);
        }
        if (previous.room == 62) {
            position(ego, 108, 79);
        }
        if (previous.room == 68) {
            ego.x = 2;
            position.f(ego, ego.x, ego.y);
        }
    }
    if (drawEgo) {
        draw(ego);
    }

    if (girlSaved) {
        load.logics(lgc.princess);
        call(lgc.princess);
    }

    show.pic();

                                                            // [ this is a new map area so we must clear the last areas beenIn flags
    if (!beenIn61) {
        set(beenIn61);
        work = firstIn61;                                   // [ start at end of range
        :clrFlags
            if (work > lastIn61) {                          // [ equal to this rooms beenIn flag
                reset.v(work);
                --work;
                goto clrFlags;
            }
    }

    return();
}

// [ falling in chasm
// [ egoFalling in the chasm
if (!handsOff && hit.special && !egoFalling) {
    set(handsOff);
    current.status = falling;
    sound(s.ego.falling, sound.done);
    set(egoFalling);
    ignore.blocks(ego);
    ignore.objs(ego);
    get.priority(ego, work);
    set.priority.f(ego, work);
    set.view(ego, v.ego.falling);
    if (posn(ego, 86, 32, 120, 71)) {                       // [ top screen
        egoLoc = toSteps;
        y = 94;
        x = 101;
        work = 3;
        set.priority(ego, 15);
    }
    else {
        egoLoc = toDeath;
        x = ego.x;
        y = 164;
        work = 4;
    }
    move.obj.f(ego, x, y, work, hitBottom);
}

if (hitBottom) {
    stop.sound();
    reset(hitBottom);
    reset(egoFalling);
    reset(handsOff);
    if (egoLoc == toDeath) {
        erase(ego);
        set(certain.death);
        #message 10  "You successfully fall for twenty meters before
you hit the bottom.You get a 4.1 from the Russian judge.";
    }
    else {
        #message 11  "Whoops, you slipped!";
        program.control();
        current.status = stunned;
        sound(s.ego.stunned, sound.done);
        stunTimer = ego.stunned.time;
        set.view(ego, v.ego.stunned);
        set(keep.cycling);
        set.scan.start();
        if (aSecondPassed) {
            --stunTimer;
        }
        if (!stunTimer) {
            reset(keep.cycling);
            player.control();
            set.view(ego, v.ego);
            observe.blocks(ego);
            observe.objs(ego);
            release.priority(ego);
            release.loop(ego);
            current.status = normal.ego;
            work = 1;
            cycle.time(ego, work);
            reset.scan.start();
        }
        if (stunTimer && sound.done) {
            sound(s.ego.stunned, sound.done);
        }
        return();
    }
}

// [ princess dynamic
if (girlSaved) {
    call(lgc.princess);
}

// [****** SAID STUFF ******]

if ((said(look, room) || said(look, mountain) || said(look))) {
    #message 1  "You look upward and view the mountain range you so arduously crossed.
Well, you made it to Daventry!But,
what is this ? It looks like a cave leading deep into the mountain.You
see evidence that a door once covered this cave entrance.Huge boulders
lie scattered about, apparently from tumbling down the mountain.";
}

if ((said(look$in, cave) || said(look, cave))) {
    #message 2  "You gaze into the cave-like entrance. You see nothing but crumbly stone
steps leading upward.";
}

if ((said(look$in, chasm) || said(look, chasm) || said(look, over, chasm))) {
    #message 3  "A deep chasm has split the earth on this side of the mountain.
You wonder if an earthquake had once struck Daventryand caused the
destruction you see before you.You see nothing of interest across it.";
}

if ((said(jump, over, chasm) ||
    said(climb, chasm) ||
    said(climb, down, chasm) ||
    said(jump, down, chasm) ||
    said(go, across, chasm) ||
    said(jump, chasm))) {
    #message 12  "The chasm is much too wide to jump across, and too treacherous to
climb.";
}

if ((said(look, plants) ||
    said(look, trees))) {
    #message 4  "A once green woodland spreads out before you. Now though, many trees
and bushes have been cruelly charred.";
}

if (said(look, ground)) {
    #message 5  "The ground is strewn with large boulders. A deep chasm cuts into it.";
}

if (said(look, sky)) {
    #message 6  "You see a mysterious cloud cover straight above you in the sky.";
}

if ((said(look, flowers) ||
    said(get, flowers))) {
    #message 7  "You see no flowers about.";
}

if (said(look, steps)) {
    #message 8  "The stone steps within the cave entrance look mighty crumbly.
Curiously, they lead straight up into the mountain!";
}

if (said(climb, tree)) {
    #message 9  "There are no climbable trees around.";
}

if ((said(jump, over, chasm) || said(climb, down) || said(jump, chasm))) {
    #message 12  "The chasm is much too wide to jump across, and too treacherous to
climb.";
}

// [ ****** PAINLESS ROOM EXITS ******

if (current.status == normal.ego && obj.in.box(ego, 118, 59, 133, 68)) {
    new.room(62);
}

if (edge.ego.hit == left) {
    new.room(68);
}


