#include <iostream>
#include <vector>

using namespace std;

// Bottom-up exponentiation function
long long powerBottomUp(int a, int n) {
    // Base case: a^0 = 1
    if (n == 0) {
        return 1;
    }

    // Initialize the DP table
    vector<long long> dp(n + 1, 1);

    // Fill the table using the recurrence relation
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            dp[i] = dp[i / 2] * dp[i / 2];
        } else {
            dp[i] = a * dp[i - 1];
        }
    }

    return dp[n];
}

int main() {
    int a = 9;
    int n = 3;
    long long result = powerBottomUp(a, n);
    cout << a << "^" << n << " = " << result << endl;
    return 0;
}
