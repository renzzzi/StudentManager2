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