#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
   Struct and Library for queue and processes that will be later implemented
*/

/** Constructor and destructor functions
  * Builder - Receives data and returns built data
  * Destroyer - Receives a die and destroys that die */
typedef void *(*queue_node_constructor_fn)(void *);
typedef void (*queue_node_destructor_fn)(void *);

/* Our queue consists of several nodes, which have a data and a pointer to the next node */
typedef struct queue_node_t
{
     void *data;
     struct queue_node_t *next;
} queue_node_t;

/* Nickname for queue node pointer */
typedef queue_node_t *queue_iterator_t;

/* Queue has front and back pointer
Constructor and destructor function, in addition to its size */
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
     char name[30]; /*Process name*/
     char pid[20]; /* Unique integer identifier for each process */
     int time; /*CPU time required by the process to complete its execution*/
     int final_time; /*Final time returned in the output*/
} process;

/**Initialize queue**/
void queue_initialize(queue_t **q, queue_node_constructor_fn constructor,
                       queue_node_destructor_fn destructor);
/**Destroy queue**/
void queue_delete(queue_t **q);

/* Unqueue element - Remove element from the front of the queue */
void queue_pop(queue_t *q);

/* Queue element - Inserts the element at the back of the queue */
void queue_push(queue_t *q, void *data);

/* Return to the front of the queue */
void *queue_front(queue_t *q);

/* Returns the size of the queue */
size_t queue_size(queue_t *q);

/* Returns whether the queue is empty or not */
size_t queue_empty(queue_t *q);

/*Function adapted from malloc*/
void *mallocx(size_t n);

/*Build process*/
void *constructor_process(void *data);

/* Destroy process */
void destructor_process(void *data);

/* Register process in the queue */
void cadastra_process(process *p);

/* Print the process */
void print_process(const process *p);


#endif /* FILA_H*/
