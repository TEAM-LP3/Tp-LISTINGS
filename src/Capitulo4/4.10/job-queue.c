#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct job {
    /* Link field for linked list.*/
    int k;
    struct job* next;
    /* Other fields describing work to be done... */
};

/* A linked list of pending jobs.*/
struct job* job_queue;

/*pthread_self() :devuelve el id de un hilo*/

void process_job(struct job *doing) 
{
    printf("Se esta procesado el trabajo %d en el hilo : %ld\n",doing->k,pthread_self());
}
    
/* Process queued jobs until the queue is empty*/
void* thread_function (void* arg)
{
   
    printf("\n La lista es procesada\n" );

    while (job_queue != NULL) {
        /* Get the next available job. */
        struct job* next_job = job_queue;
        /* Remove this job from the list. */
        job_queue = job_queue->next;
        /* Carry out the work. */
        process_job (next_job);
        /* Clean up. */
        free (next_job);
    }
    return NULL;
}

/* Funcion para insertar los trabajos dentro de la lista tipo struct*/

void insert_jobs(){
    
  for(int j=1;j<=5;j++){

      printf("Insertando en la lista el trabajo n°: %d \n",j);
      sleep(2);
      //se asigna memoria a la variable p_job 
      struct job *p_job =(struct job *)malloc(sizeof(struct job));
      p_job->next=NULL;
      p_job->k=1;
      p_job->next=job_queue;
      job_queue=p_job;

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