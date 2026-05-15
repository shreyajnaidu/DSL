#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for patient details
struct Patient {
    char name[50];
    int age;
    int priority;
};

// Node structure for the linked list
struct Node {
    struct Patient data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return (front == NULL);
}

// Function to enqueue a patient
void enqueue(struct Patient p) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = p;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Patient '%s' added to the queue.\n", p.name);
}

// Function to dequeue a patient
void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty! No patients to remove.\n");
        return;
    }

    struct Node* temp = front;
    printf("Patient '%s' removed from the queue.\n", front->data.name);

    front = front->next;
    if (front == NULL)
        rear = NULL; // Queue becomes empty

    free(temp);
}

// Function to display all patients in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("\n--- Patient Queue ---\n");
    while (temp != NULL) {
        printf("Name: %s | Age: %d | Priority: %d\n",
               temp->data.name, temp->data.age, temp->data.priority);
        temp = temp->next;
    }
    printf("---------------------\n");
}

// Main function
int main() {
    int choice;
    struct Patient p;

    while (1) {
        printf("\n--- Patient Queue Menu ---\n");
        printf("1. Enqueue Patient\n2. Dequeue Patient\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter Patient Name: ");
                fgets(p.name, sizeof(p.name), stdin);
                p.name[strcspn(p.name, "\n")] = '\0';  // Remove trailing newline

                printf("Enter Age: ");
                scanf("%d", &p.age);
                printf("Enter Priority (1=High, 2=Medium, 3=Low): ");
                scanf("%d", &p.priority);

                enqueue(p);
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
