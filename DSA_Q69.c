#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->v = v;
    temp->w = w;
    temp->next = NULL;
    return temp;
}

void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* temp = createNode(v, w);
    temp->next = adj[u];
    adj[u] = temp;
}

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(struct Node* adj[], int n, int src) {
    int dist[100];
    int visited[100] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break;

        visited[u] = 1;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }

            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[100];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w); // remove for directed
    }

    int src;
    scanf("%d", &src);

    dijkstra(adj, n, src);

    return 0;
}
