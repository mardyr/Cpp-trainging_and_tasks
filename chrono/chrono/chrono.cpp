// chrono.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <ctime>

/*
termin: epoka - początek pomiaru czasu
termin takt - pojedyncze zdarzenie wchodzące w okres, okreslane przez biblioteke ratio ratio<60,1> taktowanie co 60 sekund 

termin okres: jest to n zbior taktow , przy takcie 1 minutowym , okres 2 minuty to 2 razy takt 1 minuta

termin: punkt w czasie to wyliczenie - okresu od epoki , czyli epoka to 1 styczen 2019:15:00, okres to 1 godzina, wiec punkt w czasie to 1 styczne 2019 16:00

*/

int main()
{
    // okres
    std::chrono::duration<int> sek(20); // 20 sekund , ratio domyslne 1 sek(taktowanie) , ilosc taktow typ int
    std::chrono::duration<int, std::ratio<60>> min3(3); // 180 sekund, no czyli 3 minuty mam okresik 
    std::chrono::duration<double, std::ratio<10>> x(0.5); // jeden takt dziesiec sekund, a my wywolujemy pol takty
    std::chrono::duration<long, std::ratio<1, 1000>> y(5); // taktuje co milisekund , i okres to 5 milisekund

    std::chrono::seconds sek15(15); // okres 15 sekund , czyli taktowanie co sekunde

    std::chrono::hours day(24); // taktowanie co godzine okres 24h

    auto okres = std::chrono::minutes(2);
    std::cout << typeid(okres).name() << std::endl;
    // chrono::milisecond(15) // czyli okres 15 milisekund z taktowaniem co sekunde
    // chrono::microseconds(1) czyli z taktowaniem co mikrosekunde
    // chrono::nanosecond(4) czyli taktowanie co nanosekunde z okresem 4 nanosekund
    
    std::cout << x.count() << std::endl; // count , zwraca ilosc taktow 
    std::cout << sek15.count() << std::endl; // 15 sekund, bo 15 taktow, taktowanie co minute

    sek15++; // zwiekszanie okresu o jeden takt, dodatkowe taktowanie
    x++;
    std::cout << x.count() << std::endl;
    std::cout << sek15.count() << std::endl;
    std::chrono::seconds r = sek15 - sek; // 16-20 , ale musza miec takie samo taktowanie
    std::cout << r.count() << std::endl;
    std::cout << std::chrono::minutes::period::num << " " << std::chrono::minutes::period::den << std::endl;
    std::cout << std::chrono::duration<long, std::ratio<20>>::period::num << " " << std::chrono::duration<int, std::ratio<10>>::period::den << std::endl;

    std::chrono::milliseconds ms2(r); // czyli zamiana zmiennej r(sekundy) , na milisekundy, tam bylo taktowanie co sekunde
    std::cout << ms2.count() << std::endl; // czyli teraz taktuje co milisekunde

    std::chrono::milliseconds ms(12344321);

    std::chrono::hours hh = std::chrono::duration_cast<std::chrono::hours>(ms);
    std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>(ms % std::chrono::hours(1)); //no wiec minuty to bedzie reszta z dzielenia przez godzine
    // rzutowanie na minuty obcina reszte, bo z modulo wychodzi np 7.2 , czyli mamy 7 minut
    std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(ms % std::chrono::minutes(1)); // to co sie nie zmiescilo w minutach
    // przez seconds ucinam do wartosci calowitych, taki int na floatcie
    std::chrono::microseconds mss = std::chrono::duration_cast<std::chrono::milliseconds>(ms % std::chrono::seconds(1));

    std::cout << ms.count() << " ms to" << std::setw(2) << hh.count() << " g. " << std::setw(2) << m.count() << " m ." << std::setw(2) <<
        s.count()<<" s ."<<std::setw(2)<<mss.count()<<" ms." <<std::endl;

    std::chrono::seconds test(10000);
    std::chrono::hours h = std::chrono::duration_cast<std::chrono::hours> (test);
    std::chrono::minutes min = std::chrono::duration_cast<std::chrono::minutes> (test % std::chrono::hours(1));
    std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(test % std::chrono::minutes(1));

    std::cout << std::setw(2) << h.count() << " g." << std::setw(2) << min.count() << " min." << std::setw(2) << sec.count() << " sekundy" << std::endl;

    // zegary
    /* sa dostepne 3 zegary w systemie
    std::chrono::system_clock // systemowy czyli podstawowy , szybszy niz high resolution
    std::chrono::high_resolution_clock // dokladniejszy, ale moze byc zgodny z systemowym
    std::chrono::steady_clock // miarowy, niemalejacy, nie da sie cofac

    */
    auto start = std::chrono::system_clock::now(); // daj do start czas jako teraz
    
    while (std::chrono::system_clock::now() < start + std::chrono::milliseconds(25))
    {
        static auto i = 0;
        i++;
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    auto start2 = std::chrono::high_resolution_clock::now();

    while (std::chrono::high_resolution_clock::now() < start2 + std::chrono::milliseconds(25))
    {
        static auto i = 0;
        i++;
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2)); // komputer sobie czeka przez 2 sekundy , spie przez
    std::cout << "Troche pospalem" << std::endl;

    std::this_thread::sleep_until(std::chrono::high_resolution_clock::now() + std::chrono::seconds(5)); //a tu spie do pewnego czasu
    std::cout << "Kima" << std::endl;

    // zamiana czasu do postaci tekstowej
    char str[100];
    auto t = std::chrono::system_clock::to_time_t(start); // konwersja na czas systemowy wyrazony liczbowo
    ctime_s(str, sizeof(str), &t); // a tu str bedzie napisem z data systemowa, konwersja napisowa
    std::cout << str << std::endl;

    const auto p0 = std::chrono::time_point<std::chrono::system_clock>{}; // ustawienie clocka na epoch time
    std::chrono::hours d(40*8760);

    const auto start = p0 + d;
    
    time_t czas = std::chrono::system_clock::to_time_t(start);

    std::cout << ctime(&czas) << std::endl;
}


