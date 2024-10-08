#include "Character.h"
#include "Party.h"

//default constructor
Party::Party() : partySize(0), maxSize(0), Characters(nullptr) {}

//constructor
Party::Party(int maxSize) : partySize(0), maxSize(maxSize) {
    Character* Characters = new Character;
}
//add characters return false if no room

bool Party::addCharacter(Character character){
    if(partySize == maxSize){
        return false;
    }
    Characters[partySize] = character;
    partySize++;
    return true;
}

//get Character
Character Party::getCharacter(int number){
    return Characters[number];
}