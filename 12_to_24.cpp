#include <iostream>
using namespace std;

class TimeConverter {
private:
    int hour;
    int minutes;

public:
    // Constructor
    TimeConverter() {
        hour = 0;
        minutes = 0;
    }

    // Function to set the time
    void setTime(int h, int m, string period) {
        if (h >= 1 && h <= 12 && m >= 0 && m <= 59) {
            hour = h;
            minutes = m;

            // Convert to 24-hour format if period is PM
            if (period == "PM" || period == "pm") {
                hour += 12;
                hour %= 24;
            }
        } else {
            cout << "Invalid time!" << endl;
        }
    }

    // Function to display time in 24-hour format
    void displayTime24() {
        cout << "Time in 24-hour format: ";
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (minutes < 10 ? "0" : "") << minutes << endl;
    }
};

int main() {
    TimeConverter timeObj;
    int h, m;
    string period;

    cout << "Enter time in 12-hour format (HH:MM AM/PM): ";
    cin >> h >> m >> period;

    timeObj.setTime(h, m, period);
    timeObj.displayTime24();

    return 0;
}
