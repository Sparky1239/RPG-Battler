#ifndef PARTY_H
#define PARTY_H

#include "Character.h"

class Party
{
private:
    Character party[];
    int partySize;
    int maxSize;


public:
    //default constructor
    Party()
    //constructor
    Party();

    ~Party();
};



#endif 