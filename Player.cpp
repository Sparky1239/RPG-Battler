#include "Player.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Return party pointer
Party* Player::getParty() {
    return party;
}

// Constructor
Player::Player(Party* party, string name) : party(party), name(name) {}

// Constructor for HumanPlayer
HumanPlayer::HumanPlayer(Party* party, string name) : Player(party, name) {}

// HumanPlayer selects input
int HumanPlayer::selectInput(int totalInputs) {
    int moveIndex = -1; // Start with an invalid index
    // Take user input for move index
    while (true) {
        cout << "Enter move index (1 to " << totalInputs  << "): ";
        cin >> moveIndex;
        // Keep asking until a valid input
        if (moveIndex >= 1 && moveIndex <= totalInputs) {
            break; // Valid input, break out of the loop
        }
        cout << "Please enter a valid input." << endl;
    }
    moveIndex --;
    return moveIndex;
}

// Takes any input from player unstored
void HumanPlayer::nullResponse() {
    char charTemp;
    cout << "Enter any key";
    cin >> charTemp; // Unstored input
}

// Constructor for ComputerPlayer
ComputerPlayer::ComputerPlayer(Party* party, string name) : Player(party, name) {}

// ComputerPlayer selects input (stub implementation)
int ComputerPlayer::selectInput(int totalInputs) {
    // For now, let's randomly select a valid move index
    return rand() % totalInputs; // Random index for example
}
