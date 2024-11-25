#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3; // 假设支持幂运算
        default: return 0;
    }
}

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void InitStack(Stack *S) {
    S->top = -1;
    return ;
}

bool Push(Stack *S, char x) {
    if (S->top == MAX_SIZE - 1) {
        return 0;
    }
    S->data[++(S->top)] = x; // 前置递增，首先将 S->top 的值增加 1，然后返回增加后的值
    return true;
}

char Pop(Stack *S) {
    char temp;
    if (S->top == -1) {
        return 0;
    }
    temp = S->data[(S->top)--]; // 后置递减，首先返回 S->top 的值，然后将 S->top 的值减 1
    return temp;
}

bool isOperator(char c) {
    return strchr("+-*/^", c) != NULL;
}

bool isNumber(char c) {
    return strchr("1234567890", c) != NULL;
}

// Infix Notation -> Polish Notation
void IN2PN(const char* in_str, char* pn_str) {
    // TODO
}

// Infix Notation -> Reverse Polish Notation
void IN2RPN(const char* in_str, char* rpn_str) {
    Stack stack;
    InitStack(&stack);

    char temp;
    int rpnIndex=0;
    for (int i=0; in_str[i] != '\0'; i++) {
        if (in_str[i] == '(') {
            Push(&stack, in_str[i]);
        } else if (in_str[i] == ')') {
            while (stack.top != -1 && stack.data[stack.top] != '(') {
                rpn_str[rpnIndex++] = stack.data[stack.top--];
            }
            Pop(&stack);
        } else if (isNumber(in_str[i])) {
            rpn_str[rpnIndex++] = in_str[i];
        } else if (isOperator(in_str[i])) {
            while (stack.top != -1 && precedence(in_str[i]) <= precedence(stack.data[stack.top]) && stack.data[stack.top] != '(') {
                rpn_str[rpnIndex++] = stack.data[stack.top--];
            }
            stack.data[++stack.top] = in_str[i];
        }
    }
    while (stack.top != -1) {
        rpn_str[rpnIndex++] = stack.data[stack.top--];
    }
    rpn_str[rpnIndex] = '\0';
}

int main() {
    char in_str[MAX_SIZE];
    char pn_str[MAX_SIZE];
    char rpn_str[MAX_SIZE];

    printf("Input string: ");
    scanf("%s", in_str);

    // IN2PN(in_str, pn_str);
    IN2RPN(in_str, rpn_str);
    
    // printf("%s\n", pn_str);
    printf("%s\n", rpn_str);
    return 0;
}