#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_list(int data[], int len) {
    Node *head = NULL;
    for (int i = len - 1; i >= 0; i--) {
        head = head_insert(head, data[i]);
    }
    return head;
}

Node *head_insert(Node *head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

Node *tail_insert(Node *head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (!head) {
        head = new_node;
    } else {
        Node *cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = new_node;
    }
    return head;
}

int main() {
    Node *head = NULL;
    int data[] = {1, 2, 3, 4, 5};
    int len = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < len; i++) {
        head = head_insert(head, data[i]);
    }
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    return 0;
}
