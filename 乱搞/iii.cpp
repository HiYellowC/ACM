#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Tv {
	int start, end;
};

Tv a[110];

bool cmp(Tv x, Tv y) {
	return x.end < y.end;
}

int main() {
	int n;
	while(~scanf("%d", &n) && n) {
		for(int i = 1; i <= n; i++)
			scanf("%d%d", &a[i].start, &a[i].end);
		sort(a + 1, a + 1 + n, cmp);
		int ans = 1;
		int T = a[1].end;
		for(int i = 2; i <= n; i++) {
			if(a[i].start >= T) {
				T = a[i].end;
				ans++;
			}	
		}
		printf("%d\n", ans);
	}
	return 0;
}
