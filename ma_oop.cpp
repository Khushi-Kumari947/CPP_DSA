#include <iostream>
using namespace std;

class shop
{
    int ItemId[100];
    int ItemPrice[100];
    int counter;

public:
    void initcounter(void)
    {
        counter = 0;
    }

    void setPrice(void);
    void displayPrice(void);
};

void shop::setPrice()
{
    cout << "Enter the Id of item no " << counter + 1 << endl;
    cin >> ItemId[counter];
    cout << "Enter the price of item no " << counter + 1 << endl;
    cin >> ItemPrice[counter];
    counter++;
}

void shop::displayPrice()
{
    for (int i = 0; i <= counter; i++)
    {
        cout << "The price of Id " << ItemId[i] << " is " << ItemPrice[i] << endl;
    }
}

int main()
{

    shop dukaan;
    dukaan.initcounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.displayPrice();
    return 0;
}