#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;

int a[MAXN], b[MAXN];
int to[MAXN];
int T[MAXN * 3]; 
bool vis[MAXN];

void Build(int l, int r, int i) {
	if(l == r) {
		T[i] = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	Build(l, mid, i << 1);
	Build(mid + 1, r, i << 1 | 1);
	T[i] = T[i << 1] + T[i << 1 | 1];
}

void Update(int l, int r, int i, int x) {
	if(l == r) {
		T[i] = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) Update(l, mid, i << 1, x);
	else Update(mid + 1, r, i << 1 | 1, x);
	T[i] = T[i << 1] + T[i << 1 | 1];
}

int find(int l, int r, int i) {
	if(l == r) {
		return l;	
	}
	int mid = (l + r) >> 1;
	if(T[i << 1]) return find(l, mid, i << 1);
	else return find(mid + 1, r, i << 1 | 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		Build(1, n, 1);
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for(int i = 1; i <= n; i++) to[a[i]] = b[i];
		int ans = 0;
		int s = 1;
		while(1) {
			vis[s] = true;
			Update(1, n, 1, s);
			if(to[s] == s) {
				ans++;
			}
			if(!T[1]) break;
			if(!vis[to[s]]) ans++, s = to[s];
			else s = find(1, n, 1);		
		}
		printf("%d\n", ans);
	}
	return 0;
}
