#ifndef PARTY_H
#define PARTY_H
#include "Character.h"

// Party class represents the group of characters in the game
class Party
{
private:
  int partySize;
  int maxSize;
  Character *Characters; // Dynamic array of characters in the party

public:
  // Default constructor
  Party();
  // Constructor initilizes the party with a max given size
  Party(int maxSize);

  // Add characters return false if no room
  bool addCharacter(Character character);

  // Gets a ref to a character in the party by their index
  Character &getCharacter(int number);

  // Calculate and return the total health of party
  int getTotalHealth();

  // Returns current party size
  int getPartySize();
};

#endif