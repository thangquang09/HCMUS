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
// Hàm tìm node đầu tiên nhỏ hơn val
TreeNode* minNode(TreeNode* node) {
    TreeNode* tmp = node;
    while(tmp != NULL && tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

void hello() {
    printf("hello world\n");
}

void deleteNode(TreeNode** node, int val) {
    if(!(*node)) return; // không tồn tại val trong cây
    if(val > (*node)->data) {
        deleteNode(&(*node)->right, val);
    }else if(val < (*node)->data) {
        deleteNode(&(*node)->left, val);
    }else {
        // Nếu node này k có lá
        if(!(*node)->left && !(*node)->right) {
            free(*node);
            *node = NULL;
        }
        // Nếu node này chỉ có lá phải
        else if(!(*node)->left) {
            TreeNode* tmp = (*node)->right;
            *node = tmp;
        }
        // Nếu node này chỉ có lá trái
        else if(!(*node)->right) {
            TreeNode* tmp = (*node)->left;
            *node = tmp;
        }
        // Nếu node này có cả 2 lá
        else {
            // ta đi tìm Node nhỏ nhất lớn hơn val
            TreeNode* tmp = minNode((*node)->right);
            // gán giá trị của tmp cho node và xóa tmp
            (*node)->data = tmp->data;
            deleteNode(&(*node)->right, tmp->data);
        }
    }
}


// Lê Trường
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

// TreeNode* minNode(TreeNode* root) {
//     TreeNode* tmp = root;
//     while (tmp && tmp->left) tmp = tmp->left;
//     return tmp;
// }

void deleteNode23(TreeNode** root, int val) {
    TreeNode* curr = *(root);
    while (1) {
        if(!curr) return;
        else if(val < curr->data) {
            curr = curr->left;
        }else if(val > curr->data) {
            curr = curr->right;
        }else {
            if(!curr->left && !curr->right) {
                curr = NULL;
                free(curr);
            }else if(!curr->left) {
                TreeNode* tmp = curr->right;
                curr = tmp;
            }else if(!curr->right) {
                TreeNode* tmp = curr->left;
                curr = tmp;
            }else {
                TreeNode* tmp = minNode(curr->right);
                curr->data = tmp->data;
                curr = curr->right;
                val = tmp->data;
            }
        }
    }
}


int main() {
    BinaryTree tree;
    init(&tree);
    //insert cây ở câu 1.1.3
    printf("Tree: ");
    int c[] = {50, 25, 75, 10, 33, 56, 89, 4, 11, 40, 52, 61, 82, 95};
    for(int i = 0; i < 14; i++) {
        insert(&tree.root, c[i]);
    }
    print(tree.root);
    printf("\n");
    printf("Delete test:\n");
    int deleteVal[] = {35, 61, 33, 89, 75};
    int n = sizeof(deleteVal)/sizeof(int);
    for(int i = 0; i < n; i++) {
        printf("Tree after deleted %d: ", deleteVal[i]);
        deleteNode23(&tree.root, deleteVal[i]);
        print(tree.root);
        printf("\n");
    }
    return 0;
}
