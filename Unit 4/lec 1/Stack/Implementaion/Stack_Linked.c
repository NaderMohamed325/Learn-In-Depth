#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct Node {
    int data;           /**< Data stored in the node */
    struct Node* next;  /**< Pointer to the next node */
} Node;

// Define a structure for the stack
typedef struct {
    Node* top;  /**< Pointer to the top node of the stack */
} Stack;

/**
 * @brief Creates a new node with the given data.
 *
 * This function dynamically allocates memory for a new node and initializes its data and next pointer.
 *
 * @param data The data to be stored in the new node.
 * @return A pointer to the newly created node.
 */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Creates a new stack.
 *
 * This function dynamically allocates memory for a new stack structure and initializes its top pointer to NULL.
 *
 * @return A pointer to the newly created stack.
 */
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

/**
 * @brief Checks if the stack is empty.
 *
 * @param stack Pointer to the stack.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

/**
 * @brief Pushes an element onto the stack.
 *
 * This function creates a new node with the given data and pushes it onto the top of the stack.
 *
 * @param stack Pointer to the stack.
 * @param data The data to be pushed onto the stack.
 */
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

/**
 * @brief Pops an element from the stack.
 *
 * This function removes and returns the top element from the stack.
 *
 * @param stack Pointer to the stack.
 * @return The data of the element popped from the stack.
 */
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

/**
 * @brief Returns the top element of the stack without removing it.
 *
 * @param stack Pointer to the stack.
 * @return The data of the top element of the stack.
 */
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

/**
 * @brief Destroys the stack and frees its memory.
 *
 * This function deallocates the memory used by the stack and its nodes.
 *
 * @param stack Pointer to the stack to be destroyed.
 */
void destroyStack(Stack* stack) {
    while (stack->top != NULL) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);
}

int main() {
    Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Top element of stack: %d\n", peek(stack));

    printf("Popping elements: ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");

    destroyStack(stack);

    return 0;
}
