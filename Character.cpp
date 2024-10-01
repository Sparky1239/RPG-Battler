#include "Character.h"
#include <iostream>
#include <string>

//default constructor
    Character::Character() : name(""), health(0), strength(0), moves(nullptr) {}

//constructor  //need to add dynamic array for moves
    Character::Character(std::string name, int health, int strength, Move moves[]) 
    : name(name), health(health), strength(strength), moves(moves[]) {}
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

    //moves  //might need to be a pointer figure out how moves will work ... dynamic array??

    Move Character::getMoves(){
        return moves
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
    //moves //again figure out how moves work
    void Character::setMoves(std::Move characterMoves){
        this->moves = characterMoves;
    }

    // function that causes a character to perform a move; 
    bool performMove(Move move, Character target){
        target.takeDamage(  ) //need to figure out how moves do damage
        
        //return true when move can be performed otherwise false

    }
    // does damage to character, can also use negative values to heal
    void Character::takeDamage(int damage){
        this->health =-damage;
    }


    //checks if character is alive
    bool isAlive();
