// Practical 6 : Matrix Chain Multiplication using Dynamic Programming

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// p holds the dimensions, matrix i has order p[i-1] x p[i]
int matrixChainOrder(const vector<int> &p) {
    int n = p.size();

    vector<vector<int>> m(n, vector<int>(n, 0));

    // len is the length of the chain being considered
    for (int len = 2; len < n; len++) {
        for (int i = 1; i <= n - len; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter " << n + 1 << " dimensions:" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "p[" << i << "] : ";
        cin >> p[i];
    }

    cout << "\nOrder of the matrices:" << endl;
    for (int i = 1; i <= n; i++)
        cout << "A" << i << " : " << p[i - 1] << " x " << p[i] << endl;

    cout << "\nMinimum number of scalar multiplications = "
         << matrixChainOrder(p) << endl;

    cout << "\n----------------------------------------\n";
    cout << "Name           : Shlok Uprit\n";
    cout << "Enrollment No. : 92460118211\n";

    return 0;
}
