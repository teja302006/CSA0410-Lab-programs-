#include <stdio.h>

int main()
{
    int alloc, max, avail, need;

    printf("Enter Allocation: ");
    scanf("%d",&alloc);

    printf("Enter Maximum: ");
    scanf("%d",&max);

    printf("Enter Available: ");
    scanf("%d",&avail);

    need = max - alloc;

    printf("Need = %d\n",need);

    if(need <= avail)
        printf("System is in Safe State");
    else
        printf("System is in Unsafe State");

    return 0;
}
