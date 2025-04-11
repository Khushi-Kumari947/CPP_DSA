 

#include <iostream>
using namespace std;

class TimeKeeper
{
private:
    int hours;
    int minutes;

public:
    TimeKeeper()
    {
        hours = 0;
        minutes = 0;
    }
    TimeKeeper(int h, int m)
    {
        hours = h;
        minutes = m;
    }

    void Add_minutes(int min)
    {
        hours = hours + min / 60;
        minutes = minutes + min;
        minutes = minutes % 60;
        hours = hours % 24;//To ensure clock to be in 24-Hour format
    }

    void setTime(int h, int m)
    {
        if (h >= 0 && h < 24 && m >= 0 && m < 60)
        {
            hours = h;
            minutes = m;
        }
        else
        {
            cout << "Invalid time input!\n";
        }
    }

    void convertTo12Hour()
    {
        string period = (hours < 12) ? "AM" : "PM";
        int hour12 = (hours > 12) ? hours - 12 : hours;
        if (hour12 == 0)
        {
            hour12 = 12; // 12:00 AM should be displayed as 12:00 AM
        }
        cout << "Time in 12-hour format: " << hour12 << ":" << (minutes < 10 ? "0" : "") << minutes << " " << period << endl;
    }
};


int main() {
    TimeKeeper t;
    int h, m;
    cout << "Enter time in 24-hour format (HH MM): ";
    cin >> h >> m;

    t.setTime(h, m);
    t.convertTo12Hour();

    return 0;
}