# Graph Theory

## What is a Graph?

A graph is a data structure that consists of the following two components Nodes (Vertices, Points) and Edges (Linkes, Arcs).

Graphs are used to solve many real-life problems. Graphs are used to represent networks. The networks may include paths in a city or telephone network or circuit network. Graphs are also used in social networks like linkedIn, Facebook. For example, in Facebook, each person is represented with a vertex (or node). Each node is a structure and contains information like person id, name

We can donate the graph as G where G = (V, E).

If the edge pair is ordered, the graph is called a directed graph (digraph). If the edge pair is unordered, it is an undirected graph.\

-   Vertix w is said to be adjacent to vertex v if there is an edge between w and v.

-   The degree of a vertex is the number of edges connected to it.

-   Degree = In-degree + Out-degree

-   The simple path is a path that does not have a repeated vertex.

-   The cycle is a path that starts and ends at the same vertex.

-   Simple cycle is a cycle that does not have a repeated edge.

-   Isolated vertex is a vertex that has degree 0.

-   Cut vertex is a vertex that when removed makes the graph disconnected.

-   Connectivity in a graph is the minimum number of vertices/edges that need to be removed to make the graph disconnected.

## Types of Graphs

### Directed Graphs

1. DAG (Directed Acyclic Graph): A directed graph that contains no cycles.

2. Trees: A connected graph with no cycles.

### Undirected Graphs

1. Connected Graph: A graph in which each pair of vertices is connected by a unique path.

2. Complete Graph: A graph in which each pair of vertices is connected by a unique edge.

3. Biconnected Graph: A connected graph that remains connected even after any vertex is removed.

## Complete Graph

A complete graph is a graph in which each pair of graph vertices is connected by an edge. A complete digraph is a directed graph in which each pair of distinct vertices is connected by a pair of unique edges (one in each direction).

### Properties

-   A complete graph with n vertices contains n(n-1)/2 edges.

## Bipartite Graph

A bipartite graph is a graph whose vertices can be divided into two independent sets, U and V, such that every edge connects a vertex in U to one in V.

### Properties

-   A bipartite graph does not contain any odd-length cycles.
-   The maximum number of edges of a bipartite graph having n vertices is $$n^2/4$$.

## Regular Graph

A regular graph is a graph in which each vertex has the same number of neighbors.

### Properties

-   A regular graph of degree k is a graph in which each vertex has degree k.

## Simple Graph

A simple graph is an undirected graph that does not contain loops or multiple edges.

## Graph Representation

There are two ways to represent a graph:

1.  **Adjacency Matrix**: A two-dimensional matrix, in which the rows represent source vertices and columns represent destination vertices. Data on edges and vertices must be stored externally. Only the cost for one edge can be stored between each pair of vertices.

2.  **Adjacency List**: Vertices are stored as records or objects, and every vertex stores a list of adjacent vertices. This data structure allows the storage of additional data on the vertices. Additional data can be stored if edges are stored as objects, in which case each vertex stores its incident edges and each edge stores its incident vertices.

### Adjacency List

An adjacency list represents a graph as an array of linked lists.

The index of the array represents a vertex and each element in its linked list represents the other vertices that form an edge with the vertex.

V = {0, 1, 2, 3, 4}
E = {(0, 1), (0, 4), (1, 0), (1, 2), (1, 3), (1, 4), (2, 1), (2, 3), (3, 1), (3, 2), (3, 4), (4, 0), (4, 1), (4, 3)}

```plaintext
0 -> 1 -> 4
1 -> 0 -> 2 -> 3 -> 4
2 -> 1 -> 3
3 -> 1 -> 2 -> 4
4 -> 0 -> 1 -> 3
```

For a weighted graph, we can store the weight of the edges in the linked list nodes.

### Complexity Analysis

For a directed graph G = (V, E), where V is the number of vertices and E is the number of edges:
Total storage: Θ(V+E)

For an undirected graph, the storage is Θ(V+2E) = Θ(V+E)

### Pros and Cons

#### Pros

-   Space-efficient for representing sparse graphs.
-   Can be modified to support many graph variants.

#### Cons

-   Determining whether an edge exists between two vertices is not as efficient as when using an adjacency matrix.

### Adjacency Matrix

An adjacency matrix is a 2D array of V x V vertices.

Each row and column represent a vertex.

If the value of any element a[i][j] is 1, it represents that there is an edge connecting vertex i and vertex j.

V = {0, 1, 2, 3, 4}
E = {(0, 1), (0, 4), (1, 0), (1, 2), (1, 3), (1, 4), (2, 1), (2, 3), (3, 1), (3, 2), (3, 4), (4, 0), (4, 1), (4, 3)}

```plaintext
    0 1 2 3 4
   -----------
0 | 0 1 0 0 1
1 | 1 0 1 1 1
2 | 0 1 0 1 0
3 | 0 1 1 0 1
4 | 1 1 0 1 0
```

For a weighted graph, we can store the weight of the edges in the matrix instead of 0 and 1.

### Complexity Analysis

For a graph G = (V, E), where V is the number of vertices and E is the number of edges:
Total storage: Θ(V^2)
Time to list all vertices adjacent to a vertex v: Θ(V)
Time to determine whether an edge (u, v) exists: Θ(1)

### Pros and Cons

#### Pros

-   Edge weight lookup is O(1).

#### Cons

-   Requires Θ(V^2) space, even for sparse graphs.

## Graph Traversal

Graph traversal is the process of visiting all the vertices of a graph in a systematic way.

There are two standard methods to traverse a graph:

1.  **Breadth First Search (BFS)**: It is a graph traversal algorithm that starts traversing the graph from the root node and explores all the neighbouring nodes. Then, it selects the nearest node and explores all the unexplored nodes. The algorithm follows the same process for each of the nearest nodes until it finds the goal.

2.  **Depth First Search (DFS)**: It is a graph traversal algorithm that traverses the graph in a depthward motion and uses a stack to remember to get the next vertex to start a search when a dead end occurs in any iteration.

### Breadth First Search (BFS)

BFS is a traversing algorithm where you should start traversing from a selected node (source or starting node) and traverse the graph layerwise thus exploring the neighbour nodes (nodes which are directly connected to source node). You must then move towards the next-level neighbour nodes.

```plaintext

BFS (G, s)                   //Where G is the graph and s is the source node
      let Q be queue.
      Q.enqueue( s ) //Inserting s in queue until all its neighbour vertices are marked.

      mark s as visited.
      while ( Q is not empty)
           //Removing that vertex from queue, whose neighbour will be visited now
           v  =  Q.dequeue( )

          //processing all the neighbours of v
          for all neighbours w of v in Graph G
               if w is not visited
                        Q.enqueue( w )             //Stores w in Q to further visit its neighbour
                        mark w as visited.
```

### Complexity Analysis

For a graph G = (V, E), where V is the number of vertices and E is the number of edges:
Time complexity: O(V+E)
Space complexity: O(V)

### Applications

-   Shortest path in an unweighted graph.

### Depth First Search (DFS)

DFS is a traversing algorithm where you should start traversing from a selected node (source or starting node) and move as far as possible in the same branch, and then backtracks until you find the other branch to explore.

```plaintext
DFS (G, u)
      u.visited = true
      for each v in G.Adj[u]
           if v.visited == false
               DFS(G, v)
```

### Complexity Analysis

For a graph G = (V, E), where V is the number of vertices and E is the number of edges:

Time complexity: O(V+E)
Space complexity: O(V)

### Applications

-   Topological sorting.
-   Finding connected components.
-   Solving puzzles with only one solution, such as mazes.
