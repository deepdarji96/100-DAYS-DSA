#include <stdio.h>

int main()
{
    int n;
    int a[100];
    int i, temp;
    int left, right;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    left = 0;
    right = n - 1;

    while (left < right)
    {
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;

        left++;
        right--;
    }

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}


