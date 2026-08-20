
#include <stdio.h>

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;
    int frames[10];
    int lastUsed[10];
    int frameCount = 0;
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = -1;

        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            lastUsed[found] = i; 
            printf("Page %d already in frame -> No fault\n", page);
            continue;
        }

        pageFaults++;

        if (frameCount < capacity) {
            frames[frameCount] = page;
            lastUsed[frameCount] = i;
            frameCount++;
        } else {
            int lruIndex = 0;
            for (int j = 1; j < capacity; j++) {
                if (lastUsed[j] < lastUsed[lruIndex])
                    lruIndex = j;
            }
            frames[lruIndex] = page;
            lastUsed[lruIndex] = i;
        }

        printf("Page %d causes a fault -> Frames: ", page);
        for (int j = 0; j < frameCount; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}
