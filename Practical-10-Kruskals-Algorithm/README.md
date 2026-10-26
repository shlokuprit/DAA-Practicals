# Practical 10 : Minimum Spanning Tree using Kruskal's Algorithm

## Aim

To find the Minimum Spanning Tree of a connected, weighted, undirected graph using Kruskal's Algorithm.

## Objective

- To apply the greedy method by processing edges in increasing order of weight.
- To use the Disjoint Set Union (Union Find) structure for cycle detection.
- To compute the total weight of the minimum spanning tree.

## Introduction

Kruskal's Algorithm builds the Minimum Spanning Tree edge by edge instead of vertex by vertex. All edges are sorted by weight, and the algorithm repeatedly takes the cheapest remaining edge, as long as adding it does not form a cycle. To check for a cycle quickly, every vertex belongs to a set, and two vertices are in the same set when they are already connected. An edge whose endpoints are in the same set would create a cycle, so it is skipped. The Disjoint Set Union structure with path compression and union by rank performs these checks in almost constant time.

## Algorithm

1. Start.
2. Read the number of vertices, the number of edges and every edge as `(u, v, weight)`.
3. Sort all edges in increasing order of weight.
4. Make a separate set for every vertex.
5. For each edge `(u, v, w)` in sorted order:
   - If `find(u) != find(v)`, add the edge to the MST, add `w` to the total and perform `union(u, v)`.
   - Stop early once the MST contains V − 1 edges.
6. If the MST has fewer than V − 1 edges, report that the graph is disconnected.
7. Otherwise print the MST edges and the total weight.
8. Stop.

---

## Sample Input and Output

```
Enter the number of vertices: 4
Enter the number of edges: 5
Enter 5 edges (u v weight), vertices numbered 0 to 3:
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Edges in the Minimum Spanning Tree:
Edge		Weight
2 - 3		4
0 - 3		5
0 - 1		10

Total weight of the MST = 19
```

When the graph is not connected:
```
Enter the number of vertices: 4
Enter the number of edges: 2
Enter 2 edges (u v weight), vertices numbered 0 to 3:
0 1 3
2 3 5

The graph is not connected, MST does not exist.
```

---

## Complexity

Time Complexity : O(E log E)
Space Complexity : O(V + E)

Sorting the edges takes O(E log E). The union and find operations with path compression and union by rank are nearly constant each, so the sort dominates the running time. The edge list needs O(E) space and the parent and rank arrays need O(V).

---

## Conclusion

Kruskal's Algorithm produces the same total MST weight as Prim's Algorithm but works from the edges rather than the vertices. Because its cost depends mainly on sorting the edges, it is especially efficient for sparse graphs, while Prim's matrix version suits dense graphs better.
