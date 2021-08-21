#include <malloc.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/*
pthread_cleanup_push must be balanced by a corresponding call to
pthread_cleanup_pop , which unregisters the cleanup handler. As a convenience,
pthread_cleanup_pop takes an int flag argument; if the flag is nonzero, the cleanup
action is actually performed as it is unregistered.
*/

//Limpia los recursos para que no se filtren cuando un hilo se detiene"

/* Allocate a temporary buffer. */
void *allocate_buffer(size_t size)
{
    printf("utilizando malloc para asignar memoria \n"); 
    return malloc(size);
}

/* Deallocate a temporary buffer. */

void deallocate_buffer(void *buffer)
{
    printf("\n Desasignando el buffer , ejecutando el cleanup handler\n");
    free(buffer);
    printf("Se libero el Buffer \n");
}

void do_some_work()
{
    /* Allocate a temporary buffer. */
    void *temp_buffer = allocate_buffer(1000); //asigna memoria al buffer
    
    /* Register a cleanup handler for this buffer, to deallocate it in
    case the thread exits or is cancelled. */
    pthread_cleanup_push(deallocate_buffer, temp_buffer);
    
    /* Do some work here that might call pthread_exit or might be
    cancelled... */
    
    printf(" Se cancela el hilo \n");
    sleep(2);
    pthread_exit(0);

    /*Unregister the cleanup handler. Because we pass a nonzero value,
     this actually performs the cleanup by calling
     deallocate_buffer. */
    pthread_cleanup_pop(1);
}

int main(){
   do_some_work();
}