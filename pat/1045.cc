#include <bits/stdc++.h>
using namespace std;

const int MAXN = 210;

int a[MAXN], b[10010];
int dp[10010][MAXN];
struct tree {
	int T[MAXN * 3];
	void Update(int l, int r, int pos, int val, int i) {
		if(l == r) {
			T[i] = val;
			return ;
		}	
		int mid = (l + r) >> 1;
		if(pos <= mid) Update(l, mid, pos, val, i << 1);
		else Update(mid + 1, r, pos, val, i << 1 | 1);
		T[i] = max(T[i << 1], T[i << 1 | 1]);
	}
	int Query(int tl, int tr, int l, int r, int i) {
		if(tl == l && tr == r) return T[i];
		int mid = (tl + tr) >> 1;
		if(r <= mid) return Query(tl, mid, l, r, i << 1);
		else if(l > mid) return Query(mid + 1, tr, l, r, i << 1 | 1);
		else return max(Query(tl, mid, l, mid, i << 1), Query(mid + 1, tr, mid + 1, r, i << 1 | 1));
	}
};

tree t[10010];

int main() {
	int n, n1, n2;
	scanf("%d", &n);
	scanf("%d", &n1);
	for(int i = 1; i <= n1; i++) scanf("%d", &a[i]);
	scanf("%d", &n2);
	for(int i = 1; i <= n2; i++) scanf("%d", &b[i]);
	for(int i = 1; i <= n2; i++)
		for(int j = 1; j <= n1; j++) {
			dp[i][j] = dp[i - 1][j];
			if(b[i] == a[j]) 
					dp[i][j] = max(dp[i][j], t[i - 1].Query(1, n1, 1, j, 1) + 1);
			t[i].Update(1, n1, j, dp[i][j], 1);
		}
	int ans = 0;
	for(int i = 1; i <= n1; i++) ans = max(ans, dp[n2][i]);
	printf("%d\n", ans);
	return 0;
}
