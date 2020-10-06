//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
struct FizzBuzz
{
	std::string value;
	FizzBuzz() : FizzBuzz("0") {}
	FizzBuzz(std::string y) : value{ y } {}

	std::string printResult(int userValue);
};