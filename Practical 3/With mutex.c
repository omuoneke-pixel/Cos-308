mutex.c
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

int counter = 0;

// Declare the mutex
pthread_mutex_t mutex;

// Function executed by each thread
void *increment(void *arg)
{
    // Lock the mutex
    pthread_mutex_lock(&mutex);

    counter++;
    printf("Thread %ld incremented counter to %d\n",
           (long)arg, counter);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, increment, (void *)(long)i);
    }

    // Wait for all threads
    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("\nFinal Counter = %d\n", counter);

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
