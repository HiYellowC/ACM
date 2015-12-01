#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int a[MAXN];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int l = 1;
	int r = n;
	while(1) {
		if(l == r) break;
		if(a[l] + a[r] == m) break;	
		else if(a[l] + a[r] < m) l++;
		else r--;
	}
	if(a[l] + a[r] == m && l < r) printf("%d %d\n", a[l], a[r]);
	else printf("No Solution\n");
	return 0;
}
