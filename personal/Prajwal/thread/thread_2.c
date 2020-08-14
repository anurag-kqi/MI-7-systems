#include <stdio.h>
#include <pthread.h>
#define MAX 500000000
long long sum = 0;
pthread_mutex_t mutex;

void *fun(void* fun) {
    int count = *(int *) fun;
    for(int i = 0; i < MAX; i++) {
        // pthread_mutex_lock(&mutex);
        sum += count;
        // pthread_mutex_unlock(&mutex);
    }
    printf("This is thread running\n");
    pthread_exit(NULL);

}

int main() {
    pthread_t id1;
    pthread_t id2;
    int count = 1;
    printf("Before thread running..\n");
    pthread_create(&id1, NULL, fun, &count);

    int count2 = -1;
    pthread_create(&id2, NULL, fun, &count2);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    printf("sum: %lld\n", sum);
    printf("Stop Thread\n");
    return 0;

}
