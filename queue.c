#include <stdio.h>
#define SIZE 100  // fix macro name consistency

int queue[SIZE];
int front = -1;
int rear = -1;

// Check if queue is full
int isFull() {
    return rear == SIZE - 1;
}

// Check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Add element to the queue
void enqueue(int item) {
    if (isFull()) {
        printf("The queue is full, the element cannot be added\n");
        return;
    }
    
    if (front == -1) {
        front = 0;
    }
    
    rear++;
    queue[rear] = item;
    printf("Enqueued %d\n", item);
}

// Remove element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("The queue is empty, no element to dequeue\n");
        return -1;
    }
    int item = queue[front];
    front++;
    
    // Reset queue when empty
    if (front > rear) {
        front = rear = -1;
    }
    
    printf("Dequeued item %d\n", item);
    return item;
}

// Display the queue contents
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    displayQueue();
    
    dequeue();
    displayQueue();
    
    enqueue(40);
    displayQueue();
    
    return 0;
}

