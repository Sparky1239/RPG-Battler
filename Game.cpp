#include "Game.h"
#include "Player.h"
#include "Party.h"
#include "Character.h"
#include <iostream>


void Game::InitialiseGame(){
    //clear console
    system("CLS");
    //bring up start screen
    startScreenUSER();
    //takes input for opening or closing
    int input = user.selectInput(2); 
    //
    if (input == 1){
        StartBattle();
    }
    //once this code stops running it should end the game
}


void Game::StartBattle() {
    system("CLS");
    std::cout << " 'battle starting' or whatever text" << std::endl;
    user.getParty()->displayParty();  //a function to display the details of the user party
    computer.getParty()->displayParty();  // same thing but for the comp party
    Battle();  // starts the main battle loop (or would it be called Main() ??)
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
    std::cout << "User turn; " << std::endl;
    //need a for loop that repeat 3 times one for each character very easy to implement
    for (size_t i = 0; i < 3; i++){
        
        // this then displays the move options (or just options for the user)
        attackScreenUSER(user.getParty()->getCharacter(i));  //attack screen should be coded to show appropriate thing
        int choice = user.selectInput(user.getParty()->getCharacter(i).); 
        // ^| gets the user input

    user.performAction(choice);  // preforms the action selected by user but this func needs to be put in/implemented in HUmanPlayer (if still having)
    std::cout << "The results of the action user selected is; " << std::endl;
    }



    user.getParty()->displayStatus();  //for whateever funciton is written that displays the current status of the player
    computer.getParty()->displayStatus();

}


void Game::ComputerTurn(){
    std::cout << "ComputerPlayer turn" << std::endl;
    int choice = computer.selectInput(computer.getParty()->countOptions());  // the random number selects the move
    computer.performAction(choice);  // Preforms the action but again needs to be put in computerPlayer (assumes function)
    std::cout << "Action results:" << std::endl;
    user.getParty()->displayStatus();

    computer.getParty()->displayStatus();
}





void Game::GameEnd(){
    // Determine and display game outcome
    if (user.getParty()->getTotalHealth() > 0) {
        std::cout<< "game won" << std::endl;

    } else {
        std::cout << "Game lost"<< std::endl;

    }
    //if we are doing a 'restart or exit' thing, this is where it goes
    std::cout << "Press 1 to restart game and any other number to exit";
    int input;
    std::cin >> input;

    if (input == 1){
        InitialiseGame();
          // restarts the game if we are doing that
    } else {
        std::cout << "Game finished" << std::endl;

        exit(0);

    }
}

//show the screen for displaying move options
void Game::displayOptions(int charNum){
    


}



