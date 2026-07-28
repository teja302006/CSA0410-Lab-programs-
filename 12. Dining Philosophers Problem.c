#include <stdio.h>
int main()
{
    int i;

    for(i = 1; i <= 5; i++)
    {
        printf("Philosopher %d is Thinking\n", i);
        printf("Philosopher %d picked Left Fork\n", i);
        printf("Philosopher %d picked Right Fork\n", i);
        printf("Philosopher %d is Eating\n", i);
        printf("Philosopher %d put down both Forks\n\n", i);
    }

    return 0;
}
