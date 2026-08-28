#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
 
int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char *path = (argc > 1) ? argv[1] : ".";
 
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir failed");
        return 1;
    }
 
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.')
            continue;
        char fullpath[256];
        sprintf(fullpath, "%s/%s", path, entry->d_name);
        if (stat(fullpath, &st) == 0) {
            printf("%s\t", (S_ISDIR(st.st_mode)) ? "DIR " : "FILE");
            printf("%6ld bytes\t", (long)st.st_size);
            printf("%s\n", entry->d_name);
        }
    }
    closedir(dir);
    return 0;
}
