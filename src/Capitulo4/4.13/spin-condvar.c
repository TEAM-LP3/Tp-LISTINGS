#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>

int thread_flag;
pthread_mutex_t thread_flag_mutex;

void initialize_flag ()
{
pthread_mutex_init (&thread_flag_mutex, NULL);
thread_flag = 0;
}

/* Sets the value of the thread flag to FLAG_VALUE.
void set_thread_flag (int flag_value)
{
/* Protect the flag with a mutex lock. */
void set_thread_flag (int flag_value){
    printf("\nEstableciendo el valor del flag a %d\n",flag_value);
    pthread_mutex_lock (&thread_flag_mutex);
    thread_flag = flag_value;
    pthread_mutex_unlock (&thread_flag_mutex);
}

/* Calls do_work repeatedly while the thread flag is set; otherwise
spins. */

void do_work(){

    printf("\nWorking...\n");
    /*cambiando el valor del flag para que vuelva a entrar al bucle*/
    set_thread_flag(0);
    printf("Flag ->0 ,Vuelve al ciclo infinito\n");

}

void* thread_function (void* thread_arg)
{
    printf("Entra en la funcion ,pero espera que el flag se active a 0");
    while (1) {
        int flag_is_set;
        /* Protect the flag with a mutex lock. */
        pthread_mutex_lock (&thread_flag_mutex);
        flag_is_set = thread_flag;
        pthread_mutex_unlock (&thread_flag_mutex);
        if (flag_is_set)
         do_work ();
        /* Else don’t do anything.
        Just loop again.
        */
    }
    return NULL;
}

\

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