# Heap

## What is a Heap?

A heap/priority queue is a complete binary tree that satisfies the heap property. The heap property states that for every node `i` in the heap, the value of `i` is greater than or equal to the value of its parent, with the minimum value at the root.

## Types of Heaps

There are two types of heaps:

1. **Max Heap**: In a max heap, the value of the root node is greater than or equal to the values of its children.
2. **Min Heap**: In a min heap, the value of the root node is less than or equal to the values of its children.

## Structure of a Heap

A heap is a complete binary tree, which means that all levels of the tree are fully filled except possibly for the last level, which is filled from left to right.

For example, the following is a max heap:

```
        10
       /  \
      9    8
     / \  / \
    7  6 5   4
```

We can represent a heap using an array. The root node is at index 1, and for any node `i`, the left child is at index `2*i`, and the right child is at index `2*i + 1`.

For example, the above heap can be represented as:

```
[null, 10, 9, 8, 7, 6, 5, 4]
```

> **Note**: We can get the parent of a node `i` by dividing `i` by 2 and taking the floor of the result.

## Push Operation

The push operation is used to insert an element into the heap. The element is inserted at the end of the heap and then moved up to its correct position to maintain the heap property.

### Algorithm

1. Insert the element at the end of the heap.
2. Compare the inserted element with its parent.
3. If the inserted element is greater than its parent, swap the element with its parent.
4. Repeat steps 2 and 3 until the element is at its correct position.

### Pseudocode

```plaintext
push(heap[], value) {
    heap.push(value);
    i = heap.length - 1;
    while (i > 1 && heap[i] > heap[i / 2]) {
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}
```

## Pop Operation

The pop operation is used to remove the root element from the heap. The last element of the heap is moved to the root, and then the element is moved down to its correct position to maintain the heap property.

### Algorithm

1. Replace the root element with the last element of the heap.
2. Compare the root element with its children.
3. If the root element is less than any of its children, swap the root element with the larger child.
4. Repeat steps 2 and 3 until the element is at its correct position.

### Pseudocode

```plaintext
pop(heap[]) {
    root = heap[1];
    heap[1] = heap[heap.length - 1];
    heap.pop();
    i = 1;
    while (2 * i < heap.length) {
        j = 2 * i;
        if (j + 1 < heap.length && heap[j + 1] > heap[j]) {
            j = j + 1;
        }
        if (heap[i] < heap[j]) {
            swap(heap[i], heap[j]);
            i = j;
        } else {
            break;
        }
    }
    return root;
}
```

## Complexity Analysis

The time complexity of the push operation is O(log n), where n is the number of elements in the heap. The time complexity of the pop operation is also O(log n).

The space complexity of the heap is O(n), where n is the number of elements in the heap.

## Applications of Heaps

Heaps are used in various algorithms and data structures, such as:

-   Priority Queues
-   Heap Sort
-   Dijkstra's Algorithm
-   Prim's Algorithm
