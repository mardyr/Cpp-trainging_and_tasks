#include <iostream>
/*Stworz klase Mystring na podstawie klasy string oraz metodê która zwraca iloœæ samog³osek w tekœcie*/

using namespace std;
class Mystring : public string
{
    public:
    Mystring(){} // konstruktor przodka bez argumentowy wiec mozemy pomni¹ Mystring : string()
    string tekst;
    unsigned x=0;
    unsigned vowel()
    {
        string vowels ="eyuioaEYUIOA";
        for(unsigned i=0;i<this->size();i++)
            if(vowels.find(this->at(i))!=string::npos)x++; //this reprezentuje jaby string* , a metoda ->at pobiera i-ty element(znak)
        return x;
    }
    // jesli do pola z klasy mystring chcemy przypisac stringa to musimy nadpisac operator przypisania( bo w klasie string mozesz tylko stringi przypisywac)

        Mystring operator = (const char*tekst){this->assign(tekst);return *this;} // operator dzia³a na string(const char*) i wykorzystujac przypisanie, dopisuje do obiektu
        Mystring operator = (string tekst){this->assign(tekst);return *this;}
};
int main()
{
    string temp ="Dzis do mnie tula sie wlochata tarantula";
    Mystring txt;
    txt.append("Ala ma kota");
    cout <<txt<<endl;
    cout << txt.vowel()<<endl;
    cout << (txt="Rabarbar Bartka byl za barem\n");
    cout << (txt=temp)<<endl;
    cout <<"vowels="<<txt.vowel()<<endl;
    return 0;
}
