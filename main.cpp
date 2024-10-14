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

    // int choice = 0;

    // // Display the start screen
    // startScreenUSER();
    // cout << "What is your choice?: ";
    // cin >> choice;
    // cout << "\n";

    // // Check if the player wants to start the game
    // if (choice == 1) {
    //     while (true) { // Keep playing until the user decides to exit

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
            Move SmallHeal("Small Heal", -10); // Negative damage indicates healing
            Move MediumHeal("Medium Heal", -20); // Negative damage indicates healing
            Move LargeHeal("Large Heal", -30); // Negative damage indicates healing
            Move XLargeHeal("X-Large Heal", -40); // Negative damage indicates healing

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
            Move S_Heal("Small Heal", -5); // Negative damage indicates healing
            Move M_Heal("Medium Heal", -10); // Negative damage indicates healing
            Move L_Heal("Large Heal", -20); // Negative damage indicates healing
            Move XL_Heal("X-Large Heal", -40); // Negative damage indicates healing

            
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
            Seraphine.addMove(SmallHeal);
            Seraphine.addMove(MediumHeal);
            Seraphine.addMove(LargeHeal);
            Seraphine.addMove(XLargeHeal);

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
            witch.addMove(S_Heal);
            witch.addMove(M_Heal);
            witch.addMove(L_Heal);
            witch.addMove(XL_Heal);

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
            HumanPlayer humanPlayer;
            humanPlayer.name = "CS_RANGER";
            humanPlayer.party = UserParty;

            ComputerPlayer computerPlayer;
            computerPlayer.name = "PAPAGO";
            computerPlayer.party = ComputerParty;

            // // Start the game
           Game startGame;
            startGame.InitialiseGame();
            
         
            
        
            // Ask the player if they want to play again
            // int playAgainChoice;
            // cout << "Do you want to play again? (1 for Yes, 2 for No): ";
            // cin >> playAgainChoice;

            // if (playAgainChoice != 1) {
            //     cout << "Exiting the game. Goodbye!\n";
            //     break;
            // }
        // }
    // }
    //   else {
    //     cout << "Exiting the game. Goodbye!\n";
    //  }

    return 0;
}


