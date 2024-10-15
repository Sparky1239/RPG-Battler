#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Party.h"

using namespace std;

// Abstract Player class
class Player
{
protected:
    Party *party; // Pointer to the players party
    string name;  // Name of player

public:
    // Constructor for the player class
    Player(Party *party, string name);
    virtual ~Player() = default;                  // Virtual destructor for cleanup in derived classes
    virtual int selectInput(int totalInputs) = 0; // Pure virtual function
    Party *getParty();                            // Return party pointer
};

// HumanPlayer class
class HumanPlayer : public Player
{
public:
    // Constructor
    HumanPlayer(Party *party, string name);
    int selectInput(int totalInputs) override;
    // Takes any input from player unstored
    void nullResponse();
};

// ComputerPlayer class
class ComputerPlayer : public Player
{
public:
    // Constructor
    ComputerPlayer(Party *party, string name);
    int selectInput(int totalInputs) override;
};

#endif
