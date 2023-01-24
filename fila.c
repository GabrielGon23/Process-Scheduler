#include "queue.h"

/*

     Implements queue functions and process insertion

*/

/* Initialize the queue, colect the queue, constructor and destructor */
void queue_initialize(queue_t **q, queue_node_constructor_fn constructor,
                       queue_node_destructor_fn destructor)
{
     (*q) = mallocx(sizeof(queue_t)); /* Allocate area for list */
     (*q)->back = NULL;
     (*q)->front = NULL; /* Front and back point to NULL initially */
     (*q)->size = 0; /*List size starts at 0*/
     (*q)->constructor = constructor; /* Collect constructor and destructor function */
     (*q)->destructor = destructor;
}

/*Deletes the entire queue and frees up memory space
Get pointer to queue pointer because we want to modify original pointer
While queue is not empty, unqueue element */
void queue_delete(queue_t **q)
{
     while (!queue_empty(*q))
     {
         queue_pop(*q);
     }
     free(*q);
     *q = NULL;
}

/*Dequeue - Equivalent to removal in the head, removes the element from the front of the queue*/
void queue_pop(queue_t *q)
{
     assert(!queue_empty(q));
     /*Auxiliary pointer points to the front of the queue*/
     queue_iterator_t it = q->front;
     /*If only one element, front and back point to NULL*/
     if (queue_size(q) == 1)
     {
         q->front = NULL;
         q->back = NULL;
     }
     /* If you have more than one element, front becomes the next element */
     else
     {
         q->front = q->front->next;
     }
     /* I delete the date field from the iterator, frees up space and decreases the size of the list */
     q->destructor(it->data);
     free(it);
     q->size--;
}

/* Returns data from the element at the front of the queue */
void *queue_front(queue_t *q)
{
     assert(!queue_empty(q));
     return (q->front->data);
}

/*Enqueue element - Equivalent to insertion at the tail of a list
Receive the queue and data to be queued */
void queue_push(queue_t *q, void *data)
{
     /*Create new node and build data*/
     queue_node_t *new_node = mallocx(sizeof(queue_node_t));
     new_node->data = q->constructor(data);
     new_node->next = NULL;
     /* If queue is empty, front pointer points to new node */
     if (queue_size(q) == 0)
     {
         q->front = new_node;
     }
     /* Otherwise, pointer of back next points to new node */
     else
     {
         q->back->next = new_node;
     }
     /*Back next becomes new no*/
     q->back = new_node;
     /*Increase the size of the list*/
     q->size++;
}

/* Returns the size of the list */
size_t queue_size(queue_t *q)
{
     return(q->size);
}

/* Check if the queue is empty
Returns true if the queue is empty, false otherwise */
size_t queue_empty(queue_t *q)
{
     return queue_size(q) == 0 ? 1:0;
}

/*Function adapted from malloc, if pointer is NULL prints error*/
void *mallocx(size_t n)
{
     void *ptr = malloc(n);
     if (ptr == NULL)
     {
         printf("Error mallocx");
         exit(EXIT_FAILURE);
     }
     return ptr;
}

/* ************** Implementation of processes ******************* */

/* Indicate to the list how to "build" a person
Get pointer to generic data
Allocates space for 1 person
memcpy to copy date content to ptr, in person size */
void *constructor_process(void *data)
{
     void *ptr = mallocx(sizeof(process));
     memcpy(ptr, data, sizeof(process));
     return ptr;
}

/* Function to destroy process, release allocated data */
void destructor_process(void *data)
{
     free(data);
}

/*Function to read process*/
void cadastra_process(process *p)
{
     scanf("%s", p->name);
     scanf("%s", p->pid);
     scanf("%d", &p->time);
}

/*Function to print process list*/
void print_process(const process *p)
{
     printf("%s %s %d ms\n", p->name, p->pid, p->final_time);
}
