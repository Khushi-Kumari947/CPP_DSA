#include <iostream>
#include <vector>
using namespace std;

class Knapsack {
private:
    int maxWeight;
    vector<int> weights;
    vector<int> values;
    vector<vector<int>> memo;

public:
    // Constructor to initialize values and weights
    Knapsack(int maxW, vector<int>& w, vector<int>& v) {
        maxWeight = maxW;
        weights = w;
        values = v;
        memo.resize(w.size() + 1, vector<int>(maxWeight + 1, -1));  // Initialize memo table to -1 for memoization
    }

    // Recursive function to solve knapsack problem
    int kp_rec(int n, int capacity) {
        // Base case: no items left or no capacity
        if (n == 0 || capacity == 0)
            return 0;

        // If the weight of the nth item is more than the capacity, skip it
        if (weights[n - 1] > capacity)
            return kp_rec(n - 1, capacity);

        // Return the maximum of including or not including the current item
        else
            return max(
                values[n - 1] + kp_rec(n - 1, capacity - weights[n - 1]),  // Include the item
                kp_rec(n - 1, capacity)  // Exclude the item
            );
    }

    // Memoization function to solve knapsack problem
    int kp_mem(int n, int capacity) {
        // Base case: no items left or no capacity
        if (n == 0 || capacity == 0)
            return 0;

        // Check if the solution is already computed
        if (memo[n][capacity] != -1)
            return memo[n][capacity];

        // If the weight of the nth item is more than the capacity, skip it
        if (weights[n - 1] > capacity)
            memo[n][capacity] = kp_mem(n - 1, capacity);
        else
            // Store the result of including or not including the current item
            memo[n][capacity] = max(
                values[n - 1] + kp_mem(n - 1, capacity - weights[n - 1]),  // Include the item
                kp_mem(n - 1, capacity)  // Exclude the item
            );

        return memo[n][capacity];
    }

    // Function to solve using recursion
    int solveRecursively() {
        return kp_rec(weights.size(), maxWeight);
    }

    // Function to solve using memoization
    int solveMemoization() {
        return kp_mem(weights.size(), maxWeight);
    }
};

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int maxWeight = 50;

    // Create an instance of the Knapsack class
    Knapsack ks(maxWeight, weights, values);

    // Solve the knapsack problem using recursion and memoization
    cout << "Max value (Recursive): " << ks.solveRecursively() << endl;
    cout << "Max value (Memoization): " << ks.solveMemoization() << endl;

    return 0;
}
