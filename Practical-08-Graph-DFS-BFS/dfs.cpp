// Practical 8(a) : Depth First Search (DFS)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive DFS, visits a vertex and then goes as deep as possible
void dfs(int u, const vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v, adj, visited);
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter " << E << " edges (u v), vertices numbered 0 to " << V - 1 << ":" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // undirected graph
    }

    // Sort neighbours so that smaller vertices are visited first
    for (int i = 0; i < V; i++)
        sort(adj[i].begin(), adj[i].end());

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    vector<bool> visited(V, false);

    cout << "\nDFS Traversal starting from vertex " << start << " : ";
    dfs(start, adj, visited);
    cout << endl;

    cout << "\n----------------------------------------\n";
    cout << "Name           : Shlok Uprit\n";
    cout << "Enrollment No. : 92460118211\n";

    return 0;
}
