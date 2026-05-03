#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    vector<bool> visited(n + 1, false);

    // start DFS from node 1
    dfs(1, adj, visited);

    // check if all nodes are visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NOT CONNECTED";
            return 0;
        }
    }

    cout << "CONNECTED";
    return 0;
}
