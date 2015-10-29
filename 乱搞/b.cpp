#include <iostream>
#include <cstdio>
#include <cstring>
#define Max 20
#define INF 0x7f7f7f7f
using namespace std;

int var, equ;
int b[Max][Max];
int c[Max][Max];
int x[Max];
int free_x[Max];
int free_num;
int ans1, ans2;

void Init() {
	int n;
	char ch;
	n = 4;
	var = equ = n * n;
	free_num = 0;
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	memset(x, 0, sizeof(x));
	for(int i = 1; i <= equ; i++) {
		cin >> ch;
		b[i][var + 1] = ch == 'b' ? 0 : 1;
		c[i][var + 1] = !b[i][var + 1];
		b[i][i] = c[i][i] = 1;
		if(i > n)
			b[i][i - n] = c[i][i - n] = 1;
		if(i <= n * (n - 1))
			b[i][i + n] = c[i][i + n] = 1;
		if(i % n != 1)
			b[i][i - 1] = c[i][i - 1] = 1;
		if(i % n != 0)
			b[i][i + 1] = c[i][i + 1] = 1;
	}
}

void gauss(int a[][Max], int & ans) {
	int i, j, k;
	int row, col;
	for(row = col = 1; row <= equ && col <= var; row++, col++) {
		for(i = row; i <= equ; i++)
			if(a[i][col])
				break;
		if(i == equ + 1) {
			free_x[++free_num] = col;
			row--;
			continue;
		}
		if(i != row)
			for(j = 1; j <= var + 1; j++)
				swap(a[row][j], a[i][j]);
		for(i = row + 1; i <= equ; i++)
			if(a[i][col])
				for(j = 1; j <= var + 1; j++)
					a[i][j] ^= a[row][j];
	}
	for(i = row; i <= equ; i++)
		if(a[i][var + 1]) {
			ans = INF;
			return ;
		}
	if(row == equ + 1) {
		for(i = equ; i >= 1; i--) {
			x[i] = a[i][var + 1];
			for(k = i + 1; k <= var; k++)
				x[i] ^= (a[i][k] & x[k]);
		}
		for(i = 1; i <= var; i++)	
			if(x[i])
				ans++;
		return ;
	}
	else {
		int s = 1 << free_num;
		ans = INF;
		for(int i = 0; i < s; i++) {
			int cnt = 0;
			for(k = 0; k < free_num; k++)
				if((i >> k) & 1) {
					x[free_x[k + 1]] = 1;
					cnt++;
				}
				else
					x[free_x[k + 1]] = 0;
			for(k = row - 1; k >= 1; k--) {
				for(j = k; j <= var; j++)
					if(a[k][j])
						break;
				x[j] = a[k][var + 1];
				int dex = j;
				for(j = dex + 1; j <= var; j++)
					x[dex] ^= (a[k][j] & x[j]);
				if(x[dex])
					cnt++;
			}
			ans = min(ans, cnt);
		}
	}
}

int main() {
		Init();
		gauss(b, ans1);
		memset(x, 0, sizeof(x));
		free_num = 0;
		gauss(c, ans2);
		if(ans1 != INF || ans2 != INF)
			printf("%d\n", min(ans1, ans2));
		else
			printf("Impossible\n");
	return 0;
}
