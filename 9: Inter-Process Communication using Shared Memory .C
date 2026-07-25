#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    key_t key = 1234;
    int shmid;
    char *str;

    // Create shared memory
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Attach shared memory
    str = (char *)shmat(shmid, NULL, 0);

    // Write data
    strcpy(str, "Hello from Shared Memory!");

    printf("Data Written: %s\n", str);

    // Detach shared memory
    shmdt(str);

    // Delete shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
