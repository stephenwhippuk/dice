#pragma once 
#include "defs.h"
#include "generator.h"

namespace DiceSim {
    generator_t createSumGenerator(int numDice, DiceType type);
    generator_t createMaxGenerator(int numDice, DiceType type);
    generator_t createDiffGenerator(DiceType type);
};