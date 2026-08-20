#include <stdio.h>
 
int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = 5, n = 4;
    int allocation[4];
    int blockCopy[5];
 
    for (int i = 0; i < m; i++) blockCopy[i] = blockSize[i];
    for (int i = 0; i < n; i++) allocation[i] = -1;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockCopy[j] >= processSize[i]) {
                allocation[i] = j;
                blockCopy[j] -= processSize[i];
                break;
            }
        }
    }
 
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}
 
