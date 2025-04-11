#pragma once
#include "defs.h"
#include "generator.h"
namespace DiceSim{
    class DiceMax : public Generator{
        private:
            DiceType diceType;
            int numDice;
        public:
            DiceMax(int numDice, DiceType type);
            virtual int actual();
            virtual double theory(int total, int value);
            virtual size_t domainSize();
            virtual int minValue();
            virtual int maxValue();

            virtual ~DiceMax(){}
    };
};