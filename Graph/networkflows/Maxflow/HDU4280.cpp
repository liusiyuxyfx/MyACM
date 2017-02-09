/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月12日 星期五 18时09分25秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

struct edge{
  int to,cost,nex;
}e[MAXN];
int cnt,head[100005];
int level[100005];
int q[100005];

void Addedge(int u,int v,int w){
  e[cnt].to=v;
  e[cnt].cost=w;
  e[cnt].nex=head[u];
  head[u]=cnt++;
}

bool bfs(int s,int t){
  queue<int>q;
  q.push(s);
  MEM(level,0);
  level[s]=1;
  int u;
  while(!q.empty()){
    u=q.front();
    q.pop();
    if(u==t) return true;
    for (int i=head[u]; i!=-1; i=e[i].nex) {
      if (!level[e[i].to]&&e[i].cost>0){
        level[e[i].to]=level[u]+1;
        q.push(e[i].to);
      }
    }
  }
  return false;
}

int dfs(int now,int maxflow,int t){
  int res=0;
  if(now==t)return maxflow;
  for (int i=head[now]; i!=-1; i=e[i].nex) {
    if(level[e[i].to]==level[now]+1&&e[i].cost>0){
      int f=dfs(e[i].to,min(maxflow-res,e[i].cost),t);
      e[i].cost-=f;
      e[i^1].cost+=f;
      res+=f;
      if (res==maxflow)
        return res;
    }
  }
  if(res==0)
    level[now]=0;
  return res;
}

int dinic(int s,int t){
  int ans=0;
  while(bfs(s,t)){
    ans+=dfs(s,INF,t);
  }
  return ans;
}

int main(){
  int T;
  cin>>T;
  int n,m;
  int s,t;
  while(T--) {
    int e=0,s=INF,t=0,ps,pt;
    MEM(head,-1);
    cnt=0;
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; ++i) {
      int x,y;
      scanf("%d %d",&x,&y);
      if(s>x)s=x,ps=i;
      if(t<x)t=x,pt=i;
    }
    for (int i=1; i<=m; ++i) {
      int u,v,w;
      scanf("%d %d %d",&u,&v,&w);
      Addedge(u,v,w);
      Addedge(v,u,w);
    }
    printf("%d\n",dinic(ps,pt));
  }
}

