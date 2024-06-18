
# Queue Implementation in C

This repository contains a C implementation of a queue data structure. It includes a circular queue implemented with dynamic memory allocation, as well as a queue implemented using two stacks.

## Simple Queue 

![image](https://github.com/NaderMohamed325/IEEE--Task/assets/112278447/c7a82481-3854-4a53-8946-4026fa9cfccf)


### Functions:

1. `Create_Queue(unsigned int size)`
   - Creates a new queue of the specified size.
   - Parameters:
     - `size`: The size of the queue to be created.
   - Returns:
     - A pointer to the newly created queue if successful, otherwise NULL.

2. `Enqueue(Queue_t *q, int val)`
   - Enqueues a value into the queue.
   - Parameters:
     - `q`: Pointer to the queue.
     - `val`: The value to be enqueued.
   - Returns:
     - void

3. `Dequeue(Queue_t *q)`
   - Dequeues a value from the queue.
   - Parameters:
     - `q`: Pointer to the queue.
   - Returns:
     - The dequeued value if successful, otherwise -1.

4. `Display(Queue_t *q)`
   - Displays the elements of the queue.
   - Parameters:
     - `q`: Pointer to the queue.
   - Returns:
     - void
---
![image](https://github.com/NaderMohamed325/IEEE--Task/assets/112278447/2072c060-097e-44ae-80d4-c77421ceb27d)

     

## Queue Implemented with Two Stacks 

### Functions:

1. `Create_Q2S(int size)`
   - Creates a new queue implemented using two stacks.
   - Parameters:
     - `size`: The size of the queue.
   - Returns:
     - A pointer to the newly created queue if successful, otherwise NULL.

2. `QS_Enqueue(Queue_2Stack_t *qs, int val)`
   - Enqueues an element into the queue.
   - Parameters:
     - `qs`: Pointer to the queue.
     - `val`: The value to be enqueued.
   - Returns:
     - void

3. `QS_Dequeue(Queue_2Stack_t *qs)`
   - Dequeues an element from the queue.
   - Parameters:
     - `qs`: Pointer to the queue.
   - Returns:
     - The dequeued element if successful, otherwise -1.

---
![image](https://github.com/NaderMohamed325/IEEE--Task/assets/112278447/7167644d-296e-4e01-96e3-43ba65dbeb67)

## Usage:

To use the queue implementations, include the respective header file (`Queue.h`) in your C program.

Example usage:
```c
#include <stdio.h>
#include "Queue.h"

int main() {
    // Create a queue with size 10
    Queue_t *queue = Create_Queue(10);
    
    // Enqueue elements
    Enqueue(queue, 5);
    Enqueue(queue, 10);
    
    // Dequeue element
    int val = Dequeue(queue);
    printf("Dequeued element: %d\n", val);
    
    // Display elements
    Display(queue);
    
    // Destroy the queue
    Destroy(queue);
    
    return 0;
}
```

