#include <bits/stdc++.h>
using namespace std;

int a[10010];

int main() {
	int n;
	scanf("%d", &n);
	int ans, sum = 0;
	int first, last;
	int First, Last;
	first = 1, ans = 0x80000000;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		if(sum > ans) ans = sum, last = i, First = first, Last = last;
		if(sum < 0) sum = 0, first = i + 1;
	}
	if(ans < 0) printf("%d %d %d\n", 0, a[1], a[n]);
	else printf("%d %d %d\n", ans, a[First], a[Last]);
	return 0;
}
