#include <iostream>
#include <fstream>
#include <string>

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
    cout << "Welcome to the Student Management System!\n";
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
    getline(cin, stud.name);

    cout << "Enter Student ID: ";
    while (true) {
        getline(cin, stud.studentId);

        // Check for duplicate ID
        if (isDuplicateId(stud.studentId)) {
            cout << "The Student ID '" << stud.studentId << "' is already taken. Please enter a different ID: ";
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
        cout << "Record Saved!" << endl;
    } else {
        cout << " Error opening file." << endl;
    }
}

void viewRecords() {
    cout << "\nVIEW ALL STUDENT RECORDS" << endl;

    ifstream file("students.txt");
    if (file.is_open()) {
        string line;
        bool hasRecords = false;  // To check if there are any records in the file
        while (getline(file, line)) {
            hasRecords = true;
            cout << line << endl;
        }
        file.close();

        if (!hasRecords) {
            cout << " No records found.\n";
        }
    } else {
        cout << " Error opening file.\n";
    }
}

void searchStudentById() {
    cout << "\nSEARCH A STUDENT RECORD BY STUDENT ID" << endl;

    string searchId;
    cout << "Enter Student ID to search: ";
    getline(cin, searchId);

    ifstream file("students.txt");
    if (file.is_open()) {
        string nameLine, idLine, courseLine, yearLevelLine, finalGradeLine, separatorLine;
        bool found = false;

        while (getline(file, nameLine)) {
            getline(file, idLine);
            getline(file, courseLine);
            getline(file, yearLevelLine);
            getline(file, finalGradeLine);
            getline(file, separatorLine);  // Separator line

            // Check if this student's ID matches
            if (idLine.find("Student ID: " + searchId) != string::npos) {
                found = true;
                cout << "\nStudent Record Found:\n";
                cout << nameLine << endl;
                cout << idLine << endl;
                cout << courseLine << endl;
                cout << yearLevelLine << endl;
                cout << finalGradeLine << endl;
                break;
            }
        }
        file.close();

        if (!found) {
            cout << "No record found for Student ID: " << searchId << endl;
        }
    } else {
        cout << "Error opening file.\n";
    }
}

void updateStudentRecord() 
{
    cout << "\nUPDATE A STUDENT RECORD" << endl;

    string searchId;
    cout << "Enter Student ID to update: ";
    getline(cin, searchId);

    ifstream file("students.txt");
    if (!file.is_open()) 
    {
        cout << "Error opening file.\n";
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile.is_open()) 
    {
        cout << "Error creating temporary file.\n";
        file.close();
        return;
    }

    string nameLine, idLine, courseLine, yearLevelLine, finalGradeLine, separatorLine;
    bool found = false;

    while (getline(file, nameLine)) 
    {
        getline(file, idLine);
        getline(file, courseLine);
        getline(file, yearLevelLine);
        getline(file, finalGradeLine);
        getline(file, separatorLine);

        if (idLine.find("Student ID: " + searchId) != string::npos) 
        {
            found = true;
            cout << "\nStudent Record Found. Enter new details:\n";

            Student updatedStudent;

            cout << "Enter New Name (leave blank to keep current): ";
            getline(cin, updatedStudent.name);

            cout << "Enter New Course (leave blank to keep current): ";
            getline(cin, updatedStudent.course);

            cout << "Enter New Year Level (enter -1 to keep current): ";
            cin >> updatedStudent.yearLevel;
            cin.ignore();

            cout << "Enter New Final Grade (enter -1 to keep current): ";
            cin >> updatedStudent.finalGrade;
            cin.ignore();

            // Extract old data
            string currentName = nameLine.substr(6); // After "Name: "
            string currentCourse = courseLine.substr(8); // After "Course: "
            int currentYearLevel = stoi(yearLevelLine.substr(12)); // After "Year Level: "
            float currentFinalGrade = stof(finalGradeLine.substr(13)); // After "Final Grade: "

            // Write updated info to temp file
            tempFile << "Name: " << (updatedStudent.name.empty() ? currentName : updatedStudent.name) << endl;
            tempFile << "Student ID: " << searchId << endl;
            tempFile << "Course: " << (updatedStudent.course.empty() ? currentCourse : updatedStudent.course) << endl;
            tempFile << "Year Level: " << (updatedStudent.yearLevel == -1 ? currentYearLevel : updatedStudent.yearLevel) << endl;
            tempFile << "Final Grade: " << (updatedStudent.finalGrade == -1 ? currentFinalGrade : updatedStudent.finalGrade) << endl;
            tempFile << "----------------------------------------" << endl;
        }
        else 
        {
            tempFile << nameLine << endl;
            tempFile << idLine << endl;
            tempFile << courseLine << endl;
            tempFile << yearLevelLine << endl;
            tempFile << finalGradeLine << endl;
            tempFile << separatorLine << endl;
        }
    }

    file.close();
    tempFile.close();

    if (found) 
    {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        cout << "Record Updated Successfully!\n";
    }
    else 
    {
        cout << "No record found for Student ID: " << searchId << endl;
        remove("temp.txt"); // Delete temp file if no changes
    }
}

void deleteStudentRecord()
{
    cout << "\nDELETE A STUDENT RECORD" << endl;

    string searchId;
    cout << "Enter Student ID to delete: ";
    getline(cin, searchId);

    ifstream file("students.txt");
    if (!file.is_open())
    {
        cout << "Error opening file.\n";
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile.is_open())
    {
        cout << "Error creating temporary file.\n";
        file.close();
        return;
    }

    string nameLine, idLine, courseLine, yearLevelLine, finalGradeLine, separatorLine;
    bool found = false;

    while (getline(file, nameLine))
    {
        getline(file, idLine);
        getline(file, courseLine);
        getline(file, yearLevelLine);
        getline(file, finalGradeLine);
        getline(file, separatorLine);

        if (idLine.find("Student ID: " + searchId) != string::npos)
        {
            found = true;
            cout << "\nStudent Record Found and Deleted:\n";
            cout << nameLine << endl;
            cout << idLine << endl;
            cout << courseLine << endl;
            cout << yearLevelLine << endl;
            cout << finalGradeLine << endl;
            cout << separatorLine << endl;
            // Do not write anything to tempFile — this deletes it!
        }
        else
        {
            // Write the whole record to temp file
            tempFile << nameLine << endl;
            tempFile << idLine << endl;
            tempFile << courseLine << endl;
            tempFile << yearLevelLine << endl;
            tempFile << finalGradeLine << endl;
            tempFile << separatorLine << endl;
        }
    }

    file.close();
    tempFile.close();

    if (found)
    {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        cout << "Record Deleted Successfully!\n";
    }
    else
    {
        cout << "No record found for Student ID: " << searchId << endl;
        remove("temp.txt"); // Clean up temp file if no deletion
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
                viewRecords(); // Call the function to view all students
                break;
            case 3:
                searchStudentById(); // Call the function to search a student by ID
                break;
            case 4:
                updateStudentRecord(); // Call the function to update a student's record
                break;
            case 5:
                deleteStudentRecord(); // Call the function to delete a student's record
                break;
            case 6:
                cout << "Goodbye! Exiting the program.....\n";
                break;
            default:
                cout << "\nOops! That's not a valid choice. Please try again.\n\n";
        }
    } while (choice != 6);
    return 0;
}