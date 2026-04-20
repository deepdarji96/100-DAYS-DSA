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

int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct Node* build(int inorder[], int postorder[], int* postIndex, int start, int end) {
    if (start > end) return NULL;

    struct Node* root = newNode(postorder[*postIndex]);
    (*postIndex)--;

    int inIndex = findIndex(inorder, start, end, root->data);

    root->right = build(inorder, postorder, postIndex, inIndex + 1, end);
    root->left = build(inorder, postorder, postIndex, start, inIndex - 1);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[1000], postorder[1000];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = build(inorder, postorder, &postIndex, 0, n - 1);

    preorder(root);

    return 0;
}
