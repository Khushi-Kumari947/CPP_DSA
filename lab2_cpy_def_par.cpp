#include <iostream>
#include <cstdlib>
using namespace std;

class time
{
private:
    int hour;
    int minute;
    int seconds;

public:
    time()
    {
        hour = 0;
        minute = 0;
        seconds = 0;
        cout<<"default constructor called!!"<<endl;
    }

    time(int h, int m, int s)
    {
        hour = h;
        minute = m;
        seconds = s;
        cout<<"parameterized constructor called!!"<<endl;
    }

    time(time &T)
    {
        hour = T.hour;
        minute = T.minute;
        seconds = T.seconds;
        cout<<"copy constructor called!!"<<endl;
    }

    void display()
    {
        cout<<"Hour:"<<hour<<endl;
        cout<<"Minutes:"<<minute<<endl;
        cout<<"seconds:"<<seconds<<endl;

    }
};

int main(int argc, char *argv[])
{

    int i, j, k;
    i = atoi(argv[1]);
    j = atoi(argv[2]);
    k = atoi(argv[3]);
    time t1;
    t1.display();
    time t3(2,30,50);
    t3.display();
    time t2(i,j,k);
    t2.display();
    time t4(t3);
    t4.display();

    return 0;
}