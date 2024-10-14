#ifndef SCREENS_H
#define SCREENS_H

#include "Character.h"
#include "Party.h"
#include <iostream>
using namespace std;

class Screens
{
public:
// Function declarations
void startScreenUSER();
void battleScreenUSER(HumanPlayer user, ComputerPlayer computer);
void attackScreenUSER(Character currentAttacker);
void attackScreenUSER_target(Party opposingTeam);
void finalWinUSER();
void finalLossUSER();
};
#endif
