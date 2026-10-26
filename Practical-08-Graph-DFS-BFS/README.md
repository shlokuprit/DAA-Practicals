# Practical 8 : Graph Traversal using DFS and BFS

## Aim

To traverse an undirected graph using Depth First Search and Breadth First Search in C++.

## Objective

- To represent a graph using an adjacency list.
- To implement DFS using recursion and BFS using a queue.
- To compare the order in which the two methods visit the vertices.

## Programs in this folder

| File | Algorithm | Data Structure Used |
|------|-----------|---------------------|
| `dfs.cpp` | Depth First Search | Recursion (call stack) |
| `bfs.cpp` | Breadth First Search | Queue |

## Introduction

Graph traversal means visiting every vertex reachable from a starting vertex exactly once. Depth First Search goes as deep as possible along one path before backtracking, so it naturally uses a stack, here the recursion stack. Breadth First Search visits all neighbours of a vertex before moving to the next level, so it uses a queue. A `visited` array in both methods makes sure no vertex is processed twice even when the graph has cycles. In both programs the neighbours of every vertex are sorted, so smaller numbered vertices are always visited first and the output is predictable.

---

## Algorithms

### Depth First Search

1. Start.
2. Read the number of vertices, the number of edges and the edge list.
3. Build the adjacency list and sort the neighbours of each vertex.
4. Read the starting vertex and mark all vertices as unvisited.
5. Call `DFS(start)`:
   - Mark the current vertex as visited and print it.
   - For each neighbour of the current vertex, if it is unvisited, call `DFS` on it.
6. Stop.

### Breadth First Search

1. Start.
2. Read the number of vertices, the number of edges and the edge list.
3. Build the adjacency list and sort the neighbours of each vertex.
4. Read the starting vertex, mark it visited and insert it into a queue.
5. While the queue is not empty:
   - Remove the front vertex and print it.
   - For each unvisited neighbour, mark it visited and insert it into the queue.
6. Stop.

---

## Sample Input and Output

Graph used for both programs:
```
0 --- 1 --- 3
|     |     |
2 --- 4 --- 5
```

### Depth First Search
```
Enter the number of vertices: 6
Enter the number of edges: 7
Enter 7 edges (u v), vertices numbered 0 to 5:
0 1
0 2
1 3
1 4
2 4
3 5
4 5
Enter the starting vertex: 0

DFS Traversal starting from vertex 0 : 0 1 3 5 4 2
```

### Breadth First Search
```
Enter the number of vertices: 6
Enter the number of edges: 7
Enter 7 edges (u v), vertices numbered 0 to 5:
0 1
0 2
1 3
1 4
2 4
3 5
4 5
Enter the starting vertex: 0

BFS Traversal starting from vertex 0 : 0 1 2 3 4 5
```

---

## Complexity

| Algorithm | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| DFS | O(V + E) | O(V) |
| BFS | O(V + E) | O(V) |

Here V is the number of vertices and E is the number of edges. Each vertex is visited once and each edge is examined twice, once from each end.

---

## Conclusion

Both DFS and BFS visit every reachable vertex in linear time, but in a different order. DFS follows one path to its end before backtracking, which makes it useful for detecting cycles and finding connected components. BFS explores level by level, so in an unweighted graph it reaches every vertex using the fewest possible edges, which makes it the natural choice for shortest path problems on unweighted graphs.
