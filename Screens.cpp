#include "Screens.h"
#include "Party.h"
#include "Character.h"
#include "Player.h"
#include <iomanip>
#include <iostream>

using namespace std;

void Screens::startScreenUSER() {
      cout <<"\n";
  cout << "|-----------------------|\n";
  cout << "|      RPG BATTLER      |\n";
  cout << "|-----------------------|\n";
  cout << "| Press 1: Start Game   |\n";
  cout << "| Press 2: Load Game    |\n";
  cout << "| Press 3: Exit         |\n";
  cout << "|-----------------------|\n";
      cout <<"\n";
}

void Screens::battleScreenUSER(HumanPlayer user, ComputerPlayer computer)  {
         cout <<"\n";
    cout << "|---------------------------------------------------------------------------|\n";
    cout << "|  USER                                   |  ENEMY                          |\n";
    cout << "|-----------------------------------------|---------------------------------|\n";
    

    // Display user and enemy characters with dynamic padding for consistent formatting
    for (int i = 0; i < 3; ++i) {
        cout << "| " << setw(10) << left << user.getParty()->getCharacter(i).getName() << " [HP: "
             << setw(3) << right << user.getParty()->getCharacter(i).getHealth() << "/"
             << setw(3) << user.getParty()->getCharacter(i).getMaxHealth() << "]" 
             << setw(16) << " " << "| "
             << setw(10) << left << computer.getParty()->getCharacter(i).getName() << " [HP: "
             << setw(3) << right << computer.getParty()->getCharacter(i).getHealth() << "/"
             << setw(3) << computer.getParty()->getCharacter(i).getMaxHealth() << "]"
             << setw(8) << " " << "|\n";
    cout << "|---------------------------------------------------------------------------|\n";
    }

    cout <<"\n";
}

void Screens::attackScreenUSER(HumanPlayer user, int CharNum) {

    cout << "\n";
    cout << "|-----------------------------|\n";
    cout << "|     ATTACK                  |\n";
    cout << "|-----------------------------|\n";

    // Calculate spaces based on the length of each move name, ensuring consistent alignment
    cout << "|    " << user.getParty()->getCharacter(CharNum).getName() << ": is Attacking! "       
         << string(9 - user.getParty()->getCharacter(CharNum).getName().length(), ' ') << "|\n";
    cout << "|                             |\n";
    cout << "| 1. " << user.getParty()->getCharacter(CharNum).getMove(0).getName() 
         << string(25 - user.getParty()->getCharacter(CharNum).getMove(0).getName().length(), ' ') << "|\n";

    cout << "| 2. " << user.getParty()->getCharacter(CharNum).getMove(1).getName() 
         << string(25 - user.getParty()->getCharacter(CharNum).getMove(1).getName().length(), ' ') << "|\n";

    cout << "| 3. " << user.getParty()->getCharacter(CharNum).getMove(2).getName() 
         << string(25 - user.getParty()->getCharacter(CharNum).getMove(2).getName().length(), ' ') << "|\n";

    cout << "| 4. " << user.getParty()->getCharacter(CharNum).getMove(3).getName() 
         << string(25 - user.getParty()->getCharacter(CharNum).getMove(3).getName().length(), ' ') << "|\n";

    cout << "|-----------------------------|\n";
    cout << "\n";
}

void Screens::attackScreenUSER_target(ComputerPlayer computer) {
    cout << "\n";
  cout << "|-----------------|\n";
  cout << "|     TARGET      |\n";
  cout << "|-----------------|\n";
  cout << "| 1. "<< computer.getParty()->getCharacter(0).getName() <<"        |\n";
  cout << "| 2. "<< computer.getParty()->getCharacter(1).getName() <<"       |\n";
  cout << "| 3. "<< computer.getParty()->getCharacter(2).getName() <<"        |\n";
  cout << "|                 |\n";
  cout << "|-----------------|\n";
    cout << "\n";
}


void Screens::saveScreen() {
    cout << "\n";
  cout << "|-----------------|\n";
  cout << "|    Save Game?   |\n";
  cout << "|-----------------|\n";
  cout << "| 1. No           |\n";
  cout << "| 2. Save         |\n";
  cout << "| 3. Save and Exit|\n";  
  cout << "|-----------------|\n";

}

void Screens::finalWinUSER() {
    cout << "\n";
  cout << "|-----------------|\n";
  cout << "|    GAME WIN     |\n";
  cout << "|-----------------|\n";
  cout << "| 1. Play Again   |\n";
  cout << "| 2. Exit         |\n";
  cout << "| 3. Save Game    |\n";  
  cout << "|-----------------|\n";
}

void Screens::finalLossUSER() {
    cout << "\n";
  cout << "|-----------------|\n";
  cout << "|    GAME LOSS    |\n";
  cout << "|-----------------|\n";
  cout << "| 1. Play Again   |\n";
  cout << "| 2. Exit         |\n";
  cout << "| 3. Save Game    |\n";  
  cout << "|-----------------|\n";
}


