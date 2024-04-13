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

void insertFirst(int data, LinkedList *list) {
    Node* newNode = makeNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

void insertK(int data, LinkedList *list, int pos) {
    int n = size(list);
    if(pos < 1 || pos > n + 1) return;
    if(pos == 1) {
        insertFirst(data, list);
    }else {
        Node* tmp = list->head;
        for(int i = 1;i <= pos - 2; i++) {
            tmp = tmp->next;
        }
        Node *newNode = makeNode(data);
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

void deleteFirst(LinkedList* list) {
    if(list->head == NULL)
        return;
    Node* tmp = list->head;
    list->head = list->head->next;
    free(tmp);
}

void deleteK(LinkedList *list, int pos) {
    int n = size(list);
    if(pos < 1 || pos > n) return; // ko hop le
    if(pos == 1) deleteFirst(list);
    else {
        Node* tmp = list->head;
        for(int i = 1; i <= pos - 2; i++) {
            tmp = tmp->next;
        }
        // tmp = pos - 1
        Node* kth = tmp->next; //node thu pos
        // cho pos - 1 ket noi voi node thu pos + 1
        tmp->next = kth->next;
        free(kth);
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

int main() {
    LinkedList list;
    init(&list);
    int a[] = {2, 3, 4, 5, 6, 7};
    int n = sizeof(a)/sizeof(int);
    for(int i = 0; i < n; i++) {
        insertK(a[i], &list, size(&list) + 1);
    }
    // cau a:
    insertK(1, &list, 2);
    printList(&list);

    // cau b:
    deleteK(&list, 2);
    printList(&list);
    return 0;
}