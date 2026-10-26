# Practical 11 : All Pairs Shortest Path using Floyd–Warshall Algorithm

## Aim

To find the shortest distance between every pair of vertices in a weighted directed graph using the Floyd–Warshall Algorithm.

## Objective

- To solve the all pairs shortest path problem using dynamic programming.
- To understand how intermediate vertices are introduced one at a time.
- To detect a negative weight cycle in the graph.

## Introduction

The Floyd–Warshall Algorithm computes the shortest path between every pair of vertices in a single run. It is a dynamic programming method. Let `dist[i][j]` be the shortest distance from `i` to `j` using only vertices `0 … k − 1` as intermediate stops. When vertex `k` is also allowed, the best path from `i` to `j` either avoids `k` or goes through it, so

`dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`.

After all V vertices have been allowed as intermediates, `dist` holds the true shortest distances. The algorithm works with negative edge weights, and if any diagonal entry `dist[i][i]` becomes negative, the graph contains a negative weight cycle.

## Algorithm

1. Start.
2. Read the number of vertices and the adjacency matrix, where −1 means there is no direct edge.
3. Replace every −1 with infinity to form the initial distance matrix.
4. For `k` from 0 to V − 1:
   - For `i` from 0 to V − 1:
     - For `j` from 0 to V − 1:
       - If `dist[i][k] + dist[k][j] < dist[i][j]`, set `dist[i][j] = dist[i][k] + dist[k][j]`.
5. If any `dist[i][i] < 0`, report a negative weight cycle.
6. Otherwise print the distance matrix, showing INF where no path exists.
7. Stop.

---

## Sample Input and Output

```
Enter the number of vertices: 4
Enter the adjacency matrix (-1 means no direct edge):
0 3 -1 7
8 0 2 -1
5 -1 0 1
2 -1 -1 0

Shortest distance matrix:
	0	1	2	3
0	0	3	5	6
1	5	0	2	3
2	3	6	0	1
3	2	5	7	0
```

When the graph has a negative weight cycle:
```
Enter the number of vertices: 3
Enter the adjacency matrix (-1 means no direct edge):
0 1 -1
-1 0 -3
1 -1 0

The graph contains a negative weight cycle.
```

Note: since −1 is used to mark a missing edge, an edge of weight exactly −1 cannot be entered.

---

## Complexity

Time Complexity : O(V³)
Space Complexity : O(V²)

The three nested loops each run V times, and only one V × V distance matrix is stored and updated in place.

---

## Conclusion

The Floyd–Warshall Algorithm finds the shortest paths between all pairs of vertices with a short and simple triple loop. Its O(V³) cost is the same for every graph, so it is most suitable for small or dense graphs. Unlike Dijkstra's Algorithm, it handles negative edge weights and can also detect negative weight cycles.
