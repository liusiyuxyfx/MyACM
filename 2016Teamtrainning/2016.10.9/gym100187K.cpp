/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月09日 星期日 12时40分43秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int main() {
  LL n,k;
  cin>>n>>k;
  LL r=n,l=1;
  for (int i=1; i<=n; ++i) {
    if (k>=n-i) k-=n-i,cout<<r--<<" ";
    else cout<<l++<<" ";
  }
  puts("");
}

