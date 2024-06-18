//
// Created by xcite on 4/15/2024.
//

#include "Stack.h"

/**
 * @brief Creates a new stack.
 *
 * This function dynamically allocates memory for a new stack structure and its underlying array.
 *
 * @param capacity The maximum capacity of the stack.
 * @return A pointer to the newly created stack, or NULL if memory allocation fails or capacity is <= 0.
 */
Stack *Create_Stack(int capacity) {
    if (capacity <= 0) {
        return NULL;
    }

    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (NULL == stack) {
        return NULL; // Return NULL if memory allocation fails
    } else {
        // Allocate memory for the array inside the stack
        stack->array = (int *) malloc(sizeof(int) * capacity);
        if (NULL == stack->array) {
            free(stack); // Free the allocated memory for stack if array allocation fails
            return NULL;
        }
        stack->max = capacity; // Set the capacity of the stack
        stack->top = -1; // Initialize top of stack to -1 (empty stack)
        return stack;
    }
}

/**
 * @brief Pushes an element onto the stack.
 *
 * @param stack Pointer to the stack.
 * @param element The element to be pushed onto the stack.
 * @return 1 if the push operation is successful, 0 otherwise.
 */
int push(Stack *stack, int element) {
    if (stack == NULL) {
        printf("Invalid stack pointer\r\n");
        return 0;
    } else if(stack->top + 1 == stack->max){
        printf("Stack is Full\r\n");
        return 0;
    }
    stack->array[++stack->top] = element;
    return 1;
}

/**
 * @brief Pops an element from the stack.
 *
 * @param stack Pointer to the stack.
 * @return The element popped from the stack, or 0 if the stack is empty.
 */
int pop(Stack *stack){
    if (stack == NULL) {
        printf("Invalid stack pointer\r\n");
        return 0;
    } else if(stack->top == -1){
        printf("Stack is Empty\r\n");
        return 0;
    }
    return stack->array[stack->top--];
}

/**
 * @brief Returns the top element of the stack without removing it.
 *
 * @param stack Pointer to the stack.
 * @return The top element of the stack, or 0 if the stack is empty.
 */
int peek(Stack *stack){
    if (stack == NULL) {
        printf("Invalid stack pointer\r\n");
        return 0;
    } else if(stack->top == -1){
        printf("Stack is Empty\r\n");
        return 0;
    }
    return stack->array[stack->top];
}

/**
 * @brief Destroys the stack and frees its memory.
 *
 * This function deallocates the memory used by the stack and its underlying array.
 *
 * @param stack Pointer to the stack to be destroyed.
 */
void Destroy(Stack *stack){
    free(stack->array);
    free(stack);
}

/**
 * @brief Checks if the stack is empty.
 *
 * @param stack Pointer to the stack.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

/**
 * @brief Checks if the stack is full.
 *
 * @param stack Pointer to the stack.
 * @return 1 if the stack is full, 0 otherwise.
 */
int isFull(Stack *stack) {
    return stack->top == stack->max - 1;
}