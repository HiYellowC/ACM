#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100010;
char str[N];

int main(void)
{
    int n;
    int i, j;
    while(~scanf("%d%s", &n, str))
    {
        int len = strlen(str);
        char flag = '1';
        int ans = 1;
        if(str[0] == '0') flag = '0';
        for(i = 1; i < len; i++)
        {
            if(str[i] != flag)
            {
                if(flag == '0') flag = '1';
                else flag = '0';
                ans ++;
            }
        }
        for(i = 0; i+1 < len; i++)
        {
            if(str[i] == str[i+1])
            {
                for(i = i+1; i+1 < len; i++)
                {
                    if(str[i] == str[i+1]) break;
                }
                if(i+1 < len) ans += 2;
                else ans++;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
