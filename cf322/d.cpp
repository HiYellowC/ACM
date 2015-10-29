#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int px[4], py[4];
int Map[200][200];
int l;
bool flag;

bool check(int x, int y, int cur, int key) {
	int addx, addy;
	if(key)
		addx = px[cur], addy = py[cur];
	else
		addy = px[cur], addx = py[cur];
	if(x + addx - 1 > l || y + addy - 1 > l) return false;
	for(int i = x; i <= x + addx - 1; i++)
		for(int k = y; k <= y + addy - 1; k++)
			if(Map[i][k])
				return false;
	return true;
}

void update(int x, int y, int cur, int key) {
	int addx, addy;
	if(key)
		addx = px[cur], addy = py[cur];
	else
		addy = px[cur], addx = py[cur];
	for(int i = x; i <= x + addx - 1; i++)
		for(int k = y; k <= y + addy - 1; k++)
			Map[i][k] = cur;
}

void del(int x, int y, int cur, int key) {
	int addx, addy;
	if(key)
		addx = px[cur], addy = py[cur];
	else
		addy = px[cur], addx = py[cur];
	for(int i = x; i <= x + addx - 1; i++)
		for(int k = y; k <= y + addy - 1; k++)
			Map[i][k] = 0;
}

void dfs(int cur) {
	if(cur == 4) {
		flag = true;
		return ;
	}
	for(int i = 1; i <= l; i++) {
		for(int k = 1; k <= l; k++) {
			if(Map[i][k] == 0) {
				if(check(i, k, cur, 1)) {
					update(i, k, cur, 1), dfs(cur + 1);
					if(flag) return ;
					del(i, k, cur, 1);
				}
				if(check(i, k, cur, 0)) {
					update(i, k, cur, 0), dfs(cur + 1);
					if(flag) return ;
					del(i, k, cur, 0);
				}
			}
		}
	}
}

int main() {
	for(int i = 1; i <= 3; i++)
		scanf("%d%d", &px[i], &py[i]);
	int sum = 0;
	for(int i = 1; i <= 3; i++)
		sum += px[i] * py[i];
	l = sqrt(sum);
	if((l - 1) * (l - 1) == sum) l--;
	if((l + 1) * (l + 1) == sum) l++;
	flag = false;
	if(l * l == sum) {
		dfs(1);	
	}
	if(!flag)
		printf("-1\n");
	else {
		printf("%d\n", l);
		for(int i = 1; i <= l; i++) {
			for(int k = 1; k <= l; k++)
				printf("%c", 'A' + Map[i][k] - 1);
			printf("\n");
		}
	}
	return 0;
}
