#include "includes/setup.h"
#include "includes/stdinclude.h"

void GetSampleSize(DiceSim::SimulationInformation& info){
    do{
        std::cout << "Enter Sample Size (greater than 0) :> ";
        std::cin >> info.sampleSize;
        }while(info.sampleSize <=0 );
}

void GetSimulationType(DiceSim::SimulationInformation& info){
    auto done = false;
    do
    {
        std::cout << "Please Enter SImulation Type" << std::endl
                 << "\t1) Maximum of 1 Dice" << std::endl
                 << "\t2) Sum of 2 Dice" << std::endl
                 << "\t3) Maximum of 2 Dice" << std::endl
                 << "\t4) Difference between 2 Dice" << std::endl
                 << "\t5) Sum of N Dice" << std::endl
                 << "\t6) Maximum of N Dice" << std::endl
                 << ":> ";
        int option = 0;
        std::cin >> option;
        switch (option){
            case 1:
                info.simulationType = DiceSim::SimulationType::OneDiceMax;
                info.numberOfDIce = 1;
                done = true;
                break;
            case 2:
                info.simulationType = DiceSim::SimulationType::TwoDiceSum;
                info.numberOfDIce = 2;
                done = true;
                break;
            case 3:
                info.simulationType = DiceSim::SimulationType::TwoDiceMax;
                info.numberOfDIce = 2;
                done = true;
                break;
            case 4:
                info.simulationType = DiceSim::SimulationType::TwoDiceDif;
                info.numberOfDIce = 2;
                done = true;
                break;
            case 5:
                info.simulationType = DiceSim::SimulationType::NDiceSum;
                done = true;
                break;
            case 6:
                info.simulationType = DiceSim::SimulationType::NDiceMax;
                done = true;
                break;
            default:
                std::cout << "Unknown option selected!" << std::endl;
        }
    } while (!done);
}

void GetNumberOfDice(DiceSim::SimulationInformation& info){
    do{
        std::cout << "Enter Number of Dice (greater than 2) :> ";
        std::cin >> info.numberOfDIce;
        }while(info.numberOfDIce <=2 );
}

void GetDiceType(DiceSim::SimulationInformation& info){
    auto done = false;
    do{
        std::cout << "PLease Select Dice Type:" << std::endl
                  << "\t1) D4" << std::endl
                  << "\t2) D6" << std:: endl
                  << "\t3) D8" << std::endl
                  << "\t4) D10" << std::endl
                  << "\t5) D12" << std::endl
                  << "\t6) D20" << std::endl
                  << ":> ";
        int option = 0;
        std::cin >> option;
        switch(option){
            case 1:
                info.diceType = DiceSim::DiceType::D4;
                done = true;
                break;
            case 2:
                info.diceType = DiceSim::DiceType::D6;
                done = true;
                break;   
            case 3:
                info.diceType = DiceSim::DiceType::D8;
                done = true;
                break;
            case 4:
                info.diceType = DiceSim::DiceType::D10;
                done = true;
                break;
            case 5:
                info.diceType = DiceSim::DiceType::D12;
                done = true;
                break;
            case 6:
                info.diceType = DiceSim::DiceType::D20;
                done = true;
                break;
            default:
                std::cout << "Unknown Option selected" << std::endl;

        }
    }while (!done);
}

int SetupGenerator(DiceSim::SimulationInformation& info){
    switch(info.simulationType){
        case DiceSim::SimulationType::TwoDiceSum:
        case DiceSim::SimulationType::NDiceSum:
            info.generator = DiceSim::createSumGenerator(info.numberOfDIce, info.diceType);
            break;
        case DiceSim::SimulationType::OneDiceMax: 
        case DiceSim::SimulationType::TwoDiceMax:
        case DiceSim::SimulationType::NDiceMax:
            info.generator = DiceSim::createMaxGenerator(info.numberOfDIce, info.diceType);
            break;
        case DiceSim::SimulationType::TwoDiceDif:
            info.generator = DiceSim::createDiffGenerator(info.diceType);
            break;
        default:
            std::cerr << "Unexpected Simulation Type in Mapping" << std::endl;
            return EXIT_FAILURE;
            break;
    }
    return EXIT_SUCCESS;
}

void printWelcome(){
    std::cout << "Welcome to the Dice Simulation" << std::endl;
}

bool IsNDiceSimulation(DiceSim::SimulationInformation& info){
    return info.simulationType == DiceSim::SimulationType::NDiceSum || info.simulationType == DiceSim::SimulationType::NDiceMax;
}

int GetSimulationSettings(DiceSim::SimulationInformation& info){
    
    printWelcome();
    GetSampleSize(info);
    GetSimulationType(info);
    if(IsNDiceSimulation(info)){
        GetNumberOfDice(info);
    }
    GetDiceType(info);
    return SetupGenerator(info);
}