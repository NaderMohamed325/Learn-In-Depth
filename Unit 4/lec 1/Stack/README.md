# Stack Implementation in C

## Overview
This is a simple implementation of a stack data structure in C. A stack is a linear data structure that follows the Last In, First Out (LIFO) principle, meaning that the last element added to the stack is the first one to be removed. This implementation provides basic stack operations such as push, pop, peek, and destroy.

## Files
- `Stack.h`: Header file containing the structure definition and function prototypes for the stack implementation.
- `Stack.c`: Source file containing the implementation of the stack functions.


## Stack Operations
- `Stack *Create_Stack(int capacity)`: Creates a new stack with the given capacity.
- `int push(Stack *stack, int element)`: Pushes an element onto the stack.
- `int pop(Stack *stack)`: Pops an element from the stack.
- `int peek(Stack *stack)`: Returns the top element of the stack without removing it.
- `void Destroy(Stack *stack)`: Destroys the stack and frees its memory.

## How to Use
1. Include the `Stack.h` header file in your C program.
2. Create a new stack using `Create_Stack()` function, passing the desired capacity as an argument.
3. Use `push()` to add elements to the stack, `pop()` to remove elements, and `peek()` to inspect the top element without removing it.
4. When you're done using the stack, call `Destroy()` to free the allocated memory.

## Example
```c
#include <stdio.h>
#include "Stack.h"

int main() {
    Stack *stack = Create_Stack(5); // Create a stack with capacity 5
    push(stack, 10); // Push 10 onto the stack
    push(stack, 20); // Push 20 onto the stack
    push(stack, 30); // Push 30 onto the stack

    printf("Top element: %d\n", peek(stack)); // Peek the top element
    printf("Popped element: %d\n", pop(stack)); // Pop an element

    Destroy(stack); // Destroy the stack
    return 0;
}
