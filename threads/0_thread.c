#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int x = 43;

void *routine()
{
    printf("Process ID %d\n", getpid());
    printf("Test from threads\n");
    sleep(3); // Requires unistd
    printf("Ending thread\n");
    return NULL; /* Return type of this function is a void pointer, so NULL must be specified */
}

void *routine2()
{
    x++;
    sleep(2);
    printf("Value of x %d\n", x);
    return NULL;
}

void *routine3()
{
    x++;
    sleep(2);
    printf("Value of x %d\n", x);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2, t3, t4;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0) /* Error checking blocks. The pthread_create returns 0 if successful */
    {
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
    {
        return 2;
    }
    if (pthread_create(&t3, NULL, &routine2, NULL) != 0)
    {
        return -1;
    }
    if (pthread_create(&t4, NULL, &routine3, NULL) != 0)
    {
        return -1;
    }
    if (pthread_join(t1, NULL) != 0) /* The pthread_join also returns 0 if successful */
    {
        return 3;
    }
    if (pthread_join(t2, NULL) != 0)
    {
        return 4;
    };

    if (pthread_join(t3, NULL) != 0)
    {
        return -1;
    };

    if (pthread_join(t4, NULL) != 0)
    {
        return -1;
    };
    return 0;
}

/*
    Summary
    pthread_t --- Custom type to create thread instances
    pthread_create --- Function to create thread
    pthread_join --- Wait till the thread returns response

    The process id remains the same because a process can contain multiple threads
    The global variable x is incremented in only one function, but the output is still incremented in both cases
    This means that x is a shared resource.
*/