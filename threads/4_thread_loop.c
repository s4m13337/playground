/*
    Creating mutiple threads using a loop
*/

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int x;

void *routine()
{
    for (int i = 0; i < 100000000; i++)
    {
        pthread_mutex_lock(&mutex);
        x++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t th[4];
    pthread_mutex_init(&mutex, NULL);

    // Creating threads in a loop
    for (int i = 0; i < 8; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
        {
            perror("Failed to create thread\n");
            return -1;
        }
    }

    // Join threads in a loop
    for (int i = 0; i < 8; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread");
            return -1;
        }
    }

    pthread_mutex_destroy(&mutex);

    printf("The value of x is %d\n", x);
    return 0;
}

/**
 * Important
 * pthread_create takes a reference to the thread instance
 * pthread_join takes the thread instance itself
 */