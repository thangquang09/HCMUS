// LÝ QUANG THẮNG - 22110202
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
	for(Node* p = list->head; p != NULL; p = p->next) {
		printf("Node address: %p | Node data: %d | Next Node address: %p\n", p, p->data, p->next);
	}
	printf("\n");
}


Node* Recursion(Node* head) {
    if(head == NULL) return NULL; // Nếu list rỗng
    if(head->next == NULL) return head; // Là node cuối cùng của list
    return Recursion(head->next);
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    LinkedList list;
    init(&list);
    // Giả sử list có những giá trị sau:
    int a[5] = {1, 2, 3, 5, 10}; int n = 5;
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nList: \n");
    for(int i = 0 ; i < n; i++) {
        insertTail(a[i], &list);
    }
    printList(&list);   
    printf("Last node of list:\n");
    Node* lastNode = Recursion(list.head);
    if(list.head != NULL) {
        printf("Node address: %p | Node data: %d | Next Node address: %p\n", lastNode, lastNode->data, lastNode->next);
    }else {
        printf("Empty list!\n");
    }
    /*
    Phân tích hàm đệ quy 4 bước
    Bước 1: Base case: Có 2 base case là
        - if(head == NULL) return NULL; (1)
        - if(head->next == NULL) return head; (2)
    Bước 2: Kết quả base case:
        - (1) trả về con trỏ NULL nếu list ban đầu rỗng
        - (2) trả về head nghĩa là con trỏ hiện tại khi head->next là NULL
    Bước 3: Trường hợp trước base case:
        Là trước khi head->next = NULL nghĩa là head->next->next = NULL; (nếu có)
        Kết quả: Như list trên thì trường hợp này trả về con trỏ quản lý data = 5
    Bước 4: Trường hợp trước tính từ bước 3:
        Là head->next->next->next là NULL (nếu có)
        Kết quả: Như list trên thì trường hợp này trả về con trỏ quản lý data = 3
    */
    return 0;
}