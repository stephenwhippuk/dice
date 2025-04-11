#pragma once 
#include <string>
#include <exception>

namespace DiceSim {
    class RangeException : public std::exception {
        private:
            std::string message;
        public:
        RangeException(const char* message)
            :
                message(message){}

            std::string what(){
                return message;
            } 
    };
};