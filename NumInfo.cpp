#include "NumInfo.h"
#include <cmath>

namespace NumInfo{
    bool isEven(uint64_t num){
        return num%2==0;
    }
    bool isOdd(uint64_t num){
        return !isEven(num);
    }
    uint32_t getLen(uint64_t num){
        return std::ceil(std::log10(num));
    }
    bool isTimedBy3(uint64_t num){
        return num%3==0;
    }
    bool isTimedBy5(uint64_t num){
        return num%5==0;
    }
}