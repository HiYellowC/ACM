#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int a[100010];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, s;
		scanf("%d%d", &n, &s);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int l = 1;
		int r = 0;
		int sum = 0;
		int ans = INF;
		while(1) {
			if(sum < s) {
				r++;
				if(r > n) break;
				sum += a[r];
			}	
			else {
				if(r - l + 1 < ans)
					ans = r - l + 1;
				sum -= a[l];
				l++;
			}
		}
		if(ans == INF)
			printf("0\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
