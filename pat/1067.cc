#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int a[MAXN], to[MAXN];
bool vis[MAXN];

int main() {
	int n, con = 0;
	int sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]), to[a[i]] = i;
	for(int i = 0; i < n; i++) {
		if(i != a[i]) sum++;
		if(i != a[i] && !vis[i]) {
			int tmp, pos;
			tmp = pos = a[i];
			while(to[tmp] != pos) {
				vis[to[tmp]] = true;
				tmp = to[tmp];	
			}
			vis[a[i]] = true;
			con++;
		}
	}
	int ans;
	if(a[0] == 0) ans = sum + con; 
	else ans = sum + con - 2;
	printf("%d\n", ans);
	return 0;
}
