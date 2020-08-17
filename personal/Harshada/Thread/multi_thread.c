#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void *myThreadFun(void *i)
{
    int tnum = (int)i;
    sleep(1);
    printf("Printing %d Thread \n", i);
    return NULL;
}

int main()
{
    int i, n;
    pthread_t thread_id;

    printf("Enter numer of threads\n");
    scanf("%d\n", &n);

    printf("Before Thread\n");
    for (i = 0; i < n; i++) {
        pthread_create(&thread_id, NULL, myThreadFun, (void*)i);
        pthread_join(thread_id, NULL);
    }
    printf("After Thread\n");

    exit(0);
}
