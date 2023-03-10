// [logics for room 127 -- Spell Seven:  Invisibility Ointment.

#include  "rm127.msg"
#include  "gamedefs.al"
#include  "colors.h"
#include  "iv-names.h"

// [  Oops is set upon every input.  If the entry is correct, it's reset.
// [Spell.status is ++ every input.  Some questionable entries --spell.status,
// [to give him a "free round."

#define  overlay.pic.text.window    143

#define  ready.for.cutting.cactus    1
#define  ready.for.squeezing.cactus  2
#define  ready.for.cactus.juice    3
#define  ready.for.lard        4
#define  ready.for.spit        5
#define  ready.for.mixing      6
#define  ready.for.spell      7
#define  ready.for.wand        8
#define  ready.for.jar        9
#define  times.up          10

#define  text.window        dv0

if (init.log)
{
    text.window = overlay.pic.text.window;
    return();
}

// [*****
// :h
// [*****

if ((!have.input || have.match)) { goto spell.input; }

set(oops);
++spell.status;

if (said(cut, cactus, with, knife) || said(cut, open, cactus, with, knife))
{
    if (!has(i.cactus) || !has(i.knife))
    {
        #message 1  "How can you use that which you do not have?";
    }
    else
    {
        #message 11  "Using your kitchen carving knife, you cut a gash in the small cactus.
Juice begins to drip.";
        if (spell.status == ready.for.cutting.cactus)
        {
            reset(oops);
        }
    }
}

if ((said(squeeze, cactus, juice, on, spoon) ||
    said(squeeze, cactus, on, spoon) ||
    said(squeeze, cactus, juice, spoon) ||
    said(squeeze, cactus, spoon)))
{
    if (!has(i.cactus))
    {
        #message 1  "How can you use that which you do not have?";
    }
    else
    {
        #message 12  "Grabbing one of the measuring spoons from the oaken table, you
grasp the slit cactus in your hand, and squeeze it
until you have a spoonful of cactus juice.The small
cactus is quite devoid of liquid now, so you toss it away.";
        drop(i.cactus);
        if (spell.status == ready.for.squeezing.cactus)
        {
            reset(oops);
        }
    }
}

if ((said(put, one, spoon, cactus, juice, bowl) ||
    said(put, spoon, cactus, juice, bowl) ||
    said(put, cactus, juice, bowl) ||
    said(pour, one, spoon, cactus, juice, bowl) ||
    said(pour, spoon, cactus, juice, bowl) ||
    said(pour, cactus, juice, bowl)))
{
    if (!has(i.bowl))
    {
        #message 1  "How can you use that which you do not have?";
    }
    else
    {
        #message 14  "You carefully add the spoonful of cactus juice to the bowl.";
        if (spell.status == ready.for.cactus.juice)
        {
            reset(oops);
        }
    }
}

if ((said(put, one, cup, lard, bowl) ||
    said(put, cup, lard, bowl) ||
    said(put, lard, bowl) ||
    said(put, one, cup, lard, bowl)))
{
    if (!has(i.lard))
    {
        #message 1  "How can you use that which you do not have?";
    }
    else
    {
        #message 13  "You scrape the lard into the mixing bowl, and keep the now-empty jar
nearby to store your finished formula.";
        drop(i.lard);
        get(i.lard.jar);
        if (spell.status == ready.for.lard)
        {
            reset(oops);
        }
    }
}

if ((said(put, two, drops, toad, spit, bowl) ||
    said(add, two, drops, toad, spit) ||
    said(put, toad, spit, bowl) ||
    said(add, toad, spit, bowl) ||
    said(put, toad, spit)))
{
    if (!has(i.toad.spit))
    {
        #message 1  "How can you use that which you do not have?";
    }
    else
    {
        #message 15  "You cautiously pour the two drops of toad spittle into the bowl.";
        drop(i.toad.spit);
        if (spell.status == ready.for.spit)
        {
            reset(oops);
        }
    }
}

if ((said(mix, mixture, spoon) ||
    said(mix, mixture, with, spoon) ||
    said(mix, bowl, with, spoon) ||
    said(mix, spoon) ||
    said(use, spoon, mix, mixture) ||
    said(use, spoon, mix) ||
    said(use, spoon, mix, bowl)))
{
    #message 16  "Using one of the stirrers lying on the table,
you mix the lard, cactus juice, and toad spittle
until it is smoothand blended.";
    if (spell.status == ready.for.mixing)
    {
        reset(oops);
        ++spell.status;                                     // [  ready for spell now
    }
}

if ((said(wave, wand) ||
    said(wave, magic, wand)))
{
    if (!has(i.magic.wand))
    {
        #message 1  "How can you use that which you do not have?";
    }
    else
    {
        #message 17  "You wave the magic wand.";
        if (spell.status == ready.for.wand)
        {
            reset(oops);
        }
    }
}

if ((said(return, ointment, jar) ||
    said(return, ointment, empty, jar) ||
    said(return, ointment, back, jar) ||
    said(return, ointment, empty, lard, jar)))
{
    if (spell.status == ready.for.jar)
    {
        #message 18  "You scoop the invisibility ointment out of the clay bowl and
return it to the lard jar.";
        drop(i.lard.jar);
        get(i.invisible.ointment);
        reset(oops);
    }
}

// [*****
// :s
// [*****

if (!oops &&
    poem.line.count < 4 &&
    spell.status == ready.for.spell)
{
    set(oops);
    prevent.input();
    set.text.attribute(black, light.white);
    set.string(1, 2);                                       // [  " " default blank string
    if (poem.line.count == 0)
    {
        overlay.pic(text.window);                           // [  pic.143 = overlay text box
        show.pic();
        set.string(2, 4);
        if (monitor.type == mono)
        {
            open.dialogue();
            get.string(1, 2, 15, 1, 28);
                                                            // [string#, prompt, row, col, max length
        }
        else
        {
            get.string(1, 2, 13, 1, 28);
        }

        if (compare.strings(1, 2))
        {
            reset(oops);
        }
    }

    if (poem.line.count == 1)
    {
        set.string(2, 5);
        if (monitor.type == mono)
        {
            get.string(1, 2, 16, 1, 34);
                                                            // [string#, prompt, row, col, max length
        }
        else
        {
            get.string(1, 2, 14, 1, 34);
        }

        if (compare.strings(1, 2))
        {
            reset(oops);
        }
    }

    if (poem.line.count == 2)
    {
        set.string(2, 6);
        if (monitor.type == mono)
        {
            get.string(1, 2, 17, 1, 34);
                                                            // [string#, prompt, row, col, max length
        }
        else
        {
            get.string(1, 2, 15, 1, 34);
        }

        if (compare.strings(1, 2))
        {
            reset(oops);
        }
    }

    if (poem.line.count == 3)
    {
        set.string(2, 7);
        if (monitor.type == mono)
        {
            get.string(1, 2, 18, 1, 29);
                                                            // [string#, prompt, row, col, max length
        }
        else
        {
            get.string(1, 2, 16, 1, 29);
        }

        if (compare.strings(1, 2))
        {
            reset(oops);
        }
    }
    set.text.attribute(text.color, bg.color);
    ++poem.line.count;
    set.string(1, 2);                                       // [  " " default blank string
    set.string(2, 2);                                       // [  " " default blank string

    if ((oops || poem.line.count == 4))
    {
        if (monitor.type == mono)
        {
            close.dialogue();
        }

        draw.pic(current.room);
        show.pic();
        accept.input();
    }
}

// [*****
// :e
// [*****

work = spell.status;
++work;
if (work == times.up && !oops)
{
    spell.status = spell.done;
}

if (oops)
{
    funny.death.view = 39;                                  // [  view number of gag death
    funny.death.loop = 2;                                   // [  loop number of gag death
}

