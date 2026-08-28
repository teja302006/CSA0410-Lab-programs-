#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
 
int main() {
    int fd, fd2;
    struct stat st;
    DIR *dir;
    struct dirent *entry;
    char buffer[100] = "Hello, UNIX System Calls!";
 
    
    fd = open("testfile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    write(fd, buffer, strlen(buffer));

    fd2 = fcntl(fd, F_DUPFD, 0);
    printf("Original fd = %d, Duplicated fd (fcntl) = %d\n", fd, fd2);
    close(fd2);
 
    
    lseek(fd, 7, SEEK_SET);
    write(fd, "MODIFIED", 8);
    close(fd);
 
    stat("testfile.txt", &st);
    printf("\nFile Information (stat):\n");
    printf("File Size: %ld bytes\n", (long)st.st_size);
    printf("File Inode: %ld\n", (long)st.st_ino);
    printf("Permissions: %o\n", st.st_mode & 0777);
  
    printf("\nDirectory Listing (opendir/readdir):\n");
    dir = opendir(".");
    if (dir) {
        while ((entry = readdir(dir)) != NULL)
            printf("%s\n", entry->d_name);
        closedir(dir);
    }
    return 0;
}
