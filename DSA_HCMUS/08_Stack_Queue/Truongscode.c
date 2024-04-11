#include <stdio.h>
#include <stdlib.h>

#define MAX 7

int flag = -1e9 + 7;

typedef struct {
    int head, tail;
    int a[MAX + 1];
} C_Queue;

void init(C_Queue* q) {
    q->head = 0;
    q->tail = -1;
}

int isEmpty(C_Queue *q) { return q->head == 0 && q->tail == -1; }

int isFull(C_Queue *q) { return (isEmpty(q) ? 0 : (q->tail + 1 == q->head) || (q->head == 0 && q->tail == MAX - 1)); }

void put(C_Queue* q, int value) {
    if (q->head <= q->tail && q->tail + 1 < MAX) q->a[++q->tail] = value;

    else {
        for (int i = 0; i <= q->head; i++) {
            if (q->a[i] == flag) {
                q->a[q->tail = i] = value;
                return;
            }
        }
    }
}

int get(C_Queue* q) {
    int tmp = q->a[q->head];

    if (q->head == q->tail) {
        q->a[q->head] = flag;
        q->head = 0;
        q->tail = -1;
    }

    else if (q->head + 1 < MAX) q->a[q->head++] = flag;

    else {
        for (int i = 0; i <= q->tail; i++) {
            if (q->a[i] != flag) {
                q->a[q->head] = flag;
                q->head = i;
                break;
            }
        }
    }

    return tmp;
}

void displayQueue(C_Queue* q) {
    if (isEmpty(q)) {
        printf("NULL\n");
        return;
    }

    for (int i = 0; i <= MAX - 1; i++) if (q->a[i] != flag) printf("%d ", q->a[i]);
}

int main() {
    C_Queue q;
    init(&q);
    printf("%d", isFull(&q));
    // int num[] = {-5, 2, 4, -3, 1, 0, 9};

    // for (int i = 0; i <= MAX; i++) q.a[i] = flag;

    // for (int i = 0; i < sizeof num / sizeof num[0]; i++) {
    //     printf("Put %d:\n", num[i]);

    //     if(!isFull(&q)){
    //         put(&q, num[i]);
    //         displayQueue(&q);
    //         printf("\n");
    //     }

    //     else printf("Queue is full.\n");
    // }

    // printf("\n");

    // int loopGet = 3;
    // for (int i = 1; i <= loopGet; i++) {
    //     if (!isEmpty(&q)) printf("Get %d:\n", get(&q));
    //     displayQueue(&q);
    //     printf("\n");
    // }

    // printf("\n");
    // printf("\nhead : %d tail: %d\n", q.head, q.tail);
    // int putArr[] = {8, 4, -3, -4};
    // for (int i = 0; i < sizeof putArr / sizeof putArr[0]; i++) {
    //     printf("Put %d:\n", putArr[i]);

    //     if(!isFull(&q)){
    //         put(&q, putArr[i]);
    //         displayQueue(&q);
    //         printf("\n");
    //     }

    //     else printf("Queue is full.\n\n");
    // }
    // printf("\nhead : %d tail: %d\n", q.head, q.tail);
    // printf("%d", isFull(&q));
    return 0;
}
