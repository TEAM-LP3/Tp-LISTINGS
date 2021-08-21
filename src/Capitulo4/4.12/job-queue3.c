#include <malloc.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

struct job {
    /* Link field for linked list.*/
    int k;
    struct job* next;

};

/* A linked list of pending jobs.*/
struct job* job_queue;

/* A mutex protecting job_queue. */
pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

/* A semaphore counting the number of jobs in the queue.*/
sem_t job_queue_count;
/* Perform one-time initialization of the job queue.*/

void initialize_job_queue ()
{
    /* The queue is initially empty. */
    job_queue = NULL;
    /* Initialize the semaphore which counts jobs in the queue.
    initial value should be zero. */
    sem_init (&job_queue_count, 0, 0);
}
/* Process queued jobs until the queue is empty.
*/


void process_job(struct job *p)

{
   printf("El job procesado es : %d.\n", p->k);
}


void* thread_function (void* arg)
{
    while (1) {
        struct job* next_job;
        /* Wait on the job queue semaphore. If its value is positive,
        indicating that the queue is not empty, decrement the count by
        1. If the queue is empty, block until a new job is enqueued. */
        sem_wait (&job_queue_count);
        /* Lock the mutex on the job queue. */
        pthread_mutex_lock (&job_queue_mutex);
        /* Because of the semaphore, we know the queue is not empty. Get
        the next available job. */
        next_job = job_queue;
        /* Remove this job from the list. */
        job_queue = job_queue->next;
        /* Unlock the mutex on the job queue because we’re done with the
        queue for now. */
        pthread_mutex_unlock (&job_queue_mutex);
        /* Carry out the work. */
        process_job (next_job);
        /* Clean up. */
        free (next_job);
    }
    return NULL;
}

void enqueue_job(struct job *new_job)

{
   pthread_mutex_lock(&job_queue_mutex);

    printf("insertando un job a la cola\n");

    new_job->next = job_queue;

    job_queue = new_job;

    sem_post(&job_queue_count);

    printf("desbloqueando luego de insertar\n");

    pthread_mutex_unlock(&job_queue_mutex);
}

void insert_jobs(){
    
  int i = 0;

  while (i < 6)
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