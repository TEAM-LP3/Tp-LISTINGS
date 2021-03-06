#include <pthread.h>
#include<stdio.h>
#include <unistd.h>
int thread_flag;
pthread_cond_t thread_flag_cv;
pthread_mutex_t thread_flag_mutex;

void initialize_flag ()
{
    /* Initialize the mutex and condition variable.*/
    pthread_mutex_init (&thread_flag_mutex, NULL);
    pthread_cond_init (&thread_flag_cv, NULL);
    /* Initialize the flag value. */
    thread_flag = 0;
}

void set_thread_flag (int flag_value)
{
    printf("\nEstableciendo el valor del flag a %d\n",flag_value); 
    /* Lock the mutex before accessing the flag value. */
    pthread_mutex_lock (&thread_flag_mutex);
    /* Set the flag value, and then signal in case thread_function is
    blocked, waiting for the flag to become set. However,
    thread_function can’t actually check the flag until the mutex is
    unlocked. */
    thread_flag = flag_value;
    pthread_cond_signal (&thread_flag_cv);
    /* Unlock the mutex. */
    pthread_mutex_unlock (&thread_flag_mutex);
}

/* Calls do_work repeatedly while the thread flag is set; blocks if
the flag is clear. */

void do_work(){

    printf("\nWorking...\n");
    /*cambiando el valor del flag para que vuelva a entrar al bucle*/
    set_thread_flag(0);
    printf("Flag ->0 ,Vuelve al ciclo infinito\n");
}


void* thread_function (void* thread_arg)
{
     printf("Entra en la funcion ,pero espera que el flag se active a 0");
    /* Loop infinitely. */
    while (1) {
        /* Lock the mutex before accessing the flag value. */
        pthread_mutex_lock (&thread_flag_mutex);
        while (!thread_flag)
            /* The flag is clear. Wait for a signal on the condition
            variable, indicating that the flag value has changed. When the
            signal arrives and this thread unblocks, loop and check the
            flag again. */
            pthread_cond_wait (&thread_flag_cv, &thread_flag_mutex);
            /* When we’ve gotten here, we know the flag must be set. Unlock
            the mutex. */
        pthread_mutex_unlock (&thread_flag_mutex);
        /* Do some work. */
        do_work ();
    }
    return NULL;
}

void *change_flag(){
    /*funcion auxiliar que bloquea a otro hilo cambiando de valor el flag*/
    set_thread_flag(1);
}

int main(){
  
  pthread_t h1,h2;
  
  printf("creamos los hilos\n");
  pthread_create(&h1,NULL,&thread_function,NULL);
  pthread_create(&h2,NULL,&change_flag,NULL);

  pthread_join(h1,NULL);
  pthread_join(h2,NULL);

  return 0;

}



