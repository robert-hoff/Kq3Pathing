// [logics for room 124 -- Spell 4.  Putting others into a deep sleep.

#include  "rm124.msg"
#include  "gamedefs.al"
#include  "colors.h"
#include  "iv-names.h"

// [  Oops is set upon every input.  If the entry is correct, it's reset.
// [Spell.status is ++ every input.  Some questionable entries --spell.status,
// [to give him a "free round."

#define  overlay.pic.text.window  143

#define  ready.for.grinding    1
#define  ready.for.acorns    2
#define  ready.for.juice    3
#define  ready.for.mixing    4
#define  ready.for.boiling    5
#define  ready.for.drying    6
#define  ready.for.spell    7
#define  ready.for.wand      8
#define  ready.for.pouch    9
#define  times.up        10

#define  text.window      dv1

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

if ((said(grind, acorns, mortar) ||
    said(grind, three, acorns, mortar)))
{
    if (!has(i.acorns))
    {
        #message 1  "How can you use that which you do not have?";
    }
    else
    {
        if (spell.status == ready.for.grinding)
        {
            #message 9  "Putting the dried acorns into the stone mortar, you use the
pestle to grind them into a rough acorn powder.";
            drop(i.acorns);
            reset(oops);
        }
        else
        {
            reset(have.match);
        }
    }
}

if ((said(put, acorn, powder, bowl) ||
    said(pour, acorn, powder, bowl)))
{
    if (!has(i.bowl))
    {
        #message 25  "You don't have a bowl.";
    }
    else
    {
        if (spell.status == ready.for.acorns)
        {
            #message 10  "Turning the heavy stone mortar upside down, you carefully
pour the acorn powder into the bowl, then return the mortar to the table.";
            reset(oops);
        }
        else
        {
            reset(have.match);
        }
    }
}

if ((said(put, cup, nightshade, bowl) ||
    said(put, cup, nightshade, juice, bowl) ||
    said(put, one, cup, nightshade, juice, bowl) ||
    said(put, one, cup, nightshade, bowl) ||
    said(put, nightshade, bowl) ||
    said(put, nightshade, juice, bowl) ||
    said(pour, cup, juice, bowl) ||
    said(pour, cup, nightshade, bowl) ||
    said(pour, cup, nightshade, juice, bowl) ||
    said(pour, one, cup, nightshade, juice, bowl) ||
    said(pour, one, cup, nightshade, bowl) ||
    said(pour, nightshade, juice, bowl)))
{
    if (!has(i.nightshade.juice))
    {
        #message 1  "How can you use that which you do not have?";
    }
    else
    {
        if (spell.status == ready.for.juice)
        {
            #message 11  "You very carefully pour a cupful of nightshade juice into
the clay bowl so as to not to spill a single drop.";
            #message 12  "There is now an ugly, brown, mealy, liquid mixture in the bowl.";
            drop(i.nightshade.juice);
            reset(oops);
        }
        else
        {
            reset(have.match);
        }
    }
}

if ((said(mix, mixture, spoon) ||
    said(mix, with, spoon) ||
    said(mix, mixture, with, spoon) ||
    said(mix, mixture)))
{
    if (spell.status == ready.for.mixing)
    {
        #message 15  "You gently stir the unappetizing liquid.";
        reset(oops);
    }
    else
    {
        reset(have.match);
    }
}

if ((said(heat, mixture, burner) ||
    said(heat, mixture, over, burner) ||
    said(heat, mixture, on, burner) ||
    said(heat, bowl, on, burner) ||
    said(heat, bowl, burner) ||
    said(heat, bowl, over, burner) ||
    said(put, bowl, burner) ||
    said(put, bowl, over, burner) ||
    said(put, bowl, on, burner) ||
    said(put, bowl, on, burner, heat)))
{
    if (!has(i.bowl))
    {
        #message 1  "How can you use that which you do not have?";
    }
    else
    {
        #message 16  "You gingerly place the clay bowl of ugly brown liquid on the charcoal
brazier.";

        if (!burner.seconds && !burner.minutes)
        {
            #message 17  "How you wish you had lit the burner!";
        }
        else
        {
            if (spell.status == ready.for.boiling)
            {
                #message 18  "Soon, the hot brazier brings the mixture to a bubble, then a boil, releasing
a bitter smelling steam.";
                #message 19  "You let it boil until the nightshade juice is
nearly gone, then remove it from the brazier.";
                reset(oops);
            }
            else
            {
                reset(have.match);
            }
        }
    }
}

if ((said(spread, mixture, table) ||
    said(spread, mixture, on, table)))
{
    if (spell.status == ready.for.drying)
    {
        #message 20  "You pour the bowl's contents onto the oaken table,
then spread the hot sticky mixture over the table top.In
a few minutes, it has dried to a very crumbly, coarse sleeping powder.";
        reset(oops);
        ++spell.status;                                     // [  bring on the poem
    }
    else
    {
        reset(have.match);
    }
}

if (said(get, sleep, powder))
{
    if (spell.status == ready.for.pouch)
    {
        #message 23  "You try to pick up the sleep powder and drop it all over the laboratory
floor, where it mixes into the dirt.How you wish you had brought a pouch
in which to carry it!";
    }
    else
    {
        reset(have.match);
    }
}

if ((said(put, sleep, powder, pouch) ||
    said(pour, sleep, powder, pouch)))
{
    if (!has(i.empty.pouch))
    {
        #message 1  "How can you use that which you do not have?";
    }
    else
    {
        if (spell.status == ready.for.pouch)
        {
            #message 22  "You untie the small leather pouch, scoop the powder from the
table, and place it within.You now have a pouch full of sleep powder.";
            reset(oops);
            drop(i.empty.pouch);
            get(i.sleep.powder);
        }
        else
        {
            reset(have.match);
        }
    }
}

if ((said(wave, wand) ||
    said(wave, magic, wand)))
{
    if (!has(i.magic.wand))
    {
        #message 1  "How can you use that which you do not have?";
        drop(i.sleep.powder);
    }
    else
    {
        if (spell.status == ready.for.wand)
        {
            #message 8  "You pass the magic wand over the table.";
            reset(oops);
        }
        else
        {
            drop(i.sleep.powder);
            reset(have.match);
        }
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
    set.string(1, 6);                                       // [  " " default blank string
    if (poem.line.count == 0)
    {
        overlay.pic(text.window);                           // [  pic.143 = overlay text box
        show.pic();
        set.string(2, 2);
        if (monitor.type == mono)
        {
            open.dialogue();
            get.string(1, 6, 15, 1, 28);
                                                            // [string#, prompt, row, col, max length
        }
        else
        {
            get.string(1, 6, 13, 1, 28);
        }

        if (compare.strings(1, 2))
        {
            reset(oops);
        }
    }

    if (poem.line.count == 1)
    {
        set.string(2, 3);
        if (monitor.type == mono)
        {
            get.string(1, 6, 16, 1, 35);
                                                            // [string#, prompt, row, col, max length
        }
        else
        {
            get.string(1, 6, 14, 1, 35);
        }

        if (compare.strings(1, 2))
        {
            reset(oops);
        }
    }

    if (poem.line.count == 2)
    {
        set.string(2, 4);
        if (monitor.type == mono)
        {
            get.string(1, 6, 17, 1, 31);
                                                            // [string#, prompt, row, col, max length
        }
        else
        {
            get.string(1, 6, 15, 1, 31);
        }

        if (compare.strings(1, 2))
        {
            reset(oops);
        }
    }

    if (poem.line.count == 3)
    {
        set.string(2, 5);
        if (monitor.type == mono)
        {
            get.string(1, 6, 18, 1, 27);
                                                            // [string#, prompt, row, col, max length
        }
        else
        {
            get.string(1, 6, 16, 1, 27);
        }

        if (compare.strings(1, 2))
        {
            reset(oops);
        }
    }
    set.text.attribute(text.color, bg.color);
    ++poem.line.count;
    set.string(1, 6);                                       // [  " " default blank string
    set.string(2, 6);                                       // [  " " default blank string

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
// :n
// [*****

// [*****
: exit
// [*****

work = spell.status;
++work;
if (work == times.up && !oops)
{
    spell.status = spell.done;
}

if (oops)
{
    funny.death.view = 38;                                  // [  view number of gag death
    funny.death.loop = 3;                                   // [  loop number of gag death
}

