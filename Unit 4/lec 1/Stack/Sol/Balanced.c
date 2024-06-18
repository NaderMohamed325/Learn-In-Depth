#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure
typedef struct {
    int *array;
    int top;
    int max;
} Stack;

// Function prototypes
Stack *Create_Stack(int capacity);
int push(Stack *stack, int element);
int pop(Stack *stack);
int peek(Stack *stack);
void Destroy(Stack *stack);
int isBalanced(const char *s);

int main() {
    int n;

    scanf("%d", &n);

    while (n--) {
        char s[2000];
        scanf("%s", s);
        if (isBalanced(s)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

Stack *Create_Stack(int capacity) {
    if (capacity <= 0) {
        return NULL;
    }

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (NULL == stack) {
        return NULL;
    } else {
        stack->array = (int *)malloc(sizeof(int) * capacity);
        if (NULL == stack->array) {
            free(stack);
            return NULL;
        }
        stack->max = capacity;
        stack->top = -1;
        return stack;
    }
}

int push(Stack *stack, int element) {
    if (stack == NULL) {
        printf("Invalid stack pointer\n");
        return 0;
    } else if (stack->top + 1 == stack->max) {
        printf("Stack is Full\n");
        return 0;
    }
    stack->array[++stack->top] = element;
    return 1;
}

int pop(Stack *stack) {
    if (stack == NULL) {
        printf("Invalid stack pointer\n");
        return 0;
    } else if (stack->top == -1) {
        printf("Stack is Empty\n");
        return 0;
    }
    return stack->array[stack->top--];
}

int peek(Stack *stack) {
    if (stack == NULL) {
        printf("Invalid stack pointer\n");
        return 0;
    } else if (stack->top == -1) {
        printf("Stack is Empty\n");
        return 0;
    }
    return stack->array[stack->top];
}

void Destroy(Stack *stack) {
    free(stack->array);
    free(stack);
}

int isBalanced(const char *s) {
    Stack *st = Create_Stack(strlen(s));
    if (st == NULL) {
        printf("Memory allocation error\n");
        return 0;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(st, s[i]);
        } else {
            if (st->top == -1) {
                Destroy(st);
                return 0;
            }
            char top = peek(st);
            if ((s[i] == ')' && top != '(') || (s[i] == ']' && top != '[') || (s[i] == '}' && top != '{')) {
                Destroy(st);
                return 0;
            }
            pop(st);
        }
    }

    int result = st->top == -1 ? 1 : 0;
    Destroy(st);
    return result;
}
