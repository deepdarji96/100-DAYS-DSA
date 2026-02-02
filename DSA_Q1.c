#include <stdio.h>

int main()
{
    int n, pos, x;
    int a[50];
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &pos);
    scanf("%d", &x);

    for (i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = x;

    for (i = 0; i <= n; i++)
        printf("%d ", a[i]);

    return 0;
}

