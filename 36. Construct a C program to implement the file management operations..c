#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void createFile(char *fname) {
    FILE *fp = fopen(fname, "w");
    if (fp == NULL) { printf("Error creating file\n"); return; }
    printf("File created successfully\n");
    fclose(fp);
}
 
void writeFile(char *fname) {
    FILE *fp = fopen(fname, "w");
    char data[100];
    printf("Enter data to write: ");
    fgets(data, 100, stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data written successfully\n");
}
 
void readFile(char *fname) {
    FILE *fp = fopen(fname, "r");
    char ch;
    if (fp == NULL) { printf("File not found\n"); return; }
    printf("File contents:\n");
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
}
 
void appendFile(char *fname) {
    FILE *fp = fopen(fname, "a");
    char data[100];
    printf("Enter data to append: ");
    fgets(data, 100, stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data appended successfully\n");
}
 
void deleteFile(char *fname) {
    if (remove(fname) == 0)
        printf("File deleted successfully\n");
    else
        printf("Error deleting file\n");
}
 
int main() {
    char fname[50];
    int choice;
    printf("Enter file name: ");
    scanf("%s", fname);
    getchar();
 
    do {
        printf("\n1.Create 2.Write 3.Read 4.Append 5.Delete 6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1: createFile(fname); break;
            case 2: writeFile(fname); break;
            case 3: readFile(fname); break;
            case 4: appendFile(fname); break;
            case 5: deleteFile(fname); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}
