#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>

#include "Move.h"

class Character {
private:
  std::string name;
  int health;
  int strength;
  Move* moves;

int moveCount;

 public:

  int moveCount;
  // default constructor
  Character();

  // constructor
  Character::Character(std::string characterName, int characterHealth,
                       int characterStrength);
  // getters
  // name
  std::string getName();
  // health
  int getHealth();
  // strength
  int getStrength();

  // setters
  // name
  void setName(std::string characterName);
  // health
  void setHealth(int characterHealth);
  // strength
  void setStrength(int characterStrength);

  // add move if no space return false
  bool addMove(Move characterMove);

  // function that causes a character to perform a move;
  void performMove(Move move, Character target);

  // does damage to character , can also use negative values to heal
  void takeDamage(int damage);

  // checks if character is alive
  bool isAlive();
};

#endif
