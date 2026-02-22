#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int A[100][100];
    int sum = 0;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    int limit = (m < n) ? m : n;

    for(int i = 0; i < limit; i++)
        sum += A[i][i];

    printf("%d", sum);

    return 0;
}
