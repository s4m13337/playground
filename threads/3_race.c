/**
 * Chapter 3 race condition
 */

#include <stdio.h>
#include <pthread.h>

int x = 0;
pthread_mutex_t mutex;

void *routine()
{
    // x++;
    for (int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex); // Locks the variable from being modified by other threads
        x++;
        pthread_mutex_unlock(&mutex); // Unlocks the variable
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2, t3, t4;
    pthread_mutex_init(&mutex, NULL);
    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
    {
        return -1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
    {
        return -1;
    }
    if (pthread_create(&t3, NULL, &routine, NULL) != 0)
    {
        return -1;
    }
    if (pthread_create(&t4, NULL, &routine, NULL) != 0)
    {
        return -1;
    }
    if (pthread_join(t1, NULL) != 0)
    {
        return -1;
    }
    if (pthread_join(t2, NULL) != 0)
    {
        return -1;
    }
    if (pthread_join(t3, NULL) != 0)
    {
        return -1;
    }
    if (pthread_join(t4, NULL) != 0)
    {
        return -1;
    }
    pthread_mutex_destroy(&mutex);
    printf("The value of x is %d\n", x);
    return 0;
}

/*
    When processing large data, the operating system may schedule the threads differently
    Since both the threads try to modify the same variable simultaneously, the consistency of result is no longer guaranteed
    This happens at larger number of iterations because at lesser number of iterations, by the time the second thread gets created, the first thread would have already computed its result.
    In case of larger iterations, when the second thread is created, the first thread's computation is not yet done, so there occurs an interleaving between the two threads.

    Race conditions can be solved with the help of mutexes
    pthread_mutex_t --- Custom type for mutex instances
    pthread_mutex_init(&mutex_var, NULL) --- Initialize the mutex, takes 2 arguments: reference to the mutex instance and Attributes which can be NULL
    pthread_mutex_destroy(&mutex) --- Destroys the mutex (Frees up itse memory)
    pthread_mutex_lock(&mutex) --- Applies mutex lock
    pthread_mutex_unlock(&mutex) --- Unlocks mutex variable

    !! Race condition can occur only on multicore processor !!
*/