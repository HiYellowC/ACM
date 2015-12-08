#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 1000010;
const LL INF = 0x3f3f3f3f3f3f3f3f;

LL a[MAXN], b[MAXN];

int main() {
    int n1, n2;
    scanf("%d", &n1);
    for(int i = 1; i <= n1; i++) scanf("%lld", &a[i]);
    a[n1 + 1] = INF;
    scanf("%d", &n2);
    for(int i = 1; i <= n2; i++) scanf("%lld", &b[i]);
    b[n2 + 1] = INF;
    int pos = (n1 + n2 + 1) / 2;
    LL ans;
    int l, r;
    l = r = 1;
    while(pos) {
        if(a[l] < b[r]) ans = a[l], l++;
        else ans = b[r], r++;
        pos--;
    }
    printf("%lld\n", ans);
    return 0;
}
