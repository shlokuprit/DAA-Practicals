# Practical 9 : Minimum Spanning Tree using Prim's Algorithm

## Aim

To find the Minimum Spanning Tree of a connected, weighted, undirected graph using Prim's Algorithm.

## Objective

- To understand the greedy method applied to graphs.
- To build a spanning tree by growing it one vertex at a time.
- To compute the total weight of the minimum spanning tree.

## Introduction

A spanning tree of a graph connects all of its vertices using exactly V − 1 edges and contains no cycle. Among all spanning trees, the one with the smallest total edge weight is called the Minimum Spanning Tree (MST). Prim's Algorithm builds the MST greedily. It starts from any vertex and, at every step, adds the cheapest edge that joins a vertex already in the tree to a vertex outside it. The array `key[v]` stores the cheapest known edge weight that connects `v` to the tree, and `parent[v]` stores the vertex at the other end of that edge.

## Algorithm

1. Start.
2. Read the number of vertices and the adjacency matrix, where 0 means no edge.
3. Set `key[v] = ∞` and `parent[v] = −1` for every vertex, and mark all vertices as not in the MST.
4. Set `key[0] = 0` so that vertex 0 is picked first.
5. Repeat V − 1 times:
   - Pick the vertex `u` not yet in the MST with the smallest `key` value.
   - Add `u` to the MST.
   - For every vertex `v` adjacent to `u` and not in the MST, if `weight(u, v) < key[v]`, set `key[v] = weight(u, v)` and `parent[v] = u`.
6. If any vertex other than 0 has no parent, report that the graph is disconnected.
7. Otherwise print every edge `parent[v] − v` and the total weight.
8. Stop.

---

## Sample Input and Output

```
Enter the number of vertices: 5
Enter the adjacency matrix (0 means no edge):
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Edges in the Minimum Spanning Tree:
Edge		Weight
0 - 1		2
1 - 2		3
0 - 3		6
1 - 4		5

Total weight of the MST = 16
```

When the graph is not connected:
```
Enter the number of vertices: 3
Enter the adjacency matrix (0 means no edge):
0 4 0
4 0 0
0 0 0

The graph is not connected, MST does not exist.
```

---

## Complexity

Time Complexity : O(V²)
Space Complexity : O(V²)

The adjacency matrix takes O(V²) space. The outer loop runs V times and each iteration scans all V vertices to find the minimum key and to update the neighbours, which gives O(V²). Using a binary heap with an adjacency list reduces the time to O(E log V).

---

## Conclusion

Prim's Algorithm always produces a minimum spanning tree because the cheapest edge crossing any cut between tree and non tree vertices is always safe to add. The matrix based version used here runs in O(V²), which is efficient for dense graphs where the number of edges is close to V².
