#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int MAXN = 100010;

LL a[MAXN], b[MAXN];

int main() {
	int n;
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		for(int i = 1; i <= n; i++) b[i] = ((a[i] * 1890 + 143) % 10007) - a[i];
		LL sum = 0;
		for(int i = 1; i <= n; i++) sum += a[i];
		LL con = 0;
		LL Max = 0;
		for(int i = 1; i <= n; i++) {
			con += b[i];
			Max = max(con, Max);
			if(con < 0) con = 0;
		}
		printf("%lld\n", sum + Max);
	}
	return 0;
}
