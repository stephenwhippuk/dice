#include "includes/stdinclude.h"
#include "lib/include/lib.h"
#include "includes/display.h"
#include "includes/setup.h"

DiceSim::simulator_t SetUp(){
        DiceSim::SimulationInformation info;
        int setupStatus  = GetSimulationSettings(info);

        if(setupStatus != EXIT_SUCCESS){
            exit(setupStatus);
        };
        printSimulationInformation(info);
        return DiceSim::createSimulator(info);
}

void Run(DiceSim::simulator_t sim){
    sim->Run();  
    printTally(sim);
}

int main(){
    try{
        initialiseDisplaySettings();
        auto sim = SetUp();
        Run(sim);
        exit(EXIT_SUCCESS);
    }
    catch(DiceSim::error_t err){
        std::cerr << err->what();
        exit(EXIT_FAILURE);
    }
}