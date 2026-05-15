#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

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

// Insert at rear end of the list
void insertRear(Node** head, Node** tail, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

// Traverse forward
void traverseForward(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Concatenate X2 at the end of X1
void concatenateLists(Node** head1, Node** tail1, Node* head2, Node* tail2) {
    if (*head1 == NULL) {   // if X1 is empty, X1 becomes X2
        *head1 = head2;
        *tail1 = tail2;
        return;
    }
    if (head2 == NULL) {    // if X2 is empty, nothing to do
        return;
    }
    // Link the tail of X1 to head of X2
    (*tail1)->next = head2;
    head2->prev = *tail1;
    *tail1 = tail2;
}

int main() {
    Node *X1_head = NULL, *X1_tail = NULL;
    Node *X2_head = NULL, *X2_tail = NULL;

    int n1, n2, i, val;

    printf("Enter number of elements in List X1: ");
    scanf("%d", &n1);
    printf("Enter elements for List X1:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &val);
        insertRear(&X1_head, &X1_tail, val);
    }

    printf("Enter number of elements in List X2: ");
    scanf("%d", &n2);
    printf("Enter elements for List X2:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &val);
        insertRear(&X2_head, &X2_tail, val);
    }

    printf("\nList X1 before concatenation:\n");
    traverseForward(X1_head);

    printf("List X2 before concatenation:\n");
    traverseForward(X2_head);

    // Concatenate
    concatenateLists(&X1_head, &X1_tail, X2_head, X2_tail);

    printf("\nList X1 after concatenation:\n");
    traverseForward(X1_head);

    return 0;
}
