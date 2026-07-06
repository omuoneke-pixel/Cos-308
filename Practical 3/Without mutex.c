stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 5

int counter = 0;
sem_t semaphore;

// Function executed by each thread
void *increment(void *arg)
{
    // Wait (lock semaphore)
    sem_wait(&semaphore);

    counter++;
    printf("Thread %ld incremented counter to %d\n",
           (long)arg, counter);

    // Release semaphore
    sem_post(&semaphore);

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];

    // Initialize semaphore with value 1
    sem_init(&semaphore, 0, 1);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, increment, (void *)(long)i);
    }

    // Wait for all threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("\nFinal Counter = %d\n", counter);

    // Destroy semaphore
    sem_destroy(&semaphore);

    return 0;
