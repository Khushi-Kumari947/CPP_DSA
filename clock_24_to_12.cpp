#include<iostream>
using namespace std;


#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    Time() {
        hours = 0;
        minutes = 0;
    }

    void setTime(int h, int m) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60) {
            hours = h;
            minutes = m;
        } else {
            cout << "Invalid time input!\n";
        }
    }

    void convertTo12Hour() {
        string period = (hours < 12) ? "AM" : "PM";
        int hour12 = (hours > 12) ? hours - 12 : hours;
        if (hour12 == 0) {
            hour12 = 12; // 12:00 AM should be displayed as 12:00 AM
        }
        cout << "Time in 12-hour format: " << hour12 << ":" << (minutes < 10 ? "0" : "") << minutes << " " << period << endl;
    }
};

int main() {
    Time t;
    int h, m;
    cout << "Enter time in 24-hour format (HH MM): ";
    cin >> h >> m;

    t.setTime(h, m);
    t.convertTo12Hour();

    return 0;
}