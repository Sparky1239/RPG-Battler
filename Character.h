#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>


class Character
{
private:
    std::string name; 

    //stats
        //HP
    int currentHP;
    int maxHP;
        //MANA
    int currentMana;
    int maxMana;
        //DEFENSE
    int magicDefense;
    int physicalDefense;
        //ATTACK
    int strength;
    int magicPower;
    

    //Spells or Moves



public:
    //default constructor
    Character();
    //constructor
    Character(std::string name,int HP, int Mana, int magic_Defense, int physical_Defense );
    //getters and setters
        //current hp
        int get_currentHP();
        void set_currentHP(int currentHP);
        //maximum hp
        int get_maxHP();
        void set_maxHP(int maxHP);
        //current mana
        int get_currentMana();
        void set_currentMana(int currentMana);
        //max mana
        int get_maxMana();
        void set_maxMana(int maxMana);
        //magic defense
        int get_magicDefense();
        void set_magicDefense(int magicDefense);
        //physical defense
        int get_physicalDefense();
        void set_physicalDefense(int physicalDefense);
        //strength
        int get_strength();
        void set_strength(int strength);
        //magicPower
        int get_magicPower();
        void set_magicPower(int magicPower);

    //battle functions
        // takes damage from source
        void takeDamage();

        //attack

        //use ability


        




};




#endif