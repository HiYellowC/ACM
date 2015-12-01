#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int a[MAXN], to[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	int pos, con = 0;
	bool flag = false;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		to[a[i]] = i;
		if(a[i] && i != a[i]) con++;
		if(a[i] == 0) pos = i;
	}
	int ans;
	if(con == 0) ans = 0;
	else {
		int ncon = 0;
		while(pos) {
			ncon++;
			pos = to[pos];
		}	
		if(ncon < con) con++;
		ans = con;
	}
	printf("%d\n", ans);
	return 0;
}
