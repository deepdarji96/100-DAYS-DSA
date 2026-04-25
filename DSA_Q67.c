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
}

void dfs(struct Node* adj[], int visited[], int stack[], int* top, int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(adj, visited, stack, top, temp->data);
        }
        temp = temp->next;
    }

    stack[++(*top)] = v;
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

    int visited[100] = {0};
    int stack[100];
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(adj, visited, stack, &top, i);
        }
    }

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
