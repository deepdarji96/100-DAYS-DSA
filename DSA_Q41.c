#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct node* temp = front;
    printf("%d\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int n, x;
    char op[20];
    scanf("%d", &n);

    while (n--) {
        scanf("%s", op);

        if (op[0] == 'e') {
            scanf("%d", &x);
            enqueue(x);
        }
        else if (op[0] == 'd') {
            dequeue();
        }
    }

    return 0;
}
