#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];  
    int top;             
} Stack;

void InitStack(Stack *S) {
    S->top = -1; 
}

int StackEmpty(Stack S) {
    return S.top == -1;
}

int Push(Stack *S, int x) {
    if (S->top >= MAX_SIZE - 1) {
        printf("栈满，无法入栈\n");
        return 0; 
    }
    S->data[++(S->top)] = x;
    return 1; 
}

int Pop(Stack *S, int *x) {
    if (StackEmpty(*S)) {
        printf("栈空，无法出栈\n");
        return 0; 
    }
    *x = S->data[(S->top)--]; 
    return 1; 
}

int GetTop(Stack S, int *x) {
    if (StackEmpty(S)) {
        printf("栈空，无法获取栈顶元素\n");
        return 0; 
    }
    *x = S.data[S.top]; 
    return 1; 
}

void DestroyStack(Stack *S) {
    S->top = -1; 
}

int main() {
    Stack S;
    int x;
    
    InitStack(&S); 
    
    Push(&S, 10);
    Push(&S, 20);
    Push(&S, 30);
    
    if (GetTop(S, &x)) {
        printf("栈顶元素: %d\n", x);
    }

    if (Pop(&S, &x)) {
        printf("出栈元素: %d\n", x);
    }

    if (StackEmpty(S)) {
        printf("栈为空\n");
    } else {
        printf("栈不为空\n");
    }

    DestroyStack(&S); 
    return 0;
}
