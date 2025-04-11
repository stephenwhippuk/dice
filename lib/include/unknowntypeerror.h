#pragma once 
#include <string>
#include <exception>

namespace DiceSim {
    class UnknownTypeError : public std::exception {
        private:
            std::string message;
        public:
        UnknownTypeError(const char* message)
            :
                message(message){}

            std::string what(){
                return message;
            } 
    };
};