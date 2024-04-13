#include<stdio.h>

void BBsort(char a[], int n) { 
	for(int i = 0; i < n - 1; i++) {
		for(int j = 1; j < n - i - 1; j++) {
			if(a[j - 1] > a[j]) {
				char tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = a[j - 1];
			}
		}
	}
}

void output(char a[], int n) {
	for(int i = 0; i < n; i++) {
		printf("%c ", a[i]);
	}
	printf("\n");
}

int main(){
	char a[100];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%c", &a[i]);
	}
	BBsort(a, n);
	output(a, n);
}

