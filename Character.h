#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>

#include "Move.h"

class Character
{
private:
  // dont change these ones maybe add
  std::string name;
  int maxHealth;
  int health;

  Move *moves;

  int moveCount;

public:
  // Default constructor
  Character();

  // Constructor that takes the name, max health, and current health
  Character(std::string name, int maxHealth, int health);

  
  // Below are the getters for thee private variables
  std::string getName();
  int getHealth();
  int getMoveCount();
  Move getMove(int moveNum);
  int getMaxHealth();

  // These are the setters for the private variables
  void setName(std::string characterName);
  void setHealth(int characterHealth);
// Below adds a move to the character's set of moves and returns false if the limit has been reachhed
  bool addMove(Move characterMove);
  // Below causes a character to perform a move;
  void performMove(Move move, Character &target);
  // Below does damage to character , can also use negative values to heal
  void takeDamage(int damage);
};

#endif
