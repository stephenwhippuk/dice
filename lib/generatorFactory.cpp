#include "include/generatorFactory.h"
#include "include/diceSum.h"
#include "include/diceMax.h"
#include "include/diceDiff.h"

DiceSim::generator_t DiceSim::createSumGenerator(int numDice, DiceSim::DiceType type){
    return DiceSim::generator_t(new DiceSim::DiceSum(numDice, type));
}

DiceSim::generator_t DiceSim::createMaxGenerator(int numDice, DiceSim::DiceType type){
    return DiceSim::generator_t(new DiceSim::DiceMax(numDice, type));
}

DiceSim::generator_t DiceSim::createDiffGenerator(DiceSim::DiceType type){
    return DiceSim::generator_t(new DiceSim::DiceDiff(type));
}