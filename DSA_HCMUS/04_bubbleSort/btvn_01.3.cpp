
#include<stdio.h>

struct boBa {
	float a, b, c;
	float F;
	void makeF() {
		F = a - 2*b + 3*c;
	}
};

void input(boBa arr[100], int *n) {
	scanf("%d", n);
	for(int i = 0; i < *n; i++){
		scanf("%f%f%f", &arr[i].a, &arr[i].b, &arr[i].c);
		arr[i].makeF();
	}
}

void BBsort(boBa arr[], int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(arr[j].F > arr[j + 1].F) {
				boBa tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void output(boBa arr[], int n){
	for(int i = 0; i < n; i++) {
		printf("arr[%d]: (%.2f, %.2f, %.2f) voi F[%d] = %.2f\n", i, arr[i].a, arr[i].b, arr[i].c, i, arr[i].F);
	}
}

int main(){
	boBa a[100];
	int n;
	input(a, &n);
	BBsort(a, n);
	output(a, n);
}

