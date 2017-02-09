/*************************************************************************
     File Name: gym100187M.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月09日 星期日 13时48分49秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int up[MAXN];
int down[MAXN];
int x;
int main() {
  int n,m,s,a,l=0,r=0;
  cin>>n;
  int u,v;
  for (int i=1; i<=n; ++i) {
    scanf("%d %d",&u,&v);
    if (u>0) up[l++]=v;
    else down[r++]=-v;
  }
  sort(up,up+l);
  sort(down,down+r);
  scanf("%d",&m);
  int x;
  for (int i=1; i<=m; ++i) {
    scanf("%d",&x);
    int ans1=upper_bound(up,up+l,x)-up;
    int ans2=r-(lower_bound(down,down+r,x)-down);
    printf("%d\n",ans1+ans2);
  }
}

