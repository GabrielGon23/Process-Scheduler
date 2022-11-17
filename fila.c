#include "fila.h"

/*

    Implementa as funcoes da fila e a insercao de processos

*/

/*Inicializa a fila, recebe a fila,construtor e destrutor*/
void queue_initialize(queue_t **q, queue_node_constructor_fn constructor,
                      queue_node_destructor_fn destructor)
{
    (*q) = mallocx(sizeof(queue_t)); /*Aloca espaco para lista*/
    (*q)->back = NULL;
    (*q)->front = NULL;              /*Frente e traseira apontam para NULL inicialmente*/
    (*q)->size = 0;                  /*Tamanho da lista inicia 0*/
    (*q)->constructor = constructor; /*Recebe funcao construtora e destrutora*/
    (*q)->destructor = destructor;
}

/*Deleta a fila por inteiro e libera espaco de memoria
Recebe ponteiro para ponteiro de fila pois queremos modificar ponteiro original
Enquanto fila nao estiver vazia, desinfileiro elemento*/
void queue_delete(queue_t **q)
{
    while (!queue_empty(*q))
    {
        queue_pop(*q);
    }
    free(*q);
    *q = NULL;
}

/*Desinfileirar - Equivale a remocao na cabeca, retira o elemento da frente da fila*/
void queue_pop(queue_t *q)
{
    assert(!queue_empty(q));
    /*Ponteiro auxiliar aponta para frente da fila*/
    queue_iterator_t it = q->front;
    /*Caso apenas um elemento, frente e traseira apontam para NULL*/
    if (queue_size(q) == 1)
    {
        q->front = NULL;
        q->back = NULL;
    }
    /*Caso tenha mais de um elemento,front passa a ser proximo elemento*/
    else
    {
        q->front = q->front->next;
    }
    /*Elimino campo data do iterador, libera espaco e decrementa tamanho da lista*/
    q->destructor(it->data);
    free(it);
    q->size--;
}

/*Retorna dado do elemento na frente da fila*/
void *queue_front(queue_t *q)
{
    assert(!queue_empty(q));
    return (q->front->data);
}

/*Enfileirar elemento - Equivale a insercao na cauda de uma lista
Recebe a fila e dado a ser enfileirado*/
void queue_push(queue_t *q, void *data)
{
    /*Cria novo no e constroi dado*/
    queue_node_t *new_node = mallocx(sizeof(queue_node_t));
    new_node->data = q->constructor(data);
    new_node->next = NULL;
    /*Se a fila vazia,ponteiro da frente aponta para novo no*/
    if (queue_size(q) == 0)
    {
        q->front = new_node;
    }
    /*Caso contrario, ponteiro da traseira next aponta para novo no*/
    else
    {
        q->back->next = new_node;
    }
    /*Back next passa a ser novo no*/
    q->back = new_node;
    /*Incrementa tamanho da lista*/
    q->size++;
}

/*Retorna o tamanho da lista*/
size_t queue_size(queue_t *q)
{
    return (q->size);
}

/*Verifica se a fila esta vazia
Retorna verdadeiro se a fila esta vazia, e falso caso contrario*/
size_t queue_empty(queue_t *q)
{
    return queue_size(q) == 0 ? 1 : 0;
}

/*Funcao adaptada de malloc, se ponteiro for NULL imprime erro*/
void *mallocx(size_t n)
{
    void *ptr = malloc(n);
    if (ptr == NULL)
    {
        printf("Erro mallocx");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

/* **************	Implementação dos processos 	******************* */

/*Indicar para lista como construir uma pessoa
Recebe ponteiro para dado generico
Aloca espaco para 1 pessoa
memcpy para copiar conteudo de data para ptr,no tamanho de pessoa*/
void *constructor_process(void *data)
{
    void *ptr = mallocx(sizeof(process));
    memcpy(ptr, data, sizeof(process));
    return ptr;
}

/*Funcao para destruir processo,libera o dado alocado*/
void destructor_process(void *data)
{
    free(data);
}

/*Funcao para ler processo*/
void cadastra_process(process *p)
{
    scanf("%s", p->name);
    scanf("%s", p->pid);
    scanf("%d", &p->time);
}

/*Funcao para imprimir processo da lista*/ 
void imprime_process(const process *p)
{
    printf("%s %s %d ms\n", p->name, p->pid, p->final_time);
}
