Practical 1
without_mutex.c
#include <stdio.h>
#include <pthread.h>

#define THREADS 10
#define COUNT 100000

int counter = 0;

void *increment(void *arg)
{
    for(int i=0;i<COUNT;i++)
        counter++;

    return NULL;
}

int main()
{
    pthread_t thread[THREADS];

    for(int i=0;i<THREADS;i++)
        pthread_create(&thread[i], NULL, increment, NULL);

    for(int i=0;i<THREADS;i++)
        pthread_join(thread[i], NULL);

    printf("Counter = %d\n", counter);

    return 0;
}
Compile
