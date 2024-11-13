#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void InitQueue(Queue *Q) {
    Q->front = 0; // 注意和Stack不一样，不是-1，为了下次插入元素后只移动rear到队列尾端的下一个位置
    Q->rear = 0;
    return ;    
}

int QueueEmpty(Queue Q) {
    return Q.front == Q.rear;
}

int EnQueue(Queue *Q, int x) {
    if (Q->rear == MAX_SIZE) {
        return 0;
    }
    Q->data[(Q->rear)++] = x;
    return 1;
}

int DeQueue(Queue *Q, int *x) {
    if (Q->front == Q->rear) {
        return 0;
    }
    *x = Q->data[(Q->front)++];
    return 1;
}

int GetHead(Queue Q, int *x) {
    if (Q.front == Q.rear) {
        return 0;
    }
    *x = Q.data[Q.front];
    return 1;
}

int main() {
    Queue Q;
    InitQueue(&Q);

    QueueEmpty(Q);

    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);

    int x;
    GetHead(Q, &x);
    printf("%d\n", x);

    DeQueue(&Q, &x);
    GetHead(Q, &x);
    printf("%d\n", x);

    return 0;
}