#include "NumInfo.h"
#include <gtest/gtest.h>
#include <cstdint>

TEST(NumInfoFuncTest,EvenTest){
    EXPECT_TRUE(NumInfo::isEven(UINT64_MAX-1));
    EXPECT_TRUE(NumInfo::isEven(0));
    for(int i=0;i<=1000;i+=2){
        EXPECT_TRUE(NumInfo::isEven(i));
    }
    EXPECT_TRUE(NumInfo::isEven(4));
}

TEST(NumInfoFuncTest,OddTest){
    EXPECT_TRUE(NumInfo::isOdd(UINT64_MAX));
    EXPECT_TRUE(NumInfo::isOdd(1));
    for(int i=1;i<=1000;i+=2){
        EXPECT_TRUE(NumInfo::isOdd(i));
    }
    EXPECT_TRUE(NumInfo::isOdd(3));
    EXPECT_FALSE(NumInfo::isOdd(4));
    EXPECT_TRUE(false);
}

TEST(NumInfoFuncTest,LenTest){
    EXPECT_EQ(NumInfo::getLen(12345),5);
    EXPECT_EQ(NumInfo::getLen(572),3);
}