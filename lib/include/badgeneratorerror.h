#pragma once
#include <string>
#include <exception>

namespace DiceSim {
    class BadGeneratorException : public std::exception {
        private:
            std::string message;
        public:
            BadGeneratorException(const char* message)
            :
                message(message){}

            std::string what(){
                return message;
            } 
    };
};