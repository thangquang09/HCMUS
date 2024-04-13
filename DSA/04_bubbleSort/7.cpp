#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(int a, int b) {
	if(a % 2 == 1 && b % 2 == 0) return true;
	if(a % 2 == 0 && b % 2 == 1) return false;
	
	if(a % 2 == 0 && b % 2 == 0) return a < b;
	else return a > b;
}

int main(){
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, cmp);
	for(int x : a) cout << x << " " ;
}

