# Practical 2 : Linear Search and Binary Search

## Aim

To search for a given element in an array using Linear Search and Binary Search in C++.

## Objective

- To implement sequential searching on an unsorted array.
- To implement interval halving on a sorted array.
- To understand why sorting the data changes the cost of searching.

## Programs in this folder

| File | Algorithm | Requirement |
|------|-----------|-------------|
| `linear_search.cpp` | Linear Search | Works on any array |
| `binary_search.cpp` | Binary Search | Array must be sorted |

---

## Algorithms

### Linear Search

1. Start.
2. Read the array and the element to be searched.
3. Examine the array from the first index onwards.
4. If the current element matches the key, report its index and stop.
5. If the array ends without a match, report that the element is absent.
6. Stop.

### Binary Search

1. Start.
2. Read the sorted array and the element to be searched.
3. Set `low` to the first index and `high` to the last index.
4. While `low` does not exceed `high`, compute `mid`.
5. If the element at `mid` equals the key, report `mid` and stop.
6. If the element at `mid` is smaller than the key, discard the left half by setting `low = mid + 1`.
7. Otherwise discard the right half by setting `high = mid - 1`.
8. If the loop ends, report that the element is absent.
9. Stop.

---

## Sample Input and Output

### Linear Search
```
Enter the number of elements: 6
Enter 6 elements: 23 45 12 67 89 5
Enter the element to search: 67
Element 67 found at index 3 (position 4).
```

### Binary Search
```
Enter the number of elements: 7
Enter 7 elements in sorted order: 11 22 33 44 55 66 77
Enter the element to search: 44
Element 44 found at index 3 (position 4).
```

### Binary Search, element absent
```
Enter the number of elements: 5
Enter 5 elements in sorted order: 1 3 5 7 9
Enter the element to search: 4
Element 4 is not present in the array.
```

---

## Complexity

| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |

---

## Conclusion

Linear Search needs no preparation and works on unordered data, but it may inspect every element. Binary Search discards half of the remaining range at each step and therefore needs only about log₂n comparisons, though it is valid only when the array is already sorted. For a single search on unsorted data, Linear Search is the practical choice; for repeated searches, sorting once and then using Binary Search is far cheaper overall.
