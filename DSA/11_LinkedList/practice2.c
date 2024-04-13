#include <stdio.h>
#include <stdlib.h>

//Định nghĩa node
typedef struct NodeType {
    int data;
    struct NodeType* next;
}Node;

//Định nghĩa Linked list
typedef struct LinkedListType{
    Node* head;
}LinkedList;

//Khởi tạo linked list
void init(LinkedList* list) {
    list->head = NULL;
}

//Hàm tạo node mới
Node* makeNode(int data){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    return p;
}

//Hàm chèn node mới vào đầu danh sách
void insertHead(int data, LinkedList* list){
    Node *p = makeNode(data);
    p->next = list->head;
    list->head=p;
}
// Hàm chèn node mới vào cuối danh sách
void insertTail(int data, LinkedList* list) {
    Node* p = makeNode(data);
    if(list->head == NULL) {
        list->head = p;
    }else {
        Node* tmp = list->head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = p;
    }
}
// Hàm xóa node ở đầu
void deleteHead(LinkedList* list) {
    if(list->head == NULL)
        return;
    Node* tmp = list->head;
    list->head = list->head->next;
    free(tmp);
}
// Hàm xóa node ở đuôi
void deleteTail(LinkedList* list) {
    if(list->head == NULL)
        return;
    Node *tmp = list->head;
    if(tmp->next == NULL) {
        list->head = NULL;
        free(tmp);
        return;
    }
    while(tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    Node *last = tmp->next; //node cuoi
    tmp->next = NULL;
    free(last);
}

void printList(LinkedList* list){
    Node* node = list->head;
    while(node!=NULL) {
        printf("Node address: %p | ", &(node->data));
        printf("Node data: %d | ", node->data);
        printf("Next node address : %p | ", (node->next));
        printf("\n");
        node = node->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    init(&list);

    int a[] = {2, 12, 9, 0, 11, 3, 4, 8};
    int n = sizeof a / sizeof(int);
    // 1.
    for(int i = 0; i < n; i++) {
        insertTail(a[i], &list);
    }
    // printList(&list);
    // 2.
    // a.
    insertHead(19,&list);
    printList(&list);
    //b.
    insertTail(-3,&list);
    printList(&list);
    // 3.
    // a.
    deleteHead(&list);
    printList(&list);
    // b.
    deleteTail(&list);
    printList(&list);
}
