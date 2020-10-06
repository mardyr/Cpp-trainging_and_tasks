// array- przesunie.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <array>
#include <stdlib.h>
#include <ctime>
#include <vector>

std::vector<int> ChangePosition(std::vector<int>& outVector, int& k, const int&size);

int main()
{
    srand(time(NULL));
    int randArray[5];
    const unsigned int size = sizeof(randArray) / sizeof(randArray[0]);
    for (int i = 0; i < size; i++)
    {
        randArray[i] = rand() % 100 + 1;
    }
    
    int k = 3;
    std::vector<int> randVector(randArray, randArray + size);
    /*for (int i : randVector) { std::cout << i << " "; }
    std::cout << std::endl<< std::string(60, '=') << std::endl;  test*/
    ChangePosition(randVector, k, size);
}

std::vector<int> ChangePosition(std::vector<int>&outVector, int& k,const int&size)
{
    if (k > size) { k = k - size; }   // if value of translation is bigger than array Size, ( back to begin postion)
    
    std::vector<int> localVector(size);
    for (int i = 0; i < size; i++)
    {
        if (i + k < size) { localVector[i + k] = outVector[i]; }
        else { localVector[k + i - size] = outVector[i]; }
    }
    for (int i : localVector) { std::cout << i << " "; }
    
    return localVector;
}


