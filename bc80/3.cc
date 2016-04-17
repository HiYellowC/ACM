#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
const long long N = 3;
long long t,b,c,f1,f2;
long long M;
LL tn, ta, tb, tc, tp;

struct Node  //矩阵
{
    long long line,cal;
    long long a[N+1][N+1];
    Node(){
        line=3,cal=3;
        a[0][0] = tc; a[0][1] = 1; a[0][2] = 0;
        a[1][0] = 1; a[1][1] = 0; a[1][2] = 0;
        a[2][0] = 1; a[2][1] = 0; a[2][2] = 1;
    }
};

Node isit(Node x,long long c)  //矩阵初始化
{
    for(long long i=0;i<N;i++)
        for(long long j=0;j<N;j++)
            x.a[i][j]=c;
    return x;
}

Node Matlab(Node x,Node s)  //矩阵乘法
{
    Node ans;
    ans.line = x.line,ans.cal = s.cal;
    ans=isit(ans,0);
    for(long long i=0;i<x.line;i++)
    {
        for(long long j=0;j<x.cal;j++)
        {
            for(long long k=0;k<s.cal;k++)
            {
                ans.a[i][j] += x.a[i][k]*s.a[k][j];
                ans.a[i][j]=(ans.a[i][j]+M)%M;
            }
        }
    }
    return ans;
}
long long Fast_Matrax(long long n)  //矩阵快速幂
{
    if(n==1)
        return f1;
    n-=2;
    long long x=1,f=n,ok=1;
    Node ans,tmp,ch;
    ans.line = 1,ans.cal = 3;
    ans.a[0][0] = 1, ans.a[0][1] = 0 ,ans.a[0][2] = 1;
    while(n>0)
    {
        if(n%2)
        {
            ans=Matlab(ans,tmp);
        }
        tmp=Matlab(tmp,tmp);
        n/=2;
    }
    return ans.a[0][0];
}

long long pow(LL x, LL y) {
	LL ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % tp;
		y >>= 1;
		x = (x * x) % tp;
	}
	return ans % tp;
}

int main()
{
    long long n,T;
    scanf("%lld",&T);
    while(T--)
    {
		scanf("%lld%lld%lld%lld%lld", &tn, &ta, &tb, &tc, &tp);
		if(ta % tp == 0) {
			printf("0\n");
			continue;
		}
		M = tp - 1;
		LL ans = Fast_Matrax(tn) % M;
		ans = (tb * ans) % M;
		ans = pow(ta, ans) % tp;
		printf("%lld\n", ans);
    }
    return 0;
}

