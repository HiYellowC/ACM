#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#define Max 300001
using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")

int n;
int deep[Max];
int e[Max * 2], R[Max];
int f2[Max * 2][19];
int dp1[Max][19], dp2[Max][19];
int dex;
int Start[Max], Next[Max * 2], End[Max * 2];

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

void dfs(int v, int d, int p) {
    e[++dex] = v;
    R[v] = dex;
    deep[v] = d;
    for(int i = Start[v]; i != -1; i = Next[i]) {
        int to = End[i];
        if(to != p) {
            dfs(to, d + 1, v);
            e[++dex] = v;
        }
    }
}

void BuildG(int a, int b) {
    Next[++dex] = Start[a];
    Start[a] = dex;
    End[dex] = b;
}

void RMQ() {
    for(int i = 1; i <= dex; i++)
        f2[i][0] = e[i];
    for(int i = 1; 1 << i <= dex; i++)
        for(int k = 1; k <= dex + 1 - (1 << i); k++) {
            int s = 1 << (i - 1);
            if(deep[f2[k][i - 1]] > deep[f2[k + s][i - 1]])
                f2[k][i] = f2[k + s][i - 1];
            else 
                f2[k][i] = f2[k][i - 1];
        }
    for(int i = 1; i <= n; i++)
        dp1[i][0] = dp2[i][0] = R[i];
    for(int i = 1; 1 << i <= n; i++) 
        for(int k = 1; k <= n + 1 - (1 << i); k++) {
            dp1[k][i] = max(dp1[k][i - 1], dp1[k + (1 << (i - 1))][i - 1]);
            dp2[k][i] = min(dp2[k][i - 1], dp2[k + (1 << (i - 1))][i - 1]);
            //printf("k: %d i: %d dp1: %d dp2: %d\n", k, i, dp1[k][i], dp2[k][i]);
        }
}

int main() {
    while(~scanf("%d", &n)) {
        memset(Start, -1, sizeof(Start));
        dex = 0;
        for(int i = 0; i < n - 1; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            BuildG(a, b);
            BuildG(b, a);
        }
        dex = 0;
        dfs(1, 1, 1);
        RMQ();
    //    for(int i = 1; i <= n; i++)
    //        printf("v: %d R: %d\n", i, R[i]);
        int t;
        scanf("%d", &t);
        while(t--) {
            int l, r;
            scanf("%d%d", &l, &r);
            int k = (int)(log(r - l + 1) / log(2));
            int a, b;
    //        printf("l: %d k: %d s: %d \n", l, k, r - (1 << k) + 1);
            a = min(dp2[l][k], dp2[r - (1 << k) + 1][k]);
            b = max(dp1[l][k], dp1[r - (1 << k) + 1][k]);
    //        printf("a: %d  b: %d\n", a, b);
            int s = (int)(log(b - a + 1) / log(2));
            int q = b - (1 << s) + 1;
            if(deep[f2[a][s]] > deep[f2[q][s]])
                printf("%d\n", f2[q][s]);
            else
                printf("%d\n", f2[a][s]);
        }
    }
    return 0;
}
