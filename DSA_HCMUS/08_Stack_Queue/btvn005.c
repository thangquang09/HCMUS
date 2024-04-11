#include <stdio.h>
#include<stdlib.h>
#define MAX 30
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


void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min_idx])
                min_idx = j;
        }
        swap(&a[i], &a[min_idx]);
    }
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
        // printf("Queue is empty!\n");
        return;
    }
    // Tim index can xoa
    int index = value;
    // for(int i = 0; i < MAX; i++) {
    //     if(q->a[i] == value){
    //         index = i;
    //         break;;
    //     }
    // }
    if(index == -1) {
        // printf("Khong tim thay\n");
        return;
    }else {
        // printf("\nXoa index = %d, value = %d\n", index, value);
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

int solve(Queue *q) {
    if(isEmpty(q)) {
        return 0;
    }
    int count = 0;
    for(int i = q->head; i <= q->tail && !isEmpty(q); i++) {
        if(q->a[i] == 1) {
            cancelRegistration(q, i);
            i-=1;
            count += 1;
        }else q->a[i]--;
    }
    return count;
}

int main() {
    Queue q;
    init(&q);
    int k, n;
    int num[MAX];
    scanf("%d%d", &k, &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    // selectionSort(num, n);
    for(int i = 0; i < k; i++) {
        put(&q, num[i]);
    }
    int totaltime = 0;
    int totalnum = k;
    displayQueue(&q);
    while(!isEmpty(&q)){
        totaltime++;
        int cnt = solve(&q);
        if(totalnum < n) {
            for(int i = totalnum; i < totalnum + cnt; i++) put(&q, num[i]);
        }
        totalnum += cnt;
    displayQueue(&q);
    }
    printf("total_time = %d\n", totaltime);


}