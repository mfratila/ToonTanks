This is a little project that I've worked on in June of 2021.
The premise of the game is that the player controls a tank, that shoots projectiles and needs to eliminate all the enemies from the level in order to complete it.
In order to achieve the core gameplay of the game I've created a base class that the Player Pawn and the enemy Turret Pawn will inherit from.
I've then created a projectile class that will instantiate on user input that will shoot towards the rotation of the controlled turret.
The health component containts a delegate and a dynamic function that will make the class that has this component attached to it to receive damage, until the health variable reaches 0 and notifies the GameMode that the actor died.
The Game Mode class handles and manages the course of the game, tracks what actors died, and decides if the game is over or the game is won.
