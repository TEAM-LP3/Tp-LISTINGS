#include <pthread.h>
#include <stdio.h>
/* Parametros para print_function. */
struct char_print_parms
{
    /*El caracter a imprimir */
    char character;
    /* El numero de veces que se imprimira */
    int count;
};
/* Imprime una serie de caracteres a stderr, según lo indicado por PARAMETERS,
que es un puntero a una estructura char_print_parms. */
void *char_print(void *parameters)
{
    /* Lanza el puntero de la cookie al tipo correcto. */
    struct char_print_parms *p = (struct char_print_parms *)parameters;
    int i;
    for (i = 0; i < p->count; ++i)
        fputc(p->character, stderr);
    return NULL;
}
/* El main del programa. */
int main()
{
    pthread_t thread1_id;
    pthread_t thread2_id;
    struct char_print_parms thread1_args;
    struct char_print_parms thread2_args;
    /* Crea un nuevo hilo para imprimir  30,000 x’s. */
    thread1_args.character = 'x';
    thread1_args.count = 30000;
    pthread_create(&thread1_id, NULL, &char_print, &thread1_args);
    /* Crea un nuevo hilo para imprimir 20,000 o’s. */
    thread2_args.character = 'o';
    thread2_args.count = 20000;
    pthread_create(&thread2_id, NULL, &char_print, &thread2_args);
    /* Asegura que el primer hilo haya terminado. */
    pthread_join(thread1_id, NULL);
    /* Asegura que el segundo hilo haya terminado. */
    pthread_join(thread2_id, NULL);
    printf("\nMain thread saliendo luego de esperar a los dos hilos\n");
    /* Ahora retorna.*/
    return 0;
}