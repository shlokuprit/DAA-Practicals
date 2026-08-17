# Practical 3 : Heap Sort using a Max Heap

## Aim

To sort an array in ascending order using the Heap Sort technique built on a max heap.

## Objective

- To represent a binary heap using a simple array.
- To understand the heapify operation that restores the heap property.
- To sort data by repeatedly extracting the maximum element.

## Introduction

A max heap is a complete binary tree in which every parent is greater than or equal to its children, so the largest value always sits at the root. When stored in an array, the children of index `i` lie at `2i + 1` and `2i + 2`. Heap Sort first turns the whole array into a max heap, then repeatedly swaps the root with the last unsorted position and rebuilds the heap over the shrinking range. Each extraction places one element in its correct final spot, and the array ends up sorted in ascending order without any auxiliary array.

## Algorithm

1. Start.
2. Read the array of `n` elements.
3. Build a max heap by calling heapify on every internal node from index `n/2 - 1` down to 0.
4. Set `end = n - 1`.
5. Exchange the root element with the element at index `end`, which fixes the current maximum in place.
6. Reduce the heap size by one and call heapify on the root to restore the max heap property.
7. Repeat steps 5 and 6 until `end` reaches the first index.
8. Display the sorted array.
9. Stop.

### Heapify (subtree rooted at index i, heap size n)

1. Assume the root index `i` holds the largest value.
2. Compare it with the left child, and update the largest index if the child is greater.
3. Compare it with the right child, and update the largest index if that child is greater.
4. If the largest index changed, exchange the two elements and heapify the affected subtree.

---

## Sample Input and Output

```
Enter the number of elements: 6
Enter 6 elements: 12 11 13 5 6 7
Sorted array: 5 6 7 11 12 13
```

---

## Complexity

| Case | Time |
|------|------|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n log n) |

Space Complexity : O(1) for the iterative sorting loop, plus O(log n) stack space used by the recursive heapify.

---

## Conclusion

Heap Sort guarantees O(n log n) running time in every case and sorts in place, which makes it more predictable than Quick Sort and lighter on memory than Merge Sort. It is not stable, and its scattered array accesses make it a little slower than Quick Sort in practice, but it is a reliable choice when the worst case must be bounded.
