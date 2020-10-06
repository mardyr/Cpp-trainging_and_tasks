#include "pch.h"

TEST(GroupOfTest, FizzBuzzTest) 
{
    FizzBuzz testUnit;
    EXPECT_EQ("0", testUnit.value);
    EXPECT_EQ("1", testUnit.printResult(1));
    EXPECT_EQ("2", testUnit.printResult(2));
    EXPECT_EQ("Fizz", testUnit.printResult(3));
    EXPECT_EQ("Buzz", testUnit.printResult(5));
    EXPECT_EQ("Fizz", testUnit.printResult(6));
    EXPECT_EQ("Buzz", testUnit.printResult(10));
    EXPECT_EQ("Fizz Buzz", testUnit.printResult(15));
}


