#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// find index in inorder
int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// build tree
struct Node* build(int preorder[], int inorder[], int* preIndex, int start, int end) {
    if (start > end) return NULL;

    struct Node* root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    int inIndex = findIndex(inorder, start, end, root->data);

    root->left = build(preorder, inorder, preIndex, start, inIndex - 1);
    root->right = build(preorder, inorder, preIndex, inIndex + 1, end);

    return root;
}

// postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[1000], inorder[1000];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = build(preorder, inorder, &preIndex, 0, n - 1);

    postorder(root);

    return 0;
}
