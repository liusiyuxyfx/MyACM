/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月11日 星期四 11时26分05秒
 ************************************************************************/
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

struct Edge{
  int from,to,cap,flow;
  int nex;
}edge[MAXN];
int head[MAXN];
int tot=0;
int a[MAXN];
int p[MAXN];
void init(){
  tot=0;
  MEM(head,-1);
}

void Addedge(int from,int to,int cap){
  edge[tot]=(Edge){from,to,cap,0,head[from]};
  head[from]=tot++;
  edge[tot]=(Edge){to,from,0,0,head[to]};
  head[to]=tot++;
}


int Maxflow(int s,int t){
  int flow=0;
  while(true) {
    MEM(a,0);
    queue<int>q;
    q.push(s);
    a[s]=INF;
    while(!q.empty()) {
      int x=q.front();
      q.pop();
      for (int i=head[x]; ~i; i=edge[i].nex) {
        Edge &e=edge[i];
        int u=e.to;
        if(!a[u]&&e.flow<e.cap) {
          p[u]=i;
          a[u]=min(a[x],e.cap-e.flow);
          q.push(u);
        }
      }

      if (a[t]) break;
    }
    if (!a[t]) return flow;
    for (int u=t; u!=s; u=edge[p[u]].from) {
      edge[p[u]].flow+=a[t];
      edge[p[u]^1].flow-=a[t];
    }
    flow+=a[t];
    }
}

int main() {
  int n,m;
  while(cin>>n>>m){
    init();
    for (int i=0; i<n; ++i){
      int x,y,cap;
      scanf("%d %d %d",&x,&y,&cap);
      Addedge(x,y,cap);
    }
    printf("%d\n",Maxflow(1,m));
  }
}

