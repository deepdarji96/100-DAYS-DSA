#include <stdio.h>

int main()
{
    int n, pos;
    int a[50];
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &pos);

    for (i = pos - 1; i < n - 1; i++)
        a[i] = a[i + 1];

    for (i = 0; i < n - 1; i++)
        printf("%d ", a[i]);

    return 0;
}

