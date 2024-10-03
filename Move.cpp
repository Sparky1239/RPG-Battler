#include "Move.h"

//default constructor
Move::Move(): name(""), damage(0){}
//constructor
Move::Move(std::string name, int damage): name(name), damage(damage){}

//getters and setters
    //string
    std::string Move::getName(){
        return name;
    }
    
    void Move::setName(std::string name){
        this->name = name;
    }
    //damage
    int Move::getDamage(){
        return damage;
    }

    void Move::setDamage(int damage){
        this->damage = damage;
    }
