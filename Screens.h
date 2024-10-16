#ifndef SCREENS_H
#define SCREENS_H
#include "Character.h"
#include "Party.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Screens // The Screens class displays various game screens
{
public:
    // Function declarations for each screen in the game
    void startScreenUSER();
    void battleScreenUSER(HumanPlayer user, ComputerPlayer computer);
    void attackScreenUSER(HumanPlayer user, int CharNum);
    void attackScreenUSER_target(ComputerPlayer computer);
    void saveScreen();
    void finalWinUSER();
    void finalLossUSER();
};

#endif
