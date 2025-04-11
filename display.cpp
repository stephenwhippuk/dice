#include "includes/display.h"
#include "includes/stdinclude.h"

#include <iomanip>

void initialiseDisplaySettings(){
    std::cout   << std::fixed 
                << std::setprecision(2);
}

inline size_t getPositionOfValue(const DiceSim::simulator_t sim, int value){
    return value - sim->getGenerator()->minValue();
}

void printTally(DiceSim::simulator_t sim){

    auto value = sim->getGenerator()->minValue();
    auto total = sim->totalCount();
    std::cout << "Value\tActual\tTheory" << std::endl;
    std::cout << "-----\t------\t------" << std::endl;
    for(auto count : sim->getActuals()){
        auto theory = sim->getTheoreticals()[ getPositionOfValue(sim, value) ];
        std::cout << value << "\t" << count << "\t" << theory << std::endl;
        value++;
    }
    auto mean = DiceSim::Mean(sim->getActuals());
    auto stdDev = DiceSim::StdDev(sim->getActuals(), mean);
    std::cout << "-----\t------\t------" << std::endl;
    std::cout << "Mean" << '\t' << mean << std::endl;
    std::cout << "Std Dev" << '\t' << stdDev << std::endl;
}

void printSimulationInformation(const DiceSim::SimulationInformation& info){
    switch(info.simulationType){
        case DiceSim::SimulationType::OneDiceMax:
            std::cout   << "Maximum Roll for 1" 
                        << DiceSim::DiceTypeToString(info.diceType)
                        << " WIth Sample Size of " 
                        << info.sampleSize 
                        << std::endl 
                        << std::endl;
            break;
        case DiceSim::SimulationType::TwoDiceSum:
            std::cout   << "Sum of 2" 
                        << DiceSim::DiceTypeToString(info.diceType)
                        << " WIth Sample Size of " 
                        << info.sampleSize 
                        << std::endl 
                        << std::endl;
            break;
        case DiceSim::SimulationType::TwoDiceMax:
            std::cout   << "Maximum Roll for 2" 
                        << DiceSim::DiceTypeToString(info.diceType)
                        << " WIth Sample Size of " 
                        << info.sampleSize 
                        << std::endl 
                        << std::endl;
            break;
        case DiceSim::SimulationType::TwoDiceDif:
            std::cout   << "DIfference Between 2" 
                        << DiceSim::DiceTypeToString(info.diceType)
                        << " WIth Sample Size of " 
                        << info.sampleSize 
                        << std::endl 
                        << std::endl;
            break;
        case DiceSim::SimulationType::NDiceSum:
            std::cout   << "Sum Of "
                        << info.numberOfDIce 
                        << DiceSim::DiceTypeToString(info.diceType)
                        << " WIth Sample Size of " 
                        << info.sampleSize 
                        << std::endl 
                        << std::endl;
            break;
        case DiceSim::SimulationType::NDiceMax:
            std::cout   << "Maximum Roll for "
                        << info.numberOfDIce 
                        << DiceSim::DiceTypeToString(info.diceType)
                        << " WIth Sample Size of " 
                        << info.sampleSize 
                        << std::endl 
                        << std::endl;
            break;
        default:
            throw DiceSim::error_t( new DiceSim::UnknownTypeError("Unkown Simuation Type") );
    }
     
}