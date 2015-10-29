#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

int a[100010];
int Left[100010], Right[100010];

stack <int> S;

int main() {
	int n;
	while(~scanf("%d", &n) && n) {
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) {
			while(!S.empty() && a[S.top()] > a[i])
				Right[S.top()] = i - 1, S.pop();
			S.push(i);
		}
		while(!S.empty())
			Right[S.top()] = n, S.pop();
		for(int i = n; i >= 1; i--) {
			while(!S.empty() && a[S.top()] > a[i])	
				Left[S.top()] = i + 1, S.pop();
			S.push(i);
		}
		while(!S.empty())
			Left[S.top()] = 1, S.pop();
		long long ans = 0;
		for(int i = 1; i <= n; i++)
			ans = max(ans, (long long)a[i] * (long long)(Right[i] - Left[i] + 1));
		printf("%lld\n", ans);
	}
	return 0;
}
