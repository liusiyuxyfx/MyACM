/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月11日 星期四 16时47分10秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=800;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

struct Edge{
  int from,to,cap,flow;
};

struct node{
  double d,x,y,r;
}a[MAXN];

int n,m,s,t;
bool vis[MAXN];
int d[MAXN];
int cur[MAXN];
vector <Edge> edges;
vector <int> g[MAXN];

void Addedge(int u,int v,int cap){
  edges.push_back(Edge{u,v,cap,0});
  edges.push_back(Edge{v,u,0,0});
  m=edges.size();
  g[u].push_back(m-2);
  g[v].push_back(m-1);
}

bool bfs(){
  MEM(vis,0);
  d[s]=0;
  vis[s]=1;
  queue<int>q;
  q.push(s);
  while (!q.empty()) {
    int x=q.front();
    q.pop();
    for (int i=0; i<g[x].size(); ++i) {
      Edge& e=edges[g[x][i]];
      if (!vis[e.to]&&e.cap >e.flow) {
        vis[e.to]=1;
        d[e.to]=d[x]+1;
        q.push(e.to);
      }
    }
  }
  return vis[t];
}

int dfs(int x,int a) {
  if (x==t||a==0)
    return a;
  int flow=0,f;
  for (int& i=cur[x]; i<g[x].size(); ++i) {
    Edge& e=edges[g[x][i]];
    if (d[e.to]==d[x]+1&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
      flow+=f;
      e.flow+=f;
      edges[g[x][i]^1].flow-=f;
      a-=f;
      if (a==0) break;
    }
  }
  return flow;
}

int Maxflow(){
  int flow=0;
  while(bfs()){
    MEM(cur,0);
    flow+=dfs(s,INF);
  }
  return flow;
}

bool judge(int i,int j){
  if(a[i].d>=a[j].d) return false;
  if((a[i].r+a[j].r)*(a[i].r+a[j].r)>
      (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y))
   return 1;
 return 0;
}

int main(){
  int T;
  cin>>T;
  while (T--) {
    int k;
    cin>>k;
    n=k*2;
    edges.clear();
    for (int i=0; i<n; ++i) g[i].clear();
    for (int i=0; i<k; ++i) {
      scanf("%lf %lf %lf %lf",&a[i].d,&a[i].x,&a[i].y,&a[i].r);
      if (a[i].d==400.0)
        s=i;
      if (a[i].d==789.0)
        t=i;
    }
    for (int i=0; i<k; ++i) {
      if (i!=s&&i!=t) Addedge(i<<1,i<<1|1,1);
      for (int j=0; j<i; ++j) {
        if (judge(i,j)) Addedge(i<<1|1,j<<1,1);
        else if(judge(j,i)) Addedge(j<<1|1,i<<1,1);
      }
    }
    Addedge(s<<1,s<<1|1,2);
    s<<=1;
    t<<=1;
    if (Maxflow()>=2)
      puts("Game is VALID");
    else puts("Game is NOT VALID");
  }
}

