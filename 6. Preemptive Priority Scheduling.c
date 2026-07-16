#include <stdio.h>

int main() {
    int n, bt[10], pr[10], p[10];
    int completed = 0, time = 0, min, shortest;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        p[i]=i+1;
        printf("Burst Time of P%d: ",i+1);
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);
    }

    printf("\nExecution Order:\n");

    while(completed<n) {

        min=9999;
        shortest=-1;

        for(int i=0;i<n;i++) {
            if(bt[i]>0 && pr[i]<min) {
                min=pr[i];
                shortest=i;
            }
        }

        printf("P%d ",p[shortest]);

        bt[shortest]--;
        time++;

        if(bt[shortest]==0)
            completed++;
    }

    return 0;
}
