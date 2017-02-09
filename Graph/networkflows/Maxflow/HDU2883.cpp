/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月16日 星期二 18时02分55秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e5+10;
const int MAXM=1e3+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

struct Edge{
  int u,v,cap,flow,nex;
  Edge(){}
  Edge(int u,int v,int cap,int flow){
    this->u=u;
    this->v=v;
    this->cap=cap;
    this->flow=flow;
  }
};

struct Dinic{
  int n,m,s,t;
  Edge e[MAXN];
  int head[MAXM];
  bool vis[MAXM];
  int d[MAXM];
  int now[MAXM];
  int nex[MAXN];

void init(int n) {
  this->n=n;
  MEM(head,-1);
  m=0;
}

void Addedge(int u,int v,int cap){
  e[m]=Edge(u,v,cap,0);
  nex[m]=head[u];
  head[u]=m++;
  e[m]=Edge(v,u,0,0);
  nex[m]=head[v];
  head[v]=m++;
}


bool bfs(){
  MEM(vis,false);
  queue<int>q;
  q.push(s);
  d[s]=0;
  vis[s]=true;
  while (!q.empty()) {
    int u=q.front();
    q.pop();
    for (int i=head[u]; i!=-1; i=nex[i]) {
      Edge& p=e[i];
      if (!vis[p.v]&&p.cap>p.flow) {

        vis[p.v]=true;
        d[p.v]=d[u]+1;
        q.push(p.v);
        printf("bfs:p.v=%d d[p.v]=%d\n",p.v,d[p.v]);
      }
    }
   }
  printf("vis[%d]=%d\n",t,vis[t]);
  return vis[t];
}

int dfs(int u,int a){
  if (u==t||a==0)return a;
  int maxflow=0;
  int f;
  for (int &i=now[u]; i!=-1; i=nex[i]){
    Edge& p=e[i];
    if (d[u]+1==d[p.v]&&(f=dfs(p.v,min(a,p.cap-p.flow)))>0) {
      p.flow+=f;
      e[i^1].flow-=f;
      maxflow+=f;
      a-=f;
      if (0==a) break;
    }
  }
  return maxflow;
}

int dinic(int s,int t) {
  this->s=s;
  this->t=t;
  printf ("s:%d t:%d n:%d\n",s,t,n);
  int maxflow=0;
  while (bfs()) {
    for (int i=0; i<n; ++i) 
      now[i]=head[i];
    maxflow+=dfs(s,INF);
    printf("dinic maxflow=%d\n",maxflow);
  }
  return maxflow;
}
}gao;

struct No{
  int l,r;
}no[500];

int p[500],pn;
int n,m,s,nu,e,t;
int main() {
  while(cin>>n>>m) {
    gao.init(3*n+2);
    pn=0;
    int sum=0;
    for (int i=1; i<=n; ++i) {
      scanf("%d %d %d %d",&s,&nu,&e,&t);
      no[i].l=s;
      no[i].r=e;
      p[pn++]=s;
      p[pn++]=e;
      sum+=nu*t;
      gao.Addedge(0,i,nu*t);

    }
      sort(p,p+pn);
      for (int i=1; i<pn ;++i) {
        gao.Addedge(n+i,3*n+1,(p[i]-p[i-1])*m);
      }
      for (int i=1; i<=n; ++i) {
        for (int j=1; j<pn; ++j) {
          if(p[j-1]>no[i].r) break;
          if (no[i].l<=p[j-1]&&no[i].r>=p[j])
            gao.Addedge(i,j+n,INF);
        }
      }
      printf("cnt=%d\n",gao.m);
      printf("%s\n",gao.dinic(0,3*n+1)==sum?"Yes":"No");
  }
}

