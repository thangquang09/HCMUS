#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node Node;


struct Node* makeNode(int data) {
    struct Node*p = (struct Node*) malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    return p;
}

struct Node* head;

void insertHead(int data, struct Node** head) {
    struct Node* p = makeNode(data);
    p->data = data;
    if(*head != NULL) {
        p->next = *head;
    }
    *head = p;
}

void printList(struct Node *head) {
    if(head != NULL) {
        printf("%d ", head->data);
        printList(head->next);
    }
}

int main() {
    struct Node* head = NULL;
	for(int i = 0; i < 3; i++) {
        insertHead(i, &head);
    }
    printList(head);
}