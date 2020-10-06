// ambigous.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <variant>
class Person
{
    std::string name;
    //int age;
    std::variant<float, int> height;
public:
    int age;
    Person( std::string n = "None",int a = 0,std::variant<float,int> h = 0 ) : name{ n }, age{ a }, height{ h } {}
    void GetAge() { std::cout << age << std::endl; }
};
class Male : virtual public Person
{
    bool power;
public:
    Male(std::string n = "Adam", int a = 0, std::variant<float, int> h = 0, bool p = 'true') : Person(n, a, h), power{ p } {}
};
class Female : virtual public Person
{
    bool grace;
public:
    Female(std::string n = "Adam", int a = 0, std::variant<float, int> h = 0, bool g = 'true') : Person(n, a, h), grace{ g } {}
};
class Student : public Male, public Female
{
public:
    std::string university;
   
};
int main()
{
    Student s;
    s.age = 23;
}

