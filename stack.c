#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void InitStack(Stack *S) {
    S->top = -1;
    return ;
}

int StackEmpty(Stack S) {
    return S.top == -1;
}

int Push(Stack *S, int x) {
    if (S->top == MAX_SIZE - 1) {
        return 0;
    }
    S->data[++(S->top)] = x; // 前置递增，首先将 S->top 的值增加 1，然后返回增加后的值
    return 1;
}

int Pop(Stack *S, int *x) {
    if (S->top == -1) {
        return 0;
    }
    *x = S->data[(S->top)--]; // 后置递减，首先返回 S->top 的值，然后将 S->top 的值减 1
    return 1;
}

int GetTop(Stack S, int *x) {
    if (S.top == -1) {
        return 0;
    }
    *x = S.data[S.top];
    return 1;
}

void DestroyStack(Stack *S) {
    S->top = -1;
    return ;
}

int main() {
    Stack S;
    InitStack(&S);

    StackEmpty(S);

    Push(&S, 1);
    Push(&S, 2);
    Push(&S, 3);

    int x;
    Pop(&S, &x);
    printf("%d\n", x);

    GetTop(S, &x);
    printf("%d\n", x);

    DestroyStack(&S);

    return 0;
}