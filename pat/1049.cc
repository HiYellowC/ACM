#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

char str[20];
LL C[20][20];

void Init() {
	for(int i = 0; i < 20; i++) C[i][i] = 1, C[0][i] = 1;
	for(int i = 1; i < 20; i++)
		for(int k = 1; k < i; k++)
			C[k][i] = C[k - 1][i - 1] + C[k][i - 1];
}

LL pow(LL a, LL b) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans *= a;
		b >>= 1;
		a = a * a;
	}
	return ans;
}

int main() {
	Init();
	scanf("%s", str);
	int len = strlen(str);
	LL sum = 0;
	LL num = 0;
	for(int i = 0; i < len; i++) {
		LL con = 0;
		for(int k = 1; k <= len - i - 1; k++) con += k * C[k][len - i - 1] * pow(9, len - i - 1 - k);
		sum += con * (str[i] - '0');
		if(str[i] - '0' > 1) sum += pow(10, len - i - 1);
		sum += num * (str[i] - '0') * pow(10, len - i - 1);
		if(str[i] - '0' == 1) num++;
	}
	printf("%lld\n", sum + num);
	return 0;
}
