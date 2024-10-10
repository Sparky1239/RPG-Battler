#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Party.h"
using namespace std;

// Abstract Player class
class Player {
protected:
  string name;
  Party* party;

public:
  virtual int selectInput(int totalInputs) ;  // Polymorphism

  //return party pointer
  Party* getParty();
};



// HumanPlayer class
class HumanPlayer : public Player {
 public:
  int selectInput(int totalInputs) override;
};

// ComputerPlayer class
class ComputerPlayer : public Player {
 public:
  int selectInput(int totalInputs) override;
};

#endif
