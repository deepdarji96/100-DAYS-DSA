#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct pair {
    struct node* node;
    int hd;
};

struct node* newNode(int x) {
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

struct node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct node* nodes[100];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

int main() {
    int n, arr[100];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, n);

    struct pair q[100];
    int front = 0, rear = -1;

    int col[200][100];
    int count[200] = {0};

    int offset = 100;

    q[++rear].node = root;
    q[rear].hd = 0;

    while (front <= rear) {
        struct pair temp = q[front++];

        int index = temp.hd + offset;
        col[index][count[index]++] = temp.node->data;

        if (temp.node->left) {
            q[++rear].node = temp.node->left;
            q[rear].hd = temp.hd - 1;
        }

        if (temp.node->right) {
            q[++rear].node = temp.node->right;
            q[rear].hd = temp.hd + 1;
        }
    }

    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", col[i][j]);
            printf("\n");
        }
    }

    return 0;
}
