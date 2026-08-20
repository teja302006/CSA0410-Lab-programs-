
#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 53;

    int totalSeekTime = 0;
    int currentHead = head;

    printf("FCFS Disk Scheduling\n");
    printf("Initial Head Position: %d\n\n", head);
    printf("Order of servicing:\n%d", currentHead);

    for (int i = 0; i < n; i++) {
        int distance = abs(requests[i] - currentHead);
        totalSeekTime += distance;
        currentHead = requests[i];
        printf(" -> %d", currentHead);
    }

    printf("\n\nTotal Seek Time = %d\n", totalSeekTime);
    printf("Average Seek Time = %.2f\n", (float)totalSeekTime / n);

    return 0;
}
