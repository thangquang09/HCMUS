#include<stdio.h>
#include<stdlib.h>

#define MAX 7
#define null INT_MIN

typedef struct {
    int head, tail;
    int a[MAX];
} Queue;

void init(Queue* q) {
    q->head = 0;
    q->tail = -1;
    for(int i = 0; i < MAX; i++) {
        q->a[i] = null;
    }
}

int isEmpty(Queue *q) {
    if(q->head == 0 && q->tail == -1) {
        return 1;
    }
    return 0;

}

int isFull(Queue *q) {
    if(q->head < q->tail) {
        if(q->tail == MAX - 1) return 1;
        return 0;
    }
    else{
        if(!isEmpty(q)) {
            if(q->tail + 1 == q->head) {
                return 1;
            }
            else return 0;
        }else {
            return 0;
        }
    }
}

void put(Queue* q, int value) {
    if(isFull(q)) {
        printf("\nQueue is full!\n");
        return;
    }
    if(q->tail < MAX - 1) { // 5
        q->tail += 1;
        q->a[q->tail] = value;
    }else {
        q->tail = -1;
        if(q->tail + 1 < q->head) {
            q->tail += 1;
            q->a[q->tail] = value;
        }else {
            q->tail = MAX - 1;
            // printf("Queue is full!\n");
        }
    }
}

int get(Queue* q) {
    if(isEmpty(q)) {
        return null;
    }
    int index = q->head;
    int value;
    if(q->head == q->tail) {
        // bao dong
        q->tail = -1;
        q->head = 0;
        value = q->a[index];
        q->a[index] = null;
    }else if(index == MAX - 1){
        value = q->a[index];
        q->a[index] = null; // danh dau phan tu da bi xoa
        q->head = 0;
    }else {
        value = q->a[index];
        q->a[index] = null;
        q->head += 1;
    }

    return value;
}

void displayQueue(Queue*q) {
    if(isEmpty(q)) {
        printf("Empty Queue!\n");
        return;
    }
    printf("\nQueue: ");
    if(q->head <= q->tail) {
        for(int i = q->head; i <= q->tail; i++) {
            printf("%3d ", q->a[i]);
        }
    }else {
        for(int i = q->tail; i < MAX; i++) {
            printf("%3d ", q->a[i]);
        }
        for(int i = 0; i <= q->head; i++) {
            printf("%3d ", q->a[i]);
        }
    }
    printf("\n");
}
void displayQueue1(Queue *q) {
    printf("\nQueue Status: ");
    for(int i = 0; i < MAX; i++) {
        if(q->a[i] != null) {
            printf("%4d ", q->a[i]);
        }else printf("null ");
    }
    printf("\n");
}
void deleteArray(int a[], int n, int index) {
    int len = n - 1;
    for(int i = index; i <= len; i++) {
        a[i] = a[i + 1];
    }
    a[n] = null;
}
void cancelRegistration(Queue *q, int value) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    // Tim index can xoa
    int index = -1;
    for(int i = 0; i < MAX; i++) {
        if(q->a[i] == value){
            index = i;
            break;;
        }
    }
    if(index == -1) {
        printf("Khong tim thay\n");
        return;
    }else {
        printf("\nXoa index = %d, value = %d\n", index, value);
    }
    // Xu ly---------------
    if(q->head <= q->tail) {
        deleteArray(q->a, q->tail, index);
        q->tail--;
    }else {
        if(index >= q->head) {
            for(int i = index; i < MAX - 1; i++) {
                q->a[i] = q->a[i + 1];
            }
            q->a[MAX - 1] = q->a[0];
            for(int i = 0; i < q->tail; i++) {
                q->a[i] = q->a[i + 1];
            }
            q->a[q->tail] = null;
        }else if (index <= q->tail){
            for(int i = index; i < q->tail; i++) {
                q->a[i] = q->a[i + 1];
            }
            q->a[q->tail] = null;
        }
        q->tail--;
    }
    if(q->tail + 1 == q->head) {
        q->head = 0; q->tail = -1; // Neu queue da rong thi reset lai
    }
}

int main() {
    // pass //
    Queue q;
    init(&q);
    int id[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    /////LUU Y : ham displayQueue() in ra theo thu tu tu head den tail, ham displayQueue1() in ra trang thai cua mang
    // Put 7 thang vao ---------------
    for(int i = 0; i < sizeof id / sizeof (int); i++) {
        put(&q, id[i]);
        // displayQueue1(&q);
    }
    printf("----------------------------\n");
    printf("\nSau khi put\n");
    displayQueue1(&q);
    // displayQueue1(&q);
    // Get 3 thang ra ---------------------
    for(int i = 0; i < 3; i++) {
        get(&q);
        // displayQueue1(&q);
    }
    printf("----------------------------\n");
    printf("\nSau khi get\n");
    // Xoa 4 thang ------------------------
    displayQueue1(&q);
    int xoa[] = {7, 6, 5, 4};
    for(int i = 0; i < sizeof xoa / sizeof (int); i++) {
        cancelRegistration(&q, xoa[i]);
        displayQueue(&q);
        displayQueue1(&q);
        printf("----------------------------\n");
    }
    // Sau khi xoa hang doi bi rong~
    return 0;
}