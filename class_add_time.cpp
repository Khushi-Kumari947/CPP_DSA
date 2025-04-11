#include <iostream>

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructor to initialize time
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}

    // Function to add hours
    void add(int h) {
        hour += h;
        hour %= 24; // Ensure hour remains within 24-hour range
    }

    // Function to add hours and minutes
    void add(int h, int m) {
        minute += m;
        hour += h + minute / 60;
        minute %= 60;
        hour %= 24; // Ensure hour remains within 24-hour range
    }

    // Function to add hours, minutes, and seconds
    void add(int h, int m, int s) {
        second += s;
        minute += m + second / 60;
        second %= 60;
        hour += h + minute / 60;
        minute %= 60;
        hour %= 24; // Ensure hour remains within 24-hour range
    }

    // Function to display time
    void displayTime() {
        std::cout << "Time: " << hour << ":" << minute << ":" << second << std::endl;
    }
};

int main() {
    Time t(10, 30, 45);

    // Display initial time
    std::cout << "Initial ";
    t.displayTime();

    // Add 2 hours
    t.add(2);
    std::cout << "After adding 2 hours: ";
    t.displayTime();

    // Add 3 hours and 20 minutes
    t.add(3, 20);
    std::cout << "After adding 3 hours and 20 minutes: ";
    t.displayTime();

    // Add 1 hour, 15 minutes, and 10 seconds
    t.add(1, 15, 10);
    std::cout << "After adding 1 hour, 15 minutes, and 10 seconds: ";
    t.displayTime();
    t.add(1, 75, 10);
    std::cout << "After adding 1 hour, 15 minutes, and 10 seconds: ";
    t.displayTime();

    return 0;
}
