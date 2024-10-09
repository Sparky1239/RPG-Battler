#include "Screens.h"

void startScreenUSER() {
  cout << "|-----------------------|\n";
  cout << "|      RPG BATTLER      |\n";
  cout << "|-----------------------|\n";
  cout << "| Press 1: Start Game   |\n";
  cout << "| Press 2: Exit         |\n";
  cout << "|-----------------------|\n";
}

void battleScreenUSER() {
  cout << "|------------------------------------|\n";
  cout << "|  USER             |  ENEMY         |\n";
  cout << "|  -----------------|  ------------  |\n";
  cout << "|  A  [HP: 100]     |  X [HP: 80]    |\n";
  cout << "|  B  [HP: 60]      |  Y    [HP: 90] |\n";
  cout << "|  C [HP: 120]      |  Z  [HP: 100]  |\n";
  cout << "|------------------------------------|\n";
  cout << "|                SELECT              |\n";
  cout << "|  1. A                              |\n";
  cout << "|  2. B                              |\n";
  cout << "|  3. C                              |\n";
  cout << "|------------------------------------|\n";
}

void attackScreenUSER() {
  cout << "|-----------------|\n";
  cout << "|     ATTACK      |\n";
  cout << "|-----------------|\n";
  cout << "| 1. ATTACKOP1    |\n";
  cout << "| 2. ATTACKOP2    |\n";
  cout << "| 3. ATTACKOP3    |\n";
  cout << "| 4. ATTACKOP4    |\n";
  cout << "|-----------------|\n";
}

void finalWinUSER() {
  cout << "|-----------------|\n";
  cout << "|    GAME WIN     |\n";
  cout << "|-----------------|\n";
  cout << "\n";
  cout << "\n";

  cout << "Press 1; Play Again \n";
  cout << "Press 2; Exit\n";
}

void finalLossUSER() {
  cout << "|-----------------|\n";
  cout << "|    GAME LOSS    |\n";
  cout << "|-----------------|\n";
  cout << "\n";
  cout << "\n";

  cout << "Press 1; Play Again \n";
  cout << "Press 2; Exit\n";
}
