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

int parent[100];
int minHight = 1e9;
int end = -1;
int start = -1;

void min_path(TreeNode* root, int pr, int hight) {
    if(!root) return;
    if(!root->right && !root->left) {
        // đây là nốt lá
        if(hight < minHight) {
            end = root->data;
            minHight = hight;
        }
    }
    if(root->left) {
        parent[root->left->data] = root->data;
        min_path(root->left, root->data, hight + 1);
    }
    if(root->right) {
        parent[root->right->data] = root->data;
        min_path(root->right, root->data, hight + 1);
    }
}



void level_count(TreeNode* root, int curr_level, int level_arr[], int *max_count) {
    if(!root) return;
    level_arr[curr_level]++;
    if(level_arr[curr_level] > *max_count) {
        *max_count = level_arr[curr_level];
    }
    level_count(root->left, curr_level + 1, level_arr, max_count);
    level_count(root->right, curr_level + 1, level_arr, max_count);
}

void count_one_child(TreeNode* root, int* count) {
    if(!root) return;
    if((!root->left && root->right) || (root->left && !root->right)) {
        *count += 1;
    }
    if(root->left) {
        count_one_child(root->left, count);
    }
    if(root->right) {
        count_one_child(root->right, count);
    }
}

void count_only_left_child(TreeNode* root, int* count) {
    if(!root) return;
    if(!root->right && root->left) {
        *count += 1;
    }
    count_only_left_child(root->left, count);
    count_only_left_child(root->right, count);
}

void find_nearest(TreeNode* root, int *distance, int diff, int *nearest) {
    if(!root) return;
    if(abs(root->data - diff) < *distance) {
        *distance = abs(root->data - diff);
        *nearest = root->data;
    }
    find_nearest(root->left, distance, diff, nearest);
    find_nearest(root->right, distance, diff, nearest);
}

void solve(int n) {
    // init lai parent
    for(int i = 0; i < 100; i++) {
        parent[i] = 0;
    }
    minHight = 1e9;
    end = -1;
    start = -1;
    //---------------
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
    // ------- 3.1----------
    printf("3.1:\n");
    int duongdi[100] = {};
    int idx = 0;
    start = tree.root->data;
    min_path(tree.root, -1, 0);
    while(end!=start) {
        duongdi[idx++] = end;
        end = parent[end];
    }
    printf("The shortest path: ");
    printf("%d ", tree.root->data);
    for(int i = idx - 1; i >= 0; i--) {
        printf("%d ", duongdi[i]);
    }
    printf("\n");
    // ------- 3.2----------
    printf("3.2:\n");
    int level[100] = {}; // mảng lưu số lượng node có level là chỉ số
    int max_count = -1; // biến max count
    int max_level = -1;
    level_count(tree.root, 1, level, &max_count); // curr level = 1 nghĩa là gốc cây có level 1
    for(int i = 0; i < 100; i++) {
        if(level[i]) {
            printf("Number of level %d node: %d\n", i, level[i]);
            if(level[i] == max_count) {
                max_level = i;
            }
        }
    }
    printf("Level %d has the most nodes\n", max_level);
    // ------- 3.3----------
    printf("3.3:\n");
    int count_oneChild_node = 0;
    count_one_child(tree.root, &count_oneChild_node);
    printf("Tree has %d one child node\n", count_oneChild_node);
    // ------- 3.4----------
    printf("3.4:\n");
    int count_left = 0;
    count_only_left_child(tree.root, &count_left);
    printf("Tree has %d node which have only left child\n", count_left);
    printf("Difference: %d\n", count_oneChild_node - count_left);
    // ------- 3.5----------
    printf("3.5:\n");
    int diff = count_oneChild_node - count_left;
    int distance = 1e9;
    int nearest_val = 0;
    find_nearest(tree.root, &distance, diff, &nearest_val);
    printf("Nearest Node Value: %d\n", nearest_val);
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
