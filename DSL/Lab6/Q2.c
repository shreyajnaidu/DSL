#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *prev, *next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->prev = newNode->next = NULL;
    return newNode;
}


void insertTerm(struct Node **head, int coeff, int exp) {
    if (coeff == 0) return; // Ignore zero coefficients
    struct Node* newNode = createNode(coeff, exp);

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;


    while (current != NULL && current->exp > exp) {
        prev = current;
        current = current->next;
    }

    if (current != NULL && current->exp == exp) {
        current->coeff += coeff;
        free(newNode);
        if (current->coeff == 0) { 
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == *head) *head = current->next;
            free(current);
        }
        return;
    }


    if (current == *head && exp > current->exp) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
  else if (current == NULL) {
        prev->next = newNode;
        newNode->prev = prev;
    }

    else {
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev) current->prev->next = newNode;
        current->prev = newNode;
    }
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Node* current = head;
    while (current != NULL) {
        printf("%dx^%d", current->coeff, current->exp);
        if (current->next != NULL && current->next->coeff > 0)
            printf(" + ");
        else if (current->next != NULL && current->next->coeff < 0)
            printf(" ");
        current = current->next;
    }
    printf("\n");
}


struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            insertTerm(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

 
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    insertTerm(&poly1, 3, 4);
    insertTerm(&poly1, 2, 2);
    insertTerm(&poly1, 1, 0);
    insertTerm(&poly2, 5, 3);
    insertTerm(&poly2, 2, 2);
    insertTerm(&poly2, 4, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    sum = addPolynomials(poly1, poly2);

    printf("Sum: ");
    display(sum);

    return 0;
}
