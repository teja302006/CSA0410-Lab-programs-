
#include <stdio.h>

#define MAX_BLOCKS 20

int main() {
    int disk[MAX_BLOCKS];
    for (int i = 0; i < MAX_BLOCKS; i++)
        disk[i] = 0;

    int indexBlock;
    int numBlocks;

    printf("Enter index block number: ");
    scanf("%d", &indexBlock);
    disk[indexBlock] = 1;

    printf("Enter number of data blocks for the file: ");
    scanf("%d", &numBlocks);

    int fileBlocks[numBlocks];
    printf("Enter %d block numbers (not necessarily contiguous):\n", numBlocks);
    for (int i = 0; i < numBlocks; i++) {
        scanf("%d", &fileBlocks[i]);
        disk[fileBlocks[i]] = 1;
    }

    printf("\nIndexed Allocation Table\n");
    printf("Index Block: %d\n", indexBlock);
    printf("Entry\tBlock No.\n");
    for (int i = 0; i < numBlocks; i++)
        printf("%d\t%d\n", i, fileBlocks[i]);

    printf("\nTo access the i-th block of the file, the system reads\n");
    printf("entry i of the index block, which directly points to it.\n");

    return 0;
}
