#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
 
int main() {
    int fd;
    char writeBuf[] = "Hello, this is OS Lab file management demo.\n";
    char readBuf[100];
    ssize_t n;
 
    
    fd = open("demo.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) { perror("open (create)"); return 1; }
    printf("File 'demo.txt' created successfully. fd = %d\n", fd);
 
    
    n = write(fd, writeBuf, strlen(writeBuf));
    printf("write(): %ld bytes written to file.\n", (long)n);
    close(fd);
 
   
    fd = open("demo.txt", O_RDONLY);
    if (fd < 0) { perror("open (read)"); return 1; }
 
    
    n = read(fd, readBuf, sizeof(readBuf) - 1);
    readBuf[n] = '\0';
    printf("read(): %ld bytes read.\nContent: %s", (long)n, readBuf);
    close(fd);
 
    
    fd = open("demo.txt", O_RDONLY);
    lseek(fd, 7, SEEK_SET);
    n = read(fd, readBuf, 20);
    readBuf[n] = '\0';
    printf("lseek() to offset 7, read: %s\n", readBuf);
    close(fd);
 
    
    if (unlink("demo.txt") == 0)
        printf("unlink(): File 'demo.txt' deleted successfully.\n");
    else
        perror("unlink");
 
    return 0;
}
 
