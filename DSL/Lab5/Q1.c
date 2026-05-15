#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Global head and tail pointers
Node* head = NULL;
Node* tail = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at rear end
void insertRear(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("%d inserted at the rear.\n", data);
}

// Delete from rear end
void deleteRear() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    printf("%d deleted from the rear.\n", temp->data);
    free(temp);
}

// Insert at given position
void insertAtPosition(int data, int pos) {
    Node* newNode = createNode(data);
    if (pos == 1) {
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        printf("%d inserted at position %d.\n", data, pos);
        return;
    }
    Node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    } else {
        tail = newNode; // if inserting at the end
    }
    temp->next = newNode;
    printf("%d inserted at position %d.\n", data, pos);
}

// Delete from given position
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    if (pos == 1) {
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        printf("%d deleted from position %d.\n", temp->data, pos);
        free(temp);
        return;
    }
    int count = 1;
    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev; // deleting last node
    }
    temp->prev->next = temp->next;
    printf("%d deleted from position %d.\n", temp->data, pos);
    free(temp);
}

// Insert after a specific value
void insertAfterValue(int data, int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    } else {
        tail = newNode;
    }
    temp->next = newNode;
    printf("%d inserted after %d.\n", data, value);
}

// Insert before a specific value
void insertBeforeValue(int data, int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }
    temp->prev = newNode;
    printf("%d inserted before %d.\n", data, value);
}

// Traverse forward
void traverseForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Forward Traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Traverse backward
void traverseBackward() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = tail;
    printf("Backward Traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Menu-driven interface
int main() {
    int choice, data, pos, value;

    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at Rear\n");
        printf("2. Delete from Rear\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Position\n");
        printf("5. Insert After Value\n");
        printf("6. Insert Before Value\n");
        printf("7. Traverse Forward\n");
        printf("8. Traverse Backward\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertRear(data);
                break;
            case 2:
                deleteRear();
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(data, pos);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 5:
                printf("Enter data and value to insert after: ");
                scanf("%d %d", &data, &value);
                insertAfterValue(data, value);
                break;
            case 6:
                printf("Enter data and value to insert before: ");
                scanf("%d %d", &data, &value);
                insertBeforeValue(data, value);
                break;
            case 7:
                traverseForward();
                break;
            case 8:
                traverseBackward();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
