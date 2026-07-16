#include <stdio.h>

int main() {
    int bt[20], p[20], wt[20], tat[20];
    int n, i, j, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Burst Time of P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    printf("\nProcess\tBT\tWT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\n", p[i], bt[i], wt[i]);

    return 0;
}
