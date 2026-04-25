#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = v;
    temp->next = NULL;
    return temp;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* temp = createNode(v);
    temp->next = adj[u];
    adj[u] = temp;

    temp = createNode(u);
    temp->next = adj[v];
    adj[v] = temp;
}

void dfs(struct Node* adj[], int visited[], int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(adj, visited, temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[100];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int s;
    scanf("%d", &s);

    int visited[100] = {0};

    dfs(adj, visited, s);

    return 0;
}
