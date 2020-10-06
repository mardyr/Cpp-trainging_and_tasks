// potega.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <math.h>
/*double potega(float podstawa, int wykladnik)
{
    if (wykladnik >= 0)
    {
        if (podstawa == 0 && wykladnik == 0) return 0;
        else if (wykladnik == 0) return 1;
        else if (wykladnik > 0) return podstawa * potega(podstawa, wykladnik - 1);
        else return 1/potega(podstawa, -wykladnik);
    }
}*/
float pot(double a, int n)
{
    if (a == 0 && n == 0) return 0;
    else if (n == 0) return 1;
    else if (n > 0) return pot(a, n - 1) * a;
    else return 1/pot(a,-n);
}

int main()
{
    std::cout << pot(2, -3);
}

