/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月20日 星期六 22时42分55秒
 ************************************************************************/
#include<bits/stdc++.h>
#define LL long long 
#define  N 1000005  
#define inf 0x7ffffff  
#define eps 1e-9  
#define pi acos(-1.0)  
using namespace std;
int vis[N];  
int gcd(LL a,LL b)  
{  
    return a%b == 0 ? b : gcd(b,a%b);  
}  
int main()  
{  
//freopen("input.txt","r",stdin);  
//freopen("output.txt","w",stdout);  
    int n;  
    while(scanf("%d",&n) != EOF)  
    {  
        memset(vis,0,sizeof(vis));  
        LL s,t;  
        int flag = 1,ans = 0;  
        for(s = 3; s <= n; s += 2)  
        {  
            for(t = 1; t < s; t += 2)  
                if(gcd(s,t) == 1)  
                {  
                     LL a = s*t;  
                     LL b = (s*s-t*t)/2;  
                     LL c = (s*s+t*t)/2;  
                     if(c <= n)  
                     {  
                        ans++;  
                        for(int i = 1; ; i++){  
                            if(c*i > n) break;  
                            vis[i*a] = vis[i*b] = vis[i*c] = 1;  
                        }  
                     }  
                    // printf("%I64d %I64d %I64d\n",a,b,c);  
                }  
        }  
        int ans1 = 0;  
        for(int i = 1; i <= n; i++)  
            if(vis[i] == 0)  
                ans1++;  
        printf("%d %d\n",ans,ans1);  
    }  
    return 0;  
}
