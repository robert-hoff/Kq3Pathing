if (isset(newRoom))
{
    load.view.v(currentEgoView);
    set.view.v(ego, currentEgoView);
    load.view(View0);
    v56 = 1;
    v57 = 110;
    v58 = 149;
    v31 = 0;
    v100 = 52;
    v101 = 131;
    load.logics(Logic104);
    load.view(View15);
    load.view(View9);
    load.sound(Sound3);
    load.view(View33);
    load.pic(currentRoom);
    draw.pic(currentRoom);
    discard.pic(currentRoom);
    if (v44 == 25)
    {
        set(f48);
    }
    if (isset(f48))
    {
        if (previousRoom == 3)
        {
            v40 = 14;
            position.v(ego, v40, v41);
        }
        else
        {
            position.v(ego, v57, v58);
        }
    }
    if (v44 == 22)
    {
        reset(f47);
        set(f48);
        v90 = 2;
        v44 = 0;
        set(f223);
        set.view(ego, View0);
        position.v(ego, v57, v58);
    }
    if (isset(f47))
    {
        draw(ego);
    }
    if (isset(f223))
    {
        set(f47);
    }
    call(Logic104);
    show.pic();
    if (isset(f223))
    {
        reset(f35);
    }
    return ();
}
reset(f225);
if (posn(ego, 84, 139, 94, 162))
{
    set(f225);
}
reset(f224);
if (v40 > 77)
{
    set(f224);
}
if ((!isset(haveInput) ||
    !isset(f224) ||
    v44 == 7))
{
    goto(Label1);
}
v226 = 0;
if (has("Chicken Feather*") &&
    said("add", "bird", "feather", "rol"))
{
    v226 = 1;
}
if (has("Cat Hair*") &&
    said("add", "cat", "fur", "rol"))
{
    v226 = 2;
}
if (has("Dog Hair*") &&
    said("add", "dog", "fur", "rol"))
{
    v226 = 3;
}
if (has("Snakeskin*") &&
    said("add", "reptile skin", "rol"))
{
    v226 = 4;
}
if (has("Powdered Fish Bone*") &&
    said("add", "bone", "rol"))
{
    v226 = 5;
}
if (has("Thimble*") &&
    said("add", "thimble", "rol"))
{
    v226 = 6;
}
if (has("Thimble and Dew*") &&
    (said("add", "thimble", "rol") ||
    said("add", "dew", "rol")))
{
    v226 = 7;
}
if (has("Dough in Ears") && said("add", "compound", "ball", "rol"))
{
    print("You consider removing the dough pieces from your ears, but decide they "
          "are too fragile. You carefully comb your scraggly hair over them so "
          "the wizard cannot detect them.");
}

if (has("Eagle Feather*") && said("add", "eagle", "feather", "rol"))
{
    v226 = 9;
}

if (has("Fly Wings*") && said("add", "bug", "rol"))
{
    v226 = 10;
}

if (has("Saffron*") && said("add", "saffron", "rol"))
{
    v226 = 11;
}

if (has("Rose Essence*") && (said("add", "essence", "rol") || said("add", "magic", "essence", "rol")))
{
    v226 = 12;
}

if (has("Magic Rose Essence*") && (said("add", "essence", "rol") || said("add", "magic", "essence", "rol")))
{
    v226 = 39;
}

if (has("Salt*") && said("add", "grains of salt", "rol"))
{
    v226 = 13;
}
if (has("Amber Stone*") && said("add", "amber", "rock", "rol"))
{
    v226 = 14;
}
if (has("Mistletoe*") && said("add", "mistletoe", "rol"))
{
    v226 = 15;
}

if (has("Magic Stone*") && (said("add", "amber", "rock", "rol") || said("add", "magic", "rock", "rol")))
{
    v226 = 16;
}

if (has("Nightshade Juice*") && said("add", "night shade", "juice", "rol"))
{
    v226 = 17;
}

if (has("Acorns*") && said("add", "acorn", "rol"))
{
    v226 = 18;
}

if (has("Empty Pouch*") && (said("add", "drain", "pouch", "rol") || said("add", "pouch", "rol")))
{
    v226 = 19;
}

if (has("Sleep Powder*") && (said("add", "pouch", "rol") || said("add", "sleep", "flour", "rol")))
{
    v226 = 20;
}

if (has("Mandrake Root*") &&
    (said("add", "mandrake", "root", "flour", "rol") ||
    said("add", "mandrake", "root", "rol") ||
    said("add", "root", "rol")))
{
    v226 = 21;
}

if (has("Fish Oil*") && said("add", "fish oil", "rol"))
{
    v226 = 22;
}

if (has("Cat Cookie*") && (said("add", "cookie", "rol") || said("add", "cat", "cookie", "rol")))
{
    v226 = 23;
}

if ((has("Poisoned Porridge") || has("Porridge")) && said("add", "porridge", "rol"))
{
    if (has("Poisoned Porridge"))
    {
        v226 = 25;
    }
    if (has("Porridge"))
    {
        v226 = 24;
    }
}

if (has("Poisoned Porridge") && said("add", "poison", "porridge", "rol"))
{
    if (has("Poisoned Porridge"))
    {
        v226 = 25;
    }
}

if (has("Ocean Water*") &&
    (said("add", "bay", "liquid", "rol") ||
    said("add", "cup", "rol") ||
    said("add", "liquid", "rol")))
{
    v226 = 26;
}

if (has("Mud*") &&
    (said("add", "ladle", "rol") ||
    said("add", "mud", "rol")))
{
    v226 = 27;
}

if (has("Toadstool Powder*") &&
    said("add", "mushroom", "flour", "rol"))
{
    v226 = 28;
}

if (has("Empty Jar*") &&
    said("add", "bottle", "rol"))
{
    v226 = 29;
}
if (has("Storm Brew*") &&
    (said("add", "brew", "rol") ||
    said("add", "bottle", "rol")))
{
    v226 = 30;
}

if (has("Toad Spittle*") &&
    (said("add", "frog", "spit", "rol") ||
    said("add", "spit", "rol")))
{
    v226 = 31;
}

if (has("Lard*") &&
    said("add", "lard", "rol"))
{
    v226 = 32;
}

if (has("Knife") &&
    said("add", "dagger", "rol"))
{
    v226 = 33;
}

if (has("Cactus*") &&
    said("add", "cactii", "rol"))
{
    v226 = 34;
}

if (has("Invisibility Ointment*") &&
    said("add", "ointment", "rol"))
{
    v226 = 36;
}

if (has("Magic Wand*") &&
    (said("add", "rod", "rol") ||
    said("add", "magic", "rod", "rol")))
{
    v226 = 37;
}

if (has("Brass Key*") &&
    said("add", "key", "rol"))
{
    v226 = 38;
}

if (has("Bowl") &&
    said("add", "basin", "rol"))
{
    v226 = 40;
}

if (has("Spoon") &&
    said("add", "ladle", "rol"))
{
    v226 = 41;
}

if (has("Empty Cup") &&
    said("add", "cup", "rol"))
{
    v226 = 42;
}

if (has("Mirror*") &&
    said("add", "looking glass", "rol"))
{
    v226 = 43;
}

if ((has("Purse and Gold Coins*") ||
    has("Empty Purse*")) &&
    (said("add", "coin purse", "rol") ||
    said("add", "coin", "rol") ||
    said("add", "coin", "coin", "rol")))
{
    if (has("Purse and Gold Coins*"))
    {
        v226 = 48;
    }
    if (has("Empty Purse*"))
    {
        v226 = 47;
    }
}

if (has("Bread") &&
    said("add", "bread", "rol"))
{
    v226 = 49;
}

if (has("Fruit") &&
    said("add", "apple", "rol"))
{
    v226 = 50;
}

if (has("Mutton") &&
    said("add", "chop", "rol"))
{
    v226 = 51;
}

if (has("Magic Map*") &&
    (said("add", "map", "rol") ||
    said("add", "magic", "map", "rol")))
{
    v226 = 54;
}

if (v226 > 0)
{
    v225 = 3;
    set(f122);
    v39 = 0;
}
else
{
    v227 = 0;
    if (obj.in.room("Chicken Feather*", currentRoom) &&
        said("capture", "bird", "feather", "rol"))
{
        v227 = 1;
    }
    if (obj.in.room("Cat Hair*", currentRoom) &&
        said("capture", "cat", "fur", "rol"))
{
        v227 = 2;
    }
    if (obj.in.room("Dog Hair*", currentRoom) &&
        said("capture", "dog", "fur", "rol"))
{
        v227 = 3;
    }
    if (obj.in.room("Snakeskin*", currentRoom) &&
        said("capture", "reptile skin", "rol"))
{
        v227 = 4;
    }
    if (obj.in.room("Powdered Fish Bone*", currentRoom) &&
        said("capture", "bone", "rol"))
{
        v227 = 5;
    }
    if (obj.in.room("Thimble*", currentRoom) &&
        said("capture", "thimble", "rol"))
{
        v227 = 6;
    }
    if (obj.in.room("Thimble and Dew*", currentRoom) &&
        (said("capture", "thimble", "rol") ||
        said("capture", "dew", "rol")))
{
        v227 = 7;
    }
    if (obj.in.room("Eagle Feather*", currentRoom) &&
        said("capture", "eagle", "feather", "rol"))
{
        v227 = 9;
    }
    if (obj.in.room("Fly Wings*", currentRoom) &&
        said("capture", "bug", "rol"))
{
        v227 = 10;
    }
    if (obj.in.room("Saffron*", currentRoom) &&
        said("capture", "saffron", "rol"))
{
        v227 = 11;
    }
    if (obj.in.room("Rose Essence*", currentRoom) &&
        (said("capture", "essence", "rol") ||
        said("capture", "magic", "essence", "rol")))
{
        v227 = 12;
    }
    if (obj.in.room("Magic Rose Essence*", currentRoom) &&
        (said("capture", "essence", "rol") ||
        said("capture", "magic", "essence", "rol")))
{
        v227 = 39;
    }
    if (obj.in.room("Salt*", currentRoom) &&
        said("capture", "grains of salt", "rol"))
{
        v227 = 13;
    }
    if (obj.in.room("Amber Stone*", currentRoom) &&
        said("capture", "amber", "rock", "rol"))
{
        v227 = 14;
    }
    if (obj.in.room("Mistletoe*", currentRoom) &&
        said("capture", "mistletoe", "rol"))
{
        v227 = 15;
    }
    if (obj.in.room("Magic Stone*", currentRoom) &&
        (said("capture", "amber", "rock", "rol") ||
        said("capture", "magic", "rock", "rol")))
{
        v227 = 16;
    }
    if (obj.in.room("Nightshade Juice*", currentRoom) &&
        said("capture", "night shade", "juice", "rol"))
{
        v227 = 17;
    }
    if (obj.in.room("Acorns*", currentRoom) &&
        said("capture", "acorn", "rol"))
{
        v227 = 18;
    }
    if (obj.in.room("Empty Pouch*", currentRoom) &&
        (said("capture", "drain", "pouch", "rol") ||
        said("capture", "pouch", "rol")))
{
        v227 = 19;
    }
    if (obj.in.room("Sleep Powder*", currentRoom) &&
        (said("capture", "pouch", "rol") ||
        said("capture", "sleep", "flour", "rol")))
{
        v227 = 20;
    }
    if (obj.in.room("Mandrake Root*", currentRoom) &&
        (said("capture", "mandrake", "root", "flour", "rol") ||
        said("capture", "mandrake", "root", "rol") ||
        said("capture", "root", "rol")))
{
        v227 = 21;
    }
    if (obj.in.room("Fish Oil*", currentRoom) &&
        said("capture", "fish oil", "rol"))
{
        v227 = 22;
    }
    if (obj.in.room("Cat Cookie*", currentRoom) &&
        (said("capture", "cookie", "rol") ||
        said("capture", "cat", "cookie", "rol")))
{
        v227 = 23;
    }
    if ((obj.in.room("Poisoned Porridge", currentRoom) ||
        obj.in.room("Porridge", currentRoom)) &&
        said("capture", "porridge", "rol"))
{
        if (obj.in.room("Poisoned Porridge", currentRoom))
{
            v227 = 25;
        }
        if (obj.in.room("Porridge", currentRoom))
{
            v227 = 24;
        }
    }
    if (obj.in.room("Poisoned Porridge", currentRoom) &&
        said("capture", "poison", "porridge"))
{
        v227 = 25;
    }
    if (obj.in.room("Ocean Water*", currentRoom) &&
        (said("capture", "bay", "liquid", "rol") ||
        said("capture", "cup", "rol") ||
        said("capture", "liquid", "rol")))
{
        v227 = 26;
    }
    if (obj.in.room("Mud*", currentRoom) &&
        (said("capture", "mud", "rol") ||
        said("capture", "ladle", "rol")))
{
        v227 = 27;
    }
    if (obj.in.room("Toadstool Powder*", currentRoom) &&
        said("capture", "mushroom", "flour", "rol"))
{
        v227 = 28;
    }
    if (obj.in.room("Empty Jar*", currentRoom) &&
        said("capture", "bottle", "rol"))
{
        v227 = 29;
    }
    if (obj.in.room("Storm Brew*", currentRoom) &&
        (said("capture", "brew", "rol") ||
        said("capture", "bottle", "rol")))
{
        v227 = 30;
    }
    if (obj.in.room("Toad Spittle*", currentRoom) &&
        (said("capture", "frog", "spit", "rol") ||
        said("capture", "spit", "rol")))
{
        v227 = 31;
    }
    if (obj.in.room("Lard*", currentRoom) &&
        said("capture", "lard", "rol"))
{
        v227 = 32;
    }
    if (obj.in.room("Knife", currentRoom) &&
        said("capture", "dagger", "rol"))
{
        v227 = 33;
    }
    if (obj.in.room("Cactus*", currentRoom) &&
        said("capture", "cactii", "rol"))
{
        v227 = 34;
    }
    if (obj.in.room("Invisibility Ointment*", currentRoom) &&
        said("capture", "ointment", "rol"))
{
        v227 = 36;
    }
    if (obj.in.room("Magic Wand*", currentRoom) &&
        (said("capture", "magic", "rod", "rol") ||
        said("capture", "rod", "rol")))
{
        v227 = 37;
    }
    if (obj.in.room("Brass Key*", currentRoom) &&
        said("capture", "key", "rol"))
{
        v227 = 38;
    }
    if (obj.in.room("Bowl", currentRoom) &&
        said("capture", "basin", "rol"))
{
        v227 = 40;
    }
    if (obj.in.room("Spoon", currentRoom) &&
        said("capture", "ladle", "rol"))
{
        v227 = 41;
    }
    if (obj.in.room("Empty Cup", currentRoom) &&
        said("capture", "cup", "rol"))
{
        v227 = 42;
    }
    if (obj.in.room("Mirror*", currentRoom) &&
        said("capture", "looking glass", "rol"))
{
        v227 = 43;
    }
    if ((obj.in.room("Purse and Gold Coins*", currentRoom) ||
        obj.in.room("Empty Purse*", currentRoom)) &&
        (said("capture", "coin purse", "rol") ||
        said("capture", "coin", "rol") ||
        said("capture", "coin", "coin", "rol")))
{
        if (obj.in.room("Purse and Gold Coins*", currentRoom))
{
            v227 = 48;
        }
        if (obj.in.room("Empty Purse*", currentRoom))
{
            v227 = 47;
        }
    }
    if (obj.in.room("Bread", currentRoom) &&
        said("capture", "bread", "rol"))
{
        v227 = 49;
    }
    if (obj.in.room("Fruit", currentRoom) &&
        said("capture", "apple", "rol"))
{
        v227 = 50;
    }
    if (obj.in.room("Mutton", currentRoom) &&
        said("capture", "chop", "rol"))
{
        v227 = 51;
    }
    if (obj.in.room("Magic Map*", currentRoom) &&
        (said("capture", "map", "rol") ||
        said("capture", "magic", "map", "rol")))
{
        v227 = 54;
    }
    if (v227 > 0)
    {
        v225 = 4;
        set(f122);
        v39 = 0;
    }
    else
    {
Label1:
        if (!isset(haveInput))
        {
            goto(Label2);
        }
        if (v44 == 7)
        {
            if ((said("capture", "up") ||
                said("board", "bed") ||
                said("capture", "up", "from", "bed") ||
                said("wake") ||
                said("wake", "board", "bed") ||
                said("capture", "up", "bed") ||
                said("board", "bed")))
            {
                v39 = 8;
                set(f122);
            }
            else
            {
                print("Shhhh! You're trying to sleep.");
                set(haveMatch);
            }
        }
        if ((said("examine", "cage") ||
            said("examine", "building") ||
            said("examine", "area") ||
            said("examine") ||
            said("examine", "drapery")))
        {
            if (!isset(f224))
            {
                print("You have always admired this lovely tapestry. It adds one of the "
                        "few bright spots to this dreary house.");
            }
            else
            {
                reset(haveMatch);
            }
        }
        if ((said("examine", "back", "drapery") ||
            said("examine", "below", "drapery")))
        {
            if (posn(ego, 52, 131, 77, 137))
            {
                print("You lift the bottom of the tapestry and peer behind it. The wall "
                        "is filled with cracks. You can see why Manannan would hang a "
                        "tapestry here. (There are also dozens of charcoal- scribbled "
                        "drawings, diagrams, maps, and notes to programmers, with the "
                        "legend \"King's Quest IV,\" but you're uninterested in this, "
                        "since you presently have your hands full with \"King's Quest "
                        "III.\") You lower the tapestry and smooth out the wrinkles.");
            }
            else
            {
                if (isset(f224))
                {
                    print("How can you see it through your bedroom wall?");
                }
                else
                {
                    print("You are not close enough.");
                }
            }
        }
        if ((said("examine", "area") ||
            said("examine") ||
            said("examine", "bedroom")))
        {
            if (!isset(f224))
            {
                print("You might try that over there in your bedroom, but not here in "
                        "the hall.");
            }
            else
            {
                print("This is your own pitiful bed chamber. Compared to Manannan's "
                        "fine room, yours is almost a cell. The bed is hard and "
                        "uncomfortable with only a threadbare blanket and a small, flat "
                        "pillow. The other furnishings are junk. But, as poor as it is, "
                        "it's your own haven, as the wizard never enters it.");
            }
        }
        if ((said("examine", "bureau") ||
            said("examine", "cabinet")))
        {
            if (!isset(f224))
            {
                print("You might try that over there in your bedroom, but not here in "
                        "the hall.");
            }
            else
            {
                print("Your dresser is a piece of junk. It's full of nicks and "
                        "scratches, and one drawer is completely missing.");
            }
        }
        if ((said("examine", "on", "bureau") ||
            said("examine", "above", "bureau") ||
            said("examine", "on", "above", "bureau") ||
            said("examine", "on", "cabinet") ||
            said("examine", "above", "cabinet") ||
            said("examine", "on", "above", "cabinet")))
        {
            if (!isset(f224))
            {
                print("You are not close enough.");
            }
            else
            {
                print("There is nothing you want there.");
            }
        }
        if ((said("look in", "bureau") ||
            said("lift", "bureau") ||
            said("look in", "cabinet") ||
            said("lift", "cabinet") ||
            said("examine", "drawer") ||
            said("lift", "drawer")))
        {
            if (!isset(f224))
            {
                print("You are not close enough.");
            }
            else
            {
                print("You have nothing of any interest in your dresser drawer.");
            }
        }
        if ((said("examine", "looking glass") ||
            said("look in", "looking glass")))
        {
            if (!isset(f224))
            {
                print("You might try that over there in your bedroom, but not here in "
                        "the hall.");
            }
            else
            {
                print("You look into the cracked mirror hanging on the wall. Your "
                        "reflection shows a tall, handsome lad dressed in dirty rags.");
            }
            if (has("Mirror*"))
            {
                reset(haveMatch);
            }
        }
        if (said("lift", "door"))
        {
            if (!isset(f225))
            {
                print("You are not close enough.");
            }
            else
            {
                if (isset(f223))
                {
                    print("You twist the door knob on the bedroom door, but to your "
                            "frustration, find it locked.");
                }
                else
                {
                    print("The door is already open.");
                }
            }
        }
        if (said("close", "door"))
        {
            if (isset(f223))
            {
                print("The door is already closed.");
            }
            else
            {
                print("You start to close the door, but, so as not to arouse the "
                        "wizard's suspicions, you leave it open.");
            }
        }
        if (said("unlock", "door"))
        {
            if (isset(f223))
            {
                print("You don't have a key that unlocks this door. It seems you are at "
                        "the mercy of the miserable old wizard.");
            }
            else
            {
                print("The door is not locked. It's not even closed!");
            }
        }
        if ((said("capture", "bolt") ||
            said("capture", "door", "bolt") ||
            said("capture", "bolt", "door")))
        {
            if (isset(f223))
            {
                print("You have nothing with which to pick a lock.");
            }
            else
            {
                print("The door is not locked. It's not even closed!");
            }
        }
        if (said("examine", "door"))
        {
            if (isset(f223))
            {
                print("The door is closed.");
            }
            else
            {
                print("The door is wide open.");
            }
        }
        if ((said("break", "door") ||
            said("break", "down", "door") ||
            said("break", "lift", "door")))
        {
            if (!isset(f225))
            {
                print("You are not close enough.");
            }
            else
            {
                if (isset(f223))
                {
                    print("You throw your body against the locked door, but in vain. The "
                            "door is too strong for you to break.");
                }
                else
                {
                    print("The door is not locked. It's not even closed!");
                }
            }
        }
        if ((said("break", "glass") ||
            said("break", "lift", "glass")))
        {
            if (!isset(f224))
            {
                print("You might try that over there in your bedroom, but not here in "
                        "the hall.");
            }
            else
            {
                print("That would do you no good. The wizard anticipated your escape "
                        "and placed iron bars outside your window.");
            }
        }
        if (said("examine", "bed"))
        {
            if (!isset(f224))
            {
                print("You might try that over there in your bedroom, but not here in "
                        "the hall.");
            }
            else
            {
                print("The bed is nothing more than a cot, hard and cold, and is "
                        "difficult to sleep on. Your pillow is small, flat, and made of "
                        "old rags.");
            }
        }
        if (said("examine", "below", "bed"))
        {
            if (!isset(f224))
            {
                print("You might try that over there in your bedroom, but not here in "
                        "the hall.");
            }
            else
            {
                v225 = 1;
                set(f122);
                v39 = 0;
            }
        }
        if ((said("lay", "bed") ||
            said("board", "bed") ||
            said("lay", "on", "bed") ||
            said("board", "sleep") ||
            said("board", "sleep", "on", "bed") ||
            said("sleep", "on", "bed") ||
            said("sleep", "bed") ||
            said("capture", "on", "bed")))
        {
            if (!isset(f224))
            {
                print("You might try that over there in your bedroom, but not here in "
                        "the hall.");
            }
            else
            {
                if (v44 == 0)
                {
                    v225 = 7;
                    set(f122);
                    v39 = 0;
                }
            }
        }
        if (said("add", "all", "rol"))
        {
            if (!isset(f224))
            {
                print("You might try that over there in your bedroom, but not here in "
                        "the hall.");
            }
            else
            {
                v225 = 3;
                set(f122);
                v39 = 0;
            }
        }
        if (said("capture", "all", "rol"))
        {
            if (!isset(f224))
            {
                print("You might try that over there in your bedroom, but not here in "
                        "the hall.");
            }
            else
            {
                v225 = 4;
                set(f122);
                v39 = 0;
            }
        }
    }
}
Label2:
--v222;
if (v222 == 1)
{
    set(f122);
}
if (isset(f122))
{
    reset(f122);
    ++v39;
    program.control();
    prevent.input();
    set(f46);
    set(f35);
    if (v39 == 1)
    {
        if (posn(ego, 88, 120, 115, 167))
        {
            ++v39;
        }
        else
        {
            move.obj(ego, 111, 152, 0, f122);
        }
    }
    if (v39 == 2)
    {
        move.obj(ego, 111, 133, 0, f122);
    }
    if (v39 == 3)
    {
        v59 = 2;
        cycle.time(ego, v59);
        stop.motion(ego);
        if (v225 == 7)
        {
            set.priority(ego, 15);
            set.view(ego, View15);
            reposition.to(ego, 119, 131);
            last.cel(ego, v36);
            set.cel.v(ego, v36);
            reverse.loop(ego, f122);
        }
        else
        {
            set.view(ego, View33);
            set.loop(ego, 0);
            set.cel(ego, 0);
            end.of.loop(ego, f122);
        }
    }
    if (v39 == 4)
    {
        v222 = 11;
        stop.motion(ego);
        reset(f35);
    }
    if (v39 == 5)
    {
        stop.motion(ego);
        if (v225 != 7)
        {
            v222 = 11;
            reset(f35);
        }
        else
        {
            set(f221);
            set.view(ego, View9);
            reposition.to(ego, 123, 131);
            set.cel(ego, 0);
            accept.input();
            v224 = 44;
            reset(f222);
            v39 = 0;
            v44 = 7;
            print("You lie down on your hard bed, stretch, then curl up, trying hard "
                    "to get comfortable. Your thin blanket and small pillow do not help "
                    "much.");
        }
        if (v225 == 1)
        {
            if (isset(f118))
            {
                print("You bend down and peek under the bed. Your possessions are still "
                        "safely hidden.");
            }
            else
            {
                print("You lean down and poke your head under the bed. You see nothing "
                        "but cobwebs and dust.");
            }
        }
        if (v225 == 3)
        {
            v36 = currentRoom;
            if (v226 > 0)
            {
                print("You get on your hands and knees and shove it under the bed. It "
                        "will be safe from the wizard's sharp eyes there.");
                set(f118);
                put.v(v226, currentRoom);
            }
            else
            {
                v220 = 1;
Label3:
                get.room.v(v220, v221);
                if (v221 == 255)
                {
                    put.v(v220, currentRoom);
                    set(f118);
                }
                ++v220;
                if (v220 == 8)
                {
                    ++v220;
                }
                if (v220 < 55)
                {
                    goto(Label3);
                }
                if (isset(f118))
                {
                    print("You get on your hands and knees and quickly shove all your "
                            "possessions under the bed. They will be safe from the wizard's "
                            "sharp eyes there.");
                    if (!isset(f93))
                    {
                        set(f93);
                        currentScore += 4;
                    }
                }
                else
                {
                    print("Obviously, you have nothing to hide, Gwydion!");
                }
            }
        }
        if (v225 == 4)
        {
            if (!isset(f118))
            {
                print("There's nothing under the bed.");
            }
            else
            {
                if (v227 > 0)
                {
                    v36 = 255;
                    get.room.v(v227, v221);
                    if (v221 != 4)
                    {
                        print("You drop down, reach under the bed, and then realize you've "
                                "never put it there!");
                    }
                    else
                    {
                        print("Dropping to your knees, you reach under the bed and retrieve "
                                "it.");
                        put.v(v227, v36);
                        reset(f118);
                        v220 = 1;
Label4:
                        get.room.v(v220, v221);
                        if (v221 == 4)
                        {
                            set(f118);
                            v220 = 55;
                        }
                        ++v220;
                        if (v220 < 55)
                        {
                            goto(Label4);
                        }
                    }
                }
                else
                {
                    reset(f118);
                    v36 = 255;
                    v220 = 1;
Label5:
                    get.room.v(v220, v221);
                    if (v221 == 4)
                    {
                        put.v(v220, v36);
                    }
                    ++v220;
                    if (v220 < 55)
                    {
                        goto(Label5);
                    }
                    print("Dropping to your knees, you reach under the bed and retrieve "
                            "all of your possessions.");
                }
            }
        }
    }
    if (v39 == 6)
    {
        set(f35);
        last.cel(ego, v36);
        set.cel.v(ego, v36);
        reverse.loop(ego, f122);
    }
    if (v39 == 7)
    {
        v39 = 10;
    }
    if (v39 == 8)
    {
        // [WARNING: this block contains no commands
        }
    if (v39 == 9)
    {
        set.view(ego, View15);
        reposition.to(ego, 118, 130);
        set.cel(ego, 0);
        end.of.loop(ego, f122);
        set(f35);
        v224 = 0;
    }
    if (v39 == 10)
    {
        v39 = 0;
        player.control();
        accept.input();
        reset(f46);
        release.priority(ego);
        reset(f35);
        start.motion(ego);
        v44 = 0;
        set.view(ego, View0);
        set.loop(ego, 1);
        reposition.to(ego, 111, 133);
        v59 = 1;
        cycle.time(ego, v59);
        if (isset(f221))
        {
            reset(f221);
            print("You gratefully rise from your hard old bed, stretching your aching "
                    "muscles.");
        }
    }
}
if (v44 == 7)
{
    --v224;
    if (v224 == 1)
    {
        set(f35);
        end.of.loop(ego, f222);
        sound(Sound3, f41);
        v224 = 22;
    }
    if (isset(f222))
    {
        reset(f222);
        set.cel(ego, 0);
        reset(f35);
        stop.cycling(ego);
    }
}
if (isset(f33))
{
    reset(f35);
    reset(f36);
    reset(f37);
    reset(f38);
    if (isset(f223) &&
        v44 != 25)
    {
        print("You suddenly find yourself in your own little room. You notice that "
                "the door is closed.");
    }
}
if (isset(f123))
{
    reset(f123);
    reset(f223);
    print("You hear a CLICK at the bedroom door. The old wizard has decided to "
            "free you by magically unlocking your door.");
}
if (isset(f223))
{
    observe.blocks(ego);
}
else
{
    ignore.blocks(ego);
}
if (v44 != 125)
{
    if (posn(ego, 11, 131, 12, 165))
    {
        new.room(Logic3);
    }
    if (posn(ego, 47, 0, 69, 43))
    {
        new.room(Logic1);
    }
}
call(Logic104);
return ();

[Messages
#message 1 "This is your own pitiful bed chamber. Compared to Manannan's fine room, yours is almost a cell. The bed is hard and uncomfortable with only a threadbare blanket and a small, flat pillow. The other furnishings are junk. But, as poor as it is, it's your own haven, as the wizard never enters it."
#message 2 "You are not close enough."
#message 3 "The bed is nothing more than a cot, hard and cold, and is difficult to sleep on. Your pillow is small, flat, and made of old rags."
#message 4 "You lean down and poke your head under the bed. You see nothing but cobwebs and dust."
#message 5 "You bend down and peek under the bed. Your possessions are still safely hidden."
#message 6 "Your dresser is a piece of junk. It's full of nicks and scratches, and one drawer is completely missing."
#message 7 "There is nothing you want there."
#message 8 "You hear a CLICK at the bedroom door. The old wizard has decided to free you by magically unlocking your door."
#message 9 "You have nothing of any interest in your dresser drawer."
#message 10 "You look into the cracked mirror hanging on the wall. Your reflection shows a tall, handsome lad dressed in dirty rags."
#message 11 "There's nothing under the bed."
#message 12 "You have always admired this lovely tapestry. It adds one of the few bright spots to this dreary house."
#message 13 "You lift the bottom of the tapestry and peer behind it. The wall is filled with cracks. You can see why Manannan would hang a tapestry here. (There are also dozens of charcoal- scribbled drawings, diagrams, maps, and notes to programmers, with the legend \"King's Quest IV,\" but you're uninterested in this, since you presently have your hands full with \"King's Quest III.\") You lower the tapestry and smooth out the wrinkles."
#message 14 "You twist the door knob on the bedroom door, but to your frustration, find it locked."
#message 15 "The door is already open."
#message 16 "The door is already closed."
#message 17 "You start to close the door, but, so as not to arouse the wizard's suspicions, you leave it open."
#message 18 "You don't have a key that unlocks this door. It seems you are at the mercy of the miserable old wizard."
#message 19 "The door is not locked. It's not even closed!"
#message 20 "You have nothing with which to pick a lock."
#message 21 "How can you see it through your bedroom wall?"
#message 22 "You throw your body against the locked door, but in vain. The door is too strong for you to break."
#message 23 "That would do you no good. The wizard anticipated your escape and placed iron bars outside your window."
#message 24 "You get on your hands and knees and quickly shove all your possessions under the bed. They will be safe from the wizard's sharp eyes there."
#message 25 "Dropping to your knees, you reach under the bed and retrieve all of your possessions."
#message 26 "You lie down on your hard bed, stretch, then curl up, trying hard to get comfortable. Your thin blanket and small pillow do not help much."
#message 27 "Shhhh! You're trying to sleep."
#message 28 "You gratefully rise from your hard old bed, stretching your aching muscles."
#message 29 "The door is closed."
#message 30 "You suddenly find yourself in your own little room. You notice that the door is closed."
#message 31 "You might try that over there in your bedroom, but not here in the hall."
#message 32 "Obviously, you have nothing to hide, Gwydion!"
#message 33 "The hallway is uninteresting, except for the tapestry on the wall."
#message 34 "You get on your hands and knees and shove it under the bed. It will be safe from the wizard's sharp eyes there."
#message 35 "Dropping to your knees, you reach under the bed and retrieve it."
#message 36 "You drop down, reach under the bed, and then realize you've never put it there!"
#message 37 "The door is wide open."
#message 38 "You consider removing the dough pieces from your ears, but decide they are too fragile. You carefully comb your scraggly hair over them so the wizard cannot detect them."




