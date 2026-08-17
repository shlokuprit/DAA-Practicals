# Practical 1 : Sorting Algorithms

## Aim

To implement Bubble Sort, Selection Sort, Insertion Sort, Merge Sort and Quick Sort in C++ and compare their efficiency.

## Objective

- To understand how each sorting technique arranges elements in ascending order.
- To distinguish between comparison based iterative sorting and divide and conquer sorting.
- To analyse the time and space complexity of each method.

## Programs in this folder

| File | Algorithm | Approach |
|------|-----------|----------|
| `bubble_sort.cpp` | Bubble Sort | Repeated adjacent comparison |
| `selection_sort.cpp` | Selection Sort | Repeated minimum selection |
| `insertion_sort.cpp` | Insertion Sort | Incremental insertion |
| `merge_sort.cpp` | Merge Sort | Divide and Conquer |
| `quick_sort.cpp` | Quick Sort | Divide and Conquer with partitioning |

---

## Algorithms

### Bubble Sort

1. Start.
2. Compare each pair of neighbouring elements from the beginning of the array.
3. If the left element is larger than the right one, exchange them.
4. After one complete pass the largest remaining element settles at the end.
5. Repeat for the shrinking unsorted portion.
6. If a pass finishes without any exchange, the array is already sorted, so stop early.
7. Display the sorted array.
8. Stop.

### Selection Sort

1. Start.
2. Treat position `i` as the boundary between the sorted and unsorted parts.
3. Scan the unsorted part and note the index of the smallest element.
4. Exchange that smallest element with the element at position `i`.
5. Move the boundary one step forward and repeat until only one element is left.
6. Display the sorted array.
7. Stop.

### Insertion Sort

1. Start.
2. Assume the first element forms a sorted sublist.
3. Pick the next element and call it `key`.
4. Move every element of the sorted sublist that is greater than `key` one position to the right.
5. Place `key` in the gap created.
6. Repeat steps 3 to 5 until the array ends.
7. Display the sorted array.
8. Stop.

### Merge Sort

1. Start.
2. If the segment has one element or fewer, it is already sorted, so return.
3. Find the middle index and split the segment into two halves.
4. Sort the left half recursively.
5. Sort the right half recursively.
6. Merge the two sorted halves by repeatedly taking the smaller front element.
7. Display the sorted array.
8. Stop.

### Quick Sort

1. Start.
2. If the segment has one element or fewer, return.
3. Choose the last element of the segment as the pivot.
4. Rearrange the segment so that smaller elements move before the pivot and larger ones after it.
5. Note the final resting index of the pivot.
6. Apply the same procedure to the part before the pivot.
7. Apply the same procedure to the part after the pivot.
8. Display the sorted array.
9. Stop.

---

## Sample Input and Output

### Bubble Sort
```
Enter the number of elements: 7
Enter 7 elements: 64 34 25 12 22 11 90
Sorted array: 11 12 22 25 34 64 90
```

### Selection Sort
```
Enter the number of elements: 5
Enter 5 elements: 64 25 12 22 11
Sorted array: 11 12 22 25 64
```

### Insertion Sort
```
Enter the number of elements: 5
Enter 5 elements: 12 11 13 5 6
Sorted array: 5 6 11 12 13
```

### Merge Sort
```
Enter the number of elements: 7
Enter 7 elements: 38 27 43 3 9 82 10
Sorted array: 3 9 10 27 38 43 82
```

### Quick Sort
```
Enter the number of elements: 6
Enter 6 elements: 10 7 8 9 1 5
Sorted array: 1 5 7 8 9 10
```

---

## Complexity Comparison

| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No |

---

## Conclusion

The three elementary methods are easy to code but degrade quickly as the input grows, since all of them perform roughly n² comparisons in the average case. Merge Sort holds O(n log n) in every case but needs extra memory for merging, whereas Quick Sort usually runs fastest in practice with very little extra space, at the risk of an O(n²) worst case when the pivot repeatedly divides the array badly.
