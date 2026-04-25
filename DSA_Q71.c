#include <stdio.h>

#define SIZE 100

int table[SIZE];

void init(int m) {
    for (int i = 0; i < m; i++)
        table[i] = -1;
}

int hash(int key, int m) {
    return key % m;
}

void insert(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i*i) % m;

        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
    }
}

void search(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i*i) % m;

        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[idx] == -1) {
            printf("NOT FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    init(m);

    for (int i = 0; i < q; i++) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (op[0] == 'I')
            insert(key, m);
        else if (op[0] == 'S')
            search(key, m);
    }

    return 0;
}
