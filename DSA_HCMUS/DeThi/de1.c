#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void DFS(TreeNode* root, int parent[], int hight, int *maxHight, int* end) {
    if(root == NULL) {
        return; // cay khong co gi ca
    }
    if(!root->left && !root->right) { // neu la` la' thi cap nhat
        if(*maxHight < hight) {
            *maxHight = hight;
            *end = root->data;
        }
    }
    if(root->left) {
        DFS(root->left, parent, hight + 1, maxHight, end);
    }
    if(root->right) {
        DFS(root->right, parent, hight + 1, maxHight, end);
    }
}

void sumMax(BinaryTree tree) {
    int parent[100000] = {};
    int start = tree.root->data;
    int end = -1;
    int maxHight = -1e9;
    DFS(tree.root, parent, 1, &maxHight, &end);
    if(end != -1) {
        int sum = tree.root->data;
        while(end != start) {
            sum += end;
            end = parent[end];
        }
        printf("sum: %d\n", sum);
    }else {
        printf("Not found!\n");
    }
}

int main() {
    int a[5] = {1, 2, 3, 4, 6};
    printf("%d", binarySearch(a, 0, 4, 5));
    return 0;
}