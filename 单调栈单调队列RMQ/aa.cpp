#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int a[111111];
int sum[211111];
const int INF = 0x3fffffff;

int main()
{
    int t,n,m,i,j,k,head,end;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        j = n;
        sum[0] = 0;
        for(i = 1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum[i] = sum[i-1]+a[i];//将前i项和全部存入sum数组中
        }
        int ans = -INF;
        for(i = n+1; i<n+k;i++)
            sum[i] = sum[i-1]+a[i-n];
        n = n+k-1;
        deque<int> Q;//双向队列
        Q.clear();
        for(i = 1; i<=n; i++)
        {
            while(!Q.empty() && sum[i-1]<sum[Q.back()])//保持队列的单调性
                Q.pop_back();
            while(!Q.empty() && Q.front()<i-k)//超过k的长度则消除队列前面的元素
                Q.pop_front();
            Q.push_back(i-1);
            if(sum[i]-sum[Q.front()]>ans)//记录，sum[n]-sum[m]所得出的是n-1到m+1之间的和
            {
                ans = sum[i]-sum[Q.front()];
                head = Q.front()+1;
                end = i;
            }
        }
        if(end>j)
        end%=j;
        printf("%d %d %d\n",ans,head,end);
    }

    return 0;
}

