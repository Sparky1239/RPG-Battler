#include "Screens.h"
#include "Party.h"
#include "Character.h"
#include "Player.h"
#include <iostream>



void Screens::startScreenUSER() {
  cout << "|-----------------------|\n";
  cout << "|      RPG BATTLER      |\n";
  cout << "|-----------------------|\n";
  cout << "| Press 1: Start Game   |\n";
  cout << "| Press 2: Exit         |\n";
  cout << "|-----------------------|\n";
}

void Screens::battleScreenUSER(HumanPlayer user, ComputerPlayer computer)  {
  cout << "|------------------------------------|\n";
  cout << "|  USER             |  ENEMY         |\n";
  cout << "|  -----------------|  ------------  |\n";
  cout << "|  "<<user.getParty()->getCharacter(0).getName()<<"  [HP: "<<user.getParty()->getCharacter(0).getHealth()<< "/"<<user.getParty()->getCharacter(0).getMaxHealth() <<"]      |  "<<computer.getParty()->getCharacter(0).getName()<<" [HP: "<<computer.getParty()->getCharacter(0).getHealth()<< "/"<<computer.getParty()->getCharacter(0).getMaxHealth() <<"]    |\n";
  cout << "|  "<<user.getParty()->getCharacter(1).getName()<<"  [HP: "<<user.getParty()->getCharacter(1).getHealth()<< "/"<<user.getParty()->getCharacter(1).getMaxHealth() <<"]      |  "<<computer.getParty()->getCharacter(1).getName()<<"    [HP: "<<computer.getParty()->getCharacter(1).getHealth()<< "/"<<computer.getParty()->getCharacter(1).getMaxHealth() <<"] |\n";
  cout << "|  "<<user.getParty()->getCharacter(2).getName()<<"  [HP: "<<user.getParty()->getCharacter(2).getHealth()<< "/"<<user.getParty()->getCharacter(2).getMaxHealth() <<"]      |  "<<computer.getParty()->getCharacter(2).getName()<<"  [HP: "<<computer.getParty()->getCharacter(2).getHealth()<< "/"<<computer.getParty()->getCharacter(2).getMaxHealth() <<"]  |\n";
  cout << "|------------------------------------|\n";
  cout << "|                SELECT              |\n";
  cout << "|  1. A                              |\n";
  cout << "|  2. B                              |\n";
  cout << "|  3. C                              |\n";
  cout << "|------------------------------------|\n";
}

void Screens::attackScreenUSER(HumanPlayer user, int CharNum) {
  cout << "|-----------------|\n";
  cout << "|     ATTACK      |\n";
  cout << "|-----------------|\n";
  cout << "| 1. "<< user.getParty()->getCharacter(CharNum).getMove(0).getName() <<"    |\n";
  cout << "| 2. "<< user.getParty()->getCharacter(CharNum).getMove(1).getName() <<"    |\n";
  cout << "| 3. "<< user.getParty()->getCharacter(CharNum).getMove(2).getName() <<"    |\n";
  cout << "| 4. "<< user.getParty()->getCharacter(CharNum).getMove(3).getName() <<"    |\n";
  cout << "|-----------------|\n";
}

void Screens::attackScreenUSER_target(ComputerPlayer computer) {
  cout << "|-----------------|\n";
  cout << "|     TARGET      |\n";
  cout << "|-----------------|\n";
  cout << "| 1. TARGETOP1    |\n";
  cout << "| 2. TARGETOP2    |\n";
  cout << "| 3. TARGETOP3    |\n";
  cout << "|                 |\n";
  cout << "|-----------------|\n";
}

void Screens::finalWinUSER() {
  cout << "|-----------------|\n";
  cout << "|    GAME WIN     |\n";
  cout << "|-----------------|\n";
  cout << "\n";
  cout << "\n";

  cout << "Press 1; Play Again \n";
  cout << "Press 2; Exit\n";
}

void Screens::finalLossUSER() {
  cout << "|-----------------|\n";
  cout << "|    GAME LOSS    |\n";
  cout << "|-----------------|\n";
  cout << "\n";
  cout << "\n";

  cout << "Press 1; Play Again \n";
  cout << "Press 2; Exit\n";
}


