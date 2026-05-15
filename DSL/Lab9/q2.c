#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// i) Recursive function to create a binary tree
Node* createTree() {
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1) return NULL;  // Base case

    Node* root = newNode(x);
    printf("Enter left child of %d:\n", x);
    root->left = createTree();
    printf("Enter right child of %d:\n", x);
    root->right = createTree();

    return root;
}

// ii) Recursive functions to print the tree

// Inorder traversal (Left → Root → Right)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal (Root → Left → Right)
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal (Left → Right → Root)
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = NULL;
    printf("Create the binary tree:\n");
    root = createTree();

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    return 0;
}
