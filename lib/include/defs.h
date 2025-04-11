#pragma once
#include <vector>
#include <string>
#include <exception>
#include <memory>

namespace DiceSim{
    enum class DiceType{
        D4 = 4,
        D6 = 6,
        D8 = 8,
        D10 = 10,
        D12 = 12,
        D20 = 20
    };

    std::string DiceTypeToString(DiceType type);    

    enum class SimulationType {
        OneDiceMax = 1,
        TwoDiceSum = 2,
        TwoDiceMax = 3,
        TwoDiceDif = 4,
        NDiceSum = 5,
        NDiceMax = 6
    };

    typedef std::vector<int> tally_t;
    typedef std::vector<double> theory_t;
    typedef std::shared_ptr<std::exception> error_t;
};

