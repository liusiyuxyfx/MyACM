/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月11日 星期四 14时13分30秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1050;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

struct Edge {
  int from,to,cap,flow;
};
vector <int> g[1050];
vector <Edge> edges;

bool vis[MAXN];
int d[MAXN];
int cur[MAXN];
int NN;

void init() {
  edges.clear();
  for (int i=0; i<=NN; ++i)
    g[i].clear();
}
void add(int u,int v,int c){
  edges.push_back((Edge){u,v,c,0});
  g[u].push_back(edges.size()-1);
  edges.push_back((Edge){v,u,0,0});
  g[v].push_back(edges.size()-1);
}

bool bfs(int s,int t){
  MEM(vis,0);
  vis[s]=1;
  queue <int>q;
  q.push(s);
  d[s]=0;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    int size=g[u].size();
    for (int i=0; i<size; ++i) {
      Edge &e=edges[g[u][i]];
      if (!vis[e.to]&&e.cap>e.flow) {
        vis[e.to]=1;
        d[e.to]=d[u]+1;
        q.push(e.to);
      }
    }
  }
  return vis[t];
}


int dfs(int u,int t,int mi){
  if (u==t||mi==0)
    return mi;
  int flow=0;
  int f;
  int size=g[u].size();
  for (int &i=cur[u]; i<size; ++i) {
    Edge &e=edges[g[u][i]];
    if (d[u]+1==d[e.to] && (f=dfs(e.to,t,min(mi,e.cap-e.flow)))>0) {
      e.flow+=f;
      edges[g[u][i]^1].flow-=f;
      flow+=f;
      mi-=f;
      if (mi==0) break;
      }
  }
  return flow;
}

int dinic(int s,int t){
  int flow=0;
  while(bfs(s,t)){
    MEM(cur,0);
    flow+=dfs(s,t,INF);
  }
  return flow;
}

int main() {
  int t,cas=1;
  cin>>t;
  int n,m;
  int pp,ss,ee;
  while (t--) {
    scanf("%d%d",&n,&m);
    NN=n+501;
    init();
    int sum=0;
    for (int i=1;i <=n; ++i) {
      scanf("%d %d %d",&pp,&ss,&ee);
      sum+=pp;
      add(0,i,pp);
      for (int j=ss; j<=ee; ++j)
        add(i,n+j,1);
    }
    for (int i=n+1; i<=n+500; ++i) 
      add(i,NN,m);
    int ans=dinic(0,NN);
    if (ans==sum)
      printf("Case %d: Yes\n\n",cas++);
    else
      printf("Case %d: No\n\n",cas++);
  }
}

