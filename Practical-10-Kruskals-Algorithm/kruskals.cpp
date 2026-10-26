// Practical 10 : Minimum Spanning Tree using Kruskal's Algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

// Disjoint Set Union, used to check whether an edge forms a cycle
int findParent(vector<int> &parent, int x) {
    if (parent[x] != x)
        parent[x] = findParent(parent, parent[x]);   // path compression
    return parent[x];
}

void unionSets(vector<int> &parent, vector<int> &rnk, int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);

    if (rnk[a] < rnk[b])
        parent[a] = b;
    else if (rnk[a] > rnk[b])
        parent[b] = a;
    else {
        parent[b] = a;
        rnk[a]++;
    }
}

void kruskalMST(int V, vector<Edge> &edges) {
    // Sort all edges in increasing order of weight
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    vector<int> parent(V), rnk(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<Edge> mst;
    int total = 0;

    for (const Edge &e : edges) {
        // Take the edge only if its endpoints are in different sets
        if (findParent(parent, e.u) != findParent(parent, e.v)) {
            unionSets(parent, rnk, e.u, e.v);
            mst.push_back(e);
            total += e.w;
        }

        if ((int)mst.size() == V - 1)
            break;
    }

    if ((int)mst.size() != V - 1) {
        cout << "\nThe graph is not connected, MST does not exist." << endl;
        return;
    }

    cout << "\nEdges in the Minimum Spanning Tree:" << endl;
    cout << "Edge\t\tWeight" << endl;
    for (const Edge &e : mst)
        cout << e.u << " - " << e.v << "\t\t" << e.w << endl;

    cout << "\nTotal weight of the MST = " << total << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter " << E << " edges (u v weight), vertices numbered 0 to " << V - 1 << ":" << endl;
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    kruskalMST(V, edges);

    cout << "\n----------------------------------------\n";
    cout << "Name           : Shlok Uprit\n";
    cout << "Enrollment No. : 92460118211\n";

    return 0;
}
