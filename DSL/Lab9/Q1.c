#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Stack structure for iterative traversals
typedef struct Stack {
    Node *data[100];
    int top;
} Stack;

void push(Stack *s, Node *node) {
    s->data[++(s->top)] = node;
}

Node *pop(Stack *s) {
    if (s->top == -1) return NULL;
    return s->data[(s->top)--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

// Create a new node
Node *newNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

/* i) Inorder Traversal (Iterative) */
void inorderIterative(Node *root) {
    Stack s;
    s.top = -1;
    Node *curr = root;

    while (curr != NULL || !isEmpty(&s)) {
        while (curr != NULL) {
            push(&s, curr);
            curr = curr->left;
        }
        curr = pop(&s);
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

/* ii) Preorder Traversal (Iterative) */
void preorderIterative(Node *root) {
    if (root == NULL) return;

    Stack s;
    s.top = -1;
    push(&s, root);

    while (!isEmpty(&s)) {
        Node *curr = pop(&s);
        printf("%d ", curr->data);

        if (curr->right)
            push(&s, curr->right);
        if (curr->left)
            push(&s, curr->left);
    }
}

/* iii) Postorder Traversal (Iterative using two stacks) */
void postorderIterative(Node *root) {
    if (root == NULL) return;

    Stack s1, s2;
    s1.top = s2.top = -1;
    push(&s1, root);

    while (!isEmpty(&s1)) {
        Node *curr = pop(&s1);
        push(&s2, curr);

        if (curr->left)
            push(&s1, curr->left);
        if (curr->right)
            push(&s1, curr->right);
    }

    while (!isEmpty(&s2)) {
        Node *curr = pop(&s2);
        printf("%d ", curr->data);
    }
}

/* iv) Print the parent of a given element */
void printParent(Node *root, int val) {
    if (root == NULL) return;

    if ((root->left && root->left->data == val) ||
        (root->right && root->right->data == val)) {
        printf("Parent of %d is %d\n", val, root->data);
        return;
    }

    printParent(root->left, val);
    printParent(root->right, val);
}

/* v) Print the depth (or height) of the tree */
int height(Node *root) {
    if (root == NULL) return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}

/* vi) Print ancestors of a given element */
int printAncestors(Node *root, int val) {
    if (root == NULL) return 0;

    if (root->data == val) return 1;

    if (printAncestors(root->left, val) || printAncestors(root->right, val)) {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

/* vii) Count the number of leaf nodes */
int countLeaves(Node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

/* --- MAIN FUNCTION FOR DEMO --- */
int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Inorder (Iterative): ");
    inorderIterative(root);
    printf("\n");

    printf("Preorder (Iterative): ");
    preorderIterative(root);
    printf("\n");

    printf("Postorder (Iterative): ");
    postorderIterative(root);
    printf("\n");

    printParent(root, 5);

    printf("Height of tree: %d\n", height(root));

    printf("Ancestors of 5: ");
    printAncestors(root, 5);
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeaves(root));

    return 0;
}
