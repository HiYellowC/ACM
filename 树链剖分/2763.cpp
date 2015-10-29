#include <iostream>
#include <cstdio>
#include <cstring>
#define Max 100010
using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")

int n, q, s;
int dex, Start[Max], Next[Max * 2], End[Max * 2], weight[Max];
int fa[Max], siz[Max], son[Max], dep[Max], top[Max], m[Max];
int T[Max << 2];

void Init() {
	dex = 0;
	memset(Start, 0, sizeof(Start));
	memset(son, 0, sizeof(son));
	memset(T, 0, sizeof(T));
	dep[1] = 0;
}

void BuildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
}

void dfs(int v, int p) {
	fa[v] = p;
	dep[v] = dep[p] + 1;
	siz[v] = 1;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != p) {
			dfs(to, v);	
			if(siz[son[v]] < siz[to])
				son[v] = to;
			siz[v] += siz[to];
		}
	}
}

void BuildT(int v, int tv) {
	m[v] = ++dex;
	top[v] = tv;
	if(son[v])
		BuildT(son[v], tv);
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != fa[v] && to != son[v])
			BuildT(to, to);
	}
}

void update(int left, int right, int x, int y, int i) {
	if(left == right) {
		T[i] = y;
		return ;
	}
	int mid = (left + right) >> 1;
	if(x <= mid)
		update(left, mid, x, y, i << 1);
	else
		update(mid + 1, right, x, y, i << 1 | 1);
	T[i] = T[i << 1] + T[i << 1 | 1];
}

int query(int left, int right, int l, int r, int i) {
	if(left >= l && right <= r)
		return T[i];
	int mid = (left + right) >> 1;
	int ans = 0;
	if(l <= mid)
		ans += query(left, mid, l, r, i << 1);
	if(r > mid)
		ans += query(mid + 1, right, l, r, i << 1 | 1);
	return ans;
}

int main() {
	while(~scanf("%d%d%d", &n, &q, &s)) {
		Init();
		int a, b, w;
		for(int i = 1; i < n; i++) {
			scanf("%d%d%d", &a, &b, &w);	
			BuildG(a, b);
			BuildG(b, a);
			weight[i] = w;	
		}
		dfs(1, 1);
//		for(int i = 1; i <= n; i++)
//			printf("v: %d fa: %d siz: %d son: %d dep: %d\n", i, fa[i], siz[i], son[i], dep[i]);
		dex = 0;
		BuildT(1, 1);
//		for(int i = 1; i <= n; i++)
//			printf("v: %d m: %d top: %d\n", i, m[i], top[i]);
		for(int i = 1; i < n; i++) {
			a = End[i * 2], b = End[i * 2 - 1];
			if(dep[a] < dep[b])
				swap(a, b);
			update(1, dex, m[a], weight[i], 1);
		}
//		for(int i = 1; i <= 5; i++)
//			printf("i: %d T: %d\n", i, T[i]);
		int sel;
		while(q--) {
			scanf("%d", &sel);	
			if(!sel) {
				int ans = 0;
				scanf("%d", &b);
				a = b;
				int top1, top2;
				top1 = top[a];
				top2 = top[s];
				while(top1 != top2) {
					if(dep[top1] > dep[top2])
						swap(top1, top2), swap(a, s);
					ans += query(1, dex, m[top2], m[s], 1);
					s = fa[top2];
					top2 = top[s];
				}
				if(a != s) {
					if(dep[a] > dep[s])
						swap(a, s);
					a = son[a];
					//printf("ma: %d ms: %d\n", m[a], m[s]);
					ans += query(1, dex, m[a], m[s], 1);
				}
				printf("%d\n", ans);
				s = b;
			}
			else {
				scanf("%d%d", &a, &b);
				int v1 = End[a * 2];
				int v2 = End[a * 2 - 1];
				if(dep[v1] < dep[v2])
					swap(v1, v2);
				update(1, dex, m[v1], b, 1);
			}
			//for(int i = 1; i <= 5; i++)
			//	printf("i: %d T: %d\n", i, T[i]);
		}
	}
	return 0;
}
