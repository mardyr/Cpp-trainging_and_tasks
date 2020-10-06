// multidimarr.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>



void PrintMultiArray(int* arr,int k,int z)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < z; j++)
        {
            *(arr+i*z+j)= j + i;
            std::cout << *(arr+i*z+j) << " ";
        }
        std::cout<<'\n';
    }
}
int main()
{

    int arr[2][2] = { {1,2},{2,4} };
    PrintMultiArray((int*)arr,2,2);
}

