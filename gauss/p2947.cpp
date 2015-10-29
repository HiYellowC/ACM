#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#define Max 310
#define MOD 7
using namespace std;

int n, m;
int a[Max][Max];
int x[Max];
int free_x[Max];
int free_num;
int ans;
int kind[Max];
map <string, int> M;

inline int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

inline int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

inline int Abs(int a) {
	if(a < 0)
		a *= -1;
	return a;
}

void Init() {
	memset(a, 0, sizeof(a));
	memset(x, 0, sizeof(x));
	free_num = 0;
	int kind_num, num;
	string date1, date2;
	for(int i = 1; i <= m; i++) {
		scanf("%d", &kind_num);
		cin >> date1 >> date2;
		for(int k = 1; k <= kind_num; k++) {
			scanf("%d", &num);
			kind[num]++;
		}
		for(int k = 1; k <= n; k++) {
			if(kind[k]) {
				a[i][k] = kind[k] % 7;
				kind[k] = 0;
			}
		}
		a[i][n + 1] = ((M[date2] - M[date1] + 1) % MOD + MOD) % MOD;
	}
}

void gauss() {
	int row, col;
	int i, j, k;
	for(row = col = 1; row <= m && col <= n; row++, col++) {
		int max_r = row;
		for(i = row + 1; i <= m; i++)
			if(Abs(a[i][col]) > Abs(a[row][col]))
				max_r = i;
		if(a[max_r][col] == 0) {
			free_x[++free_num] = col;
			row--;
			continue;
		}
		if(max_r != row)
			for(i = 1; i <= n + 1; i++)
				swap(a[row][i], a[max_r][i]);
		for(i = row + 1; i <= m; i++)
			if(a[i][col]) {
				int LCM = lcm(a[i][col], a[row][col]);
				int p1 = LCM / a[row][col];
				int p2 = LCM / a[i][col];
				for(k = 1; k <= n + 1; k++)
					a[i][k] = ((a[i][k] * p2 - a[row][k] * p1) % MOD + MOD) % MOD;
			}
	}
	for(i = row; i <= m; i++)
		if(a[i][n + 1] % 7) {
			ans = 0;
			return;
		}
	if(row < n) {
		ans = 2;
		return ;
	}
	for(i = row - 1; i >= 1; i--) {
		int temp = a[i][n + 1];
		for(k = i + 1; k <= n; k++)
			temp -= x[k] * a[i][k];
		for(j = 3; j <= 9; j++)
			if(((j * a[i][i]) % MOD + MOD) % MOD == (temp % MOD + MOD) % MOD) {
				x[i] = j;
				break;
			}
	}
	ans = 1;
	return ;
}

int main() {
	M["MON"] = 1, M["TUE"] = 2, M["WED"] = 3, M["THU"] = 4, M["FRI"] = 5, M["SAT"] = 6, M["SUN"] = 7;
	while(scanf("%d%d", &n, &m) && (n || m)) {
		Init();
		gauss();
		if(ans == 1)
			for(int i = 1; i <= n; i++) {
				printf("%d", x[i]);
				if(i != n)
					printf(" ");
				else
					printf("\n");
			}
		else if(ans == 0)
			printf("Inconsistent data.\n");
		else
			printf("Multiple solutions.\n");
	}
	return 0;
}
