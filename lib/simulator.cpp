#include "include/simulator.h"
#include "include/badgeneratorerror.h"
#include "include/rangeesxception.h"

using namespace DiceSim;

Simulator::Simulator(int sampleSize, generator_t gen){
    this->generator = gen;
    this->sampleSize = sampleSize;
    this->actuals = tally_t(gen->domainSize());
    this->theoreticals = theory_t(gen->domainSize());
}

void Simulator::Reset(){
    for(int& i : this->actuals){
        i = 0;
    }
}

void Simulator::Run(){
    for(auto i = 0; i < sampleSize; i++){
        int val = generator->actual();
        actuals[val - generator->minValue()]++;
    }
    for(auto v = generator->minValue(), i = 0 ; v <= generator->maxValue(); v++, i++){
        theoreticals[i] = generator->theory(sampleSize, v);
    }
}

const tally_t& Simulator::getActuals(){
    return actuals;
}

const theory_t& Simulator::getTheoreticals(){
    return theoreticals;
}

const generator_t Simulator::getGenerator(){
    return generator;
}

simulator_t DiceSim::createSimulator(const SimulationInformation& info){
    if(info.generator == nullptr)
        throw error_t(new BadGeneratorException("bad generator"));
    if(info.sampleSize < 1){
        throw error_t(new RangeException("Invalid Sample Size"));
    }
    return simulator_t(new Simulator(info.sampleSize, info.generator));
}

int Simulator::totalCount(){
    return sampleSize;
}