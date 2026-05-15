#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
struct Stack {
    char arr[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}
void push(struct Stack *s, char ch) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++s->top] = ch;
}
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        return '\0'; 
    }
    return s->arr[s->top--];
}

char peek(struct Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->arr[s->top];
}
int isPalindrome(char str[]) {
    struct Stack s;
    initStack(&s);

    int len = strlen(str);
    char reversed[MAX];
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }
    for (int i = 0; i < len; i++) {
        reversed[i] = pop(&s);
    }
    reversed[len] = '\0';
    if (strcmp(str, reversed) == 0) {
        return 1; 
    }
    return 0;
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int checkParentheses(char exp[]) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s)) return 0; // No matching open
            char open = pop(&s);
            if (!isMatchingPair(open, ch)) return 0; // Mismatch
        }
    }

    return isEmpty(&s); 
}

int main() {
    char str[MAX], exp[MAX];

    // i
    printf("Enter a string to check palindrome: ");
    scanf("%s", str);
    if (isPalindrome(str))
        printf("'%s' is a Palindrome.\n", str);
    else
        printf("'%s' is NOT a Palindrome.\n", str);

    // ii
    printf("\nEnter an expression to check parentheses: ");
    scanf("%s", exp);
    if (checkParentheses(exp))
        printf("Expression '%s' has Balanced Parentheses.\n", exp);
    else
        printf("Expression '%s' has Unbalanced Parentheses.\n", exp);

    return 0;
}
