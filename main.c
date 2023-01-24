#include "queue.h"

int main(void)
{
     int num, quantity;
     /*Declare the queue*/
     queue_t *queue;
     /*Declare process p*/
     process p;
     /* Initialize queue */
     queue_initialize(&queue, constructor_process, destructor_process);

     /* Individual counter for each process */
     p.final_time = 0;
     /* Total time counter */
     int count = 0;

     /* Get number of processes and quantum value */
     scanf("%d", &num);
     scanf("%d", &quantum);

     /* Receive processes and put them at the back of the queue */
     for (int i = 0; i < num; i++)
     {
         cadastra_process(&p);
         queue_push(queue, &p);
     }

     /*Each iteration represents a period in which a process uses the quantum*/
     for (int i = 0; queue->size > 0; i++)
     {
         /* Use the front element of the list */
         p = *(process *)queue_front(queue);

         /* If the difference between process time and individual time
         from it counted until the moment is smaller than the value of the quantum:
         Total time counter adds difference, Final time gets total time value
         Prints the process and removes it from the queue, so it goes to the next iteration */
         if (p.time - p.final_time <= quantum)
         {
             cont += (p.time - p.final_time);
             p.final_time = cont;
             print_process(&p);
             queue_pop(queue);
             continues;
         }
         /* Otherwise, increment the quantum of the general and individual counters of the process */
         else
         {
             count += quantity;
             p.final_time += quantum;
         }

         /* Dequeue term and insert it at the back of the queue */
         queue_pop(queue);
         queue_push(queue, &p);
     }
     /* Destroy the queue, eliminate memory space */
     queue_delete(&queue);
     return 0;
}
