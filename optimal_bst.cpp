#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Items
{
public:
    vector<int> keys;
    vector<int> frequencies;

    Items(int n)
    {
        keys.resize(n);
        frequencies.resize(n);
    }
};

class OptimalBST
{
private:
    Items items;
    vector<vector<int>> cost; // Cost table
    vector<vector<int>> root; // Root table for reconstruction
    int n;

public:
    OptimalBST(Items &items) : items(items), n(items.keys.size())
    {
        cost.resize(n, vector<int>(n, 0));
        root.resize(n, vector<int>(n, 0));
        calculateOptimalBST();
    }

    void calculateOptimalBST()
    {
        for (int len = 1; len <= n; ++len)
        {
            for (int i = 0; i <= n - len; ++i)
            {
                int j = i + len - 1;
                if (len == 1)
                {
                    cost[i][j] = items.frequencies[i];
                    root[i][j] = i;
                }
                else
                {
                    cost[i][j] = numeric_limits<int>::max();
                    int sumFreq = 0;
                    for (int k = i; k <= j; ++k)
                    {
                        sumFreq += items.frequencies[k];
                    }
                    for (int k = i; k <= j; ++k)
                    {
                        int c = (k > i ? cost[i][k - 1] : 0) +
                                (k < j ? cost[k + 1][j] : 0) + sumFreq;
                        if (c < cost[i][j])
                        {
                            cost[i][j] = c;
                            root[i][j] = k;
                        }
                    }
                }
            }
        }
    }

    void printCost()
    {
        cout << "Cost Table:\n";
        for (const auto &row : cost)
        {
            for (int val : row)
            {
                cout << val << "\t";
            }
            cout << endl;
        }
    }

    void printRoot()
    {
        cout << "Root Table:\n";
        for (const auto &row : root)
        {
            for (int val : row)
            {
                cout << val << "\t";
            }
            cout << endl;
        }
    }
};

class Graph
{
public:
    Graph() {}

    void optimalBSTFromAdjMatrix(vector<vector<int>> &adjMatrix)
    {
        int n = adjMatrix.size() - 1; // Exclude first row and column
        Items items(n);

        for (int i = 0; i < n; ++i)
        {
            items.keys[i] = adjMatrix[i + 1][0];        // first column as keys
            items.frequencies[i] = adjMatrix[i + 1][1]; // second column as frequencies
        }

        OptimalBST optimalBST(items);
        optimalBST.printCost();
        optimalBST.printRoot();
    }
};

int main()
{
    // Example adjacency matrix input (1-based index):
    // [key, frequency]
    vector<vector<int>> adjMatrix = {
        {0, 0}, // Dummy row for 1-based index
        {10, 34},
        {20, 8},
        {30, 50},
        {40, 13},
        {50, 20}};

    Graph graph;
    graph.optimalBSTFromAdjMatrix(adjMatrix);

    return 0;
}