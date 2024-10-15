#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Screens.h"
#include "Character.h"
#include "Move.h"

class Game
{
private:
    ComputerPlayer computer; // Comp controlled player
    HumanPlayer user;        // User controlled player
    Screens screen;          // Object to hanfle the display svreens

public:
    // Constructor to set up the game with user and comp players
    Game(ComputerPlayer computer, HumanPlayer user);

    // Starts games and asks player if they want to play
    void InitialiseGame();

    // Initialises for the battle
    void StartBattle();

    // Runs the battle using user and computer
    void Battle();

    // User turn player picks moves
    void UserTurn();

    // Computer picks moves
    void ComputerTurn();

    // This shows final screen win or loss
    void GameEnd();

    // Below are functions for saving and loading the game state
    void saveGame();
    void loadGame();
};

#endif