#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer to the start of the list
struct Node* head = NULL;

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertBefore(int val, int item) {
    if (head == NULL) {
        printf("List is empty. Cannot insert before.\n");
        return;
    }

    if (head->data == item) {
        struct Node* newNode = createNode(val);
        newNode->next = head;
        head = newNode;
        return;
    }


    struct Node* current = head;
    while (current->next != NULL && current->next->data != item) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element %d not found in the list.\n", item);
    } else {
        struct Node* newNode = createNode(val);
        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertAfter(int val, int item) {
    struct Node* current = head;
    while (current != NULL && current->data != item) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", item);
    } else {
        struct Node* newNode = createNode(val);
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteNode(int val) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == val) {
        head = temp->next; // Change head
        free(temp);        // Free old head
        printf("Element %d deleted.\n", val);
        return;
    }

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the list.\n", val);
        return;
    }

    prev->next = temp->next;
    free(temp); // Free memory
    printf("Element %d deleted.\n", val);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List elements: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void reverse() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next; // Store the next node
        current->next = prev;     // Reverse the current node's pointer
        prev = current;           // Move pointers one position ahead
        current = nextNode;
    }
    head = prev; // The new head is the last node (prev)
}

void sortList() {
    if (head == NULL) return;

    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL; // Last pointer

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data of adjacent nodes
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void deleteAlternate() {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        struct Node* nodeToDelete = current->next; // The node to be deleted
        current->next = nodeToDelete->next;       // Link current to the node after the one to be deleted
        free(nodeToDelete);                       // Free the memory of the alternate node
        current = current->next;                  // Move to the next node to continue
    }
}


void insertSorted(int val) {
    struct Node* newNode = createNode(val);
    struct Node* current;

    // Case 1: List is empty or new node should be the new head
    if (head == NULL || head->data >= newNode->data) {
        newNode->next = head;
        head = newNode;
    } else {
        // Case 2: Locate the node before the point of insertion
        current = head;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
int main() {
    int choice, value, item;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert an element before another element\n");
        printf("2. Insert an element after another element\n");
        printf("3. Delete a specified element\n");
        printf("4. Traverse and display the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list (Bubble Sort)\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert into a sorted list\n");
        printf("9. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the element to insert before: ");
                scanf("%d", &item);
                insertBefore(value, item);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the element to insert after: ");
                scanf("%d", &item);
                insertAfter(value, item);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                display();
                break;
            case 5:
                reverse();
                printf("List has been reversed.\n");
                break;
            case 6:
                sortList();
                printf("List has been sorted.\n");
                break;
            case 7:
                deleteAlternate();
                printf("Alternate nodes have been deleted.\n");
                break;
            case 8:
                printf("Enter the value to insert into the sorted list: ");
                scanf("%d", &value);
                insertSorted(value);
                break;
            case 9:
                printf("Exiting program.\n");
                // Free all nodes before exiting
                while(head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


