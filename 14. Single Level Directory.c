#include <stdio.h>

int main()
{
    char file[20][30];
    int n, i;

    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("Enter file names:\n");

    for(i = 0; i < n; i++)
        scanf("%s", file[i]);

    printf("\nFiles in Single Level Directory:\n");

    for(i = 0; i < n; i++)
        printf("%s\n", file[i]);

    return 0;
}
