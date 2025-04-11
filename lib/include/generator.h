#pragma once

#include <stdlib.h>
#include <memory>

namespace DiceSim{
    class Generator{
        public:
            virtual int actual () = 0;
            virtual double  theory(int total, int value) = 0;
            virtual size_t domainSize() = 0;
            virtual int minValue() = 0;
            virtual int maxValue() = 0;

            virtual ~Generator() {}
    };

    typedef std::shared_ptr<Generator> generator_t;
};