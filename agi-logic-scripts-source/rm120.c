// [logics for room 120 -- Beach talk

#include  "rm120.msg"
#include  "gamedefs.al"
#include  "iv-names.h"

if (!have.input)
{
    return();
}

if (said(look, plants))
{
    #message 1  "The lush foliage of the forest has given way to the hardy plants of the
shore.Sawgrass, bracken, and gnarled trees are all that grow here.";
}

if (said(look, trees))
{
    #message 2  "The trees are bent and twisted by years of constant sea breezes.";
}

if (said(look, ocean))
{
    #message 4  "Your eyes sweep the vast ocean before you. Blue water stretches as far
as you can see.Way in the distance it melts with the sky.";
}

if (said(look, sky))
{
    #message 5  "You see seagulls flying overhead.";
}

if (said(look, water))
{
    #message 4  "Your eyes sweep the vast ocean before you. Blue water stretches as far
as you can see.Way in the distance it melts with the sky.";
}

if (said(look, birds))
{
    #message 7  "The birds wheel and glide overhead.";
}

if ((said(look) ||
    said(look, cliff) ||
    said(look, ground) ||
    said(look, beach)))
{
    #message 3  "The sandy beach stretches north and south below steep, grassy cliffs.";
}

if ((said(swim) ||
    said(swim, ocean) ||
    said(swim, water)))
{
    #message 6  "The water looks inviting, but be careful if you go out there.";
}

if ((said(drink, water) ||
    said(drink, ocean, water) ||
    said(drink, water, ocean) ||
    said(drink, water, cup) ||
    said(drink, ocean, water, cup) ||
    said(drink, salt, water, cup) ||
    said(drink, salt, water)))
{
    #message 11  "Drinking salt water will only make you sick.";
}

if ((said(get, water) ||
    said(get, ocean, water) ||
    said(get, water, ocean) ||
    said(get, water, cup) ||
    said(get, ocean, water, cup) ||
    said(get, salt, water, cup) ||
    said(get, salt, water)))
{
    if (has(i.ocean.water))
    {
        #message 12  "Your cup is already full of water.";
    }
    else
    {
        if (!on.water)
        {
            #message 10  "You need to move closer.";
        }
        else
        {
            if (!has(i.cup))
            {
                #message 9  "You need a cup for the water.";
            }
            else
            {
                #message 8  "You fill your cup with ocean water.";
                get(i.ocean.water);
                drop(i.cup);
                if (!got.ocean.water)
                {
                    set(got.ocean.water);
                    score += 1;
                }
            }
        }
    }
}

// [*****
// :e
// [*****

