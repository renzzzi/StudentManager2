#include <iostream>
#include <fstream>

using namespace std;  // Added to avoid needing 'std::' before standard library functions

struct Student {
    string name;
    string studentId;
    string course;
    int yearLevel;
    float finalGrade;

    Student(string name, string studentId, string course, int year, float grade) 
    : name(name), studentId(studentId), course(course), yearLevel(year), finalGrade(grade) {}
};

void displayMenu()
{
    cout << "----------------------------------------\n";
    cout << "📋 Welcome to the Student Management System!\n";
    cout << "----------------------------------------\n";
    cout << "1. Add a student record\n";
    cout << "2. View all records\n";
    cout << "3. Search a record by Student ID\n";
    cout << "4. Update a record\n";
    cout << "5. Delete a student record\n";  // Added delete option
    cout << "6. Exit\n";
    cout << "----------------------------------------\n";
}

int main()
{
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

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
                cout << "Goodbye! Exiting the program.....\n";
                break;
            default:
                cout << "\n❌ Oops! That's not a valid choice. Please try again.\n\n";
        }
    } while (choice != 5);

    return 0;
}
