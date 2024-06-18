#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

typedef struct DoublyLinkedListNode DoublyLinkedListNode;
typedef struct DoublyLinkedList DoublyLinkedList;

struct DoublyLinkedListNode {
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
};

struct DoublyLinkedList {
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;
};

DoublyLinkedListNode* create_doubly_linked_list_node(int node_data) {
    DoublyLinkedListNode* node = malloc(sizeof(DoublyLinkedListNode));

    node->data = node_data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void insert_node_into_doubly_linked_list(DoublyLinkedList** doubly_linked_list, int node_data) {
    DoublyLinkedListNode* node = create_doubly_linked_list_node(node_data);

    if (!(*doubly_linked_list)->head) {
        (*doubly_linked_list)->head = node;
    } else {
        (*doubly_linked_list)->tail->next = node;
        node->prev = (*doubly_linked_list)->tail;
    }

    (*doubly_linked_list)->tail = node;
}

void print_doubly_linked_list(DoublyLinkedListNode* node, char* sep, FILE* fptr) {
    while (node) {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node) {
            fprintf(fptr, "%s", sep);
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */


void Insert_End(DoublyLinkedListNode **List, int A) {
    DoublyLinkedListNode *temp = (DoublyLinkedListNode *) malloc(sizeof(DoublyLinkedListNode));
    if (temp == NULL) {
       
        return;
    }
    temp->data = A;
    temp->next = NULL;

    if (*List == NULL) {
  
        temp->prev = NULL;
        *List = temp;
        return;
    }


    DoublyLinkedListNode *counter = *List;
    while (counter->next != NULL)
        counter = counter->next;


    temp->prev = counter;
    counter->next = temp;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *llist, int data) {
    int size = 0;
    DoublyLinkedListNode *it = llist;
    while (it != NULL) {
        size++;
        it = (DoublyLinkedListNode *) it->next;
    }
    it = llist;
    int a[size + 1];
    a[size] = data;
    for (int i = 0; i < size; ++i) {
        a[i] = it->data;
        it = (DoublyLinkedListNode *) it->next;
    }
    qsort(a, size + 1, sizeof(int), cmpfunc);
    DoublyLinkedListNode *ans = NULL;
    for (int i = 0; i <= size; ++i) {
        Insert_End(&ans, a[i]);
    }
    return ans;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = malloc(sizeof(DoublyLinkedList));
        llist->head = NULL;
        llist->tail = NULL;

        char* llist_count_endptr;
        char* llist_count_str = readline();
        int llist_count = strtol(llist_count_str, &llist_count_endptr, 10);

        if (llist_count_endptr == llist_count_str || *llist_count_endptr != '\0') { exit(EXIT_FAILURE); }

        for (int i = 0; i < llist_count; i++) {
            char* llist_item_endptr;
            char* llist_item_str = readline();
            int llist_item = strtol(llist_item_str, &llist_item_endptr, 10);

            if (llist_item_endptr == llist_item_str || *llist_item_endptr != '\0') { exit(EXIT_FAILURE); }

            insert_node_into_doubly_linked_list(&llist, llist_item);
        }

        char* data_endptr;
        char* data_str = readline();
        int data = strtol(data_str, &data_endptr, 10);

        if (data_endptr == data_str || *data_endptr != '\0') { exit(EXIT_FAILURE); }

        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

        char *sep = " ";

        print_doubly_linked_list(llist1, sep, fptr);
        fprintf(fptr, "\n");

        free_doubly_linked_list(llist1);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

