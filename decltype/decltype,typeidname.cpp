// ConsoleApplication9.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln


using namespace std;
#include <iostream>
#include <array>
#include <vector>
#include <typeinfo>
#include <string>
#include <ctime>

template<typename T1,typename T2> 
auto suma(const T1&a,const T2& b) -> decltype(a+b) // typ bedzie zwracany taki jaka jest suma elementów , bo przyjmuje typ z a+b decltyp(a+b)
{
    return a + b;
}
// decltype - podbiera typ ze swojego argumentu
// typeid().name() podpowie jakiego typu jest zamienna wg naszego komplitora
int main()
{
    int var1 = 0;
    decltype(var1) var2 = 105; // biore sobie typ z var1 i w to miejsce wstawiam typ z var1
    cout << var2 << " " << typeid(var2).name() << endl;

    double* var3 = nullptr;
    cout << typeid(nullptr).name() << endl;

    auto b = 1;
    cout << typeid(b).name() << endl;

    auto c = 1.43;
    cout << typeid(c).name() << endl;

    decltype(b) d = 5.4; 
    cout << "moje d " << d << endl;

    cout << suma(5,3.5)<<" " << typeid(suma(5, 3.5)).name() << endl;

    cout << suma(5.f, 5.f) << " " << typeid(suma(5.f, 5.f)).name() << endl;

    string txt3 = "koto"; string txt4 = "pies";

    cout << suma(txt3, txt4)<<" " << typeid(suma(txt3, txt4)).name() << endl;

    vector<int> values1{ 1,2,3,4,5 };

    for (auto x : values1) cout << "[" << x << "]" << " " << typeid(x).name();
    cout << endl;


    for (auto &x : values1) cout << x++  << " ";
    cout << endl;

    for (const auto& x : values1) cout << x << " ";
    cout << endl;

    for (auto i : { 1,2,3 }) cout << i << " ";
    cout << endl;

    auto txt = "abc";
    cout << endl << txt << typeid(txt).name() << endl;
    auto txt1 = R"(Teraz piszę 
co mi sie tylko             )";
    auto txt2 = R"ogranicznik(Teraz piszę 
 co mi sie tylko podoba nawet)")ogranicznik"; // muszę dac ogranicznik, zeby byl nawias i cudzyslow w tekscie wyswietlanym

    cout << endl << txt1 << "  " << typeid(txt1).name() << endl;

    string z;
    getline(cin, z);

    auto b4 = 4.23333333322222222222223;

    decltype(b4) v1 = 3333.1;

    cout << v1<<" to typ " << typeid(v1).name();

}



