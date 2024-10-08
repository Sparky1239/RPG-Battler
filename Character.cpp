#include "Character.h"
#include <iostream>
#include <string>

//default constructor
Character::Character()
    : name("null"), maxHealth(0), health(0), strength(0), moves(nullptr) {}

//constructor  //need to add dynamic array for moves
    Character::Character(std::string name, int maxHealth, int health, int strength) : name(name), maxHealth(maxHealth), health(health), strength(strength), moveCount(0) {
        Move* moves = new Move; // dynamic array that holds moves function later does not allow for more than 4
    }
//getters

    //name
    std::string Character::getName(){
        return name ; 
    }
    //health
    int Character::getHealth(){
        return health;
    }
    //strength
    int Character::getStrength(){
        return strength;
    }


    
//setters
    //name    
    void Character::setName(std::string characterName){
        this->name = characterName;
    }
    //health
    void Character::setHealth(int characterHealth){
        this->health = characterHealth;
    }
    //strength
    void Character::setStrength(int characterStrength){
        this->strength = characterStrength;
    }


    //add move if no space return false
    bool Character::addMove(Move characterMove){
        if(moveCount == 4){
            return false;
        }
        moves[moveCount] = characterMove;
        moveCount++;
        return true;
    }

    // function that causes a character to perform a move; 
    bool performMove(Move move, Character target){
        target.takeDamage(move.getDamage()); //need to figure out how moves do damage
        
        //return true when move can be performed otherwise false

    }
    // does damage to character, can also use negative values to heal
    void Character::takeDamage(int damage){
        this->health =-damage;
    }


    //checks if character is alive
    bool isAlive();
