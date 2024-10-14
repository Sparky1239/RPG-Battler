#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Party.h"
using namespace std;

// Abstract Player class
class Player {
 public:
  string name;
  Party* party;
  virtual int selectInput(int totalInputs);  // Polymorphism

  // return party pointer
  Party* getParty();
};

// HumanPlayer class
class HumanPlayer : public Player {
 public:
  int selectInput(int totalInputs) override;
  
  //takes any input from player unstored
  void nullResponse();
};

// ComputerPlayer class
class ComputerPlayer : public Player {
 public:
  int selectInput(int totalInputs) override;
};

#endif
