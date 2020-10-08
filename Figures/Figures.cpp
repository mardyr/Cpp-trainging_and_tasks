// Figures.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <memory>
#include "Block.h"
#include "Sphere.h"
#include "Pyramid.h"
#include "Cuboid.h"
int main()
{
    auto spherePtr = std::make_unique<Sphere>();
    auto pyramidPtr = std::make_unique<Pyramid>();
    auto cuboidPtr = std::make_unique<Cuboid>();

    spherePtr   ->  enterData();
    spherePtr   ->  showLength();
    spherePtr   ->  calculateArea();
    spherePtr   ->  calculateCapacity();
    spherePtr   ->  showCalculatedInfo();

    pyramidPtr  ->  enterData();
    pyramidPtr  ->  showLength();
    pyramidPtr  ->  calculateArea();
    pyramidPtr  ->  calculateCapacity();
    pyramidPtr  ->  showCalculatedInfo();

    cuboidPtr   ->  enterData();
    cuboidPtr   ->  showLength();
    cuboidPtr   ->  calculateArea();
    cuboidPtr   ->  calculateCapacity();
    cuboidPtr   ->  showCalculatedInfo();

    return 0;
}

