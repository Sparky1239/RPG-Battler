#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <iostream>
class Move
{
private:
    std::string name;
    int damage;

    //can add effect but rn just damage negative damage can heal
public:
//default constructor
Move();
//constructor
Move(std::string name, int damage);

//getters and setters
    //string
    std::string getName();
    
    void setName(std::string name);
    //damage
    int getDamage();

    void setDamage(int damage);

};

#endif 