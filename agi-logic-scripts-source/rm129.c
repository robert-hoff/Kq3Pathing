// [logics for room 129 -- lgc.near.desert

#include "gamedefs.al"
#include "rm129.msg"

// [  Used by rooms 12, 17, 22, & 27.
if (init.log || !have.input)
{
    return();
}

// [*****
// :handle.input
// [*****

if (said(look, room) || said(look))
{
    #message 1  "The soft, loamy soil of the forest here gives way to the sands of the
great desert stretching off to the west.";
}

if (said(look, flower))
{
    #message 2  "The flowers are pretty, but otherwise uninteresting to you.";
}

if (said(look, trees))
{
    #message 3  "The trees here cast a refreshing shade.";
}

if (said(look, flowers) || said(smell, flowers))
{
    #message 5  "There are no flowers in this area.";
}

if (said(look, ground))
{
    #message 1  "The soft, loamy soil of the forest here gives way to the sands of the
great desert stretching off to the west.";
}

if (said(look, sky))
{
    #message 9  "The clear, blue sky is brilliant with an occasional white cloud.";
}

if (said(pick, flowers) || said(get, flowers))
{
    #message 10  "There are no wildflowers to pick here.";
}

if (said(climb, trees))
{
    #message 11  "None of these trees are suitable for climbing.";
}
