#include <bits/stdc++.h>
using namespace std;

vector <int> V;

bool IsPrime(int x) {
	if(x == 1) return false;
	for(int i = 2; i * i <= x; i++) 
		if(x % i == 0) return false;
	return true;
}

int main() {
	int n, d;
	while(~scanf("%d", &n)) {
		if(n < 0) break;
		scanf("%d", &d);
		V.clear();
		int tmp = n;
		while(n) {
			V.push_back(n % d);
			n /= d;
		}
		n = tmp;
		int nn = 0;
		int s = 1;
		for(int i = (int)V.size() - 1; i >= 0; i--) {
			nn += V[i] * s;
			s *= d;
		}
		if(IsPrime(n) && IsPrime(nn)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
