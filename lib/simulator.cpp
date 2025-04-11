#include "include/simulator.h"
#include "include/badgeneratorerror.h"
#include "include/rangeesxception.h"

using namespace DiceSim;

Simulator::Simulator(int sampleSize, generator_t gen){
    this->generator = gen;
    this->sampleSize = sampleSize;
    this->tally = tally_t(gen->domainSize());
}

void Simulator::Reset(){
    for(int& i : this->tally){
        i = 0;
    }
}

void Simulator::Run(){
    for(auto i = 0; i < sampleSize; i++){
        int val = generator->actual();
        tally[val - generator->minValue()]++;
    }
}

const tally_t& Simulator::getResults(){
    return tally;
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