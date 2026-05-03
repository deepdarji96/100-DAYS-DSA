#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1]; 
    // {neighbor, weight}

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    vector<bool> visited(n + 1, false);

    // {weight, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 1}); // start from node 1
    int totalWeight = 0;

    while (!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;

        visited[node] = true;
        totalWeight += wt;

        for (auto [neighbor, weight] : adj[node]) {
            if (!visited[neighbor]) {
                pq.push({weight, neighbor});
            }
        }
    }

    cout << totalWeight << endl;

    return 0;
}
