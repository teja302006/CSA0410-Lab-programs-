#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
 
void *thread_function(void *arg) {
    long id = (long)arg;
    printf("Thread %ld started, Thread ID = %lu\n", id, pthread_self());
    printf("Thread %ld exiting\n", id);
    pthread_exit(NULL);
}
 
int main() {
    pthread_t t1, t2;
 

    pthread_create(&t1, NULL, thread_function, (void *)1);
    pthread_create(&t2, NULL, thread_function, (void *)2);

    if (pthread_equal(t1, t2))
        printf("Thread 1 and Thread 2 are the same\n");
    else
        printf("Thread 1 and Thread 2 are different\n");
 

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
 
    printf("Main thread exiting\n");
    pthread_exit(NULL);
}
