#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int num;
	int now = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &num);	
		ans += 5;
		if(num > now) ans += (num - now) * 6;
		else if(num < now) ans += (now - num) * 4;
		now = num;
	}
	printf("%d\n", ans);
	return 0;
}
