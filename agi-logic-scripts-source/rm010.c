// [logics for room 10 -- rm.lab

#include  "rm10.msg"
#include  "gamedefs.al"
#include  "iv-names.h"

// [  The objects on the shelf are inventory objects only.  The burner must be
// [started here. It stays hot for 3 minutes. There are sight gags (funny
// [dead.ego.views) following death by formula screwup.

// [  Ego can get these objects here:  fish bone, nightshade juice, mandrake
// [root powder, toadstool powder, and toad spittle. There is a mortar and
// [pestle and a charcoal brazier to be used, but not taken.

// [  If Ego enters here while falling from room 9, he dies. Otherwise, falling
// [off the stairs just stuns him.

// [  They must be here to put anything in the cup.  The exception is the
// [ocean water, which can be put in the cup or the bowl in the ocean rooms.

#define  stairs        1                                    // [  ego.location values
#define  shelves        2
#define  table        3
#define  on.table        4

#define  hit.floor        lf0
#define  waiting.to.name.jar    lf1
#define  getFishBone      lf2
#define  getNightshade      lf3
#define  getMandrake      lf4
#define  getSpit        lf5
#define  getToadstool      lf6
#define  getSaffron      lf7
#define  on.stairs        lf8
#define  waiting.for.death    lf9
#define  sound.done      lf10

#define  death.delay      lv0
#define  stunned.seconds    lv1
#define  ego.timer        lv2

% object  aTorch1        1
% object  aTorch2        2

if (init.log)
{
    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    load.view(v.ego);
    map.area = map.wiz.house;
    set.horizon(40);
    landing.x = 58;
    landing.y = 124;
    wiz.x = 11;
    wiz.y = 54;

    cat.y = 0;
    load.logics(lgc.wiz.house);

    load.view(v.ego.stunned);
    load.view(v.ego.falling);
    load.view(v.torch.flame);

    load.sound(s.ego.stunned);
    load.sound(s.ego.falling);

    load.view(v.lab.stuff);
    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);
    add.to.pic(v.lab.stuff, 0, 0, 82, 141, 15, 4);
    add.to.pic(v.lab.stuff, 0, 1, 123, 140, 15, 4);
    add.to.pic(v.lab.stuff, 0, 2, 98, 133, 15, 4);
    add.to.pic(v.lab.stuff, 0, 3, 100, 144, 15, 4);
    discard.view(v.lab.stuff);

    animate.obj(aTorch1);
    ignore.horizon(aTorch1);
    ignore.blocks(aTorch1);
    ignore.objs(aTorch1);
    position(aTorch1, 49, 58);
    set.view(aTorch1, v.torch.flame);
    draw(aTorch1);

    animate.obj(aTorch2);
    ignore.horizon(aTorch2);
    ignore.blocks(aTorch2);
    ignore.objs(aTorch2);
    position(aTorch2, 115, 33);
    set.view(aTorch2, v.torch.flame);
    draw(aTorch2);

    if (current.status == fly)
    {
        set(positionEgo);
    }

    if (positionEgo)
    {
        // [  rm.spells)
        if (previous.room == 43)
        {
            if (!funny.death.view)
            {
                ego.location = table;
                position(ego, 104, 133);
                start.motion(ego);
            }
            else
            {
                set(waiting.for.death);
                load.view.v(funny.death.view);
                set.view.v(ego, funny.death.view);
                set.loop.v(ego, funny.death.loop);
                fix.loop(ego);
                if (funny.death.loop == 3)
                {
                    position(ego, 52, 143);
                }
                else
                {
                    position(ego, 57, 143);
                }
                set.priority(ego, 15);
                set(keep.cycling);
                program.control();
                stop.motion(ego);
                set(handsOff);
                draw(ego);
                death.delay = 5;
            }
        }
        else
        {
            // [  rm.lab.stairs)
            if (previous.room == 9)
            {
                if (current.status == falling)
                {
                    load.view(v.ego.dead);
                    ego.location = 0;
                    position(ego, 40, 42);
                    set(ignore.special);
                    set.view(ego, v.ego.falling);
                    ignore.blocks(ego);
                    move.obj(ego, 43, 135, 3, hit.floor);
                    set(keep.cycling);
                    set.priority(ego, 15);
                    sound(s.ego.falling, done);
                    draw(ego);
                }
                else
                {
                    set(on.stairs);
                    ignore.block(ego);
                    reset(ignore.special);
                    ego.location = stairs;
                    position(ego, 30, 42);
                }
            }
        }
    }

    if (current.status == deferred.entry)
    {
        position.v(ego, landing.x, landing.y);
        set(positionEgo);
    }

    if (drawEgo) { draw(ego); }

    call(lgc.wiz.house);

    show.pic();

    return();

}

// [*****
// [wear.da.fawgawee
// [*****

// [  the trip wire below stairs
if (hit.special && posn(ego, 35, 143, 55, 167))
{
    reset(hit.special);
    if (ego.dir == ego.left || ego.dir == ego.up.left || ego.dir == ego.down.left)
    {
        set(on.stairs);
        ignore.block(ego);
    }
    else
    {
        reset(on.stairs);
        observe.block(ego);
    }
}

if (waiting.for.death)
{
    set.priority(ego, 15);
    set(keep.cycling);
    ego.location = on.table;
}
else
{
    if (on.stairs)
    {
        ego.location = stairs;
        set.priority(ego, 14);
    }
    else
    {
        release.priority(ego);
        if (posn(ego, 92, 139, 119, 139))
        {
            ego.location = table;
        }
        else
        {
            if (posn(ego, 58, 90, 96, 109))
            {
                ego.location = shelves;
            }
            else
            {
                ego.location = 0;
            }
        }
    }
}

// [*****
// [handle.input
// [*****

if (!have.input) { goto no.input; }

// [  LET'S DO THE BOOK LARNIN' FIRST:
if (said(look, book) || said(read, book) || said(look, in, book))
{
    #message 69  "Covered with gold trimmings, the old book's leather cover is
                 "cracked and worn, its pages yellowedand brittle.The title, however, is
                 "clear : % m32.\"";
    #message 70  "You eagerly thumb through page after page of what you assume to be magic
                 "formulas.The ink of the old handwriting is faint, and barely readable.";
    #message 71  "Most of the formulas are indecipherable, but a few are in a language you
                 "know.You treat the old book with great care as you can tell it
                 "contains recipes for some very oldand powerful magic spells.
                 "Your hands shake as you realize this book
                 "could be the key to your escape from the evil Manannan.";
}

if (ego.location != table)
{
    if (said(book, anyword) ||
        said(anyword, book) ||
        said(book, anyword, anyword) ||
        said(anyword, book, anyword) ||
        said(anyword, anyword, book) ||
        said(open, book, page, anyword) ||
        said(open, book, page, anyword) ||
        said(turn, page, anyword) ||
        said(turn, page) ||
        said(open, book, page, anyword))
    {
        #message 10  "You can't reach the book from here.";
    }
}
else
{
    if (said(turn, page, ii) ||
        said(turn, book, page, ii) ||
        said(look, page, ii) ||
        said(read, page, ii) ||
        said(open, page, ii) ||
        said(open, book, page, ii))
    {
        spell.in.progress = 121;
    }

    if (said(turn, page, iv) ||
        said(turn, book, page, iv) ||
        said(look, page, iv) ||
        said(read, page, iv) ||
        said(open, page, iv) ||
        said(open, book, page, iv))
    {
        spell.in.progress = 122;
    }

    if (said(turn, page, vii) ||
        said(turn, book, page, vii) ||
        said(look, page, vii) ||
        said(read, page, vii) ||
        said(open, page, vii) ||
        said(open, book, page, vii))
    {
        spell.in.progress = 123;
    }

    if (said(turn, page, xiv) ||
        said(turn, book, page, xiv) ||
        said(look, page, xiv) ||
        said(read, page, xiv) ||
        said(open, page, xiv) ||
        said(open, book, page, xiv))
    {
        spell.in.progress = 124;
    }

    if (said(turn, page, xxv) ||
        said(turn, book, page, xxv) ||
        said(look, page, xxv) ||
        said(read, page, xxv) ||
        said(open, page, xxv) ||
        said(open, book, page, xxv))
    {
        spell.in.progress = 125;
    }

    if (said(turn, page, lxxxiv) ||
        said(turn, book, page, lxxxiv) ||
        said(look, page, lxxxiv) ||
        said(read, page, lxxxiv) ||
        said(open, page, lxxxiv) ||
        said(open, book, page, lxxxiv))
    {
        spell.in.progress = 126;
    }

    if (said(turn, page, clxix) ||
        said(turn, book, page, clxix) ||
        said(look, page, clxix) ||
        said(read, page, clxix) ||
        said(open, page, clxix) ||
        said(open, book, page, clxix))
    {
        spell.in.progress = 127;
    }

    if (said(turn, page, rol) ||
        said(turn, book, page, rol) ||
        said(look, page, rol) ||
        said(read, page, rol) ||
        said(turn, page, book, rol) ||
        said(open, book, page, rol) ||
        said(open, page, rol) ||
        said(read, page, rol))
    {
        #message 2  "Not being an experienced sorcerer, most spells in this book are too
                    complicated for you to understand.";
    }
}



// [  GENERIC SAID STUFF:

if (said(look, room) ||
    said(look, house) ||
    said(look) ||
    said(look, lab))
{
    #message 4  "You look in awe around this torch-lit underground room. It appears to
                "be a laboratory... a \"wizard's\" laboratory.";
    #message 34  "Against the earthen walls there are rows of shelves holding numerous jars
                 "which contain strange, unknown ingredients.";
    #message 6  "The shelves also hold skeletons of small animals and birds, some human
                "skulls and bones, and other odd instruments, whose use you do not know.
                "% m8% m7";
}

if (said(look, table) || said(look, top, table) || said(look, table, top))
{
    if (posn(ego, 77, 95, 128, 120))
    {
        #message 20  "The wizard's desk is curiously empty. You have no further interest in it.";
    }
    else
    {
        #message 9  "%m8 Atop the oak table are a large leather-bound book, a mortar and
                    "pestle, a little brazier holding charcoal, and a flint, plus
                    "measuring cups, beakers, flasks, and stirrers.";
    }
}

if (said(look, under, table))
{
    #message 11  "You lean down and peek under the table. You see nothing but an earthen floor.";
}

if (said(look, stairs) || said(look, up, stairs))
{
    #message 7  "The narrow stone steps lead up to the wizard's study.";
}

if (said(get, flint))
{
    #message 13  "The flint%m52";
}

if (said(look, flint))
{
    #message 25  "The flint is used for lighting the brazier.";
}

if (said(look, flask))
{
    #message 65  "There are many measuring, stirring, and mixing implements on the laboratory table.";
}

if (said(get, flask))
{
    #message 72  "You consider taking it, but decide there is no need to carry it%m38";
}

if (said(get, charcoal))
{
    #message 24  "The charcoal%m52";
}

if (said(look, torch))
{
    #message 14  "The burning torches throw flickering shadows across the walls,
                  making the room even more ominous.";
}

if (said(look, shelf))
{
    #message 16  "You curiously gaze at the strange jars of ingredients,"
                 "the animal and human bones, and other odd implements which"
                 "line the rows of shelves."
                 "You see jars of ingredients resting on labeled shelves... shelves"
                 "bearing such ghastly names as \"Powdered Fish Bone,\" \"Nightshade Juice,\""
                 "\"Mandrake Root Powder,\" \"Saffron,\" \"Toad Spittle,\" and"
                 "\"Toadstool Powder.\"";
}

if (said(close, book))
{
    #message 46  "The wizard would notice if the book were closed.";
}

if (said(open, book))
{
    #message 44  "It's already open.";
}

if (said(get, book))
{
    if (wiz.status != dead)
    {
        #message 22  "Manannan would be very suspicious if he were to discover %m32\" missing.";
    }
    else
    {
        #message 65  "There are many measuring, stirring, and mixing implements on the laboratory table.";
    }
}

if (said(make, magic) ||
    said(do, magic) ||
    said(mix, magic) ||
    said(make, magic, spell) ||
    said(do, magic, spell) ||
    said(mix, magic, spell))
{
    #message 68  "You must open %m32\" to the proper page to read the instructions for a magic spell.";
}

if (said(look, flask) ||
    said(look$in, flask) ||
    said(open, flask) ||
    said(get, lid, off, flask) ||
    said(take, lid, from, flask) ||
    said(take, lid, flask))
{
    #message 21  "You have no flask.";
}

if (said(look, equipment))
{
    #message 23  "There is much equipment here: a mortar and pestle, a charcoal brazier
                  and flint, measuring cups, beakers, flasks, stirrers,
                  and many jarsand vials of strange ingredients.";
}


// [  YOUR BASIC "GET THE WORLD" SECTION:

if (said(get, fish$oil))
{
    #message 1  "Where?";
}

if (said(get, torch) ||
    said(get, torch, off, wall) ||
    said(get, torch, wall) ||
    said(get, torch, anyword, wall))
{
    #message 15  "The torches are firmly attached to the earthen wall. You cannot loosen them.";
}


if (waiting.to.name.jar)
{
    reset(waiting.to.name.jar);

    if (said(fishbone, rol) || said(bone, rol))
    {
        set(getFishBone);
    }

    if (said(nightshade, juice) || said(nightshade))
    {
        set(getNightshade);
    }

    if (said(mandrake, root, powder) || said(mandrake, powder) || said(mandrake) || said(mandrake, root))
    {
        set(getMandrake);
    }

    if (said(saffron) || said(saffron, powder))
    {
        set(getSaffron);
    }

    if (said(toad, spit) || said(toad) || said(spit))
    {
        set(getSpit);
    }

    if (said(toadstool, powder) || said(toadstool))
    {
        set(getToadstool);
    }

}

if (said(anyword, torch))
{
    #message 26  "The torches will not help you.";
}

if ((said(get, jar, powder, from, shelf) ||
    said(get, jar, from, shelf) ||
    said(get, jar, shelf) ||
    said(get, jar) ||
    said(get, powder) ||
    said(get, powder, shelf) ||
    said(get, powder, from, shelf)))
{
    if (ego.location != shelves)
    {
        #message 17  "You can't reach it from here.";
    }
    else
    {
        if ((obj.in.room(i.fish.bone, current.room) ||
            obj.in.room(i.nightshade.juice, current.room) ||
            obj.in.room(i.mandrake.root, current.room) ||
            obj.in.room(i.toad.spit, current.room) ||
            obj.in.room(i.saffron, current.room) ||
            obj.in.room(i.toadstool.powder, current.room)))
        {
            #message 27  "There are many jars of ingredients on the laboratory shelves. Which
                         "do you want ? ";
            set(waiting.to.name.jar);
        }
        else
        {
            #message 28  "You already have all the jars of ingredients you are likely to need. You
                         "have no interest in any other.";
        }
    }
}

if ((said(get, fishbone, rol) ||
    said(get, jar, fishbone, rol) ||
    said(get, jar, fishbone) ||
    said(get, fishbone, jar, rol)))
{
    if (ego.location != shelves)
    {
        #message 17  "You can't reach it from here.";
    }
    else
    {
        set(getFishBone);
    }
}

if (said(get, juice) ||
    said(get, nightshade, juice) ||
    said(get, juice, shelf) ||
    said(get, nightshade, juice, shelf) ||
    said(get, juice, from, shelf) ||
    said(get, jar, juice, from, shelf) ||
    said(get, nightshade, juice, from, shelf) ||
    said(get, jar, nightshade, juice, shelf) ||
    said(get, jar, nightshade, juice) ||
    said(get, jar, nightshade, juice, from, shelf) ||
    said(get, nightshade, juice, jar, shelf) ||
    said(get, nightshade, juice, jar, from, shelf))
{
    if (ego.location != shelves)
    {
        #message 17  "You can't reach it from here.";
    }
    else
    {
        set(getNightshade);
    }
}

if (said(get, mandrake, powder) ||
    said(get, mandrake, powder, shelf) ||
    said(get, mandrake, powder, from, shelf) ||
    said(get, mandrake, powder, jar, shelf) ||
    said(get, mandrake, powder, jar, from, shelf) ||
    said(get, jar, mandrake, powder, shelf) ||
    said(get, jar, mandrake, powder, from, shelf) ||
    said(get, mandrake) ||
    said(get, mandrake, root, powder) ||
    said(get, mandrake, root, powder, shelf) ||
    said(get, mandrake, root, powder, from, shelf) ||
    said(get, mandrake, root, powder, jar, shelf) ||
    said(get, mandrake, root, powder, jar, from, shelf) ||
    said(get, jar, mandrake, root) ||
    said(get, jar, mandrake, root, powder) ||
    said(get, jar, mandrake, root, powder, shelf) ||
    said(get, jar, mandrake, root, powder, from, shelf))
{
    if (ego.location != shelves)
    {
        #message 17  "You can't reach it from here.";
    }
    else
    {
        set(getMandrake);
    }
}

if (said(get, saffron) ||
    said(get, saffron, shelf) ||
    said(get, saffron, from, shelf) ||
    said(get, saffron, jar, shelf) ||
    said(get, saffron, jar, from, shelf) ||
    said(get, jar, saffron, shelf) ||
    said(get, jar, saffron, from, shelf) ||
    said(get, jar, saffron) ||
    said(get, jar, saffron, shelf) ||
    said(get, jar, saffron, from, shelf))
{
    if (ego.location != shelves)
    {
        #message 17  "You can't reach it from here.";
    }
    else
    {
        set(getSaffron);
    }
}

if (said(get, toadstool, powder) ||
    said(get, toadstool) ||
    said(get, toadstool, powder, shelf) ||
    said(get, jar, toadstool, powder, shelf) ||
    said(get, toadstool, powder, from, shelf) ||
    said(get, jar, toadstool, powder, from, shelf) ||
    said(get, jar, toadstool, powder) ||
    said(get, jar, toadstool, powder, shelf) ||
    said(get, toadstool, powder, jar, shelf) ||
    said(get, toadstool, powder, jar, from, shelf))
{
    if (ego.location != shelves)
    {
        #message 17  "You can't reach it from here.";
    }
    else
    {
        set(getToadstool);
    }
}

if (said(get, jar, spit, from, shelf) ||
    said(get, spit) ||
    said(get, toad, spit) ||
    said(get, spit, shelf) ||
    said(get, spit, from, shelf) ||
    said(get, toad, spit) ||
    said(get, toad, spit, shelf) ||
    said(get, toad, spit, from, shelf) ||
    said(get, jar, toad, spit, from, shelf) ||
    said(get, jar, toad, spit, shelf) ||
    said(get, jar, toad, spit) ||
    said(get, toad, spit, jar, from, shelf) ||
    said(get, toad, spit, jar, shelf) ||
    said(get, jar, toad, spit, shelf) ||
    said(get, jar, toad, spit, from, shelf) ||
    said(get, toad, spit, jar, from, shelf))
{
    if (ego.location != shelves)
    {
        #message 17  "You can't reach it from here.";
    }
    else
    {
        set(getSpit);
    }
}

// [  MORTAR AND PESTLE STUFF:

if (said(get, pestle) ||
    said(get, pestle, from, table) ||
    said(get, pestle, off, table))
{
    #message 39  "%m36mortar and pestle%m38";
}

if (said(look, pestle) ||
    said(look, pestle, table) ||
    said(look$in, pestle))
{
    if (ego.location != table)
    {
        #message 47  "You are not close enough.";
    }
    else
    {
        #message 41  "The mortar is a bowl-shaped implement made of stone. The pestle is a
                     "rounded stone that fits into the mortar.The mortar and pestle are used
                     "for grinding things into a powder.They are resting on the oak table.";
    }
}

if (said(use, pestle))
{
    if (ego.location != table)
    {
        #message 17  "You can't reach it from here.";
    }
    else
    {
        #message 42  "What would you do with the mortar and pestle?";
    }
}

if ((said(grind, anyword, pestle) ||
    said(put, anyword, pestle)))
{
    if (ego.location != table)
    {
        #message 17  "You can't reach it from here.";
    }
    else
    {
        #message 50  "You consider doing that, but then realize it wouldn't work.";
    }
}

// [  LET'S DO THE CHARCOAL BURNER NEXT:

if ((said(get, brazier) ||
    said(get, brazier, from, table) ||
    said(get, brazier, off, table) ||
    said(get, charcoal, brazier) ||
    said(get, charcoal, brazier, from, table) ||
    said(get, charcoal, brazier, off, table)))
{
    #message 40  "%m36charcoal brazier%m38";
}

if (said(use, burner) || said(use, charcoal, burner))
{
    if (ego.location != table)
    {
        #message 17  "You can't reach it from here.";
    }
    else
    {
        #message 45  "What would you do with the brazier?";
    }
}

if (said(light, burner) || said(light, charcoal, burner) || said(light, charcoal))
{
    if (ego.location != table)
    {
        #message 17  "You can't reach it from here.";
    }
    else
    {
        if ((burner.seconds || burner.minutes))
        {
            #message 56  "It is already burning.";
        }
        else
        {
            #message 48  "You fill the brazier with charcoal from the small supply
                         "Manannan keeps here and strike the flint on it.Soon, the brazier burns hotly.";
            burner.minutes = burner.init.minutes;
        }
    }
}

if (said(put, anyword, on, burner) ||
    said(put, anyword, on, top, burner) ||
    said(heat, anyword, on, burner) ||
    said(heat, anyword, on, top, burner) ||
    said(put, anyword, on, burner, heat) ||
    said(put, anyword, on, top, burner, heat) ||
    said(put, anyword, on, charcoal, burner) ||
    said(put, anyword, on, top, charcoal, burner) ||
    said(heat, anyword, on, charcoal, burner) ||
    said(heat, anyword, on, top, charcoal, burner) ||
    said(put, anyword, on, charcoal, burner, heat) ||
    said(put, anyword, on, top, charcoal, burner, heat))
{
    if (ego.location != table)
    {
        #message 17  "You can't reach it from here.";
    }
    else
    {
        #message 5  "%m50 Now is not the proper time.";
    }
}

if (said(look, burner) ||
    said(look, burner, table) ||
    said(look$in, burner) ||
    said(look, charcoal, burner) ||
    said(look, charcoal, burner, table) ||
    said(look$in, charcoal, burner))
{
    if (ego.location != table)
    {
        #message 47  "You are not close enough.";
    }
    else
    {
        #message 43  "Resting on the table is a small metal brazier.
                     "It holds charcoal and is used for heating or cooking things.";
        if (burner.seconds || burner.minutes)
        {
            #message 51  "%m54 You could heat things quickly with the brazier, right now.";
        }
        else
        {
            #message 53  "%m66stone cold.";
        }
    }
}

if (said(get, charcoal) || said(get, charcoal, from, burner))
{
    if (ego.location != table)
    {
        #message 17  "You can't reach it from here.";
    }
    else
    {
        #message 49  "The charcoal";
    }
}

if (said(look, charcoal))
{
    if (ego.location != table)
    {
        #message 47  "You are not close enough.";
    }
    else
    {
        if ((burner.seconds || burner.minutes))
        {
            #message 54  "%m66very hot!";
        }
        else
        {
            #message 53  "%m66stone cold.";
        }
    }
}


// [*****
// :n
// [*****

if (aSecondPassed && burner.seconds == 1 && !burner.minutes)
{
    #message 55  "The brazier has burned all the charcoal, and is now cool.";
}

if (getFishBone)
{
    reset(waiting.to.name.jar);
    reset(getFishBone);
    if (obj.in.room(i.fish.bone, current.room))
    {
        #message 29  "%m3labeled \"Powdered Fish Bone\"%m12";
        get(i.fish.bone);
        score += 1;
    }
    else
    {
        if (has(i.fish.bone))
        {
            #message 67  "You already have it.";
        }
        else
        {
            #message 19  "You already took it.";
        }
    }
}

if (getNightshade)
{
    reset(waiting.to.name.jar);
    reset(getNightshade);
    if (obj.in.room(i.nightshade.juice, current.room))
    {
        #message 31  "%m3of \"Nightshade Juice\"%m12";
        get(i.nightshade.juice);
        score += 1;
    }
    else
    {
        if (has(i.nightshade.juice))
        {
            #message 67  "You already have it.";
        }
        else
        {
            #message 19  "You already took it.";
        }
    }
}

if (getMandrake)
{
    reset(waiting.to.name.jar);
    reset(getMandrake);
    if (obj.in.room(i.mandrake.root, current.room))
    {
        #message 33  "%m3labeled \"Mandrake Root Powder\"%m12";
        get(i.mandrake.root);
        score += 1;
    }
    else
    {
        if (has(i.mandrake.root))
        {
            #message 67  "You already have it.";
        }
        else
        {
            #message 19  "You already took it.";
        }
    }
}

if (getSaffron)
{
    reset(waiting.to.name.jar);
    reset(getSaffron);
    if (obj.in.room(i.saffron, current.room))
    {
        #message 18  "%m3labeled \"Saffron\"%m12";
        get(i.saffron);
        score += 1;
    }
    else
    {
        if (has(i.saffron))
        {
            #message 67  "You already have it.";
        }
        else
        {
            #message 19  "You already took it.";
        }
    }
}

if (getSpit)
{
    reset(waiting.to.name.jar);
    reset(getSpit);
    if (obj.in.room(i.toad.spit, current.room))
    {
        #message 37  "%m3labeled \"Toad Spittle\"%m12";
        get(i.toad.spit);
        score += 1;
    }
    else
    {
        if (has(i.toad.spit))
        {
            #message 67  "You already have it.";
        }
        else
        {
            #message 19  "You already took it.";
        }
    }
}

if (getToadstool)
{
    reset(waiting.to.name.jar);
    reset(getToadstool);
    if (obj.in.room(i.toadstool.powder, current.room))
    {
        #message 35  "%m3of \"Toadstool Powder\"%m12";
        get(i.toadstool.powder);
        score += 1;
    }
    else
    {
        if (has(i.toadstool.powder))
        {
            #message 67  "You already have it.";
        }
        else
        {
            #message 19  "You already took it.";
        }
    }
}

if (hit.special)
{
    if (ego.location == stairs)
    {
        set(ignore.special);
        set.view(ego, v.ego.falling);
        ignore.blocks(ego);
        move.obj(ego, 43, 135, 3, hit.floor);
        set(keep.cycling);
        set.priority(ego, 15);
        sound(s.ego.falling, done);
        program.control();
    }
}

if (hit.floor)
{
    reset(hit.floor);

    if (current.status == falling)                          // [  only if fell.from.rm9
    {
        set.view(ego, v.ego.dead);
        reset(keep.cycling);
        stop.cycling(ego);
        set(certain.death);
    }
    else
    {
        set.view(ego, v.ego.stunned);
        stop.motion(ego);
        work = 0;
        step.size(ego, work);
        stop.sound();
        stunned.seconds = ego.stunned.time;
        current.status = stunned;
        set(sound.done);
    }
}

if (aSecondPassed)
{
    --stunned.seconds;
    if (stunned.seconds == 1)
    {
        player.control();
        accept.input();
        reset(handsOff);
        reset(keep.cycling);
        reset(sound.done);
        stop.sound();
        start.motion(ego);
        current.status = normal.ego;
        set.view(ego, v.ego);

        work = 1;
        step.size(ego, work);
        reset(ignore.special);
        observe.blocks(ego);
        release.priority(ego);
        reset(on.stairs);
    }
}

if (sound.done && current.status == stunned)
{
    sound(s.ego.stunned, sound.done);
}

if (aSecondPassed)
{
    --death.delay;
    if (waiting.for.death&& death.delay == 1)
    {
        set(certain.death);
        start.cycling(ego);

                                                            // [  THE FOLLOWING ARE PRINTED FROM A CALCULATED VALUE;
                                                            // [DON'T MUCK WITH THEIR NUMBERS!
                                                            // [57  v.gag.dead.ego.1  38a    big ears
                                                            // [          38b    fly eyes
                                                            // [          38c    poofing
                                                            // [          38d    sleeping ego
                                                            // [61  v.gag.dead.ego.2  39a    cat
                                                            // [          39b    storm
                                                            // [          39c    invisible

        if (funny.death.view == 38)
        {
            message = 57;
        }
        else
        {
            message = 61;
        }
        message += funny.death.loop;
        print.v(message);
        if (message == 60)
        {
            work = 3;
            cycle.time(ego, work);                          // [  slow down his breathing
        }
    }
}

// [*****
// [exit              // [  test for leaving the room
// [*****

if (current.status != fly.landing)
{
    if (edge.ego.hit == top && current.status == fly && ego.x > 46 && ego.x < 75) {
      new.room(9);
    }
    if (edge.ego.hit == top) {
      new.room(9);
    }
}

if (spell.in.progress)
{
    #message 30  "With trembling hands you turn the pages of %m32,\" and
                 "prepare to follow its instructions precisely.";
    // [  rm.spells);
    new.room(43);
}

call(lgc.wiz.house);














