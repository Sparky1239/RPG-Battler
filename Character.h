#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>

#include "Move.h"

class Character {
private:

//dont change these ones maybe add
  std::string name;
  int maxHealth;
  int health;
  
  Move* moves;

int moveCount;

 public:

  int moveCount;
  // default constructor
  Character();

  // constructor
  Character::Character(std::string name, int maxHealth, int health);
  // getters
  // name
  std::string getName();
  // health
  int getHealth();


  // setters
  // name
  void setName(std::string characterName);
  // health
  void setHealth(int characterHealth);


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
