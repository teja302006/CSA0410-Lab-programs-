#include <stdio.h>

int main()
{
    int buffer = 0;

    printf("Producer produces an item.\n");
    buffer++;

    printf("Items in Buffer = %d\n",buffer);

    printf("Consumer consumes an item.\n");
    buffer--;

    printf("Items in Buffer = %d\n",buffer);

    return 0;
}
