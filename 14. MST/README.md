# Spanning Tree

## What is a Spanning Tree?

A spanning tree of a graph is a subgraph that is a tree and connects all the vertices together.

## Properties of a Spanning Tree

-   A spanning tree can not have a cycle.
-   A spanning tree must be connected.

## Minimum Spanning Tree

A minimum spanning tree (MST) of a graph is a spanning tree that has the smallest possible sum of edge weights.

## Algorithms for finding Minimum Spanning Tree

-   Kruskal's Algorithm
-   Prim's Algorithm

## Applications of Minimum Spanning Tree

-   Electrical wiring
-   Computer network design
-   Transportation network design

## Properties of Minimum Spanning Tree

-   A graph can have multiple minimum spanning trees.
-   If all the edge weights are distinct, then the minimum spanning tree is unique.
-   The number of edges in a minimum spanning tree is equal to the number of vertices minus one.

## Prim's Algorithm

Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.

### How does Prim's Algorithm work?

1.  Create a set `mstHashSet` that keeps track of vertices included in the minimum spanning tree.
2.  Create a heap `minHeap` that stores the vertices not yet included in the minimum spanning tree.
3.  Assign a key value to all vertices in the input graph. Initialize all key values as `INFINITY` except the first vertex, which is assigned a key value of `0`.
4.  While `minHeap` is not empty, do the following:
    -   Extract the vertex with the minimum key value from `minHeap`. Let's call this vertex `u`.
    -   Include `u` in `mstHashSet`.
    -   Update the key value of all adjacent vertices of `u` if they are not in `mstHashSet`. The new key value is the minimum of the current key value and the weight of the edge connecting `u` and the adjacent vertex.
5.  The set `mstHashSet` will contain the vertices of the minimum spanning tree.

### Pseudocode

```plaintext

primMST(graph) {
    mstHashSet = new HashSet();
    minHeap = new Heap();

    for (vertex in graph.vertices) {
        vertex.key = INFINITY;
        minHeap.insert(vertex);
    }

    graph.vertices[0].key = 0;

    while (minHeap.size() > 0) {
        u = minHeap.extractMin();
        mstHashSet.add(u);

        for (v in u.adjacentVertices) {
            if (v not in mstHashSet and u.weight + edgeWeight(u, v) < v.key) {
                v.key = u.weight + edgeWeight(u, v);
                minHeap.decreaseKey(v);
            }
        }
    }

    return mstHashSet;
}
```

### Complexity Analysis

#### Time Complexity

-   The time complexity of Prim's algorithm is O(V^2) using an adjacency matrix and O(E log V) using an adjacency list, where V is the number of vertices and E is the number of edges in the graph.

#### Space Complexity

-   The space complexity of Prim's algorithm is O(V), where V is the number of vertices in the graph.

### Stability

Prim's algorithm is a stable algorithm, meaning that the relative order of equal weight items is preserved.

## Kruskal's Algorithm

Kruskal's algorithm is a greedy algorithm that finds a minimum spanning tree for a connected weighted graph.

### How does Kruskal's Algorithm work?

1.  Sort all the edges in non-decreasing order of their weight.
2.  Pick the smallest edge. Check if including this edge in the minimum spanning tree will create a cycle. If not, include the edge in the minimum spanning tree.
3.  Repeat step 2 until there are V-1 edges in the minimum spanning tree, where V is the number of vertices in the graph.

### Pseudocode

```plaintext

kruskalMST(graph) {
    mstHashSet = new HashSet();
    minHeap = new Heap();

    for (vertex in graph.vertices) {
        makeSet(vertex);
    }

    sort(graph.edges);

    for (edge in graph.edges) {
        if (findSet(edge.source) != findSet(edge.destination)) {
            mstHashSet.add(edge);
            union(edge.source, edge.destination);
        }
    }

    return mstHashSet;
}
```

### Complexity Analysis

#### Time Complexity

-   The time complexity of Kruskal's algorithm is O(E log E), where E is the number of edges in the graph.

#### Space Complexity

-   The space complexity of Kruskal's algorithm is O(V), where V is the number of vertices in the graph.

### Stability

Kruskal's algorithm is a stable algorithm, meaning that the relative order of equal weight items is preserved.
