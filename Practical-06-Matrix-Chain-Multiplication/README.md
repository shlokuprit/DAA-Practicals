# Practical 6 : Matrix Chain Multiplication using Dynamic Programming

## Aim

To find the minimum number of scalar multiplications needed to multiply a chain of matrices.

## Objective

- To understand that matrix multiplication is associative in result but not in cost.
- To apply dynamic programming over increasing chain lengths.
- To find the optimal order of parenthesisation.

## Introduction

Multiplying a p × q matrix by a q × r matrix costs p × q × r scalar multiplications. When several matrices are multiplied in a chain, the final product is the same whatever order we use, but the cost can differ enormously. The dimensions are stored in an array `p`, where matrix Aᵢ has order `p[i-1] × p[i]`. We define `m[i][j]` as the least cost of multiplying Aᵢ through Aⱼ, and try every split point `k` between `i` and `j`, taking the cheapest. Chains are solved in order of increasing length so that every smaller subchain is ready before it is needed.

## Algorithm

1. Start.
2. Read the number of matrices `n` and the `n + 1` dimensions into array `p`.
3. Set `m[i][i] = 0` for all `i`, since a single matrix costs nothing.
4. For chain length `L` from 2 to `n`:
   - For every starting index `i` such that `j = i + L - 1` is valid:
     - Set `m[i][j]` to infinity.
     - For every split point `k` from `i` to `j - 1`, compute
       `cost = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]`.
     - Keep the smallest cost in `m[i][j]`.
5. Display `m[1][n]` as the minimum number of multiplications.
6. Stop.

---

## Sample Input and Output

```
Enter the number of matrices: 4
Enter 5 dimensions:
p[0] : 40
p[1] : 20
p[2] : 30
p[3] : 10
p[4] : 30

Order of the matrices:
A1 : 40 x 20
A2 : 20 x 30
A3 : 30 x 10
A4 : 10 x 30

Minimum number of scalar multiplications = 26000
```

The optimal grouping here is ((A1 A2)(A3 A4)).

---

## Complexity

Time Complexity : O(n³), because there are O(n²) subchains and each one tries up to n split points.
Space Complexity : O(n²) for the cost table.

---

## Conclusion

Checking every possible parenthesisation would take exponential time, since the number of ways to bracket n matrices grows like the Catalan numbers. Dynamic programming solves each subchain exactly once and combines the results, bringing the cost down to O(n³) and making the problem practical for reasonable chain lengths.
