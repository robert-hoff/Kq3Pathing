// [logics for room 2 -- wiz's bedroom

#include  "rm2.msg"
#include  "gamedefs.al"
#include  "rm-names.h"

// [  can get the chamber pot, then throw it out the window.

// [  If ego doesn't have a chore.to.do, the wiz sometimes pops in on him here.
// [Tells him to leave, gives him 15 seconds, then poofs him to the kitchen
// [punishment.

// [  There might be a key on top of the closet. The drawer beneath the mirror
// [opens to reveal a hand mirror.  The drawer in the dresser opens to reveal
// [rose.petal.essence.  The closet door opens and closes.  Inside is the magic
// [map that lets you teleport throughout the game.

// [  If wiz.away.asleep == in.bed, Manannan is here sleeping.
// [Opening the closet door or either drawer will wake him, and send you away
// [for punishment.  You can get the key from the top of the closet without
// [waking him.

#define  dumper.x         82                                 // [  where you dump the chamber pot
#define  dumper.y        122
#define  alter.ego.y     106                               // [  where the mirror image echoes

#define  closet.shut            0                                 // [  bedroom.status values
#define  closet.open            1
#define  looked.through.closet  2
#define  got.map                3

#define  near.potty           lf0
#define  near.bed             lf1
#define  near.window          lf2
#define  near.closet          lf3
#define  near.mirror          lf4
#define  near.dresser         lf5
#define  near.rug             lf6
#define  on.rug               lf7
#define  in.way.of.drawer     lf8
#define  talked.to.wiz        lf9
#define  closet.done         lf10
#define  zzz's.done          lf11
#define  drawer.1.done       lf12
#define  drawer.2.done       lf13
#define  house.wiz.init'd    lf14
#define  next.dump.script    lf15
#define  lcl.wiz.arrived     lf16

#define  zzz's.timer          lv0
#define  ego.exit.timer       lv1
#define  got.pot.x            lv2
#define  got.pot.y            lv3
#define  dump.script          lv4
#define  alter.ego.x          lv5
#define  drawer.1.timer       lv6
#define  drawer.2.timer       lv7
#define  door.timer           lv8
#define  lcl.wiz.script       lv9
#define  bedroom.status       lv10

% object  a.alter.ego         1
% object  a.chamber.pot       2
% object  a.closet.doors      3
% object  a.drawer.2          4
% object  a.drawer.1          5

if (init.log)
{
    load.view.v(current.ego);
    set.view.v(ego, current.ego);
    load.view(v.ego);
    map.area = map.wiz.house;
    landing.x = 84;
    landing.y = 148;
    wiz.x = 20;
    wiz.y = 150;

    cat.x = 82;
    cat.y = 120;
    load.logics(lgc.wiz.house);

    if (wiz.status != dead)
    {
        wiz.status = 0;                                     // [  Clean up first.
    }

    if (wiz.away.asleep == in.bed &&
        wiz.status != dead)
    {
        load.logics(lgc.house.wiz);
        set(lgc.house.wiz.loaded);
        load.view(v.wiz.sleeping);
        load.view(v.wiz.leaving.bed);
        load.view(v.poof);

        load.sound(s.snoring);
        load.sound(s.ego.poofing);
        wiz.x = 29;
        wiz.y = 117;
        wiz.entrance.time = 0;
    }
    else
    {
        if ((wiz.away.asleep == home.after.bed ||
            wiz.away.asleep == home.after.town) &&
            !chore.to.do&&
            wiz.status != dead)
        {
            random(1, 4, work);
            if (work == 1)
            {
                set(lgc.house.wiz.loaded);
                load.logics(lgc.house.wiz);
                random(6, 12, wiz.entrance.time);           // [  he's coming later
            }
        }
    }

    load.pic(current.room);
    draw.pic(current.room);
    discard.pic(current.room);

    load.view(v.chamber.pot);
    load.view(v.door.rm2);
    load.view(v.drawer.1.rm2);
    load.view(v.drawer.2.rm2);

    animate.obj(a.chamber.pot);
    position(a.chamber.pot, 27, 133);
    set.view(a.chamber.pot, v.chamber.pot);
    draw(a.chamber.pot);
    stop.update(a.chamber.pot);

    animate.obj(a.alter.ego);
    position(a.alter.ego, 51, 70);
    set.view(a.alter.ego, v.ego);
    set.priority(a.alter.ego, 4);
    ignore.blocks(a.alter.ego);
    ignore.objs(a.alter.ego);
    ignore.horizon(a.alter.ego);
    draw(a.alter.ego);

    work = 2;

    animate.obj(a.closet.doors);
    position(a.closet.doors, 100, 115);
    set.view(a.closet.doors, v.door.rm2);
    set.priority(a.closet.doors, 5);
    cycle.time(a.closet.doors, work);
    if (bedroom.status)
    {
        last.cel(a.closet.doors, work);
        set.cel.v(a.closet.doors, work);
    }
    else
    {
        set.cel(a.closet.doors, 0);
    }
    draw(a.closet.doors);
    stop.update(a.closet.doors);

    animate.obj(a.drawer.1);                                // [  under the mirror
    ignore.objs(a.drawer.1);
    ignore.blocks(a.drawer.1);
    position(a.drawer.1, 63, 123);
    set.view(a.drawer.1, v.drawer.1.rm2);
    set.cel(a.drawer.1, 0);
    cycle.time(a.drawer.1, work);
    set.priority(a.drawer.1, 6);
    draw(a.drawer.1);
    stop.update(a.drawer.1);

    animate.obj(a.drawer.2);                                // [  the dresser
    ignore.objs(a.drawer.2);
    ignore.blocks(a.drawer.2);
    position(a.drawer.2, 107, 146);
    set.view(a.drawer.2, v.drawer.2.rm2);
    set.cel(a.drawer.2, 0);
    cycle.time(a.drawer.2, work);
    draw(a.drawer.2);
    stop.update(a.drawer.2);

    if (current.status == fly)
    {
        set(positionEgo);
    }

    if (positionEgo)
    {
        if (previous.room == 3)
        {
            position(ego, 41, 167);
        }
        else
        {
            position.v(ego, landing.x, landing.y);
        }
    }

    observe.blocks(ego);

    if (drawEgo) { draw(ego); }

    call(lgc.wiz.house);

    if (lgc.house.wiz.loaded)
    {
        call(lgc.house.wiz);

        if (wiz.away.asleep == in.bed)
        {
            set(house.wiz.init'd);
                zzz's.timer = 44;
                wiz.status = sleeping;
            set.view(a.wiz, v.wiz.sleeping);
            set.cel(a.wiz, 0);
            stop.cycling(a.wiz);
            position.v(a.wiz, wiz.x, wiz.y);
            draw(a.wiz);
            set(wiz.on.screen);
        }
        else
        {
            wiz.status = 0;
        }
    }

    show.pic();

    return();

}

// [*****
// :w
// [*****

reset(near.potty);
if (posn(ego, 0, 0, 36, 141))
{
    set(near.potty);
}

reset(near.bed);
if (posn(ego, 21, 131, 44, 140))
{
    set(near.bed);
}

reset(near.closet);
if (posn(ego, 95, 127, 112, 131))
{
    set(near.closet);
}

reset(near.mirror);
if (posn(ego, 58, 132, 70, 142))
{
    set(near.mirror);
}

reset(near.window);
if ((posn(ego, 77, 120, 91, 132) ||
    posn(ego, 0, 133, 27, 156)))
{
    set(near.window);
}

reset(near.dresser);
reset(in.way.of.drawer);
if (posn(ego, 102, 134, 117, 153))
{
    set(near.dresser);
    if (posn(ego, 108, 144, 112, 146))
    {
        set(in.way.of.drawer);
    }
}

reset(on.rug);
reset(near.rug);
if (posn(ego, 0, 133, 75, 164))
{
    set(near.rug);
    if (posn(ego, 0, 133, 69, 156))
    {
        set(on.rug);
    }
}

// [*****
// :handle.input
// [*****

if (!have.input) { goto no.input; }

// [  FIRST, WE DO THE GENERAL STUFF.

if (said(look, room) || said(look, house) || said(look) || said(look, bedroom))
{
    #message 1  "You look at Manannan's elegant bed chamber. You see fine"
                "furnishings from a regal bed to a beautifully carved closet."
                "You can't help but compare this handsome room to your own meager cubicle.";
}

if (said(look, vanity))
{
    #message 41  "There is a small drawer in the front of the mahogany vanity.";
}

if ((said(look, mirror) ||
    said(look$in, mirror)))
{
    if (!near.mirror)
    {
        #message 27  "The beveled mirror appears wavy because of imperfections in the glass. %m41";
    }
    else
    {
        current.loop(ego, work);
        if (work == facing.front)
        {
            #message 23  "The back of your hair looks cute.";
        }
        else
        {
            #message 4  "Imperfections in the glass make your reflection wavy; nevertheless, your
rags show up all too clearly.But, though in rags, your face is handsome
and your body strong.";
        }
    }
}

// [  HANDLE THE BED.

if (said(look, bed))
{
    if (wiz.status == sleeping)
    {
        #message 19  "Manannan is asleep on his great bed. His snores are so loud they
rumble off the walls.Be quiet; you wouldn't want to disturb him.";
    }
    else
    {
        #message 7  "Heavy velvet curtains drape the regal mahogany bed.";
    }
}

if (said(look, under, bed))
{
    if (near.bed)
    {
        #message 8  "Dropping to your hands and knees, you peer under the bed. There is
absolutely nothing there.";
    }
    else
    {
        #message 32  "You are not close enough.";
    }
}

if ((said(lie, bed) ||
    said(lie, on, bed) ||
    said(lie, down, on, bed) ||
    said(get, bed) ||
    said(get, on, bed) ||
    said(go, sleep) ||
    said(go, bed)))
{
    #message 18  "As comfortable as the bed looks, you have no interest
in lying on the hateful wizard's bed.";
}

// [  DO THE RUG.

if (said(look, rug))
{
    #message 13  "A beautiful rug adorns the floor. Its thick wool is woven into a
colorful design.";
}

if (said(get, rug))
{
    #message 42  "The carpet is too big and heavy to carry around.";
}

if (said(look, under, rug))
{
    if (on.rug)
    {
        #message 30  "You tug at the rug for quite a while... before realizing you're standing
on it!";
    }
    else
    {
        if (near.rug)
        {
            #message 14  "You lift up the rug in several places and look under it.
Sad to say, all you see is the dust you swept under there yesterday.";
        }
        else
        {
            #message 32  "You are not close enough.";
        }
    }
}

// [  NOW, DO THE DRESSER.

if ((said(look, top, dresser) ||
    said(look, top$of, dresser) ||
    said(look, on, top$of, dresser) ||
    said(look, on, dresser) ||
    said(look, dresser, top)))
{
    #message 10  "There is nothing exciting on top of the dresser.";
}

if ((said(look, drawer) ||
    said(look, dresser)))
{
    if (near.mirror)
    {
        #message 41  "There is a small drawer in the front of the mahogany vanity.";
    }
    else
    {
        #message 9  "The elegant dresser is made of mahogany. Its drawers are graced by beautiful gold knobs.";
    }
}

if ((said(look$in, dresser) ||
    said(look$in, drawer) ||
    said(look$in, vanity) ||
    said(look$in, dresser, drawer) ||
    said(look$in, vanity, drawer) ||
    said(look$in, drawer, dresser) ||
    said(look$in, drawer, vanity) ||
    said(open, vanity, drawer) ||
    said(open, dresser, drawer) ||
    said(open, drawer, vanity) ||
    said(open, drawer, dresser) ||
    said(open, vanity) ||
    said(open, dresser) ||
    said(open, drawer)))
{
    if (near.mirror)
    {
        if (wiz.status == sleeping)
        {
            set(lcl.wiz.arrived);
            lcl.wiz.script = 100;
        }
        else
        {
            drawer.1.timer = 44;
        }
    }
    else
    {
        if (near.dresser)
        {
            if (wiz.status == sleeping)
            {
                set(lcl.wiz.arrived);
                lcl.wiz.script = 100;
            }
            else
            {
                if (in.way.of.drawer)
                {
                    #message 38  "You bang the drawer against your shins repeatedly. (Try backing up!)";
                }
                else
                {
                    drawer.2.timer = 44;
                }
            }
        }
        else
        {
            if (near.closet)
            {
                #message 36  "Quietly opening the drawer below the closet, you discover...";
                #message 39  "nothing that interests you.";
            }
            else
            {
                #message 32  "You are not close enough.";
            }
        }
}


// [  NOW, LET'S HANDLE THE CLOSET/ARMOIRE/CABINET.

if (said(look, closet))
{
    if (!near.closet && obj.in.room(i.key, current.room))
    {
        #message 40  "%m2 There may be something metallic on its top.";
    }
    else
    {
        #message 2  "The closet is fashioned of ornately carved mahogany.";
    }
}


if (bedroom.status == closet.shut &&
   (said(look$in, closet) || said(look, inside, closet) || said(open, door) ||
    said(open, door, closet) || said(open, closet, door) || said(open, closet)))
{
    if (!near.closet)
    {
        #message 32  "You are not close enough.";
    }
    else
    {
        if (wiz.status == sleeping)
        {
            set(lcl.wiz.arrived);
            lcl.wiz.script = 100;
        }
        else
        {
            ++bedroom.status;
            start.update(a.closet.doors);
            set.cel(a.closet.doors, 0);
            end.of.loop(a.closet.doors, closet.done);
        }
    }
}

if (bedroom.status)
{
    if (obj.in.room(i.magic.map, current.room) &&
       (said(examine, closet) || said(look, behind, rol) || said(move, anyword, search, rol) ||
        said(move, clothes, rol) || said(move, anyword) || said(search, closet)))
    {
        if (!near.closet)
        {
            #message 32  "You are not close enough.";
        }
        else
        {
            bedroom.status = got.map;
            #message 28  "You're startled to discover an ancient parchment scroll. Its ink has faded,"
                         "but it seems to be a map.Taking this treasure,"
                         "you leave everything else exactly as it was.";
            get(i.magic.map);
            score += 7;
        }
    }

    if (said(look$in, closet) || said(look, inside, closet) || said(look, hats) || said(examine, closet) || said(search, closet))
    {
        if (!near.closet)
        {
            #message 32  "You are not close enough.";
        }
        else
        {
            #message 3  "You see voluminous velvet robes, satin slippers, peaked hats, and soft linen gowns.";
            bedroom.status = looked.through.closet;
        }
    }
}




if (bedroom.status && (said(close, closet) || said(close, door, closet) || said(close, closet, door) || said(close, door)))
{
    if (!near.closet)
    {
        #message 32  "You are not close enough.";
    }
    else
    {
        bedroom.status = closet.shut;
        start.update(a.closet.doors);
        last.cel(a.closet.doors, work);
        set.cel.v(a.closet.doors, work);
        beginning.of.loop(a.closet.doors, closet.done);
    }
}


if (said(search, top$of, closet) || said(search, top, closet) || said(search, on, closet) || said(search, on, top$of, closet) ||
    said(look, top$of, closet) || said(look, top, closet) || said(look, on, closet) || said(look, on, top$of, closet))
{
    if (!near.closet)
    {
        #message 12  "You are not close enough to reach the top of the closet.";
    }
    else
    {
        if (!obj.in.room(i.key, current.room))
        {
            #message 6  "You feel along the top of the closet. Your hand comes back dusty.";
        }
        else
        {
            get(i.key);
            #message 5  "You run a hand along the top of the closet. Suddenly, you touch something
metallic.Grabbing it, you discover...
a small brass key!What could it unlock ? ";
            if (!found.key)
            {
                set(found.key);
                score += 3;
            }
        }
    }
}



// [  HOW ABOUT THE WINDOW AND CHAMBER POT NEXT:

if (said(open, window) || said(close, window))
{
    if (!near.window)
    {
        #message 32  "You are not close enough.";
    }
    else
    {
        #message 17  "Manannan's bedroom window is always open. He likes fresh air.";
    }
}


if (said(look, bowl) || said(look, pot) || said(look, floor) || said(look, chamber$pot))
{
    #message 29  "Manannan's chamber pot is on the floor beside his bed.";
}

if (said(use, bowl) || said(use, pot) || said(use, chamber$pot))
{
    if (!near.potty)
    {
        #message 32  "You are not close enough.";
    }
    else
    {
        #message 33  "A feeling of great relief spreads over you.";
    }
}



if (said(look$in, bowl) || said(look$in, pot) || said(look$in, chamber$pot))
{
    if (!near.potty)
    {
        #message 32  "You are not close enough.";
    }
    else
    {
        #message 35  "You look inside Manannan's chamber pot...";
        #message 31  "and wish you hadn't!!";
    }
}

if (!handsOff &&
    (said(empty, chamber$pot) || said(empty, bowl) || said(empty, pot) ||
     said(get, chamber$pot) || said(get, bowl) || said(get, pot)))
{
    if (!near.potty)
    {
        #message 32  "You are not close enough.";
    }
    else
    {
        dump.script = 0;
        set(next.dump.script);
    }
}



// [  HANDLE THE LOCAL WIZ STUFF.

if (wiz.status == sleeping)
{
    if (said(look, wizard))
    {
        #message 19  "Manannan is asleep on his great bed. His snores are so loud they"
                     "rumble off the walls.Be quiet; you wouldn't want to disturb him.";
    }

    if (said(talk, wizard) || said(wake, up, wizard) || said(wake, wizard, up) || said(wake, wizard))
    {
        if (!talked.to.wiz)
        {
            set(talked.to.wiz);
            #message 20  "You speak softly to the sleeping wizard. \"Hhrrummph!\" he"
                         "grumbles sleepily, thumbing his nose as if at a fly.But, soon the"
                         "snoring resumes again.";
        }
        else
        {
            lcl.wiz.script = 200;
            set(lcl.wiz.arrived);
        }
    }
}



// [*****
// :no.input
// [*****

if (next.dump.script)
{
    reset(next.dump.script);
    ++dump.script;
    step = 1;
    program.control();
    prevent.input();

    if (dump.script == 1)
    {
        set(handsOff);
        start.update(a.chamber.pot);
        erase(a.chamber.pot);
        ignore.obj(a.cat);
        got.pot.x = ego.x;
        got.pot.y = ego.y;                                  // [  save for return flight
        x = dumper.x;
        move.obj.v(ego, x, ego.y, step, next.dump.script);

        if (chore.to.do == empty.pot)
        {
            chore.to.do = 0;
            chore.minutes = 0;
            chore.seconds = 0;
        }
    }

    if (dump.script == 2)
    {
        y = dumper.y;
        move.obj.v(ego, ego.x, y, step, next.dump.script);
    }

    if (dump.script == 3)
    {
        #message 24  "Wrinkling your nose in disgust, you throw the smelly contents of the"
                     "chamber pot out the open window.What a way to make a living!";
        "move.obj.v(ego, ego.x, got.pot.y, step, next.dump.script);
    }

    if (dump.script == 4)
    {
        move.obj.v(ego, got.pot.x, got.pot.y, step, next.dump.script);
    }

    if (dump.script == 5)
    {
        draw(a.chamber.pot);
        observe.obj(a.cat);
        player.control();
        accept.input();
        reset(handsOff);
    }
}

if (closet.done)
{
    reset(closet.done);
    stop.update(a.closet.doors);
}



// [  HANDLE THE DRAWER BENEATH THE MIRROR:

--drawer.1.timer;
if (drawer.1.timer == 43)
{
    stop.motion(ego);
    start.update(a.drawer.1);
    end.of.loop(a.drawer.1, done);
}

if (drawer.1.timer == 22)
{
    if (obj.in.room(i.mirror, current.room))
    {
        get(i.mirror);
        score += 1;
        #message 37  "In the vanity drawer are many uninteresting items, although the wizard's"
                     "hand mirror may come in handy.You grab it, then close the drawer.";
    }
    else
    {
        #message 34  "You find baubles and trinkets which do not interest you.";
    }
}


if (drawer.1.timer == 1)
{
    beginning.of.loop(a.drawer.1, drawer.1.done);
}

if (drawer.1.done)
{
    reset(drawer.1.done);
    stop.update(a.drawer.1);
    start.motion(ego);
}



// [  HANDLE THE DRAWER IN THE DRESSER:

--drawer.2.timer;
if (drawer.2.timer == 43)
{
    stop.motion(ego);
    start.update(a.drawer.2);
    end.of.loop(a.drawer.2, done);
}

if (drawer.2.timer == 22)
{
    if (obj.in.room(i.rose.essence, current.room))
    {
        get(i.rose.essence);
        score += 1;
        #message 11  "%m34 Suddenly, your eye falls on something that does... a vial labeled"
                     "\"Rose Petal Essence,\" which you eagerly take.";
    }
    else
    {
        #message 34  "You find baubles and trinkets which do not interest you.";
    }
}

if (drawer.2.timer == 1)
{
    beginning.of.loop(a.drawer.2, drawer.2.done);
}

if (drawer.2.done)
{
    reset(drawer.2.done);
    stop.update(a.drawer.2);
    start.motion(ego);
}



// [  HERE'S THE DEPARTMENT OF WIZZES:

if (wiz.on.screen && !PO'd.wiz.init'd)
{
    if (wiz.status == sleeping)
    {
        --zzz's.timer;
            if (zzz's.timer == 1)
            {
                start.cycling(a.wiz);
                    end.of.loop(a.wiz, zzz's.done);
                        zzz's.timer = 22;
                        sound(s.snoring, done);
            }

        if (zzz's.done)
        {
            reset(zzz's.done);
                stop.cycling(a.wiz);
            set.cel(a.wiz, 0);
        }
    }
}

if (aSecondPassed)
{
    --wiz.timer;
    if (wiz.timer == 1)
    {
        set(lcl.wiz.arrived);
    }

    if (!wiz.minutes && wiz.seconds < 8)
    {
        // [  keep wiz asleep while in bed
        wiz.seconds = 8;
    }
}

if (lcl.wiz.script == 204)
{
    current.cel(a.poof, work);
    if (work == 3)
    {
        set(lcl.wiz.arrived);
    }
}

// [  Handle the two forms of wiz arising from the good sleep that
// [comes from knowing his royalties are secure!
if (lcl.wiz.arrived)
{
    reset(lcl.wiz.arrived);
    ++lcl.wiz.script;
    // [  First, handle "wake-wiz-via-squeeking-furniture."
    if (lcl.wiz.script == 101)
    {
        prevent.input();
        program.control();
        stop.motion(ego);
        set(handsOff);
        wiz.status = 0;
        stop.cycling(a.wiz);
        set.view(a.wiz, v.wiz.leaving.bed);
        set.cel(a.wiz, 0);
        reposition.to(a.wiz, 38, 117);
        wiz.timer = 4;
        zzz's.timer = 0;
    }

    if (lcl.wiz.script == 102)
    {
        set.cel(a.wiz, 1);
        #message 22  "You try to be quiet, but an unfortunate squeak wakes Manannan. He"
                     "turns in his bed, then sits up, staring angrily at you."
                     "\"You know you're to stay out of my things,\" he growls. \"I've no"
                     "choice but to punish you for this.\"";
        wiz.timer = 4;
    }

    if (lcl.wiz.script == 103)
    {
        set.view(a.wiz, v.wiz);
        reposition.to(a.wiz, 37, 133);
        force.update(a.wiz);
        work = wiz.cycle.time;
        cycle.time(a.wiz, work);
        wiz.away.asleep = home.after.bed;
        wiz.minutes = wiz.home.minutes;
        force.update(ego);
        // [  out with the good wiz, in with the bad...
        unanimate.all();
        animate.obj(ego);
        draw(ego);
        force.update(ego);
        animate.obj(a.wiz);
        draw(a.wiz);
        force.update(a.wiz);
        make.wiz.come = osw.punish;
        set(force.wiz.come);
        lcl.wiz.script = 0;
    }

    // [  Next, handle "wake-wiz-by-talking-to-him-while-he's-asleep."
    if (lcl.wiz.script == 201)
    {
        prevent.input();
        program.control();
        stop.motion(ego);
        set(handsOff);
        wiz.status = leaving.room;
        stop.cycling(a.wiz);
        set.view(a.wiz, v.wiz.leaving.bed);
        set.cel(a.wiz, 0);
        reposition.to(a.wiz, 38, 117);
        wiz.timer = 4;
        zzz's.timer = 0;
    }

    if (lcl.wiz.script == 202)
    {
        set.cel(a.wiz, 1);
        #message 21  "This time your words awaken Manannan. A grumpy look comes to his"
                     "face. \"Don't you have anything better to do, boy, than to come in MY"
                     "bed chamber and wake me from my peaceful repose ? \"";
        wiz.timer = 4;
    }

    if (lcl.wiz.script == 203)
    {
        set.view(a.wiz, v.wiz);
        reposition.to(a.wiz, 37, 133);
        work = wiz.cycle.time;
        cycle.time(a.wiz, work);
        wiz.away.asleep = home.after.bed;
        wiz.minutes = wiz.home.minutes;
        wiz.temper = assign.chore;
        wiz.timer = 4;
    }

    if (lcl.wiz.script == 204)
    {
        animate.obj(a.poof);
        set.view(a.poof, v.poof);
        set.cel(a.poof, 0);
        work = 3;
        cycle.time(a.poof, work);
        ignore.obj(a.poof);
        set.priority(a.poof, 15);
        position(a.poof, 37, 133);
        stop.motion(a.poof);
        start.cycling(a.poof);
        draw(a.poof);
        end.of.loop(a.poof, lcl.wiz.arrived);
        sound(s.ego.poofing, done);
    }

    if (lcl.wiz.script == 205)
    {
        erase(a.wiz);
    }

    if (lcl.wiz.script == 206)
    {
        erase(a.poof);
        reset(wiz.on.screen);
        // [  prevents punishment after 25" from non-existant wizards
        reset(lgc.house.wiz.loaded);
        wiz.x = 20;
        wiz.y = 150;
        accept.input();
        player.control();
        start.motion(ego);
        reset(handsOff);
        erase(a.poof);
        wiz.status = gone;
        lcl.wiz.script = 0;
    }
}

// [  DO THE MIRROR IMAGE OF EGO SCHTICK.
if (erase.ego)
{
    erase(a.alter.ego);
}
else
{
    if (ego.y > 105)
    {
        current.view(ego, work);
        set.view.v(a.alter.ego, work);
        current.loop(ego, work);

        if (work == facing.back)
        {
            set.loop(a.alter.ego, facing.front);
        }
        else
        {
            if (work == facing.front)
            {
                set.loop(a.alter.ego, facing.back);
            }
            else
            {
                set.loop.v(a.alter.ego, work);
            }
        }

        current.cel(ego, work);
        set.cel.v(a.alter.ego, work);

        get.posn(ego, ego.x, y);
        y -= 132;
        target.y = 117;
        target.y -= y;
        reposition.to.v(a.alter.ego, ego.x, target.y);

        if (!keep.cycling &&
            (ego.dir == ego.stopped ||
                ego.dir == old.ego.dir))
        {
            stop.cycling(a.alter.ego);
        }
        else
        {
            start.cycling(a.alter.ego);
        }
    }
}

// [*****
// :exit
// [*****

call(lgc.wiz.house);
if (lgc.house.wiz.loaded)
{
    call(lgc.house.wiz);
}

if (edge.ego.hit == bottom && current.status != fly.landing && ego.x > 36 && ego.x < 52)
{
    new.room(rm.hallway);
}


















