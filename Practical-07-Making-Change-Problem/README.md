# Practical 7 : Making Change Problem using Dynamic Programming

## Aim

To find the minimum number of coins required to make a given amount from a set of denominations.

## Objective

- To solve a coin change problem using a bottom up DP array.
- To understand why a greedy choice fails for arbitrary denominations.
- To detect amounts that cannot be formed at all.

## Introduction

Given an unlimited supply of coins of certain denominations, we want to pay an exact amount using as few coins as possible. A greedy approach that always picks the largest coin works for common currency systems but not in general. For example, with coins 1, 5, 6 and 9 and an amount of 11, greedy takes 9 + 1 + 1 which is three coins, while the true optimum is 5 + 6 which is only two. Dynamic programming avoids this trap by computing `dp[i]`, the fewest coins needed for amount `i`, for every value from 0 upwards. Each `dp[i]` tries every coin that fits and takes the best result.

## Algorithm

1. Start.
2. Read the number of denominations and the denomination values.
3. Read the target amount.
4. Create an array `dp` of size `amount + 1`, fill it with infinity, and set `dp[0] = 0`.
5. For `i` from 1 to `amount`:
   - For each coin `c` in the denomination list:
     - If `c <= i` and `dp[i - c]` is reachable, set `dp[i] = min(dp[i], dp[i - c] + 1)`.
6. If `dp[amount]` is still infinity, report that the change cannot be made.
7. Otherwise display `dp[amount]`.
8. Stop.

---

## Sample Input and Output

```
Enter the number of coin denominations: 4
Enter the denominations: 1 5 6 9
Enter the amount: 11

Minimum number of coins required = 2
```

When the amount cannot be formed:
```
Enter the number of coin denominations: 2
Enter the denominations: 5 10
Enter the amount: 3

Change cannot be made with the given denominations.
```

---

## Complexity

Time Complexity : O(amount × number of denominations)
Space Complexity : O(amount)

---

## Conclusion

The DP formulation guarantees the true minimum for any set of denominations, unlike the greedy method which is correct only for canonical coin systems. The cost grows with the numeric amount rather than the number of coin types, which again makes this a pseudo polynomial algorithm.
