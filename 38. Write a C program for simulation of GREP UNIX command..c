#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <pattern> <filename>\n", argv[0]);
        return 1;
    }
 
    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", argv[2]);
        return 1;
    }
 
    char line[256];
    int lineNo = 0, found = 0;
 
    while (fgets(line, sizeof(line), fp) != NULL) {
        lineNo++;
        if (strstr(line, argv[1]) != NULL) {
            printf("%d: %s", lineNo, line);
            found = 1;
        }
    }
 
    if (!found)
        printf("Pattern \"%s\" not found in file.\n", argv[1]);
 
    fclose(fp);
    return 0;
