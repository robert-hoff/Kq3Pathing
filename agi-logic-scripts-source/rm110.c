// [logics for room 110 -- lgc.stream.mud

#include "gamedefs.al"
#include "rm110.msg"

// [  Used by rooms 13, 14 & 19.

if (init.log)
{
    return();
}

if (!handsOff)
{
    if (on.water && !ignore.water && waterView != wading)
    {
        set.view(ego, v.ego.wading.shallow);
        waterView = wadingShallow;
    }

    if (!on.water && waterView != normal.ego)
    {
        set.view(ego, v.ego);
        waterView = normal.ego;
    }
}

if (!have.input) { goto exit; }

if ((said(look) ||
    said(look, ground)))
{
    #message 1  "There is a rushing stream flowing through the forest floor.";
}

if ((said(look, stream) ||
    said(look, water)))
{
    #message 3  "Clear water flows over and
around the rocks of the stream.Wet mud lines its banks.";
}

if ((said(get, mud) ||
    said(get, mud, stream) ||
    said(get, mud, from, stream) ||
    said(get, mud, from, stream, with, spoon) ||
    said(get, mud, with, spoon)))
{
    if (has(i.mud))
    {
        #message 9  "You are already carrying it.";
    }
    else
    {
        if (!near.mud)
        {
            #message 10  "There is no mud around here.";
        }
        else
        {
            if (!has(i.spoon))
            {
                #message 4  "The thought of carrying around a handful of mud doesn't appeal to you.";
            }
            else
            {
                #message 5  "With the wooden spoon you kneel and scoop a spoonful of wet mud from
the stream's bank. You carry it with you.";
                get(i.mud);
                drop(i.spoon);
                if (!found.mud)
                {
                    set(found.mud);
                    score += 1;
                }
            }
        }
    }
}

if ((said(get, water, stream) ||
    said(get, water) ||
    said(get, water, cup)))
{
    #message 7  "You have no need to carry around the stream water. If you are thirsty
then just get a drink.";
}

if ((said(get, drink, water, stream) ||
    said(stream, get, drink, water) ||
    said(get, drink, water) ||
    said(get, drink) ||
    said(drink, water) ||
    said(drink)))
{
    if (near.water)
    {
        #message 8  "Cupping your hands, you bring the
refreshing water to your lips and drink deeply.Aaahhhh!!";
    }
    else
    {
        #message 11  "You need to move closer.";
    }
}

// [*****
// :e
// [*****

