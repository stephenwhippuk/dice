#pragma once

#include "generator.h"
#include "defs.h"
#include "siminfo.h"

namespace DiceSim {
    class Simulator{
        private:
            tally_t tally;
            generator_t generator;
            int sampleSize;
        public:
            Simulator(int sampleSize, generator_t gen);
            void Run();
            void Reset();
            const tally_t& getResults();
            const generator_t getGenerator();
            int totalCount();

    };

    typedef std::shared_ptr<Simulator> simulator_t; 

    simulator_t createSimulator(const SimulationInformation& info);
};