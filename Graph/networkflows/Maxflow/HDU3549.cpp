/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月11日 星期四 11时44分55秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=16;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

int flow[MAXN][MAXN];
int cap[MAXN][MAXN];
int p[MAXN];
int a[MAXN];
int n,m;

int maxflow(){
  queue<int>q;
  MEM(flow,0);
  int f=0;
  while (true) {
    MEM(a,0);
    a[1]=INF;
    q.push(1);
    while (!q.empty()) {
      int u=q.front();
      q.pop();
      for (int v=1; v<=n; v++)
        if (!a[v]&&cap[u][v]>flow[u][v]) {
          p[v]=u;
          q.push(v);
          a[v]=min(a[u],cap[u][v]-flow[u][v]);
        }
    }
    if (a[n]==0) break;
    for (int u=n; u!=1; u=p[u]) {
      flow[p[u]][u]+=a[n];
      flow[u][p[u]]-=a[n];
    }
    f+=a[n];
  }
  return f;
}

int main() {
  int t,cas=1;
  cin>>t;
  while(t--) {
    cin>>n>>m;
    MEM(cap,0);
    while (m--) {
      int u,v,w;
      scanf("%d %d %d",&u,&v,&w);
      cap[u][v]+=w;
    }
    printf("Case %d: %d\n",cas++,maxflow());
  }
}


