/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月20日 星期六 08时01分51秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e3+10;
const int MAXM=1e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int n,m,cnt,head[MAXN];
int dis[MAXN],a,b,head2[MAXN];
int s,t;
bool vis[MAXN];

struct Edge{
  int u,v,w,nex;
}e[MAXM*3];

void Addedge(int u,int v,int w,int head[]){
  e[cnt].u=u;
  e[cnt].v=v;
  e[cnt].w=w;
  e[cnt].nex=head[u];
  head[u]=cnt++;
}

void spfa()  {
  queue<int>q;
  q.push(a);

  MEM(vis,0);
  MEMINF(dis);
  vis[a]=1;
  dis[a]=0;
  while (!q.empty()){
    int u=q.front();
    q.pop();
    vis[u]=0;
    for (int i=head[u]; ~i; i=e[i].nex) {
      int v=e[i].v;
      if (dis[v]>dis[u]+e[i].w) {
        dis[v]=dis[u]+e[i].w;
        if (!vis[v]) {
          vis[v]=1;
          q.push(v);
        }
      }
    }
  }
}


bool bfs() {
  queue<int>q;
  MEM(dis,0);
  q.push(s);
  dis[s]=1;
  while (!q.empty()) {
    int u=q.front();
    q.pop();
    for (int i=head2[u]; ~i; i=e[i].nex) {
      int v=e[i].v;
      if (dis[v] || !e[i].w) continue;
      dis[v]=dis[u]+1;
      if (v==t) return 1;
      q.push(v);
    }
  }
  return 0;
}

int dfs(int u,int dd){
  if (u==t) return dd;
  int flow=0;
  for (int i=head2[u]; ~i; i=e[i].nex) {
    int v=e[i].v;
    if (e[i].w&&dis[v]==dis[u]+1) {
      int f=dfs(v,min(e[i].w,dd));
      flow+=f;
      dd-=f;
      e[i].w-=f;
      e[i^1].w+=f;
      if (!dd) return flow;
    }
  }
  return flow;
}


int dinic() {
  int flow=0;
  while (bfs()) {
    flow+=dfs(s,INF);
  }
  return flow;
}

int main() {
  int T;
  cin>>T;
  while (T--) {
    cnt=0;
    MEM(head,-1);
    MEM(head2,-1);
    scanf("%d %d",&n,&m);
    while (m--) {
      int u,v,w;
      scanf("%d %d %d",&u,&v,&w);
      Addedge(u,v,w,head);
    }
    scanf("%d %d",&a,&b);
    spfa();
    s=0;
    t=n+1;
    if (cnt&1)cnt++;
    for (int u=1; u<=n; ++u) {
      for (int i=head[u]; ~i; i=e[i].nex) {
        int v=e[i].v;
        if (dis[u]+e[i].w==dis[v]) {
          Addedge(u,v,1,head2);
          Addedge(v,u,0,head2);
        }
      }
    }
    Addedge(s,a,INF,head2);
    Addedge(a,s,0,head2);
    Addedge(b,t,INF,head2);
    Addedge(t,b,0,head2);
    printf("%d\n",dinic());
  }
return 0;
}

