#include "include/diceMax.h"
#include "include/rangeesxception.h"

using namespace DiceSim;

DiceMax::DiceMax(int numDice, DiceType type):
    diceType(type),
    numDice(numDice)
{}

int DiceMax::actual() {
    int result = 0;
    for(auto i = 0; i < this->numDice; i++){
        auto roll = rand() % (int) this->diceType + 1;
        result = roll > result ? roll : result;
    }
    return result;
}

size_t DiceMax::domainSize(){
    return (int) diceType;
}

int DiceMax::minValue(){
    return 1;
}

int DiceMax::maxValue(){
    return (int) diceType;
}


double DiceMax::theory(int total, int value){
    if(value < minValue() || value > maxValue()){
        throw error_t(new RangeException("requested theortical value outside of value range"));
    }
    // just for now 
    return 0;
}

