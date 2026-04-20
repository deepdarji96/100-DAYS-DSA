#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n) {
            curr->left = newNode(arr[i++]);
            queue[rear++] = curr->left;
        }

        if (i < n) {
            curr->right = newNode(arr[i++]);
            queue[rear++] = curr->right;
        }
    }

    return root;
}

int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int isCBT(struct Node* root, int index, int n) {
    if (root == NULL) return 1;
    if (index >= n) return 0;
    return isCBT(root->left, 2*index+1, n) &&
           isCBT(root->right, 2*index+2, n);
}

int isMinHeap(struct Node* root) {
    if (root->left == NULL && root->right == NULL)
        return 1;

    if (root->right == NULL)
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);

    return (root->data <= root->left->data &&
            root->data <= root->right->data) &&
           isMinHeap(root->left) &&
           isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    int total = countNodes(root);

    if (isCBT(root, 0, total) && isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}
