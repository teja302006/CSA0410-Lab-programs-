#include <stdio.h>

#define P 5   
#define R 3   

int available[R];
int maximum[P][R];
int allocation[P][R];
int need[P][R];

void calculateNeed() {
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
}

int isSafe() {
    int work[R];
    int finish[P] = {0};
    int safeSeq[P];

    for (int j = 0; j < R; j++)
        work[j] = available[j];

    int count = 0;
    while (count < P) {
        int found = 0;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < R; j++) {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += allocation[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is NOT in a safe state.\n");
            return 0;
        }
    }

    printf("System is in a SAFE state.\nSafe sequence: ");
    for (int i = 0; i < P; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");
    return 1;
}

int requestResources(int processNum, int request[]) {
    int i;
    for (i = 0; i < R; i++) {
        if (request[i] > need[processNum][i]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            return 0;
        }
    }

    for (i = 0; i < R; i++) {
        if (request[i] > available[i]) {
            printf("Resources not available, process must wait.\n");
            return 0;
        }
    }

    for (i = 0; i < R; i++) {
        available[i] -= request[i];
        allocation[processNum][i] += request[i];
        need[processNum][i] -= request[i];
    }

    if (isSafe()) {
        printf("Request granted.\n");
        return 1;
    } else {
        for (i = 0; i < R; i++) {
            available[i] += request[i];
            allocation[processNum][i] -= request[i];
            need[processNum][i] += request[i];
        }
        printf("Request denied, rolled back.\n");
        return 0;
    }
}

int main() {
    int i, j;

    int alloc[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int avail[R] = {3, 3, 2};

    for (i = 0; i < P; i++)
        for (j = 0; j < R; j++) {
            allocation[i][j] = alloc[i][j];
            maximum[i][j] = max[i][j];
        }

    for (j = 0; j < R; j++)
        available[j] = avail[j];

    calculateNeed();

    printf("Checking initial system state:\n");
    isSafe();

    printf("\nProcess P1 requests resources (1,0,2):\n");
    int request[R] = {1, 0, 2};
    requestResources(1, request);

    return 0;
}
