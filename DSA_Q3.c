#include <stdio.h>

int main()
{
    int n, k;
    int a[50];
    int i;
    int count = 0;
    int found = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &k);

    for (i = 0; i < n; i++)
    {
        count++;

        if (a[i] == k)
        {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Not Found\n");

    printf("Comparisons = %d", count);

    return 0;
}

