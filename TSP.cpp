#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

// Class representing the Traveling Salesman Problem
class TravelingSalesmanProblem {
private:
    int numCities;                   // Number of cities
    vector<vector<int>> distance;    // Distance matrix
    
public:
    // Constructor
    TravelingSalesmanProblem(int cities, vector<vector<int>> distMatrix)
        : numCities(cities), distance(distMatrix) {}

    // Function to solve the TSP problem and return the minimum cost
    int solve() {
        set<int> remainingCities;  // Set of remaining cities
        for (int i = 1; i < numCities; i++) {
            remainingCities.insert(i);  // Add all cities except the start city (0)
        }

        vector<int> path;
        path.push_back(0);  // Start from the first city (index 0)
        return tspUtil(0, remainingCities, 0);
    }

    // Recursive utility function to calculate TSP and return minimum cost
    int tspUtil(int currentCity, set<int>& remainingCities, int currentCost) {
        // Base case: If all cities have been visited, return to the starting city
        if (remainingCities.empty()) {
            return currentCost + distance[currentCity][0];  // Return cost to start
        }

        int minCost = INT_MAX;  // Initialize min cost for this recursion level

        // Try visiting all remaining cities
        for (int nextCity : remainingCities) {
            set<int> newRemainingCities = remainingCities;  // Copy the current set
            newRemainingCities.erase(nextCity);             // Remove the next city from remaining

            // Recursive call to visit the next city
            int totalCost = tspUtil(nextCity, newRemainingCities, currentCost + distance[currentCity][nextCity]);
            minCost = min(minCost, totalCost);  // Keep track of the minimum cost
        }

        return minCost;  // Return the minimum cost for this recursion level
    }
};

int main() {
    int numCities = 4;
    vector<vector<int>> distanceMatrix = {
        {0, 6, 1, 3},
        {4, 0, 2, 1},
        {1, 2, 0, 8}, 
        {3, 1, 7, 0}
    };

    TravelingSalesmanProblem tsp(numCities, distanceMatrix);
    int minCost = tsp.solve();
    cout << "Minimum cost: " << minCost << endl;

    return 0;
}
