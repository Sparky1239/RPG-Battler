#include "Player.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Return party pointer
Party *Player::getParty()
{
    return party;
}

// Constructor for the player class
Player::Player(Party *party, string name) : party(party), name(name) {}

// Constructor for HumanPlayer
HumanPlayer::HumanPlayer(Party *party, string name) : Player(party, name) {}

// HumanPlayer selects input
int HumanPlayer::selectInput(int totalInputs)
{
    int moveIndex = -1; // Start with an invalid index
    // Take user input for move index, loops until valid input recieved
    while (true)
    {
        cout << "Enter move index (1 to " << totalInputs << "): ";
        cin >> moveIndex;
        // Keep asking until a valid input
        if (moveIndex >= 1 && moveIndex <= totalInputs)
        {
            break; // Valid input, break out of the loop
        }
        cout << "Please enter a valid input." << endl;
    }
    moveIndex--; // This adjusts for a 0 based index
    return moveIndex;
}

// Below function takes any input from player unstored (used for pauses)
void HumanPlayer::nullResponse()
{
    char charTemp;
    cout << "Enter any key";
    cin >> charTemp; // Unstored input
}

// Constructor for ComputerPlayer
ComputerPlayer::ComputerPlayer(Party *party, string name) : Player(party, name) {}

// Function to let the computer select a move randomnly
int ComputerPlayer::selectInput(int totalInputs)
{
    return rand() % totalInputs; // Randonly select an input
}
