//
// Created by Nader on 4/27/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include "../Stack/Implementaion/Stack.h"
#include "../LinkedList/Implementation/SLL/SLL.h"

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

typedef struct Queue {
    int *pointer;
    int size;
    int rear;
    int front;
} Queue_t;
typedef struct {
    Stack s1;
    Stack s2;
    int size;
} Queue_2Stack_t;


typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} QNode;


/**
 @param size: The size of the queue to be created.
 @brief Creates a new queue of the specified size.
 @return A pointer to the newly created queue if successful, otherwise NULL.
 */
Queue_t
*

Create_Queue(unsigned int size);

/**@param q: Pointer to the queue.
 @param val: The value to be enqueued.
 @brief Enqueues a value into the queue.
 @return void
 */
void Enqueue(Queue_t *q, int val);

/**
 @param q: Pointer to the queue.
 @brief Dequeues a value from the queue.
 @return The dequeued value if successful, otherwise -1.
 */
int Dequeue(Queue_t *q);

/**
 @param q: Pointer to the queue.
 @brief Displays the elements of the queue.
 @return void
 */
void Display(Queue_t *q);

/**
 * @brief Creates a new queue implemented using two stacks.
 *
 * This function creates a new Queue_2Stack_t structure with two stacks, s1 and s2.
 *
 * @param size The size of the queue.
 * @return A pointer to the newly created queue if successful, otherwise NULL.
 */
Queue_2Stack_t *Create_Q2S(int size);

/**
 * @brief Enqueues an element into the queue.
 *
 * If the first stack (s1) is not full, the element is pushed onto it.
 *
 * @param qs Pointer to the queue.
 * @param val The value to be enqueued.
 * @return void
 */
void QS_Enqueue(Queue_2Stack_t *qs, int val);

/**
 * @brief Dequeues an element from the queue.
 *
 * If both stacks (s1 and s2) are empty, the queue is empty.
 * If the second stack (s2) is not empty, the element is popped from it.
 * Otherwise, elements are moved from s1 to s2, then the front element is popped from s2.
 *
 * @param qs Pointer to the queue.
 * @return The dequeued element if successful, otherwise -1.
 */
int QS_Dequeue(Queue_2Stack_t *qs);


#endif //QUEUE_QUEUE_H
