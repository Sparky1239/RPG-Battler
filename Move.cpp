#include "Move.h"

// Default constructor; initilizes move and damage empty and 0 respectivley
Move::Move() : name(""), damage(0) {}

// Constructor that sets move with a name and damage
Move::Move(std::string name, int damage) : name(name), damage(damage) {}

// Getter for the moves name
std::string Move::getName()
{
    return name;
}

// Setter for the move name
void Move::setName(std::string name)
{
    this->name = name;
}

// Getter for the moves damage
int Move::getDamage()
{
    return damage;
}

// Setter for the moves damage
void Move::setDamage(int damage)
{
    this->damage = damage;
}
