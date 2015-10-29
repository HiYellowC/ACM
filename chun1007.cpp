#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define eps 1e-5
#define MAXN 55555
#define MAXM 11111
#define INF 1000000000
#define lch(x) x<<1
#define rch(x) x<<1|1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int mx[MAXN][17], w[MAXN];
int n, q;
void rmqinit()
{
    for(int i = 1; i <= n; i++) mx[i][0] = w[i];
    int m = (int)(log(n * 1.0) / log(2.0));
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            mx[j][i] = mx[j][i - 1];
            if(j + (1 << (i - 1)) <= n) mx[j][i] = max(mx[j][i], mx[j + (1 << (i - 1))][i - 1]);
        }
}
int rmqmax(int l,int r)
{
    int m = (int)(log((r - l + 1) * 1.0) / log(2.0));
    return max(mx[l][m] , mx[r - (1 << m) + 1][m]);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &w[i]);
		rmqinit();
		scanf("%d", &q);
		while(q--) {
			int a, b;	
			scanf("%d%d", &a, &b);
			printf("%d\n", rmqmax(a, b));
		}
	}
    return 0;
}

