#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 50010;

int n, m;

int a[MAXN], b[MAXN];

int Max1[MAXN], Max2[MAXN];

int sum[MAXN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
		memset(Max1, 0x80, sizeof(Max1));
		memset(Max2, 0x80, sizeof(Max2));
		memset(sum, 0, sizeof(sum));
		int dex;
		for(int i = 1; i <= m; i++) {
			scanf("%d", &dex);
			sum[dex]++;
		}
		int ans = 0;
		for(int i = n; i >= 1; i--) {
			Max1[i] = Max1[i + 1] - sum[i], Max2[i] = Max2[i + 1] - sum[i];
			if(a[i] == 1 && b[i] < Max2[i]) ans++;	
			if(a[i] == 0 && b[i] < Max1[i]) ans++;	
			if(a[i] == 1) Max1[i] = max(b[i], Max1[i]);
			else Max2[i] = max(b[i], Max2[i]);
		}
		printf("%d\n", n - ans);
	}
	return 0;
}
