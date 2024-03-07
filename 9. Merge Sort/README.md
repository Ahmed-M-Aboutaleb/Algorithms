# Merge Sort

## What is merge sort?

Merge sort is a sorting algorithm that sorts an array by dividing it into two almost equal halves, sorting the two halves, and then merging them back together. It is a divide and conquer algorithm.

## How does merge sort work?

1. Divide: Divide the n-element sequence to be sorted into two subsequences of n/2 elements each
2. Conquer: Sort the two subsequences recursively using merge sort
3. Combine: Merge the two sorted subsequences to produce the sorted answer

## Algorithm

1. If the array has only one element, return
2. Divide the array into two halves
3. Recursively sort the two halves
4. Merge the two halves

![insertion_sort_gif](https://github.com/Ahmed-M-Aboutaleb/Algorithms/blob/main/9.%20Merge%20Sort/images/Merge-sort.gif?raw=true)

## Pseudocode

```plaintext
mergeSort(arr[], s, e) {
    if(e - s + 1 <= 1) {
        return arr;
    }

    mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);

    return arr;
}
```

```plaintext
merge(arr[], s, mid, e) {
    n1 = mid - s + 1;
    n2 = e - mid;

    left[n1], right[n2];

    for(i = 0; i < n1; i++) {
        left[i] = arr[s + i];
    }

    for(i = 0; i < n2; i++) {
        right[i] = arr[mid + 1 + i];
    }

    i = 0, j = 0, k = s;

    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
```

## Complexity

-   Time complexity: O(n log n)
-   Space complexity: O(n)

## Stability

Merge sort is a stable sort, meaning that it preserves the relative order of equal elements.
