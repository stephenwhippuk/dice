#include  "include/defs.h"
#include "include/unknowntypeerror.h"
std::string DiceSim::DiceTypeToString(DiceSim::DiceType type){
    switch(type){
        case DiceSim::DiceType::D4:
            return "D4";
        case DiceSim::DiceType::D6:
            return "D6";
        case DiceSim::DiceType::D8:
            return "D8";
        case DiceSim::DiceType::D10:
            return "D10";
        case DiceSim::DiceType::D12:
            return "D12";
        case DiceSim::DiceType::D20:
            return "D20";
        default:
            throw error_t(new UnknownTypeError("Unknown Dice Type"));
    }
}