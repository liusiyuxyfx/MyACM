/*************************************************************************
     File Name: HDU5512.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月18日 星期二 19时18分31秒
************************************************************************/
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int N,M,T;
int main() {
   cin>>T;
   int a,b,c;
   for (int cas=1; cas<=T; ++cas) {
     printf("Case #%d: ",cas);
    scanf("%d %d %d",&a,&b,&c);
    int ans=(a/__gcd(b,c));
    if (ans%2) puts("Yuwgna");
    else puts("Iaka");
   }
}

