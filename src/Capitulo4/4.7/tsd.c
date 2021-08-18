#include <malloc.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//escribe y genera archivos cuando un hilo comparte su key con otros hilos


/* The key used to associate a log file pointer with each thread. */
static pthread_key_t thread_log_key;
/* Write MESSAGE to the log file for the current thread. */
void write_to_thread_log(const char *message)
{
    FILE *thread_log = (FILE *)pthread_getspecific(thread_log_key);
    fprintf(thread_log, "%s\n", message);
}
/* Close the log file pointer THREAD_LOG. */
void close_thread_log(void *thread_log)
{
    fclose((FILE *)thread_log);
}
void *thread_function(void *args)
{
    char thread_log_filename[20];
    
    FILE *thread_log;
    
    int r;
    srand(time(NULL)); //se inicializa
    r=rand();
    
    /* Generate the filename for this thread’s log file. */
    sprintf(thread_log_filename, "thread %d.log", (int)pthread_self());
    
    /* Open the log file. */
    thread_log = fopen(thread_log_filename, "w");
    
    /* Store the file pointer in thread-specific data under thread_log_key. */
    
    pthread_setspecific(thread_log_key, thread_log);
    
    write_to_thread_log("Thread starting.");
    /* Do work here... */
    
    printf("se escribe en el log\n");
    char array_log[30];
    sprintf(array_log, "guardamos %d \n",r);
    write_to_thread_log(array_log);    

    return NULL;
}
int main()
{
    printf("hola");
    int i;
    pthread_t threads[5];


    /* pthread_key_create  usa dos parametros 
     1er parametro= un puntero tipo pthread_key_t 
     2do parametro= un puntero a una funcion de limpieza, que puede dejarse nulo */
    
    /* Create a key to associate thread log file pointers in
     thread-specific data. Use close_thread_log to clean up the file
     pointers. */
    
    pthread_key_create(&thread_log_key, close_thread_log);
    
    /* Create threads to do the work. */
    for (i = 0; i < 5; ++i)
        pthread_create(&(threads[i]), NULL, thread_function, NULL);
    
    /* Wait for all threads to finish. */
    for (i = 0; i < 5; ++i)
        pthread_join(threads[i], NULL);
    return 0;
}