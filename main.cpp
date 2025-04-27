#include <iostream>
#include <fstream>

struct Student {
    std::string name;
    std::string studentId;
    std::string course;
    int yearLevel;
    float finalGrade;

    Student(std::string name, std::string studentId, std::string course, int year, float grade) 
    : name(name), studentId(studentId), course(course), yearLevel(year), finalGrade(grade) {}
};

void displayMenu()
{
    std::cout << "\n1. Add a student record\n";
    std::cout << "2.View all records\n";
    std::cout << "3. Search a record by Student ID\n";
    std::cout << "4. Update a record\n";
    std::cout << "5. Exit\n";
}

int main()
{

    hello
    return 0;
}