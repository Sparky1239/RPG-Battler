#include "Player.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//return party pointer
  Party* Player::getParty(){
    return party;
  }

int HumanPlayer::selectInput(int totalInputs) {
    //makes variable move index
    int moveIndex=0;
    //takes user input for move index
    cin >> moveIndex;
    //keeps asking until a valid
    while (moveIndex>totalInputs && moveIndex<0)
    {
        cout << "please enter a valid input";
        cin >> moveIndex;
    }
    //returns the move choice
    return moveIndex;
    

}

//takes any input from player unstored
void HumanPlayer::nullResponse(){
  char charTemp;
  cin >> charTemp;
}



int ComputerPlayer::selectInput(int totalInputs) {
    //copied for time being

    
    //makes variable move index
    int moveIndex=0;
    //takes user input for move index
    cin >> moveIndex;
    //keeps asking until a valid
    while (moveIndex>totalInputs && moveIndex<0)
    {
        cout << "please enter a valid input";
        cin >> moveIndex;
    }
    //returns the move choice
    return moveIndex;
}
