#include<stdio.h>
#define MAX 20


int n;
int Bool[MAX] = { 0 };//Đánh dấu chưa có phần tử nào sử dụng hết
int A[MAX];//Lưu hoán vị vào mảng A

void xuat() {
	for (int i = 1; i <= n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void Try(int k) {
	for (int i = 1; i <= n; i++) {
		//Kiểm tra nếu phần tử chưa được chọn thì sẽ đánh dấu
		if (!Bool[i]) {
			A[k] = i; // Lưu một phần tử vào hoán vị
			Bool[i] = 1;//Đánh dấu đã dùng
			if (k == n)//Kiểm tra nếu đã chứa một hoán vị thì xuất
				xuat();
			else
				Try(k + 1);
			Bool[i] = 0;
		}
	}
}

int main() {
	int n; scanf("%d", &n);
	Try(1);
}