#include <cstdlib>
#include <ctime>
#include "main.h"

int f1()
{

    srand(time(0));
    return(rand()%100)%10 + 1;

}

C1::C1()
{
    this->a=10;
}
