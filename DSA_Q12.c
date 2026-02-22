#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int A[100][100];

    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    
    if(m != n)
    {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(A[i][j] != A[j][i])
            {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix");

    return 0;
}
