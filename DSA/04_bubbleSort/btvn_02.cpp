
#include<stdio.h>

void deleteArray(int a[], int *n, int idx) {
	for(int i = idx; i < *n - 1; i++) {
		a[i] = a[i + 1];
	}
	(*n)--;
}

void input(int a[], int *n) {
	printf("INPUT:\n");
	scanf("%d", n);
	for(int i = 0; i < *n; i++) {
		scanf("%d", &a[i]);
	}
}

void output(int a[], int n) {
	printf("\nOUTPUT:\n");
	for(int i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
}

void linearSearch(int a[], int *n){
	for(int i = 0; i < *n; i++) {
		for(int j = i + 1; j < *n; j++) {
			if(a[j] == a[i]) {
				deleteArray(a, n, j);
			}
		}
	}
}

void bubbleSort(int a[], int *n) {
	for(int i = 0; i < *n - 1; i++) {
		for(int j = 0; j < *n - i - 1; j++) {
			if(a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	int value = a[0];
	int i = 1;
	while(i < *n) {
		if(a[i] == value) {
			deleteArray(a, n, i);
		}else{
			value = a[i];
			i++;
		}
	}
}

int main() {
	int a[100];
	int b[100];
	int n, m;
	input(a, &n);
	for(int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	m = n;
	linearSearch(a, &n);
	output(a, n);
	bubbleSort(b, &m);
	output(b, m);
}

