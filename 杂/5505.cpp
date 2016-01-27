#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef unsigned long long LL;

LL primea[1000][2], primeb[1000][2];
int alen, blen;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		LL n, m;
		scanf("%llu%llu", &n, &m);
		alen = blen = 0;
		memset(primea, 0, sizeof(primea));
		memset(primeb, 0, sizeof(primeb));
		if(n == m) printf("0\n");
		else {
			for(LL i = 2; i * i <= n; i++)		
				if(n % i == 0) {
					primea[++alen][0] = i;
					while(n % i == 0) primea[alen][1]++, n /= i;
				} 
			if(n != 1) primea[++alen][0] = n, primea[alen][1]++;
			for(LL i = 2; i * i <= m; i++)		
				if(m % i == 0) {
					primeb[++blen][0] = i;
					while(m % i == 0) primeb[blen][1]++, m /= i;
				} 
			if(m != 1) primeb[++blen][0] = m, primeb[blen][1]++;
			if(alen != blen) {
				printf("-1\n");
				continue;
			}
			bool flag = true;
			for(int i = 1; i <= alen; i++)
				if(primeb[i][0] != primea[i][0]) {
					flag = false;
					break;
				}
			if(flag == false) {
				printf("-1\n");
				continue;
			}
			int ans = 0;
			flag = true;
			for(int i = 1; i <= alen; i++) {
				if(primeb[i][1] < primea[i][1]) {
					flag = false;
					break;
				}
				ans = max(ans, (int)ceil(log((double)primeb[i][1] / (double)primea[i][1]) / log(2)));
			}
			if(flag == false) printf("-1\n");
			else printf("%d\n", ans);

		}
	}
	return 0;
}
