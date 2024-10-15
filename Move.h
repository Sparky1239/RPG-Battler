#ifndef MOVE_H
#define MOVE_H
#include <string>
#include <iostream>
class Move
{

public:
    std::string name; // Name for the move
    int damage;       // Damage of the move

    Move();                             // Default constructor
    Move(std::string name, int damage); // Constructor that takes name and damage

    std::string getName();          // Getter for the moves name
    void setName(std::string name); // Setter for the moves name
    int getDamage();                // Getter for moves damage
    void setDamage(int damage);     // Setter for the moves damage
};

#endif