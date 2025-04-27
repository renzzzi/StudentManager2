#include <iostream>
#include <fstream>

using namespace std;  // Added to avoid needing 'std::' before standard library functions

struct Student {
    string name;
    string studentId;
    string course;
    int yearLevel;
    float finalGrade;

    // Constructor with default parameters
    Student(string name = "", string studentId = "", string course = "", int year = 0, float grade = 0.0)
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

bool isDuplicateId(const string& studentId) {
    ifstream file("students.txt");
    string line;
    while (getline(file, line)) {
        if (line.find("Student ID: " + studentId) != string::npos) {
            return true; // Duplicate ID found
        }
    }
    return false; // No duplicate found
}

void addStudent() {
    Student stud;  // Declare a student object

    cout << "\nADD A STUDENT RECORD" << endl;

    // Get student details
    cout << "Enter Student Name: ";
    cin.ignore();  // Clear any leftover newline characters from previous input
    getline(cin, stud.name);

    cout << "Enter Student ID: ";
    while (true) {
        getline(cin, stud.studentId);

        // Check for duplicate ID
        if (isDuplicateId(stud.studentId)) {
            cout << "❌ The Student ID '" << stud.studentId << "' is already taken. Please enter a different ID: ";
        } else {
            break; // ID is unique, break out of the loop
        }
    }

    cout << "Enter Course: ";
    getline(cin, stud.course);

    cout << "Enter Year Level: ";
    cin >> stud.yearLevel;
    cin.ignore();  // To ignore the newline character left by cin

    cout << "Enter Final Grade: ";
    cin >> stud.finalGrade;
    cin.ignore();  // To clean up any leftover newline character

    // Open file to append student data
    ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        file << "Name: " << stud.name << endl;
        file << "Student ID: " << stud.studentId << endl;
        file << "Course: " << stud.course << endl;
        file << "Year Level: " << stud.yearLevel << endl;
        file << "Final Grade: " << stud.finalGrade << endl;
        file << "----------------------------------------" << endl;  // Separator for readability
        file.close();
        cout << "✅ Record Saved!" << endl;
    } else {
        cout << "❌ Error opening file." << endl;
    }
}


int main()
{
    int choice;
    do {

        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear any leftover newline character from choice input

        switch (choice) {
            case 1:
                addStudent(); // Call the function to add a student
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
