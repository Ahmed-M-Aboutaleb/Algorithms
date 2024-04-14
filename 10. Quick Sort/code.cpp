#include <bits/stdc++.h>

using namespace std;

vector<int> quickSort(vector<int>& arr, int s, int e) {
    if (e - s + 1 <= 1) {
        return arr;
    }

    int pivot = arr[e];
    int swapLocationPointer = s; // pointer for left side

    // Partition: elements smaller than pivot on the left side.
    for (int iteratorPointer = s; iteratorPointer < e; iteratorPointer++) {
        if (arr[iteratorPointer] < pivot) {
            int tmp = arr[swapLocationPointer];
            arr[swapLocationPointer] = arr[iteratorPointer];
            arr[iteratorPointer] = tmp;
            swapLocationPointer++;
        }
    }
    // Move pivot in-between left & right sides
    arr[e] = arr[swapLocationPointer];
    arr[swapLocationPointer] = pivot;
    
    // Quick sort left side
    quickSort(arr, s, swapLocationPointer - 1);

    // Quick sort right side
    quickSort(arr, swapLocationPointer + 1, e);

    return arr;
}