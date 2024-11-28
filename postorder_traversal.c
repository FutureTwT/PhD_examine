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

void postorder(Node* root) {
    if (root == NULL) {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// 优化内存，单栈实现
void postorder_stack(Node* root) {
    if (root == NULL) {
        return ;
    }

    Node* stack[100];
    int top = -1;
    Node* curr = root;
    Node* lastVisited = NULL;
    // 1. 先访问左子树，2. 回溯到根节点， 3. 访问右子树，4. 访问根节点
    while (top >= 0 || curr != NULL) {
        // 后序遍历，依然是左子树优先，同中序，先左子树压栈
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top]; // 不可以top--，curr作为栈顶，左子树必然已经访问完，但是需要先检查右子树是否已经访问
        if (curr->right == NULL || curr->right == lastVisited) { // 没有右子树或者已经访问过右子树
            printf("%d ", curr->data); // 直接访问根节点
            top--; // 出栈
            lastVisited = curr; // 当前节点如果是左子树，那么可以直接向上回溯，如果是右子树，标识下已经访问，所以都标注上
            curr = NULL; // 设置为NULL，当前节点已完成处理，需要pop stack取出新节点，只要可以从栈中访问，左子树是必然访问过的
        } else {
            // 有右子树，先去访问，然后右子树同理，还是左子树先循环压栈，top增加
            curr = curr->right;
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

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("Postorder (Stack): ");
    postorder_stack(root);
    printf("\n");

    return 0;
}