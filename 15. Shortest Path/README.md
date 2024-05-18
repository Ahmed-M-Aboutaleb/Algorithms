# Dijkstra's Algorithm

## What is Dijkstra's Algorithm?

Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph. It was conceived by computer scientist Edsger W. Dijkstra in 1956 and published three years later.

The algorithm exists in many variants; Dijkstra's original variant found the shortest path between two nodes, but a more common variant fixes a single node as the "source" node and finds shortest paths from the source to all other nodes in the graph, producing a shortest-path tree.

## How does Dijkstra's Algorithm work?

The algorithm works by keeping track of the shortest distance from the source node to every other node in the graph. It does this by maintaining a priority queue of nodes that are yet to be visited. The algorithm then iterates over the nodes in the priority queue, visiting the node with the smallest distance from the source node first. It then updates the distances of all the nodes that are connected to the current node, if the new distance is smaller than the previous distance. This process is repeated until all the nodes in the graph have been visited.

## Pseudocode

```plaintext

dijkstra(graph, source) {
    distance[source] = 0;
    priorityQueue = new PriorityQueue();

    for (vertex in graph.vertices) {
        if (vertex != source) {
            distance[vertex] = INFINITY;
        }
        priorityQueue.insert(vertex, distance[vertex]);
    }

    while (priorityQueue is not empty) {
        currentVertex = priorityQueue.extractMin();

        for (neighbor in currentVertex.neighbors) {
            newDistance = distance[currentVertex] + edgeWeight(currentVertex, neighbor);

            if (newDistance < distance[neighbor]) {
                distance[neighbor] = newDistance;
                priorityQueue.decreaseKey(neighbor, newDistance);
            }
        }
    }
}
```

## Time Complexity

-   The time complexity of Dijkstra's algorithm is O(V^2) using an adjacency matrix and O(E log V) using an adjacency list, where V is the number of vertices and E is the number of edges in the graph.

## Space Complexity

-   The space complexity of Dijkstra's algorithm is O(V), where V is the number of vertices in the graph.

## Stability

-   Dijkstra's algorithm is stable, meaning that it will always produce the same output for the same input.

## Applications

Dijkstra's algorithm is used in many applications, including:

-   Finding the shortest path between two nodes in a graph.
