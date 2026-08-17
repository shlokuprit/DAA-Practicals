# Practical 5 : 0/1 Knapsack Problem using Dynamic Programming

## Aim

To find the maximum profit obtainable by filling a knapsack of fixed capacity, where each item may be taken at most once.

## Objective

- To formulate an optimisation problem as overlapping subproblems.
- To build a bottom up DP table instead of trying all subsets.
- To understand the include or exclude decision at each item.

## Introduction

In the 0/1 Knapsack problem we are given n items, each with a weight and a value, and a bag that can carry a limited total weight. Every item is either taken whole or left behind, fractions are not allowed. A brute force search would examine 2ⁿ subsets. Dynamic programming avoids this by defining `dp[i][w]` as the best profit achievable using only the first `i` items with capacity `w`. For each cell we either skip item `i` and keep `dp[i-1][w]`, or take it and add its value to `dp[i-1][w - weight[i]]`, choosing whichever is larger. The answer sits at `dp[n][capacity]`.

## Algorithm

1. Start.
2. Read the number of items `n`, then the value and weight of each item.
3. Read the knapsack capacity `W`.
4. Create a table `dp` of size `(n + 1) × (W + 1)` and fill row 0 and column 0 with zero.
5. For `i` from 1 to `n`, and for `w` from 0 to `W`:
   - If `weight[i-1] > w`, the item does not fit, so set `dp[i][w] = dp[i-1][w]`.
   - Otherwise set `dp[i][w] = max(value[i-1] + dp[i-1][w - weight[i-1]], dp[i-1][w])`.
6. Display `dp[n][W]` as the maximum profit.
7. Stop.

---

## Sample Input and Output

```
Enter the number of items: 3
Enter the value and weight of each item:
Item 1 value  : 60
Item 1 weight : 10
Item 2 value  : 100
Item 2 weight : 20
Item 3 value  : 120
Item 3 weight : 30
Enter the capacity of the knapsack: 50

Maximum profit that can be obtained = 220
```

Here items 2 and 3 are selected, giving weight 20 + 30 = 50 and profit 100 + 120 = 220.

---

## Complexity

Time Complexity : O(n × W)
Space Complexity : O(n × W)

This is pseudo polynomial, since the cost depends on the numeric value of the capacity rather than only on the number of items. The space can be reduced to O(W) by keeping just one row.

---

## Conclusion

Dynamic programming reduces the knapsack search from exponential 2ⁿ subsets to a table of n × W entries by reusing the answers to smaller subproblems. The technique works because the problem has both optimal substructure and overlapping subproblems, which are the two conditions that make DP applicable.
