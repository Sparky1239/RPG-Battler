#include "Game.h"
#include "Player.h"
#include "Party.h"
#include "Character.h"
#include <iostream>


Game::Game(ComputerPlayer computer, HumanPlayer user, Screens screen) : computer(computer), user(user), screen(screen) {}

void Game::InitialiseGame(){
    //clear console
    system("CLS");
    //bring up start screen
    screen.startScreenUSER();
    //takes input for opening or closing
    int input = user.selectInput(2); 
    //
    if (input == 1){
        StartBattle();
    }
    //once this code stops running it should end the game
}


//void Game::StartBattle() {
//    system("CLS");
//    std::cout << " 'battle starting' or whatever text" << std::endl;
//    user.getParty()->displayParty();  //a function to display the details of the user party
//    computer.getParty()->displayParty();  // same thing but for the comp party
//    Battle();  // starts the main battle loop (or would it be called Main() ??)
//}



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
        //doesnt let characters at 0 health have a move
        if(user.getParty()->getCharacter(i).getHealth()>0){
        // this then displays the move options (or just options for the user)
        screen.attackScreenUSER(user.getParty()->getCharacter(i));  //attack screen should be coded to show appropriate thing
        int moveChoice = user.selectInput(user.getParty()->getCharacter(i).getMoveCount()); 
        // ^| gets the user input
        //displays target screen
        screen.attackScreenUSER_target(computer);
        //chooses target
        int targetChoice = user.selectInput(computer.getParty()->getPartySize());

    user.getParty()->getCharacter(i).performMove(user.getParty()->getCharacter(i).getMove(moveChoice), computer.getParty()->getCharacter(targetChoice) );  // preforms the action selected by user but this func needs to be put in/implemented in HUmanPlayer (if still having)
    
    //text needs to tell what move was used could just use the screen
    std::cout << "The results of the action user selected is; " << std::endl;
    screen.battleScreenUSER(user, computer);
    
    //user has to press some input to continue
    user.nullResponse();
        }
    }

}


void Game::ComputerTurn(){

        std::cout << "ComputerPlayer turn" << std::endl;
    //need a for loop that repeat 3 times one for each character very easy to implement
    for (size_t i = 0; i < 3; i++){
        //doesnt let characters at 0 health have a move
        if(user.getParty()->getCharacter(i).getHealth()>0){
            
            int moveChoice = computer.selectInput(user.getParty()->getCharacter(i).getMoveCount()); 
            // ^| gets the computer input
            
            //chooses target
            int targetChoice = computer.selectInput(computer.getParty()->getPartySize());

            computer.getParty()->getCharacter(i).performMove(computer.getParty()->getCharacter(i).getMove(moveChoice), user.getParty()->getCharacter(targetChoice) );  // preforms the action selected by user but this func needs to be put in/implemented in HUmanPlayer (if still having)
    
            //text needs to tell what move was used could just use the screen
            std::cout << "The results of the action user selected is; " << std::endl;
            screen.battleScreenUSER(user, computer);
            //user has to press some input to continue
            user.nullResponse();
        }
    }

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


    


