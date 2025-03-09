# Heap Sort

## Maintaining the heap property

Heap Sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for the remaining elements.

In order to maintain the max-heap property, we call the procedure MAX-HEAPIFY.
Its inputs are an array $A$ and an index $i$ into the array.

When MAX-HEAPIFY is called, it is assumed that the binary trees rooted at LEFT($i$) and RIGHT($i$) are max-heaps, but that $A[i]$ might be smaller than its children, thus violating the max-heap property.

```plaintext
MAX-HEAPIFY(A, i)
    l = LEFT(i)
    r = RIGHT(i)
    if l <= A.heap-size and A[l] > A[i]
        largest = l
    else
        largest = i
    if r <= A.heap-size and A[r] > A[largest]
        largest = r
    if largest != i
        exchange A[i] with A[largest]
        MAX-HEAPIFY(A, largest)
```

## Building a heap

We can use the procedure MAX-HEAPIFY in a bottom-up manner to convert an array $A[1..n]$, where n = A.length, into a max-heap.

the elements in the subarray $A[\lfloor n/2 \rfloor + 1..n]$ are all leaves of the tree, and so each is a 1-element heap to begin with. The procedure BUILD-MAX-HEAP goes through the remaining nodes of the tree and runs MAX-HEAPIFY on each one.

```plaintext
BUILD-MAX-HEAP(A)
    A.heap-size = A.length
    for i = FLOOR(A.length / 2) downto 1
        MAX-HEAPIFY(A, i)
```

## Heap Sort Algorithm

The heapsort algorithm starts by using BUILD-MAX-HEAP to build a max-heap on the input array $A[1..n]$, where $n = A.length$. Since the maximum element of the array is stored at the root $A[1]$, we can put it into its correct final position by exchanging it with $A[n]$. If we now discard node $n$ from the heap, we observe that the children of the root remain max-heaps, but the new root element might violate the max-heap property. All we need to do is call MAX-HEAPIFY on the new root, which leaves a max-heap in $A[1..n-1]$. The heapsort algorithm then repeats this process for the max-heap of size $n-1$ down to a heap of size 2.

```plaintext
HEAPSORT(A)
    BUILD-MAX-HEAP(A)
    for i = A.length downto 2
        exchange A[1] with A[i]
        A.heap-size = A.heap-size - 1
        MAX-HEAPIFY(A, 1)
```

## Complexity Analysis

### Time Complexity

- **Best Case Complexity**: O(n log n)
- **Average Case Complexity**: O(n log n)
- **Worst Case Complexity**: O(n log n)

### Space Complexity

- The space complexity for heap sort is O(1).

## Stability

Heap Sort is not a stable sort, meaning that the relative order of equal sort items is not preserved.

```

```

```

```
