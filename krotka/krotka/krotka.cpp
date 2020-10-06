// krotka.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


 //krotka laczy wiele elementow w jeden, para laczy dwa 

#include <iostream>
#include<tuple>
#include<array>
int main()
{
    std::tuple<int, float, std::string, bool> t1(20, 2.0f, "abc", true);
    std::cout << std::get<0>(t1) << " " << std::get<1>(t1)<<" "<<std::get<2>(t1) << " " << std::get<3>(t1) << std::endl;
    /////////////////////////////////////////////////
    auto d = make_tuple(std::string("jeja"), 2.34f, 1, true);
    std::get<2>(d) = 32;
    std::cout << std::get<0>(d) << " " << std::get<1>(d) << " " << std::get<2>(d) << " " << std::get<3>(d) << std::endl;
    std::cout << typeid(d).name() << std::endl;
    auto t3(d);
    std::cout << typeid(t3).name() << std::endl;
    /////////////////////////////////////////////////////
    std::string s = "krotka";
    int xx = 1;
    std::cout << s << std::endl;
    auto t4 = make_tuple(std::ref(s),std::ref(xx)); // ref s pracuje na orginale
    std::get<0>(t4) = "edytuje ten napis";
    std::get<1>(t4) = 22;
    std::cout << s << "refere " << std::get<0>(t4) << " " <<std::get<1>(t4)<< std::endl; // tutaj normalna referencja, zmiana lokalna wplywa na globaln
    s = "zmiana";
    std::cout << s << " " << std::get<0>(t4)<< " " << std::endl; // ale tutaj globalna tez na lokalna , wow
    ///////////////////////////////////////////////////////
    std::tuple<int, double, std::string, std::string> t9(5, 3.2f, "krotka", "sie nazywam");
    std::cout << std::get<0>(t9) << " " << std::get<1>(t9) << " " << std::get<2>(t9) << "||" << std::get<3>(t9) << " " << std::endl;
    int a; double e;std::string str;
    std::tie(a,e,std::ignore, str) = t9; // tie rozpakowuje krotke ignore ignoruje element
    std::cout<< a << e << str <<std::endl;
    a += 3;
    std::cout << std::get<0>(t9) << std::endl;
    //////////////////////////////////////////////////////
    auto& [x1,x2, x3, x4] = t9; // rozpakowanie krotki do od x1 do x4
    std::cout<<"Auto typ" << ":D " << x1 << " " << x2 << " " << x3 << " " << x4 << std::endl;
    x1 = 201;
    x2 = 3.4;
    std::cout << std::get<0>(t9) << " " << std::get<1>(t9) << " " << std::get<2>(t9) <<" "<< std::get<3>(t9)<<std::endl;
    ////////////////////////////////////////////////////////////////////
    typedef std::tuple<int, double, unsigned int, int> MyTuple; // mytuple to typ
    std::cout <<"Rozmiar: "<< std::tuple_size_v<MyTuple> << std::endl; // z tylu elementow sklada sie krotka
    MyTuple t6(20, 3.0, 199, 191);
    //////////////////////////////////////////////////
    std::tuple_element_t<1, MyTuple> zmienna; // pobieranie 1 elementu z krotki czyli 3.0
    std::cout << typeid(zmienna).name() << std::endl; // zmienna ma typ jak 1-y element w krotce 
    ////////////////////////////////////////////////////////////
    std::cout << "Konkatenacja krotek 4 + 2" << std::endl;
    auto implode = tuple_cat(t6, t4);
    std::cout << std::tuple_size_v<decltype(implode)> << std::endl;
    std::cout << std::get<0>(implode) << ":" << std::get<1>(implode) << ":" << std::get<2>(implode)<<":";
    std::cout << std::get<3>(implode) << ":" << std::get<4>(implode) << ":" << std::get<5>(implode) << std::endl;
    ///////////////////////////////////////////////////////////
    //krotka w krotce
    std::tuple<int, std::tuple<float, float>> tint{ 12,{3.3f,3.2f} };
    std::cout <<"wrr"<< std::get<0>(tint) << " " << std::get<0>(std::get<1>(tint)) << std::endl;; // odnosze się do zerowego elementu krotki tinit, a pozniej do 1 elementu zadgniezdzonej krotki,
    ///i w tym pierwszym do pierwszego                                                                                       ////////////////////////////////////////////////////
    //krotka przez incjalizacje
    std::tuple tu1(std::string("lecim"), std::string(" jak Adas w Willingen"), 1.45f);
    std::cout << "KROTKA " << std::endl;
        std::cout << std::get<0>(tu1) << " " << std::get<1>(tu1) <<" "<< std::get<2>(tu1) << std::endl;
        auto konk = std::tuple_cat(tint, tu1);
        std::cout << std::tuple_size_v<decltype(konk)> << std::endl; // rozmiar konkatenkowanej krotki

    //////////////////////////////////////////////
    // tablice maja interfejs krotek
        std::cout <<"TABLICA JAKO KROTKA: "<< std::tuple_size_v<std::array<int, 10>> << std::endl;
       
        typedef std::array<int, 5> fivea;
        
        fivea tab2{ 1,2,4,5 };

        std::cout << std::tuple_size_v<fivea> << std::endl;

        std::cout << std::get<0>(tab2) << std::endl;

}

