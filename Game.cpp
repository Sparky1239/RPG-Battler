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
    //clears console
    system("clear");
    //bring up start screen
    screen.startScreenUSER();
    
    std::cout << "Press 1: Start New Game\n";
    std::cout << "Press 2: Load Game\n";
    std::cout << "Press 3: Exit\n";
    
    //takes input for opening or closing
    int input = user.selectInput(3); 
    
    if (input == 0){ // Start new game
        Battle();
    } else if (input == 1){ //loads saved game
        loadGame();
        Battle(); // continues the battle with loaded stats previously saved
    } else if (input == 2){ // exits the game
        exit(0);
    }
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
    //need a for loop that repeat 3 times one for each character very easy to implement
    for (size_t i = 0; i < 3; i++){
        //doesnt let characters at 0 health have a move
        if(user.getParty()->getCharacter(i).getHealth()>0){

            screen.battleScreenUSER(user, computer);
    
            //user has to press some input to continue
            user.nullResponse();
            
            if (computer.getParty()->getTotalHealth() <= 0) {
                break;  // (exits loop if 0 for comp party health 0)
            }
            // this then displays the move options (or just options for the user)
            screen.attackScreenUSER(user, i);  //attack screen should be coded to show appropriate thing
            int moveChoice = user.selectInput(user.getParty()->getCharacter(i).getMoveCount()); 
            // ^| gets the user input
            //displays target screen
            screen.attackScreenUSER_target(computer);
            //chooses target
            int targetChoice = user.selectInput(computer.getParty()->getPartySize());

            Move selectedMove = user.getParty()->getCharacter(i).getMove(moveChoice);

            Character& targetEnemy = computer.getParty()->getCharacter(targetChoice);


            user.getParty()->getCharacter(i).performMove(selectedMove, targetEnemy);  // preforms the action selected by user but this func needs to be put in/implemented in HUmanPlayer (if still having)
    
            //text needs to tell what move was used could just use the screen
            std::cout << user.getParty()->getCharacter(i).getName() <<" used "<< selectedMove.getName() << " on " << targetEnemy.getName() <<  std::endl;
            screen.battleScreenUSER(user, computer);
    
            //user has to press some input to continue
            user.nullResponse();
        }
    }

}


void Game::ComputerTurn(){

        std::cout << "Their turn" << std::endl;
    //need a for loop that repeat 3 times one for each character very easy to implement
    for (size_t i = 0; i < 3; i++){
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
    
    std::cout << "Press 1: Play Again\n";
    std::cout << "Press 2: Exit\n";
    std::cout << "Press 3: Save Game\n";
    std::cin >> input;

    if (input == 1){
        for (int i = 0; i<3; i++){
            user.getParty()->getCharacter(i).setHealth(user.getParty()->getCharacter(i).getMaxHealth());
            computer.getParty()->getCharacter(i).setHealth(computer.getParty()->getCharacter(i).getMaxHealth());
        }
        InitialiseGame();  //Restarts the game
    } else if (input == 2){
        std::cout << "Game ended" << std::endl;
        exit(0);
    } else if (input == 3) {
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




    


