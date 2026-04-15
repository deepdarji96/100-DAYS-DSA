#include <stdio.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

void push_front(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;
    if (front == -1) front = rear = 0;
    else if (front == 0) front = MAX - 1;
    else front--;
    dq[front] = x;
}

void push_back(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;
    if (front == -1) front = rear = 0;
    else if (rear == MAX - 1) rear = 0;
    else rear++;
    dq[rear] = x;
}

void pop_front() {
    if (front == -1) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[front]);
    if (front == rear) front = rear = -1;
    else if (front == MAX - 1) front = 0;
    else front++;
}

void pop_back() {
    if (front == -1) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[rear]);
    if (front == rear) front = rear = -1;
    else if (rear == 0) rear = MAX - 1;
    else rear--;
}

void get_front() {
    if (front == -1) printf("-1\n");
    else printf("%d\n", dq[front]);
}

void get_back() {
    if (front == -1) printf("-1\n");
    else printf("%d\n", dq[rear]);
}

void is_empty() {
    if (front == -1) printf("1\n");
    else printf("0\n");
}

void get_size() {
    if (front == -1) printf("0\n");
    else if (rear >= front) printf("%d\n", rear - front + 1);
    else printf("%d\n", MAX - front + rear + 1);
}

void clear() {
    front = rear = -1;
}

void display() {
    if (front == -1) {
        printf("-1\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n, x;
    char op[20];
    scanf("%d", &n);

    while (n--) {
        scanf("%s", op);

        if (op[0]=='p' && op[5]=='f') {
            scanf("%d", &x);
            push_front(x);
        }
        else if (op[0]=='p' && op[5]=='b') {
            scanf("%d", &x);
            push_back(x);
        }
        else if (op[0]=='p' && op[4]=='f') pop_front();
        else if (op[0]=='p' && op[4]=='b') pop_back();
        else if (op[0]=='f') get_front();
        else if (op[0]=='b') get_back();
        else if (op[0]=='e') is_empty();
        else if (op[0]=='s') get_size();
        else if (op[0]=='c') clear();
        else if (op[0]=='d') display();
    }
    return 0;
}
