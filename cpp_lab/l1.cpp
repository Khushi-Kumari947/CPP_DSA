#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort function
void bubble_sort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

int main() {
    int N;
    cin >> N;  // number of elements
    vector<int> a(N);
    for (int &x : a) cin >> x;  // input elements

    bubble_sort(a);

    for (int x : a) cout << x << " ";  // output sorted array
    return 0;
}
