//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

std::string FizzBuzz::printResult(int userValue)
{
	if (!(userValue % 15)) return "Fizz Buzz";
	else if (!(userValue % 3)) return "Fizz";
	else if (!(userValue % 5)) return "Buzz";
	return std::to_string(userValue);
}
