#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;

struct LinkedList {
    Node* head;
};
typedef struct LinkedList LinkedList;

void init(LinkedList *list) {
	list->head = NULL;
}

Node* makeNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int size(LinkedList *list) {
    int size = 0;
    Node* tmp = list->head;
    while(tmp != NULL) {
        size += 1;
        tmp = tmp->next;
    }
    return size;
}

void insertTail(int data, LinkedList *list) {
    Node* newNode = makeNode(data);
    if(list->head == NULL) {
        list->head = newNode;
    }else {
        Node* tmp = list->head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

void printList(LinkedList *list) {
    Node* tmp = list->head;
    while(tmp) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

// hamdequy 1.2

void insertK(int data, Node** curNode, int k) {
    if(k == 1) {
        Node* newNode = makeNode(data);
        newNode->next = *(curNode);
        (*curNode) = newNode;
        return;
    }

    if(k < 0 || curNode == NULL) return;

    if(k - 2 == 0) {
        Node* newNode = makeNode(data);
        newNode->next = (*curNode)->next;
        (*curNode)->next = newNode;
        return;
    }
    insertK(data, &(*curNode)->next, k - 1);
}

// hamdequy 1.2

void deleteK(Node** curNode, int k) {
    // xoa dau`
    if(k == 1) {
        if(*curNode == NULL) return;
        Node* tmp = *curNode;
        (*curNode) = (*curNode)->next;
        free(tmp);
        return;
    }
    if(*curNode == NULL || k < 0) return; // truong hop vi tri k hop le
    if(k - 2 == 0) {
        Node* kth = (*curNode)->next;
        (*curNode)->next = kth->next;
        free(kth);
        return;
    }
    deleteK(&(*curNode)->next, k - 1);
}


int main() {
    LinkedList list;
    init(&list);
    int a[] = {2, 3, 4, 5, 6, 7};
    int n = sizeof(a)/sizeof(int);
    for(int i = 0; i < n; i++) {
        insertTail(a[i], &list);
    }
    printList(&list);
    // 1.1
    insertK(1, &list.head, 2);
    printList(&list);
    // 1.2
    deleteK(&list.head, 1);
    printList(&list);
    return 0;
}