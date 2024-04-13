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
        free(q->head);
        init(q);
    }else {
        qNode* tmp = q->head;
        q->head = q->head->next;
        free(tmp);
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


int main() {
    TreeNode* node1 = makeNode(3);
    TreeNode* node2 = makeNode(4);
    TreeNode* node3 = makeNode(5);
    queue q;
    init(&q);
    push(&q, node1);
    push(&q, node2);
    printf("%d\n", isEmpty(&q));
    printf("%d \n", front(&q)->data);
    pop(&q);
    printf("%d \n", front(&q)->data);
    pop(&q);
    printf("%d\n", isEmpty(&q));
    push(&q, node1);
    // push(&q, node1);
    // printf("%d\n", isEmpty(&q));
    printf("%d \n", front(&q)->data);
    return 0;
}