#include "fila.h"

int main(void)
{
    int num, quantum;
    /*Declara a fila*/
    queue_t *fila;
    /*Declara processo p*/
    process p;
    /*Inicializa fila*/
    queue_initialize(&fila, constructor_process, destructor_process);

    /*Contador individual de cada processo*/
    p.final_time = 0;
    /*Contador de tempo total*/
    int cont = 0;

    /*Recebe numero de processos e valor do quantum*/
    scanf("%d", &num);
    scanf("%d", &quantum);

    /*Recebe processos e os coloca na traseira da fila*/
    for (int i = 0; i < num; i++)
    {
        cadastra_process(&p);
        queue_push(fila, &p);
    }

    /*Cada iteracao representa um periodo em que um processo utiliza o quantum*/
    for (int i = 0; fila->size > 0; i++)
    {
        /*Utiliza-se o elemento da frente da lista*/
        p = *(process *)queue_front(fila);

        /*Se a diferenca entre o time do processo e o tempo individual
        dele contado ate o momento for menor que valor do quantum:
        Contador do tempo total adiciona a diferenca, Final time recebe valor do tempo total
        Imprime o processo e o elimina da fila, assim segue para a proxima iteracao*/
        if (p.time - p.final_time <= quantum)
        {
            cont += (p.time - p.final_time);
            p.final_time = cont;
            imprime_process(&p);
            queue_pop(fila);
            continue;
        }
        /*Caso contrario, incrementa quantum ao contador geral e individual do processo */
        else
        {
            cont += quantum;
            p.final_time += quantum;
        }

        /*Desinfileira termo e o insere na traseira da fila*/
        queue_pop(fila);
        queue_push(fila, &p);
    }
    /*Destroi a fila,elimina espaco de memoria*/
    queue_delete(&fila);
    return 0;
}
