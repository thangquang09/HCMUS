#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Nodetype{
    int data;
    struct Nodetype* next;
}Node;

Node* makeNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct Queuetype {
    Node* head;
    Node* tail;
}Queue;

void init(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}


int isEmpty(Queue *q) {
    if(q->head == NULL) return 1;
    return 0;
}

void push(Queue *q, int data) {
    Node* newNode = makeNode(data);
    if(q->head == NULL) {
        q->head = newNode;
        q->tail = q->head;
    }else {
        q->tail->next = newNode;
        q->tail = q->tail->next;
    }
}

void pop(Queue *q) {
    if(q->head == NULL) return;
    if(q->head == q->tail) {
	    free(q->head);
	    init(q);
    }else {
	    Node* tmp = q->head;
	    q->head = q->head->next;
	    free(tmp);
    }
}

int size(Queue q) {
    int cnt = 0;
    while(q.head != NULL) {
        ++ cnt;
        q.head = q.head->next;
    }
    return cnt;
}

int front(Queue q) {
    return q.head->data;
}

void duyet(Queue q) {
    while(q.head != NULL) {
        printf("%d ", q.head->data);
        q.head = q.head->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    init(&q);

    while(1) {
        printf("---------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Front\n");
        printf("4. Size\n");
        printf("5. Duyet\n");
        printf("0. OUT\n");
        printf("---------------\n");
        int lc; scanf("%d", &lc);
        if(lc == 1) {
            int x; printf("nhap data: "); scanf("%d", &x);
            push(&q, x);
        }else if(lc == 2) {
            pop(&q);
        }else if(lc == 3) {
            if(q.head != NULL) {
                printf("Top: %d\n", front(q));
            }
        }else if(lc == 4) {
            printf("Size: %d\n", size(q));
        }else if(lc == 5) {
            duyet(q);
        }else if(lc == 0) break;
    }
    return 0;
}