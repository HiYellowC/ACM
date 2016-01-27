#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long Array[100010];

int main() {
	int n, p;
	while(~scanf("%d%d", &n, &p)) {
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &Array[i]);
			Array[i] %= p;
		}
		sort(Array + 1, Array + 1 + n);
		long long ans = (Array[n] + Array[n - 1]) % p;
		int left = 1;
		int right = n;
		while(left < right) {
			while(left < right && Array[right] + Array[left] < p) {
				ans = max(ans, Array[right] + Array[left]);
				left++;
			}
			right--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
