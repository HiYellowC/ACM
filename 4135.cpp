#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector <long long> V;

long long GetAns(long long s, long long n) {
	long long i, k;
	long long sum = 0;
	for(i = 2; i * i <= n; i++)
		if(n % i == 0) {
			V.push_back(i);
			while(n % i == 0)
				n /= i;
		}
	if(n > 1)
		V.push_back(n);
	for(i = 1; i < (1 << V.size()); i++) {
		long long num = 1;
		long long cur = 0;
		for(k = 0; k < V.size(); k++)
			if((1 << k) & i)
				num *= V[k];
		long long a = i;
		while(a) {
			if(a & 1)
				cur++;
			a >>= 1;
		}
		if(cur % 2)
			sum += s / num;
		else
			sum -= s / num;
	}
	V.clear();
	return s - sum;
}

int main() {
	long long a, b, n;
	int total;
	int cur = 1;
	scanf("%d", &total);
	while(total--) {
		scanf("%lld%lld%lld", &a, &b, &n);
		printf("Case #%d: %lld\n", cur++, GetAns(b, n) - GetAns(a - 1, n));
	}
	return 0;
}
