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

int length(struct node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct node* l1 = createList(n);

    scanf("%d", &m);
    struct node* l2 = createList(m);

    int len1 = length(l1);
    int len2 = length(l2);

    struct node *p1 = l1, *p2 = l2;

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++) p1 = p1->next;
    } else {
        for (int i = 0; i < diff; i++) p2 = p2->next;
    }

    while (p1 != NULL && p2 != NULL) {
        if (p1->data == p2->data) {
            printf("%d", p1->data);
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection");
    return 0;
}
