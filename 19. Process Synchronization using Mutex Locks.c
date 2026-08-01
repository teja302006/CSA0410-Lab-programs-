#include <stdio.h>

int main()
{
    int mutex = 1;
    int count = 0;

    if(mutex == 1)
    {
        mutex = 0;
        count++;
        printf("Shared Resource = %d\n",count);
        mutex = 1;
    }

    return 0;
}
