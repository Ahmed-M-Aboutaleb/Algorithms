# Quick Sort

## What is Quick Sort?

Quick Sort is a divide-and-conquer algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively. This can be done in-place, requiring small additional amounts of memory to perform the sorting.

## How does Quick Sort work?

1. Pick an element, called a pivot, from the array.
2. Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
3. Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.

## Algorithm

1. If the array has only one element, return

2. Choose a pivot element from the array

3. Partition the array around the pivot

4. Create two pointers the Swap Location Pointer and the Iterator Pointer.

5. Starting iterating on the array and check if element greater than the pivot if true then increment the iterator pointer else we swap the the element of iterator pointer with the element of swap location pointer and increment swap location pointer by 1.

6. After step 4 we swap pivot value with element of swap location pointer to get array which is NOT sorted but all values on the left of pivot are less than or equal it and values at right greater than it.

7. Recursively call the quick sort function on the left and right side of the pivot.

![insertion_sort_gif](https://github.com/Ahmed-M-Aboutaleb/Algorithms/blob/main/10.%Quick%20Sort/images/Quick-sort.gif?raw=true)

## Pseudocode

```plaintext

quickSort(arr[], s, e) {
    if(e - s + 1 <= 1) {
        return arr;
    }

    pivot = arr[e];
    swapLocation = s;

    for(i = s; i < e; i++) {
        if(arr[i] < pivot) {
            temp = arr[swapLocation];
            arr[swapLocation] = arr[i];
            arr[i] = temp;
            swapLocation++;
        }
    }
    arr[e] = arr[swapLocation];
    arr[swapLocation] = pivot;

    quickSort(arr, s, swapLocation - 1);
    quickSort(arr, swapLocation + 1, e);

    return arr;
}
```

### Time Complexity

-   Best Case: O(n log n)
-   Average Case: O(n log n)
-   Worst Case: O(n^2)

### Space Complexity

-   Worst Case: O(log(n))

## Stability

Quick Sort is not a stable sort, meaning that the relative order of equal sort items is not preserved.

## In-Place

Quick Sort is an in-place sort, meaning that it does not require any additional space.

## Adaptivity

Quick Sort is not an adaptive sort, meaning that it does not take advantage of existing order in the input array.

## Applications

-   Quick Sort is used in the Unix `sort` command.
-   Quick Sort is used in the C library function `qsort`.
-   Quick Sort is used in the Java library function `Arrays.sort`.
-   Quick Sort is used in the Python library function `sort`.

## Some important points

-   Quick Sort is faster than Merge Sort.
-   Number of passes: log<sub>2</sub>n
-   Number of comparisons: O(n log n)
-   Number of swaps: O(n log n)
