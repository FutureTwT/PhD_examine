#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void InitQueue(Queue *Q) {
    Q->front = 0; 
    Q->rear = 0;
    return ;    
}

int QueueEmpty(Queue Q) {
    return Q.front == Q.rear;
}

int EnQueue(Queue *Q, int x) {
    if ((Q->rear + 1) % MAX_SIZE == Q->front) { // % MAX_SIZE，仅为了rear处于数组末端且front在首端
        return 0;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAX_SIZE;
    return 1;
}

int DeQueue(Queue *Q, int *x) {
    if (Q->front == Q->rear) {
        return 0;
    }
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_SIZE;
    return 1;
}

int GetLength(Queue Q, int *x) {
    *x = (Q.rear + MAX_SIZE - Q.front) % MAX_SIZE; // % MAX_SIZE 相当于减去MAX_SIZE的整倍数
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