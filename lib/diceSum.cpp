#include "include/diceSum.h"
#include "include/rangeesxception.h"

using namespace DiceSim;
DiceSum::DiceSum(int numDice, DiceType type):
    diceType(type),
    numDice(numDice)
{}

int DiceSum::actual() {
    int total = 0;
    for(auto i = 0; i < this->numDice; i++){
        total += rand() % (int) this->diceType + 1;
    }
    return total;
}

size_t DiceSum::domainSize(){
    return ( (int) diceType * numDice) - (numDice - 1);
}

int DiceSum::minValue(){
    return numDice;
}

int DiceSum::maxValue(){
    return numDice  * (int) diceType;
}

double DiceSum::theory(int total, int value){
    if(value < minValue() || value > maxValue()){
        throw error_t(new RangeException("requested theortical value outside of value range"));
    }
    // just for now 
    auto unitProb = 1.0 / (maxValue() - minValue());
    
    return unitProb;
}


