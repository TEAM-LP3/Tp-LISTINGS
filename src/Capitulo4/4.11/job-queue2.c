
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*Programa parecido al listing 4.10 ,soluciona el problema de condiciones de carreras
  utiliza un mutex para que dos hilos no puedan realizar el mismo trabajo*/

/*
Inicializar un mutex
  pthread_mutex_t mutex;
  pthread_mutex_init (&mutex, NULL);

Con variables globales
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
*/



struct job {
    /* Link field for linked list.*/
    int k;
    struct job* next;
    /* Other fields describing work to be done... */
};

/* A linked list of pending jobs.*/
struct job* job_queue;


/* Se procesa el trabajo*/
void *process_job(struct job *doing) 
{
    printf("Se esta procesado el trabajo %d en el hilo : %ld\n",doing->k,pthread_self());
}


/* A mutex protecting job_queue. */
pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;


void* thread_function (void* arg)
{
  while (1) {
    struct job* next_job;
    /* Lock the mutex on the job queue. */
    pthread_mutex_lock (&job_queue_mutex);
    /* Now it’s safe to check if the queue is empty. */
  
    if (job_queue == NULL)
       next_job = NULL;
    else {
      /* Get the next available job. */
      next_job = job_queue;
      /* Remove this job from the list. */  
      job_queue = job_queue->next;
    }

    /* Unlock the mutex on the job queue because we’re done with the
    queue for now. */
    pthread_mutex_unlock (&job_queue_mutex);
    /* Was the queue empty?*/
    if (next_job == NULL)
       break;
      /*If so, end the thread.*/
      /* Carry out the work. */
    process_job (next_job);
    /* Clean up. */
    sleep(5);
    free (next_job);
  }
  return NULL;
}

/*Funcion que sirve para encolar el trabajo con un mutex y bloquear a otros hilos*/

void enqueue_job(struct job *new_job)
{
  printf("Encola el job\n");
  pthread_mutex_lock(&job_queue_mutex);
  new_job->next = job_queue;
  job_queue = new_job;
  pthread_mutex_unlock(&job_queue_mutex);
}

  


void insert_jobs(){
    
  int i = 0;

  while (i < 10)
  {

    sleep(1);

    printf("Ingresa  en la lista el job: %d.\n", i);
    struct job *new_job = (struct job *)malloc(sizeof(struct job));
    new_job->next = NULL;
    new_job->k = i;
    enqueue_job(new_job);
    i++;
  }
}



int main(){

  //insertamos en la lista los trabajos
  
  insert_jobs();
  
  pthread_t h1,h2;
  
  printf("creamos los hilos\n");
  pthread_create(&h1,NULL,&thread_function,NULL);
  pthread_create(&h2,NULL,&thread_function,NULL);

  pthread_join(h1,NULL);
  pthread_join(h2,NULL);

  return 0;

}