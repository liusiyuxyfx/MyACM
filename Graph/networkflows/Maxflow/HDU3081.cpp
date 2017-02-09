/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月19日 星期五 16时14分33秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e2+10;
const int MAXE=1e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

struct Edge{
  int u,v,cap,flow,nex;
}e[MAXE];
int head[MAXN];
int now[MAXN];
bool vis[MAXN];
int d[MAXN];

int nn,cnt;
vector<int>cut;

void init(int t){
  MEM(head,-1);
  cnt=0;
  nn=t;
}
void Addedge(int u,int v,int cap) {
  e[cnt].u=u;
  e[cnt].v=v;
  e[cnt].cap=cap;
  e[cnt].flow=0;
  e[cnt].nex=head[u];
  head[u]=cnt++;
}

void Addedges(int u,int v, int cap) {
  Addedge(u,v,cap);
  Addedge(v,u,0);
}

bool bfs(int s,int t) {
  MEM(vis,false);
  queue<int>q;
  q.push(s);
  d[s]=0;
  vis[s]=true;
  while (!q.empty()) {
    int u=q.front();
    q.pop();
    for (int i=head[u]; i!=-1; i=e[i].nex) {
      Edge &p=e[i];
      if (!vis[p.v]&&p.cap>p.flow) {
        vis[p.v]=true;
        d[p.v]=d[u]+1;
        q.push(p.v);
      }
    }
  }
  return vis[t];
}

int dfs(int u,int a,int t) {
  if (u==t||a==0)
    return a;
  int flow=0;
  int f;
  for (int &i=now[u]; i!=-1; i=e[i].nex) {
    Edge &p=e[i];
    if (d[u]+1==d[p.v]&&(f=dfs(p.v,min(a,p.cap-p.flow),t))>0) {
      p.flow+=f;
      e[i^1].flow-=f;
      flow+=f;
      a-=f;
      if (0==a) break;
    }
  }
  return flow;
}

int dinic (int s,int t) {
  int flow=0;
  while(bfs(s,t)) {
    for (int i=0; i<nn; ++i) 
      now[i]=head[i];
    flow+=dfs(s,INF,t);
  }
  return flow;
}

void mincut() {
  cut.clear();
  for (int i=0; i<cnt;i+=2) {
    if (vis[e[i].u]&&!vis[e[i].v])
      cut.push_back(i);
  }
}

int t,n,m,f,g[105][105],pre[105];
int find(int x) {
  return x==pre[x]?x:pre[x]=find(pre[x]);
}

bool judge (int k) {
  int s=0,t=n*2+1;
  init(t+1);
  for (int i=1; i<=n; ++i) {
    Addedges(s,i,k);
    Addedges(i+n,t,k);
    for (int j=1; j<=n; ++j) 
      if (g[i][j]) 
        Addedges(i,j+n,1);
  }
  return dinic(s,t)==n*k;
}

int main() {
  scanf("%d",&t);
  while (t--) {
    cin>>n>>m>>f;
    MEM(g,0);
    for (int i=1; i<=n; ++i) 
      pre[i]=i;
    int u,v;
    while (m--) {
      scanf("%d %d",&u,&v);
      g[u][v]=1;
    }
    while (f--) {
      scanf("%d %d",&u,&v);
      int pa=find(u);
      int pb=find(v);
      if (pa!=pb) pre[pa]=pb;
    }
    for (int i=1; i<=n; ++i) 
      for (int j=1; j<=n; ++j) {
        if (find(i)==find(j)) {
          for (int k=1; k<=n; ++k)
            g[i][k] |=g[j][k];
        }
      }
    int l=1,r=n+1;
    while(l<r) {
      int mid=(l+r)/2;
      if (judge(mid)) l=mid+1;
      else r=mid;
    }
    printf("%d\n",l-1);
  }

}

