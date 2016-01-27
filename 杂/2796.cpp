#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

typedef long long LL;

LL n;
LL Left[100010];
LL Right[100010];
struct node {
    LL val, cur;
    friend bool operator < (node n1, node n2) {
         return n1.val < n2.val;
    }
};
node Array[100010];
LL sum[100010];

void Init() {
     priority_queue <node> Q;
     Q.push(Array[1]);
     for(LL i = 2; i <= n; i++) {
         while(!Q.empty() && Array[i].val < Q.top().val) {
             Right[Q.top().cur] = i - 1;
             Q.pop();
         }
         Q.push(Array[i]);
     }
     while(!Q.empty()) {
         Right[Q.top().cur] = n;
         Q.pop();
     }
     Q.push(Array[n]);
     for(LL i = n - 1; i > 0; i--) {
         while(!Q.empty() && Array[i].val < Q.top().val) {
             Left[Q.top().cur] = i + 1;
             Q.pop();        
         }
         Q.push(Array[i]);
     }
     while(!Q.empty()) {
         Left[Q.top().cur] = 1;
         Q.pop();
     }
}

int main() {
    while(~scanf("%lld", &n)) {
        for(LL i = 1; i <= n; i++) {
            scanf("%lld", &Array[i].val);
            Array[i].cur = i;
        }
        sum[1] = Array[1].val;
        for(LL i = 2; i <= n; i++)
            sum[i] = sum[i - 1] + Array[i].val;
        Init(); 
        long long Max = -1;
        LL l, r;
        for(LL i = 1; i <= n; i++) {
	//		printf("i: %lld Left: %lld Right: %lld\n", i, Left[i], Right[i]);
            if(Array[i].val * (sum[Right[i]] - sum[Left[i] - 1]) > Max) {
                Max = Array[i].val * (sum[Right[i]] - sum[Left[i] - 1]);
                l = Left[i], r = Right[i];
            }
		}
        printf("%lld\n%lld %lld\n", Max, l, r);
    }
    return 0;    
}
