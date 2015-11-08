#include <bits/stdc++.h>
using namespace std;
int T;
int dp[1100][1100];
int n;
int q;
int a[1100];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1; i<=n; i++) scanf("%d", &a[i]);
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                if(a[j] == 0) dp[i][j] = dp[i][j-1]; 
                else if((j-1>=i)&&a[j-1] == 1&&(j-2<i||a[j-2] == 0)) dp[i][j] = dp[i][j-1] + 1;
                else dp[i][j] = dp[i][j-1];
            }
        }
        cin>>q;
        while(q--){
            int l,r;
            scanf("%d %d", &l, &r);
            printf("%d\n", dp[l][r]);
        }
    }
    return 0;
}
