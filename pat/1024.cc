#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 110;

int len, a[MAXN], b[MAXN];

bool check() {
	for(int i = 0; i <= (len - 1) / 2; i++)
		if(a[i] != a[len - 1 - i]) return false;
	return true;
}

void update() {
	int flag = 0;
	for(int i = 0; i <= len - 1; i++) {
		b[i] = a[i] + a[len - 1 - i] + flag;
		flag = 0;
		if(b[i] > 9) b[i] -= 10, flag = 1;
	}
	for(int i = 0; i <= len - 1; i++) a[i] = b[i];
	if(flag) a[len] = 1, len++;
}

void print() {
	for(int i = len - 1; i >= 0; i--) printf("%d", a[i]);
	printf("\n");
}

int main() {
	LL n;
	int k;
	scanf("%lld%d", &n, &k);
	do {a[len++] = n % 10, n /= 10;}while(n);
	int i;
	for(i = 0; i < k; i++) {
		if(check()) break;
		update();
	}
	print();
	printf("%d\n", i);
	return 0;
}
