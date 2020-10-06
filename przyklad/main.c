#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char* string = "Przyklad";
    char* x = "przyklad";
    x[2] = 'a'; // tak jak pisalem to jest nazywane undefined behaviour , i alokowane jest w ROMie , kompilator zwraca smieci
    puts(x);
    return 0;
}
