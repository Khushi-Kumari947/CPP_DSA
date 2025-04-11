#include <iostream>
#include <cstring> // Include the C string library for strcpy

using namespace std;

class Student {
private:
    char name[50];
    int roll_no;
    char course[20];

public:
    // Constructor to initialize the student class
    Student(const char* n,int Roll,const char * crs) {
        strcpy(name, n); // Copy the name to the name array
        roll_no=Roll;
        strcpy(course,crs);
    }

    // Conversion operator to convert Student to const char*
    operator const char*() {
        return name; // Return the name array as const char*
    }
};

int main() {
    // Create an object of the Student class
    Student student("Edward",4,"Btech_cse");

    // Convert class type (Student) to primitive type (const char*)
    const char* studentName = student;
    //int roll=student;

    // Display the student's name using the converted primitive type
    cout << "Student's Name: " << studentName << endl;

    return 0;
}