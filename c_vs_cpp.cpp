#include <iostream>
using namespace std;

class student
{
public:
    int roll;
    string name;
    int marks;
    void check_eligibilty(int marks)
    {
        if (marks >= 40)
        {
            printf("Eligible");
        }
        else
        {
            printf("Not Eligible!!");
        }
    }
};

int main()
{

    student s1;
    cout << "Enter roll number:" << endl;
    cin >> s1.roll;
    cout << "Enter name:" << endl;
    cin >> s1.name;
    cout << "Enter marks:" << endl;
    cin >> s1.marks;
    s1.check_eligibilty(s1.marks);

    return 0;
}