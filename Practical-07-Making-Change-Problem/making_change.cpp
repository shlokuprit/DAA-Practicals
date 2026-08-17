// Practical 7 : Making Change Problem using Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int minCoins(const vector<int> &coin, int amount) {
    // dp[i] = minimum number of coins needed to make the amount i
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int c : coin) {
            if (c <= i && dp[i - c] != INF)
                dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }

    if (dp[amount] == INF)
        return -1;

    return dp[amount];
}

int main() {
    int n;
    cout << "Enter the number of coin denominations: ";
    cin >> n;

    vector<int> coin(n);
    cout << "Enter the denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int result = minCoins(coin, amount);

    if (result == -1)
        cout << "\nChange cannot be made with the given denominations." << endl;
    else
        cout << "\nMinimum number of coins required = " << result << endl;

    cout << "\n----------------------------------------\n";
    cout << "Name           : Shlok Uprit\n";
    cout << "Enrollment No. : 92460118211\n";

    return 0;
}
