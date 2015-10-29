#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x80000000
using namespace std;

int a[100010];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int l, r, w, ln, rn;
		int ans = INF;
		int sum = 0;
		bool flag = false;
		l = 1, r = 0;
		while(1) {
			if(flag && r == n) break;
			if(sum < 0) {
				if(flag) break;
				sum = 0;	
				l = r + 1;
			}
			if(flag) w = r + n - l + 1;
			else w = r - l + 1;
			if(w == k)
				sum -= a[l++];
			if(l > n) break;
			printf("l: %d r: %d sum: %d\n", l, r, sum);
			if(sum > ans && l != r + 1)
				ln = l, rn = r, ans = sum;	
			r++;
			if(r > n)
				flag = true, r = 1;
			sum += a[r];
			printf("l: %d r: %d sum: %d\n", l, r, sum);
			if(sum > ans)
				ln = l, rn = r, ans = sum;	
		}
		printf("%d %d %d\n", ans, ln, rn);
	}
	return 0;
}
