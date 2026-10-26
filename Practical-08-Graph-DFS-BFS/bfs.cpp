// Practical 8(b) : Breadth First Search (BFS)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Iterative BFS using a queue, visits the graph level by level
void bfs(int start, const vector<vector<int>> &adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
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

    cout << "\nBFS Traversal starting from vertex " << start << " : ";
    bfs(start, adj);
    cout << endl;

    cout << "\n----------------------------------------\n";
    cout << "Name           : Shlok Uprit\n";
    cout << "Enrollment No. : 92460118211\n";

    return 0;
}
