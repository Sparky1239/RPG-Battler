#include "Character.h"
#include <iostream>
#include <string>

//default constructor
    Character::Character() : name(""), health(0), strength(0), moves(nullptr) {}

//constructor  //need to add dynamic array for moves
    Character::Character(std::string name, int health, int strength, Move moves[]) : name(name), health(health), strength(strength) {
        moves = new Move[4];
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


    //MOVES FUNCTIONS 
        //add functions and also output moves

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
