#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

LL sum[65];

void Init() {
	sum[1] = 1;
	for(int i = 2; i < 60; i++) sum[i] = 2 * sum[i - 1] - ((LL)1 << (i - 1)) + ((LL)1 << i);
}

int main() {
	Init();
	int t;
	scanf("%d", &t);
	while(t--) {
		LL M;
		scanf("%lld", &M);
		LL ans = 0;
		LL num = 0;
		while(M) {
			LL tmp = M + 1;
			int con = -1;
			while(tmp) tmp >>= 1, con++;
			LL x = ((LL)1 << con) - 1;
			M -= x;
			ans += sum[con] + (num * x);
			num++;
			if(M) ans += num, M--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

