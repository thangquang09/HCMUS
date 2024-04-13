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

void print(TreeNode* Node) {
    if(!Node) return;
    print(Node->left);
    printf("%d ", Node->data);
    print(Node->right);
}

void init(BinaryTree* tree) {
    tree->root = NULL;
}

void makeRoot(TreeNode* root, int u, int v, char c) {
    if(c == 'L') root->left = makeNode(v);
    else root->right = makeNode(v);
}

// chú thích (u v c): node v là lá bên c của u
void insert(TreeNode* Node, int u, int v, char c) {
    if(!Node) return;
    if(Node->data == u) {
        makeRoot(Node , u, v, c);
    }else {
        insert(Node->left, u, v, c);
        insert(Node->right, u, v, c);
    }
}



void search(TreeNode* node, int val, int* check) {
    if(!node) return;
    if(node->data == val) {
        *check = 1;
    }
    search(node->left, val, check);
    search(node->right, val, check);
}


void solve(int n) {
    BinaryTree tree;
    init(&tree);
    printf("Input your %d edges tree:\n", n);
    for(int i = 0; i < n; i++) {
        int u, v; char c, khoangcach;
        scanf("%d%d", &u, &v); scanf("%c", &khoangcach);
        scanf("%c", &c);
        if(tree.root == NULL) {
            tree.root = makeNode(u);
            makeRoot(tree.root, u, v, c);
        }else {
            insert(tree.root, u, v, c);
        }
    }
    printf("Tree : ");
    print(tree.root);
    printf("\n");
}

int main() {
    // Copy dòng mã hóa và dán vào.
    // cay 1:
    // 1 2 L 1 3 R 2 4 L 2 5 R 4 8 L 4 9 R 5 10 L 5 11 R 3 6 L 3 7 R 6 12 L 6 13 R 7 14 L 7 15 R
    int n1 = 14; // là số cạnh của cây
    printf("Tree 1------------\n");
    solve(n1);
    // cay 2:
    // 50 17 L 50 76 R 17 9 L 17 23 R 9 14 R 14 12 L 23 19 L 76 54 L 54 72 R 72 67 L
    int n2 = 10; // là sô cạnh của cây
    printf("Tree 2------------\n");
    solve(n2);
    // cay 3:
    // 15 11 L 15 26 R 11 8 L 11 12 R 8 6 L 8 9 R 12 14 R 26 20 L 26 30 R 30 35 R
    int n3 = 10; // là số cạnh của cây
    printf("Tree 3------------\n");
    solve(n3);
    // cay 4:
    // 3 1 L 3 10 R 1 13 L 1 5 R 5 6 L 10 11 L 10 16 R 16 15 L 16 2 R 15 9 L 15 4 R
    int n4 = 11; // là số cạnh của cây
    printf("Tree 4------------\n");
    solve(n4);
    return 0;
}
