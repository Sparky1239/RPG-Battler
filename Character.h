#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>
//#include "Move.h" //for the seperate move header


class Character{
private:
    std::string name;
    int health;
    int strength;
    Move moves;

public:
//default constructor
    Character();

//constructor
    Character::Character(std::string characterName, int characterHealth, int characterStrength, Move characterMoves[]);
//getters
    //name
    std::string getName();
    //health
    int getHealth();
    //strength
    int getStrength();

    //moves
    Move getMoves();
    
//setters
    //name    
    void setName(std::string characterName);
    //health
    void setHealth(int characterHealth);
    //strength
    void setStrength(int characterStrength);
    //moves
    void setMoves(std::Move characterMoves);

    // function that causes a character to perform a move; 
    void performMove(Move move, Character target);

    // does damage to character , can also use negative values to heal
    void takeDamage(int damage);

    //checks if character is alive
    bool isAlive();


};

#endif
