#include <iostream>
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
        cout << "default constructor called!!" << endl;
    }

    time(int h, int m, int s)
    {
        hour = h;
        minute = m;
        seconds = s;
        cout << "parameterized constructor called!!" << endl;
    }

    time(time &T)
    {
        hour = T.hour;
        minute = T.minute;
        seconds = T.seconds;
        cout << "copy constructor called!!" << endl;
    }

    void display()
    {
        cout << "Hour:" << hour << endl;
        cout << "Minutes:" << minute << endl;
        cout << "seconds:" << seconds << endl;
    }

    void add(int h)
    {
        if (hour > 24)
        {
            hour = h - 24;
        }
        else
        {
            hour = hour + h;
            if (hour > 24)
            {
                hour = hour - 24;
            }
        }
    }

    void add(int h, int m)
    {
        hour = hour + h;
        if (hour > 24)
        {
            hour = hour - 24;
        }

        if (m / 60 == 0)
        {
            minute = minute + m;
            if (minute >= 60)
            {
                int m1 = m / 60;
                hour = hour + m1;
                if (hour > 24)
                {
                    hour = h - 24;
                }
                float m2 = m / 60;
                minute = minute + (m2 - m1);
            }
        }
        else
        {
            int m1 = m / 60;
            hour = hour + m1;
            if (hour > 24)
            {
                hour = h - 24;
            }
            float m2 = m / 60;
            minute = minute + (m2 - m1);
        }
    }

    void add(int h, int m, int s)
    {
        add(h, m);
        if (s / 60 == 0)
        {
            seconds = seconds + s;
        }
        else
        {
            float s1 = s / 3600;
            int h1 = int(s1);
            if (hour > 24)
            {
                int h4 = hour - h1;
                hour = abs(h4);
                if (hour > 24)
                {
                    hour = hour - 24;
                }
            }
            else
            {
                hour = hour + h1;
                if (hour > 24)
                {
                    hour = hour - 24;
                }
            }
            float m1 = (s1 - h1) * 60;
            int m2 = int(m1);
            // minute = minute + m2;
            seconds = seconds + (m1 - m2);
            if(seconds>=60)
            {
                float s1 = s / 60;
            }
        }
    }
};
int main(int argc, char *argv[])
{

    //  int i, j, k;
    // i = atoi(argv[1]);
    // j = atoi(argv[2]);
    // k = atoi(argv[3]);
    // time t1;
    // t1.display();
    // time t3(2, 30, 50);
    // t3.display();
    // time t2(5, 42, 13);
    // t2.display();
    // time t4(t3);
    // t4.display();
    // time t5;
    // t5 = t3;
    // t5.display();
    // cout << &t5 << "  " << &t3 << endl;
    time t;
    t.add(25);
    t.display();
    t.add(25, 45);
    t.display();
    t.add(25, 45, 23);
    t.display();
    return 0;
}