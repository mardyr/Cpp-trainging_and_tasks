
// czytaj z pliku.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
class Student 
{
 protected:
    std::string name, surname;
    int age;
public:
    int getAge() const { return age; }
    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }

};
class MyClass : public Student
{
    std::vector<Student> students;
public:
    MyClass() {}
    MyClass(std::string studentInformation);
    void ReadFromFile(std::string filepath);
    void showClass()const;
    
};


int main()
{
    MyClass A;
    A.ReadFromFile("dane.txt");
    A.showClass();
   
}

MyClass::MyClass(std::string studentInformation)
{
    std::stringstream studentStream(studentInformation);
    {
        studentStream >> name;
        studentStream >> surname;
        studentStream >> age;

    }
}
void MyClass::ReadFromFile(std::string filepath)
{
    std::ifstream studentFile(filepath);

    std::string lineFromFile;

    if (studentFile.good())
    {
        while (!studentFile.eof())
        {
            std::getline(studentFile, lineFromFile);
            MyClass student(lineFromFile);
            students.emplace_back(student);
        }
    }
    studentFile.close();
}
void MyClass::showClass()const
{
    for (auto it = students.begin(); it != students.end(); it++)
    {
        std::cout << it->getName() << " " << it->getSurname() << " " << it->getAge() << " "<<std::endl;
    }
}