// factorydesign.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "ToyFactory.h"
#include "Objects.h"

int main()
{
    Toy*v = ToyFactory::createToy(Vehicles::car);
   
    delete v;
    return 0;
}

