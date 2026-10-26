// Practical 11 : All Pairs Shortest Path using Floyd-Warshall Algorithm

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>> &dist) {
    int V = dist.size();

    // Allow vertex k as an intermediate vertex, one at a time
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

void printMatrix(const vector<vector<int>> &dist) {
    int V = dist.size();

    cout << "\t";
    for (int j = 0; j < V; j++)
        cout << j << "\t";
    cout << endl;

    for (int i = 0; i < V; i++) {
        cout << i << "\t";
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> dist(V, vector<int>(V));

    cout << "Enter the adjacency matrix (-1 means no direct edge):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> dist[i][j];
            if (dist[i][j] == -1)
                dist[i][j] = INF;
        }
    }

    floydWarshall(dist);

    // A negative value on the diagonal means a negative weight cycle
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "\nThe graph contains a negative weight cycle." << endl;
            cout << "\n----------------------------------------\n";
            cout << "Name           : Shlok Uprit\n";
            cout << "Enrollment No. : 92460118211\n";
            return 0;
        }
    }

    cout << "\nShortest distance matrix:" << endl;
    printMatrix(dist);

    cout << "\n----------------------------------------\n";
    cout << "Name           : Shlok Uprit\n";
    cout << "Enrollment No. : 92460118211\n";

    return 0;
}
