#include "Game.h"
#include "Player.h"
#include "Party.h"
#include "Character.h"
#include "Move.h"
#include "Screens.h"
#include <fstream>
#include <iostream>

// This game constructor intilizies the user and comp players and the screen
Game::Game(ComputerPlayer computer, HumanPlayer user) : computer(computer), user(user)
{
    Screens screen;
}

// Below initilizes the game, clears the terminal and startst the screen game
void Game::InitialiseGame()
{
    system("clear");                 // clear console
    screen.startScreenUSER();        // bring up start screen
    int input = user.selectInput(3); // Where the user selects either the start or exit input

    // The below loop is for if the user chooses to start the battle
    if (input == 0)
    {
        Battle();
    }
    else if (input == 1)
    {
        loadGame();
        Battle();
    }
}

// Below is the main battle loop that continues until the total party health goes to 0
void Game::Battle()
{
    // Below is a while loop that operates while the user and comp parties...
    //... have remaining health
    while (user.getParty()->getTotalHealth() > 0 && computer.getParty()->getTotalHealth() > 0)
    {
        UserTurn(); // User turn to preform moves
        if (computer.getParty()->getTotalHealth() <= 0)
        {
            break; // Breaks if the comp parties health goes to 0
        }
        ComputerTurn(); // Comps turn to perform the moves
    }
    GameEnd(); // Game ends after the battle
}

// Below function handles users turn
void Game::UserTurn()
{
    std::cout << "Your turn: " << std::endl;
    screen.battleScreenUSER(user, computer);
    for (int i = 0; i < 3; i++) // Iterate through the user's party for moves
    {
        if (user.getParty()->getCharacter(i).getHealth() > 0) // Prevents characters with 0 health from performing a move
        {
            if (computer.getParty()->getTotalHealth() <= 0)
            {
                break; // Exit the loop if the computer party health is 0
            }
            screen.attackScreenUSER(user, i); // Display move options for the user
            int moveChoice = user.selectInput(user.getParty()->getCharacter(i).getMoveCount());

            // Display target selection screen
            screen.attackScreenUSER_target(computer);
            int targetChoice = user.selectInput(computer.getParty()->getPartySize());

            Move selectedMove = user.getParty()->getCharacter(i).getMove(moveChoice);
            Character &targetEnemy = computer.getParty()->getCharacter(targetChoice);

            // Performs the selected move on the chosen target
            user.getParty()->getCharacter(i).performMove(selectedMove, targetEnemy);

            // Displays the moves results
            std::cout << user.getParty()->getCharacter(i).getName()
                      << " used " << selectedMove.getName()
                      << " on " << targetEnemy.getName() << std::endl;
            screen.battleScreenUSER(user, computer);

            // Waits for a user input to continue
            user.nullResponse();
        }
    }
}

// Below function deals with the computers turn

void Game::ComputerTurn()
{
    std::cout << "Their turn" << std::endl;

    // Below loops through each character in the comps party
    for (int i = 0; i < 3; i++)
    {
        if (computer.getParty()->getCharacter(i).getHealth() > 0)
        {
            if (user.getParty()->getTotalHealth() <= 0)
            {
                break; // Stops if the user party has no health left
            }
            // Randomly selects a move and target for the computer
            int moveChoice = computer.selectInput(computer.getParty()->getCharacter(i).getMoveCount());
            int targetChoice = computer.selectInput(user.getParty()->getPartySize());
            Move selectedMove = computer.getParty()->getCharacter(i).getMove(moveChoice);
            Character &targetEnemy = user.getParty()->getCharacter(targetChoice);

            // Peforms the moves randomnly selected on the chosen character
            computer.getParty()->getCharacter(i).performMove(selectedMove, targetEnemy);
            std::cout << computer.getParty()->getCharacter(i).getName() << " used " << selectedMove.getName() << " on " << targetEnemy.getName() << std::endl;

            // Displays the battle screen after the move
            screen.battleScreenUSER(user, computer);

            // Pauses for the user to press a key
            user.nullResponse();

            screen.saveScreen();
            int saveOption = user.selectInput(3);

            if (saveOption == 1)
            {
                saveGame();
                std::cout << "Saved\n";
            }
            else if (saveOption == 2)
            {
                saveGame();
                std::cout << "Saved and exiting\n";
                exit(0);
            }
        }
    }
}

// Below function determines the winner, displays the end screen and gives options for restart or exit
void Game::GameEnd()
{
    int input;

    // Below checks whether user party has health left
    if (user.getParty()->getTotalHealth() > 0)
    {
        screen.finalWinUSER(); // User wins
    }
    else
    {
        screen.finalLossUSER(); // Computer wins
    }

    input = user.selectInput(3); // User chooses an option of play again, save game, or exit

    if (input == 0)
    {
        // Resets the health for all characters and restart the game
        for (int i = 0; i < 3; i++)
        {
            user.getParty()->getCharacter(i).setHealth(user.getParty()->getCharacter(i).getMaxHealth());
            computer.getParty()->getCharacter(i).setHealth(computer.getParty()->getCharacter(i).getMaxHealth());
        }
        InitialiseGame();
    }
    else if (input == 1)
    {
        std::cout << "Game ended" << std::endl;
        exit(0);
    }
    else if (input == 2)
    {
        saveGame(); // saves the current game state
        exit(0);
    }
}

// Below saves the current game state to a file

void Game::saveGame()
{
    std::ofstream outFile("game_save.txt");
    if (outFile.is_open())
    {

        for (int i = 0; i < user.getParty()->getPartySize(); i++)
        {
            Character &userChar = user.getParty()->getCharacter(i);
            outFile << userChar.getName() << " " << userChar.getHealth() << " " << userChar.getMaxHealth() << "\n";
        }

        // Save computer party data

        for (int i = 0; i < computer.getParty()->getPartySize(); i++)
        {
            Character &compChar = computer.getParty()->getCharacter(i);
            outFile << compChar.getName() << " " << compChar.getHealth() << " " << compChar.getMaxHealth() << "\n";
        }

        outFile.close();
        std::cout << "Checkpoint saved" << std::endl;
    }
    else
    {
        std::cerr << "Cannot save checkpoint (error)" << std::endl;
    }
}

// Below loads the saved game state from a file
void Game::loadGame()
{
    std::ifstream inFile("game_save.txt");
    if (inFile.is_open())
    {
        std::string name;
        int health, maxHealth;

        // Below loads user party data
        for (int i = 0; i < user.getParty()->getPartySize(); ++i)
        {
            inFile >> name >> health >> maxHealth;
            Character &userChar = user.getParty()->getCharacter(i);
            userChar.setHealth(health);
        }

        // Below load computer party data
        for (int i = 0; i < computer.getParty()->getPartySize(); ++i)
        {
            inFile >> name >> health >> maxHealth;
            Character &compChar = computer.getParty()->getCharacter(i);
            compChar.setHealth(health);
        }

        inFile.close();
        std::cout << "Checkpoint loaded" << std::endl;
    }
    else
    {
        std::cerr << "Error loading the checkpoint" << std::endl;
    }
}
