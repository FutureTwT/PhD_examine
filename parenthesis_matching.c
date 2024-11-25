#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void InitStack(Stack *S) {
    S->top = -1;
    return ;
}

int StackEmpty(Stack S) {
    return S.top == -1;
}

int Push(Stack *S, char x) {
    if (S->top == MAX_SIZE - 1) {
        return 0;
    }
    S->data[++(S->top)] = x; // 前置递增，首先将 S->top 的值增加 1，然后返回增加后的值
    return 1;
}

int Pop(Stack *S) {
    char temp;
    if (S->top == -1) {
        return 0;
    }
    temp = S->data[(S->top)--]; // 后置递减，首先返回 S->top 的值，然后将 S->top 的值减 1
    return temp;
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// core code
bool isBalanced(char* str) {
    Stack stack;
    InitStack(&stack);

    for (int i=0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            Push(&stack, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (StackEmpty(stack) || !isMatchingPair(Pop(&stack), ch)) {
                return false;
            }
        }
    }
    return StackEmpty(stack);
} 

int main() {
    char str[MAX_SIZE];
    printf("Input string: ");
    scanf("%s", str);

    if (isBalanced(str)) {
        printf("Balanced!\n");
    } else {
        printf("Unbalanced!\n");
    }

    return 0;
}