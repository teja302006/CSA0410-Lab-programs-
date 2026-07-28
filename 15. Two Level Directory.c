#include <stdio.h>

int main()
{
    char user[10][20], file[10][10][20];
    int users, files;
    int i, j;

    printf("Enter number of users: ");
    scanf("%d", &users);

    for(i = 0; i < users; i++)
    {
        printf("Enter user name: ");
        scanf("%s", user[i]);

        printf("Enter number of files: ");
        scanf("%d", &files);

        for(j = 0; j < files; j++)
        {
            printf("Enter file %d: ", j + 1);
            scanf("%s", file[i][j]);
        }
    }

    printf("\nDirectory Structure\n");

    for(i = 0; i < users; i++)
    {
        printf("\nUser: %s\n", user[i]);

        for(j = 0; file[i][j][0] != '\0'; j++)
            printf("%s\n", file[i][j]);
    }

    return 0;
}
