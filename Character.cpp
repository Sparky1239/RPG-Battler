#include "Character.h"

#include <iostream>
#include <string>

// default constructor
Character::Character()
    : name("null"), maxHealth(0), health(0), moves(nullptr) {}



Character::Character(std::string name, int maxHealth, int health)
    : name(name), maxHealth(maxHealth), health(health), moveCount(0) {
  moves = new Move[4];  //ALTERED
}


// // Destructor
// Character::~Character() {
//     delete[] moves; // Deallocate memory for moves array
// }

// getters

// name
std::string Character::getName() { return name; }
// health
int Character::getHealth() { return health; }

//move count
int Character::getMoveCount(){
  return moveCount;
}
//move
 Move Character::getMove(int moveNum){
  return moves[moveNum];
}
 //maxhealth
  int Character::getMaxHealth(){
    return maxHealth;
  }

// setters
// name
void Character::setName(std::string characterName) {
  this->name = characterName;
}
// health
void Character::setHealth(int characterHealth) {
  this->health = characterHealth;
}

// add move if no space return false
bool Character::addMove(Move characterMove) {
  if (moveCount == 4) {
    return false;
  }
  moves[moveCount] = characterMove;
  moveCount++;
  return true;
}



// function that causes a character to perform a move;
void Character:: performMove(Move move, Character& target) {
  target.takeDamage(move.getDamage());  
  std::cout << move.getDamage() <<"\n"<< target.getHealth()<<"\n";
}
// does damage to character, can also use negative values to heal
void Character::takeDamage(int damage) {
    this->health -= damage;  // CORRECTED IF NOT CORRECT PUT BACK TO ORIGINAL (IN COMMENTS)
  if (this->health < 0) {
        this->health = 0;  // Prevent negative health
    }
  std::cout << damage ;
}

/*void Character::takeDamage(int damage) { this->health = -damage; }*/


