// [logics for room -- 40:inside tavern

#include "gamedefs.reh"
#include "rm40.msg"

#define  inPort.init.minutes    15
#define  allAboard        5

#define  near.table      1
#define  near.bar        2

#define  drunk.time      50
#define  pirate.msg.start    28
#define  pirate.msg.end      31

#define  customers        lv1
#define  none      0
#define  pirates    1
#define  bandits    2

#define  msg.count        lv2
#define  old.gold        lv3
#define  msg          lv4

#define  script        lv5
#define  behind.bar  0
#define  to.stove    1
#define  to.table    2
#define  at.table    3
#define  back.to.stove  4
#define  back.to.bar  5
#define  back.at.bar  6

#define  script.timer      lv6
#define  sober.up        lv7
#define  drunk.timer      lv8
#define  how.drunk.to.get    lv9
#define  fly.timer        lv10                              // [ provides delay to hear bandits

#define  money.to.burn      lf0                             // [ has money with him
#define  heard.bandits      lf1
#define  talking.to.pirates    lf2
#define  serve.bar        lf3
#define  captain.pissed      lf4
#define  next          lf5
#define  talked.bandits      lf6
#define  staggering      lf7
#define  free.booze      lf8

% object  a.pirate.1      1
% object  a.bandit.1      1                                 // [ XOR in room
% object  a.pirate.2      2
% object  a.bandit.2      2                                 // [ XOR in room
% object  a.captain        3
% object  a.bartender      4

if (init.log) {
    wiz.x = 89;
    wiz.y = 154;

    landing.x = 91;
    landing.y = 153;

    set(interiorRoom);

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    load.view(v.ego);
    load.view.f(current.ego);
    set.view.f(ego, current.ego);
    if ((positionEgo || current.status == fly)) {
        position(ego, 72, 165);
    }

    if (current.status == fly) {
        fly.timer = 7;
    }

    block(59, 128, 62, 131);                                // [ who knows what this is blocking

                                                            // [ the bartender is a broad
    animate.obj(a.bartender);
    load.view(v.bartender);
    set.view(a.bartender, v.bartender);
    position(a.bartender, 78, 121);
    draw(a.bartender);
    stop.cycling(a.bartender);
    set.loop(a.bartender, facing.front);

    how.drunk.to.get = 5;                                   // [ increases geometricaly with each drink

                                                            // [ select some patrons   (customers)

    if (shipShape == inPort) {                              // [ pirates are highest priority
        customers = pirates;
        load.view(v.pirate.drinking);                       // [ all pirates are loops in this view

                                                            // [ captain
        animate.obj(a.captain);
        set.view(a.captain, v.pirate.drinking);
        position(a.captain, 58, 149);
        set.loop(a.captain, 2);
        set.cel(a.captain, 3);
        stop.cycling(a.captain);
        draw(a.captain);

                                                            // [ first mate
        animate.obj(a.pirate.1);
        set.view(a.pirate.1, v.pirate.drinking);
        position(a.pirate.1, 43, 154);
        set.loop(a.pirate.1, 0);
        set.cel(a.pirate.1, 0);
        stop.cycling(a.pirate.1);
        draw(a.pirate.1);

                                                            // [ check mate
        animate.obj(a.pirate.2);
        set.view(a.pirate.2, v.pirate.drinking);
        position(a.pirate.2, 52, 152);
        set.loop(a.pirate.2, 1);
        set.cel(a.pirate.2, 2);
        stop.cycling(a.pirate.2);
        draw(a.pirate.2);
    }
    else {
        random(1, 3, work);
        if (work < 2) {                                     // [ bandits are in town
            customers = none;
        }
        else {
            customers = bandits;
            load.view(v.bandits.drinking);                  // [ both bandits look like podlings

                                                            // [ a bandit
            animate.obj(a.bandit.1);
            set.view(a.bandit.1, v.bandits.drinking);
            position(a.bandit.1, 41, 143);
            set.loop(a.bandit.1, 1);
            set.cel(a.bandit.1, 0);
            set.priority(a.bandit.1, 13);
            stop.cycling(a.bandit.1);
            ignore.objs(a.bandit.1);
            draw(a.bandit.1);

                                                            // [ a misunderstood kind of guy
            animate.obj(a.bandit.2);
            set.view(a.bandit.2, v.bandits.drinking);
            position(a.bandit.2, 52, 152);
            set.loop(a.bandit.2, 0);
            set.cel(a.bandit.2, 0);
            set.priority(a.bandit.2, 14);
            stop.cycling(a.bandit.2);
            draw(a.bandit.2);
        }
    }

    if (drawEgo) {
        draw(ego);
    }

    script = to.stove;
    if (customers != none) {                                // [ order some drinks
        random(3, 7, script.timer);
    }
                                                            // [ pick some sounds
    if (customers == pirates) {
        load.sound(m.pirate);
        sound(m.pirate, sound.done);
    }
    if (customers == bandits) {
        load.sound(m.badguy);
        sound(m.badguy, sound.done);
    }
    if (customers == none) {
        load.sound(m.tavern);
        sound(m.tavern, sound.done);
    }

    show.pic();
    return();

}

// [ keep ship in port
if (shipShape == inPort && !voyage.minutes
    && voyage.seconds < 30 && voyage.seconds > 0) {
    voyage.seconds = 30;
}

ego.location = nowhere;
if (posn(ego, 40, 134, 73, 162))
{
    ego.location = near.table;
}

if (posn(ego, 56, 124, 114, 133))
{
    ego.location = near.bar;
}

// [ bartender script area.  Runs on next flag

if (aSecondPassed && script.timer) {
    if (!handsOff) {
        --script.timer;
    }
    if (script.timer == 0) {
        set(next);
    }
}

if (next && script == behind.bar) {                         // [ this is where we wait to serve
    ++script;
    stop.cycling(a.bartender);
    set.loop(a.bartender, facing.front);
    reset(next);
}

if (next && script == to.stove) {                           // [ go to stove
    if (!free.booze) {                                      // [ ego is NOT buying
        if (customers == pirates) {
            #message 1  "One of the rowdy seamen yells to the barmaid,
\"Wench! Come o'er here with more rum!\"";
        }
        else {
            #message 50  "One of the surly-looking characters yells to the barmaid,
\"Wench! Come o'er here with more ale!\"";
        }
    }
    reset(free.booze);
    ++script;
    start.cycling(a.bartender);
    move.obj(a.bartender, 49, 125, 1, next);
}

if (next && script == to.table) {
    ++script;
    start.cycling(a.bartender);
    move.obj(a.bartender, 49, 140, 1, next);
}

if (next && script == at.table) {                           // [ timed wait at table
    ++script;
    stop.cycling(a.bartender);
    reset(next);
    script.timer = 3;
}

if (next && script == back.to.stove) {
    ++script;
    start.cycling(a.bartender);
    move.obj(a.bartender, 49, 125, 1, next);
}

if (next && script == back.to.bar) {
    ++script;
    start.cycling(a.bartender);
    move.obj(a.bartender, 77, 125, 1, next);
}

if (next && script == back.at.bar) {                        // [ all done, set up for next
    script = behind.bar;                                    // [ goes to start next
    stop.cycling(a.bartender);
    move.obj(a.bartender, 77, 121, 1, next);
    random(30, 120, script.timer);
}

// [*****
// [ make customers drink
// [*****

random(1, 20, work);
if (customers == pirates) {
    if (work == 1) {
        last.cel(a.captain, x);
        current.cel(a.captain, y);
        ++y;
        if (y > x) {
            y = 0;
        }
        if (talking.to.pirates) {
            y = 0;
        }
        set.cel.f(a.captain, y);
    }

    if (work == 2) {
        last.cel(a.pirate.1, x);
        current.cel(a.pirate.1, y);
        ++y;
        if (y > x) {
            y = 0;
        }
        set.cel.f(a.pirate.1, y);
    }

    if (work == 3) {
        last.cel(a.pirate.2, x);
        current.cel(a.pirate.2, y);
        ++y;
        if (y > x) {
            y = 0;
        }
        set.cel.f(a.pirate.2, y);
    }
}

if (customers == bandits) {
    if (work == 1) {
        last.cel(a.bandit.1, x);
        current.cel(a.bandit.1, y);
        ++y;
        if (y > x) {
            y = 0;
        }
        set.cel.f(a.bandit.1, y);
    }

    if (work == 2) {
        last.cel(a.bandit.2, x);
        current.cel(a.bandit.2, y);
        ++y;
        if (y > x) {
            y = 0;
        }
        set.cel.f(a.bandit.2, y);
    }
}

// [ don't let him sit down if customers are here
if (customers != none && posn(ego, 33, 138, 70, 154) &&
    (current.status == normal.ego || current.status == drunk)) {  // [table
    start.motion(ego);
    reposition.to.f(ego, old.ego.x, old.ego.y);
}

if (aSecondPassed && sober.up) {
    --sober.up;
    if (sober.up == 0) {
        reset(staggering);
        player.control();
        release.loop(ego);
        current.status = normal.ego;
    }
}

// [ Scott Murphy's drinking problem

if (current.status == drunk && ego.dir != 0) {
    --drunk.timer
        if (drunk.timer == 1) {
            if (staggering) {
                reset(staggering);
                player.control();
                release.loop(ego);
                drunk.timer = 6;
            }
            else {
                set(staggering);
                program.control();
                fix.loop(ego);
                :zz
                    random(1, 8, work);
                if (work == ego.dir) {
                    goto zz;
                }
                ego.dir = work;
                drunk.timer = 5;
            }
        }
}

if (ego.poofing.done && current.status == fly) {
    fly.timer = 7;
}

if (aSecondPassed) {
    --fly.timer;
    if (fly.timer == 1 && current.status == fly &&
        posn(ego, 0, 0, 160, 160)
        && customers == bandits && !heard.bandits) {
        #message 11  "You overhear snatches of the two bandits' conversation,
\"...squirmed jist like a pig. An' that rope ya rigged inside o' that
big oak tree works great!Now nobody'll 'ere find ar' hideout. Why,
I'll bet even that wizard...\"";
        set(heard.bandits);
        score += 3;
    }
}

if (talking.to.pirates && !captain.pissed) {
    --timer.2;
    if (timer.2 == 0) {
        print.f(msg.count);
        ++msg.count;
        timer.2 = 200;
        if (msg.count == pirate.msg.end) {
            set(captain.pissed);
        }
    }
}

// [*****
// [accounting dept
// [*****

if (old.gold != gold.coin.count)
{
    old.gold = gold.coin.count;
    if (gold.coin.count == 0)
    {
        if (has(i.purse.with.coins))
        {
            drop(i.purse.with.coins);
        }
        get(i.purse.empty);
    }
}

// [ does he have money on him?
if (has(i.purse.with.coins) && gold.coin.count > 0) {
    set(money.to.burn);
}
else {
    reset(money.to.burn);
}

// [*****
// [handle.input
// [*****

if (have.input) {                                           // [ /* a real time saver */

    if ((said(sit, table) || said(sit, down, table))) {
        if (customers == none) {
            #message 44  "You don't have time to be sitting around in taverns.";
        }
        else {
            #message 45  "Your presence would not be appreciated.";
        }
    }

    work = customers;
    if ((said(look) || said(look, room) || said(look, tavern) ||
        said(look$in, bar)))
    {
        addn(work, 3);                                      // [msgs 2 + 3, 4, 5
        print.f(work);
    }

    if ((said(look, kegs) || said(look$in, kegs))) {
        #message 46  "Kegs of ale line the wall.";
    }

    if (said(look, table)) {
        if (customers == none) {
            #message 49  "A table, devoid of customers, rests against the wall.";
        }
        else {
            addn(work, 7);                                  // [msgs  7, 8, 9
            print.f(work);
        }
    }

    if ((said(look, customers) ||
        said(look, men)))                                   // [syn. to bandit & sailor
    {
        addn(work, 7);                                      // [msgs  7, 8, 9
        print.f(work);
    }

    if (said(look, barmaid)) { #message 10  "The buxom barmaid has an air of hardened determination. You get the feeling
that she doesn't take any guff from anybody."; }

    if ((said(look, out, window) || said(look, window) ||
        said(look, door) ||
        said(look, outside))) {
        #message 12  "You see the buildings of the village, and the ocean beyond.";
    }

    if (said(open, window)) {
        #message 53  "The window does not open.";
    }

    if ((said(get, men) || said(touch, stove) ||
        said(get, stove) ||
        said(kill, anyword))) {
        #message 13  "Surely, you jest!";
    }

    if (said(look, stove)) { #message 14  "It is a little pot-bellied woodstove."; }

    if (said(look, bar)) { #message 15  "The bar is a rough-hewn slab of oak."; }

    if ((said(look, swords) ||
        said(look, tapestry) ||
        said(look, wall))) {
        #message 16  "A tattered, faded tapestry hangs next to a pair of rusty swords.";
    }

    if ((said(get, swords) ||
        said(get, tapestry))) {
        #message 17  "The decorations are firmly attached to the wall, and will not come off.";
    }

    if (said(look, under, tapestry)) {
        #message 18  "You lift a corner of the tapestry, and see the dirty wall behind it.";
    }

    if (said(get, beer)) {
        #message 47  "You need to buy it first.";
    }

    if ((said(look, shelf) || said(look, bottle))) {
        #message 2  "Bottles of rum and wine sit atop shelves behind the bar.";
    }

    if (said(look, beer)) {
        #message 54  "Bottles of rum and wine sit atop shelves behind the bar.
Kegs of ale line the wall.";
    }

    if ((said(get, girl) || said(kiss, girl))) {
        #message 48  "\"Watch it, fella!\"";
    }

    if (customers == none) {
        if ((said(talk) ||
            said(talk, barmaid))) {
            #message 19  "She tosses her head, and replies, \"What'll it be fer ya, sir?
A good pull o'
ale, or 'd ya rather a dram o' rum ? My, aren't ye the han'some one!\"";
        }

        if ((said(talk, men) ||
            said(look, men))) {
            #message 23  "There is nobody here except the pretty barmaid.";
        }                                                   // [m none
    }

                                                            // [ buying a round
    if ((said(order, drinks) || said(order, drinks, men))) {
        if (customers == none) {
            #message 7  "There is nobody here except you and the barmaid.";
        }
        else {
            if (!money.to.burn) {
                #message 20  "The barmaid retorts, \"Go on, ya deadbeat. Drinks cost money, ya know!\"";                                  // [ no money
            }
            else {
                --gold.coin.count;
                if (script == to.stove) {                   // [ ready to serve
                    #message 51  "\"Right ya go, sir.\" says the pretty barmaid. \"This round's on you!\"
\"It'll be one gold coin.\"";
                    script.timer = 2;                       // [ force the serve
                    set(free.booze);
                }
                else {
                    #message 52  "\"Right ya go, sir.\" says the pretty barmaid. \"The next round's on you!\"
\"That'll be one gold coin.\"";
                }
            }
        }
    }

    if ((said(buy, drink) || said(buy, beer) ||
        said(buy, liquor))) {
        if (script != to.stove) {
            #message 27  "\"I'll be right with ya sir,\" the barmaid says, winking.";
        }
        else {
            if (ego.location == near.bar) {
                if (!money.to.burn) {
                    #message 20  "The barmaid retorts, \"Go on, ya deadbeat. Drinks cost money, ya know!\"";
                }
                else {
                    --gold.coin.count;
                    if (how.drunk.to.get < 120) {
                        how.drunk.to.get += how.drunk.to.get;
                    }
                    sober.up = how.drunk.to.get;
                    drunk.timer = 10;
                    if (current.status != drunk) {
                        current.status = drunk;
                        #message 21  "The barmaid hands you a glass, and the potent liquid burns as it slides down
your parched throat.It hits bottom, and you suddenly feel a bit woozy.";
                                                            // [            shake.screen(1);
                    }
                    else {
                        #message 22  "That one tasted even better than the last. Just one more sounds like a good
idea.";
                    }
                }
            }
            else {                                          // [ not near bar message
                #message 37  "You are too far away.";
            }
        }
    }

    if (customers == pirates) {
        if ((said(talk) || said(talk, barmaid))) {
            #message 34  "%m36 \"What can I do fer ya sir? Can I get ya somethin'? I
can't spend much time with ya, 'cause I gotta handle these seafarin'
scoundrels that come inta town t'day.\"";
        }

        if (said(talk)) {
            #message 24  "Talk to whom?";
        }

        if (said(talk, men)) {
            if (!talking.to.pirates) {
                if (!voyage.minutes && !voyage.seconds) {
                    voyage.minutes = inPort.init.minutes;   // [ 15 minutes
                }
                else {
                    if (voyage.minutes < 5) {
                        voyage.minutes = 5;                   // [ give him a few minutes
                    }
                }
                msg.count = pirate.msg.start;
                set(talking.to.pirates);
                script.timer = 0;                           // [ cancel a start of serve
            }
            else {
                timer.2 = 2;
            }

            if (captain.pissed) {
                #message 25  "The sailors just ignore you.";
            }
        }

                                                            // [ this is showing gold to pirates
        if (talking.to.pirates &&
            (said(give, gold, rol) ||
                said(give, purse, rol))) {
            if (captain.pissed) {
                #message 25  "The sailors just ignore you.";
            }
            else {
                reset(talking.to.pirates);
                if (money.to.burn) {                        // [ purse and coins
                    score += 3;
                    drop(i.purse.with.coins);
                    gold.coin.count = 0;
                    customers = none;
                    erase(a.pirate.1);
                    erase(a.pirate.2);
                    erase(a.captain);
                    set(paid.pirates);
                    #message 32  "%m31 \"Aye lad, I sees ya do have a wee bit 'o gold. It's less'n me
reg'lar  fare, but I'll gives ya passage anyways.
We'll be waitin' fer ya at the wharf, but not fer long.\"
The captain and his men down their rum in one long
draught, then leave the tavern.";
                }
                else {
                    set(captain.pissed);
                    if (has(i.purse.empty)) {
                        drop(i.purse.empty);
                        #message 42  "%m31 %m33";
                    }
                    else {
                        #message 33  "\"Ya little cheat! Ya've got not a farthing! Ya was tryin' t' weasel
aboard me ship!!Go on with ya, git outta me sight!\"";
                    }
                }
            }
        }
    }

    if (customers == bandits) {
        if ((said(talk) || said(talk, barmaid))) {
            #message 35  "%m36 Without taking her eyes off the two men, she says, \"I'll be happy to
take yer order, but be quick 'bout it 'cause those two are keepin' me
hoppin'.\"";
        }
        if (said(talk)) {
            #message 24  "Talk to whom?";
        }
        if (said(talk, men)) {
            if (!talked.bandits) {
                set(talked.bandits);
                #message 26  "One of the ugly rogues scowls at you as he says, \"Beat it, kid!\"";
            }
            else {
                #message 43  "The bandits are pointedly ignoring you. Don't press your luck.";
            }
        }
        if (said(look, men)) {
            #message 38  "The two scroungy thieves are dirty and unkempt,
and their clothes are smelly.Cruelty darkens their faces.These
look like good people to avoid.";
        }
        if ((said(kill, men) || said(rob, men))) {
            #message 13  "Surely, you jest!";
        }

    }
}

// [*****
// [exit              // [  test for leaving the room
// [*****

if (edge.ego.hit == bottom && ego.x > 63 && ego.x < 75) {
    if (current.status == drunk) {
        current.status = normal.ego;
    }
    new.room(24);
}


