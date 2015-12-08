#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;
const int INF = 0x3f3f3f3f;

int N, M, S, D;
int dex, Start[MAXN], Next[MAXN * 2], End[MAXN * 2], Cost[MAXN * 2], Dis[MAXN * 2];
bool vis[MAXN];
int dis[MAXN], cost[MAXN];
int pre[MAXN];
vector <int> V;

void BuildG(int a, int b, int c, int d) {
    Next[++dex] = Start[a];
    Start[a] = dex;
    End[dex] = b;
    Dis[dex] = c;
    Cost[dex] = d;
}

void Dij() {
    dis[S] = 0, cost[S] = 0, vis[S] = true;
    for(int i = 0; i < N; i++) {
        int MAXDIS = INF;
        int k = S;
        for(int j = 0; j < N; j++)
            if(dis[j] < MAXDIS && !vis[j]) MAXDIS = dis[j], k = j;
        vis[k] = true;
        for(int j = Start[k]; j; j = Next[j]) {
            int e = End[j];
            int d = Dis[j];
            int c = Cost[j];
            if(dis[e] > dis[k] + d) dis[e] = dis[k] + d, cost[e] = cost[k] + c, pre[e] = k;
            else if(dis[e] == dis[k] + d) {
                if(cost[e] > cost[k] + c) cost[e] = cost[k] + c, pre[e] = k;
            }
        }
    }
}

int main() {
    memset(dis, INF, sizeof(dis));
    memset(cost, INF, sizeof(cost));
    scanf("%d%d%d%d", &N, &M, &S, &D);
    int a, b, c, d;
    for(int i = 1; i <= M; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        BuildG(a, b, c, d);
        BuildG(b, a, c, d);
    }
    Dij();
    int pos = D;
    while(pos != S) V.push_back(pos), pos = pre[pos];
    V.push_back(S);
    for(int i = (int)V.size() - 1; i >= 0; i--) printf("%d ", V[i]);
    printf("%d %d\n", dis[D], cost[D]);
    return 0;
}

