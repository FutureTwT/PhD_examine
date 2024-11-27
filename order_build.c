#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preorder(Node* root) {
    if (root == NULL) {
        return ;
    }
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) {
        return ;
    }
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

Node* pre_in_buildTree(char* preorder_index, char* inorder_index, int* preorder_p, int inorderStart, int inorderEnd) {

    char rootData = preorder_index[*preorder_p];
    (*preorder_p) ++;

    Node* root = createNode(rootData);

    if (inorderStart == inorderEnd) { // 当前子树只有一个节点，根节点，直接返回
        return root;
    }

    int rootIndex;
    for (rootIndex=inorderStart; rootIndex<=inorderEnd; rootIndex++) {
        if (inorder_index[rootIndex] == rootData) {
            break;
        }
    }
    root->left = pre_in_buildTree(preorder_index, inorder_index, preorder_p, inorderStart, rootIndex-1);
    root->right = pre_in_buildTree(preorder_index, inorder_index, preorder_p, rootIndex+1, inorderEnd);

    return root;
}

Node* post_in_buildTree(char* postorder_index, char* inorder_index, int* postorder_p, int inorderStart, int inorderEnd) {

    char rootData = postorder_index[*postorder_p];
    (*postorder_p) --;

    Node* root = createNode(rootData);

    if (inorderStart == inorderEnd) { // 当前子树只有一个节点，根节点，直接返回
        return root;
    }

    int rootIndex;
    for (rootIndex=inorderStart; rootIndex<=inorderEnd; rootIndex++) {
        if (inorder_index[rootIndex] == rootData) {
            break;
        }
    }
    root->right = post_in_buildTree(postorder_index, inorder_index, postorder_p, rootIndex+1, inorderEnd);
    root->left = post_in_buildTree(postorder_index, inorder_index, postorder_p, inorderStart, rootIndex-1);

    return root;
}

int main() {
    char preorder_index[] = {'A', 'B', 'D', 'E', 'C', 'F', 'G'}; // 先序遍历序列
    char inorder_index[] = {'D', 'B', 'E', 'A', 'F', 'C', 'G'};  // 中序遍历序列
    char postorder_index[] = {'D', 'E', 'B', 'F', 'G', 'C', 'A'}; // 后序遍历序列

    int length = sizeof(preorder_index) / sizeof(preorder_index[0]);
    int preorder_p = 0;
    int postorder_p = length - 1;

    Node* root_1 = pre_in_buildTree(preorder_index, inorder_index, &preorder_p, 0, length-1);
    Node* root_2 = post_in_buildTree(postorder_index, inorder_index, &postorder_p, 0, length-1);

    printf("Preorder: ");
    preorder(root_1);
    printf("\n");

    printf("Inorder: ");
    inorder(root_1);
    printf("\n");

    printf("Postorder: ");
    postorder(root_1);
    printf("\n");

    printf("**************\n");

    printf("Preorder: ");
    preorder(root_2);
    printf("\n");

    printf("Inorder: ");
    inorder(root_2);
    printf("\n");

    printf("Postorder: ");
    postorder(root_2);
    printf("\n");

    return 0;
}