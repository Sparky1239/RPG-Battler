#include "Game.h"
#include "Player.h"
#include "Character.h"
#include "Move.h"
#include "Party.h"
#include "Screens.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    srand(time(0));  // Seed the random number generator

    

            // // Define moves for Luffy (Tank-type)
            Move SeriousPunch("Serious Punch", 20);
            Move Rasengan("Rasengan", 30);
            Move FirePunch("Fire Punch", 55);
            Move Gear4("Gear4", 65);
            
             // // Define moves for Gandalf (Mage-type)
            Move InfernoBlast("Inferno Blast", 30);
            Move SpritBomb("Sprit Bomb", 40);
            Move UnlimitedVoid("Unlimited Void", 55);
            Move Apocalypse("Apocalypse", 75);

            // // Define moves for Seraphine (Support-type)
            Move SmallPosion("Small Poison", 10); 
            Move MediumPosion("Medium Poison", 20); 
            Move LargePoison("Large Poison", 30); 
            Move XLargePoison("X-Large Poison", 40); 

            // // Define moves for Golem
            Move Punch("Punch", 30);
            Move Crunch("Crunch", 20);
            Move EarthQuake("EarthQuake", 45);
            Move Bulldoze("Bulldoze", 57);
            
             // // Define moves for Goblin
            Move slash("Slash", 20);
            Move heavySlash("Heavy Slash", 40);
            Move fireball("Fireball", 25);
            Move iceSpike("Ice Spike", 30);

            // // Define moves for Witch
            Move S_Spell("Small Spell", 5); 
            Move M_Spell("Medium Spell", 10); 
            Move L_Spell("Large Spell", 20); 
            Move XL_Spell("X-Large Spell", 40); 

            
            // // Create characters for user's party
            Character Luffy("Luffy", 600,600);
            Luffy.addMove(SeriousPunch);
            Luffy.addMove(Rasengan);
            Luffy.addMove(FirePunch);
            Luffy.addMove(Gear4);

            Character Gandalf("Gandalf",450,450);
            Gandalf.addMove(InfernoBlast);
            Gandalf.addMove(SpritBomb);
            Gandalf.addMove(UnlimitedVoid);
            Gandalf.addMove(Apocalypse);
               
            Character Seraphine("Seraphine",300,300);
            Seraphine.addMove(SmallPosion);
            Seraphine.addMove(MediumPosion);
            Seraphine.addMove(LargePoison);
            Seraphine.addMove(XLargePoison);

            // Create characters for Computer's party 
            Character golem("Golem", 700,700);
            golem.addMove(Punch);
            golem.addMove(Crunch);
            golem.addMove(EarthQuake);
            golem.addMove(Bulldoze);

            Character goblin("Goblin", 300,300);
            goblin.addMove(fireball);
            goblin.addMove(iceSpike);
            goblin.addMove(heavySlash);
            goblin.addMove(slash);
            
            Character witch("Witch", 280, 280);
            witch.addMove(S_Spell);
            witch.addMove(M_Spell);
            witch.addMove(L_Spell);
            witch.addMove(XL_Spell);

            // // Create parties for User
            Party* UserParty = new Party(3);
            UserParty->addCharacter(Luffy); // Add Character to the User party
            UserParty->addCharacter(Gandalf);
            UserParty->addCharacter(Seraphine);
             
             // // Create parties for Computer
            Party* ComputerParty = new Party(3);
            ComputerParty->addCharacter(golem);// Add characters to the Computer Party
            ComputerParty->addCharacter(goblin); 
            ComputerParty->addCharacter(witch);
            
            // // Create players
            HumanPlayer humanPlayer(UserParty, "CS_RANGER");
            
            ComputerPlayer computerPlayer(ComputerParty, "PAPAGO");


            Screens screen;

            // // Start the game

           Game startGame(computerPlayer,humanPlayer,screen);

            startGame.InitialiseGame();
            
         
            
        

    return 0;
}


