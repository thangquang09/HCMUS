#include <stdio.h>
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
    int numval = 0;
    if(q->head < q->tail) {
        numval += q->tail - q->head + 1;
        if(numval == MAX)
            return 1;
        else return 0;
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
    printf("\nQueue: ");
    for(int i = 0; i < MAX; i++) {
        if(q->a[i] != INT_MIN) {
            printf("%4d ", q->a[i]);
        }else printf("null ");
    }
    printf("\n");
}


int main() {
    Queue q;
    init(&q);
    int num1[7] = {-5, 2, 4, -3, 1, 0, 9};

    for(int i = 0; i < 7; i++) {
        if(!isFull(&q)) {
            printf("Put %d", num1[i]);
            put(&q, num1[i]);
        }else {
            printf("Stack is full!");
        }
        displayQueue(&q);
    }

    for(int i = 0; i < 8; i++) {
        if(!isEmpty(&q)) {
            printf("Get %d",get(&q));
            displayQueue(&q);
        }else {
            printf("Queue is empty!\n");
        }
    }

    for(int i = 0; i < 7; i++) {
        if(!isFull(&q)) {
            printf("Put %d", num1[i]);
            put(&q, num1[i]);
        }else {
            printf("Stack is full!");
        }
        displayQueue(&q);
    }
    return 0;

}