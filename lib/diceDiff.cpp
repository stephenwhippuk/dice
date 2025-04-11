#include "include/diceDiff.h"
#include "include/rangeesxception.h"
using namespace DiceSim;

DiceDiff::DiceDiff(DiceType type):
    diceType(type)
{}

int DiceDiff::actual(){
    auto dice1 = rand() % (int) diceType + 1;
    auto dice2 = rand() % (int) diceType + 1;
    return abs(dice1 - dice2);
}

size_t DiceDiff::domainSize(){
    return (int) diceType;
}

int DiceDiff::minValue(){
    return 0;
}

int DiceDiff::maxValue(){
    return ((int) diceType) - 1;
}

double DiceDiff::theory(int total, int value){
    if(value < minValue() || value > maxValue()){
        throw error_t(new RangeException("requested theortical value outside of value range"));
    }
    // just for now 
    return 0;
}

