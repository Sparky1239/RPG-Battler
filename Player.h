#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Party.h"

using namespace std;

// Abstract Player class
class Player {
protected:
    Party* party;
    string name;

public:
    // Constructor
    Player(Party* party, string name);

    virtual ~Player() = default; // Virtual destructor for cleanup in derived classes

    virtual int selectInput(int totalInputs) = 0; // Pure virtual function

    // Return party pointer
    Party* getParty();
};

// HumanPlayer class
class HumanPlayer : public Player {
public:
    // Constructor
    HumanPlayer(Party* party, string name);

    int selectInput(int totalInputs) override;

    // Takes any input from player unstored
    void nullResponse();
};

// ComputerPlayer class
class ComputerPlayer : public Player {
public:
    // Constructor
    ComputerPlayer(Party* party, string name);

    int selectInput(int totalInputs) override;
};

#endif
