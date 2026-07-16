#include <stdio.h>

int main() {
    int bt[20], rem[20];
    int n, tq, i, complete=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        printf("Burst Time of P%d: ",i+1);
        scanf("%d",&bt[i]);
        rem[i]=bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    while(complete<n) {

        for(i=0;i<n;i++) {

            if(rem[i]>0) {

                if(rem[i]<=tq) {
                    printf("P%d ",i+1);
                    rem[i]=0;
                    complete++;
                }

                else {
                    printf("P%d ",i+1);
                    rem[i]-=tq;
                }
            }
        }
    }

    return 0;
}
