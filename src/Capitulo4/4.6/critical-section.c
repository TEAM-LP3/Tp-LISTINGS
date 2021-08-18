#include <pthread.h> //funciones para hilos
#include <stdio.h>
#include <string.h>
#include <unistd.h> //para usar sleep()

/*OBS*/
/***************************
*  from_acct : la cuenta de la cual se realiza la tranferencia
*  to_acct : La cuenta a la cual se realiza la transferencia
*  dollars : el monto que se envia
***************************/

/*se usa la funcion pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*rutina)(void *), void *arg) */
 
 /* se usa un struct para pasar los parametros al hilo*/

 struct accounts
 {
    int from_acc;
    int to_acc;
    float dollars;
 };
  
/* An array of balances in accounts, indexed by account number.
*/

float* account_balances;

/* Transfer DOLLARS from account FROM_ACCT to account TO_ACCT. Return
0 if the transaction succeeded, or 1 if the balance FROM_ACCT is
too small. */

void*process_transaction (void *cuentas) //puntero sin identificar el tipo
{
    int old_cancel_state;

     struct accounts * p = (struct accounts * )cuentas;
     
    /* Check the balance in FROM_ACCT. */
    if (account_balances[p->from_acc] < p->dollars)
     return (void *)1;

    /* Begin critical section. */
    pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, &old_cancel_state);
    
    /* Move the money. */
    account_balances[p->to_acc] += p->dollars;
    account_balances[p->from_acc] -= p->dollars;
    
    /* End critical section. */
    pthread_setcancelstate (old_cancel_state, NULL);
    return (void *)0; //constante de puntero nulo
}

int main(int argc, char const *argv[])
{
    pthread_t hilo;
    
    struct accounts cuentas;

    /*las variables son las posiciones del struct de cuentas */
    cuentas.from_acc = 0;
    cuentas.to_acc = 1;
    cuentas.dollars = 50000;

    /*se crea un array de cuentas*/
    float accounts[2];
    /*igualamos a la variable global */
    account_balances=accounts;
    account_balances[cuentas.from_acc] = 50000;
    account_balances[cuentas.to_acc] = 10000;

    
    /* Se imprimen los valores de las variables antes de invocar a la funcion*/
    printf("\n Valores iniciales \n"); 
    printf("Valor inicial de la cuenta from_acc: %f.2 \n",account_balances[cuentas.from_acc]);
    printf("Valor inicial de la cuenta to_acc: %f.2\n",account_balances[cuentas.to_acc]);
    
    /*creamos el hilo*/
 
    pthread_create(&hilo,NULL,&process_transaction,&cuentas);

    /*tratamos de cancelar el hilo*/
    printf("Se trata de cancelar el hilo\n");
    pthread_cancel(hilo);
    /*se espera al hilo*/
    sleep(1);

    /* se espera a que el hilo termine y se almacena su estado de salida 
       usando la pthread_join que toma 2 argumentos, id del hilo y puntero nulo (void *) */ 

    void * nulo; 
    int estado_final=0;
    estado_final=pthread_join(hilo,nulo);

    printf("Comprobando estado final del hilo/n  EXITO =0 , FALLO != 0 \n ");
    if(estado_final==0)
      printf("EXITO");
    else
      printf("FALLO");  

    printf("Valores finales de las cuentas luego de la transaccion\n");
    printf("Valor final de from_acc: %f.2\n",account_balances[cuentas.from_acc]);
    printf("Valor final de to_acc: %f.2\n",account_balances[cuentas.to_acc]);

    return 0;
}
