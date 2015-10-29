#include <iostream>
#include <cstdio>
#include <cstring>
#define Max 50010
using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")

int N, M, P;
int nume[Max];
int T[Max << 2], flag[Max << 2];
int dex, Start[Max], Next[Max * 2], End[Max * 2];
int deep[Max], parent[Max], siz[Max], son[Max], top[Max], m[Max];

void Init() {
	dex = 0;
	memset(Start, 0, sizeof(Start));
	memset(deep, 0, sizeof(deep));
	memset(son, 0, sizeof(son));
	memset(T, 0, sizeof(T));
	memset(flag, 0, sizeof(flag));
}

void BuildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
}

void dfs(int v, int p) {
	deep[v] = deep[p] + 1;
	parent[v] = p;
	siz[v] = 1;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != p) {
			dfs(to, v);	
			if(siz[to] > siz[son[v]])
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
		if(to != parent[v] && to != son[v])
			BuildT(to, to);
	}
}

void PushDown(int i, int s) {
	if(flag[i]) {
		flag[i << 1] += flag[i];
		flag[i << 1 | 1] += flag[i];
		T[i << 1] += (s - (s >> 1)) * flag[i];
		T[i << 1 | 1] += (s >> 1) * flag[i];
		flag[i] = 0;
	}
}

void update(int left, int right, int l, int r, int i, int x) {
	int s = right - left + 1;
	if(l <= left && r >= right) {
		flag[i] += x;
		T[i] += x * s; 
		return ;
	}
	PushDown(i, s);
	int mid = (left + right) >> 1;
	if(l <= mid)
		update(left, mid, l, r, i << 1, x);
	if(r > mid)
		update(mid + 1, right, l, r, i << 1 | 1, x);
	T[i] = T[i << 1] + T[i << 1 | 1];
}

int query(int left, int right, int x, int i) {
	if(left == right)
		return T[i];
	PushDown(i, right - left + 1);
	int mid = (left + right) >> 1;
	if(x <= mid)
		return query(left, mid, x, i << 1);
	else
		return query(mid + 1, right, x, i << 1 | 1);
}

int main() {
	while(~scanf("%d%d%d", &N, &M, &P)) {
		Init();
		for(int i = 1; i <= N; i++)
			scanf("%d", &nume[i]);
		int a, b, c;
		for(int i = 1; i <= M; i++) {
			scanf("%d%d", &a, &b);
			BuildG(a, b);
			BuildG(b, a);
		}
		dfs(1, 1);
		dex = 0;
		BuildT(1, 1);
		for(int i = 1; i <= N; i++)
			update(1, dex, m[i], m[i], 1, nume[i]);
		char ch;
		while(P--) {
			cin >> ch;
			if(ch == 'Q') {
				scanf("%d", &a);
				printf("%d\n", query(1, dex, m[a], 1));
			}
			else {
				scanf("%d%d%d", &a, &b, &c);
				if(ch == 'D')
					c *= -1;
				int f1 = top[a], f2 = top[b];
				while(f1 != f2) {
					if(deep[f1] < deep[f2])
						swap(f1, f2), swap(a, b);
					update(1, dex, m[f1], m[a], 1, c);
					a = parent[f1];
					f1 = top[a];
				}
				if(deep[a] > deep[b])
					swap(a, b);
				update(1, dex, m[a], m[b], 1, c);
			}
		}
	}
	return 0;
}

