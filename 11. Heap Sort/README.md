# Heap Sort

## What is Heap?

Heap is a special tree structure in which each parent node is less than or equal to its child node. Then it is called a Min Heap. If each parent node is greater than or equal to its child node then it is called a max heap. It is very useful is implementing priority queues where the queue item with higher weightage is given more priority in processing.

## How does Heap Sort work?

Heap Sort Algorithm for sorting in increasing order:

1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of the tree.
3. Repeat step 2 while the size of the heap is greater than 1.

## Algorithm

1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of the tree.
3. Repeat step 2 while the size of the heap is greater than 1.

## Pseudocode

```plaintext

heapSort(arr[], n) {
    // Build heap (rearrange array)
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (i = n - 1; i > 0; i--) {
        // Move current root to end
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
```

## Complexity Analysis

### Time Complexity

-   **Best Case Complexity**: O(n log n)
-   **Average Case Complexity**: O(n log n)
-   **Worst Case Complexity**: O(n log n)

### Space Complexity

-   The space complexity for heap sort is O(1).

## Stability

Heap Sort is not a stable sort, meaning that the relative order of equal sort items is not preserved.
