#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a stack
typedef struct {
    int *array; // Array to store elements
    int top;    // Index of the top element
    int max;    // Maximum capacity of the stack
} Stack;

// Function prototypes

/**
 * @brief Creates a new stack.
 *
 * This function dynamically allocates memory for a new stack structure and its underlying array.
 *
 * @param capacity The maximum capacity of the stack.
 * @return A pointer to the newly created stack, or NULL if memory allocation fails or capacity is <= 0.
 */
Stack *Create_Stack(int capacity);

/**
 * @brief Pushes an element onto the stack.
 *
 * @param stack Pointer to the stack.
 * @param element The element to be pushed onto the stack.
 * @return 1 if the push operation is successful, 0 otherwise.
 */
int push(Stack *stack, int element);

/**
 * @brief Pops an element from the stack.
 *
 * @param stack Pointer to the stack.
 * @return The element popped from the stack, or 0 if the stack is empty.
 */
int pop(Stack *stack);

/**
 * @brief Returns the top element of the stack without removing it.
 *
 * @param stack Pointer to the stack.
 * @return The top element of the stack, or 0 if the stack is empty.
 */
int peek(Stack *stack);

/**
 * @brief Destroys the stack and frees its memory.
 *
 * This function deallocates the memory used by the stack and its underlying array.
 *
 * @param stack Pointer to the stack to be destroyed.
 */
void Destroy(Stack *stack);


/**
 * @brief Checks if the stack is empty.
 *
 * @param stack Pointer to the stack.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isEmpty(Stack *stack) ;
/**
 * @brief Checks if the stack is full.
 *
 * @param stack Pointer to the stack.
 * @return 1 if the stack is full, 0 otherwise.
 */
int isFull(Stack *stack) ;

#endif //STACK_STACK_H
