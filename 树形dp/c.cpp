#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define Max 10010
using namespace std;

int n, k;
int Start[Max], Next[Max * 2], End[Max * 2], Length[Max * 2];
int dex;
int son[Max], root, rootn, size;
int ans;
int d[Max];
bool vis[Max];
vector <int> dep;

void Init() {
	dex = 0;
	ans = 0;
	size = n;
	rootn = Max;
	memset(Start, 0, sizeof(Start));
	memset(vis, 0, sizeof(vis));
}

void BuildG(int a, int b, int c) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
	Length[dex] = c;
}

void GetRoot(int v, int fa) {
	son[v] = 0;
	int tmp, maxn = 0;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != fa && !vis[to]) {
			GetRoot(to, v);
			tmp = son[to] + 1;
			maxn = max(maxn, tmp);
			son[v] += tmp;
		}
	}
	maxn = max(maxn, size - 1 - son[v]);
	if(maxn < rootn)
		rootn = maxn, root = v;
}

void getdep(int now, int fa) {
	dep.push_back(d[now]);
	for(int i = Start[now]; i; i = Next[i]) {
		int to = End[i];
		if(to != fa && !vis[to]) {
			d[to] = d[now] + Length[i];
			getdep(to, now);
		}
	}	
}

int calc(int now, int init) {
	dep.clear();
	d[now] = init;
	getdep(now, -1);
	sort(dep.begin(), dep.end());
	int ret = 0;
	for(int l = 0, r = dep.size() - 1; l < r; )
		if(dep[l] + dep[r] <= k) ret += r - l++;
		else r--;
	return ret;
}

void work(int now) {
	ans += calc(now, 0);
	vis[now] = true;
	for(int i = Start[now]; i; i = Next[i]) {
		int to = End[i];
		if(!vis[to]) {
			ans -= calc(to, Length[i]);
			rootn = Max;
			size = son[to] + 1;
			GetRoot(to, -1);
			work(root);
		}
	}
}

int main() {
	while(~scanf("%d%d", &n, &k)) {
		if(!n && !k) break;
		Init();	
		int a, b, c;
		for(int i = 1; i < n; i++) {
			scanf("%d%d%d", &a, &b, &c);	
			BuildG(a, b, c);
			BuildG(b, a, c);
		}
		GetRoot(1, -1);
		work(root);
		printf("%d\n", ans);
	}
	return 0;
}


