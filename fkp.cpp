#include <iostream>
#include <algorithm>
using namespace std;

class item {
public:
    int weight;
    int value;
    double pf; // profit factor (value/weight)

    item(int w, int v) {
        this->weight = w;
        this->value = v;
        this->pf = static_cast<double>(v) / w; // Ensure floating-point division
    }
};

class fractional_knapSack {
public:
    // Comparator function to sort items by their profit factor in descending order
    static bool cmp(const item &I1, const item &I2) {
        return I1.pf > I2.pf;
    }

    double fKnapSack(int capacity, item arr[], int n) {
        // Sort items by profit factor in descending order
        sort(arr, arr + n, cmp);
        
        double final_value = 0.0;

        for (int i = 0; i < n; i++) {
            // If the item can be included completely
            if (arr[i].weight <= capacity) {
                capacity -= arr[i].weight;
                final_value += arr[i].value;
            }
            // If the item can't be included completely, include fractionally
            else {
                final_value += arr[i].value * ((double)capacity / arr[i].weight);
                break;
            }
        }

        return final_value;
    }
};

int main() {
    int W = 50; // Maximum capacity of the knapsack
    item I[] = {item(10, 60), item(20, 100), item(30, 120)};
    fractional_knapSack f;
    cout << "Maximum value = " << f.fKnapSack(W, I, 3) << endl;
    return 0;
}
