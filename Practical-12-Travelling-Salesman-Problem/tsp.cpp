// Practical 12 : Travelling Salesman Problem using Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter the cost matrix:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    int FULL = 1 << n;

    // dp[mask][i] = minimum cost to start at city 0, visit exactly the cities
    // in mask, and end at city i
    vector<vector<int>> dp(FULL, vector<int>(n, INF));
    vector<vector<int>> parent(FULL, vector<int>(n, -1));

    dp[1][0] = 0;   // only city 0 visited, standing at city 0

    for (int mask = 1; mask < FULL; mask++) {
        if (!(mask & 1))
            continue;   // every route must contain the starting city

        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i)) || dp[mask][i] == INF)
                continue;

            // Try moving from city i to an unvisited city j
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j))
                    continue;

                int next = mask | (1 << j);
                int newCost = dp[mask][i] + cost[i][j];

                if (newCost < dp[next][j]) {
                    dp[next][j] = newCost;
                    parent[next][j] = i;
                }
            }
        }
    }

    // Close the tour by returning to city 0
    int best = INF, last = -1;
    for (int i = 1; i < n; i++) {
        if (dp[FULL - 1][i] == INF)
            continue;
        int total = dp[FULL - 1][i] + cost[i][0];
        if (total < best) {
            best = total;
            last = i;
        }
    }

    if (n == 1) {
        best = 0;
        last = 0;
    }

    // Rebuild the route by walking back through parent[][]
    vector<int> path;
    int mask = FULL - 1, cur = last;
    while (cur != -1) {
        path.push_back(cur);
        int prev = parent[mask][cur];
        mask ^= (1 << cur);
        cur = prev;
    }
    reverse(path.begin(), path.end());
    if (n > 1)
        path.push_back(0);

    cout << "\nOptimal tour : ";
    for (int k = 0; k < (int)path.size(); k++) {
        cout << path[k];
        if (k + 1 < (int)path.size())
            cout << " -> ";
    }
    cout << endl;

    cout << "Minimum cost of the tour = " << best << endl;

    cout << "\n----------------------------------------\n";
    cout << "Name           : Shlok Uprit\n";
    cout << "Enrollment No. : 92460118211\n";

    return 0;
}
