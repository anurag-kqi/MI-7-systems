#include <stdio.h>
#include <pthread.h>
        
void* threadFunction(void* args)
{
    while(1)
    {
        printf("I am threadFunction.\n");
    }
}
int main()
{
    pthread_t id;  //Thread id created
    int ret;
    
    ret=pthread_create(&id,NULL,&threadFunction,NULL);  //Thread Creating
    if(ret==0){
        printf("Thread created successfully.\n");
    }
    else{
        printf("Thread not created.\n");
        return 0; 
    }
    
    while(1)
    {
        printf("I am main function.\n");      
    }
    
    return 0;
}
