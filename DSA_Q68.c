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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[100];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int indegree[100] = {0};

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        indegree[v]++;
    }

    int queue[100];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        struct Node* temp = adj[v];
        while (temp) {
            indegree[temp->data]--;
            if (indegree[temp->data] == 0) {
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }

    if (count != n)
        printf("\nCycle detected");

    return 0;
}
