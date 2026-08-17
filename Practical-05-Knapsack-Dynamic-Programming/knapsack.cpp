// Practical 5 : 0/1 Knapsack Problem using Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

int knapsack(const vector<int> &value, const vector<int> &weight, int capacity) {
    int n = value.size();

    // dp[i][w] = best profit using the first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                int include = value[i - 1] + dp[i - 1][w - weight[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = max(include, exclude);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> value(n), weight(n);

    cout << "Enter the value and weight of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " value  : ";
        cin >> value[i];
        cout << "Item " << i + 1 << " weight : ";
        cin >> weight[i];
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "\nMaximum profit that can be obtained = "
         << knapsack(value, weight, capacity) << endl;

    cout << "\n----------------------------------------\n";
    cout << "Name           : Shlok Uprit\n";
    cout << "Enrollment No. : 92460118211\n";

    return 0;
}
