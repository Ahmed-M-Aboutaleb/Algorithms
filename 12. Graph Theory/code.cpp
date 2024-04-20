#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 100;

vector<vector<int>> adjacency_matrix(MAX_NODES, vector<int>(MAX_NODES, 0));
vector<bool> visited(MAX_NODES, false);

void dfs(int node, int n) {
    cout << node << " "; // Process the current node
    visited[node] = true;

    // Visit all neighbors of the current node
    for (int i = 0; i < n; i++) {
        if (adjacency_matrix[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

void bfs(int start, int n) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < n; i++)
        {
            if(adjacency_matrix[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
        
    }
    
}