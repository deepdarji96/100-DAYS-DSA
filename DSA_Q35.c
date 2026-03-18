#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

int main() {
    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        rear++;
        queue[rear] = x;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
