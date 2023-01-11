// [ Princess Rosella dynamic logic

#include   "rm119.msg"
#include  "gamedefs.reh"

if (init.log) {
    animate.obj(aPrincess);
    load.view(v.princess);

    load.sound(m.princess);

    if (!girlSaved) {
        load.view(v.princess.tied);
        load.view(v.princess.burned);
        position(aPrincess, 8, 108);
        set.view(aPrincess, v.princess.tied);
        work = 3;
        cycle.time(aPrincess, work);
    }
    else {
        set.view(aPrincess, v.princess);
        get.posn(ego, x, y);
        if ((ego.dir == 1 || ego.dir == 8 || ego.dir == 2)) {
            y += 1;
        }
        if ((ego.dir == 4 || ego.dir == 5 || ego.dir == 6)) {
            y -= 1;
        }
        position.f(aPrincess, x, y);
        follow.ego(aPrincess, 8, withEgo);
    }
    draw(aPrincess);
    return();
}

if (current.room == 69 && !beenIn69) {
    #message 14  "\"There's home!\" your sister cries in delight. \"Mum and Dad will be
SOOOOOO happy!!\"";
}

if (girlSaved && spell.cast) {                              // [ don't let magic work
    #message 7  "This is no time for magic. Take Princess Rosella home.";
    spell.cast = 0;
}

if (certain.death) {
    normal.motion(aPrincess);
    stop.motion(aPrincess);
    stop.cycling(aPrincess);
    return();
}

if (said(untie, girl)) {
    if (!girlSaved) {
        distance(ego, aPrincess, work);
        if (work > 16) {
            #message 15  "You are not close enough to her.";
        }
        else {
            score += 3;
            set(girlSaved);
            if (dragonDead) {
                #message 16  "You rapidly untie Princess Rosella from the wooden pole. She looks
bewildered as to who her benefactor may be.
\"I'm your long-lost brother, Prince Alexander,\" you proudly exclaim.
The girl looks doubtful.";
                #message 18  "\"I'll explain it all later,\" you continue, realizing that now is not the
time for this.
\"Just follow me. Let's go meet the folks!\" With mixed
emotions, the girl agrees to follow you.";
                stop.sound();
                sound(m.princess, sound.done);
                set.view(aPrincess, v.princess);
                work = 1;
                cycle.time(aPrincess, work);
                follow.ego(aPrincess, 6, withEgo);          // [ start following
            }
        }
    }
    else {
        #message 17  "You've already untied her.";
    }
}

distance(ego, aPrincess, work);
if (girlSaved && withEgo) {
    if (work > 12) {
        start.cycling(aPrincess);
        follow.ego(aPrincess, 6, withEgo);
    }
    else {
        stop.cycling(aPrincess);
    }
}

// [ doing things with rosella

#define MAXSAID   5                                         // [ messages 1-6 in order

if ((said(talk, with, girl) || said(talk, girl))) {
    if (!dragonDead) {
        #message 12  "She can't hear you. She's too busy screaming!";
    }
    else {
        if (!girlSaved) {
            #message 13  "\"Help me!! Untie me!!\" Princess Rosella screams.";
        }
        else {
            ++girlTalk;
            print.v(girlTalk);
            if (girlTalk > MAXSAID) {
                --girlTalk;
            }
        }
    }
}

if (said(get, girl)) {
    if (girlSaved) {
        #message 8  "She's already with you.";
    }
    else {
        #message 20  "The girl is securely tied to the stake.";
    }
}

if (said(kill, girl)) {
    #message 9  "What manner of monster are you?";
}

if (said(kiss, girl)) {
    if (girlSaved) {
        #message 10  "You plant a brotherly kiss upon Princess Rosella's soft cheek.";
    }
    else {
        #message 21  "Not now!";
    }
}

if (said(touch, girl)) {
    if (girlSaved) {
        #message 11  "WATCH IT, FELLA!!";
    }
    else {
        #message 21  "Not now!";
    }
}

if (said(look, girl)) {
    if (!girlSaved) {
        #message 20  "The girl is securely tied to the stake.";
    }
    else {
        #message 19  "Princess Rosella is gorgeous! Why, you'd be interested in her if she
weren't your own sister! Her hair is long, silky, and golden. Her eyes
are as blue as the bluest sky.Her skin is creamy white.And her BODY...
well!!Embarrassed, you clear your throatand avert your eyes.";
    }
}


