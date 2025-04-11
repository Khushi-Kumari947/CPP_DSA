#include <iostream>
#include <unordered_map>

using namespace std;

// Helper function for top-down approach with memoization
long long powerTopDown(int a, int n, unordered_map<int, long long>& memo) {
    // Base case: a^0 = 1
    if (n == 0) {
        return 1;
    }

    // Check if the result is already in the memo table
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    // Compute power recursively and store it in the memo table
    if (n % 2 == 0) {
        long long halfPower = powerTopDown(a, n / 2, memo);
        memo[n] = halfPower * halfPower;
    } else {
        memo[n] = a * powerTopDown(a, n - 1, memo);
    }

    return memo[n];
}

// Top-down exponentiation function
long long powerTopDown(int a, int n) {
    unordered_map<int, long long> memo;
    return powerTopDown(a, n, memo);
}

int main() {
    int a = 8;
    int n = 5;
    long long result = powerTopDown(a, n);
    cout << a << "^" << n << " = " << result << endl;
    return 0;
}
