#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

struct node* merge(struct node* l1, struct node* l2) {
    struct node *head = NULL, *temp = NULL;

    while (l1 != NULL && l2 != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));

        if (l1->data < l2->data) {
            newNode->data = l1->data;
            l1 = l1->next;
        } else {
            newNode->data = l2->data;
            l2 = l2->next;
        }
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    while (l1 != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = l1->data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;
        l1 = l1->next;
    }

    while (l2 != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = l2->data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;
        l2 = l2->next;
    }

    return head;
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct node* l1 = createList(n);

    scanf("%d", &m);
    struct node* l2 = createList(m);

    struct node* result = merge(l1, l2);

    printList(result);

    return 0;
}
