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


    std::cout << "----------------------------------------\n";
    std::cout << "📋 Welcome to the Student Management System!\n";
    std::cout << "----------------------------------------\n";
    std::cout << "1. Add a student record\n";
    std::cout << "2.View all records\n";
    std::cout << "3. Search a record by Student ID\n";
    std::cout << "4. Update a record\n";
    std::cout << "5. Delete a student record\n";  // Added delete option
    std::cout << "6. Exit\n";
    std::cout << "----------------------------------------\n";
}

int main()
{

    int choice;
do {
    displayMenu();
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            // Add student
            break;
        case 2:
            // View all students
            break;
        case 3:
            // Search student
            break;
        case 4:
            // Update student
            break;
        case 5:
            std::cout << "Goodbye! Exiting the program.....\n";
            break;
        default:
        std::cout << "\n❌ Oops! That's not a valid choice. Please try again.\n\n";

    }
} while (choice != 5);



    return 0;
}