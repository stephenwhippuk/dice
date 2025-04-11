#pragma once
#include "../lib/include/lib.h"

void printTally(DiceSim::simulator_t sim);
std::string MapDiceType(DiceSim::DiceType type);
void printSimulationInformation(const DiceSim::SimulationInformation& info);
void initialiseDisplaySettings();
