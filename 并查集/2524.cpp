#include <stdio.h>

int parent[50010];

int getp(int x) {
	if(parent[x] == x)
		return x;
	return getp(parent[x]);
}

int main() {
	int n, m;
	int t = 1;
	while(~scanf("%d%d", &n, &m) && (n || m)) {
		for(int i = 1; i <= n; i++)	
			parent[i] = i;
		int a, b; 
		for(int i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			int p1, p2;
			p1 = getp(a);
			p2 = getp(b);
			if(p1 != p2)
				parent[p1] = p2;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
			if(parent[i] == i)
				ans++;
		printf("Case %d: %d\n", t++, ans);
	}
	return 0;
}
