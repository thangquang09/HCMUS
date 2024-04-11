#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct NodeType {
    int data;
    struct NodeType* next;
} Node;

typedef struct LinkedListType {
    Node* head;
} LinkedList;

void init(LinkedList* list) {
    list->head = NULL;
}

Node* makeNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
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
    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void insert(LinkedList *list, int data) {
    Node* newNode = makeNode(data);
    if(list->head == NULL) {
        list->head = newNode;
        return;
    }
    if(list->head->data <= data) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }
    Node* tmp = list->head;
    while(tmp->next != NULL && tmp->next->data > data) {
        tmp = tmp->next;
    }
    newNode->next=tmp->next;
    tmp->next = newNode;
}

void delete1(LinkedList *list, int value) {
    if(list->head == NULL) {
        return;
    }
    if(list->head->data == value) {
        Node* tmp = list->head;
        list->head = list->head->next;
        free(tmp);
        return;
    }
    Node* truoc = NULL;
    Node* sau = list->head;

    while(sau->next != NULL && sau->data < value) {
        truoc = sau;
        sau = sau->next;
    }

    if(sau->data == value) {
        truoc->next = sau->next;
        free(sau);
    }

    return;
}



int main() {
    LinkedList list;
    init(&list);
    int a[] = {7, 5, 4};
    // gia su list ban dau co nhung phan tu nhu mang a
    for(int i = 0; i < 3; i++) {
        insertTail(a[i], &list);
    }
    // 2 a)
    printf("CAU 2a\n");
    printf("List ban dau: "); printList(&list);
    int chen[] = {10, 2, 6};
    for(int i = 0; i < 3; i++) {
        printf("List sau khi chen %d: ", chen[i]);
        insert(&list, chen[i]);
        printList(&list);
    }

    printf("CAU 2b\n");
    init(&list);
    int b[] = {4, 5, 9, 10, 20};
    for(int i = 0; i < 5; i++) {
        insertTail(b[i], &list);
    }
    printf("List ban dau: "); printList(&list);
    int xoa[] = {100, -1, 3, 4, 20, 9};
    for(int i = 0; i < 6; i++) {
        printf("List sau khi xoa %d: ", xoa[i]);
        delete1(&list, xoa[i]);
        printList(&list);
    }
    return 0;
}