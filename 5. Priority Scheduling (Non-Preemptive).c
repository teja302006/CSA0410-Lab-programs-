#include <stdio.h>

int main() {
    int bt[20], pr[20], p[20];
    int i, j, n, temp;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        p[i]=i+1;
        printf("Burst Time of P%d: ",i+1);
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);
    }

    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if(pr[i]>pr[j]) {

                temp=pr[i];
                pr[i]=pr[j];
                pr[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    printf("\nExecution Order:\n");

    for(i=0;i<n;i++)
        printf("P%d ",p[i]);

    return 0;
}
