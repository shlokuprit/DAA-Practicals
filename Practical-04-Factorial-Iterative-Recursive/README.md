# Practical 4 : Factorial using Iterative and Recursive Methods

## Aim

To compute the factorial of a given number using both an iterative loop and a recursive function.

## Objective

- To implement the same mathematical definition in two different styles.
- To understand how recursion uses the call stack.
- To compare the space behaviour of iteration against recursion.

## Introduction

The factorial of a non negative integer n, written n!, is the product of all integers from 1 to n, with 0! defined as 1. The iterative version multiplies the numbers in a single loop and needs one accumulator variable. The recursive version uses the identity n! = n × (n−1)! and stops at the base case n = 0 or n = 1. Both produce the same answer, but the recursive form creates one stack frame per call, so its memory use grows with n.

## Algorithm

### Iterative Method

1. Start.
2. Read the number `n`.
3. Set `fact = 1`.
4. For `i` from 2 to `n`, set `fact = fact * i`.
5. Display `fact`.
6. Stop.

### Recursive Method

1. Start.
2. Read the number `n`.
3. If `n` is 0 or 1, return 1.
4. Otherwise return `n * factorial(n - 1)`.
5. Display the returned value.
6. Stop.

---

## Sample Input and Output

```
Enter a number: 6
Factorial using iterative method : 720
Factorial using recursive method : 720
```

Negative input is rejected:
```
Enter a number: -4
Factorial is not defined for negative numbers.
```

---

## Complexity

| Method | Time | Space |
|--------|------|-------|
| Iterative | O(n) | O(1) |
| Recursive | O(n) | O(n) for the call stack |

---

## Conclusion

Both methods take time proportional to n, but the iterative version uses constant memory while the recursive version consumes one stack frame per level. The recursive code is closer to the mathematical definition and easier to read, whereas the iterative code is safer for large inputs since it cannot overflow the stack. Note that the result itself grows very fast, so `long long` overflows beyond 20!.
