#ifndef SCREENS_H
#define SCREENS_H

#include "Character.h"
#include "Party.h"
#include <iostream>
using namespace std;

// Function declarations
void startScreenUSER();
void battleScreenUSER(Party user, Party computer);
void attackScreenUSER(character currentAttacker);
void finalWinUSER();
void finalLossUSER();

#endif
