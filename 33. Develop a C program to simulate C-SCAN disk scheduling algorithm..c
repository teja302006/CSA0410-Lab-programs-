#include <stdio.h>
#include <stdlib.h>
 
void cscan(int requests[], int n, int head, int disk_size) {
    int seek_count = 0;
    int distance, cur_track;
    int left[50], right[50];
    int l = 0, r = 0;
 
    for (int i = 0; i < n; i++) {
        if (requests[i] < head)
            left[l++] = requests[i];
        else
            right[r++] = requests[i];
    }
 
    for (int i = 0; i < l - 1; i++)
        for (int j = i + 1; j < l; j++)
            if (left[i] > left[j]) {
                int t = left[i]; left[i] = left[j]; left[j] = t;
            }
 
    for (int i = 0; i < r - 1; i++)
        for (int j = i + 1; j < r; j++)
            if (right[i] > right[j]) {
                int t = right[i]; right[i] = right[j]; right[j] = t;
            }
 
    cur_track = head;
    printf("Seek Sequence is:\n");
    printf("%d\n", cur_track);
 
    for (int i = 0; i < r; i++) {
        printf("%d\n", right[i]);
        distance = abs(right[i] - cur_track);
        seek_count += distance;
        cur_track = right[i];
    }
 
    distance = abs((disk_size - 1) - cur_track);
    seek_count += distance;
    cur_track = disk_size - 1;
 
    distance = abs(cur_track - 0);
    seek_count += distance;
    cur_track = 0;
 
    for (int i = 0; i < l; i++) {
        printf("%d\n", left[i]);
        distance = abs(left[i] - cur_track);
        seek_count += distance;
        cur_track = left[i];
    }
 
    printf("Total seek count is %d\n", seek_count);
}
 
int main() {
    int n, head, disk_size;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int requests[50];
    printf("Enter the request sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size: ");
    scanf("%d", &disk_size);
    cscan(requests, n, head, disk_size);
    return 0;
}
