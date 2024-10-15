#include "Game.h"
#include "Player.h"
#include "Party.h"
#include "Character.h"
#include "Move.h"
#include "Screens.h"
#include <fstream>
#include <iostream>


Game::Game(ComputerPlayer computer, HumanPlayer user) : computer(computer), user(user) {
    Screens screen;
}

void Game::InitialiseGame(){
    //clear console
    system("clear");
    //bring up start screen
    screen.startScreenUSER();
    //takes input for opening or closing
    int input = user.selectInput(3); 
    //
    if (input == 0){
        Battle();
    }
    else if(input == 1){
        loadGame();
        Battle();
    }
    //once this code stops running it should end the game
}


void Game::Battle(){
    //while loop for checking if health 0

        while (user.getParty()->getTotalHealth() > 0 && computer.getParty()->getTotalHealth() > 0) {
        UserTurn();
        if (computer.getParty()->getTotalHealth() <= 0) {
            break;  // (exits loop if 0 for comp party health 0)
        }
        ComputerTurn();
    }
    GameEnd();
}


void Game::UserTurn(){
    std::cout << "Your turn: " << std::endl;

    screen.battleScreenUSER(user, computer);
    // Iterate through the user's party for moves
    for (int i = 0; i < 3; i++){
        // Prevents characters with 0 health from performing a move
        if(user.getParty()->getCharacter(i).getHealth() > 0){
            if (computer.getParty()->getTotalHealth() <= 0) {
                break;  // Exit the loop if the computer party health is 0
            }
            // Display move options for the user
            screen.attackScreenUSER(user, i);
            int moveChoice = user.selectInput(user.getParty()->getCharacter(i).getMoveCount());
            
            // Display target selection screen
            screen.attackScreenUSER_target(computer);
            int targetChoice = user.selectInput(computer.getParty()->getPartySize());

            Move selectedMove = user.getParty()->getCharacter(i).getMove(moveChoice);
            Character& targetEnemy = computer.getParty()->getCharacter(targetChoice);

            // Perform the selected move on the chosen target
            user.getParty()->getCharacter(i).performMove(selectedMove, targetEnemy);
            
            // Display move result
            std::cout << user.getParty()->getCharacter(i).getName() 
                      << " used " << selectedMove.getName() 
                      << " on " << targetEnemy.getName() << std::endl;
            screen.battleScreenUSER(user, computer);

            // Waits for user input to continue
            user.nullResponse();
        }
    }
}



void Game::ComputerTurn(){

        std::cout << "Their turn" << std::endl;
    //need a for loop that repeat 3 times one for each character very easy to implement
    for (int i = 0; i < 3; i++){
        //doesnt let characters at 0 health have a move
        if(computer.getParty()->getCharacter(i).getHealth()>0){
            if (user.getParty()->getTotalHealth() <= 0) {
                break;  // (exits loop if 0 for comp party health 0)
            }
            
            int moveChoice = computer.selectInput(computer.getParty()->getCharacter(i).getMoveCount()); 
            // ^| gets the computer input
            
            //chooses target
            int targetChoice = computer.selectInput(user.getParty()->getPartySize());

            Move selectedMove = computer.getParty()->getCharacter(i).getMove(moveChoice);

            Character& targetEnemy = user.getParty()->getCharacter(targetChoice);

            computer.getParty()->getCharacter(i).performMove(selectedMove, targetEnemy);  // preforms the action selected by user but this func needs to be put in/implemented in HUmanPlayer (if still having)
    
            //text needs to tell what move was used could just use the screen
            std::cout << computer.getParty()->getCharacter(i).getName() <<" used "<< selectedMove.getName() << " on " << targetEnemy.getName() <<  std::endl;
            screen.battleScreenUSER(user, computer);
            //user has to press some input to continue
            user.nullResponse();
                // This prompts to save the game at the end of the computer's turn
    screen.saveScreen();
    int saveOption = user.selectInput(3);  // This then takes the input: 0, 1, or 2

    if (saveOption == 1){
        saveGame();  // This saves the game if the user selects to save
        std::cout << "Saved\n";
    } else if (saveOption == 2){
        saveGame();  // Save the game and exit
        std::cout << "Saved and exiting\n";
        exit(0);
    }
        }
    }

}


void Game::GameEnd() {
    int input;
    // Determines and displays the game outcome
    if (user.getParty()->getTotalHealth() > 0) {
       screen.finalWinUSER();
    } else {
        screen.finalLossUSER();
    }
    

    input = user.selectInput(3);

    if (input == 0){
        for (int i = 0; i<3; i++){
            user.getParty()->getCharacter(i).setHealth(user.getParty()->getCharacter(i).getMaxHealth());
            computer.getParty()->getCharacter(i).setHealth(computer.getParty()->getCharacter(i).getMaxHealth());
        }
        InitialiseGame();  //Restarts the game
    } else if (input == 1){
        std::cout << "Game ended" << std::endl;
        exit(0);
    } else if (input == 2) {
        saveGame();  //This saves the game checkpoint
        exit(0);
    }
}


void Game::saveGame(){
    std::ofstream outFile("game_save.txt");
    if (outFile.is_open()) {
        // Saves user party
        for (int i=0; i<user.getParty()->getPartySize();i++){
            Character& userChar = user.getParty()->getCharacter(i);
            outFile<<userChar.getName()<< " " << userChar.getHealth()<< " "<< userChar.getMaxHealth()<< "\n";
        }
        
        // Saves the computer party
        for (int i = 0; i < computer.getParty()->getPartySize();i++){
            Character& compChar = computer.getParty()->getCharacter(i);
            outFile << compChar.getName() << " " << compChar.getHealth() << " " << compChar.getMaxHealth() << "\n";
        }

        outFile.close();
        std::cout << "Checkpoint saved" << std::endl;
    } else {
        std::cerr << "Cannot save checkpoint (error)"<< std::endl;
    }
}

// A function to load the saved game state
void Game::loadGame(){
    std::ifstream inFile("game_save.txt");
    if (inFile.is_open()){
        std::string name;
        int health, maxHealth;

        // Loads the user party
        for (int i = 0; i < user.getParty()->getPartySize(); ++i) {
            inFile >> name >> health >> maxHealth;
            Character& userChar = user.getParty()->getCharacter(i);
            userChar.setHealth(health);
        }

        // Loads the computer party
        for (int i = 0; i < computer.getParty()->getPartySize(); ++i) {
            inFile >> name >> health >> maxHealth;
            Character& compChar = computer.getParty()->getCharacter(i);
            compChar.setHealth(health);
        }

        inFile.close();
        std::cout << "Checkpoint loaded" << std::endl;
    } else {
        std::cerr << "Error loading the checkpoint" << std::endl;
    }
}




    


