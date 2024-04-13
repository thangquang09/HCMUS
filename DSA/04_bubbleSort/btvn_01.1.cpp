#include<stdio.h>

void BBsort(float a[], int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

void output(float a[], int n) {
	for(int i = 0; i < n; i++) {
		printf("%f ", a[i]);
	}
	printf("\n");
}

int main(){
	float a[100];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%f", &a[i]);
	}
	BBsort(a, n);
	output(a, n);
}

