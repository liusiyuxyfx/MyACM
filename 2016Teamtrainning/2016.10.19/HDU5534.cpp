/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月19日 星期三 20时16分17秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=3e3+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int dp[MAXN];
int f[MAXN];
int w[MAXN];
int v[MAXN];
int main() {
  int n,T;
  scanf("%d",&T);
  while (T--) {
    MEM(dp,0);
    scanf("%d",&n);
    for (int i=1; i<n; ++i) scanf("%d",&f[i]);
    for (int i=1; i<n; ++i) {
      w[i]=i-1;
      v[i]=f[i]-f[1];
      if (i<n-1)
      dp[i]=-INF;
    }
    for (int i=1; i<n; ++i) 
      for (int j=w[i]; j<=n-2; ++j) 
        dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    printf("%d\n",dp[n-2]+n*f[1]);
  }
}

