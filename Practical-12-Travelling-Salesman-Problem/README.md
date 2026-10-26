# Practical 12 : Travelling Salesman Problem using Dynamic Programming

## Aim

To find the minimum cost tour that visits every city exactly once and returns to the starting city, using dynamic programming with bitmasking.

## Objective

- To understand why brute force is impractical for the Travelling Salesman Problem.
- To solve TSP using the Held–Karp dynamic programming method.
- To represent subsets of cities using bitmasks and rebuild the optimal route.

## Introduction

In the Travelling Salesman Problem (TSP), a salesman must visit `n` cities exactly once and return to the starting city at the lowest total cost. Trying every possible order needs (n − 1)! permutations, which becomes impossible very quickly. The Held–Karp method uses dynamic programming instead. A subset of visited cities is stored as a bitmask, where bit `i` is 1 if city `i` has been visited. The state `dp[mask][i]` is the minimum cost of starting at city 0, visiting exactly the cities in `mask`, and ending at city `i`. The answer is found by trying every possible last city and adding the cost of returning to city 0. A `parent` table remembers the previous city of every state so that the route itself can be printed.

## Algorithm

1. Start.
2. Read the number of cities `n` and the `n × n` cost matrix.
3. Create `dp[2ⁿ][n]` filled with infinity and set `dp[1][0] = 0`, meaning only city 0 is visited and we stand at city 0.
4. For every `mask` that contains city 0:
   - For every city `i` in `mask` with a finite `dp[mask][i]`:
     - For every city `j` not in `mask`:
       - Let `next = mask | (1 << j)`.
       - If `dp[mask][i] + cost[i][j] < dp[next][j]`, update `dp[next][j]` and set `parent[next][j] = i`.
5. For each city `i` from 1 to n − 1, compute `dp[2ⁿ − 1][i] + cost[i][0]` and keep the minimum as the answer.
6. Rebuild the tour by following the `parent` table backwards from the best last city.
7. Print the tour and its minimum cost.
8. Stop.

---

## Sample Input and Output

```
Enter the number of cities: 4
Enter the cost matrix:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

Optimal tour : 0 -> 2 -> 3 -> 1 -> 0
Minimum cost of the tour = 80
```

The tour cost is 15 + 30 + 25 + 10 = 80. The reverse route 0 → 1 → 3 → 2 → 0 has the same cost.

---

## Complexity

Time Complexity : O(n² × 2ⁿ)
Space Complexity : O(n × 2ⁿ)

There are 2ⁿ × n states, and each state tries up to n next cities. This is exponential, but far better than the O(n!) brute force approach. For example, with 15 cities brute force needs about 8.7 × 10¹⁰ routes while Held–Karp needs about 7.4 × 10⁶ steps.

---

## Conclusion

TSP is an NP-hard problem, so no polynomial time algorithm is known for it. The Held–Karp dynamic programming method still gives the exact optimal tour and is much faster than checking every permutation, which makes it practical for up to around 20 cities. For larger inputs, approximation and heuristic methods are used instead.
