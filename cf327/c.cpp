#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[500010];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int con, ans;
	con = ans = 0;
	for(int i = 2; i < n; i++) {
		if(a[i] != a[i - 1] && a[i] != a[i + 1]) con++;
		else {
			if(con == 0) continue;
			ans = max(ans, con);
			if(con % 2) {
				int dex = i - 1;
				while(con--) {
					a[dex--] = a[i];	
				}
			}
			else {
				int dex = i - 1;
				int sum = con / 2;
				while(sum--) a[dex--] = a[i];
				sum = con / 2;
				while(sum--) a[dex--] = !a[i];	
			}
			con = 0;
		}
	}
	ans = max(ans, con);
			if(con && con % 2) {
				int dex = n - 1;
				while(con--) {
					a[dex--] = a[n];	
				}
			}
			else if(con && con % 2 == 0){
				int dex = n - 1;
				int sum = con / 2;
				while(sum--) a[dex--] = a[n];
				sum = con / 2;
				while(sum--) a[dex--] = !a[n];	
			}
	printf("%d\n", (ans + 1) / 2);
	for(int i = 2; i < n; i++)
		if(a[i] != a[i - 1] && a[i] != a[i + 1]) a[i] = !a[i];
	for(int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
	return 0;
}
