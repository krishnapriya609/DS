#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insertFront(int x);
void insertRear(int x);
void deleteFront();
void deleteRear();
void display();

int main() {
    int n, choice = 0;
    printf("1: Insert Front, 2: Insert Rear, 3: Delete Front, 4: Delete Rear, 5: Display, 6: Exit\n");

    while (choice != 6) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the element to insert at front: ");
            scanf("%d", &n);
            insertFront(n);
        }
        else if (choice == 2) {
            printf("Enter the element to insert at rear: ");
            scanf("%d", &n);
            insertRear(n);
        }
        else if (choice == 3) {
            deleteFront();
        }
        else if (choice == 4) {
            deleteRear();
        }
        else if (choice == 5) {
            display();
        }
        else if (choice == 6) {
            printf("Exiting...\n");
        }
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }
     return 0;
}
void insertRear(int x) {

    if ((rear + 1) % MAX == front) {
        printf("Overflow: Deque is full!\n");
    } 
    else if (front == -1) {
        front = rear = 0;
        queue[rear] = x;
    } 
    else {
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }
}
void insertFront(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == (rear + 1) % MAX)) {
        printf("Overflow: Deque is full!\n");
    } 
    else if (front == -1) {
        front = rear = 0;
        queue[front] = x;
    } 
    else if (front == 0) {
        front = MAX - 1;
        queue[front] = x;
    } 
    else {
        front = front - 1;
        queue[front] = x;
    }
}

void insertRear(int x) {
    // ✅ Correct full condition
    if ((rear + 1) % MAX == front) {
        printf("Overflow: Deque is full!\n");
    } 
    else if (front == -1) {
        front = rear = 0;
        queue[rear] = x;
    } 
    else {
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }
}

void deleteFront() {
    if (front == -1) {
        printf("Underflow: Deque is empty!\n");
    } 
    else if (front == rear) {
        printf("Deleted element from front: %d\n", queue[front]);
        front = rear = -1;
    } 
    else {
        printf("Deleted element from front: %d\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Underflow: Deque is empty!\n");
    } 
    else if (front == rear) {
        printf("Deleted element from rear: %d\n", queue[rear]);
        front = rear = -1;
    } 
    else if (rear == 0) {
        printf("Deleted element from rear: %d\n", queue[rear]);
        rear = MAX - 1;
    } 
    else {
        printf("Deleted element from rear: %d\n", queue[rear]);
        rear = rear - 1;
    }
}

//////////////////////////////////////
void display() {
    if (front == -1) {
        printf("Deque is empty!\n");
    } else {
        printf("Deque elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}
//////////////////////////////////////////
void display() {
    if (front == -1) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque elements: ");

    for (int i = front; ; i = (i + 1) % MAX) {
        printf("%d ", queue[i]);
        if (i == rear)   // stop when last element printed
            break;
    }

    printf("\n");
}
