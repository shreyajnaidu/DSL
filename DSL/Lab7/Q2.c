#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for char stack (operators)
struct Node {
    char data;
    struct Node* next;
};

// Node for int stack (evaluation)
struct IntNode {
    int data;
    struct IntNode* next;
};

// ---------------- Char Stack ----------------
void pushChar(struct Node** top, char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = *top;
    *top = newNode;
}

char popChar(struct Node** top) {
    if (*top == NULL) return '\0';
    struct Node* temp = *top;
    char val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

char peekChar(struct Node* top) {
    if (top == NULL) return '\0';
    return top->data;
}

int isEmptyChar(struct Node* top) {
    return top == NULL;
}

// ---------------- Int Stack ----------------
void pushInt(struct IntNode** top, int val) {
    struct IntNode* newNode = (struct IntNode*)malloc(sizeof(struct IntNode));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int popInt(struct IntNode** top) {
    if (*top == NULL) return 0;
    struct IntNode* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// ---------------- Helpers ----------------
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// ---------------- i) Infix → Postfix ----------------
void infixToPostfix(char* infix, char* postfix) {
    struct Node* stack = NULL;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isDigit(c)) { // operand
            postfix[k++] = c;
        }
        else if (c == '(') {
            pushChar(&stack, c);
        }
        else if (c == ')') {
            while (!isEmptyChar(stack) && peekChar(stack) != '(') {
                postfix[k++] = popChar(&stack);
            }
            popChar(&stack); // discard '('
        }
        else if (isOperator(c)) {
            while (!isEmptyChar(stack) &&
                   precedence(peekChar(stack)) >= precedence(c)) {
                postfix[k++] = popChar(&stack);
            }
            pushChar(&stack, c);
        }
    }

    while (!isEmptyChar(stack)) {
        postfix[k++] = popChar(&stack);
    }
    postfix[k] = '\0';
}

// ---------------- ii) Postfix Evaluation ----------------
int evaluatePostfix(char* postfix) {
    struct IntNode* stack = NULL;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isDigit(c)) {
            pushInt(&stack, c - '0'); // convert char → int
        }
        else if (isOperator(c)) {
            int val2 = popInt(&stack);
            int val1 = popInt(&stack);
            int result;

            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': {
                    result = 1;
                    for (int j = 0; j < val2; j++) result *= val1;
                    break;
                }
                default: result = 0;
            }
            pushInt(&stack, result);
        }
    }
    return popInt(&stack);
}

// ---------------- Main ----------------
int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression (digits & operators only): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation Result: %d\n", result);

    return 0;
}
