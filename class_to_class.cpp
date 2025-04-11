#include <iostream>
#include <string>

using namespace std;

// Forward declaration of Time12 class
class Time12;

// Define a source class called Time24 representing time in 24-hour format
class Time24
{
private:
    int hours;
    int minutes;

public:
    // Constructor to initialize hours and minutes
    Time24(int h, int m) : hours(h), minutes(m) {}

    // Display function to show time in 24-hour format
    void displayTime24()
    {
        cout << "Time in 24-hour format: " << hours << ":" << (minutes < 10 ? "0" : "") << minutes << endl;
    }

    // Conversion operator to convert Time24 to Time12
    operator Time12() const;
};

// Define a destination class called Time12 representing time in 12-hour format
class Time12
{
private:
    int hours;
    int minutes;
    string period;

public:
    // Constructor to initialize hours, minutes, and period
    Time12(int h, int m, string p) : hours(h), minutes(m), period(p) {}

    // Display function to show time in 12-hour format
    void displayTime12()
    {
        cout << "Time in 12-hour format: " << hours << ":" << (minutes < 10 ? "0" : "") << minutes << " " << period << endl;
    }
};

// Definition of the conversion operator for Time24 to Time12
Time24::operator Time12() const
{
    string period = (hours < 12) ? "AM" : "PM";
    int hour12 = (hours > 12) ? hours - 12 : hours;
    if (hour12 == 0)
    {
        hour12 = 12; // 12:00 AM should be displayed as 12:00 AM
    }

    return Time12(hour12, minutes, period);
}

int main()
{
    // Create an object of the Time24 class
    Time24 time24(15, 30); // 3:30 PM

    // Convert Time24 to Time12 using the conversion operator
    Time12 time12 = time24;

    // Display the time in 12-hour format
    time12.displayTime12();

    return 0;
}