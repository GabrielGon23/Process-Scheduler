#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
  Struct e Biblioteca para fila e processos que serao posteriormente implementados
*/

/**Funcoes construtora e destrutora
 * Construtora - Recebe dado e retorna dado construido
 * Destrutora - Recebe um dado e destroi esse dado */
typedef void *(*queue_node_constructor_fn)(void *);
typedef void (*queue_node_destructor_fn)(void *);

/*A nossa fila consiste de varios nos, que possuem um dado e um ponteiro para o proximo no*/
typedef struct queue_node_t
{
    void *data;
    struct queue_node_t *next;
} queue_node_t;

/* Apelido para ponteiro de no da fila*/
typedef queue_node_t *queue_iterator_t;

/*A fila possui ponteiro para frente e traseira
Funcao construtora e destrutora,alem do tamanho dela*/
typedef struct queue_t
{
    queue_node_t *front;
    queue_node_t *back;
    queue_node_constructor_fn constructor;
    queue_node_destructor_fn destructor;
    size_t size;
} queue_t;

typedef struct process
{
    char name[30]; /*Nome do processo*/
    char pid[20];  /*Identificador inteiro único para cada processo*/
    int time;      /*Tempo de CPU requerido pelo processo para que finalize sua execução*/
    int final_time;        /*Final time retornado no output*/
} process;

/**Inicializa fila**/
void queue_initialize(queue_t **q, queue_node_constructor_fn constructor,
                      queue_node_destructor_fn destructor);
/**Destroi fila**/
void queue_delete(queue_t **q);

/*Desinfileira elemento - Retira elemento da frente da fila*/
void queue_pop(queue_t *q);

/*Enfileira elemento - Insere o elemento na traseira da fila*/
void queue_push(queue_t *q, void *data);

/*Retorna a frente da fila*/
void *queue_front(queue_t *q);

/*Retorna o tamanho da fila*/
size_t queue_size(queue_t *q);

/*Retorna se a fila esta vazia ou nao*/
size_t queue_empty(queue_t *q);

/*Funcao adaptada de malloc*/
void *mallocx(size_t n);

/*Construir processo*/
void *constructor_process(void *data);

/*Destruir processo*/
void destructor_process(void *data);

/*Cadastra processo na fila*/
void cadastra_process(process *p);

/*Imprime o processo*/
void imprime_process(const process *p);


#endif /* FILA_H*/
