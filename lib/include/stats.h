#pragma once
#include "defs.h"
namespace DiceSim{
    double Mean(const tally_t& tally);
    double StdDev(const tally_t& tally, double mean);
};