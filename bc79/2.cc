#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

LL ans;

void dfs(LL a, LL b, LL c, LL d, int dex, LL tmp) {
	if(dex == -1) {
		ans = max(tmp, ans);
		return ;
	}	
	LL aa = (a >> dex) & 1;
	LL bb = (b >> dex) & 1;
	LL cc = (c >> dex) & 1;
	LL dd = (d >> dex) & 1;
	if(aa == bb && cc == dd) dfs(a, b, c, d, dex - 1, (tmp << 1) | (aa ^ cc));
	else if(aa != bb && cc != dd) {
		ans = max((((tmp << 1) | 1) << dex) | (((LL)1 << dex) - 1), ans);
		return ;
		//dfs(a, (bb << dex) - 1, cc << dex, d, dex - 1, (tmp << 1) | 1);	
		//dfs(aa << dex, b, c, (dd << dex) - 1, dex - 1, (tmp << 1) | 1);
	}
	else if(aa != bb) {
		if(cc == 1) dfs(a, (bb << dex) - 1, c, d, dex - 1, (tmp << 1) | 1);
		else dfs((aa << dex), b, c, d, dex - 1, (tmp << 1) | 1);
	}
	else {
		if(aa == 1) dfs(a, b, c, (dd << dex) - 1, dex - 1, (tmp << 1) | 1);
		else dfs(a, b, cc << dex, d, dex - 1, (tmp << 1) | 1);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		LL a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		ans = 0;
		dfs(a, b, c, d, 62, 0);
		printf("%lld\n", ans);
	}
	return 0;
}

