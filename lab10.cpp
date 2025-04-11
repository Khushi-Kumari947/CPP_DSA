#include <iostream>
using namespace std;

// Interface class
class InterestCalculable
{
public:
    // Pure virtual function
    virtual void calculateInterest() = 0;
};  

// Concrete class implementing the InterestCalculable interface
class FixedDeposit : public InterestCalculable
{
private:
    double principal;
    double rate;
    double time;

public:
    // Constructor
    FixedDeposit(double p, double r, double t) : principal(p), rate(r), time(t) {}

    // Implementation of pure virtual function
    void calculateInterest() override
    {
        double interest = (principal * rate * time) / 100;
        cout << "Interest on Fixed Deposit: " << interest << endl;
    }
};

int main()
{
    FixedDeposit fd(10000.0, 8.5, 2.5);
    fd.calculateInterest();

    return 0;
}
