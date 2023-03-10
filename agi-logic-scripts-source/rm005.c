// [logics for room 5 -- rm.wiz.office

#include  "rm5.msg"
#include  "gamedefs.al"

// [  There is a locked cabinet here that opens and closes.  Inside it is the
// [magic wand.  An invisible trapdoor is in the floor; move a book on the
// [shelf, then pull a lever to open it.  There is a feather duster on the
// [cabinet.

#define  l.walking        0                                 // [  loops numbers for dusting view
#define  l.standing      1

#define  seconds.to.exit    25
#define  seconds.to.dust    22

#define  book.in.place      0
#define  book.moved      1
#define  trapdoor.open      2

#define  cabinet        1                                   // [  ego.location values
#define  bookcase        2
#define  desk          3

#define  returning.his.rod    lf0
#define  talked.to.wiz      lf1
#define  wiz.at.desk      lf2
#define  door.done        lf3
#define  house.wiz.init'd    lf5

#define  writing.timer      lv0
#define  ego.exit.seconds    lv1
#define  dusting.script      lv2
#define  door.timer      lv3
#define  book.timer      lv4
#define  trapdoor.timer      lv5
#define  dust.timer      lv6
#define  dust.seconds      lv7

% object  a.cabinet.door      1
% object  a.trapdoor      2
% object  a.book        3
% object  a.duster        4

if (init.log)
{
  load.view.v(current.ego);
  set.view.v(ego, current.ego);
  load.view(v.ego);
  map.area = map.wiz.house;
  landing.x = 88;
  landing.y = 143;
  wiz.x = 70;
  wiz.y = 130;

  cat.x = 44;
  cat.y = 145;
  load.logics(lgc.wiz.house);

  load.pic(current.room);
  draw.pic(current.room);
  discard.pic(current.room);

  load.view(v.ego.dusting);
  load.view(v.door.rm5);
  load.view(v.trapdoor.rm5);
  load.view(v.book.rm5);
  load.view(v.feather.duster.rm5);

  if ((wiz.away.asleep == home.after.bed ||                 // [  If we're home, and he's
    wiz.away.asleep == home.after.town) &&
    !chore.to.do&&
    wiz.status != dead)
  {
    random(1, 2, work);
    if (work == 1)                                          // [  home, he may drop in.
    {
      load.logics(lgc.house.wiz);
      set(lgc.house.wiz.loaded);
      load.view(v.wiz.sitting);

      random(1, 2, work);
      if (work == 1)
      {
        set(house.wiz.init'd);
          set(wiz.at.desk);
        wiz.entrance.time = 0;                              // [  he's coming now
      }
      else
      {
        random(6, 12, wiz.entrance.time);                   // [  he's coming later
      }
    }
  }

  animate.obj(a.cabinet.door);
  ignore.blocks(a.cabinet.door);
  ignore.objs(a.cabinet.door);
  position(a.cabinet.door, 23, 154);
  set.view(a.cabinet.door, v.door.rm5);
  set.cel(a.cabinet.door, 0);
  set.priority(a.cabinet.door, 14);
  work = 2;
  cycle.time(a.cabinet.door, work);
  draw(a.cabinet.door);
  stop.cycling(a.cabinet.door);
  stop.update(a.cabinet.door);

  animate.obj(a.trapdoor);
  ignore.blocks(a.trapdoor);
  ignore.objs(a.trapdoor);
  position(a.trapdoor, 95, 143);
  set.view(a.trapdoor, v.trapdoor.rm5);
  set.priority(a.trapdoor, 4);
  stop.cycling(a.trapdoor);
  work = 2;
  cycle.time(a.trapdoor, work);
  if (office.status == trapdoor.open)
  {
    last.cel(a.trapdoor, work);
    set.cel.f(a.trapdoor, work);
  }
  else
  {
    set.cel(a.trapdoor, 0);
  }
  draw(a.trapdoor);
  stop.update(a.trapdoor);

  animate.obj(a.book);
  ignore.horizon(a.book);
  ignore.blocks(a.book);
  ignore.objs(a.book);
  position(a.book, 123, 127);
  set.view(a.book, v.book.rm5);
  stop.cycling(a.book);
  work = 2;
  cycle.time(a.book, work);
  if (office.status == book.in.place)
  {
    set.cel(a.book, 0);
  }
  else
  {
    last.cel(a.book, work);
    set.cel.f(a.book, work);
  }
  draw(a.book);
  stop.update(a.book);

  animate.obj(a.duster);
  ignore.blocks(a.duster);
  ignore.objs(a.duster);
  position(a.duster, 18, 134);
  set.view(a.duster, v.feather.duster.rm5);
  set.priority(a.duster, 14);
  draw(a.duster);
  stop.update(a.duster);

  if (current.status == fly)
  {
    set(positionEgo);
  }

  if (positionEgo)
  {
    if (previous.room == 9)                                 // [  rm.lab.stairs)
    {
      position(ego, 107, 125);
      set.loop(ego, facing.right);
      start.motion(ego);
    }
    else
    {
      if (previous.room == 7)                               // [  rm.entry)
      {
        position(ego, 96, 167);
      }
      else
      {
        position.v(ego, landing.x, landing.y);
      }
    }
  }

  if (drawEgo)
  {
    draw(ego);
  }

  if (lgc.house.wiz.loaded)
  {
    cat.y = 0;                                              // [  no pussy if wiz will come!
    call(lgc.house.wiz);
    if (wiz.at.desk)
    {
      wiz.status = here;
      wiz.x = 48;
      wiz.y = 117;
      set.view(a.wiz, v.wiz.sitting);
      work = wiz.cycle.time;
      cycle.time(a.wiz, work);
      set.cel(a.wiz, 0);
      stop.cycling(a.wiz);
      set.priority(a.wiz, 13);
      ignore.block(a.wiz);
      block(0, 0, 64, 133);
      position.v(a.wiz, wiz.x, wiz.y);
      draw(a.wiz);
      set(wiz.on.screen);
      writing.timer = 2;
    }
  }

  call(lgc.wiz.house);
  ignore.objs(a.cat);

  show.pic();

  if (wiz.at.desk)
  {
    sound(m.wiz, done);
    print.at(34, 2, 2, 37);
    wiz.temper = get.outta.here;
  }

  return();

}

if (posn(ego, 23, 155, 32, 166))
{
  ego.location = cabinet;
}
else
{
  if (posn(ego, 113, 125, 121, 140))
  {
    ego.location = bookcase;
  }
  else
  {
    if (posn(ego, 36, 125, 67, 131))
    {
      ego.location = desk;
    }
    else
    {
      ego.location = 0;
    }
  }
}

// [*****
// :h
// [*****

if (!have.input) { goto no.input; }

if ((said(look, room) ||
  said(look, house) ||
  said(look) ||
  said(look, study)))
{
  #message 1  "Manannan is very private with his study, and doesn't like you poking around.
The huge oak desk is
covered with his writing implements.An oak cabinet is in the
corner.There is a chart on the rear wall.
The bookshelves are filled with books on every
subject; the wizard fancies himself to be quite a scholar.";
}

if ((said(look, basket) ||
  said(look$in, basket)))
{
  #message 21  "Don't you remember... you emptied it yesterday.";
}

if ((said(look, chart) ||
  said(look, chart, on, wall) ||
  said(look, chart, wall)))
{
  #message 8  "The chart has no meaning to you.";
}

// [    DESK STUFF.

if ((said(look, table) ||
  said(look, chair)))
{
  #message 4  "The massive desk is made from oak. The wizard does all of
his reading, writing, and calculating here.";
}

if ((said(look, top, table) ||
  said(look, on, table) ||
  said(look, top$of, table)))
{
  #message 5  "The desk is covered with the wizard's writing implements: quill pens,
jars of oak bark ink, and parchment paper.Manannan is a
prolific writer, recording his many ideasand formulas.";
}

if ((said(open, table) ||
  said(open, drawer, table) ||
  said(open, drawer) ||
  said(open, desk, drawer) ||
  said(look, inside, table) ||
  said(look, drawer) ||
  said(look, inside, drawer)))
{
  if (ego.location != desk)
  {
    #message 3  "You are not close enough.";
  }
  else
  {
    if (wiz.on.screen)
    {
      #message 30  "The wizard wouldn't appreciate that.";
    }
    else
    {
      #message 6  "You open the large desk's only drawer; but, you see nothing
interesting.Before you're caught, you close it.";
    }
  }
}

// [    HANDLE THE CABINET, KEY AND WAND.

if (said(look, cabinet))
{
  #message 7  "The oak cabinet has a brass handle on its door. Your feather duster is
lying on its top.";
}

if ((said(unlock, cabinet, use, key) ||
  said(unlock, cabinet) ||
  said(unlock, cabinet, key) ||
  said(unlock, door) ||
  said(unlock, door, use, key) ||
  said(open, cabinet) ||
  said(open, cabinet, use, key) ||
  said(open, cabinet, key) ||
  said(open, cabinet, door) ||
  said(open, door, cabinet) ||
  said(open, door) ||
  said(look, inside, cabinet) ||
  said(look$in, cabinet) ||
  said(look$in, door, cabinet) ||
  said(look$in, cabinet, door) ||
  said(use, key, unlock, cabinet) ||
  said(use, key, cabinet) ||
  said(use, key, unlock, door) ||
  said(use, key, open, cabinet)))
{
  if (ego.location != cabinet)
  {
    #message 3  "You are not close enough.";
  }
  else
  {
    if (!has(i.key))
    {
      #message 10  "You try to turn the handle, but, unfortunately, the door is locked.";
    }
    else
    {
      #message 12  "You unlock the oaken cabinet using the brass key.";
      door.timer = 44;
      if (has(i.magic.wand))
      {
        set(returning.his.rod);
      }
    }
  }
}

if (has(i.magic.wand) &&
  (said(put, wand, cabinet) ||
    said(put, wand, back, cabinet) ||
    said(put, wand, back) ||
    said(put, magic, wand, back, cabinet) ||
    said(put, magic, wand, cabinet)))
{
  if (ego.location != cabinet)
  {
    #message 3  "You are not close enough.";
  }
  else
  {
    if (!has(i.key))
    {
      #message 10  "You try to turn the handle, but, unfortunately, the door is locked.";
    }
    else
    {
      #message 12  "You unlock the oaken cabinet using the brass key.";
      set(returning.his.rod);
      door.timer = 44;
    }
  }
}

// [      HANDLE THE FEATHER DUSTER.

if ((said(look, top$of, cabinet) ||
  said(look, top, cabinet) ||
  said(look, on, cabinet) ||
  said(look, on, cabinet, top) ||
  said(look, cabinet, top) ||
  said(look, on, top$of, cabinet)))
{
  #message 9  "There is just your feather duster on the cabinet.";
}

if (!handsOff &&
  (said(get, duster) ||
    said(clean, furniture) ||
    said(clean, room) ||
    said(clean, office) ||
    said(get, feather, duster)))
{
  if (ego.location != cabinet)
  {
    #message 3  "You are not close enough.";
  }
  else
  {
    dusting.script = 0;
    set(ego.arrived);
  }
}

// [    HANDLE THE BOOK ON THE BOOKCASE.

if (said(look, shelf))
{
  #message 15  "So many books line the bookshelf, you wonder when Manannan
has time to read them all.Titles cover many subjects :
from \"Ancient Arabic Mythology,\" to \"A Study of the Heavens,\" to
\"The Philosophies of Socrates.\"";
}

if (said(look, book))
{
  if (ego.location == bookcase)
  {
    #message 14  "Carefully examining the bookshelf, you notice a glint of metal
behind one huge volume.";
  }
  else
  {
    #message 15  "So many books line the bookshelf, you wonder when Manannan
has time to read them all.Titles cover many subjects :
from \"Ancient Arabic Mythology,\" to \"A Study of the Heavens,\" to
\"The Philosophies of Socrates.\"";
  }
}

if ((said(get, book) ||
  said(get, book, from, shelf) ||
  said(get, book, off, shelf) ||
  said(get, book, shelf)))
{
  if (office.status == book.in.place)
  {
    #message 17  "You glance at the titles of the books, but do not see any
that interest you.Wait... was that a glint of metal behind one large book ? ";
  }
  else
  {
    if (office.status == book.moved)
    {
      #message 18  "You glance at the books, but see no others that interest you.";
    }
    else
    {
      reset(have.match);
    }
  }
}

if ((said(look, glint)))
{
  #message 36  "There may be something metallic behind that large book.";
}

if ((said(move, book) ||
  said(look, behind, book)))
{
  if (ego.location != bookcase)
  {
    #message 3  "You are not close enough.";
  }
  else
  {
    if (wiz.on.screen)
    {
      office.status = book.moved;
    }
    else
    {
      book.timer = 44;
    }
  }
}

if ((said(put, book, back) ||
  said(put, book, back, shelf) ||
  said(move, book, back) ||
  said(move, book, back, on, shelf) ||
  said(put, book, back, on, shelf)))
{
  if (ego.location != bookcase)
  {
    #message 3  "You are not close enough.";
  }
  else
  {
    book.timer = 44;
  }
}

if (said(look, lever))
{
  if (office.status == book.in.place)
  {
    #message 26  "You look everywhere in the room, but do not see a lever.";
  }
  else
  {
    #message 22  "The metal lever is attached to the back of the bookshelf.";
  }
}

if (said(get, lever))
{
  if (office.status == book.in.place)
  {
    #message 26  "You look everywhere in the room, but do not see a lever.";
  }
  else
  {
    #message 27  "%m22 You cannot take it.";
  }
}

if ((said(look, trapdoor) ||
  said(look, down, trapdoor) ||
  said(look$in, trapdoor)))
{
  if (office.status == trapdoor.open)
  {
    #message 24  "Peering into the dark, frightening trapdoor, you see
treacherous stone steps.";
  }
  else
  {
    #message 23  "You look closely at the floor, but do not see any signs of one.";
  }
}

if ((said(move, lever) ||
  said(move, on, lever)))
{
  if (ego.location != bookcase)
  {
    #message 3  "You are not close enough.";
  }
  else
  {
    if (office.status == book.moved)
    {
      office.status = trapdoor.open;
      trapdoor.timer = 44;
      if (!found.trapdoor.lever)
      {
        set(found.trapdoor.lever);
        score += 5;
      }
    }
    else
    {
      if (office.status == trapdoor.open)
      {
        office.status = book.moved;
        trapdoor.timer = 44;
      }
      else
      {
        reset(have.match);
      }
    }
  }
}

// [      ROOM SPECIFIC WIZARD STUFF.

if (wiz.on.screen && !PO'd.wiz.init'd)
{
  if (said(talk, wizard) &&
    wiz.at.desk)
  {
    ++wiz.temper;
  }
}

// [*****
// :n
// [*****

// [  BOOK STUFF

--book.timer;
if (book.timer == 43)
{
  start.update(a.book);
  if (office.status == book.in.place)
  {
    office.status = book.moved;
    end.of.loop(a.book, done);
  }
  else
  {
    if (office.status == book.moved)
    {
      office.status = book.in.place;
      beginning.of.loop(a.book, done);
    }
    else
    {
      book.timer = 22;                                      // [  why wait?
    }
  }
}

if (book.timer == 11)
{
  if (office.status == book.moved)
  {
    #message 19  "You push the large book aside, revealing a metal lever attached to
the back of the bookshelf.";
  }
  else
  {
    if (office.status == book.in.place)
    {
      #message 20  "You move the big book back where you found it so it again conceals
the metal lever.";
      if (wiz.status != dead)
      {
        #message 35  "You don't want the old wizard to grow suspicious of your activities.";
      }
    }
    else
    {
      #message 33  "Before you replace the book, you'd better shut the trapdoor.";
      book.timer = 1;                                       // [  why wait?
    }
  }
}

if (book.timer == 1)
{
  stop.update(a.book);
}

// [  DOOR STUFF

--door.timer;
if (door.timer == 43)
{
  start.update(a.cabinet.door);
  end.of.loop(a.cabinet.door, done);
  stop.motion(ego);
  prevent.input();
}

if (door.timer == 22)
{
  if (returning.his.rod)
  {
    reset(returning.his.rod);
    #message 31  "You carefully replace the magic wand exactly as you found it.";
    put(i.magic.wand, current.room);
  }
  else
  {
    if (!obj.in.room(i.magic.wand, current.room))
    {
      #message 13  "You find it is empty.";
    }
    else
    {
      #message 11  "Inside, you find the wizard's magic wand.";
      if (wiz.status != dead)
      {
        #message 25  "You take it with you, knowing it could mean death if he finds it missing.";
      }
      get(i.magic.wand);
      if (!found.magic.wand)
      {
        set(found.magic.wand);
        score += 4;
      }
    }
  }
}

if (door.timer == 1)
{
  beginning.of.loop(a.cabinet.door, door.done);
}

if (door.done)
{
  reset(door.done);
  stop.update(a.cabinet.door);
  #message 16  "After closing the door, you carefully relock it.";
  start.motion(ego);
  accept.input();
}

// [  TRAPDOOR STUFF

--trapdoor.timer;
if (trapdoor.timer == 43)
{
  start.update(a.trapdoor);
  stop.motion(ego);
  prevent.input();

  if (office.status == trapdoor.open)
  {
    end.of.loop(a.trapdoor, done);
  }

  if (office.status == book.moved)
  {
    beginning.of.loop(a.trapdoor, done);
  }
}

if (trapdoor.timer == 22)
{
  if (office.status == trapdoor.open)
  {
    #message 28  "A trapdoor opens, revealing steep stone steps leading into darkness.";
  }

  if (office.status == book.moved)
  {
    #message 29  "The trapdoor groans shut, disappearing into the floorboards.";
  }
}

if (trapdoor.timer == 1)
{
  start.motion(ego);
  accept.input();
  if (office.status == book.moved)
  {
    set.priority(a.trapdoor, 4);
    stop.update(a.trapdoor);
  }
}

if (office.status == trapdoor.open)
{
  block(88, 126, 112, 144);
  set.priority(a.trapdoor, 12);
  start.update(a.trapdoor);
}
else
{
  if (wiz.at.desk)
  {
    block(0, 0, 64, 133);
  }
  else
  {
    unblock();
  }
}

// [  LOCAL ROOM SPECIFIC WIZARD STUFF

if (wiz.on.screen && !PO'd.wiz.init'd)
{
  if (!house.wiz.init'd)
  {
// [  Make wiz walk to desk, sit behind it and start writing.
    set(house.wiz.init'd);
      wiz.location = 0;
    set(wiz.arrived);
  }

  if (wiz.arrived)
  {
    reset(wiz.arrived);
    ++wiz.location;

    if (wiz.location == 1)
    {
      move.obj(a.wiz, 51, 130, 1, wiz.arrived);
    }

    if (wiz.location == 2)
    {
      set(wiz.at.desk);
      reposition.to(a.wiz, 48, 117);
      work = 1;
      cycle.time(a.wiz, work);
      set.view(a.wiz, v.wiz.sitting);
      set.priority(a.wiz, 13);
      writing.timer = 2;
    }
  }

  if (wiz.at.desk)
  {
    --writing.timer;
    if (writing.timer == 21)
    {
      start.cycling(a.wiz);
    }

    if (writing.timer == 1)
    {
      writing.timer = 66;
      stop.cycling(a.wiz);
    }
  }

  if (!PO'd.wiz.init'd &&
    (cabinet.unlocked ||
      office.status ||
      book.timer ||
      trapdoor.timer ||
      door.timer))
  {
    #message 32  "Caught in the act! You can see his rage building as the wizard's
face turns red behind his white beard and his eyes bulge
alarmingly.He roars at you, \"You know you're not allowed to sneak
around in my private study!\"";
    make.wiz.come = osw.punish;
    set(force.wiz.come);
  }
}                                                           // [  end of (wiz.on.screen)

if (aSecondPassed)
{
  --dust.seconds;
  if (dust.seconds == 1)
  {
    dust.seconds = 0;
    dust.timer = 0;
    set(ego.arrived);
    dusting.script = 4;
  }
}

--dust.timer;
if (dust.timer == 1)
{
  set(ego.arrived);
}

if (ego.arrived)
{
  reset(ego.arrived);
  ++dusting.script;
  step = 1;
  set(keep.cycling);
  program.control();
  prevent.input();
  set(handsOff);

  if (dusting.script == 1)
  {
    start.update(a.duster);
    erase(a.duster);
    dust.seconds = seconds.to.dust;
    get.posn(ego, target.x, target.y);
    ignore.objs(ego);
    x = 40;
    move.obj.v(ego, x, target.y, step, ego.arrived);

    if (chore.to.do == dust.office)
    {
      chore.to.do = 0;
      chore.seconds = 0;
      chore.minutes = 0;
    }
  }

  if (dusting.script == 2)
  {
    move.obj(ego, 40, 145, 1, ego.arrived);
  }

// [  the next two sections loop back and forth while he dusts.

  if (dusting.script == 3)                                  // [  he's by the desk
  {
    set.view(ego, v.ego.dusting);
    set.loop(ego, l.walking);
    fix.loop(ego);
    random(26, 63, x);
    move.obj.v(ego, x, ego.y, step, ego.arrived);
  }

  if (dusting.script == 4)
  {
    random(6, 33, dust.timer);
    set.loop(ego, l.standing);
    fix.loop(ego);
    dusting.script = 2;                                     // [  cause dust.timer will trigger
  }

// [  Wrap up this chore.

  if (dusting.script == 5)
  {
    set.loop(ego, l.walking);
    fix.loop(ego);
    move.obj(ego, 40, 145, 1, ego.arrived);
  }

  if (dusting.script == 6)
  {
    set.view(ego, v.ego);
    release.loop(ego);
    move.obj.v(ego, ego.x, target.y, step, ego.arrived);
  }

  if (dusting.script == 7)
  {
    move.obj.v(ego, target.x, ego.y, step, ego.arrived);
  }

  if (dusting.script == 8)
  {
    player.control();
    accept.input();
    reset(handsOff);
    reset(keep.cycling);
    set.view(ego, v.ego);
    current.status = normal.ego;
    observe.objs(ego);
    dusting.script = 0;
    draw(a.duster);
    stop.update(a.duster);
  }
}

// [*****
// :e
// [*****

if (posn(ego, 94, 125, 102, 126) &&
  current.status == normal.ego &&
  office.status == trapdoor.open)
{
  new.room(9);
}

if (posn(ego, 94, 140, 106, 152) &&
  current.status == fly &&
  office.status == trapdoor.open)
{
  new.room(9);
}

if (edge.ego.hit == bottom &&
  current.status != fly.landing &&
  ego.x > 92 && ego.x < 105)
{
  new.room(7);
}

call(lgc.wiz.house);

if (lgc.house.wiz.loaded)
{
  call(lgc.house.wiz);
}

if (wiz.on.screen && wiz.at.desk)
{
  wiz.x = 59;                                               // [  fool wiz.logics
  wiz.y = 125;
}

if (wiz.on.screen &&
  !PO'd.wiz.init'd &&
  make.wiz.come)                                            // [  make him rise, and get pissed
{
  program.control();
  stop.motion(ego);
  reset(keep.cycling);
  reset(lgc.house.wiz.loaded);
  if (wiz.at.desk)
  {
    reset(wiz.at.desk);
    set.view(a.wiz, v.wiz);
    reset(handsOff);
    reposition.to(a.wiz, 59, 125);
    set.priority(a.wiz, 11);
    wiz.x = 59;
    wiz.y = 125;
  }
}
