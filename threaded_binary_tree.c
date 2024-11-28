#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
    int ltag;
    int rtag;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->ltag = newNode->rtag = 0;
    return newNode;
}

void inorder_threadify(Node* root, Node** pre) {
    if (root == NULL) {
        return ;
    }

    inorder_threadify(root->left, pre);
    if (root->left == NULL) {
        root->left = *pre;
        root->ltag = 1;
    }

    if (*pre != NULL && (*pre)->right == NULL) {
        (*pre)->right = root;
        (*pre)->rtag = 1;
    }

    *pre = root;

    inorder_threadify(root->right, pre);
}

void inorder(Node* root) {
    Node* current = root; // 当前正在处理的节点

    while (current != NULL && current->ltag == 0) { // 定位中序遍历的起点
        current = current->left;
    }

    while (current != NULL) {
        printf("%d ", current->data);

        if (current->ltag == 1) { // 直接转到线索节点，然后会访问
            current = current->right;
        } else {
            current = current->right; // 转到右子树，但是不访问，需要找到右子树的最左节点
            while (current != NULL && current->ltag == 0) {
                current = current->left;
            }
        }
    }
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    Node *pre = NULL;

    inorder_threadify(root, &pre);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    return 0;
}