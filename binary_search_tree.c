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

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key); //  return 将新创建的节点传递回递归调用链
    }

    if (key < root->data) {
        root->left = insert(root->left, key); // 通过递归调用进行新节点的赋值
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else if (key > root->data) {
        return search(root->right, key);
    }
}

Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL) { // 务必判断非空树
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return NULL; // 空树
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // 左右子树均不为空，需要合并左右子树，将右子树最小值交换根节点，替代删除
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);            
        }
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return ;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder of BST: ");
    inorder(root);
    printf("\n");   

    // 查找节点
    int key = 40;
    Node* found = search(root, key);
    if (found != NULL) {
        printf("Key %d found in the BST.\n", key);
    } else {
        printf("Key %d not found in the BST.\n", key);
    }

    // 删除节点
    root = deleteNode(root, 50);
    printf("Inorder of BST after deleting 50: ");
    inorder(root);
    printf("\n");

    return 0;
}