# Insertion Sorting

## Introduction

### What is Sorting?

Sorting is the process of arranging the elements of an array in a particular order. For example, if we want to arrange the elements of an array in ascending order, then we arrange them from the smallest to the largest. Similarly, if we want to arrange the elements of an array in descending order, then we arrange them from the largest to the smallest.

### What is Insertion Sort?

Insertion Sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. However, insertion sort provides several advantages:

-   Simple implementation
-   Efficient for (quite) small data sets
-   More efficient in practice than most other simple quadratic (i.e., O(n^2)) algorithms such as selection sort or bubble sort

### How does Insertion Sort work?

It's idea to break the problem into sub-problems. We start with the assumption that a list with one element (position 0) is already sorted.
Then our second sub-problem is to sort first two elements. We keep adding one element at a time to the sorted list and keep the list sorted at all times.
Using the iterative approach, we start at the second element and compare it with the first element. If the second element is smaller than the first element, we swap them. Then we move to the third element and compare it with the second element and using the two pointers technique, we keep moving the smaller element to the left. We keep doing this until the list is sorted.

![insertion_sort_gif](https://github.com/Ahmed-M-Aboutaleb/Algorithms/blob/main/5.%20Insertion%20Sort/images/insertion-sort.gif?raw=true)

## Pseudocode

```plaintext

for(i = 1 to n-1){
    j = i - 1
    while(j >= 0 and arr[j+1] < arr[j]){
        temp = arr[j+1]
        arr[j+1] = arr[j]
        arr[j] = temp
        j -= 1
    }
}

```

## Complexity

### Time Complexity

-   Best Case: O(n)
-   Average Case: O(n^2)
-   Worst Case: O(n^2)

### Space Complexity

-   O(1)

### Stability

-   The insertion sort is stable, i.e., it does not change the relative order of elements with equal keys.

### In-Place

-   It is an in-place sorting algorithm as it requires a constant amount of extra space.

### Adaptivity

-   It is adaptive, i.e., it reduces its time complexity if the input array is partially sorted.

## Applications

-   Insertion sort is used when the number of elements is small.
-   It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.

## Some important points

-   Number of passes: n-1
-   Number of comparisons: $n^2/2$
-   Number of swaps: $n^2/2$
-   Number of inversions: $n(n-1)/2$
-   Number of average inversions: $n(n-1)/4$
