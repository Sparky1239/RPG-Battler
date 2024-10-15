#include "Character.h"
#include <iostream>
#include <string>

// Default constructor
Character::Character()
    : name("null"), maxHealth(0), health(0), moves(nullptr) {}

// Constructor that initializes the character with a given name, max health, and current health
Character::Character(std::string name, int maxHealth, int health)
    : name(name), maxHealth(maxHealth), health(health), moveCount(0)
{
  moves = new Move[4]; 
}

// Getter for the character's name
std::string Character::getName() { return name; }
// Getter for the character's current health
int Character::getHealth() { return health; }
// Getter for the number of moves the character has learned
int Character::getMoveCount()
{
  return moveCount;
}
// Getter for a specific move from the moves array based on its index
Move Character::getMove(int moveNum)
{
  return moves[moveNum];
}
// Getter for the character's maximum health
int Character::getMaxHealth()
{
  return maxHealth;
}

// Setter for the character's name
void Character::setName(std::string characterName)
{
  this->name = characterName;
}
// Setter for the character's current health
void Character::setHealth(int characterHealth)
{
  this->health = characterHealth;
}

// This adds a new move to the character's moves list
// And if the move count is already 4, return false, else add the move and return true
bool Character::addMove(Move characterMove)
{
  if (moveCount == 4)
  {
    return false;
  }
  moves[moveCount] = characterMove;
  moveCount++;
  return true;
}

// Function that makes the character perform a move on a target character
void Character::performMove(Move move, Character &target)
{
  target.takeDamage(move.getDamage());
}

// Reduces the character's health by the given damage amount
// And if the health drops below 0, it gets set to 0
void Character::takeDamage(int damage)
{
  this->health -= damage; 
  if (this->health < 0)
  {
    this->health = 0;
  }
}

