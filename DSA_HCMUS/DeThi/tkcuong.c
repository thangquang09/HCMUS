#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void f(int a[], int n, int *sosanh, int *hoanvi) {
    *sosanh += *sosanh + 1;
    *hoanvi += *hoanvi + 1;
}
void innitialArray(int a[], int n, int min, int max) {
    for(int i = 0; i < n; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
}
void ans(int a[],int n,int vonglap)
{
    printf("So vong lap: %d\n", vonglap);
    int fre_hoanvi[100] = {};
    int fre_sosanh[100] = {};
    int tongHoanVi = 0, tongSoSanh = 0;
    for(int i=0; i<vonglap; i++)
    {
        innitialArray(a,n,-100,100);
        int hoanvi=0, sosanh=0;
        f(a,n,&hoanvi,&sosanh);
        fre_hoanvi[hoanvi]++;
        fre_sosanh[sosanh]++;
        tongHoanVi+=hoanvi;
        tongSoSanh+=sosanh;
    }
    // in ra bang tan suat
    printf("So lan: ");
    for(int i=0; i<50; i++)
    {
        printf("%d ", i);
    }
    printf("\nSo sanh: ");
    for(int i=0; i<50; i++) 
    {
        printf("%d ", fre_sosanh[i]);
    }
    printf("\nHoan vi: ");
    for(int i=0; i<50; i++) {
        printf("%d ", fre_hoanvi[i]);
    }
    printf("\nTrung binh so sanh: %f\n",(float)tongSoSanh/vonglap);
    printf("\nTrung binh hoan vi: %f\n",(float)tongHoanVi/vonglap);
    printf("\n");
}


int main() {
    time_t t;
    srand((unsigned)time(&t));
    int a[10] = {};
    int n = 10;
    ans(a, n, 100);


    return 0;
}