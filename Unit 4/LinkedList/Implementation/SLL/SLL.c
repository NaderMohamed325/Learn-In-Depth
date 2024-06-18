/**
 * @file Linked_List.c
 * @brief Implementation of functions for singly linked list manipulation.
 */

#include "SLL.h"


/**
 * @brief Inserts a new node at the head of a linked list.
 *
 * This function creates a new node, prompts the user for data, and inserts it
 * at the beginning of a linked list. If memory allocation fails, it prints an
 * error message.
 *
 * @param List A pointer to a pointer to the head of the linked list.
 */
void InsertAtHead(node_t **List) {
    struct node *Temp = (struct node *) malloc(sizeof(node_t));
    if (Temp == NULL) {
        printf("Memory allocation failed\n");
    } else {
        printf("Enter your data: ");
        scanf_s("%d", &Temp->data);
        if (*List == NULL) {
            *List = Temp;
            Temp->next = NULL;
        } else {
            Temp->next = *List;
            *List = Temp;
        }
    }
}

/**
 * @brief Inserts a new node at the end of a linked list.
 *
 * This function creates a new node, prompts the user for data, and inserts it
 * at the end of a linked list. If memory allocation fails, it prints an error
 * message.
 *
 * @param List A pointer to a pointer to the head of the linked list.
 */
void InsertAtEnd(node_t **List) {
    // Allocate memory for the new node
    struct node *Temp = (struct node *) malloc(sizeof(node_t));

    if (Temp == NULL) {
        printf("Memory allocation failed\n");
    } else {
        printf("Enter your data: ");
        scanf_s("%d", &Temp->data);

        if (*List == NULL) {
            // If the list is empty, make Temp the first node
            *List = Temp;
            Temp->next = NULL;
        } else {
            // Traverse the list to find the last node
            node_t *Last = *List;
            while (Last->next != NULL) {
                Last = Last->next;
            }

            // Insert the new node at the end
            Last->next = Temp;
            Temp->next = NULL;
        }
    }
}

/**
 * @brief Calculates the size of a singly linked list.
 *
 * This function traverses the linked list and counts the number of nodes
 * to determine the size of the list.
 *
 * @param List - Pointer to a pointer to the head of the linked list.
 * @return The size of the linked list.
 */
int List_Size(node_t **List) {
    int counter = 0;
    node_t *Temp = *List;
    while (Temp != NULL) {
        counter++;
        Temp = Temp->next;
    }
    return counter;
}

/**
 * @brief Deallocates memory and destroys a singly linked list.
 *
 * This function deallocates memory for each node in the linked list and
 * sets the list's head pointer to NULL, effectively destroying the list.
 *
 * @param List - Pointer to a pointer to the head of the linked list.
 */
void Destroy_List(node_t **List) {
    node_t *Temp = *List;
    while (Temp != NULL) {
        *List = (*List)->next;
        free(Temp);
        Temp = *List;
    }
}

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
void InsertAfterPosition(node_t **List, int index) {
    node_t *Temp = (node_t *) malloc(sizeof(node_t));
    if (Temp == NULL) {
        printf("Memory allocation failed\n");
    } else {
        printf("Enter your data: ");
        scanf_s("%d", &Temp->data);
        if (*List == NULL) {
            *List = Temp;
            Temp->next = NULL;
        } else {
            int size = List_Size(List);
            if (index > size || index < 0)
                printf("Invalid Position\n");
            else {
                node_t *P = *List;
                int counter = 0;
                while (counter < index) {
                    P = P->next;
                    counter++;
                }
                Temp->next = P->next;
                P->next = Temp;
            }
        }
    }
}

/**
 * @brief Deletes the first node from a linked list.
 *
 * @param List  A pointer to the pointer to the head of the linked list.
 */
void DeleteAtHead(node_t **List) {
    if (*List == NULL) {
        printf("List is empty\n");
    } else {
        node_t *Temp = *List;
        *List = (*List)->next;
        free(Temp);
    }
}

/**
 * @brief Deletes a node at the specified index from a linked list.
 *
 * @param List  A pointer to the pointer to the head of the linked list.
 * @param index The index of the node to be deleted (0-based).
 */
void DeleteN_node(node_t **List, int index) {
    if (*List == NULL) {
        printf("List is empty\n");
    } else if (index < 0) {
        printf("Invalid position\n");
    } else if (index == 0) {
        // Special case: deleting the first node
        node_t *temp = *List;
        *List = temp->next;
        free(temp);
    } else {
        int counter = index;
        node_t *temp = *List;
        while (counter-- > 1 && temp->next) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            printf("Invalid position\n");
        } else {
            node_t *lv = temp->next;
            temp->next = lv->next;
            free(lv);
        }
    }
}

/**
 * @brief Displays the contents of a linked list.
 *
 * @param List  A pointer to the head of the linked list.
 */
void Display_List(node_t *List) {
    node_t *temp = List;
    if (temp == NULL) {
        printf("The list is empty\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
