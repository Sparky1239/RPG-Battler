#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Party.h"
using namespace std;

// Abstract Player class
class Player {
 public:
  string name;
  Party party;

  virtual void selectMove(Character &attacker,
                          Character &target) = 0;  // Polymorphism
};

// HumanPlayer class
class HumanPlayer : public Player {
 public:
  void selectMove(Character &attacker, Character &target) override;
};

// ComputerPlayer class
class ComputerPlayer : public Player {
 public:
  void selectMove(Character &attacker, Character &target) override;
};

#endif
