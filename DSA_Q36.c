#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int x) {
    if (size == MAX) {
        return;
    }
    pq[size++] = x;
}

// Find index of smallest element
int getMinIndex() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete (remove smallest)
void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = getMinIndex();
    printf("%d\n", pq[minIndex]);

    // Shift elements left
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Peek (show smallest)
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = getMinIndex();
    printf("%d\n", pq[minIndex]);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'i') {   // insert
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') {  // delete
            delete();
        }
        else if (op[0] == 'p') {  // peek
            peek();
        }
    }

    return 0;
}
