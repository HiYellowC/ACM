#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

long long Array[100010];
long long Left[100010], Right[100010];
stack <long long> S;

int main() {
	int i, n;
	while(scanf("%d", &n)) {
		if(!n)
			break;
		Array[0] = -1;
		for(i = 1; i <= n; i++)
			scanf("%lld", &Array[i]);
		while(!S.empty())
			S.pop();
		Array[n + 1] = -1;
		S.push(0);
		for(i = 1; i <= n; i++) {
			while(Array[S.top()] >= Array[i])
				S.pop();
			Left[i] = S.top() + 1;
			S.push(i);
		}
		while(!S.empty())
			S.pop();
		S.push(n + 1);
		for(i = n; i >= 1; i--) {
			while(Array[S.top()] >= Array[i])
				S.pop();
			Right[i] = S.top() - 1;
			S.push(i);
		}
		long long Max = 0;
		for(i = 1; i <= n; i++)
			if(Array[i] * (Right[i] - Left[i] + 1) > Max)
				Max = Array[i] * (Right[i] - Left[i] + 1);
		printf("%lld\n", Max);
	}
	return 0;
}
