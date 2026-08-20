
#include <stdio.h>
#include <stdlib.h>

#define DISK_SIZE 200

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

int main() {
    int requests[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 53;
    char direction = 'R'; // R = towards higher, L = towards lower

    int totalSeekTime = 0;
    int currentHead = head;

    sortArray(requests, n);

    int i;
    for (i = 0; i < n; i++)
        if (requests[i] >= head)
            break;

    printf("SCAN Disk Scheduling\n");
    printf("Initial Head Position: %d, Direction: %s\n\n",
           head, direction == 'R' ? "Right (increasing)" : "Left (decreasing)");

    printf("Order of servicing:\n%d", currentHead);

    if (direction == 'R') {
        for (int j = i; j < n; j++) {
            totalSeekTime += abs(requests[j] - currentHead);
            currentHead = requests[j];
            printf(" -> %d", currentHead);
        }
        totalSeekTime += abs((DISK_SIZE - 1) - currentHead);
        currentHead = DISK_SIZE - 1;
        printf(" -> %d (end of disk)", currentHead);

        for (int j = i - 1; j >= 0; j--) {
            totalSeekTime += abs(requests[j] - currentHead);
            currentHead = requests[j];
            printf(" -> %d", currentHead);
        }
    } else {
        for (int j = i - 1; j >= 0; j--) {
            totalSeekTime += abs(requests[j] - currentHead);
            currentHead = requests[j];
            printf(" -> %d", currentHead);
        }
        totalSeekTime += abs(0 - currentHead);
        currentHead = 0;
        printf(" -> %d (start of disk)", currentHead);

        for (int j = i; j < n; j++) {
            totalSeekTime += abs(requests[j] - currentHead);
            currentHead = requests[j];
            printf(" -> %d", currentHead);
        }
    }

    printf("\n\nTotal Seek Time = %d\n", totalSeekTime);
    printf("Average Seek Time = %.2f\n", (float)totalSeekTime / n);

    return 0;
}
