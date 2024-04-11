#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct NodeType {
    int data;
    struct NodeType* left, * right;
} TreeNode;

typedef struct queueNode {
    TreeNode *node;
    struct queueNode* next;
} qNode;

qNode* makeqNode(TreeNode* data) {
    qNode* newNode = (qNode*)malloc(sizeof(qNode));
    newNode->node = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct queue {
    qNode* head;
    qNode* tail;
} queue;

void init(queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

void push(queue* q, TreeNode* data) {
    qNode* newNode = makeqNode(data);
    if(q->head == NULL) {
        q->head = newNode;
        q->tail = q->head;
    }else {
        q->tail->next = newNode;
        q->tail = q->tail->next;
    }
}

void pop(queue* q) {
    if(q->head == q->tail) {
        init(q);
    }else {
        q->head = q->head->next;
    }
}

int isEmpty(queue* q) {
    if(q->head == NULL) return 1;
    else return 0;
}

TreeNode* front(queue* q) {
    return q->head->node;
}
//----------------------------------

TreeNode* makeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void makeRoot(TreeNode* root, int u, int v, char c) {
    if(c == 'L') root->left = makeNode(v);
    else root->right = makeNode(v);
}
// use for binary tree
// chú thích (u v c): node v là lá bên c của u
void insert1(TreeNode* Node, int u, int v, char c) {
    if(!Node) return;
    if(Node->data == u) {
        makeRoot(Node , u, v, c);
    }else {
        insert1(Node->left, u, v, c);
        insert1(Node->right, u, v, c);
    }
}

void BFS(TreeNode* root) {
    if(!root) return;
    queue q; init(&q);
    push(&q, root);
    printf("%d ", root->data);
    while(!isEmpty(&q)) {
        TreeNode* tmp = front(&q);
        pop(&q);
        if(tmp->left) {
            push(&q, tmp->left);
            printf("%d ", tmp->left->data);
        }
        if(tmp->right) {
            push(&q, tmp->right);
            printf("%d ", tmp->right->data);
        }
    }
}

void inoder(TreeNode* root) {
    if(!root) return;
    printf("%d ", root->data);
    inoder(root->left);
    inoder(root->right);
}

int main() {
    TreeNode* root = NULL;
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int u, v; char c;
        char tmp;
        scanf("%d%d", &u, &v);
        scanf("%c", &tmp); scanf("%c", &c);
        if(root==NULL) {
            root = makeNode(u);
            makeRoot(root, u, v, c);
        }else {
            insert1(root, u, v, c);
        }
    }
    BFS(root);
    // inoder(root);
    return 0;
}