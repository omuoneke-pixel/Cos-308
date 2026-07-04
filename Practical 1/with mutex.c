Practical 1: Mutex Lock Demonstration
#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void *increment(void *arg)
{
    pthread_mutex_lock(&lock);

    counter++;

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t t1, t2, t3, t4, t5;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);
    pthread_create(&t3, NULL, increment, NULL);
    pthread_create(&t4, NULL, increment, NULL);
    pthread_create(&t5, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);

    printf("Final Counter = %d\n", counter);

    pthread_mutex_destroy(&lock);

    return 0;
}

Compile:
gcc mutex.c -o mutex -pthread

Run:
./mutex

Expected output:
Final Counter = 5
