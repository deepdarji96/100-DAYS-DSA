#include <stdio.h>
#define MAX 100

int q[MAX], front = 0, rear = -1;
int st[MAX], top = -1;

void enqueue(int x) {
    q[++rear] = x;
}

int dequeue() {
    return q[front++];
}

void push(int x) {
    st[++top] = x;
}

int pop() {
    return st[top--];
}

int main() {
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    while (front <= rear)
        push(dequeue());

    front = 0;
    rear = -1;

    while (top != -1)
        enqueue(pop());

    for (int i = front; i <= rear; i++)
        printf("%d ", q[i]);

    return 0;
}
