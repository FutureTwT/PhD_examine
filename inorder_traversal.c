#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(Node* root) {
    if (root == NULL) {
        return ;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void inorder_stack(Node* root) {
    if (root == NULL) {
        return ;
    }

    Node* stack[100];
    int top = -1;
    Node* curr = root;

    // 1. 左子树入栈 2. 出栈等价于访问了左子树+根节点 3. 访问右子树（右子树也是先把左子树压栈，之后出栈的时候再访问当前“右子树根节点”）
    while (top >= 0 || curr != NULL) { // 栈空后可能是遍历完了左子树和根，还需要进一步走右子树
        while (curr != NULL) {
            stack[++top] = curr;
            // 深入左子树最底层
            curr = curr->left;
        }
        // 使用栈进行回溯
        curr = stack[top--]; // 访问根节点
        printf("%d ", curr->data);
        curr = curr->right;
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

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Inorder (Stack): ");
    inorder_stack(root);
    printf("\n");

    return 0;
}