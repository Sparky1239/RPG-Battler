#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Screens.h"


class Game
{
private:
    ComputerPlayer computer;
    HumanPlayer user;

public:

// starts games and asks player if they want to play
void InitialiseGame();

//initialises for the battle
void StartBattle();

//runs the battle using user and computer
void Battle();

//user turn player picks moves
void UserTurn();

//computer picks moves
void ComputerTurn();

//shows final screen win or loss
void GameEnd();



};

Game::Game(/* args */)
{
}

Game::~Game()
{
}

#endif