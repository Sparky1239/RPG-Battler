#include "Player.h"
#include <iostream>
#include <cstdlib>
using namespace std;
void HumanPlayer::selectMove(Character &attacker, Character &target) {
    int moveIndex;
    
    cout << "Select a move for " << attacker.name << ": ";
    
    for (int i = 0; i < attacker.moves.size(); i++) {
        cout << i << ": " << attacker.moves[i].name << " (Damage: " << attacker.moves[i].damage << ")\n";
    }
   
    cin >> moveIndex; // prompt user for move index
   
    attacker.performMove(attacker.moves[moveIndex], target);
}



void ComputerPlayer::selectMove(Character &attacker, Character &target) {
    
    int moveIndex = rand() % attacker.moves.size();
    
    cout << attacker.name << " (Computer) uses " << attacker.moves[moveIndex].name << " on " << target.name << "!\n";
    
    attacker.performMove(attacker.moves[moveIndex], target);
}
