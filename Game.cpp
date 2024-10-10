

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

void Game::StartBattle(){
//what needs to happen at the start of battle


//then go nto another function which is the battle loop
}


void Game::Battle(){
    //while loop for checking if health 0
    while (user.getParty()->getCharacter(0).getHealth() +
     user.getParty()->getCharacter(1).getHealth() + 
     user.getParty()->getCharacter(2).getHealth() > 0){



        
     }
}

void Game::UserTurn();

void Game::ComputerTurn();

void Game::GameEnd();