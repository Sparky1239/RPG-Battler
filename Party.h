#ifndef PARTY_H
#define PARTY_H

#include "Character.h"

class Party
{
private:
    
    int partySize;
    int maxSize;
    Character* Characters;

public:
    
    //default constructor
    Party();
    //constructor
    Party(int maxSize);

    //add characters return false if no room
    bool addCharacter(Character character);

    //get character
    Character getCharacter(int number);

};



#endif 