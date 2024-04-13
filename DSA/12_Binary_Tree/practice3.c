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

TreeNode* search(TreeNode* node, int val) {
    if(!node) return NULL; // ko tìm thấy
    if(val > node->data) {
        // tìm bên phải
        return search(node->right, val);
    }else if(val < node->data) {
        // tìm bên trái
        return search(node->left, val);
    }else {
        // đã tìm thấy
        return node;
    }
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
    printf("Cây hiện tại: ");
    int a[] = {50, 25, 75, 10, 33, 56, 89, 4, 11, 40, 52, 61, 82, 95};
    int n = sizeof(a) / sizeof(int);
    for(int i = 0; i < n; i++) {
        insert(&tree.root, a[i]);
    }
    print(tree.root);
    printf("\n");
    // test hàm tìm kiếm
    int timKiem[] = {4, 89, 33, 61, 35};
    int m = sizeof(timKiem) / sizeof(int);
    for(int i = 0; i < m; i++) {
        printf("Tim gia tri cua %d trong cay: ", timKiem[i]);
        TreeNode* tmp = search(tree.root, timKiem[i]);
        if(!tmp) {
            printf("Khong tim thay\n");
        }else {
            printf("Tim thay!\n");
        }
    }
    printf("\n");
}