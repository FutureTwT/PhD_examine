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

void preorder(Node* root) {
    if (root == NULL) {
        return ;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void preorder_stack(Node* root) {
    if (root == NULL) {
        return ;
    }

    Node* stack[100];
    int top = -1;
    stack[++top] = root;
    
    // 1. 访问根节点，2. 先存右子树，再存左子树 3. 下一轮直接访问左子树
    while (top >= 0) { // 栈空后停止遍历
        Node* temp_node = stack[top--];
        printf("%d ", temp_node->data);

        if (temp_node->right) { // 把后遍历的右节点先放到栈底
            stack[++top] = temp_node->right;
        }
        if (temp_node->left) {
            stack[++top] = temp_node->left;
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

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Preorder (stack): ");
    preorder_stack(root);
    printf("\n");

    return 0;
}