#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int *queue;
    int front;
    int rear;
    int size;
} CircularQueue;

void initQueue(CircularQueue *q, int size) {
    q->queue = (int *)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = size;
}

int isFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % q->size);
}

int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->queue[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    int item = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return item;
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->queue[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

void freeQueue(CircularQueue *q) {
    free(q->queue);
    q->queue = NULL;
}

int main() {
    CircularQueue q;
    initQueue(&q, SIZE);

    int choice, value;

    while (1) {
        printf("\nChoose operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                freeQueue(&q);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}

