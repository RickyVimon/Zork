# Zork
 C++ Small version of the Zork game
 Author: Ricard Vivó Montero
 
 Repository: https://github.com/RickyVimon/Zork
 License: https://github.com/RickyVimon/Zork/blob/master/License.txt

In this version of Zork, I implemented some extra features like the way of reading the stats of the enemies. I created a file Json called Bestiary in which contains all the stats from all the monsters in the game. This way, it is easier to include new monsters and to balance theis stats in further modifications.
Something similar happens with the introduction and the help options, it also reads and prints the text drom external files.
There is another feature which is the player class. In this version you can choose to become one of 3 different classes: A berserker, a Slayer or a Lancer. Everyone has its own stats and combat modifiers, so, in a firther extension of the game, more features can be added to the different classes.
The combat systems in this game is based on the board RPG games. As I included RPG stats for all the creatures, when attacking a d20 (dice of 20 faces) is rolled. If the result is higher than the targets armor, then you hit them and then Roll for damage.
In this case, each weapon has a different die type, for example, great axes would use a d12 meanwhile a sword would use a d10 and so on.. then, the base atatck modifier is added to the damage.
If the enemy is killed, it drops all the items it had as loot and the player also gains an amount of experience. If the experience is enough to level up, the players Levels Up, increasing their life according to some of their stats.

HOW TO PLAY:------------------------------------------------------------------------------------------------
These are the command you can use. The GOAL OF THE GAME is to KILL the THIEF. Once killed, the gam is finished.

- Look: This command will show you more information about the room you are in.
	You can use Look + name to look at something concrete. Example: Look chest.

- Move: You can use this command followed by the options north, south, east or west to
	move into that direction, in case there is any exit on that direction.
	You can also use the commands north, south, east and west without the word "move".

- Take: This command will allow to take whatever you write next, if that can be taken.
	Example: Take sword.

- Drop: Same as Take command but to drop objects to the ground. If you use the command Look
	after having used the command drop, you will see the dropped object on the ground.

- Equip: This command will allow you to equip your weapons and armor items. You can check
	how the objects modify your stats using the command stats. Example: Equip Sword.

- Unequip: Opposide of the command Equip. In this case, the unequipped object will still
	be in your inventory.

- Stats: Use this command to print your RPG Stats.

- Inventory: Use this command to print the list of the items you have and which ones are
	eqquiped.

- Attack: Use this command to attack the enemy of the room. Be careful! he will attack you back!
	Remember than in this tutorial you are very low level, so the chance you miss some
	attacks is high.

- Help: Prints the lists of commands.

