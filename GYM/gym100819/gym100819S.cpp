/*************************************************************************
     File Name: gym100819S.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月08日 星期六 14时13分51秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=3e6+6;
int hp[MAXN],wait[MAXN];
LL dp[MAXN];
int x;
int main() {
  int n;
  cin>>n;
  for (int i=1; i<=n; ++i) {
    scanf("%d",&x);
    scanf("%d %d",&hp[x],&wait[x]);
  }
  for (int i=MAXN; i>=1; --i) { 
    dp[i]=dp[i+1];
    if (hp[i]) dp[i]=max(dp[i],hp[i]+dp[i+wait[i]]);
  }
  printf("%I64d\n",dp[1]);
}


