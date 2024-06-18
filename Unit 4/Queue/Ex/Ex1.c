#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int size;
} Queue;

Queue *CreateQueue(int size);
void Enqueue(Queue *q, int val);
void Dequeue(Queue *q);
int Front(Queue *q);

int main() {
    int q;
    scanf("%d", &q);
    Queue *myQueue = CreateQueue(q);
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x;
            scanf("%d", &x);
            Enqueue(myQueue, x);
        } else if (type == 2) {
            Dequeue(myQueue);
        } else {
            printf("%d\n", Front(myQueue));
        }
    }
    free(myQueue->array);
    free(myQueue);
    return 0;
}

Queue *CreateQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->array = (int *)malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

void Enqueue(Queue *q, int val) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
    } else {
        q->rear++;
        q->array[q->rear] = val;
        if (q->front == -1) {
            q->front = 0;
        }
    }
}

void Dequeue(Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
    } else {
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }
}

int Front(Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->array[q->front];
    }
}

