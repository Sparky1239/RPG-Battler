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

void InitialiseGame();

void StartBattle();

void Battle();

void UserTurn();

void ComputerTurn();

void GameEnd();


};

Game::Game(/* args */)
{
}

Game::~Game()
{
}

#endif