// [logics for room 4 -- rm.ego.bedroom
// [  February 29, 1988

#include  "rm4.msg"
#include  "gamedefs.al"
#include  "rm-names.h"
#include  "iv-names.h"

// [  This is Gwydion's room plus part of upstairs hallway. It has an
// [invisible door.  If wiz locks you in, you can't leave till punish.timer
// [is done.  Manannan never enters this room.  can hide inventory under bed

#define  l.looking.right          0 // [rm4    VIEW.LOOKING.UNDER
#define  l.looking.rear           1 // [rm22

#define  ego.in.bed             lf1
#define  zzz's.done             lf2
#define  door.locked            lf3
#define  in.bedroom             lf4
#define  near.door              lf5

#define  object                 lv0
#define  room                   lv1
#define  ego.timer              lv2
#define  zzz's.timer            lv4
#define  reason.going.to.bed    lv5
#define  looking    1
// [  %define  sleeping    2
#define  putting    3
#define  getting    4

#define  obj2hide               lv6
#define  obj2get                lv7


if (init.log)
{
    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    load.view(v.ego);
    map.area = map.wiz.house;
    landing.x = 110;
    landing.y = 149;
    // [NEVER load lgc.wiz in this room!
    wiz.y = 0;
    cat.x = 52;
    cat.y = 131;
    load.logics(lgc.wiz.house);
    load.view(v.ego.leaving.bed);
    load.view(v.ego.sleeping);
    load.sound(s.snoring);
    load.view(v.ego.looking.under);
    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    if (current.status == fly)
    {
        set(positionEgo);
    }

    if (positionEgo)
    {
        if (previous.room == 3)
        {
            ego.x = 14;
            position.v(ego, ego.x, ego.y);
        }
        else
        {
            position.v(ego, landing.x, landing.y);
        }
    }

    if (current.status == locked.in.bedroom)
    {
        reset(drawEgo);
        set(positionEgo);
        start.a.poof = poof.in;
        current.status = normal.ego;
        set(door.locked);
        set.view(ego, v.ego);
        position.v(ego, landing.x, landing.y);
    }

    if (drawEgo)
    {
        draw(ego);
    }

    if (door.locked)
    {
        // [to fool rm0 into !drawing him
        set(drawEgo);
    }
    call(lgc.wiz.house);
    show.pic();

    if (door.locked)
    {
        reset(keep.cycling);
    }

    return();

}

reset(near.door);
if (posn(ego, 84, 139, 94, 162))
{
    set(near.door);
}

reset(in.bedroom);
if (ego.x > 77)
{
    set(in.bedroom);
}



// [*****
// [handle.input
// [*****

if (!have.input || !in.bedroom || current.status == sleeping)
{
    goto normal.input;
}

obj2hide = 0;

if (has(i.chicken.feather) && said(hide, chicken, feather, rol))
{
    obj2hide = chicken.feather;
}

if (has(i.cat.hair) && said(hide, cat, hair, rol))
{
    obj2hide = cat.hair;
}

if (has(i.dog.hair) && said(hide, dog, hair, rol))
{
    obj2hide = dog.hair;
}

if (has(i.snakeskin) && said(hide, snake$skin, rol))
{
    obj2hide = snakeskin;
}

if (has(i.fish.bone) && said(hide, fish$bone, rol))
{
    obj2hide = fish.bone;
}

if (has(i.thimble) && said(hide, thimble, rol))
{
    obj2hide = thimble;
}

if (has(i.dew) && (said(hide, thimble, rol) || said(hide, dew, rol)))
{
    obj2hide = dew;
}

if (has(i.dough.balls) && said(hide, dough, pieces, rol))
{
    #message 38  "You consider removing the dough pieces from your ears, but decide"
                 "they are too fragile.You carefully comb your scraggly hair over them"
                 "so the wizard cannot detect them.";
}

if (has(i.eagle.feather) && said(hide, eagle, feather, rol))
{
    obj2hide = eagle.feather;
}

if (has(i.fly.wings) && said(hide, fly, rol))
{
    obj2hide = fly.wings;
}

if (has(i.saffron) && said(hide, saffron, rol))
{
    obj2hide = saffron;
}

if (has(i.rose.essence) &&
   (said(hide, essence, rol) || said(hide, magic, essence, rol)))
{
    obj2hide = rose.essence;
}

if (has(i.magic.essence) &&
   (said(hide, essence, rol) || said(hide, magic, essence, rol)))
{
    obj2hide = magic.essence;
}

if (has(i.salt) && said(hide, salt, rol))
{
    obj2hide = salt;
}

if (has(i.amber.stone) && said(hide, amber, stone, rol))
{
    obj2hide = amber.stone;
}

if (has(i.mistletoe) && said(hide, mistletoe, rol))
{
    obj2hide = mistletoe;
}

if (has(i.magic.stone) && (said(hide, amber, stone, rol) || said(hide, magic, stone, rol)))
{
    obj2hide = magic.stone;
}

if (has(i.nightshade.juice) && said(hide, nightshade, juice, rol))
{
    obj2hide = nightshade.juice;
}

if (has(i.acorns) && said(hide, acorns, rol))
{
    obj2hide = acorns;
}

if (has(i.empty.pouch) &&
   (said(hide, empty, pouch, rol) || said(hide, pouch, rol)))
{
    obj2hide = empty.pouch;
}

if (has(i.sleep.powder) &&
   (said(hide, pouch, rol) || said(hide, sleep, powder, rol)))
{
    obj2hide = sleep.powder;
}

if (has(i.mandrake.root) &&
   (said(hide, mandrake, root, powder, rol) || said(hide, mandrake, root, rol) || said(hide, root, rol)))
{
    obj2hide = mandrake.root;
}

if (has(i.fish.oil) && said(hide, oil, rol))
{
    obj2hide = fish.oil;
}

if (has(i.cat.cookie) && (said(hide, cookie, rol) || said(hide, cat, cookie, rol)))
{
    obj2hide = cat.cookie;
}

if (has(i.porridge.poisoned) || has(i.porridge)) && said(hide, porridge, rol)
{
    if (has(i.porridge.poisoned))
    {
        obj2hide = porridge.poisoned;
    }

    if (has(i.porridge))
    {
        obj2hide = porridge;
    }
}

if (has(i.porridge.poisoned) && said(hide, poison, porridge, rol))
{
    if (has(i.porridge.poisoned))
    {
        obj2hide = porridge.poisoned;
    }
}

if (has(i.ocean.water) &&
   (said(hide, ocean, water, rol) || said(hide, cup, rol) || said(hide, water, rol)))
{
    obj2hide = ocean.water;
}

if (has(i.mud) && (said(hide, spoon, rol) || said(hide, mud, rol)))
{
    obj2hide = mud;
}

if (has(i.toadstool.powder) && said(hide, toadstool, powder, rol))
{
    obj2hide = toadstool.powder;
}

if (has(i.fish.jar) && said(hide, jar, rol))
{
    obj2hide = fish.jar;
}

if (has(i.storm.brew) && (said(hide, brew, rol) || said(hide, jar, rol)))
{
    obj2hide = storm.brew;
}

if (has(i.toad.spit) && (said(hide, toad, spit, rol) || said(hide, spit, rol)))
{
    obj2hide = toad.spit;
}

if (has(i.lard) && said(hide, lard, rol))
{
    obj2hide = lard;
}

if (has(i.knife) && said(hide, knife, rol))
{
    obj2hide = knife;
}

if (has(i.cactus) && said(hide, cactus, rol))
{
    obj2hide = cactus;
}

if (has(i.invisible.ointment) && said(hide, ointment, rol))
{
    obj2hide = invisible.ointment;
}

if (has(i.magic.wand) && (said(hide, wand, rol) || said(hide, magic, wand, rol)))
{
    obj2hide = magic.wand;
}

if (has(i.key) && said(hide, key, rol))
{
    obj2hide = key;
}

if (has(i.bowl) && said(hide, bowl, rol))
{
    obj2hide = bowl;
}

if (has(i.spoon) && said(hide, spoon, rol))
{
    obj2hide = spoon;
}

if (has(i.cup) && said(hide, cup, rol))
{
    obj2hide = cup;
}

if (has(i.mirror) && said(hide, mirror, rol))
{
    obj2hide = mirror;
}

if (has(i.purse.with.coins) || has(i.purse.empty)) &&
   (said(hide, purse, rol) || said(hide, coins, rol) || said(hide, gold, coins, rol))
{
    if (has(i.purse.with.coins))
    {
        obj2hide = purse.with.coins;
    }
    if (has(i.purse.empty))
    {
        obj2hide = purse.empty;
    }
}

if (has(i.bread) && said(hide, bread, rol))
{
    obj2hide = bread;
}

if (has(i.fruit) && said(hide, fruit, rol))
{
    obj2hide = fruit;
}

if (has(i.mutton) && said(hide, mutton, rol))
{
    obj2hide = mutton;
}

if (has(i.magic.map) && (said(hide, map, rol) || said(hide, magic, map, rol)))
{
    obj2hide = magic.map;
}

if (obj2hide)
{
    reason.going.to.bed = putting;
    set(ego.arrived);
    ego.location = 0;
    goto no.input;
}

obj2get = 0;

if (obj.in.room(i.chicken.feather, current.room) && said(get, chicken, feather, rol))
{
    obj2get = chicken.feather;
}

if (obj.in.room(i.cat.hair, current.room) && said(get, cat, hair, rol))
{
    obj2get = cat.hair;
}

if (obj.in.room(i.dog.hair, current.room) && said(get, dog, hair, rol))
{
    obj2get = dog.hair;
}

if (obj.in.room(i.snakeskin, current.room) && said(get, snake$skin, rol))
{
    obj2get = snakeskin;
}

if (obj.in.room(i.fish.bone, current.room) && said(get, fish$bone, rol))
{
    obj2get = fish.bone;
}

if (obj.in.room(i.thimble, current.room) && said(get, thimble, rol))
{
    obj2get = thimble;
}

if (obj.in.room(i.dew, current.room) && (said(get, thimble, rol) || said(get, dew, rol)))
{
    obj2get = dew;
}

if (obj.in.room(i.eagle.feather, current.room) && said(get, eagle, feather, rol))
{
    obj2get = eagle.feather;
}

if (obj.in.room(i.fly.wings, current.room) && said(get, fly, rol))
{
    obj2get = fly.wings;
}

if (obj.in.room(i.saffron, current.room) && said(get, saffron, rol))
{
    obj2get = saffron;
}

if (obj.in.room(i.rose.essence, current.room) && (said(get, essence, rol) || said(get, magic, essence, rol)))
{
    obj2get = rose.essence;
}

if (obj.in.room(i.magic.essence, current.room) &&
   (said(get, essence, rol) || said(get, magic, essence, rol)))
{
    obj2get = magic.essence;
}

if (obj.in.room(i.salt, current.room) && said(get, salt, rol))
{
    obj2get = salt;
}

if (obj.in.room(i.amber.stone, current.room) && said(get, amber, stone, rol))
{
    obj2get = amber.stone;
}

if (obj.in.room(i.mistletoe, current.room) && said(get, mistletoe, rol))
{
    obj2get = mistletoe;
}

if (obj.in.room(i.magic.stone, current.room) && (said(get, amber, stone, rol) || said(get, magic, stone, rol)))
{
    obj2get = magic.stone;
}

if (obj.in.room(i.nightshade.juice, current.room) && said(get, nightshade, juice, rol))
{
    obj2get = nightshade.juice;
}

if (obj.in.room(i.acorns, current.room) && said(get, acorns, rol))
{
    obj2get = acorns;
}

if (obj.in.room(i.empty.pouch, current.room) && (said(get, empty, pouch, rol) || said(get, pouch, rol)))
{
    obj2get = empty.pouch;
}

if (obj.in.room(i.sleep.powder, current.room) && (said(get, pouch, rol) || said(get, sleep, powder, rol)))
{
    obj2get = sleep.powder;
}

if (obj.in.room(i.mandrake.root, current.room) &&
    (said(get, mandrake, root, powder, rol) || said(get, mandrake, root, rol) || said(get, root, rol)))
{
    obj2get = mandrake.root;
}

if (obj.in.room(i.fish.oil, current.room) && said(get, oil, rol))
{
    obj2get = fish.oil;
}

if (obj.in.room(i.cat.cookie, current.room) && (said(get, cookie, rol) || said(get, cat, cookie, rol)))
{
    obj2get = cat.cookie;
}

if (obj.in.room(i.porridge.poisoned, current.room) ||
    obj.in.room(i.porridge, current.room)) && said(get, porridge, rol)
{
    if (obj.in.room(i.porridge.poisoned, current.room))
    {
        obj2get = porridge.poisoned;
    }

    if (obj.in.room(i.porridge, current.room))
    {
        obj2get = porridge;
    }
}

if (obj.in.room(i.porridge.poisoned, current.room) && said(get, poison, porridge))
{
    obj2get = porridge.poisoned;
}

if (obj.in.room(i.ocean.water, current.room) &&
   (said(get, ocean, water, rol) || said(get, cup, rol) || said(get, water, rol)))
{
    obj2get = ocean.water;
}

if (obj.in.room(i.mud, current.room) &&
    (said(get, mud, rol) || said(get, spoon, rol)))
{
    obj2get = mud;
}

if (obj.in.room(i.toadstool.powder, current.room) && said(get, toadstool, powder, rol))
{
    obj2get = toadstool.powder;
}

if (obj.in.room(i.fish.jar, current.room) && said(get, jar, rol))
{
    obj2get = fish.jar;
}

if (obj.in.room(i.storm.brew, current.room) && (said(get, brew, rol) || said(get, jar, rol)))
{
    obj2get = storm.brew;
}

if (obj.in.room(i.toad.spit, current.room) && (said(get, toad, spit, rol) || said(get, spit, rol)))
{
    obj2get = toad.spit;
}

if (obj.in.room(i.lard, current.room) && said(get, lard, rol))
{
    obj2get = lard;
}

if (obj.in.room(i.knife, current.room) && said(get, knife, rol))
{
    obj2get = knife;
}

if (obj.in.room(i.cactus, current.room) && said(get, cactus, rol))
{
    obj2get = cactus;
}

if (obj.in.room(i.invisible.ointment, current.room) && said(get, ointment, rol))
{
    obj2get = invisible.ointment;
}

if (obj.in.room(i.magic.wand, current.room) && (said(get, magic, wand, rol) || said(get, wand, rol)))
{
    obj2get = magic.wand;
}

if (obj.in.room(i.key, current.room) && said(get, key, rol))
{
    obj2get = key;
}

if (obj.in.room(i.bowl, current.room) && said(get, bowl, rol))
{
    obj2get = bowl;
}

if (obj.in.room(i.spoon, current.room) && said(get, spoon, rol))
{
    obj2get = spoon;
}

if (obj.in.room(i.cup, current.room) && said(get, cup, rol))
{
    obj2get = cup;
}

if (obj.in.room(i.mirror, current.room) && said(get, mirror, rol))
{
    obj2get = mirror;
}

if (obj.in.room(i.purse.with.coins, current.room) || obj.in.room(i.purse.empty, current.room)) &&
    (said(get, purse, rol) || said(get, coins, rol) || said(get, gold, coins, rol))
{
    if (obj.in.room(i.purse.with.coins, current.room))
    {
        obj2get = purse.with.coins;
    }
    if (obj.in.room(i.purse.empty, current.room))
    {
        obj2get = purse.empty;
    }
}

if (obj.in.room(i.bread, current.room) && said(get, bread, rol))
{
    obj2get = bread;
}

if (obj.in.room(i.fruit, current.room) && said(get, fruit, rol))
{
    obj2get = fruit;
}

if (obj.in.room(i.mutton, current.room) && said(get, mutton, rol))
{
    obj2get = mutton;
}

if (obj.in.room(i.magic.map, current.room) && (said(get, map, rol) || said(get, magic, map, rol)))
{
    obj2get = magic.map;
}

if (obj2get)
{
    reason.going.to.bed = getting;
    set(ego.arrived);
    ego.location = 0;
    goto no.input;
}

// [*****
// :normal.input
// [*****

if (!have.input) { goto no.input; }

if (current.status == sleeping)
{
    // [wake includes "wake$up"
    if (said(get, up) ||
        said(get$out, bed) ||
        said(get, up, from, bed) ||
        said(wake) ||
        said(wake, leave, bed) ||
        said(get, up, bed) ||
        said(leave, bed))
    {
        ego.location = 8;
        set(ego.arrived);
    }
    else
    {
        #message 27  "Shhhh! You're trying to sleep.";
        set(have.match);
    }
}

if (said(look, wall) ||
    said(look, house) ||
    said(look, room) ||
    said(look) ||
    said(look, tapestry))
{
    if (!in.bedroom)
    {
        #message 12  "You have always admired this lovely tapestry. It adds one of the few"
                     "bright spots to this dreary house.";
    }
    else
    {
        reset(have.match);
    }
}

if (said(look, behind, tapestry) || said(look, under, tapestry))
{
    if (posn(ego, 52, 131, 77, 137))
    {
        #message 13  "You lift the bottom of the tapestry and peer behind it. The wall is filled"
                     "with cracks.You can see why Manannan would hang a tapestry here."
                     "(There are also dozens of charcoal - scribbled drawings, diagrams, maps, and"
                     "notes to programmers, with the legend \"King's Quest IV,\" but you're"
                     "uninterested in this, since you presently have your hands full with"
                     "\"King's Quest III.\") You lower the tapestry and smooth out the wrinkles.";
    }
    else
    {
        if (in.bedroom)
        {
            #message 21  "How can you see it through your bedroom wall?";
        }
        else
        {
            #message 2  "You are not close enough.";
        }
    }
}

if (said(look, room) || said(look) || said(look, bedroom))
{
    if (!in.bedroom)
    {
        #message 31  "You might try that over there in your bedroom, but not here in the hall.";
    }
    else
    {
        #message 1  "This is your own pitiful bed chamber. Compared to Manannan's"
                    "fine room, yours is almost a cell.The bed is hardand"
                    "uncomfortable with only a threadbare blanketand a small, flat pillow."
                    "The other furnishings are junk.But, as poor as it is,"
                    "it's your own haven, as the wizard never enters it.";
    }
}

if (said(look, dresser) || said(look, cabinet))
{
    if (!in.bedroom)
    {
        #message 31  "You might try that over there in your bedroom, but not here in the hall.";
    }
    else
    {
        #message 6  "Your dresser is a piece of junk. It's full of nicks and
                    "scratches, and one drawer is completely missing.";
    }
}

if (said(look, on, dresser) ||
    said(look, above, dresser) ||
    said(look, on, top$of, dresser) ||
    said(look, on, cabinet) ||
    said(look, above, cabinet) ||
    said(look, on, top$of, cabinet))
{
    if (!in.bedroom)
    {
        #message 2  "You are not close enough.";
    }
    else
    {
        #message 7  "There is nothing you want there.";
    }
}

if (said(look$in, dresser) ||
    said(open, dresser) ||
    said(look$in, cabinet) ||
    said(open, cabinet) ||
    said(look, drawer) ||
    said(open, drawer))
{
    if (!in.bedroom)
    {
        #message 2  "You are not close enough.";
    }
    else
    {
        #message 9  "You have nothing of any interest in your dresser drawer.";
    }
}

if (said(look, mirror) || said(look$in, mirror))
{
    if (!in.bedroom)
    {
        #message 31  "You might try that over there in your bedroom, but not here in the hall.";
    }
    else
    {
        #message 10  "You look into the cracked mirror hanging on the wall. Your
                     "reflection shows a tall, handsome lad dressed in dirty rags.";
    }

    if (has(i.mirror))
    {
        reset(have.match);                                  // [so we get a show.obj(iv.mirror)
    }
}

if (said(open, door))
{
    if (!near.door)
    {
        #message 2  "You are not close enough.";
    }
    else
    {
        if (door.locked)
        {
            #message 14  "You twist the door knob on the bedroom door, but to your
                         "frustration, find it locked.";
        }
        else
        {
            #message 15  "The door is already open.";
        }
    }
}

if (said(close, door))
{
    if (door.locked)
    {
        #message 16  "The door is already closed.";
    }
    else
    {
        #message 17  "You start to close the door, but, so as not to arouse the wizard's
                     "suspicions, you leave it open.";
    }
}

if (said(unlock, door))
{
    if (door.locked)
    {
        #message 18  "You don't have a key that unlocks this door. It seems you are at
                     "the mercy of the miserable old wizard.";
    }
    else
    {
        #message 19  "The door is not locked. It's not even closed!";
    }
}

if (said(pick, lock) || said(pick, door, lock) || said(pick, lock, door))
{
    if (door.locked)
    {
        #message 20  "You have nothing with which to pick a lock.";
    }
    else
    {
        #message 19  "The door is not locked. It's not even closed!";
    }
}

if (said(look, door))
{
    if (door.locked)
    {
        #message 29  "The door is closed.";
    }
    else
    {
        #message 37  "The door is wide open.";
    }
}

if (said(break, door) || said(break, down, door) || said(break, open, door))
{
    if (!near.door)
    {
        #message 2  "You are not close enough.";
    }
    else
    {
        if (door.locked)
        {
            #message 22  "You throw your body against the locked door, but in vain. The
                         "door is too strong for you to break.";
        }
        else
        {
            #message 19  "The door is not locked. It's not even closed!";
        }
    }
}

if (said(break, window) || said(break, open, window))
{
    if (!in.bedroom)
    {
        #message 31  "You might try that over there in your bedroom, but not here in the hall.";
    }
    else
    {
        #message 23  "That would do you no good. The wizard anticipated your escape and placed
                     "iron bars outside your window.";
    }
}

// [  HERE'S THE BED STUFF:

if (said(look, bed))
{
    if (!in.bedroom)
    {
        #message 31  "You might try that over there in your bedroom, but not here in the hall.";
    }
    else
    {
        #message 3  "The bed is nothing more than a cot, hard and cold, and"
                    "is difficult to sleep on.Your pillow is small, flat, and made of old rags.";
    }
}

if (said(look, under, bed))
{
    if (!in.bedroom)
    {
        #message 31  "You might try that over there in your bedroom, but not here in the hall.";
    }
    else
    {
        reason.going.to.bed = looking;
        set(ego.arrived);
        ego.location = 0;
    }
}

if (said(lie, bed) ||
    said(go, bed) ||
    said(lie, on, bed) ||
    said(go, sleep) ||
    said(go, sleep, on, bed) ||
    said(sleep, on, bed) ||
    said(sleep, bed) ||
    said(get, on, bed))
{
    if (!in.bedroom)
    {
        #message 31  "You might try that over there in your bedroom, but not here in the hall.";
    }
    else
    {
        if (current.status == normal.ego)
        {
            reason.going.to.bed = sleeping;
            set(ego.arrived);
            ego.location = 0;
        }
    }
}

if (said(hide, stuff, rol))
{
    if (!in.bedroom)
    {
        #message 31  "You might try that over there in your bedroom, but not here in the hall.";
    }
    else
    {
        reason.going.to.bed = putting;
        set(ego.arrived);
        ego.location = 0;
    }
}

if (said(get, stuff, rol))
{
    if (!in.bedroom)
    {
        #message 31  "You might try that over there in your bedroom, but not here in the hall.";
    }
    else
    {
        reason.going.to.bed = getting;
        set(ego.arrived);
        ego.location = 0;
    }
}

// [*****
// :no.input
// [*****

// [  EGO'S WALKING TO THE BED

--ego.timer;
if (ego.timer == 1)
{
    set(ego.arrived);
}

if (ego.arrived)
{
    reset(ego.arrived);
    ++ego.location;
    program.control();
    prevent.input();
    set(handsOff);
    set(keep.cycling);
    if (ego.location == 1)
    {
        // [if here, skip the first move.obj
        if (posn(ego, 88, 120, 115, 167))
        {
            ++ego.location;
        }
        else
        {
            move.obj(ego, 111, 152, 0, ego.arrived);
        }
    }

    if (ego.location == 2)
    {
        move.obj(ego, 111, 133, 0, ego.arrived);
    }

    if (ego.location == 3)
    {
        ego.cycle.time = 2;
        cycle.time(ego, ego.cycle.time);
        stop.motion(ego);

        if (reason.going.to.bed == sleeping)
        {
            set.priority(ego, 15);
            set.view(ego, v.ego.leaving.bed);
            reposition.to(ego, 119, 131);
            last.cel(ego, work);
            set.cel.v(ego, work);
            beginning.of.loop(ego, ego.arrived);
        }
        else
        {
            set.view(ego, v.ego.looking.under);
            set.loop(ego, l.looking.right);
            set.cel(ego, 0);
            end.of.loop(ego, ego.arrived);
        }
    }

    if (ego.location == 4)
    {
        ego.timer = 11;
        stop.motion(ego);
        reset(keep.cycling);
    }

    if (ego.location == 5)
    {
        stop.motion(ego);

        if (reason.going.to.bed != sleeping)
        {
            ego.timer = 11;
            reset(keep.cycling);
        }
        else
        {
            set(ego.in.bed);
            set.view(ego, v.ego.sleeping);
            reposition.to(ego, 123, 131);
            set.cel(ego, 0);
            accept.input();
            zzz's.timer = 44;
            reset(zzz's.done);
            ego.location = 0;
            current.status = sleeping; // [nightie, night sweet ego
            #message 26  "You lie down on your hard bed, stretch, then curl up,"
                         "trying hard to get comfortable.Your thin blanket and small"
                         "pillow do not help much.";
        }

        if (reason.going.to.bed == looking)
        {
            if (stuff.under.bed)
            {
                #message 5  "You bend down and peek under the bed. Your possessions are still safely hidden.";
            }
            else
            {
                #message 4  "You lean down and poke your head under the bed. You see nothing but cobwebs and dust.";
            }
        }

        if (reason.going.to.bed == putting)
        {
            work = current.room;

            if (obj2hide)
            {
                #message 34  "You get on your hands and knees and shove it under the bed. It will be
                             "safe from the wizard's sharp eyes there.";
                set(stuff.under.bed);
                put.v(obj2hide, current.room);
            }
            else
            {
                object = 1;                                 // [Hide everything in inventory,
                :mr.looper                                  // [under the bed.
                get.room.f(object, room);
                if (room == inventory)
                {
                    put.v(object, current.room);
                    set(stuff.under.bed);
                }
                ++object;
                if (object == dough.balls)
                {
                    ++object;
                }
                if (object < size.of.inventory)
                {
                    goto mr.looper;
                }

                if (stuff.under.bed)
                {
                    #message 24  "You get on your hands and knees and quickly shove all your"
                                 "possessions under the bed.They will be safe from the wizard's sharp"
                                 "eyes there.";
                    if (!hid.stuff.under.bed)
                    {
                        set(hid.stuff.under.bed);
                        score += 4;
                    }
                }
                else
                {
                    #message 32  "Obviously, you have nothing to hide, Gwydion!";
                }
            }
        }

        if (reason.going.to.bed == getting)
        {
            if (!stuff.under.bed)
            {
                #message 11  "There's nothing under the bed.";
            }
            else
            {
                if (obj2get)
                {
                    work = inventory;
                    get.room.v(obj2get, room);
                    if (room != rm.ego.bedroom)
                    {
                        #message 36  "You drop down, reach under the bed, and then realize"
                                     "you've never put it there!";
                    }
                    else
                    {
                        #message 35  "Dropping to your knees, you reach under the bed and retrieve it.";
                        put.v(obj2get, work);
                        reset(stuff.under.bed);
                        object = 1;                           // [See if there's anything
                        :mr.looper.2                        // [left under the bed.
                            get.room.f(object, room);
                        if (room == rm.ego.bedroom)
                        {
                            set(stuff.under.bed);
                            object = size.of.inventory;
                        }
                        ++object;
                        if (object < size.of.inventory)
                        {
                            goto mr.looper.2;
                        }
                    }
                }
                else
                {
                    reset(stuff.under.bed);
                    work = inventory;
                    object = 1;                             // [Return everything that
                    : retrieve.inventory                    // [he hid under the bed.
                    get.room.f(object, room);
                    if (room == rm.ego.bedroom)
                    {
                        put.v(object, work);
                    }
                    ++object;
                    if (object < size.of.inventory)
                    {
                        goto retrieve.inventory;
                    }
                    #message 25  "Dropping to your knees, you reach under the bed and retrieve all of your possessions.";
                }
            }
        }
    }

    if (ego.location == 6)
    {
        set(keep.cycling);
        last.cel(ego, work);
        set.cel.v(ego, work);
        beginning.of.loop(ego, ego.arrived);
    }

    if (ego.location == 7)
    {
        ego.location = 10;
    }

    // [can't be an 8.  See "get out of bed" above.
    if (ego.location == 8)
    {
    }

    // [do the "get out of bed" schtick
    if (ego.location == 9)
    {
        set.view(ego, v.ego.leaving.bed);
        reposition.to(ego, 118, 130);
        set.cel(ego, 0);
        end.of.loop(ego, ego.arrived);
        set(keep.cycling);
        zzz's.timer = 0;
    }

    if (ego.location == 10)
    {
        ego.location = 0;
        player.control();
        accept.input();
        reset(handsOff);
        release.priority(ego);
        reset(keep.cycling);
        start.motion(ego);
        current.status = normal.ego;
        set.view(ego, v.ego);
        set.loop(ego, facing.left);
        reposition.to(ego, 111, 133);
        ego.cycle.time = 1;
        cycle.time(ego, ego.cycle.time);

        if (ego.in.bed)
        {
            reset(ego.in.bed);
            #message 28  "You gratefully rise from your hard old bed, stretching your aching muscles.";
        }
    }
}

if (current.status == sleeping)
{
    --zzz's.timer;
    if (zzz's.timer == 1)
    {
        set(keep.cycling);
        end.of.loop(ego, zzz's.done);
        sound(s.snoring, done);
        zzz's.timer = 22;
    }

    if (zzz's.done)
    {
        reset(zzz's.done);
        set.cel(ego, 0);
        reset(keep.cycling);
        stop.cycling(ego);
    }
}

if (ego.poofing.done)
{
    // [don't reset( ego.poofing.done);
    reset(keep.cycling);
    reset(no.cycling);
    reset(ignore.special);
    reset(ignore.water);
    if (door.locked && current.status != fly)
    {
        #message 30  "You suddenly find yourself in your own little room. You
                     "notice that the door is closed.";
    }
}

if (punishment.done)
{
    reset(punishment.done);
    reset(door.locked);
    #message 8  "You hear a CLICK at the bedroom door. The old wizard has decided
                "to free you by magically unlocking your door.";
}

if (door.locked)
{
    observe.blocks(ego);
}
else
{
    ignore.blocks(ego);
}

// [*****
// [exit              // [  test for leaving the room
// [*****

if (current.status != fly.landing)
{
    if (posn(ego, 11, 131, 12, 165)) { new.room(rm.hallway); }
    if (posn(ego, 47, 0, 69, 43)) { new.room(rm.tower); }
}

call(lgc.wiz.house);

















