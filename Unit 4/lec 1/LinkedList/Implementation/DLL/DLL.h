#ifndef DLL_H
#define DLL_H
#include <stdlib.h>
#include <stdio.h>
#define or ||
// Define the structure of a node in the doubly linked list
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node_t;

// Function prototypes

/**
 * Inserts a new node with the value A at the head of the doubly linked list.
 *
 * @param List A pointer to a pointer to the doubly linked list.
 * @param A    The value to be inserted in the new node.
 */
void InsertAtHead(node_t** List, int A);

/**
 * Inserts a new node with the value A at the end of the doubly linked list.
 *
 * @param List A pointer to a pointer to the doubly linked list.
 * @param A    The value to be inserted in the new node.
 */
void Insert_End(node_t** List, int A);

/**
 * Returns the number of nodes in the doubly linked list.
 *
 * @param List A pointer to a pointer to the doubly linked list.
 * @return The number of nodes in the list.
 */
int List_size(node_t** List);

/**
 * Inserts a new node with the value A at the specified index in the doubly linked list.
 *
 * @param List  A pointer to a pointer to the doubly linked list.
 * @param A     The value to be inserted in the new node.
 * @param index The index at which the new node should be inserted.
 */
void Insert_NA(node_t** List, int A, int index);

/**
 * Inserts a new node with the value A at the specified index in the doubly linked list.
 * Calls Insert_NA with index decremented by 1.
 *
 * @param List  A pointer to a pointer to the doubly linked list.
 * @param A     The value to be inserted in the new node.
 * @param index The index at which the new node should be inserted.
 */
void Insert_NB(node_t** List, int A, int index);

/**
 * Deletes the first node (head) from the doubly linked list.
 *
 * @param List A pointer to a pointer to the doubly linked list.
 */
void Delete_Head(node_t** List);

/**
 * Deletes the last node from the doubly linked list.
 *
 * @param List A pointer to a pointer to the doubly linked list.
 */
void Delete_end(node_t** List);

/**
 * Deletes the node at the specified index in the doubly linked list.
 *
 * @param List  A pointer to a pointer to the doubly linked list.
 * @param index The index of the node to be deleted.
 */
void Delete_N(node_t** List, int index);

#endif // DLL_H
