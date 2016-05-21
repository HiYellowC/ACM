#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int a[3][MAXN];
multiset <int> S;

int main() {
	int n, p;
	int ans = 0;
	scanf("%d%d", &n, &p);
	for(int i = 0; i < 3; i++)
		for(int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			a[i][j] = (a[i][j] + a[i][j - 1]) % p;
		}
	for(int i = 1; i <= n; i++) S.insert((a[0][i] - a[1][i - 1] + p) % p);	
	for(int j = n; j >= 1; j--) {
		int con = ((a[2][n] - a[2][j - 1] + p) % p + a[1][j]) % p;
		multiset<int>::iterator it = S.lower_bound(p - con);
		if(it == S.begin()) {
			it = S.end(), it--;
			ans = max(ans, (con + *it) % p);
		}
		else ans = max(ans, con + *(--it));
		S.erase(S.find((a[0][j] - a[1][j - 1] + p) % p));
	}
	printf("%d\n", ans);	
	return 0;
}
