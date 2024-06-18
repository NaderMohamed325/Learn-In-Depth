#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *array;
    int top;
    int max;
} Stack;

int peek(Stack *stack);

Stack *Create_Stack(int capacity);

int push(Stack *stack, int element);

int pop(Stack *stack);

void Destroy(Stack *stack);

bool isEmpty(Stack *stack);

int poisonousPlants(int n, int p[]);

int main() {
    int n;
    scanf("%d", &n);
    int *p = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    if(poisonousPlants(n, p)==1){
        printf("0\n");
    }
    printf("%d\n", poisonousPlants(n, p));

    free(p);
    return 0;
}

Stack *Create_Stack(int capacity) {
    if (capacity <= 0) {
        return NULL;
    }
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    } else {
        stack->array = (int *) malloc(sizeof(int) * capacity);
        if (stack->array == NULL) {
            free(stack);
            return NULL;
        }
        stack->max = capacity;
        stack->top = -1;
        return stack;
    }
}

int push(Stack *stack, int element) {
    if (stack == NULL || stack->top + 1 == stack->max) {
        return 0;
    }
    stack->array[++stack->top] = element;
    return 1;
}

int pop(Stack *stack) {
    if (stack == NULL || stack->top == -1) {
        return 0;
    }
    return stack->array[stack->top--];
}

void Destroy(Stack *stack) {
    if (stack != NULL) {
        free(stack->array);
        free(stack);
    }
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

int peek(Stack *stack) {
    if (stack == NULL || stack->top == -1) {
        return -1;
    }
    return stack->array[stack->top];
}

int poisonousPlants(int n, int p[]) {
    Stack *s = Create_Stack(n);
    int days = 0;

    for (int i = 0; i < n; i++) {
        int dying_days = 0;
        while (!isEmpty(s) && p[i] <= peek(s)) {
            pop(s);
            dying_days++;
        }
        days = (days < dying_days) ? dying_days : days;
        push(s, p[i]);
    }

    Destroy(s);
    return days;
}
