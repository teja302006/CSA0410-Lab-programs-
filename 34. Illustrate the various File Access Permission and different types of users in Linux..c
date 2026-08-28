#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat file;
    char filename[50];

    printf("Enter file name: ");
    scanf("%s", filename);

    if (stat(filename, &file) == -1) {
        printf("File not found!\n");
        return 1;
    }

    printf("\nFile Access Permissions:\n");

    printf("Owner  : ");
    printf("%c%c%c\n",
           (file.st_mode & S_IRUSR) ? 'r' : '-',
           (file.st_mode & S_IWUSR) ? 'w' : '-',
           (file.st_mode & S_IXUSR) ? 'x' : '-');

    printf("Group  : ");
    printf("%c%c%c\n",
           (file.st_mode & S_IRGRP) ? 'r' : '-',
           (file.st_mode & S_IWGRP) ? 'w' : '-',
           (file.st_mode & S_IXGRP) ? 'x' : '-');

    printf("Others : ");
    printf("%c%c%c\n",
           (file.st_mode & S_IROTH) ? 'r' : '-',
           (file.st_mode & S_IWOTH) ? 'w' : '-',
           (file.st_mode & S_IXOTH) ? 'x' : '-');

    printf("\nTypes of Users in Linux:\n");
    printf("1. Owner  - User who owns the file\n");
    printf("2. Group  - Users belonging to the file's group\n");
    printf("3. Others - All other users\n");

    return 0;
}
