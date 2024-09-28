#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>
#include "Move.h" //for the seperate move header

using namespace std;
class Character{
private:
    string name;
    int health;
    int strength;
    vector<Move> moves;

public:
    Character(string characterName, int characterHealth, int characterStrength, vector<Move> characterMoves)
    : name(characterName), health(characterHealth), strength(characterStrength),moves(characterMoves){}

    string getName(){
        return name;

    }
    int getHealth(){
        return health;
    }
    int getStrength(){
        return strength;
    }

    vector<Move> getMoves(){
        return moves;

    }

    void setName(string characterName){
        name = characterName;

    }
    void setHealth(int characterHealth) {
        health = characterHealth;
    }


    void setStrength(int characterStrength){

        strength = characterStrength;
    }

    void setMoves(vector<Move>characterMoves){
        moves = characterMoves;
    }

    // two functions; 
    void performMove(Move move){
        //whatever logic needs to go here

    }

    bool isAlive(){
        return health>0;
        // + whatever otherlogic needs to go here


    }


};

#endif
