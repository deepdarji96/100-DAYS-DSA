#include <stdio.h>
#include <string.h>

void reverse(char str[], int n) {
    if(n < 0)
        return;
    printf("%c", str[n]);
    reverse(str, n - 1);
}

int main() {
    char str[100];
    scanf("%s", str);

    int n = strlen(str);
    reverse(str, n - 1);

    return 0;
}

