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

int dfs(struct Node* adj[], int visited[], int recStack[], int v) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->data;

        if (!visited[u]) {
            if (dfs(adj, visited, recStack, u))
                return 1;
        }
        else if (recStack[u]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[v] = 0;
    return 0;
}

int hasCycle(struct Node* adj[], int n) {
    int visited[100] = {0};
    int recStack[100] = {0};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, visited, recStack, i))
                return 1;
        }
    }

    return 0;
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

    if (hasCycle(adj, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}
