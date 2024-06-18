#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *array;
    int top;
    int max;
} Stack;

Stack *Create_Stack(int capacity);

int push(Stack *stack, int element);

int pop(Stack *stack);

void Destroy(Stack *stack);

bool isPrime(int num);

void storeNPrimes(int n, int *primes);

bool isEmpty(Stack *stack);

int main() {
  int n;
    scanf("%d",&n);
    Stack *s=Create_Stack(n);
    int start;
    scanf("%i",&start);
    n--;
    push(s,start);
    while (n--){
        int x;
        scanf("%i",&x);
        if(x>())
    }
    free(s);
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

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void storeNPrimes(int n, int *primes) {
    int count = 0;
    int num = 2;

    while (count < n) {
        if (isPrime(num)) {
            primes[count++] = num;
        }
        num++;
    }
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
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