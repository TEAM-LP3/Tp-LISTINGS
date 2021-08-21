#include <pthread.h>
#include <stdio.h>
/* Calcule números primos sucesivos (de manera muy ineficiente). Devuelve el
N-ésimo número primo, donde N es el valor al que apunta *ARG */
void *compute_prime(void *arg)
{
    int candidate = 2;
    int n = *((int *)arg);
    while (1)
    {
        int factor;
        int is_prime = 1;
        /* Pruebe la primalidad por división sucesiva. */
        for (factor = 2; factor < candidate; ++factor)
            if (candidate % factor == 0)
            {
                is_prime = 0;
                break;
            }
        /* ¿Este es el número primo que estamos buscando? */
        if (is_prime)
        {
            if (--n == 0)
                /* Devuelve el número primo deseado como valor de retorno del hilo. */
                return (void *)candidate;
        }
        ++candidate;
    }
    return NULL;
}
int main()
{
    pthread_t thread;
    int which_prime = 5000;
    int prime;
    /* Inicia el hilo de cálculo, hasta el número primo 5000. */
    pthread_create(&thread, NULL, &compute_prime, &which_prime);
    /* Hace otro trabajo  */
    int i = 0;
    printf("Waiting the %dth prime number \n", which_prime);
    while (i < 1000000)
        i++;

    /* Espera a que se complete el hilo de números primos y obtenga el resultado. */
    pthread_join(thread, (void *)&prime);
    /* Imprime el primo más grande que calculo */
    printf("The %dth prime number is %d.\n", which_prime, prime);
    return 0;
}