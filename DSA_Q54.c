#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
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

    struct node* q[100];
    int front = 0, rear = -1;

    q[++rear] = root;

    int leftToRight = 1;

    while (front <= rear) {
        int size = rear - front + 1;
        int temp[100];

        for (int i = 0; i < size; i++) {
            struct node* curr = q[front++];

            int index = leftToRight ? i : (size - 1 - i);
            temp[index] = curr->data;

            if (curr->left) q[++rear] = curr->left;
            if (curr->right) q[++rear] = curr->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", temp[i]);

        leftToRight = !leftToRight;
    }

    return 0;
}
