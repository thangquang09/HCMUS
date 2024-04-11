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


void deleteHead(LinkedList* list) {
    if(list->head == NULL)
        return;
    list->head = list->head->next;
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

int main(){
    LinkedList list;
    init(&list);
    //Tạo danh sách tự động
    for(int i = 0; i < 10; i++)
        insertHead(i, &list);
    //In danh sách
    printList(&list);
    return 0;
}