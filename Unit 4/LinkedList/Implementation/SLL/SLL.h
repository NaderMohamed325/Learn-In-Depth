#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
/**
 * @file Linked_List.h
 * @brief Header file for singly linked list manipulation.
 */

/**
 * @struct node
 * @brief A structure representing a node in a singly linked list.
 */
struct node {
    int data;          ///< Data stored in the node.
    struct node *next; ///< Pointer to the next node in the list.
};

/**
 * @typedef node_t
 * @brief A typedef for the node structure to simplify usage.
 */
typedef struct node node_t;

/**
 * @brief Inserts a new node at the head of a linked list.
 *
 * This function creates a new node, prompts the user for data, and inserts it
 * at the beginning of a linked list. If memory allocation fails, it prints an
 * error message.
 *
 * @param List A pointer to a pointer to the head of the linked list.
 */
void InsertAtHead(node_t **List);

/**
 * @brief Inserts a new node at the end of a linked list.
 *
 * This function creates a new node, prompts the user for data, and inserts it
 * at the end of a linked list. If memory allocation fails, it prints an error
 * message.
 *
 * @param List A pointer to a pointer to the head of the linked list.
 */
void InsertAtEnd(node_t **List);

/**
 * @brief Calculates the size of a singly linked list.
 *
 * This function traverses the linked list and counts the number of nodes
 * to determine the size of the list.
 *
 * @param List - Pointer to a pointer to the head of the linked list.
 * @return The size of the linked list.
 */
int List_Size(node_t **List);

/**
 * @brief Deallocates memory and destroys a singly linked list.
 *
 * This function deallocates memory for each node in the linked list and
 * sets the list's head pointer to NULL, effectively destroying the list.
 *
 * @param List - Pointer to a pointer to the head of the linked list.
 */
void Destroy_List(node_t **List);

/**
 * @brief Inserts a new node with user-entered data after a specific position in the linked list.
 *
 * This function allows the user to enter the data for the new node and inserts it after
 * the specified position in the linked list. It handles cases where the list is empty,
 * and it checks for invalid positions.
 *
 * @param List - Pointer to a pointer to the head of the linked list.
 * @param index - The position (index) after which the new node should be inserted.
 */
void InsertAfterPosition(node_t **List, int index);

/**
 * @brief Deletes the first node from a linked list.
 *
 * @param List  A pointer to the pointer to the head of the linked list.
 */
void DeleteAtHead(node_t **List);

/**
 * @brief Deletes a node at the specified index from a linked list.
 *
 * @param List  A pointer to the pointer to the head of the linked list.
 * @param index The index of the node to be deleted (0-based).
 */
void DeleteN_node(node_t **List, int index);

/**
 * @brief Displays the contents of a linked list.
 *
 * @param List  A pointer to the head of the linked list.
 */
void Display_List(node_t *List);

#endif /* LINKED_LIST_H */
