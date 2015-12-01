#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;

int deep[MAXN];
int dex, Start[MAXN], Next[2 * MAXN], End[2 * MAXN];
int fa[MAXN], in[MAXN];

void BuildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
}

int dfs(int v, int f) {
	int high = 0;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != f) {
			high = max(dfs(to, v), high);	
		}
	}
	return high + 1;	
}

int getfa(int x) {
	return x == fa[x] ? x : getfa(fa[x]);
}

int main() {
	int n, a, b;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		in[a]++, in[b]++;
		BuildG(a, b);
		BuildG(b, a);
		int aa = getfa(a);
		int bb = getfa(b);
		if(aa != bb) fa[aa] = bb;
	}
	int con = 0;
	for(int i = 1; i <= n; i++)
		if(getfa(i) == i) con++;
	if(con > 1) printf("Error: %d components\n", con);
	else {
		int Max = 0;
		con = 0;
		for(int i = 1; i <= n; i++) {
			if(in[i] == 1) {
				deep[i] = dfs(i, -1);
				Max = max(deep[i], Max);
			}	
		}
		for(int i = 1; i <= n; i++)
			if(deep[i] == Max) printf("%d\n", i);
	}
	return 0;
}
