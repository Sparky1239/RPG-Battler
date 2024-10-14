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
 

  //constructor
  Player(Party* party, string name);

  
  virtual int selectInput(int totalInputs);  // Polymorphism

  // return party pointer
  Party* getParty();
};

// HumanPlayer class
class HumanPlayer : public Player {
 public:
 //constructor
  HumanPlayer(Party* party, string name);

  int selectInput(int totalInputs) override;
  
  //takes any input from player unstored
  void nullResponse();
};

// ComputerPlayer class
class ComputerPlayer : public Player {
 public:
  //constructor
  ComputerPlayer(Party* party, string name);
  int selectInput(int totalInputs) override;
};

#endif
