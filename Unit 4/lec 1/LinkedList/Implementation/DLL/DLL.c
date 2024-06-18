

#include "DLL.h"

/**
 * Inserts a new node with the value A at the head of the doubly linked list.
 *
 * @param List A pointer to a pointer to the doubly linked list.
 * @param A    The value to be inserted in the new node.
 */
void InsertAtHead(node_t **List, int A) {
    node_t *temp = (node_t *) malloc(sizeof(node_t));
    if (temp == NULL) {
        printf("Can't allocate memory\n");
    } else {
        temp->data = A;
        temp->right = *List;
        temp->left = NULL;

        if (*List != NULL) {
            (*List)->left = temp;
        }

        *List = temp;
    }
}

/**
 * Inserts a new node with the value A at the end of the doubly linked list.
 *
 * @param List A pointer to a pointer to the doubly linked list.
 * @param A    The value to be inserted in the new node.
 */
void Insert_End(node_t **List, int A) {
    node_t *temp = (node_t *) malloc(sizeof(node_t));
    if (temp == NULL) {
        printf("Can't allocate memory\n");
    } else {
        temp->data = A;
        node_t *counter = *List;
        while (counter->right != NULL)
            counter = counter->right;

        temp->left = counter;
        temp->right = NULL;
        counter->right = temp;
    }
}

/**
 * Returns the number of nodes in the doubly linked list.
 *
 * @param List A pointer to a pointer to the doubly linked list.
 * @return The number of nodes in the list.
 */
int List_size(node_t **List) {
    int counter = 0;
    node_t *temp = *List;
    while (temp->right != NULL) {
        counter++;
        temp = temp->right;
    }
    return counter;
}

/**
 * Inserts a new node with the value A at the specified index in the doubly linked list.
 *
 * @param List  A pointer to a pointer to the doubly linked list.
 * @param A     The value to be inserted in the new node.
 * @param index The index at which the new node should be inserted.
 */
void Insert_NA(node_t **List, int A, int index) {
    if (index < 0 or index > List_size(List))
        printf("Invalid address\n");
    else {
        node_t *temp = (node_t *) malloc(sizeof(node_t));
        if (temp == NULL)
            printf("Can't allocate memory\n");
        else {
            temp->data = A;
            int counter = index;
            node_t *co = *List;
            while (counter--) {
                co = co->right;
            }
            if (co->right != NULL) {
                temp->right = co->right;
                temp->left = co;
                co->right->left = temp;
                co->right = temp;
            } else {
                temp->left = co;
                temp->right = NULL;
                co->right = temp;
            }
        }
    }
}

/**
 * Inserts a new node with the value A at the specified index in the doubly linked list.
 * Calls Insert_NA with index decremented by 1.
 *
 * @param List  A pointer to a pointer to the doubly linked list.
 * @param A     The value to be inserted in the new node.
 * @param index The index at which the new node should be inserted.
 */
void Insert_NB(node_t **List, int A, int index) {
    if (index == 0)
        InsertAtHead(List, A);
    else
        Insert_NA(List, A, index - 1);
}

/**
 * Deletes the first node (head) from the doubly linked list.
 *
 * @param List A pointer to a pointer to the doubly linked list.
 */
void Delete_Head(node_t **List) {
    if (*List != NULL) {
        node_t *temp = *List;
        (*List) = (*List)->right;
        if (*List != NULL) {
            (*List)->left = NULL;
        }
        free(temp);
    }
}

/**
 * Deletes the last node from the doubly linked list.
 *
 * @param List A pointer to a pointer to the doubly linked list.
 */
void Delete_end(node_t **List) {
    node_t *temp = *List;
    while (temp->right != NULL)
        temp = temp->right;
    if (temp->left != NULL) {
        temp->left->right = NULL;
    }
    free(temp);
}

/**
 * Deletes the node at the specified index in the doubly linked list.
 *
 * @param List  A pointer to a pointer to the doubly linked list.
 * @param index The index of the node to be deleted.
 */
void Delete_N(node_t **List, int index) {
    if (index < 0 or index > List_size(List)) {
        printf("Invalid position\n");
    } else {
        int counter = index;
        node_t *temp = *List;
        while (counter--) {
            temp = temp->right;
        }
        if (index == 0)
            Delete_Head(List);
        else {
            if (temp->right != NULL) {
                node_t *pre = temp->left;
                node_t *after = temp->right;

                pre->right = after;
                after->left = pre;
                temp->right = NULL;
                temp->left = NULL;
                free(temp);
            } else {
                Delete_end(List);
            }
        }
    }
}
