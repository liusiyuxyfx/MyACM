/*************************************************************************
     File Name: gym101147.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月03日 星期二 14时01分49秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
LL p[50][50];
LL C(LL n, LL m) {
  if (n == m || m == 0) return 1;
  if (p[n][m]!=0) return p[n][m];
  return p[n][m] = C(n-1, m-1) + C(n-1, m);
}

int main() {
  freopen("popcorn.in", "r", stdin);
  ios::sync_with_stdio(false);
  int T;
  LL n,m;
  cin>>T;
  while(T--) {
    cin>>n>>m;
    cout<<C(n,m)<<endl;
  }
}

