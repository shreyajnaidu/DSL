#include <stdio.h>
#define SIZE 5   // You can change this size as needed

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full! Cannot insert %d\n", value);
        return;
    }

    if (isEmpty())
        front = 0;  // First element insertion

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d inserted into queue.\n", value);
}

// Function to delete an element
void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty! Nothing to delete.\n");
        return;
    }

    printf("%d deleted from queue.\n", queue[front]);

    if (front == rear)
        front = rear = -1;  // Queue becomes empty
    else
        front = (front + 1) % SIZE;
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
