#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType* left, * right;
} TreeNode;

typedef struct BinaryTreeType {
    struct NodeType* root;
} BinaryTree;

TreeNode* makeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void print(TreeNode* node) {
    if(!node) return;
    print(node->left);
    printf("%d ", node->data);
    print(node->right);
}

void init(BinaryTree* tree) {
    tree->root = NULL;
}

void insert(TreeNode** Node, int data) {
    if(!(*Node)) {
        *Node = makeNode(data);
    }else if((*Node)->data < data) {
        // gán vào lá bên phải
        insert(&(*Node)->right, data);
    }else if((*Node)->data > data) {
        // gán vào lá bên trái
        insert(&(*Node)->left, data);
    }
}

int main() {
    BinaryTree tree;
    init(&tree);
    //insert các cây ở câu 1.1
    // 1.1.1
    printf("1.1.1: ");
    int a[] = {4, 6, 2, 3, 5, 1, 7};
    for(int i = 0; i < 7; i++) {
        insert(&tree.root, a[i]);
    }
    print(tree.root);
    printf("\n");

    // 1.1.2
    init(&tree);
    printf("1.1.2: ");
    int b[] = {8, 10, 3, 6, 14, 1, 7, 13, 4};
    for(int i = 0; i < 9; i++) {
        insert(&tree.root, b[i]);
    }
    print(tree.root);
    printf("\n");

    // 1.1.3
    init(&tree);
    printf("1.1.3: ");
    int c[] = {50, 25, 75, 10, 33, 56, 89, 4, 11, 40, 52, 61, 82, 95};
    for(int i = 0; i < 14; i++) {
        insert(&tree.root, c[i]);
    }
    print(tree.root);
    printf("\n");
    return 0;
}
