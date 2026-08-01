#include <stdio.h>

int main()
{
    int data = 100;

    printf("Reader reads: %d\n",data);

    data = 200;

    printf("Writer updates: %d\n",data);

    return 0;
}
