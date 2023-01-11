// [logics for room 39 -- GENERAL STORE

#include "gamedefs.reh"
#include "rm39.msg"

#define  near.counter      1
#define  near.dog        2

#define  counterY        109

#define  dead.time        lv0
#define  old.gold        lv1
#define  script        lv2
#define  start.store  0
#define  greet.ego    1
#define  get.response  2
#define  no.response  3
#define  wandering    4
#define  dusting    5
#define  start.pick  6
#define  pick.item    7
#define  move.center  8
#define  store.done  9

#define  script.timer      lv3
#define  script.msg      lv4
#define  wag.timer        lv5                               // [ time of cycling
#define  center.x        lv6                                // [ where you were
#define  buy.msg        lv7

#define  already.tried.steal    lf0
#define  next          lf1
#define  get.single      lf2                                // [ flag for single word response
#define  ego.there        lf3

% object  a.storekeeper      1
% object  a.store.dog      2

if (init.log) {
    set(interiorRoom);

    wiz.x = 104;
    wiz.y = 134;

    landing.x = 55;
    landing.y = 141;

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

                                                            // [ sounds
    load.sound(m.store);
    reset(sound.done);

                                                            // [ customize ego
    load.view(v.ego);
    load.view(v.ego.dead);
    load.view.f(current.ego);
    set.view.f(ego, current.ego);

                                                            // [ man's furriest friend
    animate.obj(a.store.dog);
    load.view(v.store.dog);
    set.view(a.store.dog, v.store.dog);
    add.to.pic(v.store.dog, 0, 0, 51, 136, 1, 1);
    position(a.store.dog, 51, 136);
    work = 3;
    cycle.time(a.store.dog, work);
    stop.cycling(a.store.dog);
    ignore.blocks(a.store.dog);
    draw(a.store.dog);

                                                            // [ the store keeper
    animate.obj(a.storekeeper);
    load.view(v.storekeeper);
    set.view(a.storekeeper, v.storekeeper);
    position(a.storekeeper, 61, counterY);

                                                            // [ slow him down
    work = 2;
    step.time(a.storekeeper, work);
    cycle.time(a.storekeeper, work);
    draw(a.storekeeper);

    if ((positionEgo || current.status == fly)) {
        position(ego, 117, 136);
        if (current.status == normal.ego) {
            set(next);                                      // [ start the store keeper script
            move.obj(ego, 92, 136, 1, ego.there);
        }
        else {
            script = wandering;
            set(next);
        }
    }

    if (current.status == deferred.entry) {
        set(positionEgo);
        set(drawEgo);
        set(next);                                          // [ start the store keeper script
        position(ego, 92, 136);
    }

    if (drawEgo) {
        draw(ego);
    }

    show.pic();
    sound(m.store, sound.done);
    return();
}

// [ end of move obj in

if (ego.there) {
    reset(ego.there);
    start.motion(ego);
}

if (ego.poofing.done) {
    set(next);
    if (current.status != normal.ego) {
        script = wandering;
        script.timer = 0;
    }
}

ego.location = nowhere;

if (posn(ego, 58, 131, 108, 133)) {
    ego.location = near.counter;
}

if (posn(ego, 48, 131, 67, 140)) {                          // [  stepping on dog
    wag.timer = 6;
    ego.location = near.dog;
}

// [ Timer department

// [ dog tail wag timer
if (aSecondPassed && wag.timer) {
    start.cycling(a.store.dog);
    if (!handsOff) {
        --wag.timer;
    }
    if (wag.timer == 0) {
        set.cel(a.store.dog, 0);                            // [ asleep again
        stop.cycling(a.store.dog);
    }
}

// [ store keeper runs on a script.  Follows, script controllers.

if (aSecondPassed && script.timer) {
    if (!handsOff) {
        --script.timer;
    }
    if (script.timer == 0) {
        set(next);
    }
}

if (next && script == start.store) {
    ++script;
    script.timer = 0;
    x = 92;                                                 // [ ego after move.obj
    y = counterY;
    work = 1;
    start.cycling(a.storekeeper);
    move.obj.f(a.storekeeper, x, y, work, next);
}

if (next && script == greet.ego) {
    ++script;
    script.timer = 0;
    set.loop(a.storekeeper, 2);
    stop.cycling(a.storekeeper);
    reset(next);
    script.timer = 1;
}

if (next && script == get.response) {
    ++script;
    script.timer = 0;
    if (script.msg == 0) {                                  // [ first greeting
        #message 26  "\"Good day to you, young man,\" greets the store keeper. \"What can
I do for you ? \"";
        ++script.msg;
    }
    else {
        #message 8  "The storekeeper asks \"Now, what can I do for you?\"";                                           // [ a what to buy message
    }
    reset(next);
    script.timer = 30;                                      // [ wait for a response for a long time
}

if (next && script == no.response) {                        // [ if he responds, he won't get here
    ++script;
    reset(get.single);
    script.timer = 0;
    #message 13  "\"I've got some dusting to do,\" the shopkeeper says, turning around.
\"Just let me know when you need something.\"";                                              // [  back to dusting
    set(next);                                              // [ falls through this loop
}

if (next && script == wandering) {
    ++script;
    script.timer = 0;
    start.cycling(a.storekeeper);
    y = counterY;
    random(56, 92, x);
    work = 1;
    move.obj.f(a.storekeeper, x, y, work, next);
}

if (next && script == dusting) {
    script.timer = 0;
    script = wandering;                                     // [ repeat this sequence
    reset(next);
    set.loop(a.storekeeper, 3);                             // [ back view
    start.cycling(a.storekeeper);
    random(2, 3, script.timer);
}

if (next && script == start.pick) {                         // [ buying something
    ++script;
    script.timer = 0;
    y = counterY;
    center.x = ego.x;                                       // [ save a position to return to
    random(56, 92, x);
    work = 1;
    start.cycling(a.storekeeper);
    move.obj.f(a.storekeeper, x, y, work, next);
    prevent.input();
    program.control();
}

if (next && script == pick.item) {
    script.timer = 0;
    ++script;
    set.loop(a.storekeeper, 3);                             // [ back view
    set.cel(a.storekeeper, 0);
    start.cycling(a.storekeeper);
    prevent.input();
    program.control();
    reset(next);

}

if (script == move.center) {                                // [ artificial end.of.loop
    current.cel(a.storekeeper, work);
    if (work == 6) {
        set(next);
    }
}

if (next && script == move.center) {
    script.timer = 0;
    ++script;
    y = counterY;
    start.cycling(a.storekeeper);
    work = 1;
    move.obj.f(a.storekeeper, center.x, y, work, next);
    prevent.input();
    program.control();
}

if (next && script == store.done) {                         // [ print the got message
    reset(next);
    print.f(buy.msg);
    set.loop(a.storekeeper, 2);
    #message 27  "\"What else can I get for you?\" asks the amiable storekeeper.";                                              // [ any thing else
    set(get.single);
    stop.cycling(a.storekeeper);
    script = no.response;
    script.timer = 10;                                      // [ time before he wanders
    accept.input();
    player.control();
}

// [ accounting department

if (old.gold != gold.coin.count) {
    old.gold = gold.coin.count;
    if (gold.coin.count == 0) {
        if (has(i.purse.with.coins)) {
            drop(i.purse.with.coins);
        }
        get(i.purse.empty);
    }
}

// [*****
// :h
// [*****

if (have.input) {

    if (said(dog, last)) {
        #message 46  "Why, \"Ration\", of course!";
    }

    if ((said(look) ||
        said(look, room) ||
        said(look, store))) {
        #message 2  "The store is full of general merchandise and
supplies to meet the needs of the village.A friendly storekeeper
bustles busily behind the counter.";
    }

    if ((said(look, goods) ||
        said(look, shelves))) {
        #message 3  "The shelves are filled with all sorts of useful items.
There are a few items of particular interest to you : leather pouches,
salt, fish oil, and lard.";
    }

    if ((said(look, clerk) ||
        said(look, store, clerk))) {
        #message 4  "The short, balding storekeeper seems to be an amiable fellow.";
    }

    if ((said(look, out, window) ||
        said(look, out, door) ||
        said(look, outside))) {
        #message 5  "Outside, you see the village and the ocean.";
    }

    if ((said(look, on, floor) || said(look, floor))) {
        #message 47  "A brown-spotted dog lies on the floor.";
    }

    if (said(look, door)) {
        #message 1  "The door is open fully to the sea breezes.";
    }

    if ((said(look, stove) ||
        said(look, woodstove))) {
        #message 6  "The woodstove is hard at work heating the little store. It is
chilly here, so close to the ocean.";
    }

    if (said(pet, dog)) {
        if (ego.location != near.dog) {
            #message 38  "You need to be closer.";
        }
        else {
            wag.timer = 5;
            if (!obj.in.room(i.dog.hair, current.room)) {
                #message 40  "As you pet him, Kenny licks your hand and thumps his tail in appreciation.";
            }
            else {
                get(i.dog.hair);
                score += 1;
                #message 41  "%m40 A small wad of dog fur collects in your hand, and you tuck it into your
pocket for later use.";
            }
        }
    }

    if ((said(get, fur) || said(get, dog, fur) || said(get, fur, dog))) {
        if (!obj.in.room(i.dog.hair, current.room)) {
            #message 42  "You already have some dog fur.";
        }
        else {
            if (ego.location != near.dog) {
                #message 38  "You need to be closer.";
            }
            else {
                wag.timer = 6;
                get(i.dog.hair);
                score += 1;                                 // [ also gotten above
                #message 41  "%m40 A small wad of dog fur collects in your hand, and you tuck it into your
pocket for later use.";
            }
        }
    }

    if (said(talk, dog)) {
        wag.timer = 6;
        #message 43  "You speak to the dog in a soothing voice, and his ears perk up. \"Go
ahead and pet him, \" says the storekeeper. \"Kenny loves attention.\"";
    }

    if (said(look, dog)) {
        #message 44  "The dog lying on the floor is obviously a mutt. The name, \"Kenny\",
is embossed on his leather collar.";
    }

    if ((said(kick, dog) || said(eat, dog))) {
        #message 45  "You must be kidding.";
    }

    if (said(get, dog)) {
        #message 49  "Kenny belongs to the storekeeper.";
    }

    if (said(get, man)) {
        #message 51  "He won't let you!";
    }

    if ((said(kill, dog) || said(kill, man))) {
        #message 50  "You're not that cruel!";
    }

    if (said(get, anyword)) {
        #message 17  "This is a business, not a charity. You have to buy the things you want.";
    }

    if (said(jump)) {
        #message 18  "How high? Are you a rabbit?";
    }

    if ((said(jump, counter) || said(jump, over, counter))) {
        #message 28  "Don't jump the counter. The storekeeper would get mad.";
    }

    if (said(steal, anyword)) {
        #message 7  "That is not a smart idea. The storekeeper is keeping an eye on you!";
    }

    if (said(buy)) {
        #message 8  "The storekeeper asks \"Now, what can I do for you?\"";
    }

    if (said(buy, anyword)) {
        if (ego.location != near.counter) {
            #message 19  "You need to move closer to the counter.";
        }
        else {
            if (gold.coin.count == 0) {                     // [ he hasn't the money
                #message 10  "You don't have any money.";                                  // [no tickee no laundry
            }
            else {
                reset(have.match);                          // [ only charge for matches
                if (said(buy, salt)) {
                    if (!obj.in.room(i.salt, current.room)) {
                        #message 30  "You already bought it. You don't need any more.";
                        goto AlreadyHasIt;
                    }
                    get(i.salt);
                    score += 1;
                }
                if (said(buy, lard)) {
                    if (!obj.in.room(i.lard, current.room)) {
                        #message 30  "You already bought it. You don't need any more.";
                        goto AlreadyHasIt;
                    }
                    get(i.lard);
                    score += 1;
                }
                if ((said(buy, fish, oil) || said(buy, oil)
                    || said(buy, fish$oil))) {
                    if (!obj.in.room(i.fish.oil, current.room)) {
                        #message 30  "You already bought it. You don't need any more.";
                        goto AlreadyHasIt;
                    }
                    get(i.fish.oil);
                    score += 1;
                }
                if ((said(buy, pouch) || said(buy, leather, pouch))) {
                    if (!obj.in.room(i.empty.pouch, current.room)) {
                        #message 30  "You already bought it. You don't need any more.";
                        goto AlreadyHasIt;
                    }
                    get(i.empty.pouch);
                    score += 1;
                }
                if (have.match) {                           // [ this costs him
                    random(21, 25, buy.msg);
                    --gold.coin.count;
                    script.timer = 0;
                    script = start.pick;
                    set(next);
                }
                :AlreadyHasIt
                    if (said(buy, food)) {
                        #message 11  "\"Try the tavern across the street,\" the friendly storekeeper says.";
                    }

                if (said(buy, supplies)) {
                    #message 12  "\"The store is full of supplies,\" the balding shopkeeper tells you.
\"What would you like?\"";
                }

                if ((said(buy, beer) || said(buy, wine)
                    || said(buy, rum))) {
                    #message 11  "\"Try the tavern across the street,\" the friendly storekeeper says.";
                }

                                                            // [ catch the fallout (poorly)
                if (said(buy, anyword)) {
                    #message 15  "You have no use for %w2.";
                }
            }
        }
    }                                                       // [ end of buying if

    if (said(talk, storekeeper)) {
        if (ego.location != near.counter) {
            random(31, 37, work);                           // [ casual conversation
            print.f(work);
        }
        else {
            script = start.store;                           // [ show intent to purchase
            set(next);
        }
    }
}                                                           // [ end of no input

// [*****
// :e
// [*****

if (hit.special) {
    new.room(24);
}
else {
    if (x > 123) {
        new.room(24);
    }
}


