#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int N;
int height[80010];
int ans[80010];
long long res;

void fun() {
	stack <int> S;
	S.push(1);
	for(int i = 2; i <= N; i++) {
		while(!S.empty() && height[S.top()] <= height[i]) {
			ans[S.top()] = i - 1;
			S.pop();
		}
		S.push(i);
	}
	while(!S.empty()) {
		ans[S.top()] = N;
		S.pop();
	}
	for(int i = 1; i <= N; i++)
		res += ans[i] - i;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &height[i]);
	fun();
	printf("%lld\n", res);
	return 0;
}
