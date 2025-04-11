#include <iostream>
#include <cstring> // Include the C string library for strcpy

using namespace std;

class Student {
private:
    char name[50]; // Assuming a maximum name length of 49 characters
    int roll_no;
    string course;

public:
    // Constructor to initialize the student's name
    Student(const char* n) {
        strcpy(name, n); // Copy the name to the name array
    }

    // Display function to show the student's name
    void displayName() {
        cout << "Student's Name: " << name << endl;
    }
};

int main() {
    // Create an array of characters to store the name of the student
    char studentName[] = "Bella Swan";

    // Convert primitive type (char array) to class type (Student)
    Student student(studentName);

    // Display the student's name using the display function of the Student class
    student.displayName();

    return 0;
}