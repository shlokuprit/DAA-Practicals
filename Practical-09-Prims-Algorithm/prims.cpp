// Practical 9 : Minimum Spanning Tree using Prim's Algorithm

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Returns the unvisited vertex with the smallest key value
int minKey(const vector<int> &key, const vector<bool> &inMST) {
    int minVal = INT_MAX, minIndex = -1;

    for (int v = 0; v < (int)key.size(); v++) {
        if (!inMST[v] && key[v] < minVal) {
            minVal = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void primMST(const vector<vector<int>> &graph) {
    int V = graph.size();

    vector<int> parent(V, -1);      // parent[v] = vertex that connects v to the tree
    vector<int> key(V, INT_MAX);    // key[v] = cheapest edge weight to reach v
    vector<bool> inMST(V, false);

    key[0] = 0;   // start building the tree from vertex 0

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST);
        if (u == -1)
            break;   // graph is disconnected
        inMST[u] = true;

        // Update keys of the neighbours of u
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Every vertex except the root must have a parent
    for (int v = 1; v < V; v++) {
        if (parent[v] == -1) {
            cout << "\nThe graph is not connected, MST does not exist." << endl;
            return;
        }
    }

    int total = 0;
    cout << "\nEdges in the Minimum Spanning Tree:" << endl;
    cout << "Edge\t\tWeight" << endl;
    for (int v = 1; v < V; v++) {
        cout << parent[v] << " - " << v << "\t\t" << graph[v][parent[v]] << endl;
        total += graph[v][parent[v]];
    }

    cout << "\nTotal weight of the MST = " << total << endl;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (0 means no edge):" << endl;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    primMST(graph);

    cout << "\n----------------------------------------\n";
    cout << "Name           : Shlok Uprit\n";
    cout << "Enrollment No. : 92460118211\n";

    return 0;
}
