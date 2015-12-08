#include <bits/stdc++.h>
using namespace std;

const int MAXN = 210;
const int INF = 0x3f3f3f3f;

int N, m;
int dex, Start[MAXN], Next[MAXN * 2], End[MAXN * 2], Cost[MAXN * 2], Dis[MAXN * 2];
bool vis[MAXN];
int dis[MAXN], cost[MAXN], son[MAXN], ans[MAXN];
int pre[MAXN];
string city[MAXN];
map <string, int> M;
vector <int> V;

void BuildG(int a, int b, int c) {
    Next[++dex] = Start[a];
    Start[a] = dex;
    End[dex] = b;
    Dis[dex] = c;
}

void Dij() {
    ans[1] = 1, son[1] = 0, dis[1] = 0, cost[1] = 0, vis[1] = true;
    for(int i = 0; i < N; i++) {
        int MAXDIS = INF;
        int k = 1;
        for(int j = 1; j <= N; j++)
            if(dis[j] < MAXDIS && !vis[j]) MAXDIS = dis[j], k = j;
        vis[k] = true;
        for(int j = Start[k]; j; j = Next[j]) {
            int e = End[j];
            int d = Dis[j];
            int c = Cost[e];
            if(dis[e] > dis[k] + d) dis[e] = dis[k] + d, cost[e] = cost[k] + c, son[e] = son[k] + 1, ans[e] = ans[k], pre[e] = k;
            else if(dis[e] == dis[k] + d) {
                ans[e] += ans[k];
                if(cost[e] < cost[k] + c) cost[e] = cost[k] + c, son[e] = son[k] + 1, pre[e] = k;
              	else if(cost[e] == cost[k] + c) {
                    if(son[e] > son[k] + 1) son[e] = son[k] + 1, pre[e] = k;
              	}
            }
        }
    }
}

int main() {
    memset(dis, INF, sizeof(dis));
    memset(cost, INF, sizeof(cost));
    memset(son, INF, sizeof(son));
    scanf("%d%d", &N, &m);
    cin >> city[1], M[city[1]] = 1;
    for(int i = 2; i <= N; i++) cin >> city[i], M[city[i]] = i, scanf("%d", &Cost[i]);
    string a, b;
    int c;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        scanf("%d", &c);
        BuildG(M[a], M[b], c);
        BuildG(M[b], M[a], c);
    }
    Dij();
    int D = M["ROM"];
    printf("%d %d %d %d\n", ans[D], dis[D], cost[D], cost[D] / son[D]);
    int pos = D;
    while(pos != 1) V.push_back(pos), pos = pre[pos];
    V.push_back(1);
    for(int i = (int)V.size() - 1; i >= 0; i--) {
      cout << city[V[i]];
      if(i > 0) printf("->");
    }
    puts("");
    return 0;
}

