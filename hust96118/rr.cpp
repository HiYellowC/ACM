#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=110;
char s[maxn];
int N;
int dp[110][55][220][2];
int main()
{
    while(scanf("%s",s+1)!=EOF)
    {
        scanf("%d",&N);
        int len=strlen(s+1);
        memset(dp,0,sizeof(dp));
        dp[0][0][len][0]=1;
        for(int i=1;i<=len;i++)
        {
            for(int j=0;j<=N;j++)
            {
                for(int k=0;k<=(len<<1);k++)
                {
                    for(int l=0;l<2;l++)
                    {
                        int pos;
                        if(s[i]=='T')
                        {
                            pos=k+(l==0?-1:1);
                            //接受当前的T，也就是这一步要转身成方向l，那么需要前一个字符方向l^1的状态存在
                            if(dp[i-1][j][k][l^1])dp[i][j][k][l]=1;
                            //如果要修改这个T，那么要求前i-1个字符修改过j-1次，因为是修改T，所以方向不变
                            else if(j>0&&pos>=0&&pos<=(len<<1)&&dp[i-1][j-1][pos][l])
                                dp[i][j][k][l]=1;

                        }
                        else
                        {
                            pos=k+(l==0?-1:1);
                            if(pos>=0&&pos<=(len<<1)&&dp[i-1][j][pos][l])
                                dp[i][j][k][l]=1;
                            else if(j>0&&dp[i-1][j-1][k][l^1])
                                dp[i][j][k][l]=1;
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int j=N;j>=0;j-=2)
        {
            for(int k=0;k<=(len<<1);k++)
            {
                for(int l=0;l<2;l++)
                    if(dp[len][j][k][l])
                    ans=max(ans,abs(k-len));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

