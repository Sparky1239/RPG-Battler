#include "Party.h"
#include "Character.h"

// Default constructor
Party::Party() : partySize(0), maxSize(0), Characters(nullptr) {}

// Constructor that creates a party with a given max size
Party::Party(int maxSize) : partySize(0), maxSize(maxSize)
{
  Characters = new Character[maxSize]; // Dynamically allocates memory for characters
}

// Below adds a character to party, returns false if party full
bool Party::addCharacter(Character character)
{
  if (partySize == maxSize)
  {
    return false;
  }
  Characters[partySize] = character; // Add character to party
  partySize++;
  return true;
}

// Get a reference to a character in the party by their index
Character &Party::getCharacter(int number) { return Characters[number]; }

// Callculates and returns teh total health of all the characters in party
int Party::getTotalHealth()
{
  return Characters[0].getHealth() + Characters[1].getHealth() +
         Characters[2].getHealth();
}

// Return party size
int Party::getPartySize() { return partySize; }