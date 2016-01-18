#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 100010;

struct OP {
	int kind;
	int num;
};

OP op[MAXN];

int sorted[MAXN];

struct Tree {
	LL sum[5];
	int con;
};

Tree T[MAXN << 2];

void PushUp(int i) {
	for(int j = 0; j < 5; j++) T[i].sum[j] = 0;
	for(int j = 0; j < 5; j++) T[i].sum[j] += T[i << 1].sum[j], T[i].sum[(j + T[i << 1].con) % 5] += T[i << 1 | 1].sum[j];
	T[i].con = T[i << 1].con + T[i << 1 | 1].con;
}

void BuildT(int l, int r, int i) {
	if(l == r) {
		memset(T[i].sum, 0, sizeof(T[i].sum));
		T[i].con = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	BuildT(l, mid, i << 1);
	BuildT(mid + 1, r, i << 1 | 1);
	PushUp(i);
}

void AddT(int l, int r, int pos, LL val, int i) {
	if(l == r) {
		T[i].sum[1] += val;
		T[i].con++;;
		return ;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) AddT(l, mid, pos, val, i << 1);
	else AddT(mid + 1, r, pos, val, i << 1 | 1);
	PushUp(i);
}

void DelT(int l, int r, int pos, LL val, int i) {
	if(l == r) {
		T[i].sum[1] -= val;
		T[i].con--;
		return ;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) DelT(l, mid, pos, val, i << 1);
	else DelT(mid + 1, r, pos, val, i << 1 | 1);
	PushUp(i);
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		char str[5];
		int num, kind;
		int dex = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%s", str);
			if(str[0] == 'a') scanf("%d", &num), kind = 1;
			else if(str[0] == 'd') scanf("%d", &num), kind = 2;
			else kind = 3;
			op[i].kind = kind, op[i].num = num;
			if(kind < 3) sorted[++dex] = num;	
		}
		sort(sorted + 1, sorted + 1 + dex);
		int m = unique(sorted + 1, sorted + 1 + dex) - sorted - 1;
		BuildT(1, m, 1);
		for(int i = 1; i <= n; i++) {
			if(op[i].kind == 1) {
				num = lower_bound(sorted + 1, sorted + 1 + m, op[i].num) - sorted;					
				AddT(1, m, num, op[i].num, 1);
			}	
			else if(op[i].kind == 2) {
				num = lower_bound(sorted + 1, sorted + 1 + m, op[i].num) - sorted;
				DelT(1, m, num, op[i].num, 1);
			}
			else printf("%lld\n", T[1].sum[3]);
		}
	}
	return 0;
}
