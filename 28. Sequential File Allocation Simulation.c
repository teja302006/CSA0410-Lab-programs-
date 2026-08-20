
#include <stdio.h>

#define MAX_BLOCKS 20

int disk[MAX_BLOCKS];

void initDisk() {
    for (int i = 0; i < MAX_BLOCKS; i++)
        disk[i] = 0; 
}

int main() {
    initDisk();

    int startBlock, numBlocks;
    printf("Enter starting block number: ");
    scanf("%d", &startBlock);
    printf("Enter number of blocks required: ");
    scanf("%d", &numBlocks);

    if (startBlock + numBlocks > MAX_BLOCKS) {
        printf("Not enough space on disk.\n");
        return 0;
    }

    int canAllocate = 1;
    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        if (disk[i] == 1) {
            canAllocate = 0;
            break;
        }
    }

    if (!canAllocate) {
        printf("Blocks not free, allocation failed.\n");
        return 0;
    }

    for (int i = startBlock; i < startBlock + numBlocks; i++)
        disk[i] = 1;

    printf("\nFile allocated (Sequential Allocation)\n");
    printf("Start Block: %d\n", startBlock);
    printf("Length: %d blocks\n", numBlocks);
    printf("Blocks occupied: ");
    for (int i = startBlock; i < startBlock + numBlocks; i++)
        printf("%d ", i);
    printf("\n\nNote: Records are accessed sequentially - to read the\n");
    printf("k-th record, all previous (k-1) records must be read first.\n");

    return 0;
}
