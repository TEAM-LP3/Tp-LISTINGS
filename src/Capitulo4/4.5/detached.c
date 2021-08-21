#include <pthread.h>
#include <stdio.h>
void *thread_function(void *thread_arg)
{
    /* Cuenta el hilo aca*/
    int i = 0;
    while (i < 10)
    {
        printf("\nContando desde hilo hijo: %d\n", i);
        i++;
    }
}
int main()
{
    pthread_attr_t attr;
    pthread_t thread;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&thread, &attr, &thread_function, NULL);
    pthread_attr_destroy(&attr);
    /* Trabaja aqui */

    int i = 0;
    while (i < 11)
    {
        printf("\nContando desde hilo padre: %d\n", i);
        i++;
    }
    /* No es necesario unirse al segundo hilo */
    return 0;
}