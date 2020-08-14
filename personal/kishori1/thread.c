/*Program of Threads*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* func_thread(void* arg)
{
    printf("Inside the thread\n");
    //exit the current thread
    pthread_exit(NULL);
}

void
fun()
{
  pthread_t ptid;
  // Creating a new thread
  pthread_create(&ptid, NULL, &func_thread, NULL);

  printf("before thread terminates\n");
  printf("%lu\n", ptid);
  printf("%lu\n", pthread_self());

  //Compare the two threads
  if(pthread_equal(ptid, pthread_self())) {
    printf("Threads are equal\n");
  }
  else {
    printf("Threads are not equal\n");
  }
  pthread_join(ptid, NULL);
  printf("This line will be printed after thread ends\n");
  pthread_exit(NULL);
}

// Driver code
int
main()
{
    fun();
    return 0;
}
