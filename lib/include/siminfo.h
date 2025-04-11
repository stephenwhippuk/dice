#pragma once
#include "defs.h"
#include "generator.h"

namespace DiceSim{
    struct SimulationInformation{
        int sampleSize;
        int numberOfDIce;
        SimulationType simulationType;
        DiceType diceType;
        generator_t generator;
    };
};