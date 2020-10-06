// 4.5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
class Student
{
    char sex;
    int birthYear;
    int numberInClass;
    std::string name;
    std::string surname;
public:
    char getSex()               { return sex;           }
    int getYear()               { return birthYear;     }
    int getNumInCls()           { return numberInClass; }
    std::string getName()       { return name;          }
    std::string getSurName()    { return surname;       }
    friend class myClass;
    
};
class myClass : public Student
{
public:
    myClass() {}
    myClass(std::string studentInformation);
    std::vector<Student> students;
    void ReadFromFile(std::string filepath);
    std::vector<Student> sortbyNumber(std::vector<Student>& classOut);
    Student getStudent(int number);
    void showOne(Student& s)const;
    void showStudent();
    void showStudent(char sex);
};
int main()
{
    myClass A;
    A.ReadFromFile("data.txt");
    //A.showStudent();
    A.showStudent('M');
    Student s = A.getStudent(2);
    A.showOne(s);
    return 0;
}

myClass::myClass(std::string studentInformation)
{
    std::stringstream studentStream(studentInformation);
    studentStream >> name;
    studentStream >> surname;
    studentStream >> sex;
    studentStream >> birthYear;
    studentStream >> numberInClass;
}
void myClass::ReadFromFile(std::string filepath)
{
    std::ifstream studentFile(filepath);
    
    std::string lineFromFile;
    if (studentFile.good())
    {
        while (!studentFile.eof())
        {
            getline(studentFile, lineFromFile);
            myClass student(lineFromFile);
            students.emplace_back(student);
        }
    }
    else { std::cout << "CLOSE FILE" << std::endl; }
    studentFile.close();
}
std::vector<Student> myClass::sortbyNumber(std::vector<Student>&classOut)
{
    std::sort(classOut.begin(), classOut.end(), [](Student& s1, Student& s2)
        {
            if (s1.getNumInCls() == s2.getNumInCls()) { std::cout << "WRONG NUMBERS" << std::endl; }
            return s1.getNumInCls() < s2.getNumInCls();
        });
    return classOut;
}
Student myClass::getStudent(int number)
{
    auto it = std::find_if(students.begin(), students.end(), [&number](Student s1)
        { return number == s1.getNumInCls(); });
    if (it != students.end()) return *it;

}
void myClass::showStudent()
{
    while (!students.empty())
    {
        std::cout<<(students.end()-1)->getName() << " " << (students.end()-1)->getSurName() <<" "<< (students.end()-1)->getSex()<<" "<< (students.end()-1)->getYear()<<" "<< (students.end()-1)->getNumInCls() << std::endl;
        students.pop_back();
    }
}
void myClass::showStudent(char sex)
{
    if (sex == 'K')
    {
        for (auto it = students.begin(); it != students.end(); it++)
        {
            if (it->getSex() == 'K')
            {
                std::cout<<it->getName() << " " << it->getSurName() << " " << it->getSex() << " " << it->getYear() << " " << it->getNumInCls() << std::endl;
            }
        }
    }
    else if (sex == 'M')
    {
         for (auto it = students.begin(); it != students.end(); it++)
         {
             if (it->getSex() == 'M')
             {
                 std::cout << it->getName() << " " << it->getSurName() << " " << it->getSex() << " " << it->getYear() << " " << it->getNumInCls() << std::endl;
             }
         }
    }
    else { std::cout << "WRONG SEX\n"; }
}
void myClass::showOne(Student&s)const
{
    std::cout << s.getName() << " " << s.getSurName() << " " << s.getSex() << " " << s.getYear()<<" " << s.getNumInCls() << std::endl;

}
