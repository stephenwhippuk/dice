#include "defs.h"
#include "generator.h"
namespace DiceSim{
    class DiceDiff : public Generator{
        private:
            DiceType diceType;
        public:
            DiceDiff(DiceType type);
            virtual int actual();
            virtual double theory(int total, int value);
            virtual size_t domainSize();
            virtual int minValue();
            virtual int maxValue();
            ~DiceDiff(){}
    };
};