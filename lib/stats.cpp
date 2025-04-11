#include "include/stats.h"
#include <math.h>

using namespace DiceSim;

double DiceSim::Mean(const tally_t& tally ){
    int total = 0;

    for(auto x : tally){
        total += x;
    }

    return total / (tally.size() * 1.0);
}

double DiceSim::StdDev(const tally_t& tally, double mean){
    double sumOfSquares = 0;

    for(auto x : tally){
        double variance = x - mean;
        sumOfSquares += variance * variance;
    }

    auto meanVariance = sumOfSquares / (tally.size() - 1.0);
    return sqrt(meanVariance);
}