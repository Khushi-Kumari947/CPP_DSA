#include <iostream>
#include <cstdlib>
using namespace std;

int sum(int a, int b)
{
    return a + b;
}

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }
    void display()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main(int argc, char *argv[])
{

    // Display the total number of command line arguments
    cout << "Total number of command line arguments: " << argc << endl;
    int i = atoi(argv[1]);
    int j = atoi(argv[2]);
    int k = atoi(argv[3]);
    // cout<<"The sum is "<<sum(i,j)<<argv[0]<<endl;

    // Display each command line argument

    Time t(i, j, k);
    t.display();
    for (int i = 0; i < argc; ++i)
    {
        cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
