#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

/*Diferencia entre funcion cleanup handler en C y C++ 
  En C++ se llama a una excepcion ,usar pthread_exit no garantiza que se limpien los recursos
  en la pila */

class ThreadExitException
{
 public:
      ThreadExitException(void *return_value) : thread_return_value(return_value) {}

       void *DoThreadExit()
       {
           printf("\nSe trata de cancelar el hilo \n");
           pthread_exit(thread_return_value);
        }

 private:
       void *thread_return_value;
};

class example
{

public:
       example(int size)
    {

        printf("\nSe asigna la memoria\n");
        memory = malloc(size);
    }

    ~example()

    {

        printf("\n Libera memoria\n");
        free(memory);
    }

private:
    void *memory;
};

void do_some_work()

{

    example e(100);
    printf("Se lanza la excepcion\n");
    throw ThreadExitException(NULL);
}

void *thread_function(void *)

{

    try

    {
        do_some_work();
    }

    catch (ThreadExitException ex)
    {
        printf("Libera los recursos\n");
        ex.DoThreadExit();
    }

    return NULL;
}

int main()

{

    pthread_t hilo;
    printf("\nCreamos el hilo\n");
    pthread_create(&hilo,NULL, &thread_function,NULL);
    printf("\n Espera a que el hilo termine\n");
    pthread_join(hilo, NULL);
}